/* Declarations the C of src/magic_koudan2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KOUDAN2_DECLS_H
#define MAGIC_KOUDAN2_DECLS_H

#include "main/decls.h"
void func_801B0030(void);
void func_801B0FF0();
void func_801B0050(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801CBA6C[];
extern u8 *D_801E3A6C;
extern s16 D_80162080;
void func_801B0F30(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK func_801B07FC;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0684(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
extern MgSVec D_801CBA50;
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
extern s16 D_801CBA4A[];
extern s32 D_801517C0;
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B106C;
void func_801B01E4(void);
typedef struct { s32 unk0; s32 unk4; } MgAnim;
void func_800D4368(void *, s16, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern s16 D_801CBA24[];
extern MgAnim *D_801CBA28[];
void func_801B00BC(void);
s32 func_80039A74(s32);
extern u8 D_801CBA14;
extern u8 D_801CBA15;
extern u8 D_801CBA16;
extern u16 D_801CBA18;
void func_801B0308(void);
extern u8 D_801CB560[];
extern u8 D_801CB580[];
extern u8 D_801CB5A0[];
extern u8 D_801CB5C0[];
extern u8 D_801CB61C[];
extern u8 D_801CB63C[];
extern u8 D_801CB65C[];
extern u8 D_801CB67C[];
extern u8 D_801CB69C[];
extern u8 D_801CB6BC[];
extern u8 D_801CB6DC[];
extern u8 D_801CB6FC[];
extern u8 D_801CB71C[];
extern u8 D_801CB73C[];
extern u8 *D_801CBA34[];

#endif /* MAGIC_KOUDAN2_DECLS_H */
