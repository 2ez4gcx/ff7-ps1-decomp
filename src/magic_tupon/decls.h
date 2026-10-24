/* Declarations the C of src/magic_tupon/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TUPON_DECLS_H
#define MAGIC_TUPON_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B64C8();
extern M2C_UNK D_801D90DC;
void func_801B2258(s32 arg0);
extern u8 *D_801EDA8C;
s32 func_801B0068(s16 **pp);
extern s16 D_801EDE2E[];
void func_801B10E8(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B00A4;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801EDDF8;
extern MgMat D_801EDA6C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B1FB0(MgSVec *v, s16 scale, s32 dist);
void func_801B4104(void);
extern u16 D_801ED8B8;
extern s16 D_801ED8DA;
extern u16 D_801EDBB8;
extern u16 D_801EDBA8;
extern s32 D_801ED8D4;
extern s32 D_801EDBC4;
extern M2C_UNK D_801EDB88;
void func_8003A63C(void *, void *, MgMat *);
extern M2C_UNK D_801EDBC8;
void func_801B1C0C(MgMat *, void *);

#endif /* MAGIC_TUPON_DECLS_H */
