/* Declarations the C of src/magic_joker1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JOKER1_DECLS_H
#define MAGIC_JOKER1_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
void func_801B1340();
extern M2C_UNK D_801B2F10;
void func_801B1198(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK func_801B10B4;
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
void func_801B0494(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u16 D_801CF9B6;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
extern MgVec D_801B798C;
MgMat *func_8003B16C(MgMat *, MgMat *);
MgSVec *func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern s32 D_801517C0;
extern s32 D_801CF99C;
extern M2C_UNK D_801B2EB4;
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B06E8(void);
void func_801B0900(void);
s32 func_800D56A8(void *);
extern s32 D_801CF9A8;
void func_800D4D4C(s32, s32);
void func_800D55F4(s32, s32, s32);
void func_801B0B38(void);
extern MgSVec D_801CF9B0;
extern s32 D_801CF9AC;
extern u8 D_80151A4E[][0xB9C];
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
extern s16 D_80158D00[];
s32 func_80039F5C(s32);
extern MgVec D_801B797C;
MgVec *func_8003AB84(MgMat *, MgVec *, MgVec *);
void func_801B0EA4(void);
extern u8 D_80151919[][0xB9C];
extern u8 D_80151A46[][0xB9C];
extern MgVec D_801CF9B8;
extern MgVec D_801CF9C8;
void func_801B11C0(void);
void func_801B1244(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B140C;
extern MgTask *D_801CF9A0;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_801CF9A4;
void func_801B0FA4(void);
MgTask *func_800D4FA8(s32);
void func_800D5774(s32);

#endif /* MAGIC_JOKER1_DECLS_H */
