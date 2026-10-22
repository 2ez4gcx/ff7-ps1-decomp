"""The C side of the build: what the game was compiled with, as near as we
can run it on Windows.

    GCC 2.6.3 cpp -> GCC 2.6.3 cc1 (mips-sony-psx) -> maspsx -> GNU as

cc1 and cpp are GCC 2.6.3 built for 32-bit Windows with decompals/old-gcc's
psx patches (docs/toolchain.md); maspsx stands in for PSY-Q's ASPSX, with
tools/maspsx-extern.patch so small externs (`.extern x, 4`) go through $gp
as ASPSX did. Paths come from FF7_TOOLCHAIN (default D:/FF7/toolchain).
"""
import os
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
# up to 8 bytes through $gp. ASPSX 2.34 and later behave the same for every
# function tried; 2.56 is the working choice until one tells them apart.
CFLAGS = ['-O2', '-G8']
GP_SIZE = 8
ASPSX = '2.56'


class Failed(Exception):
    pass


def _run(cmd, data=None, env=None):
    done = subprocess.run(cmd, input=data, capture_output=True, text=True, env=env)
    if done.returncode:
        raise Failed(f'{" ".join(map(str, cmd))}\n{done.stderr[-4000:]}')
    return done.stdout


def assembly(src, cflags=None, gp_size=GP_SIZE, aspsx=ASPSX):
    """C file -> (cc1 output, assembly GNU as takes)."""
    env = dict(os.environ, TMPDIR=tempfile.gettempdir())
    # macro.inc keeps jump-table labels global: the tables are in another file.
    pre = _run([str(CPP), '-undef', '-Dmips', '-D__GNUC__=2', '-D_LANGUAGE_C', '-DLANGUAGE_C',
                '-DINCLUDE_ASM_USE_MACRO_INC=1',
                '-I', str(ROOT / 'include'), '-I', str(ROOT / 'src'), str(src)], env=env)
    cc = _run([str(CC1), '-quiet', *(cflags or CFLAGS), '-o', '-'], pre, env=env)
    if not cc:
        raise Failed(f'cc1 made nothing of {src}')
    ms = _run([sys.executable, str(MASPSX), f'--aspsx-version={aspsx}', f'-G{gp_size}',
               '--expand-div'], cc)
    return cc, ms


def compile_c(src, obj, cflags=None, gp_size=GP_SIZE, aspsx=ASPSX):
    """C file -> object, as the game's build made it."""
    _, asm = assembly(src, cflags, gp_size, aspsx)
    Path(obj).parent.mkdir(parents=True, exist_ok=True)
    # The INCLUDE_ASM paths are relative to the repository root.
    done = subprocess.run([PREFIX + 'as', *AS_FLAGS, '-o', str(obj), '-'], input=asm,
                          capture_output=True, text=True, cwd=ROOT)
    if done.returncode:
        raise Failed(f'as {src}\n{done.stderr[-4000:]}')
