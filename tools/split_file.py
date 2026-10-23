#!/usr/bin/env python3
"""Split one C file of a target in two, where the game's source files change.

    python tools/split_file.py TARGET FILE NEW CODE_ADDRESS [RODATA_ADDRESS]

Every entry of src/TARGET/FILE.c (INCLUDE_ASM, INCLUDE_RODATA, function in C)
from CODE_ADDRESS on (rodata from RODATA_ADDRESS on) moves to
src/TARGET/NEW.c, its asm folder renamed, and the target's splat config
gets the matching `c` (and `.rodata`) subsegments. The block of the file's
own declarations goes to both files. Then run `tools/build.py --split`
for the target, and give NEW.c its options in tools/psyq.py if they differ.
Take the work lock first (build/us/work.lock) when others may be putting.
"""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import targets  # noqa: E402

ENTRY = re.compile(r'^(INCLUDE_ASM|INCLUDE_RODATA)\("[^"]+", (\w+)\);$')
HEAD = re.compile(r'^[A-Za-z_][\w \*]*?\b(\w+)\(.*\)\s*\{$')
SUB = re.compile(r'^(\s*)- \[(0x[0-9A-Fa-f]+), (\.?\w+), (\w+)\]\s*$', re.M)


def address(name, named):
    if name in named:
        return named[name]
    return int(re.search(r'([0-9A-F]{8})$', name).group(1), 16)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('target')
    ap.add_argument('file')
    ap.add_argument('new')
    ap.add_argument('code', type=lambda v: int(v, 16))
    ap.add_argument('rodata', nargs='?', type=lambda v: int(v, 16))
    args = ap.parse_args()
    t = targets.get(args.target)
    named = {}
    for path in (t.config.parent).glob('symbols.us.*.txt'):
        for m in re.finditer(r'^\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)', path.read_text(encoding='utf-8'), re.M):
            named[m.group(1)] = int(m.group(2), 16)

    src = t.src / f'{args.file}.c'
    lines = src.read_text(encoding='utf-8').split('\n')
    include = f'#include "{args.target}/decls.h"'
    assert lines[:2] == ['#include "common.h"', include], lines[:2]
    body = lines[2:]
    starts = []
    for k, line in enumerate(body):
        m, h = ENTRY.match(line), HEAD.match(line)
        if m or h:
            kind, n = (m.group(1), m.group(2)) if m else ('C', h.group(1))
            at = k
            while at > 0 and (body[at - 1].startswith('/*') or body[at - 1].startswith(' *')):
                at -= 1
            starts.append((at, kind, n))
    lead = '\n'.join(body[:starts[0][0]]).strip('\n')
    parts = {args.file: [lead] if lead else [], args.new: [lead] if lead else []}
    for i, (at, kind, n) in enumerate(starts):
        end = starts[i + 1][0] if i + 1 < len(starts) else len(body)
        chunk = '\n'.join(body[at:end]).strip('\n')
        limit = args.rodata if kind == 'INCLUDE_RODATA' else args.code
        later = limit is not None and address(n, named) >= limit
        if later:
            chunk = chunk.replace(f'/nonmatchings/{args.file}"', f'/nonmatchings/{args.new}"')
        parts[args.new if later else args.file].append(chunk)

    config = t.config.read_text(encoding='utf-8')
    subs = list(SUB.finditer(config))

    def insert_after(kind, offset):
        nonlocal config
        own = [m for m in SUB.finditer(config) if m.group(3) == kind and m.group(4) == args.file]
        if not own:
            sys.exit(f'{t.config.name} has no [.., {kind}, {args.file}]')
        m = own[0]
        line = f'{m.group(1)}- [{offset:#X}, {kind}, {args.new}]'.replace('0X', '0x')
        config = config[:m.end()] + '\n' + line + config[m.end():]

    insert_after('c', args.code - t.origin)
    if args.rodata is not None:
        insert_after('.rodata', args.rodata - t.origin)
    t.config.write_text(config, encoding='utf-8', newline='\n')
    for name, chunks in parts.items():
        (t.src / f'{name}.c').write_text('#include "common.h"\n' + include + '\n\n' + '\n\n'.join(chunks) + '\n',
                                         encoding='utf-8', newline='\n')
        print(f'src/{args.target}/{name}.c: {len(chunks)} entries')


if __name__ == '__main__':
    main()
