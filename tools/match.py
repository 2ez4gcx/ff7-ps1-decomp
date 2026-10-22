#!/usr/bin/env python3
"""Does a C function compile to exactly the game's code? Checked word for word.

    python tools/match.py FILE.c [--target main]

Each function in FILE.c is compiled (tools/psyq.py) and its relocations are
applied as the linker would, with the function placed at its address in the
game and symbols at their addresses in the built executable (build/us/, so
run tools/build.py once first). The result must equal the game's words:
those splat's asm lists (asm/us/<target>/nonmatchings/...), or, for a
function already in C (splat writes no asm for it), those of the executable
on the disc. Each file is built with its own options (tools/psyq.py).
Functions that need data of their own (string literals, static tables) are
reported as such: that data's place is decided at link time.
"""
import argparse
import os
import re
import struct
import subprocess
import sys
import tempfile
from functools import lru_cache
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import psyq  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
GP = 0x80062D44
ELF = {'main': ROOT / 'build' / 'us' / 'scus_941.63.elf'}


@lru_cache(maxsize=None)
def symbols(target='main'):
    """name -> address of every symbol the built executable knows."""
    out = {}
    elfs = [ELF['main']]
    if target != 'main':
        elfs.append(ROOT / 'build' / 'us' / f'{target}.elf')
    for elf in elfs:
        text = subprocess.run([psyq.PREFIX + 'nm', str(elf)], capture_output=True, text=True).stdout
        for line in text.splitlines():
            parts = line.split()
            if len(parts) == 3:
                out.setdefault(parts[2], int(parts[0], 16) & 0xFFFFFFFF)
    return out


def address_of(name, target='main'):
    if name in symbols(target):
        return symbols(target)[name]
    m = re.search(r'_?([0-9A-Fa-f]{8})$', name)
    return int(m.group(1), 16) if m else None


# The game's executables as on the disc: path, and address of file offset 0.
GAME = {'main': (ROOT / 'disks' / 'us' / 'SCUS_941.63', 0x80010000 - 0x800)}


@lru_cache(maxsize=None)
def code_starts(target='main'):
    """Sorted addresses of the code symbols of the built executable."""
    text = subprocess.run([psyq.PREFIX + 'nm', '-n', str(ELF[target])], capture_output=True, text=True).stdout
    return sorted({int(a, 16) & 0xFFFFFFFF for a, kind, _ in (l.split() for l in text.splitlines()
                                                                   if len(l.split()) == 3) if kind in 'Tt'})


