/* Declarations the C of src/magic_sldfang/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SLDFANG_DECLS_H
#define MAGIC_SLDFANG_DECLS_H

#include "main/decls.h"
void func_801B05DC(void *arg0, M2C_UNK arg1, M2C_UNK arg2);
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B00A4(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0180(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02FC(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03D8(MgSVec *p, MgSVec *q, MgVec *n);
void func_801B0650(MgSVec *v0, MgSVec *v1, s32 color);
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { MgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s16 x0; s16 y0; u8 r1; u8 g1; u8 b1; u8 pad; s16 x1; s16 y1; } MgLineG2;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern MgLineG2 *D_801D4DC4;
extern s32 D_801517C0;
M2C_UNK *func_801B0054(s32 a, s32 b);
void func_801B3028(s32, s32, s32);
extern M2C_UNK D_801B94D4;
M2C_UNK *func_801B007C(s32 a, s32 b);
typedef struct { s32 head; s32 tail; s32 count; s32 v[0x18]; } MgRing;
void func_801B07B4(MgRing *r, s32 val);
void func_801B18FC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { u16 v; } MgHalf;
typedef struct { u16 f[12]; } SfPart;
extern MgTask D_80162978[];
extern s16 D_8015169C;
extern u8 D_80062D98;
extern MgHalf D_801BCDC0;
extern SfPart D_801D4DE0[];
extern SfPart D_801D4DF2[];
extern u8 D_801BCDB8[];
void func_800D4368(void *, s32, s32);
MgLineG2 *func_800D4D90(void *, s32, s32, MgLineG2 *);

#endif /* MAGIC_SLDFANG_DECLS_H */
