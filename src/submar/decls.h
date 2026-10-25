/* Declarations the C of src/submar/ uses (tools/auto_decomp.py adds to this). */
#ifndef SUBMAR_DECLS_H
#define SUBMAR_DECLS_H

#include "main/decls.h"
void func_800A63E4(s32 arg0);
extern s32 D_800AE3C8;
extern s32 D_800AE3F0;
void func_800A162C(void);
M2C_UNK func_800A1444(M2C_UNK, M2C_UNK *);
extern s32 D_800AD340;
extern s32 D_800AD344;
extern s32 D_800AD348;
extern s32 D_800AD34C;
extern M2C_UNK D_800AD904;
extern M2C_UNK D_800AD91C;
typedef struct SubEnt { s32 x; s32 y; s32 z; s32 pad[3]; u32 idx; s32 pad2; } SubEnt;
extern SubEnt D_800B265C[];
void func_800A4B50(SubEnt *p);
void func_800A64C0(s32 arg0);
typedef struct { u32 first; u32 *last; } SubOtEnt;
extern u32 D_801BCF48;
extern SubOtEnt D_800AE644[];
void func_800A6548(s32 arg0);
extern u32 D_801BCF4C;
void func_800A6420(u32 arg0, s32 arg1);
extern u32 D_801BCF08[];
extern SubOtEnt D_800AE5A4[];
void func_800AB484(s32 arg0);
typedef struct { u8 pad[0xA]; u16 flags; u16 y; u16 pad2; } SubTile;
typedef struct { s16 a; s16 b; s16 c; s16 d; } SubTileOut;
extern SubTileOut D_801BCF78[];
void func_800A2E7C(void);
typedef struct { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; u16 flags; s16 fC; s16 fE; } SubTileM;
extern u8 D_800B0E5C[];
extern u32 D_800B1E60;
extern SubTileM D_800B5F4C[];
void func_800A3188(void);
void func_800A12EC(void);
extern s16 D_8009A000[];
extern s32 D_8009A004;
extern s32 D_8009A008;
extern s32 D_800AD330;
extern s32 D_800AD334;
extern s32 D_800AD338;
extern s32 D_800AD33C;
extern u8 D_800B365C[];
extern u8 D_800B565C[];
void func_800A16BC(s32 arg0);
M2C_UNK func_800A4BBC(M2C_UNK *);
extern s32 D_800AD350[];
extern s32 D_800B1E64;
extern s32 D_800B1E70;
extern s32 D_800B1E74;
extern s32 D_800B1E78;
extern s32 D_800B1E7C;
extern s32 D_800B1E80;
extern s32 D_800B1E84;
extern M2C_UNK D_800B1EB0;
typedef struct { s32 x; s32 y; s32 z; u8 pad[0x80]; s16 *p[5]; } SubTrail;
void func_800AA180(SubTrail *a);
void func_800A2FB8(s16 arg0);
extern s32 D_800AE960;

#endif /* SUBMAR_DECLS_H */
