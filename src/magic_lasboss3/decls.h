/* Declarations the C of src/magic_lasboss3/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LASBOSS3_DECLS_H
#define MAGIC_LASBOSS3_DECLS_H

#include "main/decls.h"
void func_801B0040(void);
void func_801BA85C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80042DA8(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B0208(s32 base, s16 range, MgSVec *out);
s32 func_801B1254(s16 **pp);
extern s16 D_801FC706[];
s32 func_801B1290(s32 t, s32 s);
s32 func_80039A74(s32);
void func_801B23A8(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B1380;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B246C(void);
s32 func_800C4FC8(s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_80163C74;
extern s16 D_801BB7D0;

#endif /* MAGIC_LASBOSS3_DECLS_H */
