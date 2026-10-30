/* Declarations the C of src/magic_spark/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SPARK_DECLS_H
#define MAGIC_SPARK_DECLS_H

#include "main/decls.h"
s32 func_801B0054(void);
void func_801B2200();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0078(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0154(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02D0(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03AC(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B228C;
extern MgTask D_80162978[];
extern MgTask *D_801E39B8;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B2014;
extern s32 D_801E39BC;
extern s32 D_801E39C0;
void func_801B0FAC(void);
M2C_UNK func_800D4368(s16 *, s16, s32);
s32 func_800D4D90(void *, s32, M2C_UNK, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801CB9AC[];
extern u16 D_801CB9B0[];
extern s32 D_801E39B4;
void func_801B0490(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
s32 func_800D29D4(void *, s32, M2C_UNK, s32);
extern u8 D_801CB384;
extern s32 D_801CB970[];
void func_801B0E70(void);
M2C_UNK func_8003B35C(MgMat *, MgVec *);
M2C_UNK func_8003B48C(MgMat *);
M2C_UNK func_8003B51C(MgMat *);
M2C_UNK func_8003BF8C(MgSVec *, MgMat *);
M2C_UNK func_800D4284(s16 *, s32, MgMat *);
extern u8 D_801CB9A0[];
extern u16 D_801CB9A4[];
void func_801B05AC(void);
M2C_UNK func_8003B69C(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_801CADC8;
void func_801B0700(void);
typedef struct { u8 b[8]; } SpB8;
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
s32 func_8003BD1C(MgSVec *, MgSVec *, s16 *, u8 *, u8 *, u8 *, s32 *, s32 *);
s32 func_80042DA8(void);
extern MgSVec D_801E39C4;
extern MgMat D_800FA63C;
void func_801B1098();
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
extern s16 D_801E39CA;

#endif /* MAGIC_SPARK_DECLS_H */
