/* Declarations the C of src/magic_bacume/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BACUME_DECLS_H
#define MAGIC_BACUME_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0D5C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B7ED0[];
extern u8 *D_801CFED0;
extern s16 D_80162080;
void func_801B0C9C(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B08C4(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
typedef struct { s16 unk0; u8 pad2[0x12]; } MgObj14;
extern MgObj14 D_801B6F30[];
MgObj14 *func_801B031C(void);
s32 func_801B0294(void);
extern u8 D_801B0E40[];
s32 func_800BBA84(s32, s32, s32);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D52A0(s32, s32);
M2C_UNK func_800D5444(s32, s32, s32, void *);
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
void func_801B0368(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801B6ECC;
void func_801B04F8(void);
s32 func_8003BD7C(MgSVec *, MgSVec *, MgSVec *, MgSVec *, u8 *, u8 *, u8 *, u8 *, s32 *, s32 *);
void func_80046794(s32, void *);
extern MgMat D_800FA63C;
void func_801B008C(MgTask *p);
void func_801B06AC(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { u16 v; } MgHalf;
MgMat *func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u16 D_801031EA;
extern s16 D_801B6ED0;
extern MgVec D_801B6ED4;
extern s16 D_801B6EEE;
extern MgHalf D_801B6EF2;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_8003CC1C(s32, s32);
s32 func_80042DA8(void);
M2C_UNK func_800D4CBC(s32, s32, s32);
M2C_UNK func_800D5774(s32);
extern s16 D_801B6EF6[];
extern s16 D_801B6EF8;
extern MgSVec D_801B6EFC;
extern s16 D_801B6F00;
extern MgMat D_801B6F0C;
extern s32 D_801B6F20;
extern s32 D_801B6F24;
extern s32 D_801B6F28;
extern s16 D_801B6F2C;

#endif /* MAGIC_BACUME_DECLS_H */
