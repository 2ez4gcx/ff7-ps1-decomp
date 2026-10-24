/* Declarations the C of src/magic_seed/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SEED_DECLS_H
#define MAGIC_SEED_DECLS_H

#include "main/decls.h"
void func_801B0810(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK func_801B038C;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_SEED_DECLS_H */
