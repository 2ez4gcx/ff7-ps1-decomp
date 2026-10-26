/* Declarations the C of src/magic_climb/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CLIMB_DECLS_H
#define MAGIC_CLIMB_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
s32 func_801B0B44();
extern M2C_UNK D_801B4DFC;
void func_801B0AE4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B6AB0[];
extern u8 *D_801D6AB0;
extern s16 D_80162080;
s32 func_800BBEAC(void (*)());
void func_800D2980(void *, s32, s32, s32);
void func_801B08B4(void);
extern u8 D_801B0BBC[];
extern s32 D_801B6AA8;
extern s32 D_801B6AAC;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003A08C(MgVec *, MgVec *);
void func_801B0028(MgSVec *a, MgSVec *b, s32 k, MgSVec *out);
void func_801B07F4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern struct { u8 v; } D_801B4C00;
extern u16 D_801B66E0;
void func_801B0124(void);
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; MgSVec *unkC; u8 pad10[0x10]; } MgObjP;
void func_8003B48C(void *);
void func_8003B51C(void *);
void func_8003B710(void *, s32, s32 *);
s32 func_8003BD7C(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
void func_80046794(s32, void *);
extern u8 D_800FA63C[];
extern u8 D_801B66C0[];
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { MgSVec v; MgMat m; } ClScratch;
void func_800D5138(s32);
void func_800D51D4(s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_800D5774(s32);
void func_800D41FC(void *, void *, MgMat *);
s32 func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B0304(void);
extern u8 D_800FA6E0[][0x40];
extern u8 D_80151A4C[][0xB9C];
extern ClScratch *D_801B66E4;
typedef struct { MgSVec p0; MgSVec p1; MgSVec q0; MgSVec q1; MgSVec out; MgVec a; MgVec b; MgMat m; s32 flag; } ClScratch2;
typedef struct { u8 b[8]; } ClB8;
typedef struct { MgSVec a; MgSVec b; } ClTrail;
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
extern ClScratch2 *D_801B66D4;
extern MgSVec D_801B66C4[];
extern ClTrail D_801B66E8[];

#endif /* MAGIC_CLIMB_DECLS_H */
