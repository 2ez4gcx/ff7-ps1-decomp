#!/usr/bin/env python3
"""Decompile one function by hand: start from a draft, compare, put it in.

    python tools/work.py show NAME [--target main] > work/NAME.c
    python tools/work.py diff work/NAME.c NAME [--target main]
    python tools/work.py put work/NAME.c NAME [--target main]

A work file is `#include "common.h"`, `#include "<target>/decls.h"`, any
declarations of its own, then the function. `show` writes one from m2c's
draft. A declaration in the work file replaces the one decls.h has for the
same name (and the function's own prototype comes from its definition), so
types can be fixed there. `diff` compiles the work file as the function's
source file is built and prints both codes side by side, `*` on each word
that differs. `put` checks that it matches, then replaces the function's
INCLUDE_ASM with it and moves its declarations into decls.h; if a changed
declaration makes another function stop matching, nothing is changed.
Several people (or agents) can `put` at once: they take turns.
"""
import argparse
import re
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import auto_decomp as ad  # noqa: E402
import diff_func  # noqa: E402
import match  # noqa: E402
import psyq  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]


def where(name):
    """(source file, folder name, asm path) of a function still in asm."""
    for src in ad.sources():
        m = re.search(rf'^INCLUDE_ASM\("[^"]*/nonmatchings/(\w+)", {name}\);$', src.read_text(encoding='utf-8'), re.M)
        if m:
            return src, m.group(1), ad.ASM / m.group(1) / f'{name}.s'
    return None


def split_work(text, name):
    """(declarations, function) of a work file. The function must be the last
    thing in it, with no data of its own: a static or constant table would be
    placed elsewhere once its whole file is compiled (GCC puts such data at
    the end of a file), so the game's tables stay in asm and are declared
    extern."""
    m = re.search(rf'^[A-Za-z_][\w \*]*?\b{name}\(.*\)\s*\{{$', text, re.M)
    if m is None:
        raise SystemExit(f'no definition of {name} in the work file')
    head = text[:m.start()]
    decls = [l for l in head.splitlines() if l.strip() and not l.startswith('#')]
    body = text[m.start():].rstrip() + '\n'
    depth, end = 0, None
    for i, c in enumerate(body):
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                end = i + 1
                break
    if end is None or body[end:].strip():
        raise SystemExit('the function must be the last thing in the work file')
    if re.search(r'\bstatic\b|\basm\s*\(|__asm__', body):
        raise SystemExit("no static data or asm in the function: keep the game's tables in asm (extern)")
    for d in decls:
        if '=' in d or re.search(r'\basm\s*\(|__asm__', d):
            raise SystemExit(f'only declarations before the function, no definitions: {d!r}')
    return decls, body


def symbol_of(decl):
    m = re.search(r'(\w+)\s*(?:\[[^\]]*\])*\s*(?:\(.*\))?\s*;$', decl)
    if m is None:
        return None
    # A function pointer, or an array of them: (*name)(...), (*name[])(...)
    pointer = re.search(r'\(\s*\*\s*(\w+)\s*(?:\[[^\]]*\]\s*)*\)', decl)
    if pointer:
        return pointer.group(1)
    m2 = re.search(r'\b(\w+)\s*\(', decl)                  # a prototype: name(...)
    if m2 and not decl.lstrip().startswith('extern'):
        return m2.group(1)
    return m.group(1)


def merged(known, decls, name, proto):
    """decls.h with the work file's declarations in it (replacing any for the
    same names) and `proto` as the function's own. A function already in C
    keeps the prototype of its definition."""
    out = ad.with_prototype(known, name, proto)
    in_c = ad.defined()
    for d in decls:
        sym = symbol_of(d)
        if sym is None or sym == name or sym in in_c:
            continue
        old = ad.declaration(out, sym)
        if old is None:
            out = out.replace(ad.END, d + '\n' + ad.END, 1)
        elif old != d:
            out = out.replace(old, d, 1)
    return out


