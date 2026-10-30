/* Declarations the C of src/magic_timedmg/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TIMEDMG_DECLS_H
#define MAGIC_TIMEDMG_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B171C();
void func_801B0020(s32 arg0, void *arg1);
M2C_UNK func_8003B48C(M2C_UNK *);
M2C_UNK func_8003B51C(M2C_UNK *);
M2C_UNK func_8003BBDC(s32, void *, M2C_UNK *, M2C_UNK *);
extern M2C_UNK D_800FA63C;
extern s32 D_801B3164;
void func_801B1688(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern s16 D_80162080;
extern s16 D_801B9A68[];
extern u8 D_801B9D1C[];
extern u8 *D_801D9D1C;
void func_800D52A0(s32, s32);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern u8 D_8015190F[][0xB9C];
extern u8 D_801B1834[];
extern s32 D_801D9D20;
void func_800D2980(void *, s32, s32, s32);
void func_800D3994(s32, s32, void *);
s32 func_800BBEAC(M2C_UNK *);
void func_801B095C(void);
void func_801B1504(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } TdObj;
extern u8 D_80062D98;
extern struct { u8 v; } D_800F5B70;
extern struct { u8 v; } D_800F5B71;
extern struct { u8 v; } D_800F5B72;
s32 func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_800D5774(s32);
void func_801B0DD0(void);
void func_801B0F74(void);
void func_801B128C(void);
extern TdObj D_80162978[];
extern s16 D_801B9A6A;
void func_801B0124(s32, s32);
void func_801B06E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern s32 D_801517C0;
extern u8 D_801B3188[];
extern MgMat D_801B319C;
extern u8 D_801B318C[];
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003B64C(void *, void *);
s32 func_8003B66C(void);
MgMat *func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D4D90(void *, s32, s32, u8 *);
typedef struct { s16 x; s16 y; } TdPt;
extern TdPt D_801B91E8[];
extern s32 D_801B9628[];
extern s32 D_801B3184[];
s32 func_80039F5C(s32);

#endif /* MAGIC_TIMEDMG_DECLS_H */
