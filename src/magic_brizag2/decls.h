/* Declarations the C of src/magic_brizag2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BRIZAG2_DECLS_H
#define MAGIC_BRIZAG2_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B58B4();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003A08C(MgVec *, MgVec *);
s32 func_8003A59C(s32);
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003CC1C(s32, s32);
s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0150(s32 ang, MgMat *m, MgVec *v);
void func_801B2FCC(MgSVec *v0, MgSVec *v1, s32 color);
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { MgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s16 x0; s16 y0; u8 r1; u8 g1; u8 b1; u8 pad; s16 x1; s16 y1; } MgLineG2;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s32 D_801EA264;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern MgTask D_80162978[];
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B5938;
extern MgTask *D_801EA268;
extern s32 D_801EA26C;
extern s32 D_801EA278;
void func_801B57EC(void);
void func_801B3474(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
extern s16 D_8015169C;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B27C(MgMat *, MgSVec *, MgVec *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
extern u8 D_801D5E58[];
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B3640(void);

#endif /* MAGIC_BRIZAG2_DECLS_H */
