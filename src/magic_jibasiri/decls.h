/* Declarations the C of src/magic_jibasiri/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JIBASIRI_DECLS_H
#define MAGIC_JIBASIRI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B1094();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C18F0[];
extern s32 D_801D98F0;
extern s16 D_80162080;
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
void func_800D4368(MgSVec *, s32, s32);
extern struct { s32 *unk0; s32 unk4; s16 unk8; } D_801C1888;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 *D_801C1894[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B02DC(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern u16 D_801C18B4;
extern s32 D_801C17C4;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern M2C_UNK D_801B1100;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_801B0FD0;
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);

#endif /* MAGIC_JIBASIRI_DECLS_H */
