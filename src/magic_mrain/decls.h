/* Declarations the C of src/magic_mrain/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MRAIN_DECLS_H
#define MAGIC_MRAIN_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
void func_801B289C();
extern M2C_UNK D_801D4384;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B007C(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0158(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02D4(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03B0(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B2928;
extern MgTask D_80162978[];
extern MgTask *D_801ED824;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B27A4;
extern s32 D_801ED828;
extern s32 D_801ED82C;
void func_801B0EA8(void);
extern s16 D_8015169C;
extern u16 D_801D5800;
void func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
extern u8 *D_801ED820;
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801D2A2C;

#endif /* MAGIC_MRAIN_DECLS_H */
