/* Declarations the C of src/magic_catastro/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CATASTRO_DECLS_H
#define MAGIC_CATASTRO_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0058(void);
M2C_UNK func_801B4AB0();
extern M2C_UNK D_801C6C08;
s32 func_801B0B40(s16 **pp);
extern s16 D_801D88F2[];
void func_801B1C9C(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B0C68;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];

#endif /* MAGIC_CATASTRO_DECLS_H */
