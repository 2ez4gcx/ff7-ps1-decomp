/* Declarations the C of src/itemmenu/ uses (tools/auto_decomp.py adds to this). */
#ifndef ITEMMENU_DECLS_H
#define ITEMMENU_DECLS_H

#include "main/decls.h"
void func_801D01E8(s32 arg0);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
void func_801D03B4(s32 *arg0, s32 *arg1);
void func_801D0618(u16 *arg0, u16 *arg1);
s32 func_801D062C(s32 arg0);
s32 func_801D0CAC(s32 arg0);
extern s16 D_8009D85E;
s32 func_801D0CE8(s32 arg0);
extern s16 D_8009D862;
void func_801D0E4C(u8 *arg0);
extern u8 D_801D3E60[];
void func_801D0A74(s16 arg0, s16 arg1, u16 **arg2);
s32 func_801D3228(void);
extern u8 D_801D3890[];
s32 func_801D0650(s16 arg0, s16 arg1, u16 **arg2);
void func_801D2974(s32 arg0, s32 arg1);
extern s32 D_801D3F60[];
extern u8 D_801D3834[];
s32 func_801D29C4(void);
s32 func_801D069C(s16 arg0, s16 arg1, u16 **arg2);
s32 func_801D2E84(void);
extern s32 D_8009D180[];
void func_801D031C(void);
extern u8 D_8009D2C8[];
extern u8 D_801D3D90[];
s32 func_801D0DCC(s32 arg0);
extern u8 D_8009D5E8;
extern u16 D_80062F50;
s32 func_801D076C(s16 arg0, s16 arg1, u16 **arg2);
extern u16 D_801D35B4[];
s32 func_801D0D24(s32 arg0);
extern Slot84 D_8009C75A[];
s32 func_801D081C(s16 arg0, s16 arg1, u16 **arg2);
s32 func_801D08E4(s16 arg0, s16 arg1, u16 **arg2);
s32 func_801D09AC(s16 arg0, s16 arg1, u16 **arg2);
void func_801D2C00(s32 arg0);
s32 func_801D3138(s32 arg0);
typedef struct { u8 party[4]; u8 wpn; u8 arm; u8 pad[2]; s32 wm[8]; s32 am[8]; s32 m[3]; } ItmSave;
typedef struct { s32 wm[8]; s32 am[8]; u8 pad[0x44]; } ItmChrM;
extern ItmChrM D_8009C778[];
void func_801D0BA0(void);
extern s32 D_801D3E48;
extern u8 D_801D3DDC[];
void func_801D0228(s16 arg0, s16 arg1, s32 arg2);
s32 func_801D03C8(void *base, u32 n, s32 (*cmp)(), void (*swap)());
void func_801D0AAC(u32 arg0);
s32 func_801D3018(s32 arg0);
s32 func_801D2F00(s32 arg0);
typedef struct { s32 m[8]; u8 pad[0x64]; } ItmMat8;
extern ItmMat8 D_8009C798[];
void func_801D2A18(s32 *arg0);
void func_801D2CDC(void);
s32 func_801D2ABC(s32 arg0);
typedef struct { u8 pad[5]; u8 slot[8]; u8 rest[0x17]; } ItmArmor;
extern ItmArmor D_80071E48[];
s32 func_801D2D74(void);
typedef struct { u8 pad[0x40]; s32 wm[8]; s32 am[8]; u8 pad2[4]; } ItmChr;
s32 func_801D0704(s16 arg0, s16 arg1, u16 **arg2);
void func_801D296C(void);

#endif /* ITEMMENU_DECLS_H */
