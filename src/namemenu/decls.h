/* Declarations the C of src/namemenu/ uses (tools/auto_decomp.py adds to this). */
#ifndef NAMEMENU_DECLS_H
#define NAMEMENU_DECLS_H

#include "main/decls.h"
void func_801D0014(s32 arg0);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
void func_801D16B4(void *arg0, void *arg1);
s32 func_801D1AA0(s32 arg0);
void func_801D02C8(s32 arg0);
typedef struct { s32 w[0x21]; } NmChr;
extern NmChr D_801D904C[];
typedef struct { u8 a; s8 b; } NmCurve;
typedef struct { s32 rank; u8 id; u8 lvl; u8 pad6[2]; u16 base[8]; u16 stat[8]; u8 *p; s32 f2C; u8 pad30[0xC]; s32 c[16]; } NmLvl;
extern NmCurve D_80082484[][8];
extern u8 D_80082268[][0x38];
void func_801D1838(NmLvl *arg0);
s32 func_801D05BC(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_801D8F24[];
extern u8 D_801D8F80[];
extern u8 D_801D8FDC[];
void func_801D066C(s32 arg0);
extern s32 D_801D9048;
extern u8 D_801D977C[];
extern u8 D_801D978C;
void func_801D0724(void);
extern u8 D_801D9781;
extern u8 D_801D9784;
void func_801D01CC(void);
void func_801D0328(void);
extern u8 D_801D8E6C[][12];
void func_801D1254(void);
typedef struct { s32 f0; u16 hp; u16 maxhp; u16 mp; u16 maxmp; u8 pad[0x78]; } NmHp;
extern NmHp D_8009C760[];
extern u8 D_801D9870[];
void func_801D14E8(u8 *arg0);

#endif /* NAMEMENU_DECLS_H */
