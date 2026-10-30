/* Declarations the C of src/magic_triangle/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TRIANGLE_DECLS_H
#define MAGIC_TRIANGLE_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B1340();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801D31C0[];
extern u8 *D_801EB1C0;
extern s16 D_80162080;
void func_801B1280(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0DC4(void);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
extern MgTask D_80162978[];
M2C_UNK func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B13BC;
void func_801B008C(void);
M2C_UNK func_800D4368(s16 *, M2C_UNK, M2C_UNK);
u8 *func_800D4D90(void *, s32, M2C_UNK, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u8 D_801D30C4[];
extern u16 D_801D30C8;
extern s32 *D_801D30CC[];
void func_801B01A8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
M2C_UNK func_8003B05C(MgMat *, MgMat *);
M2C_UNK func_8003B48C(MgMat *);
M2C_UNK func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
M2C_UNK func_8003BC6C(MgSVec *, MgVec *, s32 *);
M2C_UNK func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern s16 D_801D30EA;
extern MgSVec D_801D30F0;
void func_801B07A0(void);
extern s16 D_801590D4;
extern MgTask D_801621F0[];
extern u8 *D_80163C74;
extern u16 D_801D314C;
extern s32 *D_801D3150[];
void func_801B0BDC(void);
s32 func_80039A74(s32);
s32 func_80042DA8();
s32 func_800BC04C(void (*)());
extern s16 D_801D3194;
extern s16 D_801D3198[];
void func_801B091C(void);
M2C_UNK func_8003A63C(MgMat *, MgMat *, MgMat *);
M2C_UNK func_8003B35C(MgMat *, MgVec *);
M2C_UNK func_8003BF8C(MgSVec *, MgMat *);
extern s16 D_801D3158;
extern MgVec D_801D315C;
extern s16 D_801D3176[];
extern s32 *D_801D317C[];
M2C_UNK func_800D52A0();
M2C_UNK func_800D5774(s32);
extern u8 D_800F5B70[];
void func_801B0320(void);

#endif /* MAGIC_TRIANGLE_DECLS_H */
