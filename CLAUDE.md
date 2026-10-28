# Notes for Claude Code

A matching decompilation of Final Fantasy VII (PS1, USA, all three discs): C that the game's own
compilers turn back into exactly the bytes on the disc. Start with [README.md](README.md)
(setup, building, progress), [docs/toolchain.md](docs/toolchain.md) (compilers, options
per file, rodata) and [docs/matching.md](docs/matching.md) (how to match a function,
what GCC needs, how batches of agents work).

## Rules

- Never commit the game's data: disc images, files taken from the disc (`disks/`), the
  asm splat makes from them (`asm/`), `build/`. `.gitignore` keeps them out; keep it so.
- Everything in the repository is in English: code, comments, docs, commit messages.
  The maintainer (2ez4gcx) writes in Vietnamese: answer them in Vietnamese.
- This is an independent project: do not copy code from other FF7 decomps
  (Xeeynamo/ff7-decomp is AGPL and forbids LLM-assisted work); read them only to
  understand formats, if at all. FFNx and m2c are GPL: no code from them either.
- Commit as `2ez4gcx <108074836+2ez4gcx@users.noreply.github.com>` (set it in this
  clone's git config) and end each message with
  `Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>`. Commit and push after each
  batch that builds: `tools/build.py <target>` must say `N/N targets match`.
- Ask before downloading anything new.

## Resuming the work

`py tools/progress.py` shows what is left per group. The usual next step is a batch of
the ~30 smallest functions still in asm of one target (battle, field, world, the menus
eqipmenu/namemenu/savemenu/shopmenu, then the minigames and the spell effects), given to
a subagent with docs/matching.md, one at a time (the maintainer's limit). Known
near misses that resisted, and handwritten functions, are listed in
[docs/near-misses.md](docs/near-misses.md): skip them in batches.

When a target's file holds several of the game's files (a switch function cannot be
put because its jump table's alignment is off), split it where the jump tables change
alignment: see "Rodata" in docs/toolchain.md and `tools/split_file.py`.
