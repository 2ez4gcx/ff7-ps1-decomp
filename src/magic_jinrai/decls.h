/* Declarations the C of src/magic_jinrai/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JINRAI_DECLS_H
#define MAGIC_JINRAI_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
M2C_UNK func_801B02B0();
extern M2C_UNK D_801B3470;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801B5228[];
extern s32 D_801517C0;
extern u8 *D_80163C74;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B3354;
void func_801B01E4(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B00E0(void);

#endif /* MAGIC_JINRAI_DECLS_H */
