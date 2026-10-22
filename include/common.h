#ifndef COMMON_H
#define COMMON_H

/* Types as the game's C used them (PSY-Q, 32-bit MIPS R3000). */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Rodata taken from asm, kept in its place among the functions as
 * INCLUDE_ASM is (GCC 2.6.3 would put top-level asm ahead of them). */
#if !defined(M2CTX) && !defined(PERMUTER) && !defined(INCLUDE_RODATA)
#define INCLUDE_RODATA(FOLDER, NAME) \
    void __maspsx_include_asm_hack_rodata_##NAME() { \
        __asm__( \
            ".section .rodata # maspsx-keep\n" \
            "    .include \"" FOLDER "/" #NAME ".s\" # maspsx-keep\n" \
            ".text # maspsx-keep\n" \
        ); \
    }
#endif

#include "include_asm.h"

#endif /* COMMON_H */
