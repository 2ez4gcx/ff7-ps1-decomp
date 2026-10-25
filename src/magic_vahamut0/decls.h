/* Declarations the C of src/magic_vahamut0/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_VAHAMUT0_DECLS_H
#define MAGIC_VAHAMUT0_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0060(void);
M2C_UNK func_801B7920();
extern M2C_UNK D_801D823C;
void *func_801B2BDC(void *arg0, s32 arg1, void *arg2);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801FD11C;
extern MgMat D_801FC8E0;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B0088(MgSVec *v, s16 scale, s32 dist);
s32 func_801B01A4(s16 **pp);
extern s16 D_801FD13E[];
s32 func_801B01E0(s32 a, s32 b);
s32 func_80039A74(s32);
void func_801B13AC(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B03D4;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B24A4(void);
extern s32 D_801FD924[];
typedef struct { u32 tag; u8 pad4[4]; s32 xy0; u8 pad0c[4]; s32 xy1; u8 pad14[4]; s32 xy2; } MgPolyT;
s32 func_8003BC0C(MgSVec *, MgSVec *, MgSVec *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern MgSVec D_801FCDF4[];
extern MgPolyT *D_80163C74;
MgPolyT *func_801B4018(void);

#endif /* MAGIC_VAHAMUT0_DECLS_H */
