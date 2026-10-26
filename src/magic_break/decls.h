/* Declarations the C of src/magic_break/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BREAK_DECLS_H
#define MAGIC_BREAK_DECLS_H

#include "main/decls.h"
void func_801B0854(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern M2C_UNK D_801B08DC;
void func_801B0758(s32 arg0);
void func_801B07F4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801CD328[];
extern u8 *D_801ED328;
extern s16 D_80162080;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
s32 func_800D55A4(s32);
extern u8 D_8015190F[][0xB9C];
void func_801B05E0(void);
M2C_UNK func_800D5774(s32);
extern u8 D_80062D98;
void func_801B0000(void);
void func_801B024C(void);
void func_801B0440(void);
extern MgTask D_80162978[];
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern MgMat D_801CD2F8;
extern u8 D_801CD318[];
extern s16 D_801CD322;
extern s32 D_801517C0;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003B35C(MgMat *, MgVec *);
extern MgMat D_801CD2D8;
extern u8 D_801CD2C8[];
extern s32 D_801CD2CC;
extern s16 D_801CD2D2;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_8003C21C(MgSVec *, MgMat *);
extern s32 D_1F800028;
extern s32 D_1F800024;
extern MgSVec D_801CD2B0;
extern u8 D_801CD2B8[];
extern s16 D_801CD2C2;

#endif /* MAGIC_BREAK_DECLS_H */
