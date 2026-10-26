/* Declarations the C of src/magic_korosi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KOROSI_DECLS_H
#define MAGIC_KOROSI_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B0BFC();
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
void func_801B0640(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u16 D_801D11CC;
MgMat *func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
extern s32 D_801E91D0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_801B0CBC;
extern MgTask *D_801E91D4;
extern s32 D_801E91D8;
extern s32 D_801E91FC;
void func_801B0AB0(void);
extern u8 D_801B0000[];
void func_801B048C(void);
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
extern u8 D_801D11BC[];
extern struct { u8 v; } D_801D11BD;
extern struct { u8 v; } D_801D11BE;
void func_801B070C(void);
s32 func_80042DA8(void);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_800D5774(s32);
extern s16 D_80158D00;
extern s16 D_80158D04;
extern MgVec D_801D1178;
extern MgVec D_801D1188[];
extern MgVec D_801D118C[];
extern MgMat D_801E91DC;
typedef struct { s16 unk0; s16 unk2; MgSVec pos; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } KrTask;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern struct { s16 v; u8 pad[0xB9A]; } D_801518F6[];

#endif /* MAGIC_KOROSI_DECLS_H */
