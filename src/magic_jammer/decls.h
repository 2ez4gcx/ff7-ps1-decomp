/* Declarations the C of src/magic_jammer/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JAMMER_DECLS_H
#define MAGIC_JAMMER_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0B44();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801D12D8[];
extern s32 D_801E92D8;
extern s16 D_80162080;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B0BB0;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B0A68;
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_801B01AC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
extern MgSVec D_801D1294;
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
extern s16 D_801D128E[];
extern s32 D_801517C0;
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgTask D_80162978[];
void func_801B0324(void);
typedef struct { s32 tag; u8 r; u8 g; u8 b; u8 code; } MgColTag;
extern MgColTag D_801D129C;
extern s32 D_801D12A8[];
s32 func_800D4D90(void *, s32, s32, s32);

#endif /* MAGIC_JAMMER_DECLS_H */
