/* Declarations the C of src/magic_rollfire/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ROLLFIRE_DECLS_H
#define MAGIC_ROLLFIRE_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B08C4();
void func_801B0864(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BCE60[];
extern u8 *D_801DCE60;
extern s16 D_80162080;
void func_801B02F4(void);
extern u8 D_801DCE6C;
MgObj20 *func_801B0320(void);
void func_801B0230(void);
extern u8 D_801B093C[];
void func_800D2980(void *, s32, s32, s32);
extern s32 D_801DCE64;
extern s32 D_801DCE68;
s32 func_800BBEAC(void (*)());
void func_801B0610(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80039A74(s32);
s32 func_80042DA8();
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801BCE34;
extern MgSVec *D_801BCE38;
void func_801B0020(MgTask *p);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { MgSVec a; MgSVec b; MgVec v; MgMat m; s32 flag; } RfBuf;
void func_8003ACE4(MgSVec *, MgVec *, s32);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(void *, MgVec *, s32 *);
void func_800D41FC(void *, void *, MgMat *);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D5774(s32);
void func_801B0384(MgSVec *pos, MgSVec *dir, s32 arg2, s32 count);
extern MgMat D_800FA63C;
extern u8 D_80151AC0[][0xB9C];
extern u8 D_801BCE3C[];
extern RfBuf *D_801BCE5C;

#endif /* MAGIC_ROLLFIRE_DECLS_H */
