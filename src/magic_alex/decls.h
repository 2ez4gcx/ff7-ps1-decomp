/* Declarations the C of src/magic_alex/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ALEX_DECLS_H
#define MAGIC_ALEX_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B6AB0();
extern M2C_UNK D_801DED44;
void func_801B3E14(void *arg0);
M2C_UNK func_801B3430(void *, s16, s16);
extern u8 D_80062D98;
extern u8 D_801DEA40;
void func_801B3498(void *arg0);
s32 func_80039A74(s16);
s32 func_80039B40(s16);
s32 func_801B0068(s16 **pp);
extern s16 D_801F0632[];
void func_801B10C0(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
extern M2C_UNK func_801B00A4;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A08C(MgVec *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
extern MgMat D_801EDDEC;
extern MgMat D_801F0610;
MgMat *func_801B2C78(MgSVec *v, s16 scale, s32 dist);
void func_801B2F38(void);
void func_8003A63C(void *, void *, MgMat *);
void func_801B1BE4(MgMat *, void *);
extern u16 D_801EDB30;
extern s32 D_801EDB4C;
extern s16 D_801EDB52;
extern M2C_UNK D_801EDE0C;
extern u16 D_801EDE2C;
extern u16 D_801EDE3C;
extern s32 D_801EDE48;
extern M2C_UNK D_801EDE4C;
typedef struct { s32 n; MgSVec v[1]; } MgSVecList;
void func_801B1E24(MgSVecList *a, MgSVec *b, MgSVec *out);
void func_801B1EB4(MgSVecList *a, MgSVec *b, MgSVec *d, s32 t);

#endif /* MAGIC_ALEX_DECLS_H */
