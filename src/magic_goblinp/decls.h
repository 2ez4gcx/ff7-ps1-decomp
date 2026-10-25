/* Declarations the C of src/magic_goblinp/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GOBLINP_DECLS_H
#define MAGIC_GOBLINP_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
M2C_UNK func_801B0E64();
void func_801B0518(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgTask D_80162978[];
extern u16 D_801BA3C4;
extern s32 D_801D23C8;
void func_801B0188(void);
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { MgTag tag; u8 r0; u8 g0; u8 b0; u8 code; s16 x0; s16 y0; u8 r1; u8 g1; u8 b1; u8 pad; s16 x1; s16 y1; } MgLineG2;
typedef struct { s16 x; s16 y; s16 z; s16 pad0; s16 a; s16 b; s16 c; s16 pad1; s16 vx; s16 vy; s16 vz; s16 pad2; } GbPart;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { u8 pad0[8]; s32 otz; u8 pad1[4]; s32 w10; s32 w14; s32 c0; s32 c1; s16 vx; s16 vy; s16 vz; } GbScratch;
extern GbPart D_801D23D8[];
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003B710(void *, s32, void *);
s32 func_8003BBDC(void *, void *, void *, void *);

#endif /* MAGIC_GOBLINP_DECLS_H */
