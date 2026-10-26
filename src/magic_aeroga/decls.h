/* Declarations the C of src/magic_aeroga/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_AEROGA_DECLS_H
#define MAGIC_AEROGA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B09F0();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
extern u8 D_801B1A48[];
extern u8 *D_801C9A48;
typedef struct { s16 unk0; u8 pad2[0x12]; } MgObj14;
extern MgObj14 D_801B0AA8[];
MgObj14 *func_801B055C(void);
void func_801B04E8(void);
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_801B095C(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_800BBA84(s32, s32, s32);
void func_801B0754(void);
void func_801B05A8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; } MgPart;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
extern u8 D_80062D98;
extern s16 D_801B0A66;
s32 func_80042DA8();
void func_800D5774(s32);
extern u16 D_801B0A64;
extern s16 D_801B0A94[];
typedef struct { u8 r; u8 g; u8 b; u8 cd; } MgRgb;
typedef struct { s16 r; s16 g; s16 b; } MgColor3;
void func_8003B48C(void *);
void func_8003B51C(void *);
s32 func_8003BD7C(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
void func_80046794(s32, void *);
extern u8 D_800FA63C[];
extern s32 D_801517C0;
extern MgColor3 D_801B0A68[];
void func_801B008C(MgPart *p);

#endif /* MAGIC_AEROGA_DECLS_H */
