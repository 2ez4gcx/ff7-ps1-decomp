#!/usr/bin/env python3
"""Let overlays be written in C: their code becomes a C file of splat's.

    python tools/to_c.py TARGET... | --all

In each target's splat config the code turns from `asm` into `c`
(src/<target>/text.c, every function an INCLUDE_ASM at first), its rodata
goes with it (`.rodata`, so splat moves each function's tables and strings
into its asm), and INCLUDE_ASM takes the maspsx_hack form. Then
`tools/build.py --split TARGET` writes the C file and must still match.
"""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import targets  # noqa: E402

HACK = ('  # GCC 2.6.3 puts top-level asm ahead of the functions around it; this\n'
        '  # INCLUDE_ASM wraps each in a function maspsx unwraps, keeping the order.\n'
        '  include_asm_macro_style: maspsx_hack\n')


def convert(config):
    text = config.read_text(encoding='utf-8')
    if re.search(r'^\s*- \[0x[0-9a-fA-F]+, c, ', text, re.M):
        return False
    text = re.sub(r'^(\s*- \[0x[0-9a-fA-F]+), rodata, rodata\]', r'\1, .rodata, text]', text, flags=re.M)
    text = re.sub(r'^(\s*- \[0x[0-9a-fA-F]+), asm, text\]', r'\1, c, text]', text, flags=re.M)
    if 'include_asm_macro_style' not in text:
        text = text.replace('  use_legacy_include_asm: False\n', '  use_legacy_include_asm: False\n' + HACK, 1)
    config.write_text(text, encoding='utf-8', newline='\n')
    return True


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('names', nargs='*')
    ap.add_argument('--all', action='store_true', help='every overlay')
    args = ap.parse_args()
    names = [n for n in targets.all_targets() if n != 'main'] if args.all else args.names
    done = sum(convert(targets.get(n).config) for n in names)
    print(f'{done} of {len(names)} configs changed')


if __name__ == '__main__':
    main()
