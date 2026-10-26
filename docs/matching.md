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
- Write the symbols the asm names (`D_801E56D6`, not `D_801E56D0.pad`; the array the asm
  indexes, not a neighbour plus an offset): tools/propagate.py renames only those, so
  copies of the function elsewhere get the right addresses.
- A global the asm only reaches through a field symbol: `D_f[0] = v; f(&D_f[-4])`, or an
  anonymous-struct extern for the field. A global filled then passed by address: assign
  its fields, pass `&D_x`.
- Actor fields: a struct array based at the field's own address (`D_80074EFC[]`, never
  named otherwise) gives `sym+off(reg)`; a flat `u8` array hoists the base instead.
- An index `(a*0x2E7 + b*0xD) << 2` is `X[a].c[b]` folded by the common factor 4; only a
  declared global struct array gives its `sym+reg` addressing.
- A local struct copied from rodata with `lwl`/`lwr`: `r = D_x;` from an extern (put
  keeps the table as an `INCLUDE_RODATA`). A copy with an `or`/`andi 3` alignment test and
  two loops is a byte-aligned struct, `typedef struct { u8 b[N]; } T;`,
  `*(T *)dst = *(T *)src`.
- Results: `sll v0, v0, 16; bltz` on a returned value with a copy in `v1` is an `s32`
  callee and local tested `(s16)r < 0`; a result re-masked with `andi 0xFFFF` at each use
  is kept in an `s32` (callee returning `s32`); `sll 16; sra 4` on a call result is
  `(s16)f(a, b) << 12`. A `move v0, vN` of an index before index arithmetic in a search
  loop means the function returns the index. A branch to the epilogue whose empty delay
  slot `li v0, N` could have filled: `v0` is live, the function is `s32` returning
  nothing.
- A copy without sign extension whose later uses are sign-extended can still be an `s16`
  parameter or local.
- One `lhu` compared to 0 over two adjacent byte fields: `p->a == 0 && p->b == 0`.
- Hardware and polled globals are `volatile`: `jr ra; nop` after a store (the store kept
  out of the delay slot, or out of a `j`/`jal` slot) means the pointee is volatile (the
  GPU/DMA/SPU ports in the libraries); a spin loop on a halfword needs the global
  declared `volatile u16` (`D_80095DD4`). Declarations in `main/decls.h` reach every
  overlay, so their types matter there too.
- A `u16` global read with `lh` needs `(s16)D_x < N`, the mirror of `(u8)D_x` for `lbu`.
  m2c's `&D_x + 0xA` on an `s32` extern scales by 4: declare `extern u8 D_x[];`.
- A table written both byte by byte and through a struct gets one name with the struct
  type, cast to `u8 *` where it is written bytewise; never a second name for data.
- A `u8` result the callers use without `andi`: define `s32 f()` returning a `u8` local.
  A callee declared `s32 f();` whose caller does `return f();` must be defined `s32`.
