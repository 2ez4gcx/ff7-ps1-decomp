/* Declarations the C of src/magic_gospel/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GOSPEL_DECLS_H
#define MAGIC_GOSPEL_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0048(void);
M2C_UNK func_801B3914();
extern M2C_UNK D_801DDCE4;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801E0988;
extern MgMat D_801E0628;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B0070(MgSVec *v, s16 scale, s32 dist);
s32 func_801B018C(s16 **pp);
extern s16 D_801E09AA[];
void func_801B120C(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B01C8;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B3394(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK func_801B31BC;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
extern MgTask D_80162978[];
void func_801B1270(void);
extern s32 D_801E25DC;

#endif /* MAGIC_GOSPEL_DECLS_H */
