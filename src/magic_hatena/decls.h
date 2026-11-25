/* Declarations the C of src/magic_hatena/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HATENA_DECLS_H
#define MAGIC_HATENA_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B105C();
void func_801B0C50(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s16, M2C_UNK);
s32 func_800D4D90(u16 *, s32, M2C_UNK, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgTask D_80162978[];
extern u16 D_801BB200;
extern s32 D_801D3204;
s32 func_800BBEAC();
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B1128;
extern MgTask *D_801D3208;
extern s32 D_801D320C;
void func_801B0F60(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0A90(void);
void func_801B0D2C(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D56A8(void *);
void func_800D5774(s32);
s32 func_801B09E4();
extern MgMat D_800FA63C;
extern M2C_UNK D_801BA544;
extern s32 D_1F800000[];
void func_8003A08C(MgVec *, MgVec *);
s32 func_80042DA8();
typedef struct { u32 addr : 24; u32 len : 8; } HaTag;
typedef struct { u8 b[8]; } HaB8;
typedef struct { HaTag tag; s32 rgbc; s32 xy0; s32 uvclut0; s32 xy1; s32 uvtp1; s32 xy2; u16 uv2; u16 pad; } HaPolyFT3;
typedef struct { u8 pad0[4]; HaTag *ot; s32 shift; HaPolyFT3 *prim; s32 w10; s32 area; u8 pad18[4]; s32 otz; u8 pad20[4]; s32 cnt; MgSVec v28; MgSVec v30; MgSVec v38; } HaPolyCtx;
typedef struct { u16 idx[3]; u16 pad6; s32 w8; u16 uv1; u16 uv2; } HaPolyEnt;
HaPolyEnt *func_801B0074(HaPolyCtx *arg0, u8 *arg1, u16 *arg2);
typedef struct { HaTag tag; s32 rgbc; s32 xy0; s32 uvclut0; s32 xy1; s32 uvtp1; s32 xy2; u16 uv2; u16 pad; s32 xy3; u16 uv3; u16 pad2; } HaPolyFT4;
typedef struct { u8 pad0[4]; HaTag *ot; s32 shift; HaPolyFT4 *prim; s32 w10; s32 area; u8 pad18[4]; s32 otz; u8 pad20[4]; s32 cnt; MgSVec v28; MgSVec v30; MgSVec v38; MgSVec v40; } HaQuadCtx;
typedef struct { u16 idx[4]; s32 w8; u16 uv1; u16 uv2; u16 uv3; u16 pad12; } HaQuadEnt;
HaQuadEnt *func_801B02AC(HaQuadCtx *arg0, u8 *arg1, u16 *arg2);
typedef struct { HaTag tag; u8 r0; u8 g0; u8 b0; u8 code; s32 xy0; s32 c1; s32 xy1; s32 c2; s32 xy2; } HaPolyG3;
typedef struct { u8 pad0[4]; HaTag *ot; s32 shift; HaPolyG3 *prim; u8 pad10[4]; s32 area; u8 pad18[4]; s32 otz; u8 pad20[4]; s32 cnt; MgSVec v28; MgSVec v30; MgSVec v38; } HaG3Ctx;
typedef struct { u16 idx[3]; u16 pad6; s32 c0; s32 c1; s32 c2; } HaG3Ent;
HaG3Ent *func_801B0544(HaG3Ctx *arg0, u8 *arg1, s32 *arg2);
typedef struct { HaTag tag; u8 r0; u8 g0; u8 b0; u8 code; s32 xy0; s32 c1; s32 xy1; s32 c2; s32 xy2; s32 c3; s32 xy3; } HaPolyG4;
typedef struct { u8 pad0[4]; HaTag *ot; s32 shift; HaPolyG4 *prim; u8 pad10[4]; s32 area; u8 pad18[4]; s32 otz; u8 pad20[4]; s32 cnt; MgSVec v28; MgSVec v30; MgSVec v38; MgSVec v40; } HaG4Ctx;
typedef struct { u16 idx[4]; s32 c0; s32 c1; s32 c2; s32 c3; } HaG4Ent;
HaG4Ent *func_801B0764(HaG4Ctx *arg0, u8 *arg1, u16 *arg2);

#endif /* MAGIC_HATENA_DECLS_H */
