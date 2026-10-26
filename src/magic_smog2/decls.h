/* Declarations the C of src/magic_smog2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SMOG2_DECLS_H
#define MAGIC_SMOG2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0E84();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D1A18[];
extern u8 *D_801E9A18;
extern s16 D_80162080;
s32 func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0F00;
void func_801B0DC4(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D3994(s32, u8, s16 *);
extern u8 D_8015190F[][0xB9C];
extern M2C_UNK func_801B06B4;
void func_801B008C(void);
M2C_UNK func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, M2C_UNK, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801D19D4[];
extern u16 D_801D19D0[];
extern s32 D_801D19E4[];
void func_801B0590(void);
typedef struct { s8 v; } MgByte;
extern MgByte D_801D1A04;
extern MgByte D_801D1A05;
extern MgByte D_801D1A06;
extern s16 D_801D1A0C[];
void func_801B0458(void);
M2C_UNK func_801B0190(s16, s16, s16, s16);

#endif /* MAGIC_SMOG2_DECLS_H */
