/* Declarations the C of src/magic_renbaku/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_RENBAKU_DECLS_H
#define MAGIC_RENBAKU_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B08C4();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B0948;
extern MgTask D_80162978[];
extern MgTask *D_801D9170;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B067C(void);
extern s32 D_801D9174;
extern s32 D_801D9178;
void func_801B0074(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { u16 v; } MgHalf;
extern MgHalf D_801C1168;
extern u8 D_801D917C[];
extern u8 D_801D9180[];
extern u8 D_801D9182[];
extern u8 D_801C1160[];
extern MgSVec D_801D9B34;
extern s32 D_801D916C;
extern s32 D_801517C0;
extern s16 D_8015169C;
extern u8 D_80062D98;
s32 func_80039F5C(s32);
s32 func_8003A08C(void *, void *);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);

#endif /* MAGIC_RENBAKU_DECLS_H */
