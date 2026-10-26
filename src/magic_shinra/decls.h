/* Declarations the C of src/magic_shinra/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SHINRA_DECLS_H
#define MAGIC_SHINRA_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B0950();
extern M2C_UNK D_801BAD68;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u8 D_801BC8C0[];
extern s32 D_801CC8C0;
extern s16 D_80162080;
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D54EC(s32, M2C_UNK *);
void func_801B0664();
extern u8 D_800FAFDC;
extern M2C_UNK D_801B09F0;
extern s16 D_801CC8C4;
extern M2C_UNK D_801CC8C8;
void func_801B0504(void);
s32 func_800C4FC8(s16, s16, s16);
extern u8 D_80062D98;
extern s32 D_80163C74;
extern u16 D_801BC8BC;
extern u16 D_801BC8BE;
void func_801B0088(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern s32 D_801517C0;
extern MgMat D_800FA63C;
extern MgSVec D_801BC878;
extern s16 D_801BC88A;
void func_801B01E8(void);
s32 func_80039A74(s32);
void func_8003C8DC(s32, MgMat *);
extern MgSVec D_801B9048[];
extern MgSVec D_801BA5C8[];
extern MgSVec D_801BA998[];
extern u16 D_801BC890;
extern s32 D_801BC894;
extern s32 D_801BC898;
extern s32 D_801BC89C;
extern s16 D_801BC8A6;
extern s32 D_801BC8B0;
extern s16 D_801BC8B6;

#endif /* MAGIC_SHINRA_DECLS_H */
