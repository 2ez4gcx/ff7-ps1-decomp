/* Declarations the C of src/magic_beast/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BEAST_DECLS_H
#define MAGIC_BEAST_DECLS_H

#include "main/decls.h"
s32 func_801B0054(void);
M2C_UNK func_801B13EC();
void func_801B0408(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
s32 func_800D29D4(void *, s32, s32, s32);
void func_800D4368(void *, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgTask D_80162978[];
extern u8 D_801C2ECC[];
extern s32 D_801C3498[];
extern s32 D_801DB4B0;

#endif /* MAGIC_BEAST_DECLS_H */
