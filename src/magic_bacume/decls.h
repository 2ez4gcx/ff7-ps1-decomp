/* Declarations the C of src/magic_bacume/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BACUME_DECLS_H
#define MAGIC_BACUME_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0D5C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B7ED0[];
extern u8 *D_801CFED0;
extern s16 D_80162080;
void func_801B0C9C(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK func_801B08C4;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
typedef struct { s16 unk0; u8 pad2[0x12]; } MgObj14;
extern MgObj14 D_801B6F30[];
MgObj14 *func_801B031C(void);

#endif /* MAGIC_BACUME_DECLS_H */
