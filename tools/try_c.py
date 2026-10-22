#!/usr/bin/env python3
"""Compile C functions with the original compiler and compare them with the
game's code, function by function.

    python tools/try_c.py FILE.c [--target main] [--flags "-O2 -G8"]

Each function in FILE.c is looked up by name in asm/us/<target>/ (splat's
output) and its words are compared with what cpp -> cc1 (GCC 2.6.3) ->
maspsx -> GNU as makes of it. Fields a relocation will fill (%hi/%lo,
%gp_rel, jal targets) are left out of the comparison. Prints OK or the first
differing instruction per function.
"""
import argparse
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import psyq  # noqa: E402
PREFIX = psyq.PREFIX


def compile_c(src, cflags, aspsx, gvalue):
    try:
        cc_out, ms_out = psyq.assembly(src, cflags.split(), int(gvalue), aspsx)
        obj = Path(tempfile.mkstemp(suffix='.o')[1])
        psyq.compile_c(src, obj, cflags.split(), int(gvalue), aspsx)
    except psyq.Failed as e:
        sys.exit(str(e))
    return obj, cc_out, ms_out


def compiled_functions(obj):
    """{name: [words]} of the functions in an object's .text."""
    dump = subprocess.run([PREFIX + 'objdump', '-d', '-z', str(obj)], capture_output=True, text=True).stdout
    out, cur = {}, None
    for line in dump.splitlines():
        m = re.match(r'^[0-9a-f]+ <(\w+)>:', line)
        if m:
            cur = m.group(1)
            out[cur] = []
            continue
        m = re.match(r'^\s+[0-9a-f]+:\s+([0-9a-f]{8})\s', line)
        if m and cur:
            out[cur].append(int(m.group(1), 16))
    return out


def original(name, target):
    """Words of a function from splat's asm (the /* off vram WORD */ comments)."""
    for path in (ROOT / 'asm' / 'us' / target).rglob('*.s'):
        text = path.read_text(encoding='utf-8', errors='replace')
        m = re.search(rf'^glabel {name}\n(.*?)^endlabel {name}', text, re.M | re.S)
        if m:
            words = re.findall(r'/\* [0-9A-F]+ [0-9A-F]+ ([0-9A-F]{8}) \*/', m.group(1))
            return [struct.unpack('<I', bytes.fromhex(w))[0] for w in words]
    return None


def masked(word):
    op = word >> 26
    if op in (2, 3):                       # j / jal: target filled by relocation
        return word & 0xFC000000
    if op in (0x0F, 0x08, 0x09) or op >= 0x20:   # lui, addi(u), loads/stores: immediates
        return word & 0xFFFF0000
    return word


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('source', type=Path)
    ap.add_argument('--target', default='main')
    ap.add_argument('--flags', default=' '.join(psyq.CFLAGS))
    ap.add_argument('--aspsx', default=psyq.ASPSX)
    ap.add_argument('--show', action='store_true', help='print the compiler and maspsx output')
    args = ap.parse_args()
    g = re.search(r'-G\s*(\d+)', args.flags)
    obj, cc_out, ms_out = compile_c(args.source, args.flags, args.aspsx, g.group(1) if g else 0)
    if args.show:
        print(cc_out, '\n----- maspsx -----\n', ms_out)
    ok = True
    for name, words in compiled_functions(obj).items():
        want = original(name, args.target)
        if want is None:
            print(f'{name}: not in asm/us/{args.target}')
            continue
        diff = next((i for i in range(max(len(words), len(want)))
                     if i >= len(words) or i >= len(want) or masked(words[i]) != masked(want[i])), None)
        if diff is None:
            print(f'{name}: OK ({len(words)} instructions)')
        else:
            ok = False
            got = f'{words[diff]:08X}' if diff < len(words) else '-'
            exp = f'{want[diff]:08X}' if diff < len(want) else '-'
            print(f'{name}: differs at instruction {diff}: got {got}, want {exp} '
                  f'({len(words)} vs {len(want)} instructions)')
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
