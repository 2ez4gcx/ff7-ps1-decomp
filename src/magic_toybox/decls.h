/* Declarations the C of src/magic_toybox/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TOYBOX_DECLS_H
#define MAGIC_TOYBOX_DECLS_H

#include "main/decls.h"
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B00D4(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B01B0(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B032C(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B0408(MgSVec *p, MgSVec *q, MgVec *n);
void func_801B0074(s32 a, s32 b);
void func_801B1530(s32, s32, s32);
void func_801B0094(s32 a, s32 b);
void func_801B00B4(s32 a, s32 b);

#endif /* MAGIC_TOYBOX_DECLS_H */
