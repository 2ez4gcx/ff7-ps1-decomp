/* Declarations the C of src/magic_kyogiri/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KYOGIRI_DECLS_H
#define MAGIC_KYOGIRI_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B069C(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0714;
extern M2C_UNK D_801B14CC;
void func_801B059C(s32 arg0);
void func_801B063C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B3620[];
extern u8 *D_801D3620;
extern s16 D_80162080;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D3994(s32, u8, s16 *);
extern u8 D_8015190F[][0xB9C];
extern u8 D_801518F6[][0xB9C];
void func_801B0348(void);
void func_801B0000(void);
typedef struct { s32 tag; u8 r; u8 g; u8 b; u8 code; s16 f; } KyoPrim;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_800D4284(void *, s32, MgMat *);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
void func_801B0168(void);
typedef struct { s16 v[4]; } KyoCopy;
void func_800D4368(void *, s16, s32);
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);
M2C_UNK func_800D5774(s32);
extern u8 D_801B350C[];
extern u8 D_801B352C[];
extern u8 D_801B3588[];

#endif /* MAGIC_KYOGIRI_DECLS_H */
