/* Declarations the C of src/magic_hades/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HADES_DECLS_H
#define MAGIC_HADES_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801BA978();
extern M2C_UNK D_801DDE34;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0068(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0144(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02C0(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B039C(MgSVec *p, MgSVec *q, MgVec *n);
s32 func_801B19B4(s16 **pp);
extern s16 D_801F7B76[];
s32 func_801B19F0(s32 a, s32 b);
void func_801B2B1C(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B1AE8;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];

#endif /* MAGIC_HADES_DECLS_H */
