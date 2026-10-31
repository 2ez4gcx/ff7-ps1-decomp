/* Declarations the C of src/magic_stop/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_STOP_DECLS_H
#define MAGIC_STOP_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B0DB8();
void func_801B02AC(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s32 D_801CB280;
extern M2C_UNK D_801B3194;
extern u8 D_80062D98;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
M2C_UNK func_8003B27C(MgMat *, MgSVec *, MgVec *);
MgMat *func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
void func_801B0510(void);
void func_8003B69C(s32, s32, s32);
extern M2C_UNK D_801B2E94;
extern s16 D_801B3270[];
extern u16 D_801B3278[];
s32 func_800BBEAC(void *);
void func_800D2980(void *, s32, s32, s32);
M2C_UNK func_800D5444(s32, s32, s32, M2C_UNK *);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern u8 D_801B0000[];
extern u8 D_801B0E54[];
extern MgTask *D_801CB284;
extern M2C_UNK func_801B0890;
void func_801B0074(void);
M2C_UNK func_800D5774(s16);
extern M2C_UNK D_801B2EF0;

#endif /* MAGIC_STOP_DECLS_H */
