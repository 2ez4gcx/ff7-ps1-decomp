/* Declarations the C of src/magic_q_shu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_Q_SHU_DECLS_H
#define MAGIC_Q_SHU_DECLS_H

#include "main/decls.h"
void func_801B007C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
void func_800D4368(void *, s32, s32);
extern u16 D_801BDA98;
extern s32 D_801517C0;
extern s32 D_801D5AE8;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801BD9CC;
void func_801B03FC(void);
extern u16 D_801BDAC4;
extern s32 D_801BD84C;
void func_801B0F5C(s32 arg0, s32 arg1);
void func_801B0C5C(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B1028();
extern u8 D_801B0010[];
extern u8 D_801B10A4[];
void func_801B0138(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 unk0; s32 unk4; } MgAnim;
extern MgAnim *D_801BDAA8[];
extern s16 D_801BDAA4[];
void func_801B0264(void);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
extern s32 D_801BD8E4;
extern s16 D_801BDAB8;
void func_801B04B4(void);
s32 func_80042DA8();
extern s32 D_801BD9AC;
extern s16 D_801BDAD0;
void func_801B08E0(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003C21C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern MgMat D_800FA63C;
extern MgScratch D_801B0000;
extern u16 D_801BDAD4;
extern MgVec D_801BDAD8;
void func_800BBA84(s32, s32, s32);
void func_800D5774(s32);
extern s16 D_801518F4[][0x5CE];

#endif /* MAGIC_Q_SHU_DECLS_H */
