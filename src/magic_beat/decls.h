/* Declarations the C of src/magic_beat/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BEAT_DECLS_H
#define MAGIC_BEAT_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
s32 func_801B0DAC();
extern M2C_UNK D_801BB764;
void func_801B0D4C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BD540[];
extern u8 *D_801DD540;
extern s16 D_80162080;
void func_801B0C00(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(M2C_UNK *);
s32 func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
void func_801B09E0(void);
void func_801B0CA0(void);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(s16 *);
extern u8 D_80062D98;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_8016297C;
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0E70;
void func_801B0778(void);
M2C_UNK func_800D4368(s16 *, s16, s16);
u8 *func_800D4D90(void *, s32, M2C_UNK, u8 *);
extern s32 D_801517C0;
extern u8 D_801BB574[];
extern u8 D_801BB66C[];
extern u8 *D_801BD530;
extern u16 D_801BD538;
void func_801B0624(void);
extern u8 D_801BB418;
extern s16 D_801BD52C;
void func_801B0858(void);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8();
void func_801B0028(void);
void func_800D52A0(s32, s32);
void func_8003B69C(s32, s32, s32);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern M2C_UNK D_801BD504;
extern s16 D_801BD50E;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { MgSVec v; MgMat m; } BtScr;
typedef struct { u8 b[8]; } BtB8;
void func_801B03F0(void);
void func_800D5774(s32);
void func_8003C21C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
extern BtScr *D_801BD53C;
void func_801B01BC(void);
typedef struct { s8 v; } MgByte;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { MgMat m; MgSVec rot; MgVec sc; } BtXf;
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
M2C_UNK func_800D4284(s16 *, s16, MgMat *);
extern u8 D_801BD514;
extern MgByte D_801BD518;
extern MgByte D_801BD519;
extern MgByte D_801BD51A;
extern BtXf *D_801BD520;
extern s16 D_801518F4[][0x5CE];

#endif /* MAGIC_BEAT_DECLS_H */
