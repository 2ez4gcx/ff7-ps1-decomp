/* Declarations the C of src/magic_debucho/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DEBUCHO_DECLS_H
#define MAGIC_DEBUCHO_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B1D64();
extern M2C_UNK D_801BAC54;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801C42A0;
extern MgMat D_801C4058;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist);
s32 func_801B0184(s16 **pp);
extern s16 D_801C42C2[];
void func_801B11DC(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B01C0;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];

#endif /* MAGIC_DEBUCHO_DECLS_H */
