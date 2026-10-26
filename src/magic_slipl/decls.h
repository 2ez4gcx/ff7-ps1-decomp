/* Declarations the C of src/magic_slipl/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SLIPL_DECLS_H
#define MAGIC_SLIPL_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0824();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern MgObj20 D_80162978[];
extern M2C_UNK D_801B08C0;
extern MgObj20 *D_801D0E68;
extern M2C_UNK func_801B0000;
extern M2C_UNK func_801B0614;

#endif /* MAGIC_SLIPL_DECLS_H */
