/* Declarations the C of src/magic_dethper/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DETHPER_DECLS_H
#define MAGIC_DETHPER_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B1D58();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0150(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(M2C_UNK *);
void func_800D2980(void *, s32, s32, s32);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern MgTask D_80162978[];
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B1DE4;
extern MgTask *D_801CF0E8;
extern s32 D_801CF0EC;
void func_801B1B80(s32 arg0);
void func_801B1A00(void);
typedef struct { u8 b[8]; } DpB8;
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s16 D_801B70DC[];
extern M2C_UNK func_801B173C;
typedef struct { void *unk0; u8 pad[0x28]; s32 unk2C; } DpScratch;
void func_800D3994(s32, s32, void *);
void func_801B0854(void *);
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);
extern u8 D_8015190F[][0xB9C];
extern u8 D_801518F6[][0xB9C];
extern M2C_UNK D_801B60C8;
void func_801B11FC(void);
void func_801B151C(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_8003B69C(s32, s32, s32);
s32 func_800D29D4(void *, s32, s32, s32);
void func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
extern s16 D_80158D00;
extern s16 D_80158D04;
extern M2C_UNK D_801B62CC;
extern MgVec D_801B70BC;
extern s32 D_801CF0E4;
typedef struct { void *unk0; s32 unk4; s32 unk8; s32 unkC; u8 pad10[0x1C]; s32 unk2C; } DpScr2;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003A79C(MgMat *, MgMat *, MgMat *);
void func_8003B27C(MgMat *, MgSVec *, MgVec *);
void func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_801B115C(void *, s32);
void func_800D5138(s32);
void func_800D51D4(s32);
void func_800D5774(s32);
extern MgMat D_800FA63C;
extern MgVec D_801B70AC;

#endif /* MAGIC_DETHPER_DECLS_H */
