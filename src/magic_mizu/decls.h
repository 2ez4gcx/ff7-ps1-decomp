/* Declarations the C of src/magic_mizu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MIZU_DECLS_H
#define MAGIC_MIZU_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0AD8();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C28A4[];
extern u8 *D_801DA8A4;
extern s16 D_80162080;
void func_801B0A18(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK func_801B04E4;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_MIZU_DECLS_H */
