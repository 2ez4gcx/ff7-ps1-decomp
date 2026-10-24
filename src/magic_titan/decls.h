/* Declarations the C of src/magic_titan/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TITAN_DECLS_H
#define MAGIC_TITAN_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B5190();
extern M2C_UNK D_801C0EC8;
s32 func_801B1A24(s16 **pp);
extern s16 D_801D3E02[];
s32 func_801B1A60(s32 t, s32 s);
s32 func_80039A74(s32);
void func_801B2B84(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B1B50;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];

#endif /* MAGIC_TITAN_DECLS_H */
