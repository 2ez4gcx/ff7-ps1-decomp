/* Declarations the C of src/magic_hikari/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HIKARI_DECLS_H
#define MAGIC_HIKARI_DECLS_H

#include "main/decls.h"
void func_801B0124(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern u16 D_801B8920;
extern s32 D_801517C0;
extern u8 *D_801D0924;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B8848;
void func_801B0610(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_80151918[][0xB9C];
void func_801B01E0(void);
void func_801B0698(s32 arg0, s32 arg1);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B072C;
extern M2C_UNK D_801B4804;
void func_801B006C(void);
extern s32 D_801B4770;
extern u16 D_801B8914;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; u16 unk4; u16 unk6; u16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgHikariObj;
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8(void);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
void func_8003C21C(MgSVec *, MgMat *);
M2C_UNK func_800D5138(M2C_UNK);
M2C_UNK func_800D51D4(M2C_UNK);
M2C_UNK func_800D5774(s16);
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
extern s16 D_800F5B74;
extern u8 D_80151909[][0xB9C];
extern u8 D_8015190F[][0xB9C];
extern s16 D_801D0928[];

#endif /* MAGIC_HIKARI_DECLS_H */
