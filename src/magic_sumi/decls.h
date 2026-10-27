/* Declarations the C of src/magic_sumi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SUMI_DECLS_H
#define MAGIC_SUMI_DECLS_H

#include "main/decls.h"
void func_801B0B38(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B0C3C;
void func_801B0964();
void func_801B0BB4(s32 arg0, M2C_UNK arg1);
extern s16 D_801B501C;
void func_801B006C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgObj20 D_80162978[];
extern s16 D_801B5028[];
extern s32 *D_801B502C[];
extern s32 D_801CD060;
void func_801B03E8(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_800D4484(s32, s32);
extern s16 D_801B5054[];
extern u8 D_801B5048[];
MgMat *func_800D4368(void *, s16, s32);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_800D3994(s32, s32, void *);
void func_801B0514(void);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151918[][0xB9C];
void func_801B0174(void);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, void *, MgSVec *);
void func_8003C21C(MgSVec *, MgMat *);
s32 func_80042DA8();
extern s16 D_801B5044;
void func_800D5774(s32);
extern u8 D_8016297C[];

#endif /* MAGIC_SUMI_DECLS_H */
