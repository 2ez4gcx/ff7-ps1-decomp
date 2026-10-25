#!/usr/bin/env python3
"""Draft functions with m2c and keep the ones that match the game exactly.

    python tools/auto_decomp.py [--target main] [--max 32] [--limit 200] [--dry-run] [NAME ...]

For each function of src/<target>/*.c still taken from asm (INCLUDE_ASM),
smallest first (at most --max instructions), m2c writes C from its asm with
the declarations of src/<target>/decls.h as context (an overlay's include
the main executable's). The draft is compiled the
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
import atexit
import os
import re
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import psyq  # noqa: E402
import targets  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
M2C = psyq.TOOLS / 'm2c' / 'm2c.py'
TARGET = 'main'
SRC = ROOT / 'src' / 'main'
DECLS = SRC / 'decls.h'
ASM = ROOT / 'asm' / 'us' / 'main' / 'nonmatchings'
INCLUDE = 'INCLUDE_ASM("../asm/us/main/nonmatchings/{}", {});'
END = '\n#endif /* MAIN_DECLS_H */'


def use(name):
    """Work on target `name` (main, field, battle...): its sources, its
    declarations (made if missing) and its asm."""
    global TARGET, SRC, DECLS, ASM, INCLUDE, END
    t = targets.get(name)
    TARGET, SRC, DECLS, ASM = name, t.src, t.decls, t.asm
    INCLUDE = 'INCLUDE_ASM("../' + t.asm.relative_to(ROOT).as_posix() + '/{}", {});'
    guard = f'{name.upper()}_DECLS_H'
    END = f'\n#endif /* {guard} */'
    if not DECLS.exists():
        write(DECLS, f'/* Declarations the C of src/{name}/ uses (tools/auto_decomp.py adds to this). */\n'
                     f'#ifndef {guard}\n#define {guard}\n\n#include "main/decls.h"\n\n#endif /* {guard} */\n')
    if name != 'main' and DECLS.exists():
        drop_main_duplicates()
    # Each source file sees them (splat writes new ones with common.h only).
    include = f'#include "{name}/decls.h"'
    for src in sources():
        text = src.read_text(encoding='utf-8')
        if include not in text and text.startswith('#include "common.h"\n'):
            with Turn():
                text = src.read_text(encoding='utf-8')
                if include not in text and text.startswith('#include "common.h"\n'):
                    write(src, text.replace('#include "common.h"\n', f'#include "common.h"\n{include}\n', 1))


def drop_main_duplicates():
    """An overlay's decls.h may hold guesses about the main executable's
    symbols from before they were decompiled; where main/decls.h now says
    otherwise, its declaration is the one to keep."""
    main = targets.get('main').decls.read_text(encoding='utf-8')
    text = DECLS.read_text(encoding='utf-8')
    keep = []
    for line in text.splitlines():
        m = re.search(r'\b((?:func|D)_[0-9A-F]{8})\b', line)
        theirs = declaration(main, m.group(1)) if m and line.rstrip().endswith(';') else None
        if theirs is not None and theirs != line:
            continue
        keep.append(line)
    new = '\n'.join(keep) + '\n'
    if new != text:
        with Turn():
            write(DECLS, new)


def write(path, text):
    """Replace a file's contents at once: another process reading it meanwhile
    sees the old file or the new one, never a part of either."""
    tmp = path.with_name(f'.{path.name}.{os.getpid()}.tmp')
    tmp.write_text(text, encoding='utf-8', newline='\n')
    for _ in range(50):
        try:
            os.replace(tmp, path)
            return
        except PermissionError:                 # Windows: a reader has it open
            time.sleep(0.1)
    os.replace(tmp, path)


HEAD = re.compile(r'^([A-Za-z_][\w \*]*?\b(\w+)\(.*\))\s*\{$', re.M)


def sources():
    return sorted(SRC.glob('*.c'))


def context():
    """decls.h with its includes expanded, for m2c's C parser."""
    stub = Path(tempfile.gettempdir()) / f'ff7_m2c_stub_{os.getpid()}_{TARGET}.c'
    stub.write_text(f'#include "common.h"\n#include "{TARGET}/decls.h"\n', encoding='utf-8')
    env = dict(os.environ, TMPDIR=tempfile.gettempdir())
    out = subprocess.run([str(psyq.CPP), '-undef', '-P', '-DM2CTX', '-I', str(ROOT / 'include'),
                          '-I', str(ROOT / 'src'), str(stub)], capture_output=True, text=True, env=env).stdout
    ctx = Path(tempfile.gettempdir()) / f'ff7_m2c_context_{os.getpid()}_{TARGET}.c'
    ctx.write_text('\n'.join(l for l in out.splitlines() if not l.startswith('#')) + '\n', encoding='utf-8')
    for f in (stub, ctx):
        atexit.register(f.unlink, missing_ok=True)
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


