/* Declarations the C of src/magic_dragonn/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DRAGONN_DECLS_H
#define MAGIC_DRAGONN_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B0A54();
void func_801B0074(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern s32 D_801517C0;
extern u8 D_80062D98;
extern u8 D_801C2918[];
extern s32 D_801DA954;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_800D4284(void *, s32, void *);
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B01D8(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
extern u8 D_801C26FC[];
s32 func_800D29D4(void *, s32, s32, s32);
void func_801B037C(void);
extern MgMat D_800FA63C;
extern void *D_801C2924[];
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
void func_801B054C(void);
extern void *D_801C2934[];
extern u8 D_801B0000[];
extern MgTask *D_801DA958;
extern s32 D_801DA95C;
extern M2C_UNK D_801B0B20;
void func_801B08E0(void);
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
void func_801B0720(void);
typedef struct { u8 b[8]; } DrB8;
extern s16 D_801C2944[];
void func_800D5774(s32);

#endif /* MAGIC_DRAGONN_DECLS_H */
