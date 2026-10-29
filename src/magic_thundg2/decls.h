/* Declarations the C of src/magic_thundg2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_THUNDG2_DECLS_H
#define MAGIC_THUNDG2_DECLS_H

#include "main/decls.h"
void func_801B000C(void);
s32 func_801B0F1C();
void func_801B0EB4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u8 D_801B0FDC[];
extern u8 D_801D1E8C[];
extern u8 *D_801EDE8C;
extern s16 D_80162080;
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(u8 *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D54EC(s32, M2C_UNK *);
s32 func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK, u8);
void func_801B0908(void);
extern u8 D_800FA6D4;
extern u8 D_801517BC;
extern s32 D_801D1E80;
extern M2C_UNK D_801D1E84;
void func_801B06D0(void);
M2C_UNK func_800D4368(s16 *, M2C_UNK, M2C_UNK);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s32 D_801D1738;
extern s16 D_801D1E4C;
void func_801B079C(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern M2C_UNK D_801D1E50;
extern s16 D_801D1E5A;
extern s16 D_801D1E60;
extern s16 D_801D1E6A[];
extern s32 D_801D1E74[];
void func_801B0540(void);
s32 func_8003B66C();
extern M2C_UNK D_801D17E4;
extern M2C_UNK D_801D1844;
extern M2C_UNK *D_801D1E18;
extern s8 D_801D1E1C;
extern s8 D_801D1E1D;
extern s8 D_801D1E1E;
extern s16 D_801D1E20;
extern s16 D_801D1E24;
extern s32 D_801D1E40;
void func_801B002C(void);
typedef struct { s32 anim; u8 r; u8 g; u8 b; u8 code; u16 frame; u16 pad; } ThSprC;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80042DA8();
M2C_UNK func_800D3F0C(MgSVec *, M2C_UNK, M2C_UNK);
M2C_UNK func_800D4284(void *, s16, s16 *);
extern s16 D_801D1DB8;
extern ThSprC D_801B0000;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; u8 unk14[3]; u8 pad17; u8 unk18[3]; u8 pad1B; s16 unk1C; s16 unk1E; } ThBolt;
typedef struct { u8 b[8]; } ThB8;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_800D52A0(s32, s32);
void func_800D5774(s32);
void func_801B0224(void);
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
extern u16 D_801D1E88;

#endif /* MAGIC_THUNDG2_DECLS_H */
