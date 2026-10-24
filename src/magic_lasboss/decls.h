/* Declarations the C of src/magic_lasboss/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LASBOSS_DECLS_H
#define MAGIC_LASBOSS_DECLS_H

#include "main/decls.h"
void func_801B0040(void);
M2C_UNK func_801B2A50();
s32 func_801B0060(s16 **pp);
extern s16 D_801E6C06[];
s32 func_801B009C(s32 t, s32 s);
s32 func_80039A74(s32);
void func_801B11C0(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B018C;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B141C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern s16 D_8015169C;
void func_800D4368(MgSVec *, s32, s32);
extern u16 D_801D6ACC;
extern s32 D_801517C0;
extern s32 D_801E6BD8;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801D5EA8;

#endif /* MAGIC_LASBOSS_DECLS_H */
