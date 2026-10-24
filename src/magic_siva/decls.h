/* Declarations the C of src/magic_siva/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SIVA_DECLS_H
#define MAGIC_SIVA_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
M2C_UNK func_801B49CC();
extern M2C_UNK D_801D9E98;
void func_801B274C(s32 arg0);
extern s32 D_801F2674;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801F1374;
extern MgMat D_801F0040;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B007C(MgSVec *v, s16 scale, s32 dist);
s32 func_801B0198(s16 **pp);
extern s16 D_801F139E[];
s32 func_801B01D4(s32 t, s32 s);
s32 func_80039A74(s32);
void func_801B1300(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B02C4;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B275C(MgSVec *arg0);
s32 func_800D4D90(M2C_UNK *, s32, M2C_UNK, s32);
extern s32 D_801517C0;
extern s32 D_80163C74;
extern M2C_UNK D_801F0298;
void func_801B4334(void);
M2C_UNK func_8003B2CC(void *, M2C_UNK *, s32);
M2C_UNK func_800D41FC(MgMat *, M2C_UNK *, void *);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern M2C_UNK D_801546EC;
extern M2C_UNK D_801F036C;
extern u8 *D_801F0374;

#endif /* MAGIC_SIVA_DECLS_H */
