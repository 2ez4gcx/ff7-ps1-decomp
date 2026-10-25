/* Declarations the C of src/magic_gesui/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GESUI_DECLS_H
#define MAGIC_GESUI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0BE8();
void func_801B0020(void);
M2C_UNK func_801B0D44();
void func_801B0040(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C1108[];
extern u8 *D_801D9108;
extern s16 D_80162080;
void func_801B01AC(u8 *arg0, u8 *arg1);
s32 func_801B01FC(s32 arg0, s16 arg1);
extern s16 D_801D910C[];
extern s16 D_801D930C[][0x60];

#endif /* MAGIC_GESUI_DECLS_H */
