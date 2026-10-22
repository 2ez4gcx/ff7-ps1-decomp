#!/usr/bin/env python3
"""Rebuild the game's executables from this repository and check them.

    python tools/build.py            # split if needed, assemble, link, compare
    python tools/build.py --split    # run splat again first (after config changes)

Each target is one splat config in config/. Its asm (and later C) is
assembled into build/<region>/, linked with the linker script splat writes,
and the result must match the original file on the player's disc byte for
byte (its SHA-1 is in the config). Tools: the mipsel GNU binutils (set
MIPSEL_PREFIX, default D:/FF7/toolchain/mipsel/bin/mipsel-none-elf-).
"""
import argparse
import hashlib
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PREFIX = os.environ.get('MIPSEL_PREFIX', 'D:/FF7/toolchain/mipsel/bin/mipsel-none-elf-')
AS_FLAGS = ['-EL', '-march=r3000', '-mtune=r3000', '-mabi=32', '-no-pad-sections', '-G0', '-Iinclude']
PYTHON = sys.executable

TARGETS = [
    # (splat config, name of the file on the disc)
    ('config/scus_941.63.us.yaml', 'SCUS_941.63'),
]


def run(cmd, **kw):
    done = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, **kw)
    if done.returncode:
        sys.exit(f'failed: {" ".join(map(str, cmd))}\n{done.stdout}{done.stderr}')
    return done


def config_value(text, key):
    m = re.search(rf'^\s*{key}:\s*(\S+)', text, re.M)
    return m.group(1) if m else None


def objects(ld_script):
    """Object files a splat linker script names, with their sources."""
    out = []
    for obj in sorted(set(re.findall(r'(build/\S+?\.o)\(', ld_script.read_text()))):
        src = Path(obj[len('build/us/'):-2] + '.s') if obj.startswith('build/us/') else None
        out.append((ROOT / obj, ROOT / src if src else None))
    return out


def build(config, original, split, jobs):
    cfg = (ROOT / config).read_text(encoding='utf-8')
    target = ROOT / config_value(cfg, 'target_path')
    if not target.exists():
        sys.exit(f'{target} is missing: run tools/extract_disc.py on your disc first')
    ld = ROOT / config_value(cfg, 'ld_script_path')
    if split or not ld.exists():
        done = subprocess.run([PYTHON, '-m', 'splat', 'split', Path(config).name],
                              cwd=ROOT / 'config', capture_output=True, text=True)
        if done.returncode:
            sys.exit(f'splat failed for {config}\n{done.stdout[-3000:]}{done.stderr[-3000:]}')
    work = []
    for obj, src in objects(ld):
        if src is None or not src.exists():
            sys.exit(f'no source for {obj}')
        if not obj.exists() or obj.stat().st_mtime < src.stat().st_mtime:
            work.append((obj, src))

    def assemble(item):
        obj, src = item
        obj.parent.mkdir(parents=True, exist_ok=True)
        run([PREFIX + 'as', *AS_FLAGS, '-o', str(obj), str(src)])

    with ThreadPoolExecutor(max_workers=jobs) as pool:
        list(pool.map(assemble, work))
    elf = ROOT / config_value(cfg, 'elf_path')
    auto = [p for p in (ROOT / config_value(cfg, 'undefined_syms_auto_path'),
                        ROOT / config_value(cfg, 'undefined_funcs_auto_path')) if p.exists()]
    link = [PREFIX + 'ld', '-EL', '-nostdlib', '--no-check-sections', '-o', str(elf),
            '-Map', str(elf.with_suffix('.map')), '-T', str(ld)]
    for path in auto:
        link += ['-T', str(path)]
    run(link)
    out = elf.with_suffix('')
    run([PREFIX + 'objcopy', '-O', 'binary', str(elf), str(out)])
    want = config_value(cfg, 'sha1')
    got = hashlib.sha1(out.read_bytes()).hexdigest()
    ok = got == want
    print(f'{original}: {"OK" if ok else "DIFFERS"} ({len(work)} assembled, sha1 {got})')
    if not ok:
        first = next((i for i, (a, b) in enumerate(zip(out.read_bytes(), target.read_bytes())) if a != b), None)
        print(f'  first difference at 0x{first:X}' if first is not None else
              f'  sizes differ: {out.stat().st_size} vs {target.stat().st_size}')
    return ok


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--split', action='store_true', help='run splat again before building')
    ap.add_argument('--jobs', type=int, default=os.cpu_count() or 4)
    args = ap.parse_args()
    results = [build(config, name, args.split, args.jobs) for config, name in TARGETS]
    sys.exit(0 if all(results) else 1)


if __name__ == '__main__':
    main()
