/* Declarations the C of src/magic_brizara/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BRIZARA_DECLS_H
#define MAGIC_BRIZARA_DECLS_H

#include "main/decls.h"
void func_801B0714(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s16);
extern s16 D_80151774;
extern M2C_UNK D_801B07A4;
void func_801B0634(s32 arg0);
void func_801B06B4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801B8F98[];
extern u8 *D_801D8F98;
extern s16 D_80162080;
void func_801B0000(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D29D4(M2C_UNK *, s32, s32, u8 *);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern M2C_UNK D_801B8F78;
extern s16 D_801B8F82;
extern MgTask D_80162978[];
void func_801B01C8(void);
extern M2C_UNK D_801B8F88;
extern s16 D_801B8F92;
void func_801B03A4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; MgSVec unk10; MgSVec unk18; } MgObjBriz;
void func_800D5774();
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_BRIZARA_DECLS_H */
