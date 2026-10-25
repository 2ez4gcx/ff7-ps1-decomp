/* Declarations the C of src/magic_laser/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LASER_DECLS_H
#define MAGIC_LASER_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B06F4();
void func_801B0694(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C88F4[];
extern u8 *D_801E88F4;
extern s16 D_80162080;
void func_801B0640(s16 arg0, s16 arg1);
s32 func_800BBEAC(void (*)());
void func_801B048C(void);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0764;
void func_801B02F8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_800D4368(MgSVec *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801C88E4;
void func_801B03D8(void);
extern s16 D_801C88F0;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_800D3994(s32, s32, void *);
s32 func_800D55F4(s32, void *, s32);
s32 func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151918[][0xB9C];
void func_801B0020(void);
typedef struct { s32 tag; s32 rgbc; s16 x0; s16 y0; u8 u0; u8 v0; u16 clut; s16 x1; s16 y1; u8 u1; u8 v1; u16 tpage; s16 x2; s16 y2; u8 u2; u8 v2; u16 pad2; s16 x3; s16 y3; u8 u3; u8 v3; u16 pad3; } MgFT4;
void func_8003A08C(MgVec *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_8003B66C();
s32 func_8003BBDC(void *, void *, s32 *, s32 *);
extern MgMat D_800FA63C;

#endif /* MAGIC_LASER_DECLS_H */
