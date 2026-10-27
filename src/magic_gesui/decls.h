/* Declarations the C of src/magic_gesui/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GESUI_DECLS_H
#define MAGIC_GESUI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0BE8();
void func_801B0020(void);
M2C_UNK func_801B0D44();
void func_801B0040(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C1108[];
extern u8 *D_801D9108;
extern s16 D_80162080;
void func_801B01AC(u8 *arg0, u8 *arg1);
s32 func_801B01FC(s32 arg0, s16 arg1);
extern s16 D_801D910C[];
extern s16 D_801D930C[][0x60];
void func_801B00AC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 unk0; s32 unk4; } MgGesuiAnim;
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801C10F8[];
extern MgGesuiAnim *D_801C10FC[];
void func_801B07EC(void);
extern s8 D_800F5B72;
extern s8 D_800F5B71;
extern s8 D_800F5B70;
void func_800D52A0(s32, s32);
void func_801B0290(void);
s32 func_800BBEAC(void *);
extern s16 D_801DB10C;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
s32 func_80042DA8(void);
void func_800D5774(s32);

#endif /* MAGIC_GESUI_DECLS_H */
