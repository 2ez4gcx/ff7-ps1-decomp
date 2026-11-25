#!/usr/bin/env python3
"""Find functions still in asm that have a twin already in C, and start from the twin's C.

    python tools/twins.py scan [--ops] [--min 0.85] [--only magic|other]
    python tools/twins.py diff SRC_TARGET:NAME DST_TARGET:NAME
    python tools/twins.py port SRC_TARGET:NAME DST_TARGET:NAME OUT.c [--skip-dst I,J] [--skip-src I,J]

Many functions exist in several executables (the spell effects share helpers, some menus and minigames
repeat each other) with a few edits: other constants, a case more or less, an early exit, a field at another
offset. tools/propagate.py copies a function only when the asm is identical once symbols are renamed; these tools
cover the near twins.

scan   ranks every function still in asm by its most similar functions already in C (instruction streams with
       symbols masked, difflib ratio; --ops masks registers and immediates as well, so two functions that differ
       only in register allocation or constants count as equal). A twin at 0.87 or more is usually a port with a
       few edits; --ops 0.92 or more has the same operations.
diff   shows where two functions differ in propagate.py's normalized form (symbols as S0, S1... in order of
       first use) and how their symbols pair. A pairing that goes off by one at some row means one function uses a
       symbol the other does not there: give port the indices to skip.
port   writes a work file for DST's function from the C of SRC's, with its symbols renamed by that pairing (the
       declarations it needs come along), to be checked with tools/work.py diff OUT.c NAME --target DST_TARGET and
       edited until it matches. --skip-dst drops symbols of the destination (0-based, in order of first use) and
       --skip-src those of the source that have no counterpart, so the rest pair up; the pairing is printed.
"""
import argparse
import difflib
import glob
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import auto_decomp as ad  # noqa: E402
import propagate as pp  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
REG = re.compile(r'\$(?:zero|at|v[01]|a[0-3]|t[0-9]|s[0-8]|k[01]|gp|sp|fp|ra|\d+)\b')
ROW = re.compile(r'^\s+/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s+(\S+)\s*(.*)$')


def asm_file(target, name):
    found = sorted((ROOT / 'asm' / 'us' / target / 'nonmatchings').glob(f'*/{name}.s'))
    if not found:
        sys.exit(f'no asm file for {target}:{name}')
    return found[0]


def rows(path, mask_all):
    out = []
    for line in open(path, encoding='utf-8', errors='replace'):
        m = ROW.match(line.rstrip())
        if not m:
            continue
        rest = re.sub(r'%(hi|lo)\([^)]*\)', 'SYM', m.group(2))
        rest = re.sub(r'func_[0-9A-F]+|D_[0-9A-F]+|\.L[0-9A-F]+|jtbl_[0-9A-F]+', 'X', rest)
        if mask_all:
            rest = REG.sub('R', rest)
            rest = re.sub(r'-?0x[0-9A-Fa-f]+|-?\b\d+\b', 'N', rest)
        out.append(m.group(1) + ' ' + rest.strip())
    return out


