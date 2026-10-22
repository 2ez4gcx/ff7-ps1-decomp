#!/usr/bin/env python3
"""List the files of disks/us/ that hold MIPS code, and where each loads.

    python tools/find_overlays.py [DIR ...]

FF7 keeps its overlays as plain files, as one gzip stream behind an 8-byte
header {u32 unpacked size, u32 size in memory} (BATTLE/*.X, FIELD.BIN,
WORLD.BIN, MINI/*.BIN), as gzip members ({u16 size, u16 size, u16 kind} +
gzip stream, several in a row, as in KERNEL.BIN) or LZS. For each
candidate the code is unpacked, counted (jr $ra, stack frames), and its load
address found from its own calls: `jal` targets that point into the file
land on function starts (addiu $sp, $sp, -n) only when the base is right.
"""
import struct
import sys
import zlib
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
JR_RA = 0x03E00008


def packed(data):
    """8-byte header + gzip stream -> (unpacked bytes, size in memory) or None."""
    if len(data) < 18 or data[8:11] != bytes((0x1F, 0x8B, 0x08)):
        return None
    size, memory = struct.unpack_from('<II', data, 0)
    try:
        out = zlib.decompressobj(16 + zlib.MAX_WBITS).decompress(data[8:])
    except zlib.error:
        return None
    return (out, memory) if len(out) == size else None


def gzip_members(data):
    out, i = [], 0
    while i + 6 <= len(data):
        size, _, _ = struct.unpack_from('<HHH', data, i)
        if size == 0 or i + 6 + size > len(data):
            break
        try:
            out.append(zlib.decompress(data[i + 6:i + 6 + size], 16 + zlib.MAX_WBITS))
        except zlib.error:
            return []
        i += 6 + size
    return out if i >= len(data) - 3 else []


def lzs(data):
    size = struct.unpack_from('<I', data, 0)[0]
    if size + 4 not in (len(data), len(data) - 1, len(data) - 2, len(data) - 3) and size + 4 != len(data):
        if not (len(data) - 4 <= size + 4 <= len(data)):
            return None
    out, p, end = bytearray(), 4, 4 + size
    while p < end:
        flags = data[p]
        p += 1
        for bit in range(8):
            if p >= end:
                break
            if flags & (1 << bit):
                out.append(data[p])
                p += 1
            else:
                if p + 1 >= end:
                    return None
                a, b = data[p], data[p + 1]
                p += 2
                offset = a | ((b & 0xF0) << 4)
                length = (b & 0x0F) + 3
                start = len(out) - ((len(out) - 18 - offset) & 0xFFF)
                for k in range(length):
                    src = start + k
                    out.append(out[src] if 0 <= src < len(out) else 0)
    return bytes(out)


def unpack(path):
    """[(label, bytes)] of the ways this file can hold code."""
    data = path.read_bytes()
    out = [('raw', data)]
    one = packed(data)
    if one:
        out.append(('packed', one[0]))
    members = gzip_members(data)
    out += [(f'gzip#{i}', m) for i, m in enumerate(members)]
    if path.suffix.upper() == '.LZS':
        dec = lzs(data)
        if dec:
            out.append(('lzs', dec))
    return out


def code_stats(data):
    n = len(data) // 4
    words = struct.unpack_from(f'<{n}I', data, 0)
    returns = sum(1 for w in words if w == JR_RA)
    frames = sum(1 for w in words if (w & 0xFFFF8000) == 0x27BD8000)   # addiu sp, sp, -n
    return returns, frames, words


def load_base(words):
    """The 64 KiB-aligned base that puts most self-calls on function starts."""
    starts = {i for i, w in enumerate(words) if (w & 0xFFFF8000) == 0x27BD8000}
    targets = [((w & 0x03FFFFFF) << 2) | 0x80000000 for w in words if (w >> 26) == 3]
    best = None
    for base in sorted({t & 0xFFFF0000 for t in targets if t >= 0x80070000}):
        hits = sum(1 for t in targets if base <= t < base + 4 * len(words)
                   and (t - base) // 4 in starts)
        if best is None or hits > best[1]:
            best = (base, hits)
    if not best:
        return None, 0
    # Finer: the base may not be 64 KiB aligned; try nearby word offsets.
    base0, _ = best
    fine = []
    for delta in range(-0x8000, 0x8000, 4):
        base = base0 + delta
        hits = sum(1 for t in targets if base <= t < base + 4 * len(words) and (t - base) % 4 == 0
                   and (t - base) // 4 in starts)
        fine.append((hits, -abs(delta), base))
    hits, _, base = max(fine)
    return base, hits


def main():
    dirs = [ROOT / 'disks' / 'us' / d for d in sys.argv[1:]] or [ROOT / 'disks' / 'us']
    skip = ('STAGE', 'ENEMY', 'MOVIE/', 'SOUND/')
    for top in dirs:
        for path in sorted(p for p in top.rglob('*') if p.is_file()):
            rel = path.relative_to(ROOT / 'disks' / 'us').as_posix()
            if rel.startswith(skip) or rel == 'SCUS_941.63' or (
                    rel.startswith('FIELD/') and path.suffix.upper() not in ('.BIN', '.X')):
                continue
            for label, data in unpack(path):
                if len(data) < 256:
                    continue
                returns, frames, words = code_stats(data)
                if returns < 4 or frames < 4:
                    continue
                base, hits = load_base(words)
                print(f'{rel:24s} {label:7s} {len(data):8d} bytes  jr-ra {returns:5d}  '
                      f'frames {frames:5d}  base {base and hex(base)}  self-calls {hits}')


if __name__ == '__main__':
    main()
