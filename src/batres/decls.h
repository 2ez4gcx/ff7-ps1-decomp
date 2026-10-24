/* Declarations the C of src/batres/ uses (tools/auto_decomp.py adds to this). */
#ifndef BATRES_DECLS_H
#define BATRES_DECLS_H

#include "main/decls.h"
void func_801B1008(void *arg0, void *arg1);
s32 func_801B13F4(s32 arg0);
s32 func_80014B70(void);
typedef struct { s32 rank; u8 id; u8 lvl; u8 pad6[2]; u16 base[8]; u16 stat[8]; u8 *p; s32 f2C; u8 pad30[0xC]; s32 c[16]; } NmLvl;
s32 func_801B1320(NmLvl *arg0, s32 arg1);
void func_801B1564(NmLvl *arg0, s32 arg1);
void func_801B15E4(NmLvl *arg0);
void func_801B16D8(NmLvl *arg0);
void func_801B1204(NmLvl *arg0);
s32 func_801B1448(NmLvl *arg0, s32 arg1, s32 arg2);
extern u8 D_80082460[];

#endif /* BATRES_DECLS_H */
