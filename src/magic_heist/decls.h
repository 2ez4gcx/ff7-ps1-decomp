/* Declarations the C of src/magic_heist/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HEIST_DECLS_H
#define MAGIC_HEIST_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B1170();
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
typedef struct { u8 b[8]; } MgB8;
extern MgB8 D_801B92D8[];
void func_801B0C5C(MgB8 *src);
void func_801B0CA8(MgSVec *a, MgSVec *b, MgSVec *d);
void func_801B0D00(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
void func_8003A28C(MgSVec *, MgSVec *, s32, s32);
M2C_UNK func_800D5774(s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern MgSVec D_801BA378[];
extern MgSVec D_801BA788[];
extern MgSVec D_801BAB98[];
extern MgSVec D_801D2FB4[];
extern s32 D_801D2FB0;
void func_801B0E88(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgObjH;
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
s32 func_800BBEAC(M2C_UNK *);
extern u8 D_8015190F[][0xB9C];
extern s16 D_801518F6[][0x5CE];
void func_801B048C(void);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern M2C_UNK D_801B1208;
extern MgObj20 *D_801D2FAC;
extern M2C_UNK D_801B0000;
typedef struct { s32 v; } MgWord;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern MgSVec D_801031E8;
extern MgSVec D_80158D00;
extern u8 D_801B9288[];
extern u8 D_801B92D4[];
extern s32 D_801D2FA8;
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003B27C(MgMat *, MgSVec *, MgVec *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003BF3C(MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);

#endif /* MAGIC_HEIST_DECLS_H */
