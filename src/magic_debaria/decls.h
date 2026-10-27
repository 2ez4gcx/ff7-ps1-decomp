/* Declarations the C of src/magic_debaria/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DEBARIA_DECLS_H
#define MAGIC_DEBARIA_DECLS_H

#include "main/decls.h"
void func_801B0D4C(void);
s32 func_801B12F8();
s32 func_801B0A18(s32 a);
extern s16 D_801B22EC[];
s32 func_801B0ABC(s32 a);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800BBEAC(M2C_UNK *);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern MgObj20 D_80162978[];
extern MgObj20 *D_801CAB1C;
extern s32 D_801CAB20;
s32 func_801B112C();
extern M2C_UNK D_801B0000;
void func_801B0B58(s16 *arg0, s16 *arg1);
void func_801B0D6C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s32 unk8; s32 unkC; u8 pad10[0x1C]; s32 unk2C; } DbTask;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B27C(MgMat *, MgSVec *, s32 *);
void func_8003B35C(MgMat *, s32 *);
void func_8003B69C(s32, s32, s32);
void func_8003BF8C(MgSVec *, MgMat *);
void func_800D5774(s32);
s32 func_801B0CD4(DbTask *, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801B136C[];
extern u8 *D_801CAB18;
void func_801B0F30(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
MgSVec *func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_800D4368(void *, s16, s32);
void func_800D5138(s32);
void func_800D51D4(s32);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 D_801B19C8[];
void func_800D3994(s32, s32, void *);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_801B0314(void *);
extern u8 D_8015190F[][0xB9C];
extern s16 D_80151A46[][0x5CE];
extern s16 D_801518F6[][0x5CE];
typedef struct { u8 pad0[0x24]; s32 unk24; u8 pad28[4]; s32 unk2C; } DbCtx;
typedef struct { s16 vx; s16 vy; s16 vz; s16 f6; s16 f8; s16 fA; s16 fC; s16 fE; s16 f10; s16 f12; s16 f14; s16 f16; } DbTri;
s32 func_80042DA8();
extern DbTri D_801CAB24[][0x40];
void *func_801B0054(DbCtx *arg0, u8 *arg1, s32 *arg2);

#endif /* MAGIC_DEBARIA_DECLS_H */
