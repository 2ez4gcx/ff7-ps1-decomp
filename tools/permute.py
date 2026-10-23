#!/usr/bin/env python3
"""Let decomp-permuter look for a form of a function that matches.

    python tools/permute.py WORK.c NAME [--target main] [--minutes 10] [--jobs 8]

WORK.c is a work file of tools/work.py (its own declarations, then the
function) that compiles but does not match yet. This sets up
build/us/permute/NAME/ for decomp-permuter
(https://github.com/simonlindholm/decomp-permuter, cloned to
$FF7_TOOLCHAIN/decomp-permuter): base.c is the work file with decls.h and
the headers expanded, `M2C_SFIELD` turned into named structs pycparser can
read, and compile.sh compiles a candidate as the function's file is built
and links it at its game address (tools/permute_cc.py), so only real
differences count. The permuter runs for --minutes; when it finds a form
that matches, its function replaces the one in WORK.c (written to
WORK.permuted.c) for `tools/work.py diff/put`.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import auto_decomp as ad  # noqa: E402
import psyq  # noqa: E402
import work  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
PERMUTER = psyq.TOOLS / 'decomp-permuter'


def sfield_structs(text, tag):
    """`M2C_SFIELD(expr, T *, off)` -> `((SF_tag_n *)(expr))->v`, with
    `typedef struct { s8 pad[off]; T v; } SF_tag_n;` lines to put first."""
    out, defs, seen = [], [], {}
    i = 0
    while True:
        at = text.find('M2C_SFIELD(', i)
        if at < 0:
            out.append(text[i:])
            break
        out.append(text[i:at])
        j, depth, args, cur = at + len('M2C_SFIELD('), 1, [], ''
        while depth:
            c = text[j]
            if c == '(':
                depth += 1
            elif c == ')':
                depth -= 1
                if depth == 0:
                    break
            if c == ',' and depth == 1:
                args.append(cur)
                cur = ''
            else:
                cur += c
            j += 1
        args.append(cur)
        expr, typ, off = (a.strip() for a in args)
        key = (typ, off)
        if key not in seen:
            seen[key] = f'SF_{tag}_{len(seen)}'
            elem = typ[:-1].strip() if typ.endswith('*') else typ
            pad = f's8 pad[{off}]; ' if off not in ('0', '0x0') else ''
            defs.append(f'typedef struct {{ {pad}{elem} v; }} {seen[key]};')
        out.append(f'(((({seen[key]} *)({expr}))->v))')
        i = j + 1
    return ''.join(out), defs


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('work', type=Path)
    ap.add_argument('name')
    ap.add_argument('--target', default='main')
    ap.add_argument('--minutes', type=float, default=10)
    ap.add_argument('--jobs', type=int, default=os.cpu_count() or 4)
    args = ap.parse_args()
    ad.use(args.target)
    found = work.where(args.name)
    if found is None:
        sys.exit(f'{args.name} is not an INCLUDE_ASM of src/{args.target}/')
    src = found[0]
    out = ROOT / 'build' / 'us' / 'permute' / args.name
    if out.exists():
        shutil.rmtree(out)
    out.mkdir(parents=True)

    path, mine, body, proto = work.standalone(args.work, args.name)
    text = path.read_text(encoding='utf-8')
    text, defs = sfield_structs(text, args.name[-8:])
    if defs:
        text = text.replace('#include "common.h"\n', '#include "common.h"\n' + '\n'.join(defs) + '\n', 1)
    pre = out / 'pre.c'
    pre.write_text(text, encoding='utf-8')
    env = dict(os.environ, TMPDIR=tempfile.gettempdir())
    base = subprocess.run([str(psyq.CPP), '-undef', '-P', '-DPERMUTER', '-Dmips', '-D__GNUC__=2',
                           '-I', str(ROOT / 'include'), '-I', str(ROOT / 'src'), str(pre)],
                          capture_output=True, text=True, env=env)
    if base.returncode:
        sys.exit(base.stderr)
    (out / 'base.c').write_text(base.stdout, encoding='utf-8')
    python = Path(sys.executable).as_posix()
    cc = (ROOT / 'tools' / 'permute_cc.py').as_posix()
    like = src.as_posix()
    subprocess.run([sys.executable, cc, '-', str(out / 'target.o'), args.name, args.target, like], check=True)
    (out / 'compile.sh').write_text(
        f'#!/bin/sh\n"{python}" "{cc}" "$1" "$3" {args.name} {args.target} "{like}"\n', encoding='utf-8', newline='\n')
    (out / 'settings.toml').write_text(
        f'func_name = "{args.name}"\ncompiler_type = "gcc"\n'
        f'objdump_command = "{Path(psyq.PREFIX).as_posix()}objdump -drz -m mips:3000"\n', encoding='utf-8')
    print(f'permuting {args.name} in {out} for {args.minutes} minutes', flush=True)
    # The permuter preprocesses base.c again with a `cpp` from PATH: GCC 2.6.3's.
    run_env = dict(os.environ, TMPDIR=tempfile.gettempdir(),
                   PATH=str(psyq.CPP.parent) + os.pathsep + os.environ.get('PATH', ''))
    try:
        subprocess.run([sys.executable, str(PERMUTER / 'permuter.py'), str(out), '-j', str(args.jobs),
                        '--stop-on-zero'], cwd=PERMUTER, timeout=args.minutes * 60, env=run_env)
    except subprocess.TimeoutExpired:
        pass
    results = sorted(out.glob('output-*'), key=lambda p: int(p.name.split('-')[1]))
    if not results:
        print('nothing better found')
        return
    best = results[0]
    score = int(best.name.split('-')[1])
    print(f'best score {score}: {best}')
    found_c = (best / 'source.c').read_text(encoding='utf-8')
    m = re.search(rf'^[A-Za-z_][\w \*]*?\b{args.name}\(.*\)\s*\{{$', found_c, re.M)
    if m is None:
        return
    function = work.body_of_text(found_c[m.start():]) if hasattr(work, 'body_of_text') else found_c[m.start():]
    decls, _ = work.split_work(args.work.read_text(encoding='utf-8'), args.name)
    result = args.work.with_suffix('.permuted.c')
    lines = ['#include "common.h"', f'#include "{args.target}/decls.h"', ''] + defs + decls + ['', function.rstrip()]
    result.write_text('\n'.join(lines) + '\n', encoding='utf-8')
    print(f'{"matches" if score == 0 else "closer"}: {result}')


if __name__ == '__main__':
    main()
