/* Declarations the C of src/magic_tail/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TAIL_DECLS_H
#define MAGIC_TAIL_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B1568();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D2C84[];
extern u8 *D_801EAC84;
extern s16 D_80162080;
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
M2C_UNK func_800D4368(void *, s32, s32);
extern struct { s32 *unk0; s32 unk4; s16 unk8; } D_801D2BD0;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 *D_801D2BDC[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B0180(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_801D2BFC;
extern u8 D_801D2BFA;
extern u8 D_801D2BF9;
extern u8 D_801D2BF8;
void func_801B0294(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
extern u16 D_801D2C08;
extern u8 D_801D2C07;
extern u8 D_801D2C04;
extern u8 D_801D2C06;
extern u8 D_801D2C05;
void func_801B04C4(void);
extern u8 D_801D2C10;
extern u8 D_801D2C12;
extern u8 D_801D2C11;

#endif /* MAGIC_TAIL_DECLS_H */
