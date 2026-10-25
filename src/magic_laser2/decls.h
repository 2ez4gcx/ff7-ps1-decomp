/* Declarations the C of src/magic_laser2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LASER2_DECLS_H
#define MAGIC_LASER2_DECLS_H

#include "main/decls.h"
void func_801B0010(void);
M2C_UNK func_801B0E20();
void func_801B065C(void *arg0, void *arg1);
s32 func_80039A74(s16);
s32 func_80039B40(s16);
void func_801B0030(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B577C[];
extern u8 *D_801CD77C;
extern s16 D_80162080;
void func_801B01F8(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800D4368(void *, s32, s32);
extern u16 D_801B3068;
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B2F8C;
void func_801B0D30(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B082C();
s32 func_800BBEAC(void *);
extern u8 D_80151917[][0xB9C];
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern s16 D_801B3050;
void func_801B0558();

#endif /* MAGIC_LASER2_DECLS_H */
