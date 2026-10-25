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
import atexit
import os
import re
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import auto_decomp as ad  # noqa: E402
import diff_func  # noqa: E402
import match  # noqa: E402
import psyq  # noqa: E402
import targets  # noqa: E402

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


TYPE = r'^(?:typedef\b[^\n]*?\b(\w+)\s*;|\}\s*(\w+)\s*;)$'


def after_types(text, lines):
    """decls.h with each of `lines` that names a type defined further down
    moved to the end, after it."""
    for line in lines:
        at = text.find(line + '\n')
        if at < 0:
            continue
        later = {a or b for a, b in re.findall(TYPE, text[at + len(line):], re.M)}
        if any(re.search(rf'\b{t}\b', line) for t in later):
            text = text[:at] + text[at + len(line) + 1:]
            text = text.replace(ad.END, line + '\n' + ad.END, 1)
    return text


def merged(known, decls, name, proto):
    """decls.h with the work file's declarations in it (replacing any for the
    same names) and `proto` as the function's own. A function already in C
    keeps the prototype of its definition. New types go at the end, in the
    work file's order, and a declaration that names a type defined further
    down moves after it."""
    out = ad.with_prototype(known, name, proto)
    in_c = ad.defined()
    mine = [proto]
    for d in decls:
        sym = symbol_of(d)
        if sym is None or sym == name or sym in in_c:
            continue
        if d.lstrip().startswith('typedef'):
            old = re.search(rf'^(?:typedef\b[^\n]*\b|\}}\s*){sym}\s*;$', out, re.M)
            if old is None:
                out = out.replace(ad.END, d + '\n' + ad.END, 1)
            elif old.group(0) != d:
                raise SystemExit(f'{sym} is already a type in decls.h ({old.group(0)!r}): give yours another name')
            continue
        old = ad.declaration(out, sym)
        if old is None:
            out = out.replace(ad.END, d + '\n' + ad.END, 1)
        elif old != d:
            if old.lstrip().startswith('typedef'):
                raise SystemExit(f'{sym} is already a type in decls.h ({old!r}): give yours another name')
            out = out.replace(old, d, 1)
        mine.append(d)
    return after_types(out, mine)


def standalone(work, name):
    """A file to compile for the work file: decls.h as merged() makes it,
    then the function. Returns (path, merged decls.h, function)."""
    decls, body = split_work(work.read_text(encoding='utf-8'), name)
    proto = ad.prototype(ad.HEAD.search(body).group(1))
    mine = merged(ad.DECLS.read_text(encoding='utf-8'), decls, name, proto)
    # One name per process: agents diffing the same NAME at once (two targets
    # can have one) must not compile each other's work.
    path = Path(tempfile.gettempdir()) / f'ff7_work_{os.getpid()}_{name}.c'
    path.write_text('#include "common.h"\n' + mine + '\n\n' + body, encoding='utf-8')
    atexit.register(path.unlink, missing_ok=True)
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
    if ad.TARGET == 'main':
        # Every overlay's decls.h includes main's: a symbol an overlay declares
        # itself would clash with another type in main's decls.h, and one it
        # uses undeclared (an implicit `int f()`) would get a prototype its
        # calls may not fit. A put into main declares those in its own file.
        for f in ROOT.glob('src/*/*'):
            if f.parent.name != 'main' and f.suffix in ('.c', '.h'):
                out |= set(re.findall(r'\b(?:func|D)_[0-9A-F]{8}\b', f.read_text(encoding='utf-8')))
    return out


def named_tables(asm_path, body):
    """The function's own rodata (splat moved it into its asm) that its C
    reads by name, as an extern: those tables stay asm, each in an asm file
    of its own for an INCLUDE_RODATA put right before the function.
    Returns ([(symbol, asm file text)], address of the rest of its rodata
    (what the compiler makes: jump tables, strings) or None)."""
    text = asm_path.read_text(encoding='utf-8')
    m = re.search(r'^\.section \.rodata\n(.*?)(?=^\.section \.text)', text, re.S | re.M)
    if not m:
        return [], None
    tables, rest, block = [], [], []
    for line in m.group(1).splitlines():
        block.append(line)
        end = re.match(r'\s*enddlabel (\w+)', line)
        if end:
            sym = end.group(1)
            # A table the C reads by name stays asm, and so does game data
            # next to it that the C reaches through it (an 8-byte struct
            # copied from D_801B0000 also reads D_801B0004): GCC makes only
            # jump tables and strings.
            data = '.asciz' not in '\n'.join(block)
            if not sym.startswith('jtbl_') and (data or re.search(rf'\b{sym}\b', body)):
                tables.append((sym, '.section .rodata\n' + '\n'.join(block).strip('\n') + '\n'))
            else:
                rest += re.findall(r'/\* [0-9A-F]+ ([0-9A-F]{8})', '\n'.join(block))
            block = []
    return tables, (min(int(a, 16) for a in rest) if rest else None)