def strings_of(path):
    """{symbol: C string literal} for the strings in a function's rodata."""
    text = path.read_text(encoding='utf-8')
    if '.section .rodata' not in text:
        return {}
    return {sym: f'"{s}"' for sym, s in
            re.findall(r'^dlabel (\w+)\n\s*/\* [0-9A-F]+ [0-9A-F]{8} \*/ \.asciz "((?:[^"\\]|\\.)*)"\n'
                       r'(?:.*\n)*?enddlabel \1$', text, re.M)}


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


def prototype(head):
    """The declaration for a definition's head. One with bare parameter
    names, `f(arg0)` (old style, so callers may pass any arguments), is
    declared `f()`: `f(arg0);` is no declaration C (or m2c) accepts."""
    m = re.match(r'(.*?\w)\s*\((.*)\)$', head)
    params = m.group(2).strip()
    if params and params != 'void' and re.fullmatch(r'\w+(\s*,\s*\w+)*', params):
        return m.group(1) + '();'
    return head + ';'


def defined():
    """{name: (source, prototype)} of the functions written in C."""
    out = {}
    for src in sources():
        for m in HEAD.finditer(src.read_text(encoding='utf-8')):
            out[m.group(2)] = (src, prototype(m.group(1)))
    return out


def file_matches(src):
    """None when every function in C in one source file still matches (its
    rodata too: a function may not bring data that lands elsewhere when the
    whole file is compiled), else what does not."""
    names = {n for n, (s, _) in defined().items() if s == src}
    try:
        result = match.check(src, TARGET, only=names)
    except psyq.Failed as e:
        return f'{src.name} does not compile: ' + str(e).strip().splitlines()[-1][:120]
    bad = sorted(n for n, why in result.items() if why is not None)
    if bad:
        return f'{", ".join(bad[:4])} in {src.name} no longer match ({result[bad[0]]})'
    return None


def all_match():
    """None when every function in C still matches, else what does not."""
    by_file = {}
    for name, (src, _) in defined().items():
        by_file.setdefault(src, set()).add(name)
    for src, names in by_file.items():
        try:
            result = match.check(src, TARGET, only=names)
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
    write(DECLS, decls)
    return added


# Lines of a draft that are plain statements: an assignment or a call.
STATEMENT = re.compile(r'^(\s+)(?!(?:if|else|for|while|do|return|switch|case|default|goto|break|continue)\b)'
                       r'[^;{}]*[=(][^;{}]*;$')


def variants(body, limit=40):
    """The draft, then forms of it GCC may compile differently: fields as
    struct members (M2C_SFIELD), and each pair of neighbouring statements
    swapped (GCC reorders some loads and stores, so the game's order of
    statements is not always the order of its instructions)."""
    forms = [body]
    if 'M2C_FIELD(' in body:
        forms.append(body.replace('M2C_FIELD(', 'M2C_SFIELD('))
    out = list(forms)
    for form in forms:
        lines = form.split('\n')
        for i in range(len(lines) - 1):
            a, b = STATEMENT.match(lines[i]), STATEMENT.match(lines[i + 1])
            if a and b and a.group(1) == b.group(1):
                swapped = lines[:i] + [lines[i + 1], lines[i]] + lines[i + 2:]
                out.append('\n'.join(swapped))
    return out[:limit]


