/* Declarations the C of src/magic_minimam/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MINIMAM_DECLS_H
#define MAGIC_MINIMAM_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0514();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern MgObj20 D_80162978[];
extern u8 D_801B0000[];
extern u8 D_801B05B8[];
extern MgObj20 *D_801CC8B0;
extern s32 D_801CC8B4;
void func_801B0414();

#endif /* MAGIC_MINIMAM_DECLS_H */
