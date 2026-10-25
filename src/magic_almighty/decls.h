/* Declarations the C of src/magic_almighty/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ALMIGHTY_DECLS_H
#define MAGIC_ALMIGHTY_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B04E8();
void func_801B0488(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
extern u8 D_801B05AC[];
extern u8 *D_801D05AC;
s32 func_800BBEAC(M2C_UNK *);
s32 func_800D5444(s32, M2C_UNK, s32, M2C_UNK *);
s32 func_800D54BC(s32);
extern s16 D_800F836C;
extern s32 D_801B05A8;
void func_801B03E4(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D3994(s32, u8, u8 *);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(u8 *);
extern u8 D_8015190F[][0xB9C];
void func_801B01C0(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; MgSVec unk8; MgSVec unk10; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgObjAlm;
s32 func_80042DA8(void);
M2C_UNK func_800D5774(s32);
extern u8 D_80062D98;
extern s16 D_801B059A[];
void func_801B0020(void);
M2C_UNK func_8003B2CC(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8003C21C(M2C_UNK, M2C_UNK);
M2C_UNK func_800D4368(M2C_UNK, s32, s32);
u8 *func_800D6260(u8 *, s32, s32, u8 *);
extern s32 D_801517C0;
extern u8 D_801B0578[];
extern u8 D_801B0584[];
extern s16 D_1F800002;
extern s16 D_1F800004;

#endif /* MAGIC_ALMIGHTY_DECLS_H */
