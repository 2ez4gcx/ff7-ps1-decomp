/* Declarations the C of src/magic_jaki/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JAKI_DECLS_H
#define MAGIC_JAKI_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
s32 func_801B0B40();
extern M2C_UNK D_801B1828;
void func_801B0970(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B08A8(void);
extern MgTask D_80162978[];
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0AE0(void);
extern s16 D_8015169C;
extern u8 D_801B3740[];
extern u8 *D_801D3740;
extern s16 D_80162080;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x18]; } JakiSlot;
extern JakiSlot D_801D3750[];
JakiSlot *func_801B004C(s32 arg0);
void func_801B00C4(void);
extern void (*D_801D47B8[])(JakiSlot *);
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void *);
s32 func_800D54BC(s32);
void func_801B09F0(void);
extern u8 D_801B0C30[];
extern s32 D_801D3744;
extern s32 D_801D3748;
extern s32 D_801D374C;
void func_800D5138(s32);
void func_800D51D4(s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern u8 D_80062D98;
void func_801B01BC(MgTask *p);
extern s32 D_801517C0;
extern u8 D_801B2428;
extern u8 D_801B2429;
extern u8 D_801B242A;
extern s16 D_801B242C[];
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; MgMat *unk14; s16 unk18; s16 unk1A; } JakiFx;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_800D461C(MgMat *);
extern MgMat D_800FA63C;
extern u8 D_801B2430[];
extern u8 D_801B2434;
extern u8 D_801B2435;
extern u8 D_801B2436;
void func_801B02C4(JakiFx *p);
typedef struct { u8 b[8]; } JakiB8;
void func_800D5774(s32);
void func_801B0454(void);
s32 func_80042DA8();
void func_8003A79C(MgMat *, MgMat *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_800D44E8(MgSVec *, MgMat *, s32);
extern s32 D_801B0C2C;
extern MgMat D_801B243C;
extern MgMat D_801B2480[];

#endif /* MAGIC_JAKI_DECLS_H */
