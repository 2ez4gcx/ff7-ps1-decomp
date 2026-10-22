#!/usr/bin/env python3
"""Rebuild the game's executables from this repository and check them.

    python tools/build.py                # split if needed, assemble, link, compare
    python tools/build.py --split        # run splat again first (after config changes)
    python tools/build.py field battle   # only these targets (config name prefixes)

The targets are listed in config/targets.txt, one splat config each. Its asm
(and later C) is assembled into build/us/, linked with the linker script
splat writes, and the result must match the original byte for byte (its
SHA-1 is in the config): the main executable as it is on the disc, an
overlay as the image the game loads into RAM (packed overlays are unpacked
from the disc into disks/us/unpacked/ first). Overlays link against the main
executable's symbols. Tools: the mipsel GNU binutils (set MIPSEL_PREFIX,
default D:/FF7/toolchain/mipsel/bin/mipsel-none-elf-).
"""
import argparse
import hashlib
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import find_overlays  # noqa: E402
import psyq  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
PREFIX = os.environ.get('MIPSEL_PREFIX', 'D:/FF7/toolchain/mipsel/bin/mipsel-none-elf-')
AS_FLAGS = ['-EL', '-march=r3000', '-mtune=r3000', '-mabi=32', '-no-pad-sections', '-G0', '-Iinclude']
PYTHON = sys.executable
MAIN = 'scus_941.63.us.yaml'


def run(cmd, **kw):
    done = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, **kw)
    if done.returncode:
        sys.exit(f'failed: {" ".join(map(str, cmd))}\n{done.stdout}{done.stderr}')
    return done


def config_value(text, key):
    m = re.search(rf'^\s*{key}:\s*(\S+)', text, re.M)
    return m.group(1) if m else None


def targets():
    """[(config, file on the disc, packed)] from config/targets.txt."""
    out = []
    for line in (ROOT / 'config' / 'targets.txt').read_text(encoding='utf-8').splitlines():
        if line.strip() and not line.startswith('#'):
            config, disc, kind = line.split()
            out.append((config, disc, kind == 'packed'))
    return out


def main_symbols():
    """A linker script giving overlays the main executable's own symbols (the
    ones it defines in its 0x80010000-0x80070800 image), as PROVIDE so an
    overlay's own definition of a name wins."""
    main_cfg = (ROOT / 'config' / MAIN).read_text(encoding='utf-8')
    elf = ROOT / config_value(main_cfg, 'elf_path')
    out = elf.with_name('main_symbols.ld')
    if out.exists() and out.stat().st_mtime >= elf.stat().st_mtime:
        return out
    lines = []
    for line in run([PREFIX + 'nm', str(elf)]).stdout.splitlines():
        parts = line.split()
        if len(parts) != 3 or parts[1] in ('a', 'A', 'U'):
            continue
        addr, name = int(parts[0], 16) & 0xFFFFFFFF, parts[2]
        if 0x80010000 <= addr < 0x80070800 and re.fullmatch(r'[A-Za-z_.$][\w.$]*', name):
            lines.append(f'PROVIDE({name} = 0x{addr:08X});')
    out.write_text('\n'.join(lines) + '\n', encoding='utf-8', newline='\n')
    return out


def named_by_address(elf, c_objects):
    """A linker script giving the address its name holds (D_80012345,
    func_80012345) to each symbol C code uses that nothing defines: splat
    only names what its asm refers to, and the C may refer to more."""
    names = set()
    for obj in c_objects:
        for line in run([PREFIX + 'nm', '-u', str(obj)]).stdout.splitlines():
            m = re.fullmatch(r'\s*U\s+((?:D|func|jtbl)_([0-9A-F]{8}))', line)
            if m:
                names.add(m.group(1))
    out = elf.with_name(elf.stem + '.addresses.ld')
    out.write_text(''.join(f'PROVIDE({n} = 0x{n[-8:]});\n' for n in sorted(names)), encoding='utf-8',
                   newline='\n')
    return out


def objects(ld_script):
    """Object files a splat linker script names, with their sources."""
    out = []
    for obj in sorted(set(re.findall(r'(build/\S+?\.o)\(', ld_script.read_text()))):
        stem = obj[len('build/us/'):-2] if obj.startswith('build/us/') else None
        src = None
        if stem:
            if stem.startswith('assets/'):
                src = ROOT / (stem + '.bin')
            elif stem.startswith('src/'):
                src = ROOT / (stem + '.c')
            else:
                src = ROOT / (stem + '.s')
        out.append((ROOT / obj, src))
    return out


