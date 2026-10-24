# Matching functions

How a function goes from `INCLUDE_ASM` to C that compiles to exactly the game's words,
and what the game's compilers turn out to need. `py` below is the repository's Python
(`.venv/Scripts/python`), run from the repository's root; work files go in `work/`
(ignored by git) or any folder outside the repository.

## The loop, per function NAME of target T

1. `py tools/work.py show NAME --target T > work/NAME.c` writes a work file from m2c's
   draft: includes, any new declarations, then the function. If m2c cannot draft it,
   read the asm (`asm/us/T/nonmatchings/<file>/NAME.s`) and write the C yourself.
2. Edit `work/NAME.c`. Declarations in it replace those of `src/T/decls.h` for the same
   names, so a global's type or a callee's prototype can be fixed there.
3. `py tools/work.py diff work/NAME.c NAME --target T` compiles it as its source file is
   built and prints its code next to the game's, `*` on every word that differs.
4. Repeat until `NAME: OK`, then `py tools/work.py put work/NAME.c NAME --target T`: it
   checks again, puts the function in its source file and its declarations in decls.h,
   checks the whole file (and every file, when decls.h changed), and undoes it all if
   anything stops matching.
5. A near miss can go to the permuter: `py tools/permute.py work/NAME.c NAME --target T
   --minutes 10 --jobs 4` (see [toolchain.md](toolchain.md)).

`put` takes a lock (`build/us/work.lock`), so several people or agents can work on the
same target at once. Each works on its own functions; only `put` writes `src/`.
`tools/progress.py` counts what is done.

## Rules

- No data of the function's own: no `static` or `const` tables, no global definitions,
  no `asm(...)`. GCC moves such data to the end of the file. The game's tables stay asm
  and the C declares them `extern`; `put` keeps a table the C reads by name in an asm
  file of its own (an `INCLUDE_RODATA` before the function).
- String literals are written as `"..."` (the asm shows them as `.asciz`). A string
  shared with a function still in asm stays `extern char D_x[]` until all its users
  are C.
- Keep every typedef on one line, and list new types in the order they depend on each
  other: `put` adds them at the end of decls.h in that order and moves any changed
  declaration that uses them after them. Prefix new type names with the target
  (`WmActor`, `FdWin`, `BtlRect`) so they don't clash. To give a global new fields
  without a new type, a one-line `extern struct { ... } D_x[];` replaces its declaration.
- A definition with bare parameter names, `void f(arg0) {`, is declared `f()`, so
  callers passing other numbers of arguments still compile.
- Any `D_XXXXXXXX` or `func_XXXXXXXX` name resolves by its address, named in the
  symbol files or not.
- The compiler and assembler version and options are set per file by `tools/psyq.py`
  (see [toolchain.md](toolchain.md)); if a function only matches with other ones, its
  file may hold several of the game's files.

## What GCC 2.6.3 and 2.7.2 need

### Types and declarations

- Write it the way a 1997 programmer would: structs, arrays, plain loops. m2c's
  `M2C_FIELD(p, T *, off)` is a cast pointer, `M2C_SFIELD` acts as a struct member.
- Unsigned vs signed, `u8`/`s16` parameters and returns, `!= 0` or nothing: all change
  the code. `s16 v = (s8)*p` gives `lbu`/`sll`/`sra`, an `s32` variable `lb`.
- An `s16` parameter: shift counts use the raw register, other uses sign-extend. If the
  game copies `a0` without sign extension, the parameter is `s32` (even if stored with
  `sh`); all-`s32` parameters also fix the order of register saves.
- The game passes a value with another sign extension than the callee's definition, or
  more arguments than its prototype has: call it through a cast,
  `((s32 (*)(s32, s32))func_X)(1, 0)`. Callers of a function returning `u8` often use the
  result without `andi 0xFF`: `((s32 (*)(void))f)()`.
- `v0` untouched after the last call: the function returns that call's result.
- A `lhu` followed by a redundant `andi 0xFFFF` (or `sll`/`sra 16` after a load), or a
  global read again although nothing changed it: the global is `volatile`.
  `lui; addiu; sw 0(reg)` storing a plain global is a volatile store,
  `*(volatile s32 *)&D_x = v`.
