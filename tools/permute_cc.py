#!/usr/bin/env python3
"""The compiler decomp-permuter calls (see tools/permute.py).

    python tools/permute_cc.py INPUT.c OUTPUT.o NAME TARGET LIKE

INPUT.c is compiled the way LIKE (a file of src/) is built, NAME is linked
at its address in the game (tools/match.py), and OUTPUT.o holds just its
words: the permuter compares the game's words with these, so symbol names
and addresses no longer differ where the code does not. With INPUT.c given
as `-`, the game's own words for NAME are written instead (target.o).
"""
import os
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import match  # noqa: E402
import psyq  # noqa: E402


def words_object(words, name, out):
    fd, s = tempfile.mkstemp(suffix='.s')
    os.close(fd)
    try:
        Path(s).write_text('.set noreorder\n.section .text\n.globl {0}\n{0}:\n'.format(name)
                           + ''.join(f'.word 0x{w:08X}\n' for w in words), encoding='utf-8')
        done = subprocess.run([psyq.PREFIX + 'as', '-EL', '-march=r3000', '-mabi=32', '-o', out, s],
                              capture_output=True, text=True)
        if done.returncode:
            sys.exit(done.stderr)
    finally:
        os.unlink(s)


def main():
    src, out, name, target, like = sys.argv[1:6]
    address, want = match.original(name, target)
    if src == '-':
        words_object(want, name, out)
        return
    try:
        (funcs, relocs, _, _), rodata = match.compiled_alone(src, name, target, like)
    except psyq.Failed as e:
        sys.exit(str(e)[-2000:])
    if name not in funcs:
        sys.exit(f'{name} not compiled')
    try:
        got = match.linked(funcs, relocs, name, address, target, rodata)
    except KeyError as e:
        sys.exit(f'unknown symbol or relocation {e}')
    words_object(got, name, out)


if __name__ == '__main__':
    main()
