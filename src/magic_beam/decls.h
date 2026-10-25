/* Declarations the C of src/magic_beam/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BEAM_DECLS_H
#define MAGIC_BEAM_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
extern s32 D_801DFA34;
M2C_UNK func_801B1564();
void func_801B007C(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B00A8(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B0300(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03DC(MgSVec *p, MgSVec *q, MgVec *n);
void func_801B04C0(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
typedef struct { s8 v; } MgByte;
extern MgByte D_801C79EC;
extern MgByte D_801C79ED;
extern MgByte D_801C79EE;
extern s32 D_801DFA00;
extern s32 D_801517C0;
extern u8 D_80062D98;
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0184(s32 ang, MgMat *m, MgVec *v);
void func_801B0634(void);
extern u8 D_801C79F8;
extern u8 D_801C79F9;
extern u8 D_801C79FA;
extern u16 D_801C79FC[];

#endif /* MAGIC_BEAM_DECLS_H */
