/* Declarations the C of src/magic_conf/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CONF_DECLS_H
#define MAGIC_CONF_DECLS_H

#include "main/decls.h"
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0080(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B015C(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02D8(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03B4(MgSVec *p, MgSVec *q, MgVec *n);

#endif /* MAGIC_CONF_DECLS_H */
