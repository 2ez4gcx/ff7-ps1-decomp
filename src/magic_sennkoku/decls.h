/* Declarations the C of src/magic_sennkoku/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SENNKOKU_DECLS_H
#define MAGIC_SENNKOKU_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
M2C_UNK func_801B089C();
extern M2C_UNK D_801B0A70;
extern s32 D_801CD5B0;
M2C_UNK *func_801B0084(void);
void func_801B00B8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
MgTask *func_800D4FA8(s32);
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801CD5AC;
void func_800D5774(s32);

#endif /* MAGIC_SENNKOKU_DECLS_H */
