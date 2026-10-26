# The C compiler

The game was compiled with Sony's PSY-Q: `CCPSX` runs `cpp`, `cc1` (GCC modified for the
PS1; the game used two versions of it, 2.6.3 and 2.7.2) and `ASPSX` (the assembler). This
repository uses equivalents that run on Windows:

```
cpp (GCC 2.6.3) -> cc1 (GCC 2.6.3 or 2.7.2, mips-sony-psx) -> maspsx -> GNU as (mipsel-none-elf)
```

| Step | Tool | Where it comes from |
|---|---|---|
| Preprocessing, compiling | `cpp.exe`, `cc1.exe` (GCC 2.6.3 and 2.7.2) | Built by `tools/gcc-win32/build.sh` |
| Standing in for ASPSX | [maspsx](https://github.com/mkst/maspsx) commit `4ffa8b5` + `tools/maspsx-extern.patch` | `git clone`, `git apply` |
| Assembling, linking | GNU binutils 2.40 (`mipsel-none-elf-*`) | PSn00bSDK v0.24, see the README |

`tools/psyq.py` chains these steps; `tools/build.py` uses it for every `src/**/*.c`.

## Building GCC for Windows

```bash
sh tools/gcc-win32/build.sh D:/FF7/toolchain 2.6.3
sh tools/gcc-win32/build.sh D:/FF7/toolchain 2.7.2
```

The script takes the official GCC sources (`ftp.gnu.org/old-gnu/gcc/gcc-2.6.3.tar.bz2`,
SHA-256 `71f67384…3c140`; `gcc-2.7.2.tar.gz`, SHA-256 `7cd8bce5…c5da5`) and the PS1
patches of [decompals/old-gcc](https://github.com/decompals/old-gcc) (commit `cf70ec5`,
following their `gcc-<version>-psx.Dockerfile`), and builds `cc1` and `cpp` with clang as
**32-bit Windows** programs (`i686-w64-mingw32`, part of llvm-mingw). 32 bits are needed:
these GCCs take a host integer (`HOST_WIDE_INT`) to be wide enough for a pointer, as it
was on the machines PSY-Q ran on. `tools/gcc-win32/win32-compat.c` and
`tools/gcc-win32/include/` supply the BSD string functions and `getrusage` Windows lacks.
The results pass old-gcc's tests; two builds give identical output.

`cc1` needs `TMPDIR` set to a writable folder (`psyq.py` sets it).

## The maspsx patch

ASPSX reaches a small extern variable (`.extern x, 4`, size ≤ `-G`) through `$gp`; the
original maspsx ignores `.extern` lines. `tools/maspsx-extern.patch` records those
variables (only to choose how to reach them, never to define them). It also adds
`--nop-at-expansion`: a `nop` between a load and an instruction expanded through `$at`
that uses the loaded register, which maspsx otherwise does only for ASPSX below 2.30
but the game's `text2.c` code has with a newer one. And for ASPSX below 2.30 it waits
after a load when the next instruction only writes the loaded register (`lw v0,0(v0);
nop; lui v0,...`, a dummy read of a port in the libraries), which maspsx did only for a
load followed by another load.

```bash
git -C D:/FF7/toolchain/maspsx apply "$PWD/tools/maspsx-extern.patch"
```

## Options that match

Each executable is split into C files by how each part was compiled
(`tools/psyq.py`, tables `FILE_OPTIONS` and `OVERLAY_OPTIONS`):

| File | Range | Compiler | `cc1` | maspsx |
|---|---|---|---|---|
| `src/main/text.c` | 0x800110B8–0x800137FF, game code | GCC 2.6.3 | `-O2 -G8` | `-G8`, ASPSX 2.21 |
| `src/main/text1b.c` | 0x80013800–0x80013C9B, game code | GCC 2.6.3 | `-O2 -G8` | `-G8`, ASPSX 2.21 |
| `src/main/text2.c` | 0x80013C9C–0x80016F8F, game code (kernel strings...) | GCC 2.7.2 | `-O2 -G8` | `-G8`, ASPSX 2.34, `--nop-at-expansion` |
| `src/main/text3.c` | 0x80016F90–0x8001BDAF, game code | GCC 2.6.3 | `-O2 -G8 -ffixed-25` | `-G8`, ASPSX 2.21 |
| `src/main/text4.c` | 0x8001BDB0–0x800269FF, game code | GCC 2.7.2 | `-O2 -G8` | `-G8`, ASPSX 2.21 |
| `src/main/text5.c` | 0x80026A00–0x80029A4F, game code | GCC 2.7.2 | `-O2 -G8` | `-G8`, ASPSX 2.21 |
| `src/main/akao.c` | 0x80029A50–0x80036297, AKAO sound driver, CD/movie code | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/main/lib.c` | 0x80036298–0x8003DDBB, PSY-Q libraries (libapi, libetc...) | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.34 |
| `src/main/lib2.c` | 0x8003DDBC–0x800404F3, libcd (from `bios.c`) | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/main/lib3.c` | 0x800404F4–0x80042167, PSY-Q libraries | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.34 |
| `src/main/lib3b.c` | 0x80042168–0x80042C5F, PSY-Q libraries | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/main/lib3c.c` | 0x80042C60–0x80043937, PSY-Q libraries | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.34 |
| `src/main/lib4.c` | 0x80043938–0x8004602B, libgpu (from `sys.c`) | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/main/lib5.c` | 0x8004602C–0x80048D17, libgpu and the rest | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/battle/text.c` | BATTLE.X up to 0x800B30E4 | GCC 2.7.2 | `-O2 -G0` | `-G0`, ASPSX 2.34 |
| `src/battle/text2.c` | BATTLE.X, 0x800B30E4–0x800E5F2F | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/battle/text3.c` | BATTLE.X from 0x800E5F30 | GCC 2.7.2 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/field/text.c` … `text5.c` | FIELD.BIN, cut where the game's files began | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/*menu/text.c` | the 13 menus (MENU/*.MNU) | GCC 2.7.2 | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/<overlay>/*.c` | every other overlay | GCC 2.6.3 | `-O2 -G0` | `-G0`, ASPSX 2.21 |

The game's code was many source files; our files are groups of them, cut where the way
they were built changes (or, in FIELD.BIN, where the jump tables show a new file). How
the main executable's options were settled:

- **ASPSX below 2.30 for most of the game's code**: a global plus a register is
  `lui $at; addiu $at, %lo(x); addu $at, $reg; lw 0($at)` (maspsx's form below 2.30),
  and before an instruction expanded through `$at` that uses the register just loaded
  there is an extra `nop`. 2.21 is one value below 2.30.
- **`text2.c`, a newer ASPSX**: there `%lo` is folded into the load
  (`lw $v0, %lo(x)($at)`), as from 2.30 on, and `li` of an unsigned 16-bit constant is
  still `ori`, as up to 2.56; it also has that `nop`, which maspsx gives a newer version
  only with `--nop-at-expansion` (from its patch). 2.34 is one value in between.
- **GCC 2.7.2 for `text2.c` and `text4.c`**: there a function can end
  `lw $ra; li $v0, 1; jr $ra; addiu $sp` (2.6.3 never fills a return's delay slot so),
  and some registers are allocated as 2.7.2 does (`mflo $v1` where 2.6.3 picks `$v0`).
  Elsewhere functions match only with 2.6.3. The boundaries are where those functions
  change sides, and where the same variable starts being reached through `$gp` or with
  `lui` (its declaration changed, so the source file did).
- **`-G8` only for the game's code**: no function from 0x80029A50 on uses `$gp`, not even
  for 1–4 byte variables right next to it, and neither do the overlays (`$gp` points
  into the main executable's data).
- **Externs reached with `lui`/`%lo`**: when the game reaches a small variable that way
  (too far from `$gp`, or declared bigger than `-G` in its source: part of an array or
  a struct), `psyq.py` drops the size from its `.extern` line so maspsx does not put it
  on `$gp`. Which variables near `$gp` are reached only that way is read from the game's
  own code.
- **AKAO**: Square probably built the driver apart, with older tools (ASPSX below 2.30).
- **PSY-Q libraries**: some of `lib.c` was built with other options (for example
  without filling a return's delay slot), and the GTE (cop2) and BIOS-call functions
  were assembly to begin with. Two ASPSX versions show in the libraries: libcd and
  libgpu have the unfolded `lui; addiu; addu; lw 0($at)` of a global plus a register
  (2.21), the others the folded `%lo(x)($at)` (2.34). `lib2.c` and `lib4.c` hold the
  2.21 ranges as far as the forms show them (the `$Id:` strings of `bios.c` and `sys.c`
  mark where those libraries' files are); the cuts may move once more of the
  functions around them are in C.

`INCLUDE_ASM` uses splat's `maspsx_hack` style: GCC 2.6.3 puts top-level `asm` ahead of
the C functions around it, so each `INCLUDE_ASM` is wrapped in a dummy function that
maspsx unwraps, keeping the order. `INCLUDE_RODATA` (`include/common.h`) does the same
for rodata.

### Rodata

Each C file has its own part of `.rodata` (config: `[0x800, .rodata, text]`, ...), and
splat moves every function's jump tables and strings into its asm file, so a function
written in C brings its own: GCC's `.rdata` is renamed `.rodata`. GCC aligns a jump table
on 8 bytes from the start of its file's rodata, and the link packs each file's rodata on
2 bytes (`SUBALIGN(2)`), so that alignment is relative to the file's start, as it was in
the game. Where one of our files holds several of the game's, its start is not theirs:
its jump tables are aligned on 4 bytes instead (where the game really has padding,
`match.py` reports a rodata difference), unless the file starts on 8 bytes or is marked
`unit_start` (it begins where one of the game's files began). The game's files show in
the jump tables: those of one file are all on 8 bytes, or all 4 bytes past them, so a
change marks a new file (that is how FIELD.BIN's were found). A function checked alone
(`work.py`, the permuter) has its rodata start where the function's own does, which in
such a file may be 4 bytes past the file's 8: `match.rodata_pad` puts that many bytes
before its object's rodata, so its tables are aligned as in the whole file.

Strings a function uses are string literals in its C. A function may not define tables
of its own (`static` or global data): GCC puts static data at the end of its file, which
in our larger files is not where the game has it, so the game's tables stay in asm and
the C declares them `extern` (`tools/work.py put` refuses such data, keeps a table the C
reads by name in an asm file of its own with an `INCLUDE_RODATA`, and checks the whole
file).

C code may name any address as `D_80012345` or `func_80012345`; `build.py` gives each such
name its address (`build/us/<target>.addresses.ld`), whether or not splat named it.

## Writing a function

- `tools/match.py FILE.c` compiles a file the way `build.py` does and compares **every
  word** of each function with the game's, after filling in addresses as the linker
  would (from the built ELF, so run `build.py` first), and the object's rodata with the
  game's. From Python, `match.check(file, like='src/main/akao.c')` compiles with the
  options of the named file.
- `tools/auto_decomp.py --target main --max 100` has m2c draft each function still in
  asm (smallest first) and keeps the ones that match: the draft, the draft with struct
  members (`M2C_SFIELD`) and the draft with neighbouring statements swapped are tried.
  The function replaces its `INCLUDE_ASM` and its declarations, its own prototype among
  them, go into `src/<target>/decls.h`. When a new prototype replaces a guess m2c made
  earlier for a caller, every function in C is checked again, and the new one is taken
  out if a caller stops matching. The rest are listed with the reason in
  `build/us/auto_decomp.txt`.
- `tools/work.py show NAME`, `diff FILE NAME`, `put FILE NAME`: the same by hand, from
  m2c's draft to a function in place (see its help). A work file's own declarations
  replace decls.h's for the same names.
- `tools/permute.py WORK.c NAME` hands a near miss to
  [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) (clone it next to the
  toolchain, `pip install pycparser toml` in the venv): base.c is the work file expanded,
  and each candidate is compiled as the function's file is built and linked at its game
  address (`tools/permute_cc.py`), so only real differences count. A match is written
  next to the work file for `work.py put`; `tools/permute_all.py LIST` runs a list of
  them one after the other.
- `tools/split_file.py TARGET FILE NEW ADDRESS [RODATA]` splits a C file where the game's
  source files change (a different compiler, or a variable declared otherwise), and
  `tools/find_units.py` lists the rare functions followed by a file's padding `nop`.
- When done: `tools/build.py` must still match.

What GCC 2.6.3 needs to produce the game's code (learned from functions that match):

- `while (1)` rather than `for (;;)`; a value chosen with `if`/`else` into a temporary
  and stored once, rather than `?:` inside the store.
- The scheduler may swap a load through a pointer to a struct with a store to a plain
  variable at a fixed address (and the reverse), never two accesses of the same kind.
  So when loads and stores are out of order, try a struct member
  (`D_8009A104[1].unk28 = 0`) instead of the field's own name (`D_8009A18C = 0`), or the
  other way round, or the statements in the other order.
- A fixed address kept in a register comes from a pointer variable in the source
  (`p = &x; *p |= ...`); for other fields of a constant pointer, GCC goes back to the
  fixed address (`lui`/`%lo`).
- `u16` counters give `addu n, n, 0xFFFF` + `andi`; where `n--` sits in the loop body
  decides the order constants are hoisted out of it.
- Register choice follows the order variables are declared and how long they live;
  reusing a parameter as a variable changes it.
- A `switch` table spans the smallest to the largest case, so empty cases may be needed;
  case blocks are laid out in source order, and identical tails are merged.

[m2c](https://github.com/matt-kempster/m2c) drafts C from asm:
`python D:/FF7/toolchain/m2c/m2c.py asm/us/main/nonmatchings/<file>/<function>.s`.
