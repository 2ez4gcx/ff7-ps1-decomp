/* Declarations the C of src/magic_otsunami/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_OTSUNAMI_DECLS_H
#define MAGIC_OTSUNAMI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0BC8();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C0F8C[];
extern u8 *D_801D8F8C;
extern s16 D_80162080;
void func_801B018C(u8 *arg0, u8 *arg1);
s32 func_801B01DC(s32 arg0, s16 arg1);
extern s16 D_801D8F90[];
extern s16 D_801D9190[][0x60];
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 unk0; s32 unk4; } MgGesuiAnim;
void func_800D4368(void *, s32, s32);
extern s16 D_801C0F7C[];
extern s32 D_801517C0;
extern MgGesuiAnim *D_801C0F80[];
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
s32 func_80039A74(s32);
s32 func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
void func_801B07CC(void);
extern u8 D_80151918[][0xB9C];
extern M2C_UNK D_801B0D20;
extern s16 D_801C0F70;
extern s16 D_801DAF90;
s32 func_80042DA8(void);
void func_800D52A0(s32, s32);
void func_800D5774(s32);
void func_801B0270(void);
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_OTSUNAMI_DECLS_H */
