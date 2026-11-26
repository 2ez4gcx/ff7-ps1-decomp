/* Declarations the C of src/magic_nanntoka/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_NANNTOKA_DECLS_H
#define MAGIC_NANNTOKA_DECLS_H

#include "main/decls.h"
void func_801B006C(void);
s32 func_801B2190();
void func_801B20EC(void);
extern u8 D_801E0EAE[];
void func_801B0BF8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B079C();
extern u8 D_80062D98;
extern s16 D_8015169C;
extern MgTask D_80162978[];
void func_801B2114(void);
s32 func_800BBEAC(void (*)());
void func_801B0240();
void func_801B14B8(void);
void func_801B1D48(void);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_801B0018[];
extern M2C_UNK D_801B2234;
extern MgTask *D_801DBEF4;
extern s32 D_801E2DE8;
extern s32 D_801E2DEC;
extern s32 D_801E2DF0;
void func_801B0E10(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
MgMat *func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern s32 D_801517C0;
extern u8 D_801C2294[];
void func_801B1154(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_801B008C();
extern u8 D_801C3470[];
void func_801B0FAC(void);
extern void *D_801C3EE4[];
typedef struct { u32 addr : 24; u32 len : 8; } MgTag;
typedef struct { MgTag tag; u32 pad4; u32 code; s16 sx; s16 sy; s16 dx; s16 dy; s16 w; s16 h; } NnMove;
void func_801B12F4(void);
extern u8 D_801C3244[];
M2C_UNK func_800D5774(s32);
extern u8 D_800F8380;
extern u8 D_80151909[][0xB9C];
void func_801B0C74(void);
typedef struct { MgTag tag; s32 w[9]; } NnPoly;
extern s32 D_801C3E94[];
extern s32 D_801C3E98[];
extern NnPoly *D_801DBEF0;
typedef struct { s16 x; s16 y; s16 z; s16 st; s16 vx; s16 vy; s16 vz; s16 sc; s32 col; } NnPart;
typedef struct { u8 pad0[0xC]; s32 flag; MgSVec v[4]; MgMat tm; u8 pad50[0x1F0]; s32 d[3]; } NnCtx2;
typedef struct { MgTag tag; s32 rgbc; u16 x0; u16 y0; s32 c1; s32 xy1; } NnLine;
typedef struct { u8 b[8]; } NnB8;
extern NnPart D_801E0EA8[300];
extern u16 D_800D3544;
extern u16 D_800D3546;
void func_801B192C(NnCtx2 *arg0, s32 arg1);
typedef struct { u8 r; u8 g; u8 b; u8 pad[17]; } NnCol;
extern NnCol D_801E0EB8[300];
s32 func_80042DA8(void);
void func_8003A08C(MgVec *, MgVec *);

#endif /* MAGIC_NANNTOKA_DECLS_H */
