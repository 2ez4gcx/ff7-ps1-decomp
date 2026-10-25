/* Declarations the C of src/magic_matra/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MATRA_DECLS_H
#define MAGIC_MATRA_DECLS_H

#include "main/decls.h"
void func_801B0070(void);
s32 func_801B1F38();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0090(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B016C(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02E8(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03C4(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { MgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s16 x0; s16 y0; u8 r1; u8 g1; u8 b1; u8 pad; s16 x1; s16 y1; } MgLineG2;
typedef struct { s32 unk0; s32 sxy; s32 otz; s32 flag; } MgRtp;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern MgLineG2 *D_801DC890;
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
extern s32 D_801517C0;
void func_801B1428(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color);
void func_801B04A8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u16 D_801B888C;
void func_800D4368(void *, s32, s32);
MgLineG2 *func_800D4D90(void *, s32, s32, MgLineG2 *);
extern u8 D_80062D98;
void func_801B1D54(void);
typedef struct { s32 id; s16 x; s16 y; s16 z; s16 h; s32 unkC; s32 unk10; } MgMatraTgt;
s32 func_800BBEAC(void *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
extern s32 D_801DC898;
extern s32 D_801DC89C;
extern u8 D_801DC8A4[];
extern u16 D_801DC8AA;
extern s16 D_801DC8AC;
extern MgMatraTgt D_801DE05C[];
void func_801B1558(void);
MgMat *func_8003AB84(MgMat *, MgMat *, MgMat *);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_800D2980(void *, s32, s32, s32);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern u8 D_801B20D4[];
extern u8 D_801B001C[];
extern MgMat D_801B8864;
extern MgTask *D_801DC894;
extern s32 D_801DC8A0;
extern s16 D_801DC8B0;
extern s16 D_801DC8B4;
extern s16 D_801DC8B8;
extern u8 D_801DC8BC[];
extern s32 D_801DE0F0;

#endif /* MAGIC_MATRA_DECLS_H */
