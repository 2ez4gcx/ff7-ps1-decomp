/* Declarations the C of src/magic_slipl/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SLIPL_DECLS_H
#define MAGIC_SLIPL_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B0824();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern MgObj20 D_80162978[];
extern M2C_UNK D_801B08C0;
extern MgObj20 *D_801D0E68;
extern M2C_UNK func_801B0000;
void func_801B0614(s32 arg0);
void func_801B0460(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_80042DA8();
extern u8 D_80062D98;
extern s16 D_8015169C;
void func_801B035C(void);
void func_801B0074(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B27C(MgMat *, MgSVec *, MgVec *);
MgMat *func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(void *);
void func_8003B51C(void *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s32 func_800D29D4(MgScratch *, s32, s32, s32);
void func_800D5774(s32);
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern u8 D_801B8960[];
extern s32 D_801D0E64;
typedef struct { u8 b[8]; } MgCopy8;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
extern u16 D_801518EC[][0x5CE];
void func_800D4284(void *, s32, void *);
s32 func_800D6260(void *, s32, s32, s32);
extern u8 D_801B8E38[];
extern u16 D_801B8E44;
extern u16 D_801B8E4C;

#endif /* MAGIC_SLIPL_DECLS_H */
