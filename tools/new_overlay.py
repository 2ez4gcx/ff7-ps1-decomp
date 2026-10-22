#!/usr/bin/env python3
"""Add an overlay of the disc to the project: a splat config and a target.

    python tools/new_overlay.py FIELD/FIELD.BIN 0x800A0000 field
    python tools/new_overlay.py MENU/ITEMMENU.MNU 0x801D0000 itemmenu

The overlay is the image the game puts in RAM: files packed as one gzip
stream behind {u32 unpacked size, u32 size in memory} are unpacked into
disks/us/unpacked/ (that image is what must rebuild byte for byte). Code is
told from data by its function frames and returns; the space past the image
is .bss, sized later (the header's second word is not always the size in
memory). The target goes into config/targets.txt.
"""
import argparse
import hashlib
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import find_overlays  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
TARGETS = ROOT / 'config' / 'targets.txt'
JR_RA = 0x03E00008

TEMPLATE = """\
# splat configuration for {disc} of Final Fantasy VII (USA, disc 1), loaded at
# {vram:#010x}{packed_note}. Made by tools/new_overlay.py; the overlay itself is
# never part of this repository.
name: {name}
sha1: {sha1}
options:
  basename: {name}
  target_path: {target}
  elf_path: build/us/{name}.elf
  base_path: ..
  platform: psx
  compiler: PSYQ

  asm_path: asm/us/{name}
  asset_path: assets/us/{name}
  src_path: src/{name}
  build_path: build/us
  ld_script_path: build/us/{name}.ld
  ld_dependencies: False
  # PSY-Q's linker packs sections back to back.
  ld_align_section_vram_end: False
  ld_align_segment_vram_end: False
  # .bss gets its own section, so its alignment never pads the image.
  ld_bss_is_noload: True

  find_file_boundaries: True
  gp_value: 0x80062D44

  o_as_suffix: True
  use_legacy_include_asm: False
  # GCC 2.6.3 puts top-level asm ahead of the functions around it; this
  # INCLUDE_ASM wraps each in a function maspsx unwraps, keeping the order.
  include_asm_macro_style: maspsx_hack

  section_order: [".rodata", ".text", ".data", ".bss"]

  symbol_addrs_path:
    - config/symbols.us.main.txt
    - config/symbols.us.{group}.txt
  reloc_addrs_path:
    - config/reloc_addrs.us.{group}.txt
  undefined_funcs_auto_path: build/us/undefined_funcs_auto.{name}.txt
  undefined_syms_auto_path: build/us/undefined_syms_auto.{name}.txt

  subalign: 2

  string_encoding: ASCII
  data_string_encoding: ASCII
  rodata_string_guesser_level: 2
  data_string_guesser_level: 2
segments:
  - name: {name}
    type: code
    start: 0x0
    vram: {vram:#010x}
{bss}    subsegments:
{subsegments}
  - [{size:#x}]
"""


def text_range(image):
    """(start, end) in bytes of the code: from the first function frame to
    the delay slot of the last return."""
    n = len(image) // 4
    words = struct.unpack_from(f'<{n}I', image, 0)
    frames = [i for i, w in enumerate(words) if (w & 0xFFFF8000) == 0x27BD8000]
    returns = [i for i, w in enumerate(words) if w == JR_RA]
    if not frames or not returns:
        return None
    # A leaf function ahead of the first frame stays in .rodata as words: the
    # bytes rebuild the same either way, and a later split can move it.
    return frames[0] * 4, (returns[-1] + 2) * 4


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('disc', help='file on the disc, as under disks/us/')
    ap.add_argument('vram', type=lambda s: int(s, 0), help='load address')
    ap.add_argument('name', help='short name: config, asm and symbol files use it')
    ap.add_argument('--group', help='share the symbol files of this group (magic effects)')
    args = ap.parse_args()

    src = ROOT / 'disks' / 'us' / args.disc
    data = src.read_bytes()
    unpacked = find_overlays.packed(data)
    if unpacked:
        image, memory = unpacked
        target = ROOT / 'disks' / 'us' / 'unpacked' / args.disc
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(image)
        header = f'    # file header: unpacked {len(image):#x}, second word {memory:#x}\n'
    else:
        image, target, header = data, src, ''
    span = text_range(image)
    if not span:
        sys.exit(f'{args.disc}: no code found')
    start, end = span
    subs = []
    if start > 0:
        subs.append(f'      - [0x0, .rodata, text]')
    subs.append(f'      - [{start:#x}, c, text]')
    tail = len(image) & ~3
    if end < tail:
        subs.append(f'      - [{end:#x}, data, data]')
    if tail < len(image):
        # The words above stop at the last whole word; the odd bytes after it.
        subs.append(f'      - [{tail:#x}, bin, tail]')
    config = ROOT / 'config' / f'{args.name}.us.yaml'
    config.write_text(TEMPLATE.format(
        disc=args.disc, vram=args.vram, name=args.name, group=args.group or args.name,
        packed_note=' (unpacked from its gzip stream)' if unpacked else '',
        sha1=hashlib.sha1(image).hexdigest(),
        target=target.relative_to(ROOT).as_posix(),
        bss=header,
        subsegments='\n'.join(subs), size=len(image)), encoding='utf-8', newline='\n')
    group = args.group or args.name
    for extra in (f'symbols.us.{group}.txt', f'reloc_addrs.us.{group}.txt'):
        path = ROOT / 'config' / extra
        if not path.exists():
            owner = f'{group} group' if args.group else args.disc
            path.write_text(f'// {owner}: name = 0xADDRESS; // type:func\n' if extra.startswith('symbols')
                            else '', encoding='utf-8', newline='\n')
    line = f'{config.name} {args.disc} {"packed" if unpacked else "plain"}'
    lines = [l for l in TARGETS.read_text(encoding='utf-8').splitlines() if l.split()[:1] != [config.name]] \
        if TARGETS.exists() else ['# config  file on the disc  packed|plain (built in this order)',
                                  'scus_941.63.us.yaml SCUS_941.63 plain']
    lines.append(line)
    TARGETS.write_text('\n'.join(lines) + '\n', encoding='utf-8', newline='\n')
    print(f'{config.relative_to(ROOT)}: {len(image)} bytes, text {start:#x}-{end:#x}')


if __name__ == '__main__':
    main()
