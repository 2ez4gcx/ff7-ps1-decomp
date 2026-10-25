/* Declarations the C of src/magic_blaver/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BLAVER_DECLS_H
#define MAGIC_BLAVER_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B0730();
extern M2C_UNK D_801B07A0;
void func_801B067C(s16 arg0, s16 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern MgObj20 D_80162978[];
void func_801B04C0(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B15A8;
void func_801B06D0(void);
extern s16 D_8015169C;
extern u8 D_801BEAD4[];
extern u8 *D_801DEAD4;
extern s16 D_80162080;
void func_801B03F4(void);
typedef struct { s16 unk0; u16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } BvTask;
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s32 D_801BE8C8;
extern u8 D_801BE9C8[];
extern s16 D_801BE9D0;
void func_801B0028(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003B48C(void *);
void func_8003B51C(void *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
extern u8 D_800FA6E0[][0x40];
extern s32 D_801BE62C;
extern s16 D_801BE97C[];
extern MgSVec D_801BE980;
extern MgVec D_801BE99C;
M2C_UNK func_800D3994(s32, u8, void *);
M2C_UNK func_800D5138(M2C_UNK);
M2C_UNK func_800D51D4(M2C_UNK);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(void *);
M2C_UNK func_800D5774(s32);
extern u8 D_801518F6[][0xB9C];
extern u8 D_8015190F[][0xB9C];
void func_801B014C(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { MgSVec a; MgSVec b; } BvTrail;
typedef struct { s32 tag; s32 rgbc; s32 xy0; u16 uv0; u16 clut; s32 xy1; u16 uv1; u16 tpage; s32 xy2; u16 uv2; u16 pad2; s32 xy3; u16 uv3; u16 pad3; } BvFT4;
s32 func_8003BD7C(void *, void *, void *, void *, void *, void *, void *, void *, void *, s32 *);
void func_800D41FC(void *, void *, MgMat *);
extern u8 D_800FA63C[];
extern s32 D_801B15A0;
extern MgSVec D_801BE9B0;
extern BvTrail D_801BE9D4[];

#endif /* MAGIC_BLAVER_DECLS_H */
