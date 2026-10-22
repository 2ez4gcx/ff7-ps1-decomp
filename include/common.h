#ifndef COMMON_H
#define COMMON_H

/* Types as the game's C used them (PSY-Q, 32-bit MIPS R3000). */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

#ifndef NULL
#define NULL ((void *)0)
#endif

#include "include_asm.h"

#endif /* COMMON_H */
