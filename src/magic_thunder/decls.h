/* Declarations the C of src/magic_thunder/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_THUNDER_DECLS_H
#define MAGIC_THUNDER_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B06CC();
void func_801B066C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C0E78[];
extern u8 *D_801E0E78;
extern s16 D_80162080;
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B0DAC;
void func_801B05A4(s32 arg0);
void func_801B0180(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s16 *func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s16 D_801C0E64;
void func_800D3994(s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
extern u8 D_8015190F[][0xB9C];
extern u16 D_801518F6[][0x5CE];
void func_801B0350(void);
void func_801B023C(void);
extern s16 D_801C0E70;
void func_801B0020(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
u8 *func_800D29D4(M2C_UNK *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u16 D_801C0E2C;
extern s16 D_801C0E36;
extern struct { u16 v; } D_801C0E3A;
extern s32 D_801C0E40;
extern s32 D_801C0E44;
extern s32 D_801C0E48;
extern M2C_UNK D_801C0E4C;
extern s16 D_801C0E56;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgObjThunder;
void func_800D5774(s32);
s32 func_80042DA8();

#endif /* MAGIC_THUNDER_DECLS_H */
