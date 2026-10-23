#!/usr/bin/env python3
"""Find where the game's source files (compile units) start, in a target.

    python tools/find_units.py [TARGET]

PSY-Q's linker starts each object's code on 8 bytes: a file whose code ends
4 bytes short of that is followed by one `nop` of padding, which splat
leaves at the end of the last function. So a function whose last
instruction is a `nop` after its `jr $ra` and its delay slot, with the next
function on 8 bytes, ends a source file. (A file that happens to end on 8
bytes leaves no trace, so this finds most boundaries, not all.) Prints the
first function of each file found.
"""
import argparse
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import targets  # noqa: E402


def boundaries(target):
    t = targets.get(target)
    image = t.image.read_bytes()
    starts = [a for a in match.code_starts(target)]
    syms = {}
    for name, a in match.symbols(target).items():
        if name.startswith(('func_', 'akao_', 'main_entry')) and 'NON_MATCHING' not in name:
            syms.setdefault(a, name)
    funcs = sorted(a for a in syms if t.origin <= a < t.origin + len(image))
    out = []
    for i, a in enumerate(funcs[:-1]):
        nxt = funcs[i + 1]
        words = struct.unpack(f'<{(nxt - a) // 4}I', image[a - t.origin:nxt - t.origin])
        if len(words) >= 3 and words[-1] == 0 and words[-3] == 0x03E00008 and nxt % 8 == 0:
            out.append((nxt, syms[nxt]))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('target', nargs='?', default='main')
    args = ap.parse_args()
    for a, name in boundaries(args.target):
        print(f'{a:08X} {name}')


if __name__ == '__main__':
    main()
