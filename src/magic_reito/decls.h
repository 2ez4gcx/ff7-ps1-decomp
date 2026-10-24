/* Declarations the C of src/magic_reito/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_REITO_DECLS_H
#define MAGIC_REITO_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B2354();
void func_801B12E4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D4B98[];
extern u8 *D_801ECB98;
extern s16 D_80162080;
void func_801B1350(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgSVec D_801D4ADC;
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgMat D_801ED19C;
MgMat *func_8003A79C(MgMat *, MgMat *, MgMat *);
extern MgVec D_801D4AE4;
MgMat *func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern s32 D_801D4A6C;
extern s32 D_801517C0;
extern s16 D_801D4AD8;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B221C(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B1D74(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern u8 D_80151915[][0xB9C];
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_800D44E8(MgSVec *, MgMat *);

#endif /* MAGIC_REITO_DECLS_H */
