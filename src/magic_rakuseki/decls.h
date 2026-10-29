/* Declarations the C of src/magic_rakuseki/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_RAKUSEKI_DECLS_H
#define MAGIC_RAKUSEKI_DECLS_H

#include "main/decls.h"
void func_801B0020(void);
s32 func_801B1048();
void func_801B0040(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C2A3C[];
extern u8 *D_801DAA3C;
extern s16 D_80162080;
void func_801B0464(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801C2988[];
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801C26A8;
s32 func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, s32, s32, void (*)());
void func_801B0F88(s32 arg0, s32 arg1);
extern M2C_UNK D_801B2604;
void func_801B0C58(void);
extern u16 D_801031EA;
void func_800D3994(s32, s32, void *);
void func_801B0D04(void);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151914[][0xB9C];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgMat D_800FA63C;
extern MgMat D_801B0000;
extern MgMat D_801C2A18;
extern s32 D_801C2A2C;
extern s32 D_801C2A30;
extern s32 D_801C2A34;
MgMat *func_801B00AC(MgSVec *pos, MgSVec *rot, s16 scale);
void func_801B01D4(void);
extern u16 D_801C297C;
void func_801B02F8(MgTask *src, s16 vel);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8();
void func_801B07E4(void);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
void func_801B0520();
extern MgVec D_801C29CC;
extern s32 D_801C29DC;
extern s32 D_801C29EC[];
void func_801B0A54(void);
extern MgVec D_801C29F8;
extern M2C_UNK D_801C2A08;
void func_800D5774(s32);

#endif /* MAGIC_RAKUSEKI_DECLS_H */
