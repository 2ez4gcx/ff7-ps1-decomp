/* Declarations the C of src/magic_graviga1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GRAVIGA1_DECLS_H
#define MAGIC_GRAVIGA1_DECLS_H

#include "main/decls.h"
void func_801B00E8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec unk8; MgSVec unk10; u8 pad18[8]; } MgObjVel;
extern s16 D_8015169C;
extern u8 D_80062D98;
extern MgObj20 D_80162978[];
void func_801B0000(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B1348(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0E54(void);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B13D4(void);
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
extern s16 D_80162080;
extern u8 D_801D1A84[];
extern u8 *D_801EFA84;
void func_801B1464(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B14F4;
extern u8 D_801D17B4[];
s32 func_801B0A34(void);
void func_801B07D8(MgTask *p);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_800D4368(void *, s16, s32);
M2C_UNK func_800D4484(s32, M2C_UNK);
u8 *func_800D4D90(s16 *, s32, M2C_UNK, u8 *);
extern s32 D_801517C0;
extern s16 D_801D1784[];
void func_801B0634(void);
void func_8003B51C(MgMat *);
extern u8 D_801D17AC;
extern u8 D_801D17AD;
extern u8 D_801D17AE;
extern s16 D_801D17B0[];
void func_801B01C0(void);
u8 *func_800D6260(void *, s32, s32, u8 *);
extern u8 D_801D1788[];
extern u8 D_801D1790;
extern u8 D_801D1791;
extern u8 D_801D1792;
s32 func_8003BC0C(void *, void *, void *, void *, void *, void *, void *, void *);
void func_80046794(s32, void *);
void func_801B03A8(void);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern u8 D_801D1798[];
extern u8 D_801D17A0;
extern u8 D_801D17A1;
extern u8 D_801D17A2;
typedef struct { u8 b[8]; } GvBytes8;
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(void *);
void func_800D5774(s32);
extern u16 D_801518F6[][0x5CE];
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
void func_801B0AC8(void);

#endif /* MAGIC_GRAVIGA1_DECLS_H */
