/* Declarations the C of src/magic_faiga2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FAIGA2_DECLS_H
#define MAGIC_FAIGA2_DECLS_H

#include "main/decls.h"
void func_801B0084(void);
s32 func_801B1770();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern MgTask D_80162978[];
extern MgTask *D_801DBAC0;
extern s32 D_801DBAC4;
extern u8 D_801B0030[];
extern u8 D_801B1808[];
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D574C(s32);
s32 func_800D55F4(s32, s32, s32);
void func_801B162C(void);
void func_801B0BD0(void);
void func_800D4368(void *, s32, s32);
void func_8003B69C(s32, s32, s32);
s32 func_801B0B08(void *, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801C1928[];
extern u8 *D_801DBABC;
void func_801B128C(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 D_801C2D04[];
void func_801B1128(void);
M2C_UNK func_800D5138(s32);
M2C_UNK func_800D51D4(s32);
void func_801B0D0C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BF8C(MgSVec *, MgMat *);
extern MgMat D_800FA63C;
extern u8 D_801C32E0[];
void func_801B0EF4(void);
typedef struct { u8 b[8]; } MgB8;
typedef struct { u8 v; } MgByte;
M2C_UNK func_800D5774(s32);
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
extern struct { s16 v; } D_800F5B74;
void func_801B13C4(void);
s32 func_80042DA8();
void func_800D54EC(s32, void *);
typedef struct { u32 addr : 24; u32 len : 8; } FgTag;
typedef struct { FgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s32 xy0; s32 uvclut0; s32 xy1; s32 uvtp1; s32 xy2; u16 uv2; u16 pad; } FgPolyFT3;
typedef struct { u8 pad0[4]; FgTag *ot; s32 shift; FgPolyFT3 *prim; s32 w10; s32 area; u8 pad18[4]; s32 otz; u8 pad20[4]; s32 w24; u8 pad28[4]; MgSVec v2C; MgSVec v34; MgSVec v3C; } FgPolyCtx;
typedef struct { u16 idx[3]; u8 col; u8 pad7; s32 w8; u16 uv1; u16 uv2; } FgPolyEnt;
FgPolyEnt *func_801B00A4(FgPolyCtx *arg0, u8 *arg1, u16 *arg2, s32 arg3);
typedef struct { FgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s32 xy0; s32 uvclut0; s32 xy1; s32 uvtp1; s32 xy2; u16 uv2; u16 pad; s32 xy3; u16 uv3; u16 pad2; } FgPolyFT4;
typedef struct { u8 pad0[4]; FgTag *ot; s32 shift; FgPolyFT4 *prim; s32 w10; s32 area; u8 pad18[4]; s32 otz; u8 pad20[4]; s32 w24; u8 pad28[4]; MgSVec v2C; MgSVec v34; MgSVec v3C; MgSVec v44; } FgQuadCtx;
typedef struct { u16 idx[4]; s32 w8; u16 uv1; u16 uv2; u16 uv3; u8 col; u8 pad13; } FgQuadEnt;
FgQuadEnt *func_801B0308(FgQuadCtx *arg0, u8 *arg1, u16 *arg2, s32 arg3);
typedef struct { FgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s32 xy0; s32 c1; s32 xy1; s32 c2; s32 xy2; } FgPolyG3;
typedef struct { u8 pad0[4]; FgTag *ot; s32 shift; FgPolyG3 *prim; u8 pad10[4]; s32 area; u8 pad18[4]; s32 otz; u8 pad20[0xC]; MgSVec v2C; MgSVec v34; MgSVec v3C; } FgG3Ctx;
typedef struct { u16 idx[3]; u16 pad6; s32 c0; s32 c1; s32 c2; } FgG3Ent;
FgG3Ent *func_801B05CC(FgG3Ctx *arg0, u8 *arg1, s32 *arg2, s32 arg3);
typedef struct { FgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s32 xy0; s32 c1; s32 xy1; s32 c2; s32 xy2; s32 c3; s32 xy3; } FgPolyG4;
typedef struct { u8 pad0[4]; FgTag *ot; s32 shift; FgPolyG4 *prim; u8 pad10[4]; s32 area; u8 pad18[4]; s32 otz; u8 pad20[0xC]; MgSVec v2C; MgSVec v34; MgSVec v3C; MgSVec v44; } FgG4Ctx;
typedef struct { u16 idx[4]; s32 c0; s32 c1; s32 c2; s32 c3; } FgG4Ent;
FgG4Ent *func_801B082C(FgG4Ctx *arg0, u8 *arg1, u16 *arg2, s32 arg3);

#endif /* MAGIC_FAIGA2_DECLS_H */