- The pause flag `D_80062D98` tested twice: plain `D_80062D98 == 0` tests match in most
  functions; when the first test's branch lands on the second test in the game, write one
  as `*(u8 *)0x80062D98 == 0`, or CSE retargets the branch past the second test.

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
- `do { ... } while (0);` (a macro's wrapper) is a scheduling barrier: register saves all
  before a loop's start values come from a loop wrapped so; a plain global loaded early
  and used once (2.6.3 moves it down to its use) stays early with the rest of the
  function after it wrapped so (volatile instead gives `lui; addiu; lw 0(reg)`).
- The scheduler takes a struct and a scalar to never overlap: a load in the wrong place
  around a store wants one side made a struct field (a 5th stack argument loaded after a
  store through `&D_x` only if `D_x` is a struct). A cast store (`*(u16 *)D[i].pad = 0`,
  `*(s32 *)&p->r0 = c`) keeps its place where a field store moves; a scratchpad struct at
  a constant address (`s = (T *)0x1F800000`) is never reordered with loads through struct
  pointers, so its statements are in source order.
- Copies between two globals kept load/store/load/store: both sides `volatile`.
- 2.7.2's second scheduler puts stores of nonzero constants before stores of `$zero`: a
  block of initialisations is written in its natural order anyway.
- The first access to an array decides where its base is loaded: write the first access
  through the pointer too (`p = &D[i]; p->f = -1;`).
- `q[b] = lo; q[b] |= hi << 8;` reuses the stored value; `G->a = G->b = 0` loads a global
  pointer once for both stores; a value re-read after a store without `volatile` was
  stored in both arms of an if/else and read after the join.
- A load of another symbol that 2.6.3 lifts above a store: name the stored or loaded
  element through an earlier symbol plus an offset (`D_8008326B[i + 1]` for
  `D_8008326C[i]`, `D_80151908[id][7]` for `D_8015190F[id][0]`). Adjacent halfword
  globals declared as one struct keep a load/store/load/store order. A halfword reload is
  not forwarded after a store to a neighbouring halfword of the same struct.
- Operand order of `addu`: `ptr + idx` through a named variable gives (idx, ptr),
  `M2C_FIELD(&ptr[idx], T, k)` (ptr, idx); `e = (T *)(o + (s32)base)` with `o = j * 0x18`
  gives (off, base) where `&base[j]` gives the other order; for `p = idx + p` write the sum
  into another variable, or the expander swaps it back.
- Reassociation: `a/16 + (c - 1)` becomes `(a/16 - 1) + c`, `(t + 8) + base` becomes
  `(base + 8) + t`: compute the parts in separate statements (`u = t + 8;`). Pointer
  arithmetic keeps `(x*4 + 0x70) + D`: `(s32)((u32 *)D + (v >> 2) + 0x1C)`.
- The prologue's argument copies follow where each parameter is first copied: name the
  parameter differently and write `x = arg0;` after the initialisations to move it.

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
  ... }` with `c` an `s32`. `m = 0xFF; if (c != 0xFF) m = T[c];` lets CSE carry values
  across the join where the game re-reads: if/else with an `s16 m`.
- A copy `orig = t;` lets CSE give `t`'s uses `orig`'s register: assign the result back
  to `t` (`t = (t * n + orig * (0x100 - n)) >> 8; return t;`).
- `&D_x` kept in a register for several stores: a pointer local `s16 *p = &D_x`, even when
  neighbouring globals still use `lui $at`.
- `for (i = 0, n = 0; ...)` gives `i` its register before `n`.
- A loop-invariant flag in a saved register: `c = (a & 4) ? X : Y` inside the loop.
- Local allocation runs before global allocation: temporaries local to one block that
  live across a call take `s0`, `s1`... first; one that spans a branch becomes global and
  waits. Reusing one variable (a pointer for every spawned particle, one `i` for a clamped
  value and then the loop counter) raises its priority.
- A `return 0` whose `v0 = 0` is hoisted to the top of its block holds `v0` for the whole
  block: if/else with one `return 0` at the end frees it. `r = cond; if (r) ...` gives
  the result variable `v0` and keeps it off a dying argument's register.
- `a = 1; if (c != 0xFF) a = f();` keeps 0xFF in a saved register across the call where
  the if/else form reloads it, as the game may.
- `sll 16; sra 16` of a call result into a saved register: one single-set variable per
  use, `s32 x1 = (s16)f();`. A flag that must sit in a callee-saved register across a
  call: `flag = 0;` right before that call. The first scheduler moves an instruction that
  sets a single-set pseudo live across a later call to just before the call (its delay
  slot); a pseudo set twice is not moved.
- Two same-width accesses of one global in an extended basic block can share
  `la sN, sym` even across calls; a second name for the same address (`D_8010C35E` for
  `D_8010C35C + 2`) avoids it.
- When nothing else moves a register, a no-op `q++; q--;` after the pointer's last use,
  or a separate single-block temporary for a copy (a temporary used in other blocks
  coalesces with its copy), changes the priorities.

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
- `x < 0 ? -x : x` gives `bgez x; move t, x; negu t, t`; the if form does not. Chained
  ternaries put the value blocks out of line in reverse order; an else-if chain keeps
  them inline.
- Five consecutive cases make a jump table; leaving one to `default` gives the game's
  compare tree.
- `(x & 4) || (x & 8)` folds to one `andi 0xC`; the game's two tests are
  `if (x & 4) f(1); else if (x & 8) f(1);` (the calls are cross-jumped).
- A call common to every branch, written once after the switch, changes the layout and
  the frame: write it in each branch.
- A then-arm that branches into the else-arm's store (`beqz → store; j end`): m2c's goto
  shape matches.
- Cross-jumping keeps the textually last of identical tails in place: in opcode handlers
  that end each branch with `D_800831FC[D_800722C4] += N; return 0;`, order the branches so
  the game's copy comes last. Two cases with identical bodies merge whole; where the game
  shares only inner blocks, write them once with labels and `goto` into them. Two
  `return 0` the game shares: a label and `goto`.
- A `switch` with `default` last avoids a tail merge that `default` first or an if chain
  causes; a jump table with holes needs the holes as explicit cases
  (`case 0: case 3: ... default:`). `switch (a) { case 0: v = 0; break; case 1: v = 1;
  break; default: v = 0; }` keeps `beqz`/`bne`/`j` where if/else becomes `xori`/`sltiu`.
- A range test the game does as two compares is nested, `if (c < 5) { if (c >= 3) ... }`,
  or GCC makes one `sltiu`. Two identical tests in a row are threaded into one: write
  them as two separate ifs to keep the reload.
- `if (!c) break; goto l9;` gives `beq end; j L9`; `if (!c) return 0; goto l9;` threads
  into one `bnez`. A found block placed first: `goto start; found: ...; goto after;
  start: ... if (hit) goto found;`. Early returns and if/else give different block
  orders: try `if (s >= 0) return a << s; return a >> -s;` and
  `if (c) {A; r = x;} else {B; r = y;} return r;` both.
- A non-void function falling off its end keeps `v0` live: reorg then cannot fill a
  `bnez` delay slot from the loop head, or leaves a `li v0` out of a delay slot.

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
- 2.6.3 reverses store-only loops too. A clearing loop `ori v, N; li a, -1; ... bne v, a`
  is `for (i = N; i != -1; i--) *p++ = x;` (an index `i < N + 1` gives `bgez`).
- `s = ARR; s[i].f = x;` loads the base before the multiply, so strength reduction skips
  it (the game keeps `i*5` and shifts each pass); `&ARR[i]` gets reduced. A row base built
  after the multiply in the same register: `name = D[n]; ... name[i]` inside the loop.
- A loop-bound global read as `lui; addiu; lh 0(aN)` and copied with `move` before the
  loop: an array read `D_x[0]`. A bound copied before the loop: an `s16` local,
  `s16 end = i + n; for (; i < end; i++)`.
- 2.7.2: a conditionally filled local buffer is `buf[n++] = v;` (not `*p++ = v; n++;`).
- `do { ... } while (--i != 0);` where `i--;` before an `if` got the decrement scheduled
  before a call.
- A copy loop with its guard, `lh; li -1; addiu -1; beq`: `n = p->cnt; while (--n != -1)
  *d++ = *s++;` (`for (i = n - 1; i != -1; i--)` folds the guard into `beqz`). A countdown
  entry `li 8; addiu -1`: `n = 8; loop: n -= 1; if (n != 0) { ...; goto loop; }`.
- A ring index `k++; if (k >= N) k = 0;` over `D[k].f` gives the game's stepping pointers
  and their reset at the wrap; based at the real struct start, not at field symbols.
- A store-only loop `for (i = 0; i < N; i++) { o = i * K; D[o] = c; }` gives
  `li (N-1)*K; addiu -K; bgez`. A byte offset advanced by hand (`off += 0x4C`) stays an
  unreduced `base + off`, where `i * 0x4C` or `&a[i]` is strength-reduced.
- Division in a loop: `for` with the expression inline hoists only the sign shift, a goto
  loop hoists nothing, `do`/`while` with a temporary hoists all of it. Values carried over
  from the previous pass (the game skips a first pair of `rand` draws): uninitialised
  locals declared outside the loop.

### Stack frame

- Try the plain code first; if the frame is still too small, an unused local
  (`s32 pad;`, `u8 pad[8]`) makes it bigger. Reading a field twice instead of through a
  local temporary can shrink it.
- An unused 8 bytes usually come from a local variable, not a pad: try adding or removing
  a temporary first. `u8 pad[4]` and `u8 pad[8]` both add 8 bytes, `s32 pad[1]` nothing.
- Sibling functions sharing one set of locals (club1's 3 SVECTOR, 2 MATRIX, 1 VECTOR):
  declare the unused ones in their slots to rebuild the frame.
- An `s16` local kept across calls (even a copy) adds 8 bytes; an `s32` local tested as
  `(s16)w < 0` does not. A 4-byte struct or array local takes an 8-byte slot; two scalar
  `u16` locals do not.
- A function-level `u8 pad[]` lands below the address-taken scalars, one declared in a
  later nested block above them. A value spilled at `0x10(sp)` and reloaded in a loop, with
  a frame 8 bytes bigger, is a local array holding it (`s32 sp[4]; sp[0] = ot;`); several
  dead `s16` stores to one local survive only into an array (`s16 r[4]`).

### How the scheduler and the allocator decide

- GCC 2.6.3's first scheduler works backward: loads sink toward their use, and free
  instructions (constants, address set-ups, `i = 0`) go into stall slots, the highest
  LUID first. Moving a statement after an earlier call changes where it lands and its
  live length, and with it the allocation priority `floor_log2(refs) * refs / len`.
  Compile with `-dS -dR` (or `-dL` for loop hoisting, `-dl -dg` for priorities) from a
  helper calling `psyq.assembly(..., cflags=...)`, run in a work folder: the dumps
  (`gccdump.sched`...) show the decisions.
- Registers and operand order follow pseudo creation order: user variables get lower
  pseudos than expression temps, ties break by declaration order. Order the temps and
  statements the way the registers should come (`s32 b, x; x = T[a]; b = G; R = b + x;`),
  declare a pointer before an index for `base + i`. A variable set in two blocks is
  allocated like a global, after the block-locals (2.7.2 even within one block:
  `n = s / 10; ... n = s % 10;` gives `mfhi a2` where two temps give `a1`): repeat the
  expression or use one variable per block or loop. A named variable shared by blocks
  sums their priority and takes `v0` first.
- What a store lets pass: a plain-symbol store does not stop a pointer load, a store
  through a scalar pointer stops symbol and pointer loads, a struct-field store stops
  only pointer loads, and struct member loads (alias-free) float above global stores
  where raw casts do not. So a global declared as a one-field struct
  (`extern struct { s16 v; } D_x; D_x.v = ...`, or `q = &D_x; q->v = ...`) stores like a
  struct field; `M2C_SFIELD(q, s32 **, 0) = ...` keeps later loads after a pointer store;
  a template or vector written as fields of a struct global keeps its loads in source
  order. A store written before a call stays before it.
- To stop a constant being hoisted out of a loop, set it in a local just before
  (shorter life), or give the loop more instructions.

### More forms

- Calls: a function the game calls before its definition was unprototyped,
  `((void (*)())f)(args)` (plain `lw` arguments); one called with other argument counts
  is declared `M2C_UNK f();` or defined with bare parameter names; a call that takes
  nothing may leave a constant set before it in `a0`. A wrapper setting one argument is
  `void f(s32 a, s32 b) { g(a, b, 1); }`; the same value passed twice is
  `v = D * 0x10; f(0, v, v)`; an uninitialised local passed as a fifth argument gives
  `sw sN, 0x10(sp)`; stack arguments read lazily come from a by-value struct parameter.
  An `s32 f(s16)` prototype adds `sll/sra` on the argument.
- Constants: materialised in source order of first use; `c = 0x80;` before a run of
  stores keeps it for a later `0x80 - (...)`; a colour local given 0x80 is `u8`;
  `x - C + f()` folds C onto the call result unless `k = C;` comes first;
  `f(x, c ? A : B)` puts the `li` first; `(x << 5) | 0x10` after an earlier `x << 5` is
  CSE'd where `((x << 1) | 1) << 4` is not; `sll 16; srl 12` is `(u32)(n << 16) >> 12`.
- Narrowing: `q->f = (u16)q->f - 0x64 + f() % 200` reassociates and folds; write
  single-def locals, one per statement. A byte or halfword store of a sum or shift of
  `s16` fields narrows their loads to `lbu`/`lhu` unless they go through `s32` locals
  first; `(u8)D_x` reads a halfword global as `lbu`; `b--` on a `u8` gives `addiu -1`
  where `b -= 1` gives `addiu 255`.
- Copies: a 0x48-byte template copy is a struct assignment from an extern
  `typedef struct { s32 v[18]; }`; eight word assignments give unscheduled `lw/nop/sw`
  pairs where a struct assignment groups them; a 29-word copy is
  `for (i = 0x1C; i != -1; i--) *d++ = *s++`; three words copied one at a time need a
  struct pointer parameter and struct globals; a copy that must survive as `move` is
  made through a cast (`c = (u8)t;`). GCC deletes the first of two stores to one stack
  local unless it is `*(volatile s32 *)&d.x = p;`; `*(volatile s32 *)&sym = v` gives
  `la; sw 0(reg)` and stays out of a call's delay slot.
- Addresses: `s32 off = 0x12674; *(s8 *)(p + off) = 0;` stops `&sym + offset` folding;
  `o = (i * 2 + j) << 3;` keeps one register where `* 8` makes a copy;
  `*(s32 *)(u8 *)&D_x` keeps an address in a register without redeclaring `D_x`.
- Control and loops: `if (--p->f == 0)` uses the register where `p->f--; if (...)`
  reloads (and `++p->f == N` keeps the value across later stores); separate `case 2:`
  and `case 3:` bodies keep a beq chain where `case 2: case 3:` makes a range test;
  `D_x = 0x10; break;` in each case keeps separate blocks; for cases 1 and 2 only, an
  empty `case 0: break;` gives `beq 1; slti 2; beq 2`; a ternary used directly as a stack
  argument lays its arms out reversed; `while (1) { if (!(mask & bit)) break; ... }`
  avoids loop inversion; a goto search loop with the found block first keeps it inline;
  `for (i...)` leaves the increment for a delay slot where `do { ... i++; ... } while`
  puts it before; `for (...; i++, p += size)` puts `i++` first.
- Arithmetic: `t = A; t &= B;` loads early where `t = A & B` loads last; in-place
  accumulation (`s = A - s; s += B;`) keeps one register; `q = s - q * 10` reuses the
  quotient; a remainder may want `%` or `i - i / n * n`, try both; uninitialised unused
  locals reproduce a `subu` of garbage registers; packed colour words assigned field by
  field through a bitfield struct give the `and`/`or` insertion chain.
- More arithmetic: `s16field % 12` is computed in HImode and sign-extended again; read it
  into an `s32` first (`t = p->unk2; t = t % 12;`). A signed `% 1024` whose expansion copy
  must come before other shifts: write it by hand (`m = r; if (m < 0) m += 0x3FF;
  w = r - ((m >> 10) << 10)`). `q->f = p->vx + (rand() % 100 - 0x32)` gives
  `lhu; addiu -50; addu` where `p->vx - 0x32 + rand() % 100` folds the constant;
  `(s32)((c & 0xF) * 8) - 0x80` gives `addiu -128` where the plain form gives `addiu 128`;
  a `u16` field decrement is `li 0xFFFF; addu` unless it goes through an `s32` temporary.
- More addresses: `t = idx * 4 + 0x801B0000;` as its own statement keeps the constant
  address in a register; `*(u16 *)((u8 *)0x801B0000 + idx * 2)` gives
  `lui at; addu at, v0, at; lhu 0(at)`; `extern s32 D_1F800028;` gives `lui at; sw` for a
  scratchpad word, a pointer local assigned the scratchpad address keeps it in a register
  inside a loop; `&D_801B0000` of an `extern M2C_UNK` (a code address) gives
  `addiu a0, a0, 0`. `D_x[a][b]` with 8-byte rows gives `la; addu a*8; addu b`.
- Strings and copies: two literals in reverse order: an unused `char *m = "second";` at
  the top puts it first in rodata; a pair of `$Id:` strings is one literal with an
  embedded `\0`. An unaligned 8-byte copy (`lwl`/`lwr`):
  `typedef struct { u8 b[8]; } T; *(T *)&q->f = *(T *)&p->f;`.
- The permuter can report "closer" with an unreachable statement before a case label:
  check its output with `work.py diff`. Its `inline_fn` candidates only compile inside its
  harness. It ignores stack offsets unless run with `--stack-diffs`, and its score ignores
  the frame size.
- Search helpers that worked when hand edits stalled: every ordering of a block of
  statements, every declaration order, and wrapping each statement in turn in
  `do { } while (0);`, each scored by a difflib alignment of the instruction lists
  (`work.py diff` compares by position, so one extra instruction shifts every later
  word). `cc1 -dg -dl` dumps show the order pseudos are allocated in and the register
  each gets.

## Hand-written assembly

Some functions were assembly in the original and stay `INCLUDE_ASM`: the GTE (cop2) and
BIOS-call functions of the libraries (`lib.c` … `lib5.c`; also stack swaps through
`addu v0, sp, zero`, busy loops on `t6`-`t9`, explicit `$at` use, and leaf copies
interleaved through `t0`-`t3` the way no compiler schedules), and helpers that take arguments in `t0`-`t2` or return
through `jr $at` (battle's func_800D32B4, func_800D8304, func_800D29D4). C with inline
GTE instructions (`ctc2`, `lwc2`, `mvmva`, `swc2` between ordinary code, battle's
func_800D84F8) stays asm too: it cannot be written without `asm()`. splat marks most of
these "Handwritten function", not all (highway's func_800B4114 is pure GTE unmarked).

A file's assembler can change partway: NAMEMENU's code folds `%lo` into a load with a
register index (ASPSX 2.30 and later) from func_801D14E8 on, and not before. Counting
the unfolded `addiu $at, %lo` against the folded `%lo(sym)($at)` per function finds such
a boundary; split the file there and give the new part its options in `tools/psyq.py`.
The PSY-Q libraries were split so: libcd and libgpu have the unfolded form (ASPSX 2.21,
`lib2.c` and `lib4.c`), the other libraries the folded one; the `$Id:` strings in rodata
(`bios.c`, `sys.c`, `intr.c`) show where library files begin.

## Working with agents

The work has been done in batches by Claude Code subagents, each given about 30 of the
smallest functions of one target still in asm, this document, and these rules: one work
folder each, only `tools/work.py put` changes the repository, no git, no
`tools/build.py`, give up on a function after about 20 tries without getting closer,
and report what was put, what was not (with what still differs) and any finding. Two
to eight agents at once, as the machine and the usage limits allow (each permuter run
with `--jobs 2`). An agent stopped by a usage limit keeps its context: stop its leftover
permuter processes, build everything, commit what it put, and resume it later with a
message. On Windows, agents must never run `python3`/`python` (the Microsoft Store
aliases) or `python -` reading stdin: such processes hang at 100% CPU and outlive their
command; scripts are written to a file and run with the venv's Python. Agents never
delete files (`rm`, `Remove-Item`...): Claude Code asks the user about every deletion
even when it may run everything else, so an unattended batch stalls; they overwrite
files or use new names instead (`work/` is ignored by git).
After each batch: `tools/build.py --skip-main <target>`, commit, push.

The spells repeat many functions across their files (and snobo2 repeats snobo): a batch
of one representative per group of identical functions, largest groups first, then
`tools/propagate.py`, which copies each match to its twins (the first two batches of 58
representatives became about 700 functions). Propagate compares shapes with the asm of
functions already in C, which `build.py --split` writes to `asm/us/<target>/matchings/`.

When a target's small functions all fail the same way, check its options before
grinding: counting the folded `%lo(x)($at)` forms against the unfolded `addiu $at, %lo`
ones per file found ASPSX 2.30+ in batini, batres, brom, chocobo, snobo, snobo2 and five
spells, which tools/psyq.py had as 2.21.
