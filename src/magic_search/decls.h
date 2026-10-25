/* Declarations the C of src/magic_search/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SEARCH_DECLS_H
#define MAGIC_SEARCH_DECLS_H

#include "main/decls.h"
void func_801B0170(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801B5414[];
extern s32 D_801517C0;
extern u8 *D_801CD45C;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B5280;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801B0000;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_801B008C(s32 arg0, MgSVec *rot, s16 scale);
void func_801B08B4();
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
extern u8 D_801B0020[];
extern u8 D_801B0954[];
void func_801B07B0();
typedef struct { s16 unk0; s16 unk2; u16 unk4; u16 unk6; u16 unk8; u16 unkA; u16 unkC; u16 unkE; u16 unk10; u16 unk12; u16 unk14; u16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } SrObj;
void func_800D3994(s32, s32, void *);
void func_800D44E8(MgSVec *, void *);
extern u8 D_80151918[][0xB9C];
extern u8 D_8015190F[][0xB9C];
extern u8 D_801B543C[];
extern M2C_UNK func_801B05A0;

#endif /* MAGIC_SEARCH_DECLS_H */
