/* Declarations the C of src/magic_bioga1/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BIOGA1_DECLS_H
#define MAGIC_BIOGA1_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0C8C();
void func_801B0C24(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern s16 D_80162080;
extern u8 D_801B0DA4[];
extern u8 D_801E1EF4[];
extern s32 D_801EDEF4;
void func_801B0600(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern u8 D_801E1CEC;
extern u8 D_801E1CEF;
extern u8 D_801E1CEE;
extern u8 D_801E1CED;
extern s16 D_801E1CF0;
M2C_UNK func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgObj20 D_80162978[];
void func_801B0B94(s32 arg0);
extern u8 D_8015190F[][0xB9C];
s32 func_800BBEAC(void (*)());
void func_800D3994(s32, s32, void *);
s32 func_800D55A4(s32);
void func_801B0958(void);
extern u8 D_801517BC;
extern u16 D_801B0E38[];
extern s16 D_801E1CF4[][16];
void func_800D2980(void *, s32, s32, s32);
void func_800D5444(s32, s32, s32, void *);
s32 func_800D574C(s32);
void func_800D55F4(s32, s32, s32);
void func_801B0778(void);
s32 func_80042DA8(void);
typedef struct { u8 b[8]; } MgB8;
void func_800D5774(s32);
void func_801B03B0(void);
void func_801B0020(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgB8 *D_801DDD88[];
extern u8 D_801D0E88[];
extern MgMat D_801E1CC0;
extern s32 D_801E1CD8;
extern s32 D_801E1CDC;
extern u8 D_801E1CB0[];
extern MgMat D_800FA63C;
void func_8003A63C(void *, void *, void *);
void func_8003B35C(void *, void *);
s32 func_800D29D4(void *, s32, s32, s32);

#endif /* MAGIC_BIOGA1_DECLS_H */
