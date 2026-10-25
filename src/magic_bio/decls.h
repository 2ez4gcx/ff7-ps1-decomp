/* Declarations the C of src/magic_bio/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BIO_DECLS_H
#define MAGIC_BIO_DECLS_H

#include "main/decls.h"
void func_801B0640(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern M2C_UNK D_801B06C8;
void func_801B0554(s32 arg0, s32 arg1);
void func_801B05E0(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B7888[];
extern u8 *D_801D7888;
extern s16 D_80162080;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0238(void);
void func_801B0178(void);
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u16 D_801B7884;
void func_801B0000(void);
extern u8 D_801B7874;
extern u8 D_801B7875;
extern u8 D_801B7876;
extern u8 D_801B7877;
extern s16 D_801B7878;
s32 func_80042DA8();
void func_800D5774(s32);

#endif /* MAGIC_BIO_DECLS_H */
