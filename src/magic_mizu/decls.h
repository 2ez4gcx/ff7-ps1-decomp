/* Declarations the C of src/magic_mizu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MIZU_DECLS_H
#define MAGIC_MIZU_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0AD8();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C28A4[];
extern u8 *D_801DA8A4;
extern s16 D_80162080;
void func_801B0A18(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B04E4(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B032C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003A79C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
void func_800D44E8(MgSVec *, MgMat *);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern u8 D_801C2878[];
extern s32 D_801C288C;
extern s32 D_801C2890;
extern MgSVec D_801C2898;
extern s16 D_801C28A0;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
void func_800BBA84(s32, s32, s32);
extern M2C_UNK D_801B0B54;
void func_801B008C(void);
M2C_UNK func_800D4368(s16 *, M2C_UNK, M2C_UNK);
u8 *func_800D4D90(void *, s32, M2C_UNK, u8 *);
typedef struct { s32 unk0; s32 unk4; } MgAnim;
extern u8 D_801C2868;
extern u8 D_801C2869;
extern u8 D_801C286A;
extern s16 D_801C286C[];
extern MgAnim *D_801C2870[];
void func_801B01A8(void);
s32 func_8003BBDC(s16 *, u8 *, s32 *, s32 *);
void func_80046794(s32, u8 *);
s16 func_80039F5C(s32);
M2C_UNK func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8(void);
M2C_UNK func_800D5774(s16);

#endif /* MAGIC_MIZU_DECLS_H */
