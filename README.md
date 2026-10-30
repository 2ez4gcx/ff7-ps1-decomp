# Final Fantasy VII (PS1) decomp

A decompilation of **Final Fantasy VII for the PlayStation (USA)**: the executables on
the disc turned back into assembly, then C, that rebuild to exactly the original bytes.

> This repository **does not contain** the game's discs, files taken from them, or the
> assembly generated from them. Everyone uses their own disc; everything that comes from
> it lives in `disks/`, `asm/` and `build/`, which `.gitignore` keeps out of git.

This is an independent project: it is not based on the code of any other decomp.

Most of the C here was written with AI assistance: Claude Code (Anthropic's Claude
models), working as batches of agents from the game's assembly and m2c's drafts, as
[docs/matching.md](docs/matching.md) describes. Nothing is taken on trust: a function
goes in only when it compiles to exactly the game's instructions, and every executable
is checked byte for byte against the disc.

## Status

All 319 executables of the three discs rebuild byte for byte, from C files: functions not
decompiled yet are still included as asm (`INCLUDE_ASM`). The compilers are the ones
PSY-Q used (GCC 2.6.3 and 2.7.2, see [docs/toolchain.md](docs/toolchain.md)), and each
executable is split into source files by how its parts were compiled. Progress, as
`tools/progress.py` counts it (code: the functions' bytes):

| Part | Executables | Functions in C | Code in C |
|---|---|---|---|
| Main executable (`src/main/`: game code, AKAO sound driver, PSY-Q libraries) | 1 | 812 of 1071 (76%) | 52% |
| Field (`src/field/`) | 1 | 382 of 435 (88%) | 55% |
| Battle (`src/battle/`, `brom/`, `batini/`, `batres/`) | 4 | 716 of 838 (85%) | 50% |
| World map (`src/world/`) | 1 | 420 of 459 (92%) | 58% |
| Menus (`src/*menu/`) | 13 | 225 of 243 (93%) | 47% |
| Minigames (`src/chocobo/`, `condor/`, `highway/`, `jet/`, `snobo/`, `snobo2/`, `submar/`) | 7 | 1037 of 1317 (79%) | 44% |
| Ending, disc change (`src/ending/`, `dschange/`) | 2 | 55 of 64 (86%) | 54% |
| Spell effects (`src/magic_*/`) | 290 | 2566 of 3998 (64%) | 44% |
| **All** | **319** | **6213 of 8425 (74%)** | **46%** |

The main executable's files: `text.c` … `text5.c` are the game's code
(0x800110B8–0x80029A4F), `akao.c` the AKAO sound driver, CD and movie code
(0x80029A50–0x80036297), `lib*.c` the PSY-Q libraries (0x80036298–0x80048D17).

Every C function compiles to exactly the game's instructions (and its jump tables and
strings to the game's rodata). Many were written by `tools/auto_decomp.py` (m2c drafts
them, only exact matches are kept), the rest by hand with `tools/work.py`; the main AKAO
functions use the driver's real data layouts: the song commands
(`akao_cmd_song_play/push/pop`), starting and resuming a song (`akao_song_start`,
`akao_song_resume`), looking up and starting sound effects (`akao_sfx_lookup`,
`akao_sfx_start`). Part of `lib.c` (GTE and BIOS calls) was assembly in the original.

| File on the disc | Contents | Loaded at |
|---|---|---|
| `SCUS_941.63` | Main executable: system, CD, AKAO sound driver, kernel | 0x80010000 |
| `FIELD/FIELD.BIN` | Field maps: scripts, backgrounds, models, dialogue | 0x800A0000 |
| `BATTLE/BATTLE.X`, `BROM.X` | Battles | 0x800A0000 |
| `BATTLE/BATINI.X`, `BATRES.X` | Battle start and results | 0x801B0000 |
| `WORLD/WORLD.BIN` | World map | 0x800A0000 |
| `FIELD/ENDING.X`, `DSCHANGE.X` | Ending, disc change screen | 0x800A0000 |
| `MENU/*.MNU` (13 files) | Menus: items, magic, equipment, materia, save, shops... | 0x801D0000 |
| `MINI/*.BIN` (7 files) | Minigames: `CHOCOBO`, `CONDOR`, `HIGHWAY`, `JET`, `SNOBO`, `SNOBO2`, `SUBMAR` | 0x800A0000 |
| `MAGIC/*.BIN` (289 files) | Spell, summon, limit break and enemy attack effects | 0x801B0000 |
| `SNOVA/LASBOSS3.BIN` (disc 3) | Safer Sephiroth's Supernova (`src/magic_lasboss3/`) | 0x801B0000 |

**Packed overlays:** many files (`*.X`, `FIELD.BIN`, `WORLD.BIN`, `MINI/*.BIN`) are a
gzip stream after an 8-byte header `{u32 unpacked size, u32 ...}`. Their byte-matching
target is the **unpacked image**, exactly what the game loads into RAM (`build.py`
unpacks them from the disc into `disks/us/unpacked/`). Packing them back into the
original files needs the original gzip compressor: zlib comes close (1112 of 1116 bytes
of `BROM.X`) but does not match yet.

**Three discs:** discs 2 and 3 of the USA release carry the same executables as disc 1,
byte for byte (the main one renamed `SCUS_941.64` and `SCUS_941.65`); only data files
differ between them. Disc 3 adds one executable, `SNOVA/LASBOSS3.BIN` (its `SNOVA*.LZS`
files are compressed data). So disc 1 plus disc 3's `SNOVA/` folder is all the code of
the game.

