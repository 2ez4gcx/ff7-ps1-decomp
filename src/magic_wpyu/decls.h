/* Declarations the C of src/magic_wpyu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_WPYU_DECLS_H
#define MAGIC_WPYU_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B25A8();
extern M2C_UNK D_801B265C;
extern M2C_UNK *D_801D3BFC;
extern s32 D_801D3C00;
void func_801B00C8(void);
extern M2C_UNK D_801B3774;
void func_801B013C(void);
extern M2C_UNK D_801B4B8C;
void func_801B0174(void);
extern M2C_UNK D_801B5420;
void func_801B01AC(void);
extern M2C_UNK D_801B6134;
void func_801B01E4(void);
extern M2C_UNK D_801B6B30;
void func_801B030C(void);
extern M2C_UNK D_801B9DDC;
void func_801B0344(void);
extern M2C_UNK D_801BA410;
void func_801B008C(void);
extern M2C_UNK D_801B2E40;
void func_801B0100(void);
extern M2C_UNK D_801B4178;
void func_801B021C(void);
extern M2C_UNK D_801B7554;
void func_801B0258(void);
extern M2C_UNK D_801B8038;
void func_801B0294(void);
extern M2C_UNK D_801B871C;
void func_801B02D0(void);
extern M2C_UNK D_801B9288;
void func_801B037C(void);
extern M2C_UNK D_801BB390;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B03B8(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0494(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B0610(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B06EC(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgTask D_80162978[];
extern MgTask *D_801D3BB8;
extern s32 D_801D3BC0;
extern s32 D_801D3BC4;
extern s32 D_801D3BC8;
extern M2C_UNK func_801B23C8;

#endif /* MAGIC_WPYU_DECLS_H */