def keep_unmigrated(sym, text):
    """Tell splat (config/symbols.us.<target>.txt) to keep a table out of its
    function's asm, so a split writes it as an asm file of its own again."""
    address = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8})', text).group(1)
    path = ROOT / 'config' / f'symbols.us.{ad.TARGET}.txt'
    if not path.exists():
        # The spells share symbols.us.magic.txt, where the line would hold for
        # all of them: such a target gets a symbol file of its own, listed
        # last in its splat config.
        ad.write(path, f'// Symbols of {ad.TARGET} alone (the others it shares are listed before).\n')
        config = targets.get(ad.TARGET).config
        yaml = config.read_text(encoding='utf-8')
        m = re.search(r'^(\s*)symbol_addrs_path:\n((?:\1  - .*\n)+)', yaml, re.M)
        entry = f'{m.group(1)}  - config/{path.name}\n'
        ad.write(config, yaml[:m.end()] + entry + yaml[m.end():])
    lines = path.read_text(encoding='utf-8').splitlines()
    for i, line in enumerate(lines):
        if re.match(rf'{sym}\s*=', line):
            if 'force_not_migration' not in line:
                lines[i] = line + (' force_not_migration:True' if '//' in line else ' // force_not_migration:True')
            break
    else:
        lines.append(f'{sym} = 0x{address}; // force_not_migration:True')
    ad.write(path, '\n'.join(lines) + '\n')


def compile_error(e):
    """What a failed compile says, without its warnings."""
    lines = [l for l in str(e).strip().splitlines() if 'warning:' not in l]
    return '\n'.join(lines)[-600:]


def overlays_match(known, mine):
    """For a put into main: None when every overlay file that uses a symbol
    whose declaration in main/decls.h changed (each overlay's decls.h includes
    main's) still compiles and matches, else what does not."""
    if ad.TARGET != 'main':
        return None
    old, new = set(known.splitlines()), set(mine.splitlines())
    syms = {symbol_of(l) for l in old ^ new if l.rstrip().endswith(';')} - {None}
    if not syms:
        return None
    uses = re.compile(r'\b(?:' + '|'.join(map(re.escape, sorted(syms))) + r')\b')
    try:
        for t, tg in targets.all_targets().items():
            if t == 'main':
                continue
            files = sorted(tg.src.glob('*.c'))
            if not (tg.decls.exists() and uses.search(tg.decls.read_text(encoding='utf-8'))):
                files = [f for f in files if uses.search(f.read_text(encoding='utf-8'))]
            if files:
                # Not ad.use(t): it may tidy the overlay's decls.h under the
                # lock this put already holds.
                ad.TARGET, ad.SRC, ad.DECLS, ad.ASM = t, tg.src, tg.decls, tg.asm
                for f in files:
                    why = ad.file_matches(f)
                    if why is not None:
                        return f'{t}: {why}'
    finally:
        ad.use('main')
    return None


def put(work, name):
    with ad.Turn():
        found = where(name)
        if found is None:
            raise SystemExit(f'{name} is not an INCLUDE_ASM of src/{ad.TARGET}/ (already in C?)')
        src, seg, asm_path = found
        path, mine, body, proto = standalone(work, name)
        tables, rest = named_tables(asm_path, body)
        try:
            why = match.check(path, ad.TARGET, only={name}, like=src,
                              rodata=rest if tables else None).get(name, 'not compiled')
        except psyq.Failed as e:
            why = 'does not compile: ' + compile_error(e)
        if why is not None:
            raise SystemExit(f'{name}: {why}')
        known = ad.DECLS.read_text(encoding='utf-8')
        before = src.read_text(encoding='utf-8')
        include = ad.INCLUDE.format(seg, name)
        written = []
        for sym, text in tables:
            table = ad.ASM / seg / f'{sym}.s'
            if not table.exists():
                table.write_text(text, encoding='utf-8', newline='\n')
                written.append(table)
        head = ''.join(include.replace('INCLUDE_ASM', 'INCLUDE_RODATA').replace(f', {name});', f', {sym});')
                       + '\n\n' for sym, _ in tables)
        placed = before.replace(include, head + body.rstrip('\n'), 1)
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
        # Any change to decls.h is checked against every file of the target,
        # and main's against the overlays that use what changed.
        why = ad.all_match() if mine != known else ad.file_matches(src)
        if why is None and mine != known:
            why = overlays_match(known, mine)
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
                    why2 = overlays_match(known, mine)
                if why2 is None:
                    for sym, text in tables:
                        keep_unmigrated(sym, text)
                    print(f'{name}: put in {src.relative_to(ROOT).as_posix()}, its changed declarations '
                          f'kept in the files that use them')
                    return
                for f, text in originals.items():
                    ad.write(f, text)
        if why is not None:
            ad.write(ad.DECLS, known)
            ad.write(src, before)
            for table in written:
                table.unlink()
            raise SystemExit(f'{name} matches alone, but not in its file: {why}; nothing changed')
        for sym, text in tables:
            keep_unmigrated(sym, text)
        print(f'{name}: put in {src.relative_to(ROOT).as_posix()}'
              + (f' (its tables {", ".join(s for s, _ in tables)} stay asm)' if tables else ''))


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
