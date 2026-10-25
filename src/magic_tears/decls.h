/* Declarations the C of src/magic_tears/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TEARS_DECLS_H
#define MAGIC_TEARS_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B03E4();
void func_801B0304(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0158(void);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0384(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801B0460[];
extern u8 *D_801D0460;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32));
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
void func_801B0020(void);
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D6260(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u8 D_801B0454[];
extern u8 D_801B0458;
extern u8 D_801B0459;
extern u8 D_801B045A;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8();
void func_800D5774(s32);

#endif /* MAGIC_TEARS_DECLS_H */
