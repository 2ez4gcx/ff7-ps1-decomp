/* Declarations the C of src/magic_aqua/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_AQUA_DECLS_H
#define MAGIC_AQUA_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0680();
void func_801B0074(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { u16 v[8]; } MgElem16;
extern MgTask D_80162978[];
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_80062D98;
extern s32 D_801D8998;
extern u8 D_801C098C[];
extern MgElem16 D_801D89A8[];
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B05C4(void);
s32 func_800BBEAC(void *);
M2C_UNK func_800D54EC(s32, s16 *);
extern s32 D_801D89A0;
void func_801B0254(void);
void func_800D2980(void *, s32, s32, s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern u8 D_801B0000[];
extern u8 D_801B0720[];
extern MgTask *D_801D899C;
extern s32 D_801D89A4;
typedef struct { u8 v; } MgByte;
typedef struct { u16 v; } MgHalf;
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
extern MgHalf D_800F5B74;
s32 func_80042DA8();
M2C_UNK func_800D5774();

#endif /* MAGIC_AQUA_DECLS_H */
