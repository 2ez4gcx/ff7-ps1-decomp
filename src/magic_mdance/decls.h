/* Declarations the C of src/magic_mdance/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MDANCE_DECLS_H
#define MAGIC_MDANCE_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
s32 func_801B0754();
extern M2C_UNK D_801B07C8;
void func_801B0460(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgTask D_80162978[];
void func_801B01B8(void);
void func_801B007C(void);
typedef struct { s16 x; s16 y; u8 u; u8 v; u8 w; u8 h; s32 rgbc; u16 tpage; u16 clut; } MgSprArg;
extern s16 D_8015169C;
M2C_UNK func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
extern s32 D_801CE290;
extern u8 D_801B6278[];
s32 func_800D6260(MgSprArg *, s32, s32, s32);
extern u8 D_80062D98;
extern u8 D_801B0000[];
extern MgTask *D_801CE294;
extern s32 D_801CE298;
extern s32 D_801CE29C;
void func_801B0678(void);
void func_801B04B4(s32 arg0, s32 arg1);
void func_800D5444(s32, s32, s32, void (*)(s32));
s32 func_800D54BC(s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
void func_800D54EC(s32, void *);
void func_801B0524(void);
extern u16 D_80151A46[][0x5CE];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
MgTask *func_800D4FA8(s32);
s32 func_800D56A8(void *);
extern u16 D_80153D1A;
void func_800D3994(s32, s32, void *);
s32 func_80042DA8(void);
void func_800D5774(s32);
extern s16 D_801518F4[][0x5CE];
extern u16 D_801B6284[];

#endif /* MAGIC_MDANCE_DECLS_H */
