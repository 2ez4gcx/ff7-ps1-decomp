/* Declarations the C of src/magic_shower/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SHOWER_DECLS_H
#define MAGIC_SHOWER_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0D58();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801C3454[];
extern u8 *D_801DB454;
extern s16 D_80162080;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B0DC4;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B0C80(s32 arg0, s32 arg1);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_8015190F[][0xB9C];
M2C_UNK func_800BBA84(M2C_UNK, s32, M2C_UNK);
M2C_UNK func_800D3994(s32, u8, s16 *);
void func_801B08A0(void);
extern MgTask D_80162978[];
void func_801B008C(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u16 D_801C33F8;
extern s32 *D_801C33FC[];
void func_801B018C(void);
extern u8 D_801C3404[];
extern u8 D_801C3408[];
void func_801B056C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
extern s32 D_801C303C;
extern u16 D_801C3430;
extern u8 D_801C3434[];
void func_801B06FC(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
void func_8003C4AC(MgSVec *, MgMat *);
void func_8003C8DC(s32, MgMat *);
s32 func_80042DA8();
void func_801B02B4(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003B05C(MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern s16 D_801C341A;
extern MgSVec D_801C3420;
s32 func_80039F5C(s32);
s16 func_8003CC1C(s32, s32);
M2C_UNK func_800D5774(s32);

#endif /* MAGIC_SHOWER_DECLS_H */
