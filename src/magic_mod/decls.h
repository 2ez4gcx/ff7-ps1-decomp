/* Declarations the C of src/magic_mod/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MOD_DECLS_H
#define MAGIC_MOD_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B1350();
extern M2C_UNK D_801B8FA8;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BA3B0[];
extern u8 *D_801D23B0;
extern s16 D_80162080;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B13BC;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B126C();
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern s16 D_80151A4C[][0x5CE];
void func_801B0CE8(void);
void func_801B0094(void);
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u16 D_801BA268;
extern s32 *D_801BA26C[];
void func_801B081C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003BF8C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u8 D_801BA304[];
extern MgSVec D_801BA314;
void func_801B0B4C(void);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8();
s32 func_80039F5C(s32);
s32 func_8003CC1C(s32, s32);
void func_800D52A0(s32, s32);
s32 func_800D56A8(void *);
void func_800D5774(s32);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
extern MgSVec D_801BA330[];
extern M2C_UNK func_801B01A4;
extern M2C_UNK func_801B0994;

#endif /* MAGIC_MOD_DECLS_H */
