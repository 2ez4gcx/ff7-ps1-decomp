/* Declarations the C of src/magic_esna/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ESNA_DECLS_H
#define MAGIC_ESNA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B051C();
void func_801B04BC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B483C[];
extern u8 *D_801D483C;
extern s16 D_80162080;
void func_801B0404(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D3994(s32, u8, u8 *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(u8 *);
extern u8 D_8015190F[][0xB9C];
extern s32 D_801B4838;
void func_801B01E0(void);
s32 func_800D5444(s32, M2C_UNK, s32, M2C_UNK *);
s32 func_800D54BC(s32);
s32 func_800D574C(s32);
extern s32 D_801B4834;
extern M2C_UNK D_801B05F4;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec unk8; MgSVec unk10; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgObjAlm;
s32 func_80042DA8(void);
M2C_UNK func_800D5774(s32);
extern u8 D_80062D98;
extern s16 D_801B4826[];
void func_801B0020(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern s32 D_801517C0;
extern u8 D_801B481C;
extern u8 D_801B481D;
extern u8 D_801B481E;
extern u8 D_801B4814[];
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_800D4368(MgSVec *, s32, s32);
u8 *func_800D6260(u8 *, s32, s32, u8 *);

#endif /* MAGIC_ESNA_DECLS_H */
