/* Declarations the C of src/magic_thundera/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_THUNDERA_DECLS_H
#define MAGIC_THUNDERA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B08F4();
void func_801B0894(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C90EC[];
extern u8 *D_801E90EC;
extern s16 D_80162080;
void func_801B01A0(void);
M2C_UNK func_800D4368(s16 *, M2C_UNK, s16);
u8 *func_800D4D90(M2C_UNK, s32, M2C_UNK, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern M2C_UNK D_801B097C;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern M2C_UNK D_801B0E9C;
void func_801B07F0(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
void func_801B04D8(void);
void func_801B028C(void);
extern s16 D_801C90C4;
void func_801B0020(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(void *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
u8 *func_800D29D4(M2C_UNK, s32, M2C_UNK, u8 *);
extern MgMat D_800FA63C;
extern M2C_UNK D_801B0C08;
void func_801B0348(void);
void func_8003BC6C(s16 *, s32 *, s32 *);
extern MgMat D_801C90C8;
extern M2C_UNK D_801B09B0;
extern M2C_UNK D_801B0A78;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgObjThunder;
void func_800D5774(s32);
s32 func_80042DA8();

#endif /* MAGIC_THUNDERA_DECLS_H */
