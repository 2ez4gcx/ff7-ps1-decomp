/* Declarations the C of src/magic_seed/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SEED_DECLS_H
#define MAGIC_SEED_DECLS_H

#include "main/decls.h"
void func_801B0810(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B038C(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B006C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
void func_800D4368(void *, s32, s32);
extern u16 D_801B3E54;
extern s32 D_801517C0;
extern u8 *D_801CBE8C;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B3D88;
void func_801B08D0(s32 arg0, s32 arg1);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B0CC4;
extern M2C_UNK D_801B1D04;
extern M2C_UNK D_801B2D44;
void func_801B0128(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003C21C(MgSVec *, MgMat *);
s32 func_80042DA8(void);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern MgVec D_801B3E5C;
extern struct { s16 v; } D_801B3E76;
extern s16 D_801B3E7A;
extern s16 D_801B3E7C;
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
s16 func_8003CC1C(s32, s32);
M2C_UNK func_800D5774(s32);
extern u8 D_800FA6D4;
extern u16 D_801518F6[][0x5CE];

#endif /* MAGIC_SEED_DECLS_H */
