/* Declarations the C of src/magic_konoha/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KONOHA_DECLS_H
#define MAGIC_KONOHA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0704();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BDAA8[];
extern u8 *D_801D5AA8;
extern s16 D_80162080;
s32 func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
extern u8 D_8015190F[][0xB9C];
extern M2C_UNK D_801B07DC;
extern s32 D_801D5AAC;
extern void func_801B03E0();
void func_801B008C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } KoObj;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, void *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, void *, void *);
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003C21C(MgSVec *, MgMat *);
s32 func_80042DA8(void);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s16 D_801BDA78;
extern u8 D_801BDA7C[];
extern s32 D_801BDA90[];
extern struct { s16 v; } D_801BDA96;
extern s32 D_801BDA9C[];

#endif /* MAGIC_KONOHA_DECLS_H */
