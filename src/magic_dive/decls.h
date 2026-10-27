/* Declarations the C of src/magic_dive/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DIVE_DECLS_H
#define MAGIC_DIVE_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B0BD4();
extern M2C_UNK D_801BAA50;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BCFD8[];
extern u8 *D_801CCFD8;
extern s16 D_80162080;
void func_801B0088(void);
s32 func_800C4FC8(s16, M2C_UNK, s16);
extern u8 D_80062D98;
extern s32 D_80163C74;
extern s16 D_801BCFA0;
extern s16 D_801BCFA2;
void func_801B01AC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(s16 *, M2C_UNK, M2C_UNK);
s32 func_800D4D90(void *, s32, s32, s32);
extern s32 D_801517C0;
extern s32 D_801BA98C;
extern u16 D_801BCFAC;
void func_801B0274(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s32 func_80042DA8();
s32 func_800BBEAC(M2C_UNK *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern MgSVec D_801B8C68[];
extern MgSVec D_801BA1E8[];
extern MgSVec D_801BA5B8[];
extern MgSVec D_801BCFB0;
extern M2C_UNK D_801BCFB8;
void func_801B0650(void);
M2C_UNK func_800BBA84(M2C_UNK, s16, M2C_UNK);
M2C_UNK func_800D4CBC(s16, M2C_UNK, M2C_UNK);
MgTask *func_800D4FA8(M2C_UNK);
extern u16 D_80151A46[][0x5CE];
extern u16 D_80151A4C[][0x5CE];
extern u16 D_80151A50[][0x5CE];
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B08E8();
extern M2C_UNK D_801B0CA4;

#endif /* MAGIC_DIVE_DECLS_H */
