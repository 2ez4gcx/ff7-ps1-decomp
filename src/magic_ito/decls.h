/* Declarations the C of src/magic_ito/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ITO_DECLS_H
#define MAGIC_ITO_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0D98();
void func_801B0574(void *arg0, void *arg1);
s32 func_80039A74(s16);
s32 func_80039B40(s16);
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B5578[];
extern u8 *D_801CD578;
extern s16 D_80162080;
void func_801B0CA8(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(void *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151917[][0xB9C];
extern s16 D_801B5550;
void func_801B0440(void);
void func_801B076C(void);
void func_801B008C(void);
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s32 D_801B551C;
extern u16 D_801B555C;
void func_801B0178(void);
typedef struct { u16 v; } MgHalf;
extern MgHalf D_801B5568[];
extern s32 *D_801B556C[];
typedef struct { s16 unk0; s16 unk2; u8 pad4[0x10]; } ItoObj;
extern ItoObj D_801CD57C[];
ItoObj *func_801B0268(void);
void func_801B0604(void);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void *);
extern M2C_UNK D_801B0E70;
extern M2C_UNK D_801B50D8;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8();
void func_800D4D4C(s32, s32);
void func_800D5774(s32);
extern u8 D_800FA6D4;
extern u8 D_80151919[][0xB9C];
void func_801B02F4(u32 arg0);
void func_8003B48C(void *);
void func_8003B51C(void *);
void func_800469C4(void *);
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
void func_80046794(s32, void *);
extern u8 D_800FA63C[];

#endif /* MAGIC_ITO_DECLS_H */
