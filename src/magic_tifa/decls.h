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

#endif /* MAGIC_TIFA_DECLS_H */
