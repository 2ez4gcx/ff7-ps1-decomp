/* Declarations the C of src/magic_geki1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GEKI1_DECLS_H
#define MAGIC_GEKI1_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0E5C();
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
extern s32 D_80163C74;
extern struct { s32 *unk0; s32 unk4; s16 unk8; } D_801BD488;
extern s32 *D_801BD494[];
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BD4CC[];
extern s32 D_801D54CC;
extern s16 D_80162080;
void func_801B0180(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern u16 D_801BD4A4;
extern s32 D_801BD3C4;
void func_800D4368(MgSVec *, s32, s32);
void func_801B0238(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgMat D_800FA63C;
extern u8 D_801BD4AC;
extern u8 D_801BD4AD;
extern u8 D_801BD4AE;
extern u8 D_801BD4AF;
extern u16 D_801BD4B0;
void func_801B0D98(s32 arg0, s32 arg1);
extern u8 D_8015190F[][0xB9C];
extern u8 D_801D54D0[];
void func_800D3994(s32, s32, void *);
void func_801B0854();
void func_801B0468(void);
M2C_UNK func_8003A63C(MgMat *, MgMat *, MgMat *);
M2C_UNK func_8003A79C(MgMat *, MgMat *, MgMat *);
M2C_UNK func_8003B35C(MgMat *, MgVec *);
s32 func_800D29D4(u8 *, s32, s32, s32);
M2C_UNK func_800D44E8(MgSVec *, MgMat *);
extern MgSVec D_801BD4B4;
extern s16 D_801BD4C6;
extern u16 D_801D54D4;

#endif /* MAGIC_GEKI1_DECLS_H */
