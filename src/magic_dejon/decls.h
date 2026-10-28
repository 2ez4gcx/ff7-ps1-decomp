/* Declarations the C of src/magic_dejon/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DEJON_DECLS_H
#define MAGIC_DEJON_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0D0C();
void func_801B0CAC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C6E34[];
extern u8 *D_801E6E34;
extern s16 D_80162080;
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D54EC(s32, M2C_UNK *);
s32 func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B0818();
extern M2C_UNK D_801B0E24;
extern u16 D_801B0E3A[];
extern u16 D_801C6C28[][16];
extern s32 D_801C6E28;
void func_801B03A4(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
MgMat *func_8003C21C(MgSVec *, MgMat *);
M2C_UNK func_8003A63C(MgMat *, MgMat *, MgMat *);
M2C_UNK func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
u8 *func_800D29D4(M2C_UNK *, s32, M2C_UNK, u8 *);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s16 D_801C6C02;
extern MgVec D_801C6C08;
extern s32 D_801C6C10;
extern M2C_UNK D_801C6C18;
extern s16 D_801C6C22;
void func_801B0020(void);
void func_800D2538(M2C_UNK *, u16 *);
u8 *func_800D4D90(M2C_UNK *, s32, M2C_UNK, u8 *);
extern M2C_UNK D_801C6BB0;
extern M2C_UNK D_801C6BBC;
extern MgMat D_801C6BC8;
extern s16 D_801C6BD2;
extern s16 D_801C6BD6;
extern s32 D_801C6BDC;
extern s32 D_801C6BE0;
extern s32 D_801C6BE4;
extern M2C_UNK D_801C6BE8;
void func_801B0590(void);
typedef struct { s16 vx; s16 vy; s16 vz; u8 pad[0xB96]; } MgActorPos;
typedef struct { u8 b[8]; } MgBytes8;
void func_800B8E48(u8);
extern MgActorPos D_80151A4C[];
extern s16 D_801518EA[][0x5CE];
s32 func_80042DA8(void);
void func_801B0238(void);
extern s16 D_801517B4;
extern MgSVec D_801C6E2C;
s32 func_80039A74(s32);
M2C_UNK func_800D4368(MgSVec *, s16, M2C_UNK);
u8 *func_800D6260(M2C_UNK *, s32, M2C_UNK, u8 *);
extern M2C_UNK D_801C6BF0;
extern s8 D_801C6BF8;
extern s8 D_801C6BF9;
extern s8 D_801C6BFA;

#endif /* MAGIC_DEJON_DECLS_H */
