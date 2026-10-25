/* Declarations the C of src/magic_gattai/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GATTAI_DECLS_H
#define MAGIC_GATTAI_DECLS_H

#include "main/decls.h"
s32 func_801B007C();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } GattaiObj20;
void func_800BBA40(s32);
s32 func_800BBEAC(void *);
s32 func_800BC04C(void *);
extern u8 D_800C55B8[];
extern s8 D_800F8374;
extern u8 D_80151922[][0xB9C];
extern GattaiObj20 D_801621F2[];
extern GattaiObj20 D_801621F4[];
extern GattaiObj20 D_8016297C[];
extern u8 D_801B0000[];

#endif /* MAGIC_GATTAI_DECLS_H */
