/* Declarations the C of src/magic_debucho/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DEBUCHO_DECLS_H
#define MAGIC_DEBUCHO_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B1D64();
extern M2C_UNK D_801BAC54;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801C42A0;
extern MgMat D_801C4058;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist);
s32 func_801B0184(s16 **pp);
extern s16 D_801C42C2[];
void func_801B11DC(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B01C0;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B1980(void);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern u16 D_80153D22;
void func_801B19EC(void);
void func_80046794(s32, s32);
extern s32 D_801517C0;
extern u8 D_801C4224[];
extern s32 D_801C4244;
void func_801B18B0(void);
extern u16 D_801031EA;
extern u16 D_80158D02;
void func_801B1584(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800D4D90(s32 *, s32, s32, s32);
extern s32 D_80163C74;
extern s32 D_801C41D8[];
extern s32 D_801C4218;
void func_801B1240(void);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_801C4170[];
extern s16 D_801C417A;
extern s16 D_801C4180;
extern s16 D_801C4190;
extern MgMat *D_801C41A0;
void func_801B16BC(void);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8();
void func_801B1414(void);
extern u8 D_801C41A4[];
extern s16 D_801C41AE;
extern MgMat D_801C41B4;
extern MgMat *D_801C41D4;
void func_801B1A98(void);
MgTask *func_800D4FA8(s32);
void func_800D55F4(s32, s32, s32, s32, s32);
void func_800D5774(s32);
extern u8 D_800F8380;
extern MgMat D_800FA63C;
extern struct { s16 n; u8 pad0[0x16]; u8 c0; u8 c1; u8 c2; u8 pad1[0x14]; u8 f[1]; } D_80153BC8;
extern s16 D_80153BCC;
extern MgMat D_801C4030;
extern s16 D_801C404C;
extern s16 D_801C4052;
extern s32 D_801C42C0;

#endif /* MAGIC_DEBUCHO_DECLS_H */