## Setup (Windows)

1. Python 3.12+ and a virtual environment:

   ```bash
   python -m venv .venv
   .venv/Scripts/python -m pip install -r requirements.txt
   ```

2. The GNU toolchain for MIPS (PS1): `gcc-mipsel-none-elf-12.3.0-windows.zip` from
   [PSn00bSDK v0.24](https://github.com/Lameguy64/PSn00bSDK/releases/tag/v0.24)
   (SHA-256 `51df48145d5ef4b396d3932b72ccba538cc605c7c7745b32c58c277aa00523c5`). Unpack it
   as `mipsel/` in the toolchain folder (or point `MIPSEL_PREFIX` at
   `.../bin/mipsel-none-elf-`).

3. The C compilers: GCC 2.6.3 and 2.7.2 built as 32-bit Windows programs by
   `tools/gcc-win32/build.sh` (they only need the Windows C runtime), and
   [maspsx](https://github.com/mkst/maspsx) with `tools/maspsx-extern.patch`. Details in
   [docs/toolchain.md](docs/toolchain.md).

4. Decompiling tools: [m2c](https://github.com/matt-kempster/m2c) and, for near misses,
   [decomp-permuter](https://github.com/simonlindholm/decomp-permuter), cloned into the
   toolchain folder. Note: the `m2c` package on PyPI is **not** this m2c.

All of it lives in one toolchain folder: `toolchain/` next to this repository's folder
(for `D:/FF7/ff7-ps1-decomp`, `D:/FF7/toolchain`), unless `FF7_TOOLCHAIN` names another
(`mipsel/`, `build-gcc/gcc-2.6.3/`, `build-gcc/gcc-2.7.2/`, `maspsx/`, `m2c/`,
`decomp-permuter/`). A folder set up on one Windows machine can be copied to another.

## Building

```bash
.venv/Scripts/python tools/extract_disc.py "Final Fantasy VII (USA) (Disc 1).cue"
.venv/Scripts/python tools/extract_disc.py "Final Fantasy VII (USA) (Disc 3).cue" --only SNOVA/
.venv/Scripts/python tools/build.py --split
```

`extract_disc.py` copies the files of your disc into `disks/us/` (movies left out); from
disc 3 only its own `SNOVA/` folder is needed.
`build.py` runs splat (each executable into asm under `asm/`), compiles the C, assembles
with GNU as, links with the linker scripts splat writes (overlays link against the main
executable's symbols), and compares SHA-1s with the originals. Success reads
`N/N targets match`. `build.py field battle` builds only the targets whose names start
that way.

Adding an overlay: `tools/find_overlays.py` lists the files that hold MIPS code and
guesses where they load (from the `jal`s into themselves); `tools/new_overlay.py FILE
ADDRESS NAME` writes its splat config and adds it to `config/targets.txt`.
`tools/to_c.py NAME` turns an existing overlay's code into a C file of INCLUDE_ASMs.

## Decompiling

- `tools/auto_decomp.py --target main --max 100` drafts every function still in asm
  with m2c (smallest first), tries a few forms of each, and keeps the exact matches.
- `tools/work.py show NAME > work/NAME.c` starts a function by hand from m2c's draft;
  `tools/work.py diff work/NAME.c NAME` shows its code next to the game's, word by word;
  `tools/work.py put work/NAME.c NAME` puts it in once it matches.
- `tools/match.py FILE.c` checks every function of a C file against the game.
- `tools/progress.py` counts the functions and code bytes in C (`--targets`: per
  executable).

See [docs/toolchain.md](docs/toolchain.md) for the compiler options of each file, what
GCC 2.6.3 and 2.7.2 need to produce the game's code, and the other tools (the
permuter, splitting a file).

## Layout

- `config/`: a splat config for each executable, symbol tables (`symbols.*.txt`).
- `include/`: shared types and macros (`common.h`, `m2c.h`, `include_asm.h`).
- `src/`: decompiled C (each function replacing its asm); declarations shared by a
  target's files in `src/<target>/decls.h`.
- `tools/`: disc extraction, building, the compiler (`psyq.py`), matching
  (`match.py`, `auto_decomp.py`, `work.py`, `diff_func.py`).

## Roadmap

1. ~~Add the overlays to the configs, each rebuilding byte for byte.~~ Done for the three
   discs; left: each overlay's BSS size, the original gzip packer.
2. Name known functions and variables (from the work on FF7 Recompiled: the AKAO sound
   driver, field, battle...).
3. ~~Build the original compiler (PSY-Q, GCC 2.x).~~ Done: GCC 2.6.3 + maspsx, with
   options for each part of the main executable.
4. Decompile function by function: split `text.c` and `lib.c` into the game's own
   source files and libraries, name the AKAO driver's fields, move every overlay to C.

## Contributing

Fixes and functions are welcome as pull requests. Everyone works from their own disc
(see Setup); a change is ready when `tools/build.py` still says that every target
matches. [docs/matching.md](docs/matching.md) collects what the compilers need to match,
and [docs/near-misses.md](docs/near-misses.md) lists the functions that resisted so far.
Do not commit anything taken from the disc, and do not copy code from other FF7
decompilations or from FFNx.

## License

The code in this repository is licensed under the GNU General Public License, version 3
(see [LICENSE](LICENSE)). It covers this project's own work only: Final Fantasy VII and
its data belong to Square Enix, and none of them is distributed here.
