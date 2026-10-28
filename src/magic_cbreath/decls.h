/* Declarations the C of src/magic_cbreath/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CBREATH_DECLS_H
#define MAGIC_CBREATH_DECLS_H

#include "main/decls.h"
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801C1AA0[];
extern s32 D_801517C0;
extern u8 *D_801DA120;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801C1914;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } MgObj8;
extern MgObj8 D_801C1AE0[];
MgObj8 *func_801B0148(void);
void func_801B0E54(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B0A00(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0F14(s32 arg0, s32 arg1);
extern M2C_UNK D_801B0020;
extern M2C_UNK D_801B18B0;
void func_800BBA84(s32, s32, s32);
void func_800D2980(M2C_UNK *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void *);
void func_801B06A8(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u16 D_801C1AA4;
extern s32 D_801C1AAC[];
extern s32 D_801C1AB0;
extern s16 D_801C1AC2;
void func_801B083C(void);
void func_8003B69C(s32, s32, s32);
extern MgMat D_801B0000;
extern s16 D_801C1AC8;
extern s16 D_801C1AD6;
void func_801B04C8(void);
s32 func_80042DA8(void);
void func_801B01C8(MgTask *p);
MgSVec *func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
void func_80046794(s32, void *);
void func_80046974(void *arg0);
s32 func_80039F5C(s32);
s32 func_8003CC1C(s32, s32);
void func_800D5774(s32);
extern u16 D_801C1ADC;

#endif /* MAGIC_CBREATH_DECLS_H */
