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
import struct
import subprocess
import sys
import tempfile
from functools import lru_cache
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TOOLS = Path(os.environ.get('FF7_TOOLCHAIN', 'D:/FF7/toolchain'))
CPP = TOOLS / 'build-gcc' / 'gcc-2.6.3' / 'cpp.exe'
CC1 = TOOLS / 'build-gcc' / 'gcc-2.6.3' / 'cc1.exe'


def cc1_of(version):
    """cc1 of a GCC built by tools/gcc-win32/build.sh (2.6.3 by default)."""
    return TOOLS / 'build-gcc' / f'gcc-{version}' / 'cc1.exe'
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
    # The game's code went through an ASPSX older than 2.30 (`lui $at`, `addiu
    # $at, %lo`, `addu` for a global plus a register; a nop before an $at
    # expansion that uses the register just loaded), but for text2.c, which
    # folds %lo into the load as 2.30 and later do and still has that nop
    # (maspsx's --nop-at-expansion, from its patch).
    # Some of it was compiled by GCC 2.7.2 (text2, text4, text5): it fills a return's
    # delay slot where 2.6.3 does not, and allocates some registers otherwise.
    'main/text.c': {'aspsx': '2.21'},
    'main/text2.c': {'nop_at_expansion': True, 'gcc': '2.7.2'},
    'main/text3.c': {'aspsx': '2.21'},
    'main/text4.c': {'aspsx': '2.21', 'gcc': '2.7.2'},
    'main/text5.c': {'aspsx': '2.21', 'gcc': '2.7.2'},
    'main/akao.c': {'cflags': ['-O2', '-G0'], 'gp_size': 0, 'aspsx': '2.21'},
    'main/lib.c': {'cflags': ['-O2', '-G0'], 'gp_size': 0},
}


# The overlays never use $gp: it points into the main executable's data.
OVERLAY_OPTIONS = {'cflags': ['-O2', '-G0'], 'gp_size': 0, 'aspsx': '2.21'}


def options(src):
    """{cflags, gp_size, aspsx} a source file is built with."""
    try:
        key = Path(src).resolve().relative_to(ROOT / 'src').as_posix()
    except ValueError:
        key = None
    base = {'cflags': CFLAGS, 'gp_size': GP_SIZE, 'aspsx': ASPSX}
    if key is not None and not key.startswith('main/'):
        base.update(OVERLAY_OPTIONS)
    return {**base, **FILE_OPTIONS.get(key, {})}


class Failed(Exception):
    pass


def _named_addresses():
    """name -> address from the symbol files in config/."""
    out = {}
    for path in (ROOT / 'config').glob('symbols.us.*.txt'):
        for m in re.finditer(r'^\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;', path.read_text(encoding='utf-8'), re.M):
            out[m.group(1)] = int(m.group(2), 16)
    return out


def _address(name, named):
    """The address of a symbol: from config/, or from its name (D_8006xxxx)."""
    address = named.get(name)
    if address is None:
        m = re.search(r'_([0-9A-Fa-f]{8})$', name)
        address = int(m.group(1), 16) if m else None
    return address


def _far_from_gp(name, named):
    """True when the symbol's address is known and $gp cannot reach it."""
    address = _address(name, named)
    return address is not None and not (GP - 0x8000 <= address < GP + 0x8000)


GAME = ROOT / 'disks' / 'us' / 'SCUS_941.63'


@lru_cache(maxsize=None)
def code_range(src):
    """(first, end) address of the game's code a C file of the main
    executable stands for (its c segment in the splat config), or None."""
    try:
        rel = Path(src).resolve().relative_to(ROOT / 'src')
    except ValueError:
        return None
    if rel.parts[0] != 'main':
        return None
    text = (ROOT / 'config' / 'scus_941.63.us.yaml').read_text(encoding='utf-8')
    subs = [(int(o, 16), kind, name) for o, kind, name in
            re.findall(r'^\s*- \[(0x[0-9A-Fa-f]+), (\.?\w+), (\w+)\]', text, re.M)]
    for i, (offset, kind, name) in enumerate(subs):
        if kind == 'c' and name == rel.stem and i + 1 < len(subs):
            return offset + 0x8000F800, subs[i + 1][0] + 0x8000F800
    return None