- A "symbol" such as `func_801B0000` used only through `%lo` may be a constant pointer,
  `(u32 *)0x801B0000` (an overlay's load address).
- A real global struct array (`D_x[i].f`) gives the game's `sym+off(reg)` addressing; a
  cast `((T *)D_x)[i].f` puts the base in a register instead. Declaring a struct-array
  base the asm never names can give the game's addressing.
- `s16field & 0x100` loads with `lhu`; the game's `lh` comes from reading the field into
  an `s32` local first. `s16 n = byte + 1` gives `lbu s0; addiu s0, s0, 1`, an `s32`
  gives `lbu v0; addiu s0, v0, 1`. A return value sign-extended again by the caller:
  declare both the callee and the local `s16`.
- A value narrowed with the wrong registers (`a & 0xFF`): pass it through a cast `u8`
  prototype, `((s32 (*)(s32, u8))func_X)(x, a)`.
- Variadic functions spill `a0`–`a3`: `void f(s32 cmd, ...)`, the extra arguments read
  as `args = &cmd; args[i]`, a `u16` local for the fixed one (`c = cmd;`) to get `lhu`.
- An OT link, `(x & 0xFF000000) | (y & 0xFFFFFF)`, matches as a bitfield struct
  (`typedef struct { u32 addr : 24; u32 len : 8; } FdTag;`, `->addr = ...`); with masks
  the two constants swap registers.
- 2.7.2: an array element both loaded and stored (`D[8]`) gets its address in a register
  and the branches cross-jumped; a plain extern for that element (`extern u8 D_x;`)
  keeps the game's direct `lui`/`%lo` accesses.

### Order of instructions

- The scheduler may swap a load through a struct pointer with a store to a plain global
  (it assumes they are apart), but never two accesses of the same kind. When two
  instructions are in the other order, try the statements the other way round, a field
  of a struct instead of a plain variable, or the reverse.
- 2.6.3 takes two different plain symbols as never aliasing, even indexed. A store to
  symbol plus a non-zero offset (a cast pointer, `*(s16 *)((u8 *)p + 4) = 1`) keeps a
  later load after it.
- Stores through a global pointer: `M2C_SFIELD(D_x, T *, off) = v` stops GCC reloading
  the pointer; a load that must stay after a store to a plain global: `M2C_FIELD`.
- `A[i] += 1` loads A's address first, then shifts i; `p = &A[i]; *p += n` shifts first.
  An operand written out inline each time (`(D_x + D_y[D_z])[n]`) loads the offset
  before the base; through a pointer temporary, the base first.
- 2.6.3: `base + (i << 2)` on an integer address gives `addu v0, base, idx`;
  `ptr + i * 4` puts the multiply first.
- 2.7.2 reassociates `(x*k + C) + y` so that C joins the other operand; compute
  `t = x*k + C;` in a single-use temporary to keep the game's `addiu`.
- A constant assignment written after a call is moved into the call's argument setup.
- 2.7.2: a plain scalar global read scheduled before indexed array stores the game has
  ahead of it: declare it as an array and read `D_x[0]`.
- A temporary computed as its own statement moves things: `j = 3 - i;` first in a loop
  body changes which constants are hoisted first; `n = p[0];` before an expression sets
  the operand order of its `addu`. `v <<= 8; v |= x;` keeps registers that
  `v = (v << 8) | x` swaps.

### Registers

- Register choice follows the order variables are declared and how long they live;
  caller-saved temporaries are allocated in declaration order. A C variable has one
  register for the whole function: reuse one variable where the game keeps one
  register, give temporaries their own single-use variables.
- An address kept in a register was usually a pointer variable (`p = &x; ... p->a`). A
  global re-read through a register several times is a pointer variable to it.
- A local used once (`mask = D_x;`) changes registers where CSE of the global would not.
- A remainder written `i - i / 91 * 91` gives the game's registers (or saves a `move`)
  where `i % 91` does not.
- A loop bound kept in a register (`li t3, 31` hoisted, `slt` in the loop) is a local:
  `n = 31; for (i = 1; i < n; i++)`.
- A table value re-read into the same register: `c = byte; if (T[c] != 0xFF) { c = T[c];
  ... }` with `c` an `s32`.

### Control flow

- `while (1)` matches where `for (;;)` does not.
- A `switch` table runs from the smallest to the largest case; empty `case N: break;`
  lines may be needed to make it as long as the game's. Case blocks are laid out in
  source order.
- GCC merges identical tails (cross-jumping): one store or call written in each branch
  often matches where an if/else into a temporary does not, and calls in both arms
  become one `jal` at the join with the arguments computed in each arm.
- 2.7.2 lays out `if (c) return A; return B;` reversed: use if/else into a temporary and
  one return. An `else` block placed first in the game means the condition is inverted.
- An instruction that starts both arms of an `if/else` lands in the branch delay slot:
  repeat the test in both arms. `if (r <= 0) { if (r >= -1) ... }` nested, not `&&`.
- A two-case `switch` gives the game's block layout where `if/else` does not.
- `m = 0; if (!(x & 0x20)) m = 3;` gives `sltiu/negu/andi`; `(x & 0x200) != 0` through a
  temporary gives `andi/sltu`; `v & (1 << n)` with a mask local keeps `li 1; sllv; and`.
- `return 1` sharing a register with a store of 1: a `ret` variable.
- 2.6.3 lays out `if (c) { A; return 0; } else { B; return 1; }` with B first.
- In a switch, `if (cond) break; return 1;` keeps the cases apart; the inverted
  `if (!cond) return 1; break;` gets cross-jumped into one tail.
- A `sltiu` clamp after a `< 0` test: `(u32)v > 11`.
- A hoisted `slti` flag and `-(i > 0) & 8`: `(rows >= 2 && i > 0) ? 8 : 0`.
- `lw 0(reg); ... jr ra; sw 0(reg)` on a global (the store in the delay slot): a pointer
  local, `p = &D_x; *p += n;` (a volatile store stays out of the delay slot).
- A retry loop with the result zeroed in a jump's delay slot:
  `do { ... } while (dir == 0 && i < 100); if (dir != 0) { ... } else { mask = 0; }
  return mask;`.

### Loops

- An address stepping by a constant: write `base + i * 0x20` and let loop optimisation
  make the stepping register, not a pointer advanced by hand. A loop that only counts a
  byte offset down to `bgez` is `for (i = N * sizeof(T); i >= 0; i -= sizeof(T))`.
- Loops over struct arrays: `p = &D[i];` inside the loop.
- Counters declared `u16` give `addu n, n, 0xFFFF` + `andi`; where `n--` sits decides
  which constants are hoisted first. A `u8` loop bound gives `beqz` at the loop entry.
- A constant left inside a loop with a call: a `goto` loop stops it being hoisted.
- Doubled address computations (`&D[i]` used twice) come from a flat `s32` array indexed
  `D[i * 2]` and `D[i * 2 + 1]`.
- The exception: a loop register kept at a struct's last field, the other fields at
  negative offsets (`-8(s0)`, `-16(s0)`), is a pointer advanced by hand
  (`p = D.o; ... p->x = v; p++;`).
- 2.7.2 reverses a loop that only stores: a counter from N-1 down to `bgez` and a pointer
  stepping down from the array's end is `for (i = 0; i < N; i++) a[i] = c;`.
- Registers stepping by a constant, set up after the hoisted constants, come from an
  expression of the counter at each use: `(s16)(x + i * 0x10)` in a call, or a row
  counter `n * 0xB + 0x9A` with `n++` inside an `if` (two such registers swap if written
  as two variables). A loop ending in `slt p, base + 8` is a `for` over `i` reading
  `base[i]`, with `i` optimised away.
- A counter that must get the first free register: `n++` in each branch (the tails are
  merged only after register allocation).

### Stack frame

- Try the plain code first; if the frame is still too small, an unused local
  (`s32 pad;`, `u8 pad[8]`) makes it bigger. Reading a field twice instead of through a
  local temporary can shrink it.

## Hand-written assembly

Some functions were assembly in the original and stay `INCLUDE_ASM`: the GTE (cop2) and
BIOS-call functions of `lib.c`, and helpers that take arguments in `t0`-`t2` or return
through `jr $at` (battle's func_800D32B4, func_800D8304, func_800D29D4). C with inline
GTE instructions (`ctc2`, `lwc2`, `mvmva`, `swc2` between ordinary code, battle's
func_800D84F8) stays asm too: it cannot be written without `asm()`.

A file's assembler can change partway: NAMEMENU's code folds `%lo` into a load with a
register index (ASPSX 2.30 and later) from func_801D14E8 on, and not before. Counting
the unfolded `addiu $at, %lo` against the folded `%lo(sym)($at)` per function finds such
a boundary; split the file there and give the new part its options in `tools/psyq.py`.

## Working with agents

The work has been done in batches by Claude Code subagents, each given about 30 of the
smallest functions of one target still in asm, this document, and these rules: one work
folder each, only `tools/work.py put` changes the repository, no git, no
`tools/build.py`, give up on a function after about 20 tries without getting closer,
and report what was put, what was not (with what still differs) and any finding. At
most four agents at once. On Windows, agents must never run `python3`/`python` (the
Microsoft Store aliases) or `python -` reading stdin: such processes hang at 100% CPU and
outlive their command; scripts are written to a file and run with the venv's Python.
After each batch: `tools/build.py <target>`, commit, push.
