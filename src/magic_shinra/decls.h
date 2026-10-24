/* Declarations the C of src/magic_shinra/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SHINRA_DECLS_H
#define MAGIC_SHINRA_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
M2C_UNK func_801B0950();
extern M2C_UNK D_801BAD68;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u8 D_801BC8C0[];
extern s32 D_801CC8C0;
extern s16 D_80162080;

#endif /* MAGIC_SHINRA_DECLS_H */
