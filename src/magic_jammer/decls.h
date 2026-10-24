/* Declarations the C of src/magic_jammer/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JAMMER_DECLS_H
#define MAGIC_JAMMER_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0B44();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D12D8[];
extern u8 *D_801E92D8;
extern s16 D_80162080;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B0BB0;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B0A68;
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);

#endif /* MAGIC_JAMMER_DECLS_H */
