/* Declarations the C of src/magic_matra/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MATRA_DECLS_H
#define MAGIC_MATRA_DECLS_H

#include "main/decls.h"
void func_801B0070(void);
M2C_UNK func_801B1F38();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0090(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B016C(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02E8(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03C4(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { MgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s16 x0; s16 y0; u8 r1; u8 g1; u8 b1; u8 pad; s16 x1; s16 y1; } MgLineG2;
typedef struct { s32 unk0; s32 sxy; s32 otz; s32 flag; } MgRtp;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern MgLineG2 *D_801DC890;
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
extern s32 D_801517C0;
void func_801B1428(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color);
void func_801B04A8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u16 D_801B888C;
void func_800D4368(void *, s32, s32);
MgLineG2 *func_800D4D90(void *, s32, s32, MgLineG2 *);
extern u8 D_80062D98;

#endif /* MAGIC_MATRA_DECLS_H */
