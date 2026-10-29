/* Declarations the C of src/magic_seald/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SEALD_DECLS_H
#define MAGIC_SEALD_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B0E98();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern MgTask D_80162978[];
extern MgTask *D_801DB3B0;
extern s32 D_801DB3B4;
extern u8 D_801B0000[];
extern u8 D_801B0F64[];
void func_801B0D4C();
void func_801B0B3C(void);
typedef struct { u8 b[8]; } MgB8;
s32 func_80042DA8(void);
void func_800D5138(s32);
void func_800D51D4(s32);
void func_800D5774(s32);
void func_801B0974(void);
void func_801B07A0(void);
extern s16 D_8015169C;
extern u8 D_80062D98;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
s32 func_801B0728(void *, s32);
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern u8 D_801C1084[];
extern s32 D_801DB3AC;
extern s32 D_1F800000[];
void func_8003B69C(s32, s32, s32);
extern u8 D_801C22A8[];

#endif /* MAGIC_SEALD_DECLS_H */
