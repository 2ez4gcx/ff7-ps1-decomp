/* Declarations the C of src/magic_saikyo/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SAIKYO_DECLS_H
#define MAGIC_SAIKYO_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B10A8();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D60F4[];
extern u8 *D_801EE0F4;
extern s16 D_80162080;
void func_801B0758(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801D607C[];
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801D5DA4;
void func_801B0980(void);
extern s16 D_801D60A8[];
extern u8 D_801D60A6;
extern u8 D_801D60A5;
extern u8 D_801D60A4;
void func_801B0810(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_800FA63C;
extern s32 D_801D60D4;
extern s32 D_801D60D8;
extern s32 D_801D60DC;
extern s16 D_801D608A[];
extern u8 *D_801D6090[];
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, s32 *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);

#endif /* MAGIC_SAIKYO_DECLS_H */
