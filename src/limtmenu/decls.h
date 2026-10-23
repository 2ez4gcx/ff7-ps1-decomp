/* Declarations the C of src/limtmenu/ uses (tools/auto_decomp.py adds to this). */
#ifndef LIMTMENU_DECLS_H
#define LIMTMENU_DECLS_H

#include "main/decls.h"
void func_801D002C(s32 arg0);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
void func_801D006C(void);
extern s32 D_80062F6C;
extern s32 D_801D2320;
extern u8 D_801D235C[];
extern s32 D_801D2410;
void func_801D013C(s32 arg0);
extern u8 D_8009C746[];
extern u8 D_8009C747[];
extern u8 D_8009C757[];
extern u8 D_801D2344[];
extern u8 D_801D2345[];
extern u8 D_801D2346[];
extern u8 D_801D234A;
extern u8 D_801D234B;
extern u8 D_801D234C;
extern u8 D_801D21DC[];
extern u8 D_80049314[];
typedef struct { s32 w[7]; } Blk;
typedef struct { u8 a[8]; Blk b[3]; u8 rest[0x3E4]; } Ent;
extern Ent D_8009D8F8[];
extern Blk D_801D1324[];

s32 func_801D11A8(void);
#endif /* LIMTMENU_DECLS_H */
