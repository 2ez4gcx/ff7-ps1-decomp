/* Declarations the C of src/magic_seed/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SEED_DECLS_H
#define MAGIC_SEED_DECLS_H

#include "main/decls.h"
void func_801B0810(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK func_801B038C;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B006C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
void func_800D4368(void *, s32, s32);
extern u16 D_801B3E54;
extern s32 D_801517C0;
extern u8 *D_801CBE8C;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B3D88;

#endif /* MAGIC_SEED_DECLS_H */
