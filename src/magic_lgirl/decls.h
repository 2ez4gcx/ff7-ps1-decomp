/* Declarations the C of src/magic_lgirl/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LGIRL_DECLS_H
#define MAGIC_LGIRL_DECLS_H

#include "main/decls.h"
s32 func_801B0054(void);
void func_801B0C9C();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B0D28;
extern MgTask D_80162978[];
extern MgTask *D_801E8EC0;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B0BFC;
extern s32 D_801E8EC4;
extern s32 D_801E8EC8;
typedef struct { s32 head; s32 tail; s32 count; s32 size; s32 last; s32 prev; s32 buf[1]; } MgRing;
void func_801B0078(MgRing *r, s32 v);

#endif /* MAGIC_LGIRL_DECLS_H */
