/* Declarations the C of src/magic_oil/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_OIL_DECLS_H
#define MAGIC_OIL_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0AC4();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801D4778[];
extern u8 *D_801EC778;
extern s16 D_80162080;
void func_801B0A04(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK func_801B057C;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
extern MgTask D_80162978[];

#endif /* MAGIC_OIL_DECLS_H */
