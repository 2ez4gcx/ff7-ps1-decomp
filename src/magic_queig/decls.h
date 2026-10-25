/* Declarations the C of src/magic_queig/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_QUEIG_DECLS_H
#define MAGIC_QUEIG_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B33B4();
s32 func_801B0DBC(s32 a);
extern s16 D_801CCC60[];
s32 func_801B0E60(s32 a);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B3430;
extern MgTask D_80162978[];
extern MgTask *D_801E5550;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B318C;
extern s32 D_801E5554;
void func_801B1AE0(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_800D4284(void *, s32, void *);
s32 func_800D6260(void *, s32, s32, s32);
extern s16 D_8015169C;
extern s32 D_801517C0;
extern s32 D_801E554C;
extern u8 D_80062D98;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern u8 D_801CD468[];
extern s32 D_801CD46C;
extern u16 D_801CD474;
extern u16 D_801CD47C;

#endif /* MAGIC_QUEIG_DECLS_H */
