/* Declarations the C of src/magic_lunatic/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LUNATIC_DECLS_H
#define MAGIC_LUNATIC_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
void func_801B0D44();
extern M2C_UNK D_801C96E0;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
s32 func_800BBEAC(void (*)());
extern M2C_UNK D_801B0E10;
extern MgTask D_80162978[];
extern MgTask *D_801E23DC;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern s32 D_801E23E0;
extern s32 D_801E23E4;
extern s32 D_801E23E8;
void func_801B0B28(void);
void func_801B007C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; } MgPart18;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u16 D_801CA3C8[];
extern s32 D_801E23D8;
extern MgPart18 D_801E23EC[][0x64];
void func_801B0484(void);
extern u8 D_801CA3D0[];
extern s16 D_801CA3D4[];
void func_801B05F0(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern MgMat D_800FA63C;
extern M2C_UNK D_801C8FF8;
void func_801B0798(void);
extern M2C_UNK D_801C936C;
void func_801B0944(void);
typedef struct { u8 b[8]; } MgB8;
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
extern u8 D_800F5B70[];
extern s16 D_800F5B74[];
void func_800D3994(s32, s32, void *);
s32 func_800D574C(s32);
void func_800D55F4(s32, s32, s32);
void func_800D5774(s32);

#endif /* MAGIC_LUNATIC_DECLS_H */
