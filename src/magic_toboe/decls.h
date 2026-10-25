/* Declarations the C of src/magic_toboe/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TOBOE_DECLS_H
#define MAGIC_TOBOE_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0820();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801B15B0[];
extern u8 *D_801C95B0;
extern s16 D_80162080;
void func_801B030C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
extern MgSVec D_801B1598;
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
extern s16 D_801B1592[];
extern s32 D_801517C0;
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgObj20 D_80162978[];
void func_801B0760(s32 arg0, s32 arg1);
void func_801B0484();
s32 func_800BBEAC(void *);
extern u8 D_80151917[][0xB9C];
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0194(void);
void func_800D44E8(MgSVec *, MgMat *);
extern MgSVec D_801B1580;
MgMat *func_8003A79C(MgMat *, MgMat *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
extern u8 D_801B1570[];
s32 func_800BBA84(s32, s32, s32);
void func_800D2980(void *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void (*)(s32, s32));
extern u8 D_801B089C[];
void func_801B008C(void);
typedef struct { s8 v; } MgByte;
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern MgByte D_801B1568;
extern MgByte D_801B1569;
extern MgByte D_801B156A;
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
s32 func_80042DA8();
u16 *func_800D4FA8(s32);

#endif /* MAGIC_TOBOE_DECLS_H */
