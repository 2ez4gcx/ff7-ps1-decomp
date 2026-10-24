/* Declarations the C of src/chocobo/ uses (tools/auto_decomp.py adds to this). */
#ifndef CHOCOBO_DECLS_H
#define CHOCOBO_DECLS_H

#include "main/decls.h"
typedef struct { u8 pad0[2]; u8 a; u8 cnt; u8 pad4[0x12]; s16 f16; u16 off; s32 base; s32 f20; } WmHdr3;
s32 func_800AD9D8(s32, s32, s32, s32);
void func_800AF9E4(WmHdr3 *, s16, s32);
s32 func_800AD91C(WmHdr3 *arg0, s32 arg1, s32 arg2);
s32 func_800B00DC(WmHdr3 *arg0, u8 *arg1);
void func_800B01B0(s32, s16, s16, s16);

#endif /* CHOCOBO_DECLS_H */
