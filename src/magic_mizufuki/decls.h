/* Declarations the C of src/magic_mizufuki/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MIZUFUKI_DECLS_H
#define MAGIC_MIZUFUKI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B140C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D1DAC[];
extern s32 D_801E9DAC;
extern s16 D_80162080;
void func_801B017C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_800D4368(MgSVec *, s32, s32);
extern u16 D_801D1D4C;
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801D1724;

#endif /* MAGIC_MIZUFUKI_DECLS_H */
