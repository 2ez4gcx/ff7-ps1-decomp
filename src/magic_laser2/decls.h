/* Declarations the C of src/magic_laser2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LASER2_DECLS_H
#define MAGIC_LASER2_DECLS_H

#include "main/decls.h"
void func_801B0010(void);
M2C_UNK func_801B0E20();
void func_801B065C(void *arg0, void *arg1);
s32 func_80039A74(s16);
s32 func_80039B40(s16);
void func_801B0030(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B577C[];
extern u8 *D_801CD77C;
extern s16 D_80162080;
void func_801B01F8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800D4368(void *, s32, s32);
extern u16 D_801B3068;
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B2F8C;

#endif /* MAGIC_LASER2_DECLS_H */
