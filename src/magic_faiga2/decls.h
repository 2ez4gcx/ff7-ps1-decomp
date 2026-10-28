/* Declarations the C of src/magic_faiga2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FAIGA2_DECLS_H
#define MAGIC_FAIGA2_DECLS_H

#include "main/decls.h"
void func_801B0084(void);
s32 func_801B1770();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern MgTask D_80162978[];
extern MgTask *D_801DBAC0;
extern s32 D_801DBAC4;
extern u8 D_801B0030[];
extern u8 D_801B1808[];
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D574C(s32);
s32 func_800D55F4(s32, s32, s32);
void func_801B162C(void);
void func_801B0BD0(void);
void func_800D4368(void *, s32, s32);
void func_8003B69C(s32, s32, s32);
s32 func_801B0B08(void *, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_801C1928[];
extern u8 *D_801DBABC;
void func_801B128C(void);
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 D_801C2D04[];
void func_801B1128(void);
M2C_UNK func_800D5138(s32);
M2C_UNK func_800D51D4(s32);
void func_801B0D0C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BF8C(MgSVec *, MgMat *);
extern MgMat D_800FA63C;
extern u8 D_801C32E0[];
void func_801B0EF4(void);
typedef struct { u8 b[8]; } MgB8;
typedef struct { u8 v; } MgByte;
M2C_UNK func_800D5774(s32);
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
extern struct { s16 v; } D_800F5B74;
void func_801B13C4(void);
s32 func_80042DA8();
void func_800D54EC(s32, void *);

#endif /* MAGIC_FAIGA2_DECLS_H */
