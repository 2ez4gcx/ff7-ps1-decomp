/* Declarations the C of src/magic_freeze/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FREEZE_DECLS_H
#define MAGIC_FREEZE_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B17D0();
void func_801B1770(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801D5F30[];
extern u8 *D_801E5F30;
extern s16 D_80162080;
extern M2C_UNK D_801B1840;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B16BC(s16 arg0, s16 arg1);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s8 v; } MgByte;
extern MgByte D_801D5E2C;
extern MgByte D_801D5E2D;
extern MgByte D_801D5E2E;
extern u8 D_801D5E28[];
extern s16 D_801E5F38;
extern s16 D_801E5F3A;
extern s16 D_801E5F3C;
extern s32 D_801517C0;
extern u8 D_80062D98;
s32 func_80039A74(s32);
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern MgTask D_80162978[];

#endif /* MAGIC_FREEZE_DECLS_H */
