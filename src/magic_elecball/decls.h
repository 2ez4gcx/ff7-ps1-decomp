/* Declarations the C of src/magic_elecball/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ELECBALL_DECLS_H
#define MAGIC_ELECBALL_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0E98();
void func_801B0B10(s16 arg0, s16 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
void func_801B0694(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B0B64(void);
extern s16 D_8015169C;
extern u8 D_801D11E4[];
extern u8 *D_801EF1E4;
extern s16 D_80162080;
void func_801B00E8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec unk8; MgSVec unk10; u8 pad18[8]; } MgObjVel;
extern u8 D_80062D98;
void func_801B0020(void);
void func_801B0518(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s8 D_801D11D0;
extern s8 D_801D11D1;
extern s8 D_801D11D2;
extern s16 D_801D11D4[];
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B02FC(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D6260(void *, s32, s32, u8 *);
extern u8 D_801D11BC[];
extern u8 D_801D11C4;
extern u8 D_801D11C5;
extern u8 D_801D11C6;
void func_800D2980(void *, s32, s32, s32);
extern u8 D_801B0F18[];
void func_801B0D4C(void);
extern s16 D_801D11A8[];
MgMat *func_800D4368(void *, s16, s32);
void func_801B01C0(void);
extern u8 D_801D11B4;
extern u8 D_801D11B5;
extern u8 D_801D11B6;
extern u8 D_801D11AC[];
void func_800D3994(s32, s32, void *);
void func_800D5444(s32, s32, s32, void (*)(s16, s16));
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
extern u16 D_801518F6[][0x5CE];
extern u8 D_8015190F[][0xB9C];
void func_801B0BD0(void);
extern s8 D_801D11DC;
extern s8 D_801D11DD;
extern s8 D_801D11DE;
extern s16 D_801D11E0[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec unk8; MgSVec unk10; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } ElTask;
void func_800D5774(s32);

#endif /* MAGIC_ELECBALL_DECLS_H */
