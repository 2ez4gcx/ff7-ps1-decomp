/* Declarations the C of src/magic_kinzan/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KINZAN_DECLS_H
#define MAGIC_KINZAN_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0678();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B10B4[];
extern u8 *D_801C90B4;
extern s16 D_80162080;
void func_801B05B4(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B02B0(void);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
s32 func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B06F4;
void func_801B008C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { u8 r; u8 g; u8 b; u8 code; } MgColTag;
void func_8003B05C(MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D4D90(u8 *, s32, s32, u8 *);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern u8 D_801B109C[];
typedef struct { u8 v; } MgByte;
extern MgByte D_801B10A0;
extern MgByte D_801B10A1;
extern MgByte D_801B10A2;
extern u8 D_801B10A3;
extern u16 D_801B10A4;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8(void);
s32 func_800C4FC8(s32, s32, s32);
M2C_UNK func_800D5774(s32);
extern s32 D_80163C74;
extern s16 D_801B10A8;
extern MgSVec D_801B10AC;

#endif /* MAGIC_KINZAN_DECLS_H */
