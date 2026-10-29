/* Declarations the C of src/magic_osen/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_OSEN_DECLS_H
#define MAGIC_OSEN_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B100C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D2D48[];
extern u8 *D_801EAD48;
extern s16 D_80162080;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801D2D28;
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
extern s32 D_801D2D3C[];
extern s32 D_801D2D40[];
extern s32 D_801D2D44[];
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_801B022C(MgSVec *pos, MgSVec *rot, s16 s);
void func_801B0174(void);
MgMat *func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801590D4;
extern MgObj20 D_801621F0[];
extern s32 D_80163C74;
extern s32 D_801D2944;
extern u16 D_801D2CE4;
M2C_UNK func_800BBA84(M2C_UNK, s32, M2C_UNK);
s32 func_800BBEAC(void (*)());
void func_800D2980(void *, s32, s32, s32);
void func_800D3994(s32, s32, void *);
void *func_800D54EC(s32, void *);
void func_801B0AA0(void);
extern u8 D_80151918[][0xB9C];
extern M2C_UNK D_801B10DC;
extern s32 D_801EAD4C;
void func_801B008C(void);
extern u16 D_801D2CD8;
extern s32 D_801D27BC;
void func_800D4484(s32, s32);
void func_801B02DC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_801D2CEC[];
extern u8 D_801D2CED;
extern u8 D_801D2CEE;
extern s16 D_801D2CF4;
void func_801B08F0(void);
void func_8003B64C(s32 *, s32 *);
void func_8003B6BC(s32, s32);
void func_8003BF8C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern s32 D_801D2D0C[];
extern u16 D_801D2D04;
extern s16 D_801D2D22[];
void func_801B0718(void);
void func_801B040C(s16, s16, s16, s16);
extern s32 D_801D2A0C;
extern u8 D_801D2CFC[];
extern s16 D_801D2D00[];
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8(void);
s32 func_800BC04C(void (*)());
void func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_OSEN_DECLS_H */
