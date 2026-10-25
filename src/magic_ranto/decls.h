/* Declarations the C of src/magic_ranto/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_RANTO_DECLS_H
#define MAGIC_RANTO_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B079C();
extern M2C_UNK D_801B6C2C;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801B9668[];
extern u8 *D_801C9668;
extern s16 D_80162080;
extern u8 D_801B0830[];
extern u8 D_801C9670[];
extern s16 D_801C966C;
void func_800D54EC(s32, void *);
void func_801B0170(void);
extern MgObj20 D_80162996[];
void func_801B0088(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(s16 *, M2C_UNK, M2C_UNK);
s32 func_800D4D90(u8 *, s32, M2C_UNK, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 D_801B6874;
extern u16 D_801B9650;
extern MgTask D_80162978[];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80039A74(s16);
s32 func_80039B40(s16);
s32 func_80042DA8(void);
void func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(M2C_UNK *);
u16 *func_800D4FA8(s32);
extern s16 D_801B9654;
extern s16 D_801B9658[];
extern u8 D_801517F0[];
extern u8 D_801518F6[][0xB9C];
extern u8 D_80151A4C[][0xB9C];

#endif /* MAGIC_RANTO_DECLS_H */