def attempt(name, src, path, ctx, known):
    """Draft `name` and look for a form of it that matches: (body, decls of
    it, decls.h as it would be) or (None, why)."""
    # Without its own prototype: that is only a guess m2c made for a caller.
    own = Path(tempfile.gettempdir()) / f'ff7_m2c_context_{os.getpid()}_{name}.c'
    own.write_text(''.join(l for l in ctx.read_text(encoding='utf-8').splitlines(keepends=True)
                           if not re.search(rf'\b{name}\s*\(', l)), encoding='utf-8')
    decls, body = draft(path, name, own)
    own.unlink(missing_ok=True)
    if body is None:
        return None, 'm2c could not draft it'
    # A global m2c could only call a pointer: let it be read through too.
    decls = [re.sub(r'^extern void \*', 'extern u8 *', d) for d in decls]
    # The function's own strings (splat moved them into its asm) become
    # string literals again: the compiler puts them back in its rodata.
    for sym, text in strings_of(path).items():
        body = re.sub(rf'\(\s*[\w\s\*]+\)\s*&{sym}\b|&{sym}\b|\b{sym}\b', lambda m: text, body)
        decls = [d for d in decls if not re.search(rf'\b{sym}\b', d)]
    new = [d for d in decls if d not in known and not re.search(rf'\b{name}\b', d)]
    proto = prototype(HEAD.search(body).group(1))
    mine = with_prototype(known, name, proto)
    if new:
        mine = mine.replace(END, '\n'.join(new) + '\n' + END, 1)
    first = None
    for k, form in enumerate(variants(body)):
        test = Path(tempfile.gettempdir()) / f'ff7_try_{name}_{k}.c'
        test.write_text('#include "common.h"\n' + mine + '\n\n' + form, encoding='utf-8')
        try:
            why = match.check(test, TARGET, only={name}, like=src).get(name, 'not compiled')
        except psyq.Failed as e:
            why = 'does not compile: ' + str(e).strip().splitlines()[-1][:120]
        test.unlink(missing_ok=True)
        if why is None:
            return (form, new, proto), None
        if first is None:
            first = why
        if why.startswith('does not compile'):
            break
    return None, first


LOCK = ROOT / 'build' / 'us' / 'work.lock'


class Turn:
    """One `put` at a time, across processes."""

    def __enter__(self):
        LOCK.parent.mkdir(parents=True, exist_ok=True)
        for _ in range(6000):
            try:
                self.fd = os.open(LOCK, os.O_CREAT | os.O_EXCL | os.O_WRONLY)
                return self
            except FileExistsError:
                time.sleep(0.1)
        raise SystemExit(f'{LOCK} is held; remove it if no put is running')

    def __exit__(self, *exc):
        os.close(self.fd)
        os.unlink(LOCK)


def apply(name, seg, src, form, new, proto):
    """Put a matching function in its file and its declarations in decls.h;
    None when done, else why not (and nothing changed)."""
    with Turn():
        return _apply(name, seg, src, form, new, proto)


def _apply(name, seg, src, form, new, proto):
    known = DECLS.read_text(encoding='utf-8')
    for d in new:
        sym = re.search(r'(\w+)(?:\[\w*\])*(?:\(.*\))?;$', d)
        if sym and declaration(known, sym.group(1)) not in (None, d):
            return f'{sym.group(1)} is declared otherwise since: {declaration(known, sym.group(1))!r}'
    mine = with_prototype(known, name, proto)
    new = [d for d in new if d not in mine]
    if new:
        mine = mine.replace(END, '\n'.join(new) + '\n' + END, 1)
    before = src.read_text(encoding='utf-8')
    write(DECLS, mine)
    write(src, before.replace(INCLUDE.format(seg, name), form.rstrip('\n'), 1))
    old = declaration(known, name)
    why = all_match() if old is not None and old != proto else file_matches(src)
    if why is not None:
        write(DECLS, known)
        write(src, before)
        return f'matches alone, but not in its file ({why})'
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('names', nargs='*')
    ap.add_argument('--target', default='main', help='src/<target>: main, field, battle...')
    ap.add_argument('--max', type=int, default=32, help='largest function tried, in instructions')
    ap.add_argument('--limit', type=int, default=200, help='functions tried this run')
    ap.add_argument('--jobs', type=int, default=os.cpu_count() or 4, help='functions tried at once')
    ap.add_argument('--dry-run', action='store_true', help='check, but change nothing')
    ap.add_argument('--sync', action='store_true', help='only add the prototypes decls.h lacks')
    args = ap.parse_args()
    use(args.target)
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
    # Drafted in batches against the declarations as they stand, then put in
    # one at a time, so each batch sees what the one before it added.
    batch = max(1, args.jobs * 4)
    for at in range(0, len(todo), batch):
        part = todo[at:at + batch]
        ctx, known = context(), DECLS.read_text(encoding='utf-8')
        with ThreadPoolExecutor(args.jobs) as pool:
            results = list(pool.map(lambda t: attempt(t[1], t[3], t[4], ctx, known), part))
        for (_, name, seg, src, path), (found, why) in zip(part, results):
            if found is not None and not args.dry_run:
                why = apply(name, seg, src, *found)
            if why is not None:
                log.append(f'{name}: {why}')
                continue
            kept += 1
            print(f'{name}: matches', flush=True)
    report = ROOT / 'build' / 'us' / 'auto_decomp.txt'
    report.write_text('\n'.join(log) + '\n', encoding='utf-8')
    print(f'{kept} of {len(todo)} matched; the rest are in {report.relative_to(ROOT)}')


if __name__ == '__main__':
    main()
