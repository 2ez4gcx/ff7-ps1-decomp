/* Declarations the C of src/magic_berserk/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BERSERK_DECLS_H
#define MAGIC_BERSERK_DECLS_H

#include "main/decls.h"
void func_801B0018(void);
s32 func_801B07D0();
void func_801B0764(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
extern u8 D_801D1334[];
extern u8 *D_801EF334;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, s32, M2C_UNK *);
s32 func_800D54BC();
extern M2C_UNK D_801B0858;
void func_801B06B0(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(void *);
M2C_UNK func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151A4C[][0xB9C];
extern M2C_UNK func_801B0454;
void func_801B034C(void);
typedef struct { s32 anim; s32 rgbc; u16 frame; u16 pad; } BsSpr;
M2C_UNK func_800D4368(void *, M2C_UNK, M2C_UNK);
u8 *func_800D4D90(BsSpr *, s32, M2C_UNK, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern BsSpr D_801B000C;

#endif /* MAGIC_BERSERK_DECLS_H */
