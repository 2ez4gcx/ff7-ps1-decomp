/* Declarations the C of src/magic_thunder2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_THUNDER2_DECLS_H
#define MAGIC_THUNDER2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B147C();
void func_801B00B0(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
void func_800D4368(MgSVec *, s32, s32);
extern struct { s32 *unk0; s32 unk4; s16 unk8; } D_801D2174;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 *D_801D2180[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;

#endif /* MAGIC_THUNDER2_DECLS_H */
