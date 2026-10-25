/* Declarations the C of src/magic_gravide/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GRAVIDE_DECLS_H
#define MAGIC_GRAVIDE_DECLS_H

#include "main/decls.h"
void func_801B0730(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B07A0;
void func_801B0568(s32 arg0, s32 arg1);
void func_801B06C4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D0A64[];
extern u8 *D_801EEA64;
extern s16 D_80162080;
void func_801B0000(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_800D4368(void *, s32, s32);
void func_800D4484(s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801D0A48;
void func_801B00F0(void);
extern s16 D_801D0A4C;
void func_801B01F4(void);
extern s16 D_801D0A60;
void func_800D3994(s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151A4C[][0xB9C];
void func_801B02E8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec pos; MgSVec vel; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgObjGrav;
void func_800D5774(s32);

#endif /* MAGIC_GRAVIDE_DECLS_H */
