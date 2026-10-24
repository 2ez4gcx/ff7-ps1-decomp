/* Declarations the C of src/magic_satan/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SATAN_DECLS_H
#define MAGIC_SATAN_DECLS_H

#include "main/decls.h"
s32 func_801B00E0(void);
M2C_UNK func_801B664C();
s32 func_801B0104(void);
M2C_UNK func_801B672C();
void func_801B65FC(void);
extern s32 D_800F8368;
extern M2C_UNK D_801C87AC;
extern M2C_UNK D_801D47AC;
extern M2C_UNK *D_801E07AC;
extern s32 *D_801E07B0;
extern s32 D_801E1A10;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0128(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0204(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B0380(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B045C(MgSVec *p, MgSVec *q, MgVec *n);
s32 func_801B2898(s16 **pp);
extern s16 D_801E7E16[];
s32 func_801B28D4(s32 a, s32 b);
void func_801B3A14(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B29CC;
M2C_UNK func_800BC04C(M2C_UNK *);
extern MgObj20 D_801621F0[];

#endif /* MAGIC_SATAN_DECLS_H */
