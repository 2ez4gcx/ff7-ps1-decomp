#!/usr/bin/env python3
"""Reuse C written for one function on its copies elsewhere.

    python tools/propagate.py [--dry-run] [TARGET ...]

Many functions appear in several executables (the spell effects share
helpers), the same instructions with other addresses. For every function
still in asm in the targets named (all overlays by default), this looks for
a function already in C, in any target, whose asm is the same once symbol
names and addresses are set aside. The C is copied with its symbols renamed
the way the two asm files pair them, the declarations it needs come along,
and the copy goes through the same check and `put` as tools/work.py: it is
kept only if it matches.
"""
import argparse
import re
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import auto_decomp as ad  # noqa: E402
import targets  # noqa: E402
import work  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
SYMBOL = re.compile(r'\b(?:func|D|jtbl)_[0-9A-F]{8}\b|\.L[0-9A-F]{8}\b')
ROW = re.compile(r'/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/\s+(.*)$', re.M)


def shape(path, name):
    """(normalized instructions, symbols in order of first use) of a
    function's asm, or None. Symbols become S0, S1...; labels are kept apart
    (they do not appear in C)."""
    if not path.exists():
        return None
    text = path.read_text(encoding='utf-8')
    code = text.split('.section .text')[-1] if '.section .rodata' in text else text
    rows = ROW.findall(code)
    if not rows:
        return None
    names, out = [], []
    for row in rows:
        def sub(m):
            s = m.group(0)
            if s.startswith('.L'):
                return 'L'
            if s == name:
                return 'SELF'
            if s not in names:
                names.append(s)
            return f'S{names.index(s)}'
        out.append(SYMBOL.sub(sub, re.sub(r'\s+', ' ', row.strip())))
    return '\n'.join(out), names


def body_of(src, name):
    """The C definition of `name` in a source file."""
    text = src.read_text(encoding='utf-8')
    m = re.search(rf'^[A-Za-z_][\w \*]*?\b{name}\(.*\)\s*\{{$', text, re.M)
    if m is None:
        return None
    depth = 0
    for i in range(m.start(), len(text)):
        if text[i] == '{':
            depth += 1
        elif text[i] == '}':
            depth -= 1
            if depth == 0:
                return text[m.start():i + 1]
    return None


def index_done(all_targets):
    """{shape: (target, name, symbols, C body)} for functions in C."""
    out = {}
    for t in all_targets:
        tg = targets.get(t)
        for src in sorted(tg.src.glob('*.c')):
            text = src.read_text(encoding='utf-8')
            for m in ad.HEAD.finditer(text):
                name = m.group(2)
                path = next(tg.asm.glob(f'*/{name}.s'), None)
                if path is None:
                    continue
                sh = shape(path, name)
                if sh is None or sh[0] in out:
                    continue
                body = body_of(src, name)
                if body:
                    out[sh[0]] = (t, name, sh[1], body)
    return out


def needed_decls(source_target, body, names):
    """Declaration lines the body's symbols have in its target's decls."""
    tg = targets.get(source_target)
    text = tg.decls.read_text(encoding='utf-8') if tg.decls.exists() else ''
    lines = []
    for n in names:
        if not re.search(rf'\b{n}\b', body):
            continue
        d = ad.declaration(text, n)
        if d is None and source_target != 'main':
            d = ad.declaration(targets.get('main').decls.read_text(encoding='utf-8'), n)
        if d is not None and d not in lines:
            lines.append(d)
    return lines


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('names', nargs='*', help='targets to fill (default: every overlay)')
    ap.add_argument('--dry-run', action='store_true')
    args = ap.parse_args()
    every = list(targets.all_targets())
    wanted = args.names or [t for t in every if t != 'main']
    done = index_done(every)
    print(f'{len(done)} distinct functions in C to copy from', flush=True)
    put = 0
    for t in wanted:
        ad.use(t)
        for src in ad.sources():
            for seg, name in re.findall(r'^INCLUDE_ASM\("[^"]*/nonmatchings/(\w+)", (\w+)\);$',
                                        src.read_text(encoding='utf-8'), re.M):
                sh = shape(ad.ASM / seg / f'{name}.s', name)
                if sh is None or sh[0] not in done:
                    continue
                from_target, from_name, from_syms, body = done[sh[0]]
                mapping = dict(zip(from_syms, sh[1]))
                mapping[from_name] = name
                rename = lambda s: SYMBOL.sub(lambda m: mapping.get(m.group(0), m.group(0)), s)
                decls = [rename(d) for d in needed_decls(from_target, body, list(mapping))]
                text = ('#include "common.h"\n' + f'#include "{t}/decls.h"\n\n' + '\n'.join(decls) + '\n\n'
                        + rename(body) + '\n')
                path = Path(tempfile.gettempdir()) / f'ff7_copy_{t}_{name}.c'
                path.write_text(text, encoding='utf-8')
                if args.dry_run:
                    print(f'{t} {name}: from {from_target} {from_name}')
                    continue
                try:
                    work.put(path, name)
                    put += 1
                except SystemExit as e:
                    print(f'{t} {name}: not kept ({str(e)[:100]})', flush=True)
                finally:
                    path.unlink(missing_ok=True)
    print(f'{put} functions copied')


if __name__ == '__main__':
    main()
