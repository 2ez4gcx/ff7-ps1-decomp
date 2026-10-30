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
- A decremented halfword global (`lhu; addiu -1; sh; sll 16; bnez`) is `s16`; `u16` gives
  `andi 0xFFFF`. `(u16)p->f` in an `s32` sum gives `lhu` where the plain field gives `lh`;
  `t = *(s16 *)&G; t &= 0x1F;` keeps `lh` where the one-liner becomes `lhu`. A `u8` global
  tested `x < 9` gives `sltiu`, `s32 t = D_x; t < 9` gives `slti`.
- Reassigning a `u16` parameter (`arg2 >>= 4`) keeps the `andi 0xFFFF` a separate `u16`
  local loses. An 8-byte struct parameter (`MgSVec v`) spills `a1`/`a2` to the caller's
  frame and passes `&v` on.
- A volatile struct field makes 2.6.3 re-read it after a branch instead of reusing the
  earlier load (which also moves constants to other registers); after an `lh` of a field,
  `((volatile T *)p)->f & 1` forces the `lhu` reload. A pause flag kept in a saved
  register: `extern volatile u8 D_80062D98; z = D_80062D98; if (z == 0)`.
- Spawn functions copy a 0x48-byte template: a struct type with the fields the function
  writes, copied as `s->unk4 = *(T *)&D_x;`. A packed word filled field by field from an
  uninitialised union of a `u32` and `u8` bitfields gives the `and`/`or` insertion chain
  on a stale register; such a union kept in a register with `x.b.d2 += c` re-reads the
  field for `if (x.b.d2 >= 10)` (`srl`), where `(x.b.d2 += c) >= 10` compares the masked
  sum.
