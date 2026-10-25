/* Declarations the C of src/magic_minimam/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MINIMAM_DECLS_H
#define MAGIC_MINIMAM_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0514();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern MgObj20 D_80162978[];
extern u8 D_801B0000[];
extern u8 D_801B05B8[];
extern MgObj20 *D_801CC8B0;
extern s32 D_801CC8B4;
void func_801B0414();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
extern u8 D_801518F6[][0xB9C];
extern u8 D_8015190F[][0xB9C];
void func_801B0190(void);
void func_801B0074(void);
typedef struct { s16 x; s16 y; s16 z; u16 s; } MinimamPt;
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801B48A0[];
extern struct { u16 v; } D_801B48A8;
extern s32 D_801CC8AC;
extern MinimamPt D_801CC8B8[];
s32 func_80042DA8();
s32 func_800D56A8(void *);
void func_800D5774(s32);

#endif /* MAGIC_MINIMAM_DECLS_H */
