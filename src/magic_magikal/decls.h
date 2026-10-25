/* Declarations the C of src/magic_magikal/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MAGIKAL_DECLS_H
#define MAGIC_MAGIKAL_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B068C();
void func_801B0074(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s8 v; } MgByte;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern MgByte D_801C09A4;
extern MgByte D_801C09A6;
extern MgByte D_801C09A5;
void func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
extern s32 D_801D89AC;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern M2C_UNK D_801B0734;
extern MgTask *D_801D89B0;
extern s32 D_801D89B4;
extern s32 D_801D89B8;
void func_801B058C(void);
extern M2C_UNK func_801B0000;
void func_801B0214(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80042DA8();
void func_800D5774(s32);
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
extern struct { s16 v; } D_800F5B74;
extern MgSVec D_801D89BC;
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
extern u8 D_8015190F[][0xB9C];

#endif /* MAGIC_MAGIKAL_DECLS_H */
