/* Declarations the C of src/magic_netsu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_NETSU_DECLS_H
#define MAGIC_NETSU_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0D0C();
void func_801B0644(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801D61E8;
extern u8 D_801D61E9;
extern u8 D_801D61EA;
extern s16 D_801D61EC[];
extern u8 *D_801EE21C;
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern u8 D_801D621C[];
extern s16 D_80162080;
extern MgObj20 D_80162978[];
void func_801B0430(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern u16 D_801D61B0;
extern s32 D_801D601C;
void func_801B008C(void);
s32 func_800C4FC8(s16, M2C_UNK, M2C_UNK);
extern s32 D_80163C74;
extern s16 D_801D615C;
s32 func_800BBEAC(void (*)());
void func_800D2980(void *, s32, s32, s32);
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
void func_801B0BB0(void);
extern u8 D_80151918[][0xB9C];
extern u8 D_801B0DCC[];
extern s16 D_801EE220;
void func_801B04EC(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BF8C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u8 D_801D61B4[];
extern s16 D_801D61CE[];
extern s32 D_801D61D4[];
void func_800D52A0(s32, s32);
void func_800D5774(s32);
void func_801B016C(void);
void func_801B072C(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
extern u16 D_801031EA;
extern u8 D_801D1070[];
extern MgScratch D_801D6160;
extern u8 *D_801D6170[];
extern u8 D_801D619C;
extern u8 D_801D619D;
extern u8 D_801D619E;
extern s16 D_801D61A4;
extern MgVec D_801D620C;
void func_8003B35C(MgMat *, MgVec *);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003C21C(MgSVec *, MgMat *);
s32 func_80042DA8();
extern s16 D_801D61FA[];
extern u8 D_801D6204;
extern u8 D_801D6205;
extern u8 D_801D6206;

#endif /* MAGIC_NETSU_DECLS_H */
