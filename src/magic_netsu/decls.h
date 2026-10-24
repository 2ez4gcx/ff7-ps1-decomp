/* Declarations the C of src/magic_netsu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_NETSU_DECLS_H
#define MAGIC_NETSU_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0D0C();
void func_801B0644(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801D61E8;
extern u8 D_801D61E9;
extern u8 D_801D61EA;
extern s16 D_801D61EC[];
extern u8 *D_801EE21C;
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern u8 D_801D621C[];
extern s16 D_80162080;
extern MgObj20 D_80162978[];
void func_801B0430(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern u16 D_801D61B0;
extern s32 D_801D601C;
void func_801B008C(void);
s32 func_800C4FC8(s16, M2C_UNK, M2C_UNK);
extern s32 D_80163C74;
extern s16 D_801D615C;

#endif /* MAGIC_NETSU_DECLS_H */
