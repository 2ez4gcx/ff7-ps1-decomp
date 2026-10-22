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
import targets  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
GP = 0x80062D44


@lru_cache(maxsize=None)
def symbols(target='main'):
    """name -> address of every symbol the built executable knows (an
    overlay's own first, then the main executable's)."""
    out = {}
    elfs = [targets.get(target).elf]
    if target != 'main':
        elfs.append(targets.get('main').elf)
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


@lru_cache(maxsize=None)
def code_starts(target='main'):
    """Sorted addresses of the code symbols of the built executable."""
    text = subprocess.run([psyq.PREFIX + 'nm', '-n', str(targets.get(target).elf)],
                          capture_output=True, text=True).stdout
    return sorted({int(a, 16) & 0xFFFFFFFF for a, kind, _ in (l.split() for l in text.splitlines()
                                                                   if len(l.split()) == 3) if kind in 'Tt'})


ROW = re.compile(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/')


@lru_cache(maxsize=None)
def asm_of(name, target='main'):
    """(code lines, rodata lines) of a function's asm file from splat, or
    None. The rodata is the function's own (splat migrates it there)."""
    base = targets.get(target).asm
    for path in base.rglob(f'{name}.s'):
        code, rodata, part = [], [], None
        for line in path.read_text(encoding='utf-8').splitlines():
            m = re.match(r'\s*\.section\s+(\.\w+)', line)
            if m:
                part = m.group(1)
                continue
            (rodata if part in ('.rodata', '.rdata') else code).append(line)
        return code, rodata
    return None


@lru_cache(maxsize=None)
def original(name, target='main'):
    """(address, [words]) of a function of the game, or None: from splat's
    asm while it has some, else from the executable on the disc, up to the
    next function of the built one (whose layout matches the game's)."""
    asm = asm_of(name, target)
    if asm is not None:
        rows = ROW.findall('\n'.join(asm[0]))
        if rows:
            return int(rows[0][0], 16), [struct.unpack('<I', bytes.fromhex(w))[0] for _, w in rows]
    if name not in symbols(target):
        return None
    address = symbols(target)[name]
    end = next((a for a in code_starts(target) if a > address), None)
    if end is None:
        return None
    data = game_bytes(address, end - address, target)
    return address, list(struct.unpack(f'<{len(data) // 4}I', data))


def game_bytes(address, size, target='main'):
    t = targets.get(target)
    return _image(t.image)[address - t.origin:address - t.origin + size]


@lru_cache(maxsize=None)
def _image(path):
    return path.read_bytes()


def rodata_address(name, target='main'):
    """Where a function's own rodata starts in the game, from its asm."""
    asm = asm_of(name, target)
    if asm is None:
        return None
    found = re.findall(r'/\* [0-9A-F]+ ([0-9A-F]{8})', '\n'.join(asm[1]))
    return min(int(a, 16) for a in found) if found else None


@lru_cache(maxsize=None)
def placed(obj_path, section, target='main'):
    """Address the link put a section of one of our objects at (map file)."""
    text = targets.get(target).elf.with_suffix('.map').read_text(encoding='utf-8', errors='replace')
    m = re.search(rf'^ {re.escape(section)}\s+0x([0-9a-f]+)\s+0x[0-9a-f]+ {re.escape(obj_path)}$', text, re.M)
    return int(m.group(1), 16) if m else None


def object_text(obj):
    """Functions of an object's .text: {name: (offset, [words])}, relocations
    [(offset, type, symbol)], its .rodata (bytes, relocations), and whether
    it has other data (.data, .sdata, .bss...)."""
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
    sizes = {name: int(size, 16) for name, size in re.findall(r'^\s*\d+\s+(\.\S+)\s+([0-9a-f]+)', heads, re.M)}
    data = any(sizes.get(n) for n in ('.data', '.sdata', '.bss', '.sbss', '.rdata'))
    rodata, rodata_relocs = b'', []
    if sizes.get('.rodata'):
        hexdump = subprocess.run([psyq.PREFIX + 'objdump', '-s', '-j', '.rodata', str(obj)],
                                 capture_output=True, text=True).stdout
        for m in re.finditer(r'^ [0-9a-f]{4,} ((?:[0-9a-f]{2,8} ){1,4})', hexdump, re.M):
            rodata += bytes.fromhex(m.group(1).replace(' ', ''))
        rel = subprocess.run([psyq.PREFIX + 'objdump', '-r', '-j', '.rodata', str(obj)],
                             capture_output=True, text=True).stdout
        rodata_relocs = [(int(o, 16), t, sym) for o, t, sym in
                         re.findall(r'^([0-9a-f]{8}) (R_MIPS_\w+)\s+(\S+)', rel, re.M)]
    return funcs, relocs, (rodata, rodata_relocs), data


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def linked(funcs, relocs, name, address, target, rodata=None):
    """The words of function `name` once linked at `address`, its object's
    .rodata at `rodata`."""
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
        elif sym == '.rodata':
            if rodata is None:
                raise KeyError('.rodata (where it goes is not known)')
            s = rodata
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


def linked_rodata(rodata, rodata_relocs, funcs, places, target):
    """An object's .rodata once linked: words pointing into .text (jump
    tables) get the address their function has in the game."""
    out = bytearray(rodata)
    for off, kind, sym in rodata_relocs:
        if kind != 'R_MIPS_32':
            raise KeyError(kind)
        value = struct.unpack_from('<I', out, off)[0]
        if sym == '.text':
            owner = next((n for n, (start, words) in funcs.items() if start <= value < start + 4 * len(words)), None)
            if owner is None or owner not in places:
                raise KeyError(f'.text+0x{value:X}')
            value = places[owner] + value - funcs[owner][0]
        else:
            s = address_of(sym, target)
            if s is None:
                raise KeyError(sym)
            value += s
        struct.pack_into('<I', out, off, value & 0xFFFFFFFF)
    return bytes(out)


def check(src, target='main', only=None, cflags=None, gp_size=None, like=None, aspsx=None, rodata=None):
    """{function: None if exact, else a reason} for the functions of src,
    built as `like` (a file of src/) is when given. The object's .rodata,
    if any, goes at `rodata`: by default where the function's own rodata is
    in the game (one function checked), or where the build put this file's."""
    fd, name = tempfile.mkstemp(suffix='.o')
    os.close(fd)
    obj = Path(name)
    try:
        psyq.compile_c(src, obj, cflags, gp_size, aspsx, like=like)
        funcs, relocs, (ro, ro_relocs), data = object_text(obj)
    finally:
        obj.unlink(missing_ok=True)
    names = [n for n in funcs if not n.startswith('__maspsx') and (not only or n in only)]
    if ro and rodata is None:
        if len(names) == 1:
            rodata = rodata_address(names[0], target)
        else:
            try:
                rel = Path(like or src).resolve().relative_to(ROOT).with_suffix('.o').as_posix()
                rodata = placed(f'build/us/{rel}', '.rodata', target)
            except ValueError:
                pass
    out, places = {}, {}
    for name in names:
        orig = original(name, target)
        if orig is None:
            out[name] = 'not in the game'
            continue
        address, want = orig
        places[name] = address
        try:
            got = linked(funcs, relocs, name, address, target, rodata)
        except KeyError as e:
            out[name] = f'unknown symbol or relocation {e}'
            continue
        if len(got) != len(want):
            out[name] = f'{len(got)} instructions, game has {len(want)}'
            continue
        diff = next((i for i in range(len(got)) if got[i] != want[i]), None)
        if diff is not None:
            out[name] = f'instruction {diff}: {got[diff]:08X}, game {want[diff]:08X}'
        elif data:
            out[name] = 'needs data of its own'
        else:
            out[name] = None
    if ro and rodata is not None and any(v is None for v in out.values()):
        # Jump tables point into every function of the object, asm ones too.
        for n in funcs:
            if n not in places and not n.startswith('__maspsx'):
                orig = original(n, target)
                if orig is not None:
                    places[n] = orig[0]
        try:
            mine = linked_rodata(ro, ro_relocs, funcs, places, target)
        except KeyError as e:
            why = f'rodata: unknown symbol or relocation {e}'
        else:
            game = game_bytes(rodata, len(mine), target)
            at = next((i for i in range(len(mine)) if mine[i] != game[i]), None)
            why = None if at is None else f'rodata differs at 0x{rodata + at:08X}'
        if why is not None:
            for n in out:
                if out[n] is None:
                    out[n] = why
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
