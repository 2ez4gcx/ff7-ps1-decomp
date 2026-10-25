/* Declarations the C of src/magic_kafun/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KAFUN_DECLS_H
#define MAGIC_KAFUN_DECLS_H

#include "main/decls.h"
void func_801B0F18(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0020;
extern M2C_UNK D_801B1460;
extern M2C_UNK func_801B0E14;
void func_801B0F94(s32 arg0, M2C_UNK arg1);
extern s16 D_801D16A8;
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801D16B4[];
extern s32 D_801517C0;
extern u8 *D_801E9D28;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801D1504;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } MgObj8;
extern MgObj8 D_801D16E8[];
MgObj8 *func_801B0308(void);
void func_801B08B4(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern s32 D_801D16CC[];
extern s32 D_801D16D0;
void func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern s16 D_801D16E2;
extern u16 D_801D16C4;
u8 *func_800D29D4(void *, s32, s32, u8 *);

#endif /* MAGIC_KAFUN_DECLS_H */
