#!/usr/bin/env python3
"""Run decomp-permuter over near misses, one after the other.

    python tools/permute_all.py LIST [--minutes 20] [--jobs 8]

LIST has one `TARGET NAME WORK.c` per line: functions still in asm whose
work file compiles but differs a little. Each gets tools/permute.py for
--minutes; one that reaches a match is put in with tools/work.py put.
A line whose function is already in C is skipped.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('list', type=Path)
    ap.add_argument('--minutes', type=float, default=20)
    ap.add_argument('--jobs', type=int, default=8)
    args = ap.parse_args()
    py = sys.executable
    for line in args.list.read_text(encoding='utf-8').splitlines():
        if not line.strip() or line.startswith('#'):
            continue
        target, name, work = line.split(maxsplit=2)
        srcs = ''.join(p.read_text(encoding='utf-8') for p in (ROOT / 'src' / target).glob('*.c'))
        if not re.search(rf'^INCLUDE_ASM\("[^"]+", {name}\);$', srcs, re.M):
            print(f'{name}: already in C', flush=True)
            continue
        done = subprocess.run([py, str(ROOT / 'tools' / 'permute.py'), work, name, '--target', target,
                               '--minutes', str(args.minutes), '--jobs', str(args.jobs)],
                              capture_output=True, text=True)
        tail = (done.stdout.strip().splitlines() or [''])[-1]
        print(f'{name}: {tail}', flush=True)
        if tail.startswith('matches: '):
            result = tail[len('matches: '):]
            put = subprocess.run([py, str(ROOT / 'tools' / 'work.py'), 'put', result, name, '--target', target],
                                 capture_output=True, text=True)
            print(f'{name}: {(put.stdout + put.stderr).strip().splitlines()[-1]}', flush=True)


if __name__ == '__main__':
    main()
