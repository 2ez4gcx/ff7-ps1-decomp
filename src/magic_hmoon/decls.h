/* Declarations the C of src/magic_hmoon/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HMOON_DECLS_H
#define MAGIC_HMOON_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0054(void);
void func_801B1140();
extern M2C_UNK D_801C93D4;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B007C(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0158(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02D4(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03B0(MgSVec *p, MgSVec *q, MgVec *n);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B11CC;
extern MgTask D_80162978[];
extern MgTask *D_801E3740;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B1014(void);
extern s32 D_801E3744;
extern s32 D_801E3748;
s32 func_800BBEAC(void *);
void func_800D3994(s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
extern s16 D_8015169C;
extern s16 D_801518F6[][0x5CE];
extern u8 D_8015190F[][0xB9C];
void func_801B0B00(void);
void func_801B08B4(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003B16C(MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_801B05E8(void *);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801E374C;
extern s32 D_801E3750;
extern s32 D_801E3754;
extern MgMat D_801E375C;
typedef struct { s32 pad[12]; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; } HmScr;
typedef struct { u8 b[8]; } HmB8;
typedef struct { s16 vx; s16 vy; s16 vz; u8 pad[0xB96]; } MgActorPos;
typedef struct { s8 v; } MgByte;
typedef struct { u16 v; } MgHalf;
s32 func_80042DA8(void);
void func_801B0494(void);
M2C_UNK func_800D5774(s32);
extern MgActorPos D_80151A4C[];
extern MgSVec D_80158D00;
extern MgVec D_801CB72C;
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
extern MgHalf D_800F5B74;

#endif /* MAGIC_HMOON_DECLS_H */
