/* Declarations the C of src/brom/ uses (tools/auto_decomp.py adds to this). */
#ifndef BROM_DECLS_H
#define BROM_DECLS_H

#include "main/decls.h"
void func_800A015C(void);
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

s32 func_80017108();void func_800A0534(BromImg *img);
void func_800A00CC(void);
void func_800A01A0(void);
void func_80017678(void);
void func_8001786C(u8 arg0);
void func_8001C980(void);
void func_80020058(s32 arg0);
void func_80043F6C(BromRect *arg0, s32 r, s32 g, s32 b);
void func_8004418C(s32 *arg0, s32 arg1);
extern u8 D_800A06B4[];
extern u8 D_800A06BC[];
extern BromRect D_800A06C4;
extern u8 D_800A073C[][0x2000];
extern s32 D_800A473C[];

#endif /* BROM_DECLS_H */
