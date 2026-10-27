/* Declarations the C of src/magic_brand/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BRAND_DECLS_H
#define MAGIC_BRAND_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0020(void);
s32 func_801B0C38();
extern M2C_UNK D_801B5148;
void func_801B0BD8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B6DFC[];
extern u8 *D_801D6DFC;
extern s16 D_80162080;
void func_801B0048(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_8003B35C(M2C_UNK, M2C_UNK *);
M2C_UNK func_8003C21C(void *, M2C_UNK);
M2C_UNK func_800D4284(s16 *, s16, M2C_UNK);
u8 *func_800D4D90(void *, s32, M2C_UNK, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u8 D_801B6D98;
extern u8 D_801B6D99;
extern u8 D_801B6D9A;
extern u8 D_801B6D9B;
extern u16 D_801B6D9C;
extern M2C_UNK D_801B6DA0;
void func_801B01B0(void);
typedef struct { M2C_UNK *a; s32 pad; u16 f; } BrFrame;
M2C_UNK func_800D4368(s16 *, M2C_UNK, s16);
extern M2C_UNK D_801B4FB8;
extern u8 D_801B4FBC;
extern M2C_UNK D_801B5080;
extern BrFrame D_801B6DB0;
void func_801B02A8(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern s16 D_801B6DC6;
extern MgMat D_801B0000;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_801B0404(void);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_800BBEAC(M2C_UNK *);
void func_801B0540(void);
extern M2C_UNK D_801B6DCC;
extern s16 D_801B6DD6;
extern MgMat D_801B6DDC;
void func_801B06C4(void);
typedef struct { u8 b[8]; } BrB8;
void func_800D5138(s32);
void func_800D51D4(s32);
void func_800D5774(s32);
s32 func_80042DA8();
void func_801B0A8C(s32 arg0);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
void func_801B0B2C(void);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(s16 *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
s32 func_800D54EC(s32, void *);
extern M2C_UNK D_8016297C;
extern M2C_UNK D_801B0CD0;

#endif /* MAGIC_BRAND_DECLS_H */
