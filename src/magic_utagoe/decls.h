/* Declarations the C of src/magic_utagoe/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_UTAGOE_DECLS_H
#define MAGIC_UTAGOE_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B06EC();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern MgTask D_80162978[];
extern M2C_UNK D_801B0794;
extern MgTask *D_801CC840;
extern s32 D_801CC844;
extern s32 D_801CC848;
void func_801B05EC(void);
extern M2C_UNK D_801B0000;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
extern s16 D_8015169C;
extern u8 D_80151908[][0xB9C];
extern MgSVec D_801CC84C;
void func_801B0218(void);
void func_801B0074(void);
s32 func_80039A74(s32);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
typedef struct { s8 v; } MgByte;
extern MgByte D_801B4834;
extern MgByte D_801B4835;
extern MgByte D_801B4836;
extern s32 D_801CC83C;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
s32 func_80039F5C(s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_80042DA8(void);
M2C_UNK func_800D5774(s32);
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
typedef struct { u16 v; } MgHalf;
extern MgHalf D_800F5B74;

#endif /* MAGIC_UTAGOE_DECLS_H */
