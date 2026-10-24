/* Declarations the C of src/magic_thundg1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_THUNDG1_DECLS_H
#define MAGIC_THUNDG1_DECLS_H

#include "main/decls.h"
void func_801B000C(void);
M2C_UNK func_801B0F00();
void func_801B0E0C(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0890(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);

#endif /* MAGIC_THUNDG1_DECLS_H */
