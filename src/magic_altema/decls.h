/* Declarations the C of src/magic_altema/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ALTEMA_DECLS_H
#define MAGIC_ALTEMA_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0EC4();
void func_801B0E7C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern M2C_UNK func_801B0BBC;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B0F54;
extern MgObj20 *D_801D9EB4;
extern s32 D_801D9EB8;
typedef struct { u32 addr : 24; u32 len : 8; } AtTag;
typedef struct { u8 pad[0x10]; AtTag head; } AtOt;
typedef struct { AtTag tag; u32 c0; s32 xy0; u32 c1; s32 xy1; u32 c2; s32 xy2; u32 c3; s32 xy3; } AtPoly;
typedef struct { AtOt *ot; u8 pad4[4]; AtPoly *buf; u8 padC[0x30]; s32 step; s32 n; s32 color; } AtGrad;
AtPoly *func_801B0580(AtGrad *arg0);
AtPoly *func_801B0650(AtGrad *arg0, s16 arg1);
void func_801B0074(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D6260(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern M2C_UNK D_801C1DEC;
extern s8 D_801C1DF0[];
extern MgMat D_801C1DFC;
extern s16 D_801C1E04[];
extern s32 D_801C1E10[];
extern s32 D_801D9EB0;
void func_801B01E0(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003B35C(MgMat *, MgVec *);
void func_8003BF8C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern M2C_UNK D_801C1074;
void func_801B0420(void);
extern M2C_UNK D_801C1810;
void func_801B0850(void);
void func_800D5774(s32);
extern u8 D_800F5B70[];
extern u16 D_800F5B74;
extern u8 D_800F8380;
extern u16 D_801C1E1C;

#endif /* MAGIC_ALTEMA_DECLS_H */
