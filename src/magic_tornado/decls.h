/* Declarations the C of src/magic_tornado/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TORNADO_DECLS_H
#define MAGIC_TORNADO_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B10F4();
typedef struct { s16 unk0; s16 unk2; s16 unk4[3]; s16 unkA; u8 pad[0x40]; } MgObj4C;
extern MgObj4C D_801C2F34[];
MgObj4C *func_801B0020(void);
MgObj4C *func_801B07E0(void);
extern MgObj4C D_801C4CE4[];
extern M2C_UNK D_801B1164;
extern M2C_UNK func_801B0F60;
extern M2C_UNK func_801B1070;

#endif /* MAGIC_TORNADO_DECLS_H */
