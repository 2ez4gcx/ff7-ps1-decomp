/* Declarations the C of src/magic_tsurara/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TSURARA_DECLS_H
#define MAGIC_TSURARA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0C38();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u8 D_801D1B4C[];
extern u8 *D_801E9B4C;
extern s16 D_80162080;
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
void func_801B0B78(s32 arg0, s32 arg1);
M2C_UNK func_800BBEAC(void (*)());
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern M2C_UNK func_801B06D0;
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
extern M2C_UNK D_801B0CDC;
void func_801B0304(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s32 D_801D18C4;
extern u16 D_801D1AA4;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgMat D_800FA63C;
extern s16 D_801D1B0C[];
extern s16 D_801D1B14;
extern s16 D_801D1B1C;
extern MgVec D_801D1B20;
MgMat *func_801B00B0(MgSVec *arg0, MgSVec *arg1, s16 arg2);
void func_801B03F0(void);
typedef struct { s32 tag; } TsFrame;
typedef struct { u16 v; } MgHalf;
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgVec D_801D1AAC;
extern TsFrame D_801D1ABC;
extern s32 D_801D1ACC[];
void func_801B058C(void);
void func_8003B69C(s32, s32, s32);
extern MgMat D_801D1ADC;
extern u16 D_801D1B06;
void func_801B01A8(void);
typedef struct { s32 tag; u8 r; u8 g; u8 b; u8 code; } MgColTag;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
extern s32 D_80163C74;
extern MgColTag D_801D1A88;
extern s32 D_801D1A94[];

#endif /* MAGIC_TSURARA_DECLS_H */
