/* Declarations the C of src/magic_quasar/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_QUASAR_DECLS_H
#define MAGIC_QUASAR_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B1470();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D754C[];
extern s32 D_801EF54C;
extern s16 D_80162080;
void func_801B008C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_800D4368(MgSVec *, s32, s32);
extern u16 D_801D7410;
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801D7344;

#endif /* MAGIC_QUASAR_DECLS_H */
