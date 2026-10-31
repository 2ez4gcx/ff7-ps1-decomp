/* Declarations the C of src/magic_lv4jibak/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LV4JIBAK_DECLS_H
#define MAGIC_LV4JIBAK_DECLS_H

#include "main/decls.h"
void func_801B0070(void);
void func_801B1858();
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
extern MgLineG2 *D_801CFD2C;
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
extern s32 D_801517C0;
void func_801B115C(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color);
void func_801B04A8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D4368(void *, s32, s32);
MgLineG2 *func_800D4D90(void *, s32, s32, MgLineG2 *);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u16 D_801B7D28;
void func_801B0574(void);
typedef struct { u8 pad0[4]; s32 unk4; s32 unk8; u8 pad[0x570]; } MgRec57C;
extern MgRec57C D_801CFD40[];
void func_801B0CF4(void *sc, MgRec57C *r, s32 col);
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);
void func_800D5774(s32);
s32 func_800BBEAC(void *);
s32 func_80042DA8(void);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
s32 func_800D574C(s32);
extern M2C_UNK D_801B1904;
extern MgTask *D_801CFD30;
extern s16 D_801CFD3A;
extern s32 D_801CFD3C;
void func_801B128C(s32 arg0, s32 arg1);
extern u8 D_801B001C[];
void func_801B0DF0(void *sc, u8 *r, s32 col);
void func_801B0FE4(void *, u8 *, s32);
typedef struct { MgTag tag; s32 c0; s32 xy0; s32 c1; s32 xy1; s32 c2; s32 xy2; } JbPolyG3;
typedef struct { s32 unk0; s32 sxy; s32 otz; s32 flag; MgSVec p0; MgSVec p1; u8 pad[0xA0]; MgVec d0; MgVec d1; } JbScratch;
s32 func_8003BC0C(void *, void *, void *, void *, void *, void *, void *, void *);
void func_801B096C(JbScratch *sc, MgRec57C *r);
typedef struct { MgSVec p; MgVec n; s32 ang; } JbEnt;
typedef struct { u8 pad0[4]; s32 cnt; u8 pad8[0xC]; MgVec a; MgVec b; u8 pad34[8]; JbEnt e[1]; } JbRec;
typedef struct { s32 u0; s32 u4; s32 u8; s32 uC; MgSVec p10; MgSVec p18; MgSVec p20; u8 pad28[0x38]; s32 s60; s32 s64; s32 s68; u8 pad6C[0xC]; s32 s78; u8 pad7C[0x44]; MgVec c0; MgVec d0; MgVec e0; MgVec f0; } JbSc2;
extern u8 D_8015190F[][0xB9C];
extern s16 D_801518F6[][0x5CE];
extern s16 D_801CFD34;
extern s16 D_801CFD36;
extern s16 D_801CFD38;
extern MgVec D_801B7D00;
s32 func_80039F5C(s32);
void func_800D3994(s32, s32, void *);

#endif /* MAGIC_LV4JIBAK_DECLS_H */