@lru_cache(maxsize=None)
def _never_through_gp(lo, hi):
    """Addresses near $gp that the game's code in [lo, hi) reaches only with
    lui/%lo: variables that part's source declared bigger than -G (in a
    struct or an array). The same variable may be on $gp in another part,
    whose source declared it otherwise."""
    if not GAME.exists():
        return frozenset()
    data = GAME.read_bytes()[lo - 0x8000F800:hi - 0x8000F800]
    sext = lambda v: v - 0x10000 if v & 0x8000 else v
    gp, absolute, upper = set(), set(), {}
    for (w,) in struct.iter_unpack('<I', data):
        op, rs, rt, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        if op == 0x0F:                                  # lui
            upper[rt] = imm << 16
            continue
        if op == 0x09 or 0x20 <= op <= 0x2E:            # addiu, loads, stores
            if rs == 28:
                gp.add(GP + sext(imm))
            elif rs in upper:
                absolute.add((upper[rs] + sext(imm)) & 0xFFFFFFFF)
            if op < 0x28:                               # addiu and loads write rt
                upper.pop(rt, None)
        elif op == 0:
            upper.pop((w >> 11) & 31, None)
            if w & 0x3F == 0x08:                        # jr: the function may end
                upper.clear()
        else:
            upper.pop(rt, None)
    return frozenset(a for a in absolute - gp if GP - 0x8000 <= a < GP + 0x8000)


def _absolute_externs(asm, span):
    """A small extern the game reaches with lui/%lo (too far from $gp, or
    declared bigger than -G in its source: part of a struct or an array):
    drop the size the compiler gave it, so the assembler does not put it on
    $gp. `span` is the part of the game's code the file stands for."""
    named = _named_addresses()
    near = _never_through_gp(*span) if span else frozenset()
    out = []
    for line in asm.splitlines(keepends=True):
        m = re.match(r'\s*\.extern\s+([\w.$]+)\s*,\s*\d+\s*$', line)
        if m and (_far_from_gp(m.group(1), named) or _address(m.group(1), named) in near):
            line = re.sub(r'\s*,\s*\d+\s*$', '\n', line)
        out.append(line)
    return ''.join(out)


def _run(cmd, data=None, env=None):
    done = subprocess.run(cmd, input=data, capture_output=True, text=True, env=env)
    if done.returncode:
        raise Failed(f'{" ".join(map(str, cmd))}\n{done.stderr[-4000:]}')
    return done.stdout


def assembly(src, cflags=None, gp_size=None, aspsx=None, like=None, nop_at_expansion=None):
    """C file -> (cc1 output, assembly GNU as takes). Options not given are
    those of `like` (a file of src/), or of src itself."""
    default = options(like or src)
    cflags = default['cflags'] if cflags is None else cflags
    gp_size = default['gp_size'] if gp_size is None else gp_size
    aspsx = default['aspsx'] if aspsx is None else aspsx
    nop_at = default.get('nop_at_expansion', False) if nop_at_expansion is None else nop_at_expansion
    env = dict(os.environ, TMPDIR=tempfile.gettempdir())
    # macro.inc keeps jump-table labels global: the tables are in another file.
    pre = _run([str(CPP), '-undef', '-Dmips', '-D__GNUC__=2', '-D_LANGUAGE_C', '-DLANGUAGE_C',
                '-DINCLUDE_ASM_USE_MACRO_INC=1',
                '-I', str(ROOT / 'include'), '-I', str(ROOT / 'src'), str(src)], env=env)
    cc = _run([str(cc1_of(default.get('gcc', '2.6.3'))), '-quiet', *cflags, '-o', '-'], pre, env=env)
    if not cc:
        raise Failed(f'cc1 made nothing of {src}')
    cc = _absolute_externs(cc, code_range(like or src))
    # GCC calls the read-only section .rdata; the game's (and splat's) is .rodata.
    cc = re.sub(r'^\t\.rdata$', '\t.section\t.rodata', cc, flags=re.M)
    # GCC aligns jump tables to 8 bytes from the start of its file's .rodata.
    # Ours put many of the game's files in one, so that start is not theirs:
    # keep tables on 4 bytes, as splat's asm does; where the game has padding
    # before one, tools/match.py tells.
    cc = re.sub(r'^\t\.align\t3$', '\t.align\t2', cc, flags=re.M)
    ms = _run([sys.executable, str(MASPSX), f'--aspsx-version={aspsx}', f'-G{gp_size}',
               '--expand-div', *(['--nop-at-expansion'] if nop_at else [])], cc)
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
