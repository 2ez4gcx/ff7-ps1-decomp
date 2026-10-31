/* Declarations the C of src/magic_sennkoku/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SENNKOKU_DECLS_H
#define MAGIC_SENNKOKU_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
s32 func_801B089C();
extern M2C_UNK D_801B0A70;
extern s32 D_801CD5B0;
M2C_UNK *func_801B0084(void);
void func_801B00B8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
MgTask *func_800D4FA8(s32);
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801CD5AC;
void func_800D5774(s32);
void func_801B01C8(void);
typedef struct { s16 x; s16 y; } MgXY;
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { u8 pad0[4]; s32 unk4; s32 unk8; s32 unkC; u8 pad10[0x20]; u8 unk30[0x80]; MgXY p[4]; } MgSenSc;
typedef struct { MgTag tag; s32 col; s32 xy0; s32 unkC; s32 xy1; s32 unk14; s32 xy2; s32 unk1C; s32 xy3; s32 unk24; } MgSenPrim;
extern s32 D_801CD5E8;
extern s32 D_801CD5DC;
extern s32 D_801CD5E0;
extern s32 D_801CD5E4;
extern s32 D_801CD5EC;
extern s32 D_801CD5B4[];
extern s32 D_801B54DC[];
extern s32 D_801B5598;
extern u8 D_8015190F[][0xB9C];
extern u16 D_801CD5A4;
extern u16 D_801CD5A8;
extern u16 D_800D3546;
extern u16 D_800D3544;
extern s32 D_801517C0;
extern MgSenPrim *D_80163C74;
extern MgMat D_800FA63C;
void func_800D3994(s32, s32, void *);
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
extern u8 D_801B0930[];
void func_801B0650(void);
s32 func_80042DA8();
extern u8 D_80151919[][0xB9C];
extern u16 D_80151A46[][0x5CE];
typedef struct { u16 v; } MgHalf;
extern MgHalf D_80163758;
extern MgHalf D_80163766;

#endif /* MAGIC_SENNKOKU_DECLS_H */
