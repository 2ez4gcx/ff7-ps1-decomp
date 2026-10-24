/* Declarations the C of src/magic_awa/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_AWA_DECLS_H
#define MAGIC_AWA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B1128();
void func_801B1068(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern M2C_UNK func_801B0CB4;
void func_801B0458(void);
M2C_UNK func_800D4368(void *, s32, s32);
M2C_UNK func_801B0148(M2C_UNK, s16, M2C_UNK, s16);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s16 D_801C9834;
extern s16 D_801C9836;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } MgObj8;
extern MgObj8 D_801C9868[];
MgObj8 *func_801B0560(void);
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800D4D90(void *, s32, s32, s32);
extern s32 D_801517C0;
extern s32 D_801C9704;
extern s16 D_801C9830[];
extern u8 *D_801E1EA8;
extern MgObj20 D_80162978[];
void func_801B0020(void);
extern u8 D_801C9EA8[];
extern s16 D_80162080;

#endif /* MAGIC_AWA_DECLS_H */
