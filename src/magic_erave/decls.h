/* Declarations the C of src/magic_erave/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ERAVE_DECLS_H
#define MAGIC_ERAVE_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
void func_801B226C();
extern M2C_UNK D_801CBD74;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern MgTask D_80162978[];
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B22F8;
extern MgTask *D_801E941C;
extern s32 D_801E9420;
extern s32 D_801E9424;
void func_801B2200(void);
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
s32 func_800BBEAC(M2C_UNK *);
extern s16 D_8015169C;
extern M2C_UNK func_801B1AD0;
u8 func_801B1784(s32 arg0);
M2C_UNK func_800D3994(u8, u8, u16 *);
extern u8 D_801517F0[];
extern s16 D_801518EA[][0x5CE];
extern s16 D_801518F6[][0x5CE];
extern s16 D_801518FC[][0x5CE];
extern u8 D_8015190F[][0xB9C];
extern u16 D_801EC310;
extern u16 D_801EC314;
extern s16 D_801EC316;
u8 func_801B1904(s32 arg0);
extern s16 D_80151A4C[][0x5CE];
extern s16 D_80151A50[][0x5CE];
void func_801B0C9C(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern M2C_UNK D_801CACD0;
extern s32 D_801E9418;
void func_801B0AB0(void);
s32 func_800D4D90(u8 *, s32, s32, s32);
extern MgVec D_801D1340;
extern u16 D_801D1384;
void func_801B0E58(void);
extern void *D_801D1360[];

#endif /* MAGIC_ERAVE_DECLS_H */
