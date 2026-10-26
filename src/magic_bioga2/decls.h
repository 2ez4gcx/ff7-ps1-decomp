/* Declarations the C of src/magic_bioga2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BIOGA2_DECLS_H
#define MAGIC_BIOGA2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0AB8();
void func_801B04A4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u16 D_801E37E4;
M2C_UNK func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
extern u8 *D_801EF7F4;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B0A50(void);
extern u8 D_801B0B50[];
extern u8 D_801E37F4[];
extern s16 D_80162080;
s32 func_800BBEAC(void (*)());
void func_800D2980(void *, s32, s32, s32);
void func_800D54EC(s32, void *);
void func_801B0734(void);
extern u8 D_801517BC;
extern u8 D_801B7BB0[];
extern u8 D_801E37E8[];
extern s32 D_801E37F0;
void func_801B0328(void);
extern s8 D_801E37D4;
extern s8 D_801E37D5;
extern s8 D_801E37D6;
extern s8 D_801E37D7;
extern s16 D_801E37D8[];
void func_801B0564(void);
void func_800D3994(s32, s32, void *);
s32 func_80042DA8();
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_BIOGA2_DECLS_H */
