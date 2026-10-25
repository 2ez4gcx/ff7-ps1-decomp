/* Declarations the C of src/magic_q_shu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_Q_SHU_DECLS_H
#define MAGIC_Q_SHU_DECLS_H

#include "main/decls.h"
void func_801B007C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
void func_800D4368(void *, s32, s32);
extern u16 D_801BDA98;
extern s32 D_801517C0;
extern s32 D_801D5AE8;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801BD9CC;
void func_801B03FC(void);
extern u16 D_801BDAC4;
extern s32 D_801BD84C;
void func_801B0F5C(s32 arg0, s32 arg1);
void func_801B0C5C(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B1028();
extern u8 D_801B0010[];
extern u8 D_801B10A4[];
void func_801B0138(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 unk0; s32 unk4; } MgAnim;
extern MgAnim *D_801BDAA8[];
extern s16 D_801BDAA4[];

#endif /* MAGIC_Q_SHU_DECLS_H */
