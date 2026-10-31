/* Declarations the C of src/magic_lgirl/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_LGIRL_DECLS_H
#define MAGIC_LGIRL_DECLS_H

#include "main/decls.h"
s32 func_801B0054(void);
void func_801B0C9C();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B0D28;
extern MgTask D_80162978[];
extern MgTask *D_801E8EC0;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B0BFC(void);
extern s32 D_801E8EC4;
extern s32 D_801E8EC8;
typedef struct { s32 head; s32 tail; s32 count; s32 size; s32 last; s32 prev; s32 buf[1]; } MgRing;
void func_801B0078(MgRing *r, s32 v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_800D3994(s32, s32, void *);
s32 func_800BBEAC(void *);
extern s16 D_8015169C;
extern u8 D_8015190F[][0xB9C];
extern MgSVec D_801E8ECC;
void func_801B093C(void);
void func_801B00F8(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
typedef struct { u8 flag; u8 pad[0x13]; } LgFx;
typedef struct { u8 cnt; u8 pad[2]; LgFx e[1]; } LgFxList;
extern LgFxList D_801D0D72;
extern u8 D_801D0E98;
extern u8 D_801D0E9C[];
extern s32 D_801E8EBC;
void func_801B07D4(void);
s32 func_80039A74();
extern u8 D_801D0EB4[];
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
s32 func_800D574C(s32);
void func_800D5774(s32);
extern s32 D_801E8ED4;
extern s32 D_801E8ED8;
extern s32 D_801E8EDC;
extern s32 D_801E8EE0;
extern s32 D_801E8EE4;
extern M2C_UNK func_801B0270;

#endif /* MAGIC_LGIRL_DECLS_H */