def build(config, disc, packed, split, jobs):
    cfg = (ROOT / 'config' / config).read_text(encoding='utf-8')
    target = ROOT / config_value(cfg, 'target_path')
    if not target.exists():
        source = ROOT / 'disks' / 'us' / disc
        if not source.exists():
            sys.exit(f'{source} is missing: run tools/extract_disc.py on your disc first')
        if packed:
            image = find_overlays.packed(source.read_bytes())
            if not image:
                sys.exit(f'{disc}: not a packed overlay')
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(image[0])
    ld = ROOT / config_value(cfg, 'ld_script_path')
    if split or not ld.exists():
        done = subprocess.run([PYTHON, '-m', 'splat', 'split', config],
                              cwd=ROOT / 'config', capture_output=True, text=True)
        if done.returncode:
            sys.exit(f'splat failed for {config}\n{done.stdout[-3000:]}{done.stderr[-3000:]}')
    work = []
    for obj, src in objects(ld):
        if src is None or not src.exists():
            sys.exit(f'no source for {obj}')
        newest = src.stat().st_mtime
        if src.suffix == '.c':
            # Compiler settings and headers too (a cheap stand-in for real dependencies).
            newest = max([newest, (ROOT / 'tools' / 'psyq.py').stat().st_mtime] +
                         [h.stat().st_mtime for h in (ROOT / 'include').glob('*.h')] +
                         # its own target's headers and the main executable's (overlays include those)
                         [h.stat().st_mtime for h in {*src.parent.glob('*.h'), *(ROOT / 'src' / 'main').glob('*.h')}] +
                         [p.stat().st_mtime for p in psyq.MASPSX.parent.glob('maspsx/*.py')])
        # After a split, C files include asm splat may have just rewritten.
        if not obj.exists() or obj.stat().st_mtime < newest or (split and src.suffix == '.c'):
            work.append((obj, src))

    def assemble(item):
        obj, src = item
        obj.parent.mkdir(parents=True, exist_ok=True)
        if src.suffix == '.c':
            try:
                psyq.compile_c(src, obj)
            except psyq.Failed as e:
                sys.exit(f'failed: {src}\n{e}')
        elif src.suffix == '.bin':
            # Raw bytes splat kept as they are (a 'bin' subsegment), as .data.
            run([PREFIX + 'objcopy', '-I', 'binary', '-O', 'elf32-littlemips', '-B', 'mips',
                 '--rename-section', '.data=.data,alloc,load,data,contents', str(src), str(obj)])
        else:
            run([PREFIX + 'as', *AS_FLAGS, '-o', str(obj), str(src)])

    with ThreadPoolExecutor(max_workers=jobs) as pool:
        list(pool.map(assemble, work))
    elf = ROOT / config_value(cfg, 'elf_path')
    auto = [p for p in (ROOT / config_value(cfg, 'undefined_syms_auto_path'),
                        ROOT / config_value(cfg, 'undefined_funcs_auto_path')) if p.exists()]
    link = [PREFIX + 'ld', '-EL', '-nostdlib', '--no-check-sections', '-o', str(elf),
            '-Map', str(elf.with_suffix('.map')), '-T', str(ld)]
    if config != MAIN:
        link += ['-T', str(main_symbols())]
    for path in auto:
        link += ['-T', str(path)]
    link += ['-T', str(named_by_address(elf, [o for o, s in objects(ld) if s.suffix == '.c']))]
    run(link)
    out = elf.with_suffix('')
    run([PREFIX + 'objcopy', '-O', 'binary', str(elf), str(out)])
    want = config_value(cfg, 'sha1')
    got = hashlib.sha1(out.read_bytes()).hexdigest()
    ok = got == want
    what = f'{disc} (unpacked)' if packed else disc
    print(f'{what}: {"OK" if ok else "DIFFERS"} ({len(work)} assembled, sha1 {got})', flush=True)
    if not ok:
        first = next((i for i, (a, b) in enumerate(zip(out.read_bytes(), target.read_bytes())) if a != b), None)
        print(f'  first difference at 0x{first:X}' if first is not None else
              f'  sizes differ: {out.stat().st_size} vs {target.stat().st_size}')
    return ok


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('only', nargs='*', help='targets to build (config name prefixes); the main '
                    'executable is always built first')
    ap.add_argument('--split', action='store_true', help='run splat again before building')
    ap.add_argument('--jobs', type=int, default=os.cpu_count() or 4)
    ap.add_argument('--skip-main', action='store_true', help='link overlays against the main '
                    'executable as last built, without building it again')
    args = ap.parse_args()
    results = []
    for config, disc, packed in targets():
        if args.only and config != MAIN and not any(config.startswith(o) for o in args.only):
            continue
        if config == MAIN and args.skip_main:
            continue
        results.append(build(config, disc, packed, args.split, args.jobs))
    print(f'{sum(results)}/{len(results)} targets match')
    sys.exit(0 if all(results) else 1)


if __name__ == '__main__':
    main()
