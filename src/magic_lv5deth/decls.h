/* Declarations the C of src/magic_lv5deth/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LV5DETH_DECLS_H
#define MAGIC_LV5DETH_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0508();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void *);
void func_801B0310(void);
void func_801B0414();
extern MgTask D_80162978[];
extern u8 D_801B05E0[];
extern MgTask *D_801D8E54;
extern s32 D_801D8E58;
extern u8 D_801B0000[];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_800D3994(s32, s32, void *);
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);
void func_801B01BC(void);
void func_801B0074(void);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80062D98;
extern u8 D_800F5B70[];
extern s16 D_800F5B74;
extern s16 D_8015169C;
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
void func_800D5774(s32);
extern s32 D_801517C0;
extern u8 D_801C0E48[];
extern s16 D_801C0E4C[];
extern s32 D_801D8E50;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B69C(s32, s32, s32);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_801C0868[];

#endif /* MAGIC_LV5DETH_DECLS_H */
