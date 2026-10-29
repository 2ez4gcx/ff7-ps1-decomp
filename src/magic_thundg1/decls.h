/* Declarations the C of src/magic_thundg1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_THUNDG1_DECLS_H
#define MAGIC_THUNDG1_DECLS_H

#include "main/decls.h"
void func_801B000C(void);
void func_801B0F00();
void func_801B0E0C(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0890(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0E98(void);
extern s16 D_8015169C;
extern s16 D_80162080;
extern u8 *D_801D3BE0;
extern u8 D_801D3C90[];
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
M2C_UNK func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_801B0F80;
void func_801B0490(void);
M2C_UNK func_800D4368(void *, M2C_UNK, M2C_UNK);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s32 D_801D16FC;
extern s16 D_801D3C4C;
void func_801B002C(void);
typedef struct { s32 anim; u8 r; u8 g; u8 b; u8 code; u16 frame; u16 pad; } ThSprC;
M2C_UNK func_800D4284(void *, s16, s16 *);
extern ThSprC D_801B0000;
extern s16 D_801D3BE4;
void func_801B0724(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern M2C_UNK D_801D3C60;
extern s16 D_801D3C6A;
extern s16 D_801D3C70;
extern s16 D_801D3C7A[];
extern s32 D_801D3C84[];
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_801B055C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003B35C(MgMat *, MgVec *);
void func_8003C21C(MgSVec *, MgMat *);
extern M2C_UNK D_801D3C50;
extern s16 D_801D3C58[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; u8 unk14[3]; u8 pad17; u8 unk18[3]; u8 pad1B; s16 unk1C; s16 unk1E; } ThBolt;
typedef struct { u8 b[8]; } ThB8;
void func_801B0174(void);
void func_800D52A0(s32, s32);
void func_800D5774(s32);
void func_800D3F0C(MgSVec *, s32, s32);
s32 func_80042DA8(void);
extern u8 D_800F5B70[];
extern u16 D_801518F6[][0x5CE];

#endif /* MAGIC_THUNDG1_DECLS_H */