def standalone(work, name):
    """A file to compile for the work file: decls.h as merged() makes it,
    then the function. Returns (path, merged decls.h, function)."""
    decls, body = split_work(work.read_text(encoding='utf-8'), name)
    proto = ad.HEAD.search(body).group(1) + ';'
    mine = merged(ad.DECLS.read_text(encoding='utf-8'), decls, name, proto)
    path = Path(tempfile.gettempdir()) / f'ff7_work_{name}.c'
    path.write_text('#include "common.h"\n' + mine + '\n\n' + body, encoding='utf-8')
    return path, mine, body, proto


def show(name):
    found = where(name)
    if found is None:
        raise SystemExit(f'{name} is not an INCLUDE_ASM of src/{ad.TARGET}/')
    src, seg, path = found
    decls, body = ad.draft(path, name, ad.context())
    if body is None:
        raise SystemExit(f'm2c could not draft {name}; its asm is {path.relative_to(ROOT)}')
    known = ad.DECLS.read_text(encoding='utf-8')
    new = [d for d in decls if d not in known and not re.search(rf'\b{name}\b', d)]
    print(f'/* {name}, from {src.relative_to(ROOT).as_posix()} (asm: {path.relative_to(ROOT).as_posix()}) */')
    print('#include "common.h"')
    print(f'#include "{ad.TARGET}/decls.h"')
    if new:
        print()
        print('\n'.join(new))
    print()
    print(body, end='')


LOCAL = '/* Declared here otherwise than in the other files (tools/work.py). */'


def with_local(text, decls):
    """A source file with `decls` in its block of its own declarations (made
    after the decls.h include if missing), replacing any for the same names."""
    include = f'#include "{ad.TARGET}/decls.h"\n'
    if LOCAL not in text:
        text = text.replace(include, include + '\n' + LOCAL + '\n', 1)
    start = text.index(LOCAL) + len(LOCAL) + 1
    end = text.index('\n\n', start - 1) + 1 if '\n\n' in text[start - 1:] else len(text)
    block = text[start:end].splitlines()
    for d in decls:
        sym = symbol_of(d)
        at = next((i for i, l in enumerate(block) if symbol_of(l) == sym), None)
        if at is None:
            block.append(d)
        else:
            block[at] = d
    return text[:start] + ''.join(l + '\n' for l in block) + text[end:]


def uses(text, sym):
    """Whether C code (not INCLUDE_ASM lines) of a file names `sym`."""
    return any(re.search(rf'\b{sym}\b', l) for l in text.splitlines()
               if not l.startswith(('INCLUDE_ASM', 'INCLUDE_RODATA')))


def localize(known, mine, src, before_src):
    """Files to write so that declarations the work file changed live in the
    files that use them instead of decls.h: the new one in `src`, the old
    one in each other file. {path: text}, or None if nothing to do."""
    changed = {}
    for line in mine.splitlines():
        if line.strip() and line not in known.splitlines() and line.rstrip().endswith(';'):
            sym = symbol_of(line)
            if sym:
                changed[sym] = line
    if not changed:
        return None
    decls = mine
    files = {}
    for sym, new in changed.items():
        old = ad.declaration(known, sym)
        decls = decls.replace(new + '\n', '', 1)
        for other in ad.sources():
            if other == src:
                continue
            text = files.get(other, other.read_text(encoding='utf-8'))
            if old is not None and uses(text, sym):
                files[other] = with_local(text, [old])
    files[src] = with_local(files.get(src, before_src), list(changed.values()))
    files[ad.DECLS] = decls
    if ad.TARGET == 'main':
        # The overlays include main/decls.h: those that use a symbol it no
        # longer declares get the old declaration in their own decls.h.
        for other in sorted((ROOT / 'src').glob('*/*.c')):
            target = other.parent.name
            if target == 'main':
                continue
            text = other.read_text(encoding='utf-8')
            for sym in changed:
                old = ad.declaration(known, sym)
                if old is None or not uses(text, sym):
                    continue
                header = other.parent / 'decls.h'
                h = files.get(header, header.read_text(encoding='utf-8') if header.exists() else None)
                end = f'\n#endif /* {target.upper()}_DECLS_H */'
                if h is None or end not in h or ad.declaration(h, sym) is not None:
                    continue
                files[header] = h.replace(end, '\n' + old + end, 1)
    return files


