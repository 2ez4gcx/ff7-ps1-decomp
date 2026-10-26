/* Declarations the C of src/magic_elevator/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ELEVATOR_DECLS_H
#define MAGIC_ELEVATOR_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0EF0(void);
void func_801B0E90(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B65BC[];
extern u8 *D_801D65BC;
extern s16 D_80162080;
void func_801B0528(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D4368(s16 *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern s32 D_801517C0;
extern s16 D_801B1114[];
typedef struct { s16 flag; u8 pad[0x22]; } ElvPart;
extern ElvPart D_801B115C[];
ElvPart *func_801B04E0(void);
void func_801B0418(void);
void func_801B0020(ElvPart *);
s32 func_800BBEAC(void (*)());
s32 func_800D7A88(s32, s32, void *, s32, s32, s32);
extern u8 D_80154CA4[];
extern s16 D_801B10EC;
extern s16 D_801B10F0;
extern s16 D_801D65C0;
extern s16 D_801D65C2;
extern s16 D_801D65C4;
extern s32 D_801D65CC;
extern s32 D_801D65D0;
extern s32 D_801D65D4;
void func_801B0BC0(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80039F5C(s32);
extern s32 D_801D65C8;
s32 func_801B0A10(MgSVec *d, MgSVec *p1, MgSVec *p2);
void func_801B0854(MgSVec *pos, MgSVec *v);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 unk0; s16 unk2; MgSVec pos; MgSVec vel; MgSVec rot; MgSVec spin; } ElvFx;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
s32 func_80042DA8(void);
extern s16 D_801B1122[];
extern MgVec D_801B1128;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);
void func_801B05E4(MgSVec *);
extern MgSVec D_801B1140;
extern MgSVec D_801B1148;
extern MgSVec D_801B1150;
extern s32 D_801B113C;
extern s32 D_801B1158;

#endif /* MAGIC_ELEVATOR_DECLS_H */
