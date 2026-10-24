/* Declarations the C of src/brom/ uses (tools/auto_decomp.py adds to this). */
#ifndef BROM_DECLS_H
#define BROM_DECLS_H

#include "main/decls.h"
void func_800A015C(void);
M2C_UNK func_800A0534(M2C_UNK);
void func_800A0000(void);
extern s32 D_800A06CC;
extern s16 D_800A06E0;
extern s8 D_800A06E2;
extern s8 D_800A06E3;
extern s8 D_800A06E4;
extern s32 D_800A0728;
extern s8 D_800A0739;
u32 func_800A0514(u32 arg0);
typedef struct { u16 magic[4]; u16 w; u16 h; u16 data[1]; } BromImg;
typedef struct { s16 x; s16 y; s16 w; s16 h; } BromRect;
s32 func_800A05D4(BromImg *arg0, s32 x, s32 y);

#endif /* BROM_DECLS_H */
