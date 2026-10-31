/* Declarations the C of src/magic_night/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_NIGHT_DECLS_H
#define MAGIC_NIGHT_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B2528();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0150(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B25F4;
extern MgTask D_80162978[];
extern MgTask *D_801DBEE4;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_801DBEE8;
extern s32 D_801DBEEC;
extern s32 D_801DBEF0;
void func_801B2420(void);
typedef struct { s32 head; s32 tail; s32 count; s32 size; s32 last; s32 prev; s32 buf[1]; } MgRing;
void func_801B0ECC(MgRing *r, s32 v);
void func_801B1860(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(u8 *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u16 D_801C3EDC;
typedef struct { s16 v; } MgHalf;
extern MgHalf D_801C3EDE;
extern s32 D_801DBEE0;
void func_800D3994(s32, s32, void *);
void func_801B0948(void *);
extern s16 D_801518F6[][0x5CE];
extern u8 D_8015190F[][0xB9C];
extern M2C_UNK D_801C3350;
extern M2C_UNK func_801B1B54;
void func_801B1940(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
extern MgMat D_800FA63C;
void func_801B14C8(void);
typedef struct { void *unk0; s32 unk4; s32 unk8; s32 unkC; u8 pad10[0xCC]; u8 unkDC; u8 unkDD; u8 unkDE; u8 padDF; u8 unkE0; u8 unkE1; u8 unkE2; } NtScr;
void func_8003B16C(MgMat *, MgMat *);
s32 func_801B0E58(NtScr *, s32);
extern M2C_UNK D_801C3964;

#endif /* MAGIC_NIGHT_DECLS_H */
