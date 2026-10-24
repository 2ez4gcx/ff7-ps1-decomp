/* Declarations the C of src/eqipmenu/ uses (tools/auto_decomp.py adds to this). */
#ifndef EQIPMENU_DECLS_H
#define EQIPMENU_DECLS_H

#include "main/decls.h"
void func_801D0124(s32 arg0);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
void func_801D1B94(s32 arg0);
u32 func_801D1BD4(u32 arg0);
void func_801D7FDC(void);
extern s32 D_80062D9C;
void func_801D2A80(s32 *arg0, s32 *arg1);
void func_801D2CE4(s32 *arg0, s32 *arg1);
s32 func_801D1BDC(s32 arg0);
void func_801D0164(void);
void func_801D2E78(s32 arg0);
s32 func_801D2A94(void *base, u32 n, s32 (*cmp)(), void (*swap)());
s16 func_801D2D40(u16 arg0, u16 arg1, u32 **arg2);
void func_801D2E40(u16 arg0, u16 arg1, s32 **arg2);
s32 func_801D2EBC(s32 arg0, s32 arg1);
s32 func_801D2CF8(u8 arg0, u8 arg1, u32 arg2, u32 arg3);
void func_801D513C(u8 *a, u8 *b, s32 *c, s32 *d);
void func_801D7FF4(void);
extern u16 D_80062D80;
extern s32 D_801D88EC;
extern u16 D_801D88E0;
void func_801D3A24(void);
typedef struct { u8 id; u8 pad1; u8 flag; u8 pad3[2]; u8 attr; u8 pad6[2]; } EqpMat8;
typedef struct { EqpMat8 e[0x38]; u8 pad[0x280]; } EqpChrMat;
extern u8 D_8009D954[];
void func_801D509C(void);
extern s32 D_801DF6B0;
void func_801D0574(void);
extern s32 D_80062F6C;
extern u8 D_801D8AA0[];
extern s32 D_801D8AE8;
extern s32 D_801D8AEC;
extern s32 D_801D8AF0;
void func_801D4678(s32 arg0);
typedef struct { u8 pad0[2]; s16 top; u8 pad4[7]; s8 pos; u8 padC[6]; } EqpCursor;
extern EqpCursor D_801DF590[];
extern s32 D_801DF6BC;
void func_801D3CB0(void);
extern s32 D_801D8830;
void func_801D2EFC(void);
extern s16 D_801D8834;
extern s16 D_801D8836;
extern s16 D_801D883A;
extern s16 D_801D884A[];
void func_801D5194(void);
extern s8 D_801DF6E8;
extern u8 D_801DF6EC[];
void func_801D0184(s32 x, s32 y, u8 *slots);
s32 func_801D5300(s32 x, s32 y, s32 item);
typedef struct { u8 filled; u8 count; u8 pad[8]; s16 v[8]; } EqpStatDiff;
extern EqpStatDiff *D_801D8B08;
void func_801D1BF4(void);
extern u8 D_801D8674[][0x14];
void func_801D3AA0(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3);
extern s32 func_80028CA0();
s32 func_8002603C(u8 arg0);
void func_80026A34(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

#endif /* EQIPMENU_DECLS_H */
