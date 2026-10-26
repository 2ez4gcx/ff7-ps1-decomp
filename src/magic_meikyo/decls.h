/* Declarations the C of src/magic_meikyo/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MEIKYO_DECLS_H
#define MAGIC_MEIKYO_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
s32 func_801B0A80();
extern M2C_UNK D_801C1EB0;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C39D8[];
extern u8 *D_801DB9D8;
extern s16 D_80162080;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; } MeikyoTask;
M2C_UNK func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u8 D_801C39B8;
extern u8 D_801C39B9;
extern u8 D_801C39BA;
void func_801B0094(MeikyoTask *p);
MeikyoTask *func_801B0418(s16 arg0);
extern MeikyoTask D_801DB9DC[];
void func_801B0378(void);
void func_801B0180(MeikyoTask *p);
s32 func_800BBEAC(void *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B089C(void);
extern M2C_UNK D_801B0B28;
extern s16 D_801DD14C;
typedef struct { u32 tag; u8 r0; u8 g0; u8 b0; u8 code; s16 x0; s16 y0; u8 r1; u8 g1; u8 b1; u8 pad; s16 x1; s16 y1; } MeikyoLine;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, void *, s32 *);
s32 func_8003BBDC(MgSVec *, void *, s32 *, s32 *);
void *func_8003C21C(void *, MgMat *);
void func_80046794(s32, void *);
extern MgMat D_800FA63C;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800BBA84(s32, s32, s32);
void func_800D3994(s32, s32, void *);
void func_800D5774(s32);
void func_801B04A0(void);
extern u16 D_801518F6[][0x5CE];
extern u8 D_8015190F[][0xB9C];
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B69C(s32, s32, s32);
void func_8003BF8C(void *, MgMat *);
void func_8003C4AC(MgSVec *, MgMat *);
s32 func_80042DA8();
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 D_801C0B88;
extern u8 D_801C196C;
extern u8 D_801C39D0;
extern s16 D_801C39CA;

#endif /* MAGIC_MEIKYO_DECLS_H */