@lru_cache(maxsize=None)
def original(name, target='main'):
    """(address, [words]) of a function of the game, or None: from splat's
    asm while it has some, else from the executable on the disc, up to the
    next function of the built one (whose layout matches the game's)."""
    base = ROOT / 'asm' / 'us' / target / 'nonmatchings'
    for path in base.rglob(f'{name}.s'):
        rows = re.findall(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/', path.read_text(encoding='utf-8'))
        if rows:
            return int(rows[0][0], 16), [struct.unpack('<I', bytes.fromhex(w))[0] for _, w in rows]
    if target not in GAME or name not in symbols(target):
        return None
    path, origin = GAME[target]
    address = symbols(target)[name]
    end = next((a for a in code_starts(target) if a > address), None)
    if end is None:
        return None
    data = path.read_bytes()[address - origin:end - origin]
    return address, list(struct.unpack(f'<{len(data) // 4}I', data))


def object_text(obj):
    """Functions of an object's .text: {name: (offset, [words])}, relocations
    [(offset, type, symbol)], and whether other sections hold data."""
    dump = subprocess.run([psyq.PREFIX + 'objdump', '-dr', '-z', '--section=.text', str(obj)],
                          capture_output=True, text=True).stdout
    funcs, relocs, cur, words = {}, [], None, []
    for line in dump.splitlines():
        m = re.match(r'^([0-9a-f]+) <([^>]+)>:', line)
        if m:
            cur = m.group(2)
            funcs[cur] = (int(m.group(1), 16), [])
            continue
        m = re.match(r'^\s+([0-9a-f]+):\s+([0-9a-f]{8})\s', line)
        if m and cur:
            funcs[cur][1].append(int(m.group(2), 16))
            continue
        m = re.match(r'^\s+([0-9a-f]+): (R_MIPS_\w+)\s+(\S+)', line)
        if m:
            relocs.append((int(m.group(1), 16), m.group(2), m.group(3)))
    heads = subprocess.run([psyq.PREFIX + 'objdump', '-h', str(obj)], capture_output=True, text=True).stdout
    data = any(int(size, 16) for name, size in re.findall(r'^\s*\d+\s+(\.\S+)\s+([0-9a-f]+)', heads, re.M)
               if name in ('.rodata', '.data', '.sdata', '.rdata', '.bss', '.sbss'))
    return funcs, relocs, data


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def linked(funcs, relocs, name, address, target):
    """The words of function `name` once linked at `address`."""
    start, words = funcs[name]
    words = list(words)
    end = start + 4 * len(words)
    base = address - start                 # object offset -> address in the game
    mine = [r for r in relocs if start <= r[0] < end]
    for i, (off, kind, sym) in enumerate(mine):
        k = (off - start) // 4
        w = words[k]
        if sym == '.text':
            s = base
        else:
            s = address_of(sym, target)
            if s is None:
                raise KeyError(sym)
        if kind == 'R_MIPS_26':
            target_addr = s + ((w & 0x03FFFFFF) << 2)
            words[k] = (w & 0xFC000000) | ((target_addr >> 2) & 0x03FFFFFF)
        elif kind == 'R_MIPS_HI16':
            lo = next((o for o, t, s2 in mine[i + 1:] if t == 'R_MIPS_LO16' and s2 == sym), None)
            low = sext16(words[(lo - start) // 4] & 0xFFFF) if lo is not None else 0
            value = s + ((w & 0xFFFF) << 16) + low
            words[k] = (w & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF)
        elif kind == 'R_MIPS_LO16':
            words[k] = (w & 0xFFFF0000) | ((s + sext16(w & 0xFFFF)) & 0xFFFF)
        elif kind == 'R_MIPS_GPREL16':
            words[k] = (w & 0xFFFF0000) | ((s + sext16(w & 0xFFFF) - GP) & 0xFFFF)
        else:
            raise KeyError(kind)
    return words


def check(src, target='main', only=None, cflags=None, gp_size=None, like=None, aspsx=None):
    """{function: None if exact, else a reason} for the functions of src,
    built as `like` (a file of src/) is when given."""
    fd, name = tempfile.mkstemp(suffix='.o')
    os.close(fd)
    obj = Path(name)
    try:
        psyq.compile_c(src, obj, cflags, gp_size, aspsx, like=like)
        funcs, relocs, data = object_text(obj)
    finally:
        obj.unlink(missing_ok=True)
    out = {}
    for name in funcs:
        if name.startswith('__maspsx') or (only and name not in only):
            continue
        orig = original(name, target)
        if orig is None:
            out[name] = 'not in the game'
            continue
        address, want = orig
        try:
            got = linked(funcs, relocs, name, address, target)
        except KeyError as e:
            out[name] = f'unknown symbol or relocation {e}'
            continue
        if len(got) != len(want):
            out[name] = f'{len(got)} instructions, game has {len(want)}'
            continue
        diff = next((i for i in range(len(got)) if got[i] != want[i]), None)
        if diff is None:
            out[name] = 'needs data of its own' if data else None
        else:
            out[name] = f'instruction {diff}: {got[diff]:08X}, game {want[diff]:08X}'
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source', type=Path)
    ap.add_argument('--target', default='main')
    args = ap.parse_args()
    try:
        result = check(args.source, args.target)
    except psyq.Failed as e:
        sys.exit(str(e))
    for name, why in result.items():
        print(f'{name}: {"OK" if why is None else why}')
    sys.exit(0 if all(w is None for w in result.values()) else 1)


if __name__ == '__main__':
    main()
