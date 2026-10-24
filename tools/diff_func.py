#!/usr/bin/env python3
"""Show a C function's code next to the game's, instruction by instruction.

    python tools/diff_func.py FILE.c NAME [--target main] [--like src/main/akao.c]

FILE.c is compiled the way the file named by --like is built (by default the
file of the target the function is in), the function is linked at its
address in the game (tools/match.py), and both are disassembled side by
side; a `*` marks each word that differs. The last line says whether the
function matches.
"""
import argparse
import os
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import psyq  # noqa: E402
import targets  # noqa: E402


def disassemble(words, address):
    """Each word as text, as objdump reads it at `address`."""
    fd, path = tempfile.mkstemp(suffix='.bin')
    os.close(fd)
    try:
        Path(path).write_bytes(struct.pack(f'<{len(words)}I', *words))
        out = subprocess.run([psyq.PREFIX + 'objdump', '-D', '-b', 'binary', '-m', 'mips:3000', '-EL',
                              f'--adjust-vma=0x{address:X}', path], capture_output=True, text=True).stdout
    finally:
        os.unlink(path)
    text = {}
    for line in out.splitlines():
        parts = line.split('\t')
        if len(parts) >= 3 and parts[0].strip().endswith(':'):
            text[int(parts[0].strip()[:-1], 16)] = ' '.join(p.strip() for p in parts[2:]).replace('\t', ' ')
    return [text.get(address + 4 * i, '?') for i in range(len(words))]


def file_of(name, target):
    """The source file of the target whose INCLUDE_ASM or code names `name`."""
    for src in sorted(targets.get(target).src.glob('*.c')):
        if f', {name});' in src.read_text(encoding='utf-8') or f' {name}(' in src.read_text(encoding='utf-8'):
            return src
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source', type=Path)
    ap.add_argument('name')
    ap.add_argument('--target', default='main')
    ap.add_argument('--like', type=Path, help='build as this file of src/ is built')
    args = ap.parse_args()

    like = args.like or file_of(args.name, args.target)
    try:
        (funcs, relocs, (ro, ro_relocs), data), rodata = match.compiled_alone(args.source, args.name, args.target, like)
    except psyq.Failed as e:
        sys.exit(str(e))
    if args.name not in funcs:
        sys.exit(f'{args.name} is not in {args.source}')
    address, want = match.original(args.name, args.target)
    try:
        got = match.linked(funcs, relocs, args.name, address, args.target, rodata)
    except KeyError as e:
        sys.exit(f'unknown symbol or relocation {e}')
    mine, game = disassemble(got, address), disassemble(want, address)
    n = max(len(got), len(want))
    for i in range(n):
        a = mine[i] if i < len(got) else ''
        b = game[i] if i < len(want) else ''
        same = i < len(got) and i < len(want) and got[i] == want[i]
        print(f'{address + 4 * i:08X} {" " if same else "*"} {a:<40.40} | {b}')
    result = match.check(args.source, args.target, only={args.name}, like=like).get(args.name)
    print(f'{args.name}: {"OK" if result is None else result}')


if __name__ == '__main__':
    main()
