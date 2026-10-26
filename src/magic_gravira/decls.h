/* Declarations the C of src/magic_gravira/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GRAVIRA_DECLS_H
#define MAGIC_GRAVIRA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0C10();
void func_801B0B50(s16 arg0, s16 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
void func_801B06D4(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B0BA4(void);
extern s16 D_8015169C;
extern u8 D_801D0F40[];
extern u8 *D_801EEF40;
extern s16 D_80162080;
void func_801B0108(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec unk8; MgSVec unk10; u8 pad18[8]; } MgObjVel;
extern u8 D_80062D98;
void func_801B0020(void);
void func_801B0558(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s8 D_801D0F3A;
extern s8 D_801D0F39;
extern s8 D_801D0F38;
extern s16 D_801D0F3C[];
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B033C(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern u8 D_801D0F2E;
extern u8 D_801D0F2D;
extern u8 D_801D0F2C;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
extern u8 D_801D0F24[];
u8 *func_800D6260(void *, s32, s32, u8 *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0C80;
void func_800D4484(s32, s32);
extern s16 D_801D0F10[];
MgMat *func_800D4368(void *, s16, s32);
void func_801B01E0(void);
extern u8 D_801D0F14[];
extern u8 D_801D0F1C;
extern u8 D_801D0F1D;
extern u8 D_801D0F1E;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec pos; MgSVec vel; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } GrObj;
void func_800D3994(s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];
extern struct { u16 v; u8 pad[0xB9A]; } D_801518F6[];

#endif /* MAGIC_GRAVIRA_DECLS_H */
