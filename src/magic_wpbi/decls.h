/* Declarations the C of src/magic_wpbi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_WPBI_DECLS_H
#define MAGIC_WPBI_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0DDC();
extern M2C_UNK D_801B0E90;
extern M2C_UNK *D_801D09F0;
extern s32 D_801D09F4;
void func_801B008C(void);
extern M2C_UNK D_801B1494;
void func_801B00C4(void);
extern M2C_UNK D_801B1E10;
void func_801B00FC(void);
extern M2C_UNK D_801B28B4;
void func_801B0134(void);
extern M2C_UNK D_801B3188;
void func_801B016C(void);
extern M2C_UNK D_801B3C0C;
void func_801B01A4(void);
extern M2C_UNK D_801B45C0;
void func_801B01DC(void);
extern M2C_UNK D_801B4F74;
void func_801B0214(void);
extern M2C_UNK D_801B598C;
void func_801B024C(void);
extern M2C_UNK D_801B62D0;
void func_801B0284(void);
extern M2C_UNK D_801B6BA4;
void func_801B02BC(void);
extern M2C_UNK D_801B7564;
void func_801B02F4(void);
extern M2C_UNK D_801B7FB8;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B032C(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0408(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B0584(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B0660(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgTask D_80162978[];
extern MgTask *D_801D09B0;
extern s32 D_801D09B4;
extern s32 D_801D09B8;
extern s32 D_801D09BC;
extern M2C_UNK func_801B0C60;

#endif /* MAGIC_WPBI_DECLS_H */
