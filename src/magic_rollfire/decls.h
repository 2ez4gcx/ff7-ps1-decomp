/* Declarations the C of src/magic_rollfire/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ROLLFIRE_DECLS_H
#define MAGIC_ROLLFIRE_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B08C4();
void func_801B0864(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BCE60[];
extern u8 *D_801DCE60;
extern s16 D_80162080;
void func_801B02F4(void);
extern u8 D_801DCE6C;
MgObj20 *func_801B0320(void);
void func_801B0230(void);
void func_801B0020();
extern u8 D_801B093C[];
void func_800D2980(void *, s32, s32, s32);
extern s32 D_801DCE64;
extern s32 D_801DCE68;
s32 func_800BBEAC(void (*)());
void func_801B0610();

#endif /* MAGIC_ROLLFIRE_DECLS_H */
