/* Declarations the C of src/magic_odin1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ODIN1_DECLS_H
#define MAGIC_ODIN1_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B65A0();
extern M2C_UNK D_801DD640;
void func_801B27DC(void);
extern s32 D_801F7EE0[];
s32 func_801B1630(s16 **pp);
extern s16 D_801F76FE[];
void func_801B2778(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B1758;
M2C_UNK func_800BBEAC(M2C_UNK *);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801F3554;
extern MgMat D_801F27F0;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B2944(MgSVec *v, s16 scale, s32 dist);
void func_801B2FFC(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK func_801B2EC0;
extern MgTask D_80162978[];
void func_801B5148(s16 arg0, s16 arg1, s16 arg2);
extern s32 func_801B5088;

#endif /* MAGIC_ODIN1_DECLS_H */
