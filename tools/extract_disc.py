#!/usr/bin/env python3
"""Copy the files of a Final Fantasy VII (USA) disc image into disks/us/.

    python tools/extract_disc.py "path/to/Final Fantasy VII (USA) (Disc 1).cue"

The image is the player's own: a .cue with one MODE2/2352 data track (or the
.bin itself). Files are read through the ISO 9660 file system; sectors of
Form 2 (movie and XA audio streams) keep only their first 2048 bytes, which
is enough for the code and data this project rebuilds. Nothing extracted
here is ever committed (see .gitignore).
"""
import argparse
import hashlib
import re
import struct
import sys
from pathlib import Path

SECTOR = 2352
USER = 24          # sync 12, header 4, subheader 8 (Form 1)
ROOT = Path(__file__).resolve().parents[1]


def bin_of(path):
    path = Path(path)
    if path.suffix.lower() != '.cue':
        return path
    text = path.read_text(encoding='utf-8', errors='replace')
    m = re.search(r'FILE\s+"([^"]+)"', text)
    if not m:
        sys.exit(f'{path}: no FILE line')
    if 'MODE2/2352' not in text:
        sys.exit(f'{path}: track 1 is not MODE2/2352')
    return path.with_name(m.group(1))


class Disc:
    def __init__(self, path):
        self.f = open(path, 'rb')

    def sector(self, lba):
        self.f.seek(lba * SECTOR)
        return self.f.read(SECTOR)[USER:USER + 2048]

    def extent(self, lba, size):
        out = bytearray()
        for i in range((size + 2047) // 2048):
            out += self.sector(lba + i)
        return bytes(out[:size])

    def walk(self):
        """(path, lba, size) of every file, directories first visited."""
        pvd = self.sector(16)
        if pvd[1:6] != b'CD001':
            sys.exit('not an ISO 9660 data track')
        root = pvd[156:156 + 34]
        lba, size = struct.unpack_from('<I', root, 2)[0], struct.unpack_from('<I', root, 10)[0]
        yield from self._dir(lba, size, '')

    def _dir(self, lba, size, prefix):
        data = self.extent(lba, size)
        p = 0
        while p < len(data):
            n = data[p]
            if n == 0:
                p = (p // 2048 + 1) * 2048
                continue
            rec = data[p:p + n]
            p += n
            flba, fsize, flags = struct.unpack_from('<I', rec, 2)[0], struct.unpack_from('<I', rec, 10)[0], rec[25]
            name = rec[33:33 + rec[32]]
            if name in (b'\0', b'\1'):
                continue
            name = name.decode('ascii', 'replace').split(';')[0]
            if flags & 2:
                yield from self._dir(flba, fsize, prefix + name + '/')
            else:
                yield prefix + name, flba, fsize


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('image', help='the disc .cue (or .bin)')
    ap.add_argument('--out', type=Path, default=ROOT / 'disks' / 'us')
    ap.add_argument('--skip', default='MOVIE/', help='comma-separated path prefixes left out')
    args = ap.parse_args()
    disc = Disc(bin_of(args.image))
    skip = tuple(s for s in args.skip.split(',') if s)
    count = 0
    for path, lba, size in disc.walk():
        if skip and path.startswith(skip):
            continue
        dst = args.out / path
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_bytes(disc.extent(lba, size))
        count += 1
    print(f'{count} files -> {args.out}')
    exe = args.out / 'SCUS_941.63'
    if exe.exists():
        print(f'SCUS_941.63 sha1 {hashlib.sha1(exe.read_bytes()).hexdigest()}')


if __name__ == '__main__':
    main()
