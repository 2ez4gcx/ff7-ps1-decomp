/* Declarations the C of src/magic_slow/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SLOW_DECLS_H
#define MAGIC_SLOW_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B07FC();
void func_801B079C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BB148[];
extern u8 *D_801DB148;
extern s16 D_80162080;
void func_801B01B8(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgPrim;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_8003A08C(MgVec *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B05C(MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003BA10(MgVec *, MgVec *, MgVec *);
void func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
void func_800D5774(s32);
void func_801B0020(void *arg0, void *arg1, s32 arg2);
void func_801B013C(void *arg0);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern u8 D_801B4A8C[];
extern u8 D_801B96E0[];
extern u8 D_801B9F70[];
extern u16 D_801BA864;
extern u16 D_801BA866;
extern s16 D_801BA868;
extern MgPrim D_801BA86C;
extern MgPrim D_801BA87C;
extern s16 D_801BB11C;
extern MgMat D_801BB128;
typedef struct { u16 x; u16 y; u16 z; u16 pad; } SlowVtx;
extern SlowVtx D_801BA88C[];
void func_800D2980(void *, s32, s32, s32);
s32 func_800BBEAC(void *);
M2C_UNK func_800D54EC();
s32 func_800D574C();
s32 func_800D55F4(s32, s32, s32);
void func_800D44E8(MgSVec *, MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003BF3C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
extern u8 D_801B0A28[];
extern s32 D_801B4A88[];
extern s32 D_801B6C6C[];
extern s16 D_801BB120;
extern s16 D_801BB122;
typedef struct { s16 v; } MgHalf;
extern MgHalf D_801BB124;
extern u16 D_800FA650;
extern u16 D_800FA654;
extern u16 D_800FA658;

#endif /* MAGIC_SLOW_DECLS_H */