def scan(args):
    asm_left = set()
    for src in glob.glob(str(ROOT / 'src' / '*' / '*.c')):
        target = Path(src).parent.name
        for name in re.findall(r'^INCLUDE_ASM\("[^"]*", (\w+)\);$', Path(src).read_text(encoding='utf-8'), re.M):
            asm_left.add((target, name))
    pool = []
    for p in glob.glob(str(ROOT / 'asm' / 'us' / '*' / 'nonmatchings' / '*' / '*.s')):
        p = Path(p)
        target, name = p.parts[-4], p.stem
        if name.startswith('func_'):
            pool.append((target, name, (target, name) not in asm_left, rows(p, args.ops)))
    in_c = [x for x in pool if x[2] and len(x[3]) >= 20]
    todo = [x for x in pool if not x[2] and len(x[3]) >= 20
            and (args.only is None or x[0].startswith('magic_') == (args.only == 'magic'))]
    todo.sort(key=lambda x: len(x[3]))
    print(f'{len(todo)} functions in asm, {len(in_c)} in C', flush=True)
    slack = 12 if args.ops else 10
    for target, name, _, mine in todo:
        found = []
        for ct, cn, _, other in in_c:
            if abs(len(other) - len(mine)) > max(4, len(mine) // slack):
                continue
            sm = difflib.SequenceMatcher(None, mine, other, autojunk=False)
            if sm.real_quick_ratio() < args.min or sm.quick_ratio() < args.min:
                continue
            ratio = sm.ratio()
            if ratio >= args.min:
                found.append((ratio, ct, cn, len(other)))
        if found:
            found.sort(reverse=True)
            print(f'{target}:{name} {len(mine)} ' + ' | '.join(f'{ct}:{cn} {n} {r:.2f}' for r, ct, cn, n in found[:3]),
                  flush=True)


def shape_of(arg):
    target, name = arg.split(':')
    return pp.shape(asm_file(target, name), name)


def diff(args):
    (a, an), (b, bn) = shape_of(args.src), shape_of(args.dst)
    ra, rb = a.split('\n'), b.split('\n')
    print(len(ra), len(rb), 'rows;', len(an), len(bn), 'symbols')
    shown = 0
    for i, (x, y) in enumerate(zip(ra, rb)):
        if x != y:
            print(i, '|', x, '|', y)
            shown += 1
            if shown >= 25:
                break
    print('symbols in order (source -> destination):')
    for x, y in list(zip(an, bn))[:80]:
        print(' ', x, '->', y)


def indices(text):
    return {int(x) for x in text.split(',') if x}


def port(args):
    (st, sn), (dt, dn) = args.src.split(':'), args.dst.split(':')
    ssh, dsh = shape_of(args.src), shape_of(args.dst)
    ad.use(st)
    src = next((s for s in ad.sources()
                if re.search(rf'^[A-Za-z_][\w \*]*?\b{sn}\(.*\)\s*\{{$', s.read_text(encoding='utf-8'), re.M)), None)
    if src is None:
        sys.exit(f'{sn} is not in C in src/{st}/')
    body = pp.body_of(src, sn)
    skip_s, skip_d = indices(args.skip_src), indices(args.skip_dst)
    ssyms = [s for i, s in enumerate(ssh[1]) if i not in skip_s]
    dsyms = [s for i, s in enumerate(dsh[1]) if i not in skip_d]
    if len(ssyms) != len(dsyms):
        print('warning: symbol counts differ', len(ssyms), len(dsyms))
    mapping = dict(zip(ssyms, dsyms))
    mapping[sn] = dn
    for k, v in mapping.items():
        print(' ', k, '->', v)
    rename = lambda s: pp.SYMBOL.sub(lambda m: mapping.get(m.group(0), m.group(0)), s)
    decls = [rename(d) for d in pp.needed_decls(st, body, list(mapping), src, dt)]
    out = Path(args.out)
    out.write_text('#include "common.h"\n' + f'#include "{dt}/decls.h"\n\n' + '\n'.join(decls) + '\n\n'
                   + rename(body) + '\n', encoding='utf-8', newline='\n')
    print(f'wrote {out}: {len(body.splitlines())} lines from {src.relative_to(ROOT)}')
    print(f'next: .venv/Scripts/python tools/work.py diff {out} {dn} --target {dt}')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    p = sub.add_parser('scan')
    p.add_argument('--ops', action='store_true', help='mask registers and immediates as well')
    p.add_argument('--min', type=float, default=0.85)
    p.add_argument('--only', choices=['magic', 'other'], help='spell targets only, or everything else')
    p.set_defaults(run=scan)
    p = sub.add_parser('diff')
    p.add_argument('src')
    p.add_argument('dst')
    p.set_defaults(run=diff)
    p = sub.add_parser('port')
    p.add_argument('src')
    p.add_argument('dst')
    p.add_argument('out')
    p.add_argument('--skip-dst', default='')
    p.add_argument('--skip-src', default='')
    p.set_defaults(run=port)
    args = ap.parse_args()
    args.run(args)


if __name__ == '__main__':
    main()
