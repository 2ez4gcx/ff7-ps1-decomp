/* Declarations the C of src/magic_club1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CLUB1_DECLS_H
#define MAGIC_CLUB1_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B1418();
void func_801B1258(void);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
void func_801B1174();
extern s32 D_801E56C4;
void func_801B1298(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_80062D98;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern s32 D_801E56C8;
extern s32 D_801E56CC;
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B14E4;
extern MgTask *D_801E56C0;
void func_801B131C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0B30(void);
void func_801B0E9C(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgVec *func_8003AB84(MgMat *, MgVec *, MgVec *);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
extern u8 D_80151919[][0xB9C];
extern u8 D_80151A46[][0xB9C];
extern MgVec D_801CD69C;
extern MgVec D_801CD6AC;
extern MgSVec D_801E56D0;
extern MgVec D_801E56D8;
extern MgVec D_801E56E8;
void func_801B06E0(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
s32 func_80039A74(s32);
MgMat *func_8003B16C(MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern s32 D_801517C0;
extern M2C_UNK D_801CCF64;
extern s32 D_801E56BC;
void func_801B08F8(void);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
void func_800D4D4C(s32, s32);
s32 func_800D56A8(void *);
extern MgMat D_800FA63C;
void func_801B048C(void);
MgSVec *func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B0150(s32 ang, MgMat *m, MgVec *v);
extern u16 D_801E56D6;
s32 func_80039F5C(s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c);
extern u8 D_80151A4E[][0xB9C];
extern s16 D_80158D00[];
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
s32 func_80039B40(s32);
void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n);
extern u16 D_801518F6[][0x5CE];
void func_801B0F9C();

#endif /* MAGIC_CLUB1_DECLS_H */
