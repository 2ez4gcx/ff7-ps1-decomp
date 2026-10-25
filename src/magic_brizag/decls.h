/* Declarations the C of src/magic_brizag/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BRIZAG_DECLS_H
#define MAGIC_BRIZAG_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B324C();
s32 func_801B0A8C(s32 a);
extern s16 D_801C0DB0[];
s32 func_801B0B30(s32 a);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern MgTask D_80162978[];
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B32C8;
extern MgTask *D_801D9600;
extern s32 D_801D9604;
extern M2C_UNK func_801B303C;
void func_801B1D3C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B27C(MgMat *, MgSVec *, MgVec *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801BF388[];
extern s32 D_801D95FC;
void func_801B0BCC(s16 *arg0, s16 *arg1, s32 *arg2);
void func_801B1F08(void);

#endif /* MAGIC_BRIZAG_DECLS_H */
