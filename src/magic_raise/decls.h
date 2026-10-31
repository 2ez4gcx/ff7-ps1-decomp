/* Declarations the C of src/magic_raise/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_RAISE_DECLS_H
#define MAGIC_RAISE_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
extern s32 D_801DBD1C;
s32 func_801B0C3C();
extern M2C_UNK D_801B8874;
M2C_UNK *func_801B0084(void);
void func_801B1FF8();
M2C_UNK *func_801B00B4(void);
M2C_UNK *func_801B00E8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B2084;
extern MgTask D_80162978[];
extern MgTask *D_801DBD0C;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B1D04(void);
extern s32 D_801DBD10;
extern s32 D_801DBD18;
s32 func_800BBEAC(M2C_UNK *);
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
void func_801B09FC(void);
void func_801B0270(void);
M2C_UNK func_800D4368(s16 *, s16, s32);
s32 func_800D6260(s8 *, s32, M2C_UNK, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern s8 D_801C3CF0;
extern s16 D_801C3CFA;
extern s32 D_801DBD08;
void func_801B0DF4(void);
s32 func_800D4D90(s8 *, s32, M2C_UNK, s32);
extern s8 D_801C3D00;
extern s8 D_801C3D01;
extern s8 D_801C3D02;
void func_801B0CCC(void);
typedef struct { u8 b[8]; } RaB8;
MgTask *func_800D4FA8(s32);
extern u16 D_80153D22[];
void func_801B011C(void);
extern s8 D_801C3CE0;
extern s16 D_801C3CEA;
void func_801B037C(void);
void func_801B0F08(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
M2C_UNK func_8003A63C(M2C_UNK *, M2C_UNK *, M2C_UNK *);
M2C_UNK func_8003B35C(M2C_UNK *, s32 *);
M2C_UNK func_8003B48C(M2C_UNK *);
M2C_UNK func_8003B51C(M2C_UNK *);
M2C_UNK func_8003BF8C(u16 *, M2C_UNK *);
s32 func_800D29D4(M2C_UNK, s32, M2C_UNK, s32);
extern M2C_UNK D_800FA63C;
extern M2C_UNK D_801B8140;
void func_801B07A4(void);
s32 func_80042DA8(void);
void func_801B04F0(void);
void func_8003A08C(MgVec *, MgVec *);
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_80151A46[][0xB9C / 2];
extern u16 D_80151A4E[][0xB9C / 2];
extern s32 D_801DBD14;
extern M2C_UNK func_801B10D0;
void func_801B14BC(void);
void func_801B18D8(void);
extern u8 D_80151919[][0xB9C];
extern s16 D_801518F6[][0x5CE];
void func_800D5774(s32);

#endif /* MAGIC_RAISE_DECLS_H */
