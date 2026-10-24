/* Declarations the C of src/magic_chi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CHI_DECLS_H
#define MAGIC_CHI_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
M2C_UNK func_801B061C();
extern M2C_UNK D_801B47E0;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B8080[];
extern u8 *D_801C8080;
extern s16 D_80162080;
void func_801B0088(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_800D4368(MgSVec *, s32, s32);
extern u16 D_801B8034;
extern s32 D_801517C0;
extern s32 D_80163C74;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B471C;

#endif /* MAGIC_CHI_DECLS_H */
