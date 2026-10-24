/* Declarations the C of src/magic_mdance/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MDANCE_DECLS_H
#define MAGIC_MDANCE_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
M2C_UNK func_801B0754();
extern M2C_UNK D_801B07C8;
void func_801B0460(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgTask D_80162978[];
extern s32 func_801B01B8;
void func_801B007C(void);
typedef struct { s16 x; s16 y; u8 u; u8 v; u8 w; u8 h; s32 rgbc; u16 tpage; u16 clut; } MgSprArg;
extern s16 D_8015169C;
M2C_UNK func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
extern s32 D_801CE290;
extern u8 D_801B6278[];
s32 func_800D6260(MgSprArg *, s32, s32, s32);
extern u8 D_80062D98;

#endif /* MAGIC_MDANCE_DECLS_H */
