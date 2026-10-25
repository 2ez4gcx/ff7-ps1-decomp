/* Declarations the C of src/magic_hvshot/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HVSHOT_DECLS_H
#define MAGIC_HVSHOT_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B103C();
extern M2C_UNK D_801B10AC;
void func_801B0F88(s16 arg0, s16 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern M2C_UNK func_801B07F8;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B0FDC(void);
extern s16 D_8015169C;
extern u8 D_801B59F8[];
extern u8 *D_801D59F8;
extern s16 D_80162080;
extern M2C_UNK D_801B1A18;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { u8 b[0x40]; } MgMat40;
extern MgMat40 D_800FA6E0[];
extern MgMat D_801B52B4;
extern u8 D_801B52E4[];
extern u8 D_801B52EC[];
extern u16 D_801B52E8;
extern u16 D_801B52F0;
extern s32 D_801B52D8;
extern u8 D_801B52F8[];
extern s32 D_801517C0;
extern u8 D_80062D98;
void func_8003A63C(void *, void *, void *);
void func_8003B35C(void *, void *);
void func_8003B48C(void *);
void func_8003B51C(void *);
void func_8003C21C(void *, void *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
void func_800D5138(s32);

#endif /* MAGIC_HVSHOT_DECLS_H */
