/* Declarations the C of src/magic_dise/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DISE_DECLS_H
#define MAGIC_DISE_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
void func_801B1634();
extern M2C_UNK D_801B5964;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B007C(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0158(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02D4(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03B0(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
s32 func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B1700;
extern MgTask D_80162978[];
extern MgTask *D_801CE144;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_801CE148;
extern s32 D_801CE14C;
extern s32 D_801CE150;
void func_801B15B4(void);
s32 func_801B0494(s32 x, s32 v, s32 a, s32 lim);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } MgQ8;
extern s16 D_8015169C;
extern MgQ8 D_801CE2D8[];
void func_801B1084(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s32 unk14; u8 pad18[0x18]; MgVec unk30; } MgDiseP;
void func_8003AB84(MgMat *, MgVec *, MgVec *);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
s32 func_80042DA8(void);
void func_800D3994(s32, s32, void *);
s32 func_800D55F4(s32, ...);
s32 func_800D56A8(void *);
void func_800D5774(s32);
extern u8 D_80062D98;
extern u8 D_80151915[][0xB9C];
extern s16 D_80151A46[][0x5CE];
extern s32 D_80163774;
extern MgDiseP D_801CE154[];
extern MgVec D_801B6130;
extern M2C_UNK func_801B04E0;

#endif /* MAGIC_DISE_DECLS_H */
