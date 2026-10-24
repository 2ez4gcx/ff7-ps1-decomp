/* Declarations the C of src/magic_thunder2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_THUNDER2_DECLS_H
#define MAGIC_THUNDER2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B147C();
void func_801B00B0(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
M2C_UNK func_800D4368(void *, s32, s32);
extern struct { s32 *unk0; s32 unk4; s16 unk8; } D_801D2174;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 *D_801D2180[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B0020(void);
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
extern s16 D_8015169C;
extern s16 D_80162080;
extern u8 D_801D220C[];
extern u8 *D_801EA20C;
void func_801B01A4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_801D2198;
extern u8 D_801D2196;
extern u8 D_801D2195;
extern u8 D_801D2194;
extern MgObj20 D_80162978[];
void func_801B02B8(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
extern u16 D_801D21A4;
extern u8 D_801D21A3;
extern u8 D_801D21A0;
extern u8 D_801D21A2;
extern u8 D_801D21A1;
void func_801B04E8(void);
extern u8 D_801D21AC;
extern u8 D_801D21AE;
extern u8 D_801D21AD;
void func_801B09F4(void);
extern MgVec D_801D21FC;
extern s32 D_801D2204[];
extern s32 D_801D2200;
MgMat *func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
extern s16 D_801D21EA[];
s32 func_800D29D4(void *, s32, s32, s32);

#endif /* MAGIC_THUNDER2_DECLS_H */
