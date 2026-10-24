/* Declarations the C of src/magic_q_shu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_Q_SHU_DECLS_H
#define MAGIC_Q_SHU_DECLS_H

#include "main/decls.h"
void func_801B007C(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
void func_800D4368(MgSVec *, s32, s32);
extern u16 D_801BDA98;
extern s32 D_801517C0;
extern s32 D_801D5AE8;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801BD9CC;
void func_801B03FC(void);
extern u16 D_801BDAC4;
extern s32 D_801BD84C;

#endif /* MAGIC_Q_SHU_DECLS_H */
