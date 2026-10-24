/* Declarations the C of src/magic_kinzan/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KINZAN_DECLS_H
#define MAGIC_KINZAN_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0678();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B10B4[];
extern u8 *D_801C90B4;
extern s16 D_80162080;
void func_801B05B4(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK func_801B02B0;
extern M2C_UNK D_801B10AC;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_KINZAN_DECLS_H */
