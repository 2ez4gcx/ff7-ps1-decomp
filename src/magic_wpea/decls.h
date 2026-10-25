/* Declarations the C of src/magic_wpea/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_WPEA_DECLS_H
#define MAGIC_WPEA_DECLS_H

#include "main/decls.h"
void func_801B0054(s32 arg0, M2C_UNK arg1);
s32 func_80042DA8();
void func_801B1384();
extern M2C_UNK D_801B1438;
extern M2C_UNK *D_801CF914;
extern s32 D_801CF918;
void func_801B00C0(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B19FC;
void func_801B012C(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B2310;
void func_801B0198(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B2A74;
void func_801B0204(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B3308;
void func_801B0270(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B3C04;
void func_801B02DC(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B4458;
void func_801B0348(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B4E1C;
void func_801B03B4(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B58CC;
void func_801B0420(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B6310;
void func_801B048C(s32 arg0, M2C_UNK arg1);
extern M2C_UNK D_801B6D8C;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B04F8(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B05D4(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B0750(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B082C(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgTask D_80162978[];
extern MgTask *D_801CF8D4;
extern s32 D_801CF8D8;
extern s32 D_801CF8DC;
extern s32 D_801CF8E0;
void func_801B11E8(void);
extern s16 D_8015169C;
extern u8 D_8015190F[][0xB9C];
extern MgSVec D_801CF8E4;
void func_800D3994(s32, s32, void *);
extern MgSVec D_801CF8EC;
extern u8 D_80151A46[][0xB9C];
MgMat *func_8003BF8C(MgSVec *, MgMat *);
extern MgVec D_801B78C0;
extern MgVec D_801CF8F4;
MgVec *func_8003AB84(MgMat *, MgVec *, MgVec *);
extern void func_801B0DF8(void);
extern void func_801B0FE4(void);

#endif /* MAGIC_WPEA_DECLS_H */
