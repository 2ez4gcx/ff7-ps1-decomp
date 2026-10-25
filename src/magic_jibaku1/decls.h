/* Declarations the C of src/magic_jibaku1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JIBAKU1_DECLS_H
#define MAGIC_JIBAKU1_DECLS_H

#include "main/decls.h"
void func_801B006C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern u16 D_801B8584;
extern s32 D_801517C0;
extern u8 *D_801D0588;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B83F8;
void func_801B0128(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_80042DA8();
s32 func_800BBEAC(void *);
void func_800D5774(s32);
void func_801B02B0(s32 arg0, s32 arg1);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
s32 func_801B0338();
s32 func_800BBA84();
void func_800D2980(void *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void *);
extern u8 D_801B03B4[];
extern u8 D_801B0000[];

#endif /* MAGIC_JIBAKU1_DECLS_H */
