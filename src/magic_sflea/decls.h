/* Declarations the C of src/magic_sflea/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SFLEA_DECLS_H
#define MAGIC_SFLEA_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B1D3C();
void func_801B0BC4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
void func_800D4368(void *, s32, s32);
extern u16 D_801D3C80;
extern s32 D_801517C0;
extern s32 D_801EBD50;
extern u16 D_801D3C48[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B0C90(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_801D3C8C[];
extern s8 D_801D3C8A;
extern s8 D_801D3C89;
extern s8 D_801D3C88;
extern u8 D_801D3C84[];
void func_801B0074(s32 arg0, s32 arg1, s32 arg2);
typedef struct { u32 addr : 24; u32 len : 8; } SfTag;
typedef struct { u8 pad[0x406C]; SfTag head; } SfOt;
typedef struct { SfTag tag; u32 c0; s32 xy0; s32 xy1; s32 xy2; s32 xy3; } SfPoly;
void func_801B0144(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern MgMat D_800FA63C;
s32 func_800D29D4(void *, s32, s32, s32);
extern M2C_UNK D_801D27D0;
void func_801B0304(void);
extern M2C_UNK D_801D39F4;
void func_801B04BC(void);
void func_801B0674(void);
extern u8 D_801D3C64[];
extern u8 D_801D3C65;
extern u8 D_801D3C66;
extern u16 D_801D3C68;
void func_801B0A3C(void);
extern u8 D_801D3C70[];
extern u8 D_801D3C71;
extern u8 D_801D3C72;
extern s16 D_801D3C74;
s32 func_801B17C8(void);
typedef struct { u8 b[8]; } MgB8;
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
extern s32 D_801EBD58;
s32 func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
s32 func_800D56A8(void *);
s32 func_800D55F4(s32, s32, s32);
void func_801B0F7C(void);
void func_801B0E10(void);
void func_801B07C8(void);
typedef struct { SfTag tag; u32 rgbc; s32 xy0; u16 uv0; u16 clut; s32 xy1; u16 uv1; u16 tpage; s32 xy2; u16 uv2; u16 pad2; s32 xy3; u16 uv3; u16 pad3; } SfFT4;
s32 func_8003BD7C(MgSVec *, MgSVec *, MgSVec *, MgSVec *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
void func_800D2980(M2C_UNK *, s32, s32, s32);
extern u8 D_800F5B70[];
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B1E10;
extern MgObj20 *D_801EBD54;
extern u8 D_801EBD5F;
void func_801B1938(void);

#endif /* MAGIC_SFLEA_DECLS_H */
