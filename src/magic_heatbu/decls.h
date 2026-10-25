/* Declarations the C of src/magic_heatbu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HEATBU_DECLS_H
#define MAGIC_HEATBU_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
s32 func_801B06CC();
void func_801B0074(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s8 v; } MgByte;
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgTask D_80162978[];
extern MgByte D_801C09E4;
extern MgByte D_801C09E5;
extern MgByte D_801C09E6;
extern s32 D_801D89EC;
s32 func_800BBEAC(M2C_UNK *);
void func_800D2980(void *, s32, s32, s32);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern u8 D_801B0774[];
extern MgTask *D_801D89F0;
extern s32 D_801D89F4;
extern s32 D_801D89F8;
extern M2C_UNK func_801B05CC;
extern M2C_UNK D_801B0000;
void func_801B0214(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80042DA8();
void func_800D5774(s32);
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
extern struct { s16 v; } D_800F5B74;
extern MgSVec D_801D89FC;

#endif /* MAGIC_HEATBU_DECLS_H */
