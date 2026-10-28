/* Declarations the C of src/magic_flea/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FLEA_DECLS_H
#define MAGIC_FLEA_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B15CC();
void func_801B0880(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgObj20 D_80162978[];
extern u16 D_801D34D0[];
extern u16 D_801D3508;
extern s32 D_801EB5D8;
void func_801B094C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s8 D_801D3510;
extern s8 D_801D3511;
extern s8 D_801D3512;
extern s16 D_801D3514[];
extern u8 D_801D350C[];
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B1698;
extern MgObj20 *D_801EB5DC;
extern s32 D_801EB5E0;
s32 func_800BBEAC(M2C_UNK *);
void func_800D2980(M2C_UNK *, s32, s32, s32);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
void func_801B147C(void);
typedef struct { u8 b[8]; } MgB8;
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
void func_800D3994(s32, s32, void *);
void func_801B0E34(void);
void func_801B0ACC(void);
void func_801B05A4(void);
extern u8 D_801D34EC[];
extern u8 D_801D34ED;
extern u8 D_801D34EE;
extern u16 D_801D34F0;
void func_801B06F8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern MgMat D_800FA63C;
extern u8 D_801D34F8[];
extern u8 D_801D34F9;
extern u8 D_801D34FA;
extern s16 D_801D34FC;
void func_801B0234(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
s32 func_800D29D4(void *, s32, s32, s32);
extern M2C_UNK D_801D327C;
void func_801B03EC(void);
void func_801B0074(void);
extern M2C_UNK D_801D2058;

#endif /* MAGIC_FLEA_DECLS_H */
