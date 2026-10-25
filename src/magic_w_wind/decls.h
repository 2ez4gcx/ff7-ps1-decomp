/* Declarations the C of src/magic_w_wind/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_W_WIND_DECLS_H
#define MAGIC_W_WIND_DECLS_H

#include "main/decls.h"
void func_801B0460(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B4854[];
extern u8 *D_801D4854;
extern s16 D_80162080;
void func_801B04C0();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D3994(s32, u8, u8 *);
s32 func_800D54BC(s32);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
void func_801B0208(void);
extern u8 D_8015190F[][0xB9C];
extern M2C_UNK D_801B061C;
extern s32 D_801B484C;
extern s32 D_801B4850;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec unk8; MgSVec unk10; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgObjAlm;
s32 func_80042DA8(void);
M2C_UNK func_800D5774(s32);
extern u8 D_80062D98;
extern s16 D_801B483E[];
void func_801B0010(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 x; s16 y; u8 u; u8 v; u8 w; u8 h; u8 r; u8 g; u8 b; u8 code; u16 tpage; u16 clut; } MgSpr16;
extern s32 D_801517C0;
extern MgSpr16 D_801B0000;
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_800D4368(MgSVec *, s32, s32);
u8 *func_800D6260(MgSpr16 *, s32, s32, u8 *);

#endif /* MAGIC_W_WIND_DECLS_H */
