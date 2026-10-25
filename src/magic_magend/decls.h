/* Declarations the C of src/magic_magend/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MAGEND_DECLS_H
#define MAGIC_MAGEND_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0448();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B1748[];
extern u8 *D_801C1748;
extern s16 D_80162080;
s32 func_800BBEAC(void *);
extern M2C_UNK D_801B04B4;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B03F4(s32 arg0, s32 arg1);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0174(void);
void func_801B0080(void);
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801B1730;
extern u8 D_801B1734[];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s32 func_80042DA8();
void func_800D3994(s32, s32, void *);
void func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];
extern MgSVec D_801B1740;

#endif /* MAGIC_MAGEND_DECLS_H */
