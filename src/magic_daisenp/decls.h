/* Declarations the C of src/magic_daisenp/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DAISENP_DECLS_H
#define MAGIC_DAISENP_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
M2C_UNK func_801B0E38();
extern s32 D_801CF2F4;
void func_801B007C(void);
void func_801B0250(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { u16 v; } MgHalf;
extern MgTask D_80162978[];
extern MgHalf D_801B72E8;
extern u8 D_801CF300[];
extern u8 D_801CF302[];
extern u8 D_801CF304[];
extern u8 D_801CF306[];
extern u8 D_801B72E0[];
extern MgSVec D_801CFCB8;
extern s32 D_801CF2EC;
extern s32 D_801517C0;
extern s16 D_8015169C;
extern u8 D_80062D98;
s32 func_80039F5C(s32);
s32 func_8003A08C(void *, void *);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);

#endif /* MAGIC_DAISENP_DECLS_H */
