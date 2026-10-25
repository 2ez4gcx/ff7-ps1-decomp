/* Declarations the C of src/magic_comet/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_COMET_DECLS_H
#define MAGIC_COMET_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B1364();
void func_801B1258(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern MgTask D_80162978[];
extern M2C_UNK func_801B0C58;
void func_801B12D8(void);
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
extern s16 D_8015169C;
extern s16 D_80162080;
extern M2C_UNK D_801B13E8;
extern M2C_UNK D_801D34C0;
extern u8 *D_801EB4C0;
void func_801B0020(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_800FA63C;
extern u8 D_80062D98;
extern s32 D_801517C0;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
void func_80046974(void *);
s32 func_80042DA8(void);

#endif /* MAGIC_COMET_DECLS_H */
