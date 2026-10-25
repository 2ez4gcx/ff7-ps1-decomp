/* Declarations the C of src/magic_tsol/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TSOL_DECLS_H
#define MAGIC_TSOL_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
s32 func_801B06EC();
extern M2C_UNK D_801B0760;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_801B0000[];
M2C_UNK func_800BBEAC(M2C_UNK *);
extern u8 func_801B04EC[];
extern MgTask D_80162978[];
extern MgTask *D_801CDBB0;
extern s32 D_801CDBB4;
extern s32 D_801CDBB8;
void func_801B007C(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_80042DA8(void);
s32 func_800D6260(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801B5B50[];
extern s32 D_801B5B5C[];
extern s32 D_801B5B74[];
extern MgMat D_801B5B8C;
extern s32 D_801CDBAC;
extern MgMat D_801CDBCC;
extern MgMat D_801CDBEC;
void func_801B02AC(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
MgTask *func_800D4FA8(s32);
s32 func_800D56A8(void *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
void func_800D5774(s32);
void func_800D4D4C(s32, s32);
extern MgSVec D_80153D20;
typedef struct { s32 vx; s32 vy; s32 vz; } MgIVec;
extern MgIVec D_801CDBE0;

#endif /* MAGIC_TSOL_DECLS_H */
