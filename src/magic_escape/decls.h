/* Declarations the C of src/magic_escape/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ESCAPE_DECLS_H
#define MAGIC_ESCAPE_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0E60(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_801B0020(void);
M2C_UNK func_801B009C();
extern M2C_UNK func_801B063C;
void func_801B0E00(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_800F8380;
extern s16 D_8015169C;
extern u8 D_80151909[][0xB9C];
extern MgTask D_80162978[];
typedef struct { u8 pad[0x5C]; u16 x; u16 y; } EscapeEnv;
extern EscapeEnv *D_801517C0;

#endif /* MAGIC_ESCAPE_DECLS_H */
