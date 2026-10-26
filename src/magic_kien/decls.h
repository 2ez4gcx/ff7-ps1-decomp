/* Declarations the C of src/magic_kien/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KIEN_DECLS_H
#define MAGIC_KIEN_DECLS_H

#include "main/decls.h"
void func_801B0214(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern u16 D_801C20DC;
extern s32 D_801517C0;
extern u8 *D_801DA114;
extern s32 *D_801C20BC[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003B05C(MgMat *, MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgMat D_800FA63C;
extern s16 D_801C2098;
extern s16 D_801C20A0;
extern MgVec D_801C20A4;
extern MgMat D_801C20F4;
MgMat *func_801B006C(MgSVec *arg0, MgSVec arg1, s16 arg3);
void func_801B013C(void);
extern s32 D_801C1FCC;
extern u16 D_801C20B8;
void func_801B087C(s32 arg0, s32 arg1);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B055C(void);
void func_801B0948();
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B09C4;
extern M2C_UNK D_801B0000;
s32 func_801B0308(void);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, s32 *);
void func_8003B69C(s32, s32, s32);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 D_801518F6[][0xB9C];
extern s16 D_801C20E0;
extern s32 D_801C20E8;
extern s16 D_801C20EE[];
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8(void);
void func_800D4CBC(s32, s32, s32);
M2C_UNK func_800D5774(s32);

#endif /* MAGIC_KIEN_DECLS_H */