def local_block(text):
    """The declarations of a file's own block."""
    if LOCAL not in text:
        return []
    start = text.index(LOCAL) + len(LOCAL) + 1
    end = text.index('\n\n', start - 1) if '\n\n' in text[start - 1:] else len(text)
    return [l for l in text[start:end].splitlines() if l.strip()]


def locally_declared():
    """Symbols some source file declares in its own block."""
    out = set()
    for f in ad.sources():
        for line in local_block(f.read_text(encoding='utf-8')):
            sym = symbol_of(line)
            if sym:
                out.add(sym)
    return out


def put(work, name):
    with ad.Turn():
        found = where(name)
        if found is None:
            raise SystemExit(f'{name} is not an INCLUDE_ASM of src/{ad.TARGET}/ (already in C?)')
        src, seg, _ = found
        path, mine, body, proto = standalone(work, name)
        try:
            why = match.check(path, ad.TARGET, only={name}, like=src).get(name, 'not compiled')
        except psyq.Failed as e:
            why = 'does not compile: ' + str(e).strip()[-300:]
        if why is not None:
            raise SystemExit(f'{name}: {why}')
        known = ad.DECLS.read_text(encoding='utf-8')
        before = src.read_text(encoding='utf-8')
        placed = before.replace(ad.INCLUDE.format(seg, name), body.rstrip('\n'), 1)
        # A symbol some file declares in its own block stays out of decls.h:
        # this file gets its declaration in its own block too.
        own = locally_declared()
        mine_lines = mine.splitlines()
        mine_local = [l for l in mine_lines if l.rstrip().endswith(';') and l not in known.splitlines()
                      and symbol_of(l) in own]
        if mine_local:
            mine = ''.join(l + '\n' for l in mine_lines if l not in mine_local)
            placed = with_local(placed, mine_local)
        ad.write(ad.DECLS, mine)
        ad.write(src, placed)
        changed = [l for l in known.splitlines() if l.strip() and l not in mine.splitlines()]
        # Any change to decls.h is checked against every file of the target.
        why = ad.all_match() if mine != known else ad.file_matches(src)
        if why is not None and changed:
            # The other files may have been written with the old declarations:
            # keep each file's own.
            originals = {f: f.read_text(encoding='utf-8') for f in ad.sources()}
            files = localize(known, mine, src, placed)
            if files:
                for f, text in files.items():
                    ad.write(f, text)
                why2 = ad.all_match()
                if why2 is None:
                    print(f'{name}: put in {src.relative_to(ROOT).as_posix()}, its changed declarations '
                          f'kept in the files that use them')
                    return
                for f, text in originals.items():
                    ad.write(f, text)
        if why is not None:
            ad.write(ad.DECLS, known)
            ad.write(src, before)
            raise SystemExit(f'{name} matches alone, but not in its file: {why}; nothing changed')
        print(f'{name}: put in {src.relative_to(ROOT).as_posix()}')


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('command', choices=['show', 'diff', 'put'])
    ap.add_argument('args', nargs='+')
    ap.add_argument('--target', default='main')
    args = ap.parse_args()
    ad.use(args.target)
    if args.command == 'show':
        show(args.args[0])
        return
    work, name = Path(args.args[0]), args.args[1]
    if args.command == 'put':
        put(work, name)
        return
    found = where(name)
    like = found[0] if found else diff_func.file_of(name, args.target)
    path, _, _, _ = standalone(work, name)
    sys.argv = ['diff_func', str(path), name, '--target', args.target, '--like', str(like)]
    diff_func.main()


if __name__ == '__main__':
    main()
