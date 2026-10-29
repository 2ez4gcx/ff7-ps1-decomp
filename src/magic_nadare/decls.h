/* Declarations the C of src/magic_nadare/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_NADARE_DECLS_H
#define MAGIC_NADARE_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B1FDC();
void func_801B1158(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D5378[];
extern u8 *D_801ED378;
extern s16 D_80162080;
void func_801B1910(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801D5354[];
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801D511C;
void func_801B1500(void);
extern s32 D_801D5244;
extern u16 D_801D5314;
void func_801B1820(void);
extern s32 D_801D4F94;
extern s16 D_801D5308;
extern u16 D_801D5348;
void func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void (*)());
void func_800D2980(M2C_UNK *, s32, s32, s32);
void func_800D3994(s32, s32, void *);
s32 func_800D52A0(s32, s32);
void func_800D54EC(s32, void *);
s32 func_801B11C4(void);
void func_801B1C54(void);
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
extern u8 D_80151918[][0xB9C];
extern M2C_UNK D_801B2118;
extern s16 D_801ED97C;
void func_801B1350(void);
typedef struct { s16 a; s16 b; s16 c; s16 d; } NdRec;
extern s16 D_801ED37C[];
extern s16 D_801ED47C[];
extern NdRec D_801ED57C[];
extern s32 D_801D4C9C;
extern u8 D_801D4CA4[];
extern s16 D_801D530A;
extern u8 D_801D4CA0[];
void func_801B15C8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
u8 *func_801B0020(void *, s32, s32, u8 *, void *, MgMat *, MgMat *);
extern MgMat D_800FA63C;
extern MgSVec D_801D5318;
extern MgVec D_801D5320;
extern u8 D_801D5330[];
void func_801B19CC(void);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u16 D_801031EA[];
extern MgVec D_801D5358;
extern s32 D_801D536C;
extern s16 D_801D5372;
s32 func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_NADARE_DECLS_H */
