#!/usr/bin/env python3
"""How much of the game is in C: functions and code bytes, per group of targets.

    python tools/progress.py [--targets]

A function counts as in C when its source file defines it, as asm while it
is an INCLUDE_ASM. Code bytes are the functions' sizes in the built ELFs
(build/us/*.elf, from tools/build.py), so build first.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import psyq  # noqa: E402
import targets  # noqa: E402

HEAD = re.compile(r'^[A-Za-z_][\w \*]*?\b(\w+)\(.*\)\s*\{$', re.M)
INCLUDE = re.compile(r'^INCLUDE_ASM\("[^"]*", (\w+)\);$', re.M)


def group(name):
    if name == 'main':
        return 'main executable'
    if name.startswith('magic_'):
        return 'spell effects (MAGIC)'
    if name.endswith('menu'):
        return 'menus'
    if name in ('chocobo', 'condor', 'highway', 'jet', 'snobo', 'snobo2', 'submar'):
        return 'minigames'
    if name in ('battle', 'brom', 'batini', 'batres'):
        return 'battle'
    return name


def sizes(elf):
    """{function: size} of an ELF's text symbols."""
    if not elf.exists():
        return {}
    out = subprocess.run([psyq.PREFIX + 'nm', '-S', '--defined-only', str(elf)],
                         capture_output=True, text=True).stdout
    found = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 4 and parts[2] in 'tT':
            found[parts[3]] = int(parts[1], 16)
    return found


def count(target):
    """(functions in C, functions in asm, bytes in C, bytes in asm)."""
    c, asm = set(), set()
    for src in sorted(target.src.glob('*.c')):
        text = src.read_text(encoding='utf-8')
        c |= {n for n in HEAD.findall(text) if not n.startswith('__maspsx')}
        asm |= {n for n in INCLUDE.findall(text) if not n.startswith(('D_', 'jtbl_'))}
    size = sizes(target.elf)
    return len(c), len(asm), sum(size.get(n, 0) for n in c), sum(size.get(n, 0) for n in asm)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--targets', action='store_true', help='one line per target, not per group')
    args = ap.parse_args()
    rows = {}
    for name, target in targets.all_targets().items():
        key = name if args.targets else group(name)
        row = rows.setdefault(key, [0, 0, 0, 0, 0])
        for i, v in enumerate(count(target)):
            row[i] += v
        row[4] += 1
    total = [sum(r[i] for r in rows.values()) for i in range(5)]
    print(f'{"":24} {"files":>5} {"functions in C":>16} {"code in C":>18}')
    for key, (c, a, cb, ab, n) in list(rows.items()) + [('all', total)]:
        f = 100 * c / (c + a) if c + a else 0
        b = 100 * cb / (cb + ab) if cb + ab else 0
        print(f'{key:24} {n:5} {c:6}/{c + a:<6} {f:5.1f}% {cb:8}/{cb + ab:<8} {b:5.1f}%')


if __name__ == '__main__':
    main()
