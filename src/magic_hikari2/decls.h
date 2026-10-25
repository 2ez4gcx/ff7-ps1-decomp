/* Declarations the C of src/magic_hikari2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HIKARI2_DECLS_H
#define MAGIC_HIKARI2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0854();
void func_801B01B4(s16 arg0);
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
extern s16 D_801B8AC8;
extern s16 D_801B8ACA;
void func_801B0120(s16 arg0);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
void func_801B008C(void);
void func_801B02E0(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern s32 D_801B8A04;
extern s16 D_801B8AE0[];
extern u8 *D_801D0AE4;
s32 func_800C4FC8(M2C_UNK, M2C_UNK, s16);
extern s32 D_80163C74;
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern u8 D_801B8AE4[];
extern s16 D_80162080;
extern MgObj20 D_80162978[];
void func_801B0228(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern u16 D_801B8AD4;
extern s32 D_801B492C;
void func_801B07CC(s32 arg0, s32 arg1);
void func_801B039C(void);
extern u8 D_80151918[][0xB9C];
void func_800D3994(s32, s32, void *);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; u16 unk4; u16 unk6; u16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgHikariObj;
s16 func_8003CC1C(s32, s32);
void func_8003C21C(MgSVec *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
extern s16 D_801D0AE8[];
extern s16 D_800F5B74;
extern u8 D_80151909[][0xB9C];
M2C_UNK func_800D5774(s16);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_8015190F[][0xB9C];
s32 func_80042DA8(void);

#endif /* MAGIC_HIKARI2_DECLS_H */
