/* Declarations the C of src/magic_veget/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_VEGET_DECLS_H
#define MAGIC_VEGET_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0940();
extern M2C_UNK D_801B6A50;
extern M2C_UNK *D_801C4618;
void func_801B0030(void);
extern M2C_UNK D_801B94D4;
void func_801B0060(void);
extern M2C_UNK D_801BAF38;
void func_801B0090(void);
extern M2C_UNK D_801BC99C;
void func_801B00C0(void);
extern M2C_UNK D_801BF240;
void func_801B00F0(void);
extern M2C_UNK D_801C06A4;
void func_801B0120(void);
extern M2C_UNK D_801C2050;
void func_801B0150(void);
extern M2C_UNK D_801C36AC;
void func_801B08E0(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C461C[];
extern u8 *D_801E461C;
extern s16 D_80162080;
extern M2C_UNK D_801B09B0;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800BBEAC(void (*)());
void func_801B06C4(s32 arg0, s32 arg1);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { MgSVec a; s16 bx; s16 by; s16 bz; s16 bpad; } VgPos;
typedef struct { s16 unk0; s16 unk2; MgSVec pos; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } VgObj;
void func_800D3994(s32, s32, void *);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
extern u8 D_8015190F[][0xB9C];
extern struct { s16 v; u8 pad[0xB9A]; } D_80151A46[];
extern struct { s16 v; u8 pad[0xB9A]; } D_801518F6[];
extern struct { u16 v; u8 pad[0xB9A]; } D_80151A4C[];
extern struct { u16 v; u8 pad[0xB9A]; } D_80151A50[];
extern VgPos *D_801C4614;
void func_801B0180(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { MgSVec v; MgMat m; } VgWork;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } VgTask;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003BF8C(void *, MgMat *);
s32 func_80042DA8(void);
u8 *func_800D29D4(void *, s32, s32, u8 *);
void func_800D3F0C(void *, s32, s32);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_800D5774(s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s32 D_801C45D0;
extern s32 D_801C45D4;
extern s16 D_801C45DA;
extern s32 D_801C45E0;
extern s16 D_801C45EA;
extern s32 D_801C4604[];
extern s32 D_801C4608;
extern s32 D_801C460C;
extern VgWork *D_801C4610;

#endif /* MAGIC_VEGET_DECLS_H */
