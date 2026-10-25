/* Declarations the C of src/magic_queik/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_QUEIK_DECLS_H
#define MAGIC_QUEIK_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B0330();
void func_801B024C();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0074(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgTask D_80162978[];
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
extern u16 D_801518F6[][0x5CE];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
extern s16 D_8015169C;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern s32 D_801517C0;
extern s32 D_801D0AE8;
extern u8 D_801B840C[];
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_800D5774(s32);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)());
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern M2C_UNK D_801B03CC;
extern MgTask *D_801D0AEC;
extern u8 D_801B0000[];

#endif /* MAGIC_QUEIK_DECLS_H */