- A parameter its callers sign-extend (`sll/sra`) but the callee uses raw is `s32` in the
  callee, and callers passing a sum cast it, `f(0, (s16)(x + 0x2F), ...)`. `put` refuses a
  function whose new prototype breaks a caller already in C ("matches alone, but not in
  its file"): fix the caller first, then put.
- A call's `s32` result assigned to an `s16` local leaves the raw copy in a saved register
  and sign-extends from `v0`; `s16 a = f()` stored at the end of its block gives `move v0,
  s0; sh v0` where an `s32` gives `sh s0`. A function that falls off its end is `s32` when
  the game leaves a `bne; nop` delay slot unfilled. A leftover register passed as an extra
  argument: call through a cast prototype with that argument.
- `(u8 *)0x801A0000` instead of `&D_801A0000` (an overlay's code address) removes an
  `addiu v1, v1, 0`. `addiu s5, s4, -0xF0` between two tables means one symbol with
  offsets: declare one struct, not two arrays. A dead local copied from rodata (`c =
  D_x;`) is kept.
- A global read as `lh D_a` and later through `la D_a+0x18` is one struct (count at 0,
  bytes at 0x18); separate externs give the second access its own `lui`. A global declared
  as an array (`extern s32 D_x[]; D_x[0] = v;`) gives a shared `la reg; sw 0(reg)` where a
  scalar gives `lui at; sw`; the words of one packet buffer are one array, a GPU packet `{
  u32 addr:24; u32 len:8; u32 code[N]; }`. Two externs for adjacent halfwords stop the
  shared `la` of element 0.
- `s32 x = T[i]; s16 id = x;` gives `lh; move` with the sign-extension redone later, a
  single `s16` gives `lhu` plus `sll/sra`. A `u8` parameter used directly as `D[arg0]`
  (with `i = arg0` for an early use) keeps the prologue copy order and the repeated `andi`
  that `s32` plus masks loses; `s32 arg5; u8 mode = arg5;` gives `lbu; ... andi 0xFF`;
  `u16 arg1` instead of `s32` moves the prologue `andi a1, 0x7FFF`. A `u8` local used as
  an index gives `andi 0xff`, an `s16` one a plain `move`. `(s32)f(x) << 11 >> 12` gives
  `sra` where a `u32` prototype gives `srl`.
- Stack argument slots holding dead values: `sh` at 0x10/0x14(sp) before a one-argument
  call are `vx`/`vz` of a local `MgSVec m` used as `f(m.vx * m.vx + m.vz * m.vz)`. A
  second name for one address (`(Spr *)((u8 *)&D_x - 4)`) stops CSE from keeping a
  call-argument address in a saved register.
- A volatile global that one function reads plainly: a second extern at a neighbouring
  address (`extern BtlV14 D_80151842[];`, fields read at +2) gives plain loads while
  decls.h's symbol stays volatile; a cast of the volatile array to a non-volatile struct
  matches the code but adds 16 bytes of frame (battle func_800C0630). A twin from another
  target whose struct has members this target's type lacks takes a local struct declared
  at a symbol 4 bytes below the real one (`FdWinBox D_80083270[]`, field func_800D579C),
  so decls.h's type stays.
- `(D_x & 0xFF)` on an `s8` global gives `lbu`; `(u8)D_x` gives `lb` and an 8-byte frame
  slot. `(s16)a` on a `u16 a` that is also read raw gives `lhu` with `sll/sra` after the
  join. `s32 t = (u16)(t >> 1)` compares with `slti`, `u16 t` with `sltiu`. A `u8` local
  holding a constant 0 becomes a `$LC0` constant-pool load (work.py: unknown relocation
  '.rodata'): use `s32`.
- With `s16 i`, `rot.vx = i * 0x100` gives `sll 16; sra 8` and `i << 8` gives `sll 8`;
  `*frame = p->unk2 << 6` loads with `lhu`, `p->unk2 * 0x40` with `lh`; `*frame = D_x <<
  9` on an `s16` global that is also incremented loads with `lhu`, `t = D_x; *frame = t
  << 9;` with `lh`. With `s16 k`, separate stores `q[4] = k * 0x10; q[5] = k * 0x10;`
  keep `sll 16; sra 12` where the chained assignment gives `srl`; `a << 4` stored into a
  byte gives `sll 4`, `a * 0x10` gives `sll 16; srl 12`.
- A local `s16 id = arg0;` passed to an `s16` parameter avoids a loop-hoisted HImode
  truncation pseudo and its spill slot (field func_800ACC5C). `s16 v` for a quotient
  stored in two arms avoids a v0/v1 swap; a `u8` parameter gives repeated `andi` and a
  `move s2, a0` prologue (battle func_800D01C0).
- Scalar externs at consecutive words can be one array (chocobo's `s32 D_800B745C[3]`).
  Entries whose stride (0x5C) is larger than the struct (0x5A) are indexed with an
  explicit `* 0x5C` on a `u8 *`. A `(sum) * 8 + 0x108` displacement is a struct `{ u8
  pad[0x108]; T m[1]; }` (rec, idx operand order); a temp for `x + 0x38` stops the
  constant folding into the displacement.
- A struct global read once at its start is a scalar extern reached through a cast
  pointer (`w = (CondorWin *)&D_8010BDE0`): a struct-typed extern lets CSE share one `la`
  between the read and the pointer. A pointer global reloaded after every store is
  `extern u8 *volatile` (main text5.c). A short string literal copied into a word-aligned
  struct array element comes out in pieces: `strcpy(D[1].name, "..")` gives `lh; lb; sh;
  sb`.
- `loc = D_x;` into a 4-byte struct local passed as `*(s32 *)&loc` gives `lwl; lwr` then
  `lw` (main func_8003FE98). `*(volatile u16 *)(D_8009AC2B + 0x15)` through the
  neighbouring array gives `la; lhu 0(reg)`, `*(volatile T *)&D_x` the direct `lui; lhu
  %lo`.
- A table that put keeps as `INCLUDE_RODATA` and the C reads must be `extern const`: the
  scheduler then lifts its load above earlier stores (battle func_800A9DA0: `const s8
  D_800A0398` moved the `lb` above the first `sw` and removed a `nop`).
- A run of scalar globals declared as one struct global (`D_80095D88.f0`...) keeps table
  loads in source order where separate scalars get hoisted; three adjacent globals
  written through a cast struct pointer pin a load after them (main func_80034FC8). Splat
  may name a vector's second field as a symbol of its own: `D_801D5358.vx += 0x12C;
  D_801D5358.vy += 0x190;` gives load, load, add, add, store, store, where a separate
  `extern s32 D_801D535C` does not match (nadare func_801B19CC).
- A pointer local to such a constant address instead of the volatile neighbour form folds
  back to `lui; lhu` (main batch 10). In 5-primitive draw functions, `u8` colour constants
  (0xF0/0xC8/0xA0) give `ori` where `s8` gives `addiu -16` (main func_80028030).
- A function that falls off its end must be `s32` to keep the last loop's `bnez; nop`
  (nadare func_801B11C4).
- `(s16)*(u16 *)p - 7` gives `addiu -7` where plain `u16 - 7` gives `li 0xFFF9; addu`
  (battle func_800C223C). `k = 0x4B0; q->f = q->f - k + rand() % N;` keeps the constant
  on the field where `(u16)q->f - 0x4B0` makes a hoisted HImode constant (64336) that
  takes a saved register (thundg2, rakuseki func_801B0D04); `u = i * 0x258 - 0x12C; t =
  ang + u;` keeps `addiu -300` unfolded where `ang + (i * 0x258 - 0x12C)` folds it
  (rocket func_801B11FC).
- `k << 4` on an `s16 k` stored to a byte gives `sll 4`, `k * 0x10` gives `sll 16; srl
  12` (ho_den func_801B0148). An `s8 c = D_x * 6;` colour local stored into several byte
  globals gives the game's load order where `s32 c` does not (osen func_801B02DC); a `u8`
  global read once into an `s32 c` used twice (a halfword store and the 4th argument)
  gives `lbu a3` directly, where `u8 c` adds `t0` and a `move` (thundg2).
- An `s16` parameter used only in `sh` stores keeps its `move s2,a2` out of the prologue;
  `s32` swapped three registers (rakuseki func_801B00AC). A callee defined with one
  parameter that the game calls with two is called through a cast prototype (altema
  func_801B0580).
- A pause-flag test that needs `andi v0,v1,0xFF` matched with `extern volatile u8
  D_80062D98` in that spell's decls.h; CSE then reuses the register as the zero of a
  later `0 < n` loop guard (rocket func_801B0D98).
- A global m2c types `u16` that the code also reads with `lh` is `s16`: `extern s16
  D_x[]; D_x[0] += -D / 2 + p->unk2 % 2 * D;` gives `la a1; lhu 0(a1); sh 0(a1)` and
  reloads `p->unk2` after the store (lasboss func_801B21C8).
- `(u32)(f(x) * 0x19) >> 7` stored into an `s16` gives `srl`: keep the shared `s32`
  prototype and cast at the use (atomic func_801B03AC). `x * 0x200` gives `lh` where `x
  << 9` gives `lhu`; `-p->unk2 * 6` gives `negu` before the multiply, `p->unk2 * -6` does
  not (lasboss2 func_801B04F4, func_801B0A34). `(u32)((u16)p->unk2 - 10) < 0xF` gives
  `lhu; addiu -10; sltiu`.
- `D_x[0] = D_x[1] = D_x[2] = c` with `u8 c` puts the colour in `v1` and the base in
  `v0`; `s32`, `s16` or `s8 c` swap them, and `s8 c` gives `li v1,-128` for 0x80 (club2
  func_801B1468).
- m2c's `return 1` after `D_x = 1;` can be wrong: when the `li v0,1` only serves the
  store, the function is `void` (lasboss2 func_801B1834, lasboss func_801B2A50). `extern
  M2C_UNK D_801B0000; f(&D_801B0000)` gives `lui; addiu a0,a0,0` where `(u8 *)0x801B0000`
  drops the `addiu` (hatena func_801B105C).
- An extra splat symbol right after a struct is its field: `D_801D33FC` written as
  `D_801D33F8.vz` groups load, load, store, store and keeps a following reload after the
  stores (comet).

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
- Cast stores keep later loads after them where struct-field stores let them float above:
  `*(s32 *)(q + 0x14) = v` through a `u8 *q`; all-cast stores to a primitive in the game's
  order (`*(s16 *)((u8 *)p + 0xA) = i;`, not `*(s16 *)&p->y`); cast stores through a
  possibly-NULL slot pointer keep the `lw/nop/sw` alternation. `extern struct { u8 v; }
  D_x;` keeps a byte load after a halfword store where a plain `u8` extern floats above
  it.
- Load/store pairs across fields stay in source order only when the fields belong to one
  struct array under one base symbol; separate per-field arrays let the loads float above
  the stores. A global read twice around stores through a struct pointer is reloaded only
  when read as a struct member (`((MgSVec *)D_x)->vx`).
- Equal-priority independent stores come out in source order. A store of 0 must be written
  after the load it follows in the game, or it is hoisted ahead. In `d.vx = q->f = e` q is
  stored first, and only the last store of a chain is forwarded without a reload; `p->w ==
  0 || p->w > 0xFEFF` reloads after `p->w -= x` where a local copy forwards the stored
  value. `*(u16 *)&D` read before a store to `D` loads the old halfword with `lhu` first.
- An explicit address variable (`fp = &D_x;` before `col = &D_y;`, or `b = &tbl; sp = b +
  n * 5`) puts that address first in the prologue. In `f(D + 0x70 + ((n >> 2) << 2), q)`
  the operand written first decides which one the result's register ties to; `t = (n >> 2)
  * 4 + 0x70; f(t + D, pkt);` as its own statement keeps the result in `a0`; `k = 0x70;`
  before the call, written `((r >> 2) << 2) + k + D`, gives the `addiu 0x70` after the
  global load.
- Chained stores `a = b = c = v` evaluate the outer lvalue's address first and store the
  rightmost first: `rot.vx = rot.vz = 0` stores `vz` first, `*q = D_B9 = D_BA = v` the
  globals first, and `D[i][0] = D[i][1] = D[i][2] = 0` keeps one address register for the
  inner stores with the outer one as `sym+reg`.
- Array elements store like struct members: `extern u8 D[]; D[0] = D[1] = D[2] = c;` keeps
  a later `p->f` load after the stores where three scalar externs let it float above.
  Scratchpad globals as one-field structs (`extern MgWord D_1F800028; D_1F800028.v = v;`)
  keep their stores ahead of struct-field stores. A volatile global read floats above
  struct-member stores but not above cast or array-element stores; `*(s16 *)((u8 *)p + 2)
  = t;` keeps a later byte load after it.
- A zero vector after a computed field: `a.vz = f(...); a.vy = 0; a.vx = 0;` puts the zero
  stores after the `lh`/`li`. A dead first store `q->f = a; q->f = b;` is dropped when
  adjacent; one other store between them keeps it. In a run of read-modify-write
  statements the loads follow source order: permute the statements.
- Frame descriptors addressed below a symbol: `D_x[0] = v; *(s32 *)&D_x[-5] = w;
  f(&D_x[-5]);` gives `sw -0xA(t0)` and `addiu a0, t0, -0xA` where a pointer `(u8 *)frame
  - 0xA` folds to `lui at; sw`; a store at offset 0 of its symbol floats up, one at a
  non-zero offset of an earlier symbol stays.
- Stall-slot fill: a counter `i = 0;` set inside the `if` right after the call and before
  the loop fills the load stall and moves the address setup before the `lh`; set before
  the `if`, the order flips. `f(.., q); q++;` puts the increment before the `jal`.
- Base before index: `b = D_80162978; q = &b[f()]` gives the base `lui/addiu` before the
  `sll`; `r = f(); q = D_x; g(a, b, &((T *)q)[r]);` with `q` also set in other blocks (a
  multi-set pseudo is not sunk) keeps the base in a saved register where inline
  `&D_x[f()]` gives `lui a2` after the call.
- Many stores of pointer constants that force spills: the spilled set and the slots match
  when the stores are in ascending order of the constant. A 32-byte struct copy followed
  by `f(&m, &D_x)` gives `lw`x4/`sw`x4 groups; a K&R `f()` called `f(&m)`, with the base
  left in `a1`, gives the game's 3/3/2 grouping.
- Stores through a global pointer cast to a struct: CSE reloads the pointer after each
  byte store but keeps it across halfword and word stores, and the scheduler moves a run's
  byte store ahead of the group: write each run as the halfword/word group first and the
  byte store last. A one-field struct global (`MgByte`) written after `q->f` stores stays
  after them where plain `s8` externs float above; `*(s16 *)((u8 *)w + 4) = 0;` keeps a
  following `lhu` after it where `w[2] = 0` lets it float up.
- Stores to distinct stack slots reorder freely; a statement that loads before them keeps
  them after that load (write `a.x, a.y, a.z, b.x, b.y, b.z`). A load through a pointer
  written before a store to the same array (`w = ((s32 *)p)[1];`) keeps load-before-store.
  Trying every order of a group of stores (work/battle20/stperm.py,
  work/spells27/perm.py), or swapping two adjacent field stores, often finishes a
  function.
- Chained stores through a struct global: `D_x.vx = D_x.vz = v;` stores `vz` first, three
  separate byte externs `D_94 = D_95 = D_96 = v` store 96 first; with a ternary on the
  right (`D.r = D.g = D.b = c ? A : B;`) the three addresses are built before the branch
  and the stores come after the join. A ternary stored straight to memory emits a store
  per arm: set a local in if/else and store it once, through a one-field struct pointer
  (`MgHalf *f = (MgHalf *)((u8 *)q + 0xA); ... f->v = c;`).
- Frame descriptors below an array symbol: `MgHalf D_x[]; D_x[0].v = ...; *(s32 *)&D_x[-4]
  = ptr; f(&D_x[-4], ...)` gives `sw -8(frame)` in the call's delay slot; as a struct
  global, `T *q = &D_x; q->a = ptr; q->f = ...; f(q, ...)`, where a `u16 *` store
  schedules the argument first. `M2C_SFIELD(frame, u16 *, 0) = v;` schedules a later `lw`
  differently from `*frame = v`.
- `f(..); flag = 1;` puts the flag's `li` in the `jal` delay slot, `flag = 1; f(..)`
  before it; `f(x); x++;` keeps an increment after the call, `f(x++)` or `r = p; p++; f(a,
  r);` puts it before. `if (A && (f = x | y | z, !(B & 4)) && !(f & 0x800))` puts the
  loads of `f` ahead of an earlier test. `*(volatile s32 *)&D_x` as an argument gives
  `lui; addiu; ... lw a3, 0(v0)`; a volatile global read twice with its address kept in a
  register is `volatile u32 *t = &D_x; *t / 3600 ... *t % 3600`.
- The scheduler treats different plain symbols as never aliasing, so a plain global store
  floats above a table load; writing both through one symbol (the table as `((s32 **)((u8
  *)D_x + 6))[i]`, the store as `D_x[0] = v`) keeps the store after the load (quasar
  func_801B05B0). Likewise a scalar array element at an earlier symbol
  (`D_800F5BC8[i][0x19] |= 8`) keeps its load after a store where a struct member at the
  later symbol floats above (battle func_800AA1C8), and naming an address through a
  neighbouring symbol (`D_8015190A[o - 1]` for `D_80151909[o]`) stops two accesses
  sharing an address register.
- What kills a CSE'd global or global pointer: halfword and word struct-member stores
  keep it, byte stores and stores through casts (`*(s16 *)(r + 0x28)`) kill it, so later
  statements re-read it as the game often does. A game that reloads a pointer only after
  byte stores uses a fresh pointer variable per store group. Stores through cast pointers
  reload a stack-slot pointer per field; a one-field struct pointer (`d->a = ev->a; d->b
  = ev->b`) loads it once.
- One-field struct globals (`MgHalf`, `MgByte`) keep a following `p->unk2` reload after
  their store, and in a chain (`*rgb = D_1815.v = D_1816.v = (u8)D_x << 4;`) keep the
  stores ahead of later loads where plain `s8`/`u8` externs let the loads float above
  (kakusan func_801B0580). A chained assignment of a register variable to three plain
  byte globals adds a `move`; three statements avoid it.
- Scratchpad stores as `D_1F800040[n] = ...` (elements of one extern array) keep later
  pointer loads after them; plain externs and `*(s32 *)0x1F8000xx` let the loads float
  above. Two uses of one constant scratchpad address (`*(s32 *)0x1F800004 = f(*(s32
  *)0x1F800004)`) give `li reg, 0x1F800004` and `0(reg)`; a single use stays `lui; lw
  %lo`. A field read into a local before scratchpad stores keeps the load first.
- Two `lhu` of one halfword through a parameter stay two loads above later global stores
  only through a struct pointer (`arg0->v`); through a `u16 *` the second sinks below the
  first store. Reading `t = p->unk2;` once before the packet stores, when the game passes
  it as an argument, avoids a reload after a store through `q`.
- Argument set-up: a 3-argument call leaves the previous call's result in `a3`: write the
  3-argument call rather than passing it as a fourth argument. A ternary argument
  `f(&p->unk4, c ? 0x2000 : 0x3000, 0)` puts `li a1` at the top, if/else puts it in the
  branch delay slot. `scale.vx = scale.vz = expr;` moves the argument set-up above the
  arithmetic, the value through a local puts it after (reito func_801B1968).
  Call-argument sums are reassociated: one single-use temp per case (`D_y + t`) keeps the
  game's order (eqipmenu func_801D4760).
- A global pointer base kept in a local assigned after the call, `r = f(); q = (T *)D_x;
  g(&q[r])`, gives the base `lui` after the call; `&D_x[f()]` loads it at the end. `u =
  p->unk14;` written before an unrelated computation loads early; inline in the
  expression it loads late. `n = (u16)(x - 1); x = n;` as a block's first statement puts
  the `lhu` first.
- Folding: `q->f = q->f - 0x12C + rand() % 600` folds the constant onto the remainder; `u
  = rand(); k = (u16)q->f - 0x12C; q->f = k + u % 600;` keeps it on the field. `((w >> 4)
  & 0x100) >> 4` folds to `srl 8; andi 0x10`; the game's unfolded `srl 4; andi 0x100; srl
  4` comes from `((y & 0x100) >> 4) | x | ((y & 0x200) << 2)` with another term between
  the two uses of `y` (field func_800ACC5C). `(T *)((s32)p + t + 0x124DC)` (integer
  arithmetic) keeps a large offset in a register where `u8 *` arithmetic folds it into
  the displacement; `base = (s32)D_a; prim = D_b + base; prim += 4;` keeps `addu; addiu
  4`.
- `a | b` is evaluated in source order when split (`v = x; v |= y;`); as one expression
  GCC puts the simpler operand first. `!(v > lim - 0x160 && v < lim)` loads the field
  before the global `lim`, `!(lim - 0x160 < v && ...)` the other way round. `D[0][0] |=
  4; D[1][0] |= 4; D[2][0] |= 4;` in source order gives the game's [0], [2], [1] load
  order (battle func_800B30E4). One local reused for consecutive copies (`t = A; d.x = t;
  t = B; d.y = t;`) keeps load/store/load/store.
- CSE follows a `||` jump into its then-part and reuses everything there; a second name
  for the pointer (`(&D_8004AB54)[1]` for `D_8004AB58`) forces the reload. `q = &D_x; ...
  *q` gives a shared `la` register even for a scalar. Volatile reads (`*(volatile u16
  *)&D_x`) stop cross-jumping from merging identical argument set-ups (main
  func_800138EC). `rot.vy = p->unk2 * 0x20;` before `rot.vz = 0; rot.vx = 0;` swaps the
  index and base registers in the prologue.
- `q = &D[i]; q->c = 0; q->b = 0; D[i].a = 0;` gives a hoisted base for the `q` fields
  and `sym(reg)` for the direct access. A ternary on the right of a chained cast store,
  `*(u8 *)(D + g + K1) = *(u8 *)(D + g + K2) = (x & 8) ? 0xB0 : 0x50;`, gives one address
  register per store with the stores after the join.
- A stored halfword is not forwarded to a later load that spells the address differently:
  `D_801D5372 = c;` then `*(s16 *)((u8 *)&D_801D536C + 6) != 0x80` gives the game's `sh`
  then `lh` (nadare func_801B19CC); a store in both arms instead lets cross-jumping move
  it to the join.
- `h = &p->unk2; *h += 1; if (*h >= D_x[4])` keeps the global pointer load after the `sh`
  where `p->unk2++` lets it float up (beat func_801B0778). A store through a one-field
  struct pointer, `fd->p = ptr`, keeps a following global pointer load below it; `*fd =
  ptr` on a `u8 **` lets it float above (saikyo func_801B035C).
- `D_x[a].f--; D_x[a].f &= 0x1F;` keeps `addiu -1` and a reload after the byte store; `-=
  1` forwards the value as `addiu 255` (battle func_800C1908).
- `(*(s16 *)(q + 0x10) << 2) < *(s16 *)(q + 0x12)` schedules the two loads as the game,
  `* 4` does not (battle func_800A3ED0); `if (v > best)` and `if (best < v)` order a load
  and an `sll` differently (nadare func_801B11C4).
- Scale vector stores `sc.vz`, `sc.vy`, `sc.vx` in that order give `0x30, 0x2C, 0x28`
  (beat func_801B01BC). `q->unk10 = 0` written after the `unkE` statement leaves the
  `nop` after the first `mfhi` unfilled (iyashi func_801B0A74).
- `f(D + 0x70 + ((r >> 2) << 2), q)` with the global first keeps `r` in `a0` and the
  `addiu 0x70` before the add; `((r >> 2) << 2) + 0x70 + D` does not (iyashi
  func_801B0624). `tab = base; j = 0; tab += D_x;` with `j * 16 + (s32)tab` gives the
  preheader and `addu` operand order (nadare func_801B1350).
- A pointer local used in one expression (`b = D_8009A074; ... b + 0x10`) puts the
  `+0x10` after the add (`addu; addiu 16`) while other uses of `D_8009A074 + 0x10` stay
  in a hoisted register (main batch 10); `b = D_x;` keeps `(base + idx) + 0x270` unfolded
  only when `b` lives across calls (iyashi func_801B0D64).
- Re-reading `D_8004AB54` after `D_8004AB54 += 1` as the index stops `(n+1)*8` folding
  into `n*8+8` (main batch 10). `id = T[D]; e[8] = D; D++; e[0] = id;` gives `lh`, `move
  v1,a0`, `addiu a1,v1,1` (hiwind func_801B08DC).
- `r = f(); q = (MgTask *)((u8 *)D_80162978 + 4); g(..., (u8 *)q + (r << 5));` gives the
  base `lui; addiu` after the call and `q` in `s1` (nadare func_801B1C54).
- Stores the game places after a call go after it in source, and each zero store after
  the load it follows in the game (rakuseki func_801B02F8, func_801B0A54;
  work/spells27/perm.py found the order of about nine blocks in spells batch 38).
- Byte globals as array elements, `D_x[2] = D_x[1] = D_x[0] = 0`, keep a following
  `p->unk2` reload after them; consecutive word or halfword globals as array elements
  keep the game's load/store alternation (thundg1 func_801B0724, altema func_801B0074;
  not everywhere: `D_800F8380` as an array broke its `lui; lbu`). `*bp = D_09.v = D_0A.v
  = e` with `MgByte` globals keeps the three stores ahead of later loads, and `extern
  struct { s16 v; } D_x` scalars stop pointer loads moving above their stores; a
  neighbour read as `*(s16 *)((u8 *)&D_58 + 2)` does not share the address register of
  `D_x` (ho_den func_801B06C4, heart2 func_801B0F9C).
- Packet stores as `*(s32 *)((u8 *)p + N) = v` keep a later `D_801517C0` load after all
  of them where struct-member stores let it float above; `((u8 *)p)[7] = code;` written
  last gives the `p+7` stepping register (reazer func_801B102C). `q->unk8 = p->unk8;
  q->unkA = 0;` (copy first) gives the early `lhu` (thundg1).
- Scratchpad: `D_1F800000[0..3]` as an `extern s32` array keeps later global loads after
  the stores (seald func_801B0974). A pointer local `s = (MgSVec *)0x1F800000` assigned
  at the top keeps the stores in source order, but only when `s` itself is the call
  argument: with the literal address GCC deletes the stores (grenade func_801B0880,
  func_801B03EC); used for the offset-0 store and the argument it shares `lui a0` (faiga
  func_801B0284). A struct-member store before the call stops the `lui a0,0x1F80`
  argument being hoisted (seald func_801B0D4C).
- More frame descriptors: `D_x[0] = v; f(&D_x[-5], ...)` lets a later argument load float
  above the store, `frame = &D_x; *frame = v;` keeps it after (osen func_801B08F0, tail
  func_801B0894). A pointer stored through a one-field struct, `((HoPtr *)frame)->p =
  ptr`, lets later `lw` argument loads float above it; `*(u8 **)frame = ptr` keeps them
  below (ho_den func_801B06C4). `*p = 0; D_x[2] = ...; m = (MgMat *)(p - 5)` on a
  descriptor pointer gives `addiu s0,a1,-0x14` in a `beqz` delay slot (choco0
  func_801B1F68); `D_x[0] = v; f(&D_x[-4])` with plain externs matches where extern
  pointer variables add saved registers (choco0 func_801B1B40).
- After a base-before-index spawn (`a = D_80162978; p = &a[f()];`), later plain
  `&D_80162978[f()]` reuse the CSE'd base; `p = &b[D_8015169C]` inside `if (D_80062D98 ==
  0) {` puts its loads after the branch (faiga func_801B0D48, func_801B062C).
- A struct view on a `u8` symbol, `((Rec *)(D_x + o))->f` with a local `typedef struct {
  s16 flag; s16 frame; s16 vx; s16 vy; s16 vz; s16 pad[5]; } Rec;`, keeps decls.h's `u8
  D_x[]` for earlier callers, the `lui at; addiu at; addu at,at,o` form, and a later
  `frame` load after the `vz` store where scalar casts let it float above; `((Rec
  *)D_x)[i]` hoists the base into saved registers, and `++((Rec *)(D_x + o))->frame ==
  0x1E` forwards the value without a reload (lasboss2 func_801B0D8C).
- One-field struct and array globals keep their stores ahead of later loads: `D_x[0] =
  D_y.v = expr;` with `D_y` an `MgWord` keeps a following `lh p->unk2` reload after it
  (atomic func_801B09C8); `extern u8 D[]` elements keep their `lbu` after a struct-member
  `sh` where a plain `u8` extern hoists it (h_blow func_801B04DC); `D_x[0] = D_x[1] =
  D_x[2] = c` on a `u8` array with `(u8 *)D_y - 8` for the frame keeps `lhu p->f` after
  the byte stores (spark func_801B0FAC, mizufuki func_801B05E0); a halfword global
  written as `D[0] = v` keeps a final `lhu` after it (club2 func_801B2BD8).
- More frame descriptors: `extern T *D_x[]; D_x[0] = ptr; f(D_x, ..)` gives `sw 0(s0)`
  then `sw 0(a0)` (comet func_801B0608); `extern struct { u8 *src; s32 mode; s16 pad; s16
  val; } D_x;` keeps later `p->unk2` loads below its stores (comet func_801B0850); a byte
  colour descriptor `extern u8 D_x[]; D_x[0] = c; *(s32 *)&D_x[-4] = tbl[...]; f((s32
  *)&D_x[-4], ...)` gives `sw -4(v1)` where `col = &D_x; *(s32 *)(col - 4) = ..` folds to
  `lui at; sw`, and the colour-only twins match with `col = &D_x; *col = c; f((s32 *)(col
  - 4), ..)` (lasboss2 func_801B013C, func_801B0948). `t = &D_x; m = (MgMat *)((u8 *)t -
  0x14); ... *t = 0;` keeps the symbol address in `v0` (lasboss func_801B2A50). Unsolved:
  the game loads `D_801517C0 + 0x70` into `a1` above a pointer store `sw ptr,-0xA(s0)`
  (atomic func_801B0B44, tbreath func_801B071C).
- Scratchpad: stores through `((MgScratch *)0x1F800000)->f` let symbol loads float above
  them where raw `*(s16 *)0x1F8000xx` stores keep a table load below (club2
  func_801B1164); a final store repeated in each arm of an if chain matched where one
  store at the join sank below the argument loads (club2 func_801B1E38, func_801B1C2C).
- `MgMat D_x; D_x.m[0][0] = D_x.m[1][1] = D_x.m[2][2] = v;` keeps the game's order and a
  shared `la a1` (comet func_801B0608); `m.t[0] = m.t[1] = m.t[2] = 0` stores `t[2]`
  first. Zero stores go after the load they follow: `t = p->unk8; q->unk1A = 0; q->unk8 =
  t;` (triangle func_801B0BDC), `rot.vx = ..; rot.vy = ..; rot.vz = 0;` (hyper
  func_801B179C, club2 func_801B1A54), `rot.vy = ..; rot.vx = rot.vz = 0;` (triangle
  func_801B091C).
- `p->unk16 = D;` before `p->unk2++; if (p->unk2 == N)` forwards the incremented value
  instead of reloading it (atomic). Products written inline keep the game's
  `lhu`/`lhu`/`mult` order where a temp loads the shared field first (lasboss2
  func_801B0824). Packet constants are materialised in the order of their first store in
  source (spark func_801B0700).

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
- A `u8` copy defeats CSE: `g = f; if (c) g = f + 1;` with `s32 g` becomes `g += 1` in f's
  register; `u8 g` keeps `move a1,a0` / `addiu a1,a0,1`. The same value written `h * 2` or
  `h << 1`, `-t << 7` or `-t * 0x80`, changes temp creation order and can swap saved
  registers: try arithmetic equivalents early.
- Only element 0 of an array or struct global gets a shared `la` for repeated accesses
  (offsets 2 and 4 get their own `lui`); a struct global used for related offsets
  (`&D_A.m`, `&D_A`) keeps its address in a saved register, two symbols for the parts
  avoid it. `*(u16 *)&G |= c` and pointer locals keep the address in a register: the first
  access through it, later ones folded to `lui at`.
- A scratchpad pointer assigned at the top lands in `s0` with its `lui` after the last
  call; assigned right before use it takes a temporary. `mp = &m;` just before the first
  call that uses it, inside a loop body, puts `&m` in a saved register hoisted before the
  loop.
- A constant kept in a register (`ori t0, 0x4D; addu v0, t0, v0`): `kx = 0x4D;` before the
  loop and `kx + v` with the constant first; `v + 0x4D` gives `addiu`.
- `% 16` contains a branch, so a `rand() & 0xFFF` temp around it is function-wide and
  takes a register after `p`; with `% 6` it is block-local and gets `s1` before `p`.
- Loop-invariant values in `s16` locals give the game's `move` copies before the loop
  (`s32` copies do not); an explicit `s32 k = i;` copy of an `s16` counter takes the lower
  saved register.
- Spawn blocks: `id = arg0;` inside `if (arg1 != 0)` puts `move t2, a0` in the `beqz`
  delay slot, a second block gets its own `id2 = arg0;`; blocks of different kinds need
  their own `i`, `n`, `p`, `s`, blocks of one kind can share them.
- Variables set in several places are allocated after the block-locals: one variable
  reused for two values (`m = ...; p = ... m ...; m = ...;`), or a two-step `v = x; v = v
  | y;` in one case, moves registers for a whole switch. One `s16` counter reused for two
  loops, and inner-loop temporaries reused after the loop, give the game's s-register
  order where separate variables swap them.
- Wrapping a few statements, or a whole run, in `do { } while (0);` changes the weight of
  the pseudos inside and can flip the allocation order (work/battle19/wraprange.py tries
  every contiguous range). The `;; N regs to allocate:` line of a `-dg` dump gives the
  global allocation order directly.
- Shared address registers: a plain scalar global read is a direct `lui/lw`; struct
  members and cast dereferences go through an address register that CSE shares across
  calls (`*(u32 *)&G` gives `lw a0, 0(s0)` after each call; `((T *)&D[i].f)->vx` gives `la
  sym+16; addu; lhu 0(v)` where `D[i].f` gives `lui at; addu; lhu sym+16(at)`). An earlier
  store to `D_x+2` makes later offset-0 accesses `reg-2` and breaks the sharing: declare
  that field as its own extern. `base = (u8 *)D_x; q = base + 0x1F62; p = base + id *
  0x34;` shares one base register.
- `p++` written as its own statement raises the pointer's reference count and can flip
  `s0`/`s1`; two frame-address variables instead of one reused pointer change the temp
  registers.
- Parameters used in place (`arg1 += 8`, `arg2 = arg2 % 0x1000; if (arg2 < 0) arg2 +=
  0x1000;`) instead of copies keep their saved registers and the prologue copy order; `s16
  mode = arg0;` at the top gives an extra `move` copy of a parameter. One variable reused
  for two values (`v = f(v); if (c) v = 0; r = g(v);`, or one `h` for a clamp and a later
  `x % N`) shares one register; `p->e -= p->e / 4; p->f += p->e;` written directly kept
  the registers an `s16` temporary swapped.
- A clamp written as one nested ternary with no user locals (`p->w = p->w < 0 ? 0 : (D <
  p->w ? D : p->w);`) kept registers that if/else with locals swapped; elsewhere separate
  locals per block matched. Two typed source pointers for adjacent loops matched where one
  shared `u8 *src` flipped registers. Goto loops lower the loop weight and can flip which
  variable gets the lower saved register.
- HImode narrowing: `lh v0; move v1, v0; slti v0, v0, K` is the then-arm of `if (x >= K) {
  c = C - f; c <<= 4; } else c = K2;` with `s16 c` (`(C - f) * 0x10` has no copy); storing
  `k << 4` from an `s16 k` into a byte gives `sll v0, s0, 4`, `k * 0x10` gives `sll 16;
  srl 12`. `f((u16)(i | 0xC600))` loads `li -14848`, `j = i | 0xC600; f(j);` gives `ori`.
- `.lreg` dumps' "used N times across L insns" give each pseudo's priority,
  `floor_log2(N) * N / L`; it explains saved registers rotating between a few long-lived
  variables (field func_800A8F88). Spill slots follow pseudo-number order: parameters
  first, then locals in declaration order (swapping two declarations swapped 0x28 and
  0x30); one variable reused for a computed value can keep it in a saved register where a
  fresh one spills.
- Reusing a variable raises its priority: a loop counter reused for a later value, an
  outer variable reused as a second loop's counter, or one local for a value set before a
  call and then a loop counter put them in the game's saved registers (eqipmenu
  func_801D3490, main func_80019978, battle func_800B4E30). The other way, a separate
  counter for case loops (condor), one variable per loop (`j1` ... `j4`) so a parameter
  keeps its argument register (field), or one `q` for the first spawn blocks and an `r`
  for the rest (reito func_801B1D74) lower a shared variable's priority. A dead `i = 0;`
  in an earlier block can change which register a shared loop counter takes.
- Near-identical blocks each with their own block-scope locals get the same registers;
  shared function-level locals change the priorities. Clamp blocks comparing a
  sign-extended `lh` and then using it in halfword arithmetic in both arms need a
  separate `s16` local per block (a shared one adds an `lhu`); store inside each arm.
- `do { stmts } while (0);` around the first statements of a loop body, or `for` instead
  of `do/while`, flips allocation order (hmoon func_801B0B00, pink func_801B0C94);
  work/battle19/wraprange.py and work/spells26/wrap.py try every range. In a `do/while`,
  `q->f = rand(); i++;` keeps the `i + 1` temp out of a saved register.
- Copies of old values written before the display calls (`oa = a;`) go to saved registers
  in declaration order. `rp = &rot;` as the first statement gives the `addiu s6, sp,
  0x60` at the top, `vp = &v;` just before its first use a later register. `m = &D_x; q =
  (u8 *)m + 1;` gives a pair of saved registers for a struct and its byte view.
- A join statement `s = arg0 & 0xFF` written once after an if/else gives the delay-slot
  copy; per-arm assignments are CSE'd into a `move`. `a = 8; if (k >= C) a = X - k;` lets
  CSE share a base `lui` across the whole function (one more saved register, 8 more frame
  bytes); if/else or a ternary reloads it after the call. Packet links through a bitfield
  tag (`pk->tag.addr = ot->addr; ot->addr = (u32)pk;`) put `0xFF000000` in the game's
  register where the mask form swaps them.
- Block-scope locals become local pseudos and get `v0..a3`; function-level temporaries
  compete with the arguments (main batch 10). A temp shared by several statements takes a
  saved register across calls; one single-use temp per statement keeps it in `v0` (saikyo
  func_801B0A68).
- A permuter run found a parameter copy `u32 addr = arg1;` between two table loads that
  fixed the parameter-copy order and the saved register (main func_80037050).
- A spawn pointer used in two blocks (a loop and a later `if`) is allocated high; one
  variable per block put the loop's in `s0` (iyashi func_801B0A74), while hiwind
  func_801B05B4 matched with one shared `q`.
- User locals assigned in the game's order before a loop (`code = 0x6A; head =
  0x02000000; layer = 0x40;`) give the hoisted-constant registers; a user variable gets a
  lower pseudo than an expression temp, so it takes the higher register on ties (fubuki
  func_801B032C). `one = 1; p = &D_x;` as locals before a loop put the constant in `t2`
  and the address in `t1`; without the local the address is not hoisted (battle
  func_800A9DA0).
- `tab = base + D_x; tab += 4;` in two statements gives `tab` more references so it
  outranks `idx` (nadare func_801B11C4). A variable of its own for a middle loop's value
  stops it taking `s0` (battle func_800A3ED0); reusing a loop counter for a call result
  moves it from `a3` to `t2` (battle func_800CD860).
- `D_x++ / 32 % 3` inline in a call argument keeps the post-increment temp as the
  dividend, adjusted in place (`move a1,v0; addiu a1,a1,31`); a named `t = D_x++` does
  not (battle func_800A3ED0).
- One variable per role (not one `v`/`t`/`n` reused across blocks) keeps live ranges
  apart: it fixed three registers in battle func_800AF9C8, and one variable per clamp arm
  matched altema func_801B0850. Not always: one loop counter shared by three loops (with
  its own inner `j`) matched thundg2 func_801B0908, and one multi-set `q` for three
  divisions in different blocks ties the `subu` result to the sign register and stops
  tail merging (fullcare func_801B0AB4). Try both.
- `k -= 1;` in place inside an if / else-if chain on `k` keeps the game's `v0`/`v1` and
  the delay-slot `li` where a temp `k - 1` swaps them (thundg1 func_801B002C, choco0
  func_801B14A8). `((MgScratch *)0x1F800000)->unkA = c = 0x80;` keeps the constant in
  `a0` for a later `c - ...` where a separate `c = 0x80;` does not (altema
  func_801B01E0). A named mask `mk = 0x400040; if (v & mk)` puts the `lui` early in a
  delay slot (battle func_800AF9C8).
- `if (1 << i & D) { n++; if (n == 1) ... }` with a literal 1 shares one register for `1
  << i` and `n == 1` and hoists the global load (faiga func_801B0D48).
- Two `i == 0 ? A : B` ternaries on an `s16 i` in one loop are merged by CSE across a
  call into a sign-extension in an extra saved register (frame 0x70 instead of 0x68);
  storing each ternary straight to memory, `q->f = i == 0 ? A : B;`, gives `sll v0,s2,16;
  bnez` per test (rakuseki func_801B07E4, func_801B0A54).
- `u16 *g = &D_x; *g += a * b;` gives `lui; addiu a0; lhu 0(a0); sh 0(a0)` (rakuseki
  func_801B0C58); `u = *g; r = p->unk2 % 2; u -= 8; u += r * 0x10; *g = u;` with an `s32
  u` gives `lhu; addiu -8` where one expression gives `li 0xFFF8; addu` (rocket
  func_801B0D98).
- `n = p->unk14; p->unk14++; D[f()][0] = n;` avoids an HImode copy of `n` before the call
  and its spill slot; `p->unk14 = n + 1` keeps both (reazer func_801B17F8). `k = amp >>
  1; k *= k;` gives `sra s2,s4,1; mult s2,s2` where `(amp >> 1) * (amp >> 1)` uses `v0`.
- `D[i][0] += x` on a `u16 D[][0x5CE]` recomputes `lui/addiu/addu` per use as the game
  does; `*(u16 *)D[i] += x` shares one address (heart2 func_801B1518). `pa = &ta[i];
  pa->vx` gives `addu base,idx` and `ta[i].vx` with a hoisted `ta` gives `addu idx,base`
  (rocket func_801B0D98); `i * 4 + (s32)pk` gives `(off, base)` and `&pk[i]` the reverse
  (battle func_800C223C).
- A pointer variable for a second frame descriptor (`frame2 = &D_x; ... (u8 *)frame2 -
  8`) with `i++` after the call put `i` in `s0` and the pointer in `s2` (napalm
  func_801B07D4). Reload hands out registers round-robin: a spilled loop limit reloads
  into `a2`, then `a3` (seald func_801B0074).
- More on one variable per role: one `k` for two multiplier groups put the multiplier in
  `a1` as the game (spark func_801B0700); one `r1`...`r7` per `rand()` and one `k` per
  field avoid `move a1,v0` copies (triangle func_801B0DC4); a separate `r` for `rand()`
  next to a function-wide `t` avoided a saved register (mizufuki func_801B0E40).
- Store of a call result after later work: `r = f(..); k = field / 65; D_x = r; g(k, k,
  k);` keeps `v0` live through the divide and the temporaries in `a1`/`v1` (lasboss2
  func_801B06DC); `q = (x << 12) / 10; D_x = q;` gives `subu v1,v0,v1` where `D_x = (x <<
  12) / 10;` gives `v0` (h_blow func_801B01E0). `p->f + (rand() % N - K)` keeps `-K` on
  the remainder (cometeo func_801B0C4C).
- `a = D_x;` read once and used as the index of two byte stores keeps the index register;
  reading the global each time reloads it after the `sb` (h_blow func_801B078C). `ab =
  D_80151A24;` inside the first block plus `pb = ab + 0x28;` keeps `addiu s0,s6,0x28`
  unfolded where an inline cast symbol folds the constant into the `lwl` displacement
  (h_blow func_801B0BAC).
- `if (p->unk2 < 0xC) D = p->unk2; else D = (p->unk2 - 0xC) % 4 + 0xC;` with no local
  gives `lh a0; move v1,a0`; locals swapped `a0`/`v1` or added 8 bytes of frame (club2
  func_801B1468). With `s16 n = p->unkE;`, `p->unk6 += p->unkE;` and `+= n` give opposite
  `addu` operand orders (atomic func_801B0B44).
- A constant-address pointer keeps `2($s)` offsets only after a loop or label, where CSE
  loses the constant equivalence; in straight-line code `t->vy` folds to `lui; lh sym+2`
  (spark func_801B0A38, unsolved).

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
- `if (t == 0) {A} if (t == 0) {B}` loses the second `bnez` to CSE; `z = t == 0; if (z)
  {B}` keeps it. `i = 0; if (i < n)` keeps a guard a repeated `if (n > 0)` loses to jump
  threading. `if (A || B)` followed by a second test of the same field keeps the first
  branch threaded to the else part.
- An else-if chain cross-jumps a shared tail (`sra`); the ternary form keeps `j L; sra`
  with the shift in the delay slot. `k = 0xBC; ... p->f = k;` gets the `li` into a branch
  delay slot; a dead `id2 = arg0 & 0xFF;` in an else-if arm survives when `id2` is
  assigned again at the join, and fills a delay slot as in the game.
- `if (F & a) {...} else if (F & b) {...} else v = 0;` lets the flag's temp and `v` share
  a register where `v = 0; if (F & b)` does not. `switch (t) { case 0: x = 1; case 2:
  break; default: goto skip; }` reproduces a three-way test that if/else inverts. `m = 8;
  ... k < m ...; m = r; if (m != 0)` gives `move v0, a0` before the branch.
- An inlined callee's body: each `return` as `r = N; goto done;`, then test `r`. A search
  loop with no final `move v0, zero` has no `return 0`: the `slti` result left in `v0` is
  returned; an exit path reusing `v0`: `r = (void *)(i < 0x960); goto loop;` with `r = p;
  goto done;` in the hit branch.
- No form found yet: two constants `if (c) x = A; else x = B;` that the game branches over
  always became `sltu/subu/andi` (condor func_800A427C).
- A merged store tail: write the run of stores in each arm; cross-jumping keeps the merged
  copy at the textually last arm (the join, `j REST`, then the out-of-line exit). Two arms
  that each copy global to global (loads in both, stores after the join) are such
  cross-jumped copies.
- A linear compare chain (0x19, 0x1A, 0x1E, 0x1F) needs if/goto; a switch gives a balanced
  tree, and its case order sets the tree (`case 1: case 2: ... case 0: case 3:` versus 0,
  3, 1, 2). A store in the default arm then `return`, with the same store after the
  switch, matches where if-chains do not. An early `if (c) return 1;` chain, then a
  switch, then a final `return 0` puts the `return 1` block first.
- `if (id == 0 && (fl & 2)) A; if (id != 0) B;` is threaded straight into B. `if (t < 10)
  k = 0; else if (t >= 0x13) k = 9; else k = t - 10;` keeps copies of `t` a nested if
  loses. `d = d < 0 ? -d : d;` gives `bgez; nop; negu` where the if form hoists the next
  load above the branch. `(r & 0xFF)` on a single-set or bounded `r` is dropped by
  combine; a second, unbounded set keeps the `andi`.
- `while (1) { if (p[0] == END) { p++; break; } ... }` gives a `bne/j` exit with `p++` in
  the delay slot; `p += 3` once after an if/else join gives one shared back-edge (in both
  arms: two increments and no reduced pointer). `if (!(x & 0x80)) f(p, 0); else f(p, 1);`
  keeps the branches a 0/1 ternary folds into `srl`.
- Switch case order sets the block order (`case 1, 2, 3, 4, 0xB..0xF, 7, 5, 6, default`);
  `case 0xF: base += 0x100; case 0xD:` as a fallthrough chain gives the game's compare
  tree; cases 4, 8, 9, 0xB, 0xC become a jump table, so a `== 4 / (u32)(x - 8) < 2 /
  (u32)(x - 0xB) < 2` chain comes from `||` tests. An explicit `default` plus one shared
  `return 0` after the switch gives the delay-slot `move v0, zero`.
- A function declared `void` whose code leaves a value in v0 for its callers returns
  `s32`: `move v0, zero` before the epilogue is `return 0;` (main func_80024A3C), a tail
  call whose result callers use is `return f(...)` (battle func_800B0B94), and a switch
  whose range check leaves a `nop` in its delay slot falls off its end; callers passing
  arguments then need `s32 f()` with an empty list, as `(void)` breaks the file (battle
  func_800DDFEC).
- Branches GCC turns into arithmetic: if/else or goto forms assigning `0xFF` or `0`
  become `sltiu/negu(/andi)`, and only an inlined helper `return 0xFF; ... return 0;`
  keeps the branches (condor func_800A3304). `if (A || B) { if (C) { f = 1; goto done; }
  } f = 0; done:` keeps the branches with the zero in a delay slot. `u = (w & 0x3F) != 2
  ? arg3 : 0;` or `ct = arg3 & -((e & 0x3F) != 2);` as its own statement gives `xori;
  sltu; negu; and`; inside a larger expression it becomes a branch, and a ternary creates
  the constant 2 early, shared with a later compare. A two-constant diamond `if (c1 &&
  c2) { v = ...; a = 0; if (v == 0) goto L; } else { L: a = N; }` keeps `bnez; addu a, 0`
  / `j; ori a, N`.
- Max of two bytes: `a = src[0]; if (a < src[1]) a = src[1]; b = a >> 1;` with `s16 a, b`
  gives `slt`, a reload in the arm and `srl`; `s32 a` gives a `move` and `sra`, `u8 a`
  gives `sltu` with `andi`. One multi-set variable (`n = f & 0x8000; f &= 0x7FFF;`) gives
  `beqz` then `blez`, a single-set one `beqz` in both.
- Switch layouts: an empty `case 4: break;` above cases 1 and 3 gives the `beq 3; slti 4;
  beqz end; bne 1` tree; a dispatch testing 2, then 0, then 1 is `if (m != 2) switch (m)
  { case 0: ... case 1: ... }`; in a jump-table switch, `case 0:` joined to `default:`
  gives `sltiu 8` with no `-1` bias (main func_80039034). A switch's last case gets its
  shared join duplicated into each arm; a `goto` to a shared else avoids it.
- Cross-jumping and threading: the same store run written in every arm of an if / else-if
  chain tested with `(t -= 2) < N` gives the tail-merged layout with the stores right
  after the second test (dejon func_801B0238); `if (x < N) { A } if (x >= N) { B }` with
  calls in A gives the jump into B and the re-test after A. An inlined helper is a
  scheduling barrier that `do { } while (0)`, a block or a statement expression do not
  replace (reito func_801B1158).
- A variable divisor (`d = 100000; x / d`) gives `divu` with `bnez; break 7`, a literal
  divisor the multiply sequence. A constant hoisted out of a loop (`li a3, 1`) lands in
  the stall slot before a `div` macro.
- An if / else-if chain with a call in each arm gives one shared `jal`; a `goto` into a
  shared call (m2c's shape) does not. An `s16` parameter with an `s32` counter gets an `i
  << 16` giv (battle func_800A38FC).
- The same comparison with a global load written in both arms of an if/else, each with
  its own `return -1`, cross-jumps only the `slt; bnez; li v0,-1` tail; computing the
  limit into one variable gives one load after the join (main batch 10).
- A switch over a `u16` global with `case 1: goto ret0` shares the early `return 0` block
  and ends the CSE path before the next case, so a constant `1` is not kept across calls
  in `s3` (main batch 10).
- `if (f >= 12) k = 0x14 - f; else k = 8;` gives `bnez; ori sN, K` with the else constant
  in the delay slot; `k = 8;` before the `if` is hoisted instead (hiwind func_801B0730).
  `p->unk2 ^= 1` written after `if (D_x < 2)` lands in the `jr` delay slot (iyashi
  func_801B0D04).
- `t = p->unk2; if ((u16)(t - 0x1E) < 0x12U) { k = p->unk2 - 0x1E; ... }` keeps `k`'s
  subtraction as its own `addiu` in the call's delay slot (nadare func_801B15C8).
- `(f & 4) && (f & 8)` folds into `(f & 0xC) == 0xC`; a temp `t4 = f & 4` for the first
  test only, with the later `(f & 4) == 0` inline, keeps two tests and the delay-slot
  `andi` (battle func_800AF9C8).
- Shared store blocks: `if (t < 0xD) { k = 0xD; k -= t; goto store; } if (t >= 0x16) { k
  = t - 0x16; store: ... }` (faiga func_801B0284; `k = 0xD - t` put the second test in
  the first branch's delay slot); with a fail arm, `if (t < 2) { c = t << 6; goto store;
  } if ((t -= 2) < 0x1E) { c = 0x80; store: ... } else { p->unk0 = -1; return; }` (heart2
  func_801B11C4), or the fail block first and the label after the if/else (fullcare
  func_801B0AB4). A `copy: c = k;` label after the if/else, not inside the third arm,
  keeps two copies (at the join and in the second arm's delay slot) instead of a
  cross-jump (heart2 func_801B0F9C).
- `i = 0;` written once after an if/else join lands the `move` in one arm's `j` delay
  slot and at the end of the other; set inside each arm it floats up (reazer
  func_801B102C).
- Identical case bodies are cross-jumped; three identical cases stayed apart only when
  followed by an outer case with an inner switch of two or more cases (battle
  func_800C679C, not the whole rule).
- `p->f += 0x50;` in one arm and `-= 0x28` in the other gives `lhu; addiu` and one shared
  `sh`; a temp stored once gives `v1` (lasboss func_801B1620). Complementary tests as two
  ifs, `if (p->unk2 < 8) {...} if (p->unk2 >= 8) {...}`, give a reload of `unk2` after
  the `sh` (lasboss2 func_801B04F4).
- A call argument with an inline ternary, `f(&p->unk4, k2 + (p->unk16 == 0 ? 0x1000 :
  0x2000), ...)`, puts `addiu a0,s0,4` early; a local set in an if/else keeps it late
  (atomic func_801B0548). `D[0] = D[1] = D[2] = c ? A : B;` on an `s32` array builds the
  address registers before the branch and stores after the join (atomic func_801B0E88).
- Reorg fills a `bne` slot with the nearest independent instruction above it: `c = 0x60;
  if (x == 4) c = 0x40;` got `ori a1,0x60` into the slot only with the following pointer
  setup written after the `if` (triangle func_801B008C); `i = 0;` written after a `% 4`
  store (a new basic block) is pulled into the `bgez` slot (triangle func_801B0DC4).

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
- Don't declare a strength-reduced pointer: the loop optimiser bases it on the textually
  last access through `p` (`p->code` last gives `s0 = p + 7`), so reorder the parts of the
  body to move the base; write `a->unkC`, not a second pointer `b = a + 0xC`. `p++; i++`
  versus `i++; p++` in the tail decides which copies land in delay slots; array bases
  hoisted into locals before the loop (`a = D_x; ... &a[i]`) give hoisted `la` registers
  and (base, idx) order.
- loop.c hoists constants out of `for`/`while`/`do` loops; in a goto loop they stay inside
  and the delay slot is filled from above. Goto loops for both an inner and an outer loop
  keep a function table's `la` from being hoisted and spilled around a call.
- A loop-invariant load of a global pointer is hoisted only if the loop's stores are
  struct-member accesses (scalar `*(s16 *)` casts block it); `-dL` reports "not desirable"
  for a life-1 invariant when the loop has more than about 46 insns.
- Strength reduction: a named giv temp `w = i*12 + 16; p->x1 = arg2 + w;` after the
  statement creating the first giv keeps the game's stepping registers, where inline `arg2
  + (i*8 + 8)` is reassociated into `(arg2+8) + i*8`; the order givs are created decides
  which increment comes first. `for (...; i++, e++)` keeps `e` a biv. `arg0 + i * 0x34 +
  0x20` avoids the giv rebasing `arg0 += 0x34` causes. A struct array with fields at 0, 2,
  4 gives three stepping pointers (`addiu a2, a0, -2; addiu a1, a0, -4`), and scans over
  8-byte entries index `((T *)list)[i].f7` with no biased pointer.
- A `for` loop around an if copies `i + 1` into the branch delay slot; do/while with `i++`
  at the end does not. A loop-invariant row term as a local (`row = a->f; D[row][n].g`)
  keeps a byte-offset induction variable. A constant divisor assigned before a loop (`nx =
  0x1F40;`) gives a real `div` with it in a saved register.
- 2.7.2 `-funroll-loops` (chocobo) gives up ("Loop too big") when twice the body exceeds
  100 insns, and unrolls modulo-style when the bounds are not constant; goto loops are
  never unrolled, hoisted or strength-reduced.
- Strength reduction uses a knife-edge size test (`-dL`: `giv ... not worth while, 56 vs
  57`): one extra insn in the loop (`(u8)u` for `u & 0xFF`) loses a stepping pointer, and
  a pointer variable shared by two loops makes its giv not worth it: one pointer per loop.
  `e = e0 + i * 8` with `e0 = tab` read before the loop gives an unbiased stepping
  register where `e += 8` or `e[5]` reads get rebased.
- Base registers: `tab = D_x;` before the outer loop with `tab[i]` inside, or `v =
  &D_tbl[i]; v->vx = ...`, hoist the base and give the (idx, base) order (`D_tbl[i].vx`
  rematerialises it); base pointers assigned inside each of two loops and used as
  `&base[i]` give hoisted bases. `D[a].f[i]` and a pointer `w = D[a].g; w[0x12 + i]` give
  two stepping registers. Strided clears over interleaved globals: `D_x[off] = 0` with
  `off += 0x18`; a flag array as fields of a struct array (`D_x[i].pad3[2]`) gives the
  `lui/addiu/addu at, s0` form where `D_x[i * 0x18]` becomes an address giv.
- Loop invariants are hoisted in statement order (`fp = &v[1]; a = ...; b = a + 8;` before
  the loop); hoisted constants come out in stream order with a `col = 0` at the loop top
  ahead of them, and a variable set inside a conditional block is never hoisted. `for (i =
  0, n = 6; i < n; i++)` puts `i`'s init before the bound; `do {} while` lets a constant
  be hoisted into a saved register, a goto loop keeps it inline.
- loop.c moves an invariant only when `threshold * savings * lifetime >= insns in the
  loop` (`-dL`: "savings N moved" or "not desirable"), with a threshold between 10 and
  20, about half in a loop with a call. So a loop's size decides what is hoisted: a jump
  table's single-use `la` only while the loop is under about 104 insns (battle
  func_800B5138, where assigning the base pointer inside the body made it the hoisted
  movable), eight uses of 1 up to 730 insns and not from 746 (field func_800ACC5C, padded
  to the game's size with neutral `x << 4 >> 4` pairs that combine folds away, with a
  comment in the source).
- What blocks or allows hoisting: a call inside the body blocks hoisting of its memory
  loads (constants still move) and pointer stepping on the index, and the exit paths then
  need `i++; continue;` copies; adjacent `s16` globals declared as one struct keep their
  loads in the loop where scalar globals are hoisted; stores through a local `s16 m[36]`
  let a plain global load be hoisted, stores through an `s16 *p` do not; `M2C_SFIELD(D_x,
  ...)` lets the loop hoist a global pointer where `M2C_FIELD` reloads it. `while (1)`
  with `break`/`continue` hoists small constants and products (`id * 0x84`) into
  registers; `goto` loops recompute them per block.
- Guards: `i = N; if (i < n) { init; do { ...; i++; } while (i < n); }` puts hoisted
  constants and giv start values after the guard branch; guarding through one pointer and
  looping through a copy gives the `move t0, v1` after the guard. `i = 0; if (D_x > 0) {
  n = D_x; do ... while (i < n); }` gives `blez v0` plus `move a1, v0`. A guard `ori v0,
  1; beqz v0, exit` comes from `p < D_x + 0x800` with `p` starting at the same symbol
  (main func_8003FE98).
- Pointers and givs: pointer accesses in a loop (`p->f24`, `p++`) combine into one
  reduced pointer based at the last access ("giv ... combined"); `volatile T *p` keeps
  the original biv, and explicit `o += 0x34` offsets next to `sym + o` stay unreduced. A
  base-pointer local (`e = D_x; e[i].f`) keeps one stepping pointer with field
  displacements and flips the `addu` order, `D_x[i].f` gives one pointer per field; `off
  = i * 0xB9C;` at the body's top gives one stepping register shared by several
  symbol-plus-offset accesses (dejon func_801B0818); when `q = &D[i]` is not reduced,
  `D[i]` at each use gives the stepping pointer. Reading `p[1]` and `p[2]` creates a
  `p+4` register based on the last-created giv: write them in the game's order. A local
  `n = D_x << 5` with byte offsets `*(s16 *)((u8 *)D_y + n + k)` shares one index
  register. `D[i].name[0]` through a struct array keeps the byte read unfused (`lui;
  addiu; addu; lbu`) where a flat `u8[]` fuses it.
- Hoisted bases: `la T; move s, T` before a loop appears when an element-0 access of the
  same symbol comes earlier in the block; a user pointer `tp = &D_x[0]` used as `*tp` in
  the loop fixes their order, and a shared `la s0` after calls comes from a
  pointer-to-pointer (`tp = &D_x; (*tp)[i]`). `*(volatile u16 *)&D_x` gives a hoisted
  address plus an `andi 0xFFFF`; a plain `u16 *p = &D_x` assigned inside the loop's
  conditional block hoists only the address. `D_x[n++] = id;` under a condition gives the
  hoisted output pointer after the hoisted constants, `*q++ = id; n++;` sets it up
  earlier.
- Loop shapes: `for (i = 0; i < n; i++, out += K)` emits `i++` first among the
  increments, the same increments in the body last. `do { ... } while (++j < 2)` with
  `s16 j` gives pre-increment tests. The length itself as the copy counter (`if (n != 0)
  { e = n; do { copy; e--; } while (e != 0); }`) fixed an inflate copy loop; an outer
  `while (1)` around `for (n = 7; n != -1; n--)` keeps -1 out of a saved register. An
  up-counting loop with hoisted invariants and an apparently empty body is `for (; i <
  10; i++) { if (mask << i & D_x) { q = &D_y[i]; } }` with `q` used later; an empty `if`
  body is deleted early and gives a reversed `bgez` loop (faiga2 func_801B162C).
- Unrolling (-funroll-loops): a 3-iteration loop over an ARRAY_REF is modulo-unrolled,
  indexed through a pointer (`((s32 *)D_x)[k]`) it is unrolled completely (chocobo
  func_800AB410). Unrolled 3x5 output loops need two-term indices (`i * 8 + n * 0x18`)
  for the game's stepping registers.
- `for (i = 0; i < 10; i++) { if (...) }` matched where the same loop as `do { ...; i++;
  } while (i < 10)` let reorg rewrite `sll v1,a0,1` after `move a0,s0` into `sll v1,s0,1`
  (nadare func_801B1C54; seen with `-fno-delayed-branch` and the `.dbr` dump).
- `q = D_8009D84C[i]; p = (u8 *)&D_800F83E0[i];` bases each pointer giv at field 0 as the
  game; hand-advanced `p += 0x68` is rebased to the last field (battle func_800A3ED0).
  `off += 0xB9C` with `*(s16 *)((u8 *)D_x + off)` shares one stepping register across
  three arrays; `*(s16 *)&D_x[i]` gets a pointer giv of its own (battle func_800CD860).
- `i = 0;` then `for (; i < 3; i++)` gives the game's prologue order (battle
  func_800A9DA0). Word scratchpad values read into locals before struct-member stores
  hoist above the byte stores (battle func_800CD860).
- Strength reduction: `D_x[i * 0x74] = 3` becomes a pointer giv; `n = i * 0x74; D_x[n] =
  3;` in the then-arm keeps `addu at,at,s1` (grenade func_801B0C64). `D_x[off]` with `off
  = i * 0x44` gives `lui at; addu at,at,a1` with a stepping integer (battle
  func_800AF9C8), and `off = i * 0xB9C;` at the top of the body with `(u8 *)D + off`
  gives unfused `sym+reg` loads and `addiu s2,s2,0xB9C` (heart2 func_801B17A0). An
  `M2C_SFIELD` store in the loop lets loop.c hoist the global pointer as `move a2,a1`.
- Loop base pointers (`ta`, `tb`, `td`) set before `n = ...` hoist their `lui/addiu`
  above the guard and let the `&D_x` register be reused as the counter (rocket
  func_801B0D98). Padding a loop body with dead arithmetic that flow deletes later stops
  a small invariant (`addiu v0,sp,0x28`) being hoisted (battle func_800C223C), as in
  field func_800ACC5C.
- A `for` loop put `addiu v0,s3,1` in the branch delay slot where `do { } while` left a
  `nop` (tail func_801B0FA4).
- `j = i * 8; off = i * 0xB9C;` at the top of a loop body gives the offset-register givs
  in the game's init and increment order (spark func_801B2014). Loop base pointers
  assigned in the order `ba, bb, bd` before the loop give t6/t5/t4, whatever the
  declaration order (hyper func_801B1AC0). Unsolved: h_blow func_801B0640 keeps an
  unfolded loop guard `ori s2,zero,0x200; slti; bnez` that GCC folds in every loop form.

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
- `s16`/`u8` locals live across calls each take a slot; `u8 pad[8]` is one slot. Spilled
  locals take slots in declaration order. Halfwords spilled at a 4-byte stride (`sh`/`lhu`
  at sp+0x10, 0x14, 0x18, 0x1C) are two local `MgSVec` of which only `vx` and `vz` are
  used. A union of a `u32` and a bitfield struct kept in a register can give a 40-byte
  frame with no pad.
- Each `for (i = 0; i < n; i++)` with a variable `n` leaves a dead compare temp that keeps
  an 8-byte stack slot (`if (n) do {} while` loses it): frames of functions with many such
  loops need them. Locals sit in declaration order from the lowest address: an unused `u8
  pad[8/16/24]` before or after a local moves it to the game's slot, and two locals' order
  decides which sits at sp+0x10.
- A frame 8 bytes short (also a leaf with `addiu sp, sp, -8`) takes a `u8 pad[8]`, after
  the last array local or first; a larger pad (`u8 pad[0x20]`, `u8 pad[88]`) before a
  local moves it to the game's slot. A halfword read into a local and then `D[i]++` is
  merged by CSE into one load whose dead pseudo adds 8 bytes; a store to another global
  between them keeps both loads and the frame. Slots of address-taken locals follow the
  first `&`: `s32 v[2]` for two out-parameters.
- Frame size steps: `u8 pad[4]` and `u8 pad[8]` both give 64 where no pad gives 56,
  `pad[9..16]` 72. A function-level `u8 pad[0x38]` first in the declarations rebuilt
  scratchpad spawners' 0x50/0x58 frames; `u8 pad[8]; MgSVec v; u8 pad2[0x20];` places
  `vx`/`vz` at sp+0x18/0x1C. m2c-style `void *temp` locals add 8 bytes; a struct array
  `D[i].fn/.a/.b` instead of `s32 D[i * 6]` removed 24 bytes of dead locals (main
  func_80045D18); a cast-offset address `*((u8 *)D + 1 + i * 0xB9C)` can spill to an
  otherwise unused 8-byte slot where the typed `D[i].g` does not.
- `MgMat m; u8 pad[8];` (pad after the matrix) gives a 0x40 frame with `m` at sp+0x10;
  the pad first moves `m` (iyashi func_801B082C). `u8 pad[0x28]` before `rot` (nadare
  func_801B19CC) and `u8 pad[0x40]` (nadare func_801B1C54; iyashi func_801B0A74 for its
  0x68 frame) rebuild larger frames.
- An `s16` local copy of a field used in a compare and in later arithmetic (`s16 t =
  p->unk2;`, or `s16 k; k = 8; if (p->unk2 >= N) k = M - p->unk2;`) gives `lh v0; move
  v1,v0; slti` and 8 more bytes of frame; an `s32` gives one register (rakuseki
  func_801B0520, rocket func_801B0A34).
- A local copy of a rodata table as a byte struct (`typedef struct { u8 b[24]; } T; tbl =
  D_x;`), read as `*(s16 *)&tbl.b[i * 2]`, with `u8 pad[0x20]` before it to rebuild the
  frame (reazer func_801B17F8).
- `MgSVec unused; s32 flag;` rather than `MgVec` fixed a frame (hyper func_801B07A0);
  pads: `u8 pad[8]` after the last matrix (hyper func_801B1EA4), `u8 pad[0x30]` (triangle
  func_801B0DC4); `rot` declared last puts `m` at sp+0x10 (lasboss func_801B1C60).
  Aggregates sit lowest in declaration order, address-taken scalars above them.
- `s32 f(void)` falling off its end keeps the `bnez; nop` loop tail and passes `v0` on to
  a caller that returns it (hyper func_801B1160, func_801B254C).

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
- More arithmetic: `x % 2 * 64` on an `s16` field gives `sll 16; sra 10`, `(x % 2) << 6` a
  plain `sll 6`; `-p->f << 9` gives `negu; sll 9`, `p->f * -0x200` `sll; negu`; `k =
  (s16)t - 0x2D` (u16 t, s16 k) gives `addiu -45`, `k = t - 0x2D` `li 0xFFD3; addu`; `u16
  a, b; s16 d = a - b;` is narrowed to HImode and not CSE'd with an `a - b >= 0` test; `x
  - C + f() % n` folds C onto the remainder (one single-def local per call). A magic
  multiplier is a division by a constant: 0x5D9F7391 with shift 7 is /350, 0x7482296B with
  shift 10 /2250.
- More addresses: `*(u32 *)((u8 *)tbl + ((i - 1) << 2))` keeps the -1 out of the
  displacement; a pointer from one plain symbol (`p8 = &D_8015138F; ... (u16 *)(p8 -
  0x25)`) gives one shared `la` with negative offsets; a local table of byte-aligned
  structs indexed as `*(u8 *)(&t.b[2] + i * 6)` (`t.b[i * 6 + 2]` hoists `sp+16`).
- Calls into C already in the file: a callee called without arguments is defined `void
  f(arg0)` and declared `void f();` in the work file; a callback is passed as `(M2C_UNK
  *)func_X` and defined with bare parameter names. A work file's extern replaces decls.h's
  (never declare a symbol with another type than decls.h's), and `put` prints only cc1's
  last stderr line.
- More search helpers: a hill-climb over statement order with dependency constraints
  (work/snobo9/hc3.py, work/spells19/hc.py) solved functions plain permutation could not;
  the first scheduler's dump (`-dS`) gives each insn a priority, its depth in its
  dependency chain.
- Narrowing, more: `rot.vy = p->f << 6` gives `lhu`, `p->f * 0x40` `lh`, `-p->f * 0x40`
  `negu; sll`; `t = p->f; v = t << 6;` keeps `lh`; `t = D[0] - 8; t += (p->f % 2) << 4;
  D[0] = t;` gives `sll 16; sra 12` where the one-liner stays HImode; `s32 t = G - 6; G =
  t; if ((s16)t == 0)` gives `addiu -6; sll 16; bnez`; `a = D_x + 8; D_x = a;` through an
  `s32` gives `addiu` where `D_x -= 8` on a `u16` gives `li 0xFFF8; addu`; `y = D;` gives
  `lhu` where `if (D >= 0xE1) y = 0xE0; else y = D;` gives `lh` and a `move`; `p->f +=
  0xCC; g(p->f)` reloads where `s16 t = p->f + 0xCC; p->f = t; g(t)` forwards.
- Folding, more: `(p->e - (q->f + 0x320)) / 20` folds the constant, `k = q->f + 0x320;
  (p->e - k) / 20` keeps the `addiu`; `(s16)D->vx - 0x12C + rand() % 600` keeps `addiu
  -300` on the field, `D->vy + (rand() % 600 - 0x12C)` gives the other fold; `(x - K + n)
  % n` gives `addiu v, n, -K; addu v, x, v`, `x + (n - K)` `addiu v, x, -K; addu v, v, n`;
  `rand() % (w / 2 * 2) - w / 2` matched written inline each time; in-place `d <<= 10; d
  >>= 12;` keeps one register where `d << 10 >> 12` takes a temporary.
- Search helpers, more: comparing a sibling function's cc1 output with the draft's
  (work/spells19/dump.py on its source) found a missing `do { } while (0);`;
  work/spells24/search.py replaces a snippet by each line of a variants file and scores
  the results; constraining the game's relative order of a few lines (`A::B` in
  work/spells19/hc.py) found matches where unconstrained hill-climbs stalled.
- Arithmetic order, more: `x + (w.y - 0x800)` is reassociated to `(x - 0x800) + w.y`
  (single-def locals keep the game's form); `(t * 0x258 >> 12) + 0x258 + (k * 0xC8 >> 12)`
  keeps the add order where nesting folds the constant; `(u16)t >> 1` on `0x80 - x * 16`
  folds to `andi 0xFFF0; srl 1`, `(u32)(t << 16) >> 17` keeps it; `(i << 16) >> 9` gives
  `sll 16; sra 9` where `i << 7` gives `sll 7`; `v *= 3; v >>= 1;` gives `addu a0, a0,
  v0`.
- A function whose first instructions the scheduler moved above `addiu sp` can be cut by
  splat into a rodata symbol (the moved words) and a function at the `addiu sp`: highway's
  code starts at its entry 0x800A00D0, seven words before the function splat had found.
  tools/work.py cannot parse multi-line K&R definitions with typed parameters.
- `tools/work.py diff` compares by position, so one extra instruction shifts every later
  word: score with an aligned diff after normalising branch targets (work/main8/norm.py
  and score.py, work/spells10/diffi.py). work/spells31/magic2.py HEX SHIFT recovers a
  divisor from GCC's magic multiplier. The permuter's `inline_fn` is `inline s16
  inline_fn(u16 x) { return (s16)x; }` (a distinct HImode pseudo per use): plain code may
  not reproduce it. `put` drops a work file's declaration of a function already defined
  in C, so a callee defined `void f(void)` that new code calls with an argument has to
  become `void f(arg0)` in the source first. A function that matches only with code GCC
  inlined (an inlined helper is a scheduling barrier no block or `do { } while (0)`
  replaces) takes the helper as a `static inline` function before it in the work file:
  `put` places it right before the function, once per file (reito func_801B1158).
- A ring-buffer quad drawn by func_8003BD7C with the colour word per quad: `*(u32 *)(q +
  4) = *(u32 *)(q + 0xC) = col` (iyashi func_801B0624).
- work/main10/mk34FC8n.py brute-forces where a few independent stores sit around a fixed
  chain (under 350 compiles for main func_80034FC8); work/spells34/decl_perm.py tries
  declaration orders.
- More magic multipliers: 0x64D319FF with shift 8 is /650; 0x57619F1 is /750 (shift 4)
  and /24000 (shift 9); 0x1A6D01A7 is /620 and /19840; 0x1B4E81B5 is /600 and /19200.
- work/spells38/declperm.py tries every order of a block of declarations;
  work/spells19/hc.py with two `A::B` constraints placed a store group in 2 iterations
  (reazer func_801B17F8). A helper named `types.py` in a work folder shadows the stdlib
  module for every script run from there: give helpers distinctive names.
- More magic multipliers: 0x88888889 with shift 10 is /1920, 0x78787879 with shift 5 is
  /68, 0x66666667 with shift 3 is /20.
- tools/work.py tidies a target's decls.h whenever it uses the target (`show`, `diff`,
  `put`), dropping declarations main/decls.h already has: another spell's decls.h
  changing during a batch is expected and right.

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
to eight agents ran at once at first; now one at a time, the maintainer's limit (each
permuter run with `--jobs 2`). An agent stopped by a usage limit keeps its context:
stop its leftover permuter processes, build everything, commit what it put, and resume
it later with a message. On Windows, agents must never run `python3`/`python` (the
Microsoft Store aliases) or any Python reading stdin (`python -`, the venv's Python with
`-` or with no script): such processes hang at 100% CPU and outlive their command;
scripts are written to a file and run with the venv's Python. Agents still type
`.venv/Scripts/python -` now and then: say it in every prompt and check for hung
processes after each batch. Agents never
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
