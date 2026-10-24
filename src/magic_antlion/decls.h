/* Declarations the C of src/magic_antlion/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ANTLION_DECLS_H
#define MAGIC_ANTLION_DECLS_H

#include "main/decls.h"
void func_801B0040(void);
M2C_UNK func_801B3D30();
s32 func_801B0D60(s32 a, s32 b);
s32 func_80039A74(s32);
s32 func_801B0D24(s16 **pp);
extern s16 D_801E4166[];
void func_801B1EAC(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B0F48;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B1F10(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern u16 D_801E3F0C;
extern s16 D_801E3F06;
extern u16 D_801E3FFC;
extern u16 D_801E3FEC;
extern s32 D_801E3F28;
extern s32 D_801E4008;
extern M2C_UNK D_801E3FCC;
void func_8003A63C(void *, void *, MgMat *);
extern M2C_UNK D_801E400C;
void func_801B0B20(MgMat *, void *);

#endif /* MAGIC_ANTLION_DECLS_H */
