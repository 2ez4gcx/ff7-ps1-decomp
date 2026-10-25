/* Declarations the C of src/magic_beam/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BEAM_DECLS_H
#define MAGIC_BEAM_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
extern s32 D_801DFA34;
M2C_UNK func_801B1564();
void func_801B007C(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B00A8(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B0300(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03DC(MgSVec *p, MgSVec *q, MgVec *n);

#endif /* MAGIC_BEAM_DECLS_H */
