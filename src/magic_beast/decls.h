/* Declarations the C of src/magic_beast/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BEAST_DECLS_H
#define MAGIC_BEAST_DECLS_H

#include "main/decls.h"
s32 func_801B0054(void);
s32 func_801B13EC();
void func_801B0408(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
s32 func_800D29D4(void *, s32, s32, s32);
void func_800D4368(void *, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgTask D_80162978[];
extern u8 D_801C2ECC[];
extern s32 D_801C3498[];
extern s32 D_801DB4B0;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_801B1488;
extern MgTask *D_801DB4B4;
extern s32 D_801DB4B8;
extern s32 D_801DB4BC;
extern s32 D_801DB4C8;
extern s32 D_801DB54C;
void func_801B1320(void);
extern u8 D_801B0000[];
void func_801B0AC8(void);
typedef struct { u8 b[8]; } MgB8;
s32 func_80042DA8(void);
void func_801B0D5C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_800D3994(s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_800D5774(s32);
void func_8003BF8C(MgSVec *, MgMat *);
MgVec *func_8003AB84(MgMat *, MgVec *, MgVec *);
void func_801B0550(void);
extern u8 D_8015190F[][0xB9C];
extern MgSVec D_801DB4C0;
extern u16 D_801DB4CC[][4];
extern MgMat D_801C3488;
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
typedef struct { u16 v; } MgHalf;
extern MgHalf D_800F5B74;
typedef struct { void *unk0; s32 unk4; s32 unk8; s32 unkC; u8 pad[0xBC]; s32 unkCC; s32 unkD0; u8 pad2[8]; u8 unkDC; u8 unkDD; u8 unkDE; u8 pad3; u8 unkE0; u8 unkE1; u8 unkE2; } BsScr;
s32 func_800D574C(s32);
void func_8003B16C(MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_80039A74(s32);
s32 func_801B0398(void *);
extern MgMat D_800FA63C;
extern u8 D_801C15A8[];

#endif /* MAGIC_BEAST_DECLS_H */
