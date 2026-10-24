/* Declarations the C of src/magic_tail/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TAIL_DECLS_H
#define MAGIC_TAIL_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B1568();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D2C84[];
extern u8 *D_801EAC84;
extern s16 D_80162080;
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
void func_800D4368(MgSVec *, s32, s32);
extern struct { s32 *unk0; s32 unk4; s16 unk8; } D_801D2BD0;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 *D_801D2BDC[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;

#endif /* MAGIC_TAIL_DECLS_H */
