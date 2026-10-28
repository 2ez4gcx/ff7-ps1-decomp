/* Declarations the C of src/magic_suna/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SUNA_DECLS_H
#define MAGIC_SUNA_DECLS_H

#include "main/decls.h"
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } MgObj8;
extern MgObj8 D_801BA628[];
MgObj8 *func_801B0160(void);
void func_801B006C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern MgTask D_80162978[];
extern s16 D_8015169C;
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u16 D_801BA5F0;
extern s32 *D_801BA5F4[];
extern u8 *D_801D2C6C;
void func_801B0CDC(s32 arg0, s32 arg1);
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B1248;
extern M2C_UNK D_801B9288;
extern s16 D_801BAC68;
extern u8 D_80151917[][0xB9C];
s32 func_800BBEAC(M2C_UNK *);
void func_800BBA84(s32, s32, s32);
void func_800D2980(M2C_UNK *, s32, s32, s32);
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
void func_801B08AC(void);
void func_801B06FC(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u16 D_801BA604;
extern s32 D_801BA60C[];
extern s32 D_801BA610;
extern s16 D_801BA622;
void func_801B052C(void);
s32 func_80042DA8(void);
void func_801B01E0(MgTask *p);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_80046794(s32, void *);
void func_80046974(void *arg0);
s32 func_80039F5C(s32);
s32 func_8003CC1C(s32, s32);
void func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_SUNA_DECLS_H */
