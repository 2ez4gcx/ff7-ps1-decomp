/* Declarations the C of src/magic_frog/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FROG_DECLS_H
#define MAGIC_FROG_DECLS_H

#include "main/decls.h"
void func_801B0008(void);
void func_801B1E14();
void func_801B12E8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern s32 D_801CA93C;
extern s16 D_801CAA74[];
extern u8 *D_801E2AE8;
void func_801B1160(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern u8 D_801CAAE8[];
extern s16 D_80162080;
extern MgObj20 D_80162978[];
void func_801B11CC(void);
typedef struct { s32 *ptr[2]; } MgPtrPair;
extern MgPtrPair D_801B0000;
extern s32 *D_801CAA60;
extern u16 D_801CAA68;
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
void func_800D52A0(s32, s32);
void func_800D5444(s32, s32, s32, void *);
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
extern u8 D_801B1EAC[];
void func_801B1CDC();
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_800BBA84(s32, s32, s32);
void func_800D3994(s32, s32, void *);
void func_800D44E8(MgSVec *, void *);
extern u16 D_801518F6[][0x5CE];
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151918[][0xB9C];
extern u8 D_801CAAC8[];
void func_801B1878(void);
void func_801B13A0(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003B05C(MgMat *, MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern s16 D_801CAA82[];
extern MgSVec D_801CAA88;
s32 func_801B1518(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
s32 func_80039A74(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003A79C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003BADC(MgSVec *, void *, s32 *);
extern u8 D_801C9F8C[];
extern u8 D_801CA280[];
extern s16 D_801CAA90;
extern MgScratch D_801CAA94;
s32 func_80039F5C(s32, s32);
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8();
u16 *func_800D4FA8(s32);
extern s16 D_800F836C;
extern s16 D_801517B4;
extern MgObj20 D_8016297C[];
extern MgSVec D_801CAAC0;

#endif /* MAGIC_FROG_DECLS_H */
