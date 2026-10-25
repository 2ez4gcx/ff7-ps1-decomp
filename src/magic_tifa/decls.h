/* Declarations the C of src/magic_tifa/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TIFA_DECLS_H
#define MAGIC_TIFA_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0088(void);
M2C_UNK func_801BCD98();
extern M2C_UNK D_801CDC20;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0190(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B026C(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B03E8(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B04C4(MgSVec *p, MgSVec *q, MgVec *n);
void func_801B107C(MgSVec *v0, MgSVec *v1, s32 color);
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { MgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s16 x0; s16 y0; u8 r1; u8 g1; u8 b1; u8 pad; s16 x1; s16 y1; } MgLineG2;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern MgLineG2 *D_801F3D50;
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
extern s32 D_801517C0;
typedef struct { s32 head; s32 tail; s32 count; s32 size; s32 last; s32 prev; s32 buf[1]; } MgRing;
void func_801B11D8(MgRing *r, s32 v);
void func_801B00B0(s32 a, s32 b);
void func_801BCE2C(s32, s32, s32);
void func_801B00D0(s32 a, s32 b);
void func_801B00F0(s32 a, s32 b);
void func_801B24A8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 v; } MgHalf;
void func_800D4368(void *, s32, s32);
MgLineG2 *func_800D4D90(void *, s32, s32, MgLineG2 *);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern s16 D_801F3B7C;
extern MgHalf D_801F3B7E;
void func_801B258C(void);
extern s16 D_801F3B88;
extern MgHalf D_801F3B8A;
void func_801B1258(MgTask *arg0, MgSVec *arg1, MgSVec *arg2);
extern s16 D_800FA650;
extern s16 D_800FA654;
extern s16 D_800FA658;
MgMat *func_8003BF3C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003A79C(MgMat *, MgTask *, MgMat *);
void func_801B6D34(void);
typedef struct { s8 v; } MgByte;
extern MgByte D_801F3BBC;
extern MgByte D_801F3BBD;
extern MgByte D_801F3BBE;
void func_801BB568(void);
void func_8003B69C(s32, s32, s32);
void func_8003B710(s32 *, s32, s32 *);
void func_801B18C4(void *, s32, s32, s32);
extern u8 D_801F5360[];

#endif /* MAGIC_TIFA_DECLS_H */
