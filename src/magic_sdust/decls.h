/* Declarations the C of src/magic_sdust/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SDUST_DECLS_H
#define MAGIC_SDUST_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
void func_801B355C();
extern M2C_UNK D_801B7A00;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B35D8;
extern MgTask D_80162978[];
extern MgTask *D_801E15FC;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B3418;
extern s32 D_801E1600;
void func_801B2250(void);
typedef struct { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; s16 fE; s16 f10; s16 f12; s16 f14; s16 f16; } SdPart;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801B95E4[];
extern s32 D_801E15F8;
extern SdPart D_801E3224[];
void func_801B276C(void);
extern u8 D_801B95F0[];

#endif /* MAGIC_SDUST_DECLS_H */
