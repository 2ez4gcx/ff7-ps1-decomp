/* Declarations the C of src/magic_koudan1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KOUDAN1_DECLS_H
#define MAGIC_KOUDAN1_DECLS_H

#include "main/decls.h"
void func_801B0030(void);
s32 func_801B0AC4();
void func_801B0050(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801CB3D0[];
extern u8 *D_801E33D0;
extern s16 D_80162080;
void func_801B052C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
extern s16 D_801CB3AE[];
extern MgSVec D_801CB3B4;
extern s32 D_801517C0;
extern u8 D_80062D98;
void func_8003B69C(s32, s32, s32);
s32 func_800D29D4(void *, s32, s32, s32);
void func_801B00BC(void);
typedef struct { s32 unk0; s32 unk4; } MgAnim;
void func_800D4368(void *, s16, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern s16 D_801CB388[];
extern MgAnim *D_801CB38C[];
void func_801B09F0(s32 arg0, s32 arg1);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151917[][0xB9C];
extern s16 D_801E33D4;
void func_801B06A4(void);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
extern M2C_UNK D_801B0B6C;
void func_801B01B0(void);
s32 func_80039A74(s32);
extern u8 D_801CAF80[];
extern u8 D_801CAFA0[];
extern u8 D_801CAFC0[];
extern u8 D_801CAFE0[];
extern u8 D_801CB03C[];
extern u8 D_801CB05C[];
extern u8 D_801CB07C[];
extern u8 D_801CB09C[];
extern u8 D_801CB0BC[];
extern u8 D_801CB0DC[];
extern u8 D_801CB0FC[];
extern u8 D_801CB11C[];
extern u8 D_801CB13C[];
extern u8 D_801CB15C[];
extern u8 *D_801CB398[];
M2C_UNK func_800D5774(s32);
s32 func_80042DA8(void);

#endif /* MAGIC_KOUDAN1_DECLS_H */
