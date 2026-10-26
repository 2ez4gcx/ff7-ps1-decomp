/* Declarations the C of src/magic_berserk/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BERSERK_DECLS_H
#define MAGIC_BERSERK_DECLS_H

#include "main/decls.h"
void func_801B0018(void);
s32 func_801B07D0();
void func_801B0764(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
extern u8 D_801D1334[];
extern u8 *D_801EF334;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, s32, M2C_UNK *);
s32 func_800D54BC();
extern M2C_UNK D_801B0858;
void func_801B06B0(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(void *);
M2C_UNK func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151A4C[][0xB9C];
void func_801B0454(void);
void func_801B034C(void);
typedef struct { s32 anim; s32 rgbc; u16 frame; u16 pad; } BsSpr;
M2C_UNK func_800D4368(void *, M2C_UNK, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern BsSpr D_801B000C;
typedef struct { u8 b[8]; } BsB8;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8(void);
extern u16 D_801518F6[][0x5CE];
void func_801B0038(void);
void func_801B0228(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u8 D_801D131C[];
extern struct { s16 v; } D_801D1324;
extern s16 D_801D1326;
extern struct { s16 v; } D_801D1328;
extern MgSVec D_801D132C;
typedef struct { s32 anim; u8 r; u8 g; u8 b; u8 code; u16 frame; u16 pad; } BsSprC;
extern BsSprC D_801B0000;
u8 *func_800D4D90(BsSprC *, s32, M2C_UNK, u8 *);

#endif /* MAGIC_BERSERK_DECLS_H */
