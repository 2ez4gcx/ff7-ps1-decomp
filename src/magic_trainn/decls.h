/* Declarations the C of src/magic_trainn/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TRAINN_DECLS_H
#define MAGIC_TRAINN_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B0658();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern MgTask D_80162978[];
extern M2C_UNK D_801B06F0;
extern MgTask *D_801D9138;
extern s32 D_801D913C;
extern M2C_UNK func_801B054C;
extern u8 D_801B0000[];
void func_801B0354(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern M2C_UNK D_801C0810;
extern s32 D_801D9134;
void func_801B0074(void);
void func_800D5774(s32);
typedef struct { u8 r; u8 g; u8 b; u8 pad; s16 f; } TrainnFog;
extern TrainnFog D_800F5B70;

#endif /* MAGIC_TRAINN_DECLS_H */
