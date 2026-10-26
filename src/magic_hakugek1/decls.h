/* Declarations the C of src/magic_hakugek1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HAKUGEK1_DECLS_H
#define MAGIC_HAKUGEK1_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B1290();
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0020(s16 mask, MgSVec *out);
void func_801B01CC(s32 base, s16 range, MgSVec *out);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80042DA8(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B02FC(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist);
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_801B045C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D2A80[];
extern u8 *D_801EAA80;
extern s16 D_80162080;
s32 func_800BBEAC(void *);
extern M2C_UNK D_801B12FC;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B11B4(s32 arg0, s32 arg1);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800BBA84(s32, s32, s32);
void func_801B0D84(void);
void func_801B04C8(void);
extern u16 D_801D2A38[];
extern s32 D_801D296C;
extern s32 D_801517C0;
extern u8 D_80062D98;
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B062C(void);
extern s32 D_80163C74;
extern s16 D_801D2A44[];
extern s32 D_801D2A48[];
extern s8 D_801D2A40[];
void func_801B0878(void);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
void func_8003B69C(s32, s32, s32);
extern s16 D_801D2A5E;
void func_801B09F0(void);
typedef struct { s32 v; } HakuWord;
typedef struct { void *p; } HakuPtr;
extern s32 D_801D2A68;
extern s16 D_801D2A6E;
extern u8 D_801D139C;
extern u8 D_801D1708;
extern u8 D_801D1B14;
extern u8 D_801D20E4;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_8003CC1C(s32, s32);
void func_800D5774(s32);
extern u8 D_8015191A[][0xB9C];
extern u16 D_801D2A74[];

#endif /* MAGIC_HAKUGEK1_DECLS_H */
