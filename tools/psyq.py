"""The C side of the build: what the game was compiled with, as near as we
can run it on Windows.

    GCC 2.6.3 cpp -> GCC 2.6.3 cc1 (mips-sony-psx) -> maspsx -> GNU as

cc1 and cpp are GCC 2.6.3 built for 32-bit Windows with decompals/old-gcc's
psx patches (docs/toolchain.md); maspsx stands in for PSY-Q's ASPSX, with
tools/maspsx-extern.patch so small externs (`.extern x, 4`) go through $gp
as ASPSX did. Paths come from FF7_TOOLCHAIN (default D:/FF7/toolchain).
"""
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TOOLS = Path(os.environ.get('FF7_TOOLCHAIN', 'D:/FF7/toolchain'))
CPP = TOOLS / 'build-gcc' / 'gcc-2.6.3' / 'cpp.exe'
CC1 = TOOLS / 'build-gcc' / 'gcc-2.6.3' / 'cc1.exe'
MASPSX = TOOLS / 'maspsx' / 'maspsx.py'
PREFIX = os.environ.get('MIPSEL_PREFIX', str(TOOLS / 'mipsel' / 'bin' / 'mipsel-none-elf-'))
AS_FLAGS = ['-EL', '-march=r3000', '-mtune=r3000', '-mabi=32', '-no-pad-sections', '-G0',
            '-I', str(ROOT / 'include')]

# What the game's code matches with so far (main executable): -O2, small data
# up to 8 bytes through $gp, ASPSX between 2.30 (folds %lo into a load's
# offset) and 2.55 (still expands li as ori, which 2.56 stopped doing).
CFLAGS = ['-O2', '-G8']
GP_SIZE = 8
ASPSX = '2.34'
GP = 0x80062D44

# Files built otherwise (relative to src/): the AKAO sound driver and the
# PSY-Q libraries never use $gp, even for the smallest variables.
FILE_OPTIONS = {
    'main/akao.c': {'cflags': ['-O2', '-G0'], 'gp_size': 0, 'aspsx': '2.21'},
    'main/lib.c': {'cflags': ['-O2', '-G0'], 'gp_size': 0},
}


def options(src):
    """{cflags, gp_size, aspsx} a source file is built with."""
    try:
        key = Path(src).resolve().relative_to(ROOT / 'src').as_posix()
    except ValueError:
        key = None
    return {'cflags': CFLAGS, 'gp_size': GP_SIZE, 'aspsx': ASPSX, **FILE_OPTIONS.get(key, {})}


class Failed(Exception):
    pass


def _named_addresses():
    """name -> address from the symbol files in config/."""
    out = {}
    for path in (ROOT / 'config').glob('symbols.us.*.txt'):
        for m in re.finditer(r'^\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;', path.read_text(encoding='utf-8'), re.M):
            out[m.group(1)] = int(m.group(2), 16)
    return out


def _far_from_gp(name, named):
    """True when the symbol's address is known and $gp cannot reach it."""
    address = named.get(name)
    if address is None:
        m = re.search(r'_([0-9A-Fa-f]{8})$', name)
        address = int(m.group(1), 16) if m else None
    return address is not None and not (GP - 0x8000 <= address < GP + 0x8000)


def _absolute_far_externs(asm):
    """A small extern the game reaches with lui/%lo was declared bigger than
    -G in its source (part of a struct or array): drop the size the compiler
    gave it, so the assembler does not put it on $gp."""
    named = _named_addresses()
    out = []
    for line in asm.splitlines(keepends=True):
        m = re.match(r'\s*\.extern\s+([\w.$]+)\s*,\s*\d+\s*$', line)
        if m and _far_from_gp(m.group(1), named):
            line = re.sub(r'\s*,\s*\d+\s*$', '\n', line)
        out.append(line)
    return ''.join(out)


def _run(cmd, data=None, env=None):
    done = subprocess.run(cmd, input=data, capture_output=True, text=True, env=env)
    if done.returncode:
        raise Failed(f'{" ".join(map(str, cmd))}\n{done.stderr[-4000:]}')
    return done.stdout


def assembly(src, cflags=None, gp_size=None, aspsx=None, like=None):
    """C file -> (cc1 output, assembly GNU as takes). Options not given are
    those of `like` (a file of src/), or of src itself."""
    default = options(like or src)
    cflags = default['cflags'] if cflags is None else cflags
    gp_size = default['gp_size'] if gp_size is None else gp_size
    aspsx = default['aspsx'] if aspsx is None else aspsx
    env = dict(os.environ, TMPDIR=tempfile.gettempdir())
    # macro.inc keeps jump-table labels global: the tables are in another file.
    pre = _run([str(CPP), '-undef', '-Dmips', '-D__GNUC__=2', '-D_LANGUAGE_C', '-DLANGUAGE_C',
                '-DINCLUDE_ASM_USE_MACRO_INC=1',
                '-I', str(ROOT / 'include'), '-I', str(ROOT / 'src'), str(src)], env=env)
    cc = _run([str(CC1), '-quiet', *cflags, '-o', '-'], pre, env=env)
    if not cc:
        raise Failed(f'cc1 made nothing of {src}')
    cc = _absolute_far_externs(cc)
    ms = _run([sys.executable, str(MASPSX), f'--aspsx-version={aspsx}', f'-G{gp_size}',
               '--expand-div'], cc)
    return cc, ms


def compile_c(src, obj, cflags=None, gp_size=None, aspsx=None, like=None):
    """C file -> object, as the game's build made it."""
    _, asm = assembly(src, cflags, gp_size, aspsx, like)
    Path(obj).parent.mkdir(parents=True, exist_ok=True)
    # The INCLUDE_ASM paths are relative to the repository root.
    done = subprocess.run([PREFIX + 'as', *AS_FLAGS, '-o', str(obj), '-'], input=asm,
                          capture_output=True, text=True, cwd=ROOT)
    if done.returncode:
        raise Failed(f'as {src}\n{done.stderr[-4000:]}')
