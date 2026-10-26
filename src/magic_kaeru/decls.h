/* Declarations the C of src/magic_kaeru/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KAERU_DECLS_H
#define MAGIC_KAERU_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0D08();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0150(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern M2C_UNK D_801B0000;
void func_801B0B68(void);
extern M2C_UNK D_801B0DDC;
extern MgObj20 *D_801D5294;
extern s32 D_801D5298;
extern s32 D_801D529C;
void func_801B048C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801BD268[];
extern struct { u16 v; } D_801BD270;
extern s32 D_801D5290;
extern u8 D_801D52A0[];
extern u8 D_801D52A6[];
extern MgTask D_80162978[];
void func_801B05A8(void);
s32 func_80042DA8();
s32 func_800D56A8(void *);
M2C_UNK func_800D5774(s32);
extern u8 D_801D52A4[];
void func_801B0838(void);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
extern u8 D_801BD274[];
extern u8 D_801BD278;
extern u8 D_801BD279;
extern u8 D_801BD27A;
extern MgMat D_801D5990;
void func_801B09E8(void);
typedef struct { u8 b[8]; } KrB8;
extern s16 D_80158D00;
extern s16 D_80158D04;
extern MgVec D_801BD280;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];

#endif /* MAGIC_KAERU_DECLS_H */
