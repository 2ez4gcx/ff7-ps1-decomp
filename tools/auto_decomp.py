#!/usr/bin/env python3
"""Draft functions with m2c and keep the ones that match the game exactly.

    python tools/auto_decomp.py [--max 32] [--limit 200] [--dry-run] [NAME ...]

For each function of src/main/*.c still taken from asm (INCLUDE_ASM),
smallest first (at most --max instructions), m2c writes C from its asm with
the declarations of src/main/decls.h as context. The draft is compiled the
way its file is built (tools/psyq.py) and checked word for word
(tools/match.py); a function that matches replaces its INCLUDE_ASM, and the
declarations it needed join decls.h, its own prototype among them. When that
prototype replaces a guess m2c made earlier for a caller, every function
already in C is checked again, and the new one is undone if a caller no
longer matches. Anything else is left as it was and listed in
build/us/auto_decomp.txt with the reason, for a person to take on.

    python tools/auto_decomp.py --sync

only gives every function already in C a prototype in decls.h.
"""
import argparse
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import psyq  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
M2C = psyq.TOOLS / 'm2c' / 'm2c.py'
SRC = ROOT / 'src' / 'main'
DECLS = SRC / 'decls.h'
ASM = ROOT / 'asm' / 'us' / 'main' / 'nonmatchings'
INCLUDE = 'INCLUDE_ASM("../asm/us/main/nonmatchings/{}", {});'
END = '\n#endif /* MAIN_DECLS_H */'
HEAD = re.compile(r'^([A-Za-z_][\w \*]*?\b(\w+)\(.*\))\s*\{$', re.M)


def sources():
    return sorted(SRC.glob('*.c'))


def context():
    """decls.h with its includes expanded, for m2c's C parser."""
    stub = Path(tempfile.gettempdir()) / 'ff7_m2c_stub.c'
    stub.write_text('#include "common.h"\n#include "main/decls.h"\n', encoding='utf-8')
    env = dict(os.environ, TMPDIR=tempfile.gettempdir())
    out = subprocess.run([str(psyq.CPP), '-undef', '-P', '-DM2CTX', '-I', str(ROOT / 'include'),
                          '-I', str(ROOT / 'src'), str(stub)], capture_output=True, text=True, env=env).stdout
    ctx = Path(tempfile.gettempdir()) / 'ff7_m2c_context.c'
    ctx.write_text('\n'.join(l for l in out.splitlines() if not l.startswith('#')) + '\n', encoding='utf-8')
    return ctx


def draft(path, name, ctx):
    done = subprocess.run([sys.executable, str(M2C), '-t', 'mips-gcc-c', '--globals=used', '--valid-syntax',
                           '--comment-style=none', '--context', str(ctx), str(path)],
                          capture_output=True, text=True)
    if done.returncode or 'M2C_ERROR' in done.stdout:
        return None, None
    lines = done.stdout.rstrip().splitlines()
    head = next((i for i, l in enumerate(lines) if re.match(rf'^[\w\s\*]*\b{name}\(.*\)\s*\{{$', l)), None)
    if head is None:
        return None, None
    decls = [l for l in lines[:head] if l.strip()]
    return decls, '\n'.join(lines[head:]) + '\n'


def size_of(path):
    return len(re.findall(r'/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/', path.read_text(encoding='utf-8')))


def declaration(decls, name):
    """The line of decls.h that declares `name`, or None."""
    m = re.search(rf'^[^\n#]*\b{name}\b[^\n]*;$', decls, re.M)
    return m.group(0) if m else None


def with_prototype(decls, name, proto):
    """decls.h declaring `name` as `proto`: its line replaced, or one added."""
    old = declaration(decls, name)
    if old is not None:
        return decls.replace(old, proto, 1)
    return decls.replace(END, proto + '\n' + END, 1)


def defined():
    """{name: (source, prototype)} of the functions written in C."""
    out = {}
    for src in sources():
        for m in HEAD.finditer(src.read_text(encoding='utf-8')):
            out[m.group(2)] = (src, m.group(1) + ';')
    return out


