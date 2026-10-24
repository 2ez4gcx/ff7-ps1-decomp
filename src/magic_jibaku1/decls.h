/* Declarations the C of src/magic_jibaku1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JIBAKU1_DECLS_H
#define MAGIC_JIBAKU1_DECLS_H

#include "main/decls.h"
void func_801B006C(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern u16 D_801B8584;
extern s32 D_801517C0;
extern u8 *D_801D0588;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B83F8;

#endif /* MAGIC_JIBAKU1_DECLS_H */
