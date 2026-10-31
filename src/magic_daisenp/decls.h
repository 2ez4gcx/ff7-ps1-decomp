/* Declarations the C of src/magic_daisenp/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DAISENP_DECLS_H
#define MAGIC_DAISENP_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0E38();
extern s32 D_801CF2F4;
void func_801B007C(void);
void func_801B0250(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { u16 v; } MgHalf;
extern MgTask D_80162978[];
extern MgHalf D_801B72E8;
extern u8 D_801CF300[];
extern u8 D_801CF302[];
extern u8 D_801CF304[];
extern u8 D_801CF306[];
extern u8 D_801B72E0[];
extern MgSVec D_801CFCB8;
extern s32 D_801CF2EC;
extern s32 D_801517C0;
extern s16 D_8015169C;
extern u8 D_80062D98;
s32 func_80039F5C(s32);
s32 func_8003A08C(void *, void *);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern u8 D_801B0000[];
extern u8 D_801B0ED8[];
extern MgTask *D_801CF2F0;
extern s32 D_801CF2F8;
extern s32 D_801CF2FC;
void func_801B0B18(void);
void func_801B00A8(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
extern u16 D_801B72DC;
s32 func_80042DA8();
M2C_UNK func_800D54EC();
extern M2C_UNK func_801B04AC;
extern MgSVec D_801CFCC0;
extern s32 D_801CFCC8;
extern s32 D_801CFCCC;
extern s32 D_801CFCD0;
extern MgVec D_801CFCD8;
extern MgVec D_801CFCE8;

#endif /* MAGIC_DAISENP_DECLS_H */