def all_match():
    """None when every function in C still matches, else what does not."""
    by_file = {}
    for name, (src, _) in defined().items():
        by_file.setdefault(src, set()).add(name)
    for src, names in by_file.items():
        try:
            result = match.check(src, 'main', only=names)
        except psyq.Failed as e:
            return f'{src.name} does not compile: ' + str(e).strip().splitlines()[-1][:120]
        bad = sorted(n for n, why in result.items() if why is not None)
        if bad:
            return f'{", ".join(bad[:4])} in {src.name} no longer match'
    return None


def sync():
    """Give each function in C a prototype in decls.h, where it has none."""
    decls = DECLS.read_text(encoding='utf-8')
    added = 0
    for name, (_, proto) in sorted(defined().items()):
        if declaration(decls, name) is None:
            decls = with_prototype(decls, name, proto)
            added += 1
    DECLS.write_text(decls, encoding='utf-8', newline='\n')
    return added


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('names', nargs='*')
    ap.add_argument('--max', type=int, default=32, help='largest function tried, in instructions')
    ap.add_argument('--limit', type=int, default=200, help='functions tried this run')
    ap.add_argument('--dry-run', action='store_true', help='check, but change nothing')
    ap.add_argument('--sync', action='store_true', help='only add the prototypes decls.h lacks')
    args = ap.parse_args()
    if args.sync:
        print(f'{sync()} prototypes added to {DECLS.relative_to(ROOT)}')
        return

    todo = []
    for src in sources():
        for seg, name in re.findall(r'^INCLUDE_ASM\("[^"]*/nonmatchings/(\w+)", (\w+)\);$',
                                    src.read_text(encoding='utf-8'), re.M):
            path = ASM / seg / f'{name}.s'
            if (not args.names or name in args.names) and path.exists():
                todo.append((size_of(path), name, seg, src, path))
    todo = [t for t in sorted(todo) if t[0] <= args.max][:args.limit]
    log, kept = [], 0
    for _, name, seg, src, path in todo:
        decls, body = draft(path, name, context())
        if body is None:
            log.append(f'{name}: m2c could not draft it')
            continue
        known = DECLS.read_text(encoding='utf-8')
        new = [d for d in decls if d not in known and not re.search(rf'\b{name}\b', d)]
        proto = HEAD.search(body).group(1) + ';'
        mine = with_prototype(known, name, proto)
        if new:
            mine = mine.replace(END, '\n'.join(new) + '\n' + END, 1)
        test = Path(tempfile.gettempdir()) / f'ff7_try_{name}.c'
        test.write_text('#include "common.h"\n' + mine + '\n\n' + body, encoding='utf-8')
        try:
            why = match.check(test, 'main', only={name}, like=src).get(name, 'not compiled')
        except psyq.Failed as e:
            why = 'does not compile: ' + str(e).strip().splitlines()[-1][:120]
        test.unlink(missing_ok=True)
        if why is not None:
            log.append(f'{name}: {why}')
            continue
        if args.dry_run:
            kept += 1
            print(f'{name}: matches', flush=True)
            continue
        before = src.read_text(encoding='utf-8')
        DECLS.write_text(mine, encoding='utf-8', newline='\n')
        src.write_text(before.replace(INCLUDE.format(seg, name), body.rstrip('\n'), 1),
                       encoding='utf-8', newline='\n')
        old = declaration(known, name)
        if old is not None and old != proto:
            why = all_match()
            if why is not None:
                DECLS.write_text(known, encoding='utf-8', newline='\n')
                src.write_text(before, encoding='utf-8', newline='\n')
                log.append(f'{name}: matches alone, but its type {proto!r} breaks callers ({why})')
                continue
        kept += 1
        print(f'{name}: matches', flush=True)
    report = ROOT / 'build' / 'us' / 'auto_decomp.txt'
    report.write_text('\n'.join(log) + '\n', encoding='utf-8')
    print(f'{kept} of {len(todo)} matched; the rest are in {report.relative_to(ROOT)}')


if __name__ == '__main__':
    main()
