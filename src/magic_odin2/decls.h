/* Declarations the C of src/magic_odin2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ODIN2_DECLS_H
#define MAGIC_ODIN2_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B5264();
extern M2C_UNK D_801DCCD0;
s32 func_801B0068(s16 **pp);
extern s16 D_801F726E[];
void func_801B10E8(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B00A4;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801F6238;
extern MgMat D_801F1C3C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B2200(MgSVec *v, s16 scale, s32 dist);
void func_801B25F8(void);
s32 func_800D4D90(M2C_UNK *, s32, M2C_UNK, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern M2C_UNK D_801F1C6C;
void func_801B26D0(void);
M2C_UNK func_8003A63C(MgMat *, M2C_UNK *, MgMat *);
s32 func_800D29D4(M2C_UNK *, s32, M2C_UNK, s32);
extern M2C_UNK D_801F1C78;
extern M2C_UNK D_801F1C88;
extern MgMat *D_801F1CA8;

#endif /* MAGIC_ODIN2_DECLS_H */
