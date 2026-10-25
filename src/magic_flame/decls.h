/* Declarations the C of src/magic_flame/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FLAME_DECLS_H
#define MAGIC_FLAME_DECLS_H

#include "main/decls.h"
void func_801B0138(void);
extern s32 D_801DD870;
void func_801B10F4();
void func_801B0000(s32 arg0);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
void func_801B1014();
void func_801B00F0(s32 arg0);
void func_801B01B4(s32 arg0);
void func_801B1220();
void func_801B1084(s32 arg0, M2C_UNK arg1);
s32 func_800BBEAC(void (*)());
void func_800D2980(void *, s32, s32, s32);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B134C;
void func_801B0EB8(s32 arg0, s32 arg1);
void func_801B0FB4(void);
void func_801B0048(void);
extern s16 D_80151774;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BD868[];
extern u8 *D_801DD868;
extern s16 D_80162080;
void func_801B0DBC(s32 arg0, s32 arg1);
void func_801B0484(void);
extern u8 D_801DD874;
MgObj20 *func_801B04B0(void);
void func_801B03C0(void);
void func_801B01FC();
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151917[][0xB9C];
void func_801B082C(void);
void func_800D3994(s32, s32, void *);
extern s32 D_801DD86C;
void func_801B0908(void);
void func_800D54EC(s32, void *);
extern u8 D_80151918[][0xB9C];
void func_801B0B38(void);

#endif /* MAGIC_FLAME_DECLS_H */
