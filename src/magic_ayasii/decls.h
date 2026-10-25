/* Declarations the C of src/magic_ayasii/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_AYASII_DECLS_H
#define MAGIC_AYASII_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B04E4();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern u8 D_801B0000[];
extern u8 D_801B0584[];
extern MgObj20 *D_801CE990;
extern s32 D_801CE994;
extern s32 D_801CE998;
void func_801B0428(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D54EC(s32, void *);
extern s16 D_8015169C;
void func_801B0190(void);
extern MgTask D_80162978[];
void func_801B0074(void);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u8 D_801B6980[];
typedef struct { u16 v; } MgHalf;
extern MgHalf D_801B6988;
extern s32 D_801CE98C;
extern u8 D_801CE99C[];
extern u8 D_801CE9A4[];
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
s32 func_80042DA8();
void func_800D5774(s32);
extern u8 D_801CE9A0[];

#endif /* MAGIC_AYASII_DECLS_H */
