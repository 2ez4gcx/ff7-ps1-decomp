/* Declarations the C of src/magic_hvshot/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HVSHOT_DECLS_H
#define MAGIC_HVSHOT_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B103C();
extern M2C_UNK D_801B10AC;
void func_801B0F88(s16 arg0, s16 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern M2C_UNK func_801B07F8;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B0FDC(void);
extern s16 D_8015169C;
extern u8 D_801B59F8[];
extern u8 *D_801D59F8;
extern s16 D_80162080;
extern M2C_UNK D_801B1A18;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);

#endif /* MAGIC_HVSHOT_DECLS_H */
