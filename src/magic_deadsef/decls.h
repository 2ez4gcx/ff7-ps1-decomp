/* Declarations the C of src/magic_deadsef/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DEADSEF_DECLS_H
#define MAGIC_DEADSEF_DECLS_H

#include "main/decls.h"
void func_801B0040(void);
M2C_UNK func_801B384C();
s32 func_801B0DE4(s16 **pp);
extern s16 D_801CF89A[];
s32 func_801B0E20(s32 a, s32 b);
s32 func_80039A74(s32);
void func_801B1F6C(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B1014;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_80151A4C[][0x5CE];
extern s16 D_80151A50[][0x5CE];
void func_800D3994(s32, s32, void *);
void func_8003BF3C(MgTask *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B0F18(s32 arg0, s32 arg1, MgTask *arg2, MgSVec *arg3);

#endif /* MAGIC_DEADSEF_DECLS_H */
