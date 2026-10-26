/* Declarations the C of src/magic_oil/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_OIL_DECLS_H
#define MAGIC_OIL_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0AC4();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801D4778[];
extern u8 *D_801EC778;
extern s16 D_80162080;
void func_801B0A04(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B057C(void);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
extern MgObj20 D_80162978[];
void func_801B01FC(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_800D44E8(MgSVec *, MgMat *);
extern MgSVec D_801D473C;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003A79C(MgMat *, MgMat *, MgMat *);
extern s16 D_801D4744;
extern s32 D_801D4730;
void func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
extern u8 D_801D471C[];
extern s32 D_801517C0;
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801D4734;
void func_800BBA84(s32, s32, s32);
M2C_UNK func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B0B40;
void func_801B008C(void);
MgMat *func_800D4368(void *, s32, s32);
void func_800D4484(s32, s32, MgMat *);
extern s16 D_801590D4;
extern MgTask D_801621F0[];
extern s32 D_80163C74;
extern struct { s8 r; s8 g; s8 b; } D_801D470C;
extern u16 D_801D4710;
extern s32 *D_801D4714[];
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B03B4(void);
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern s32 D_801D4748;
extern s16 D_801D4746;
extern s16 D_801D4752;
extern s32 D_801D4758[];
s32 func_80039F5C();
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8();
s32 func_800BC04C(void (*)());
void func_800D5774(s32);

#endif /* MAGIC_OIL_DECLS_H */
