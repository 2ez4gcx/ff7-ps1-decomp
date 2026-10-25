/* Declarations the C of src/magic_kaen2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KAEN2_DECLS_H
#define MAGIC_KAEN2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B10BC();
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0020(s16 mask, MgSVec *out);
void func_801B01CC(s32 base, s16 range, MgSVec *out);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80042DA8(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B02FC(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist);
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_801B045C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D4140[];
extern u8 *D_801EC140;
extern s16 D_80162080;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B1128;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B0FF0;
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_801B0658(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u16 unk14; s16 unk16; } MgGas;
extern u16 D_801D40E8;
extern s8 D_801D40E7;
extern s8 D_801D40E4;
extern s8 D_801D40E6;
extern s8 D_801D40E5;
extern s32 D_801517C0;
extern s32 D_80163C74;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;

#endif /* MAGIC_KAEN2_DECLS_H */
