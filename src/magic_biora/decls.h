/* Declarations the C of src/magic_biora/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BIORA_DECLS_H
#define MAGIC_BIORA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0B90();
void func_801B0B30(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801CCC78[];
extern u8 *D_801ECC78;
extern s16 D_80162080;
void func_801B0350(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u16 D_801CCC68;
M2C_UNK func_800D4368(void *, s32, s32);
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B0410(void);
extern u8 D_801CCC70;
extern u8 D_801CCC73;
extern u8 D_801CCC72;
extern u8 D_801CCC71;
extern s16 D_801CCC74;
void func_801B0A94(s32 arg0, s32 arg1);
s32 func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
M2C_UNK func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_8015190F[][0xB9C];
void func_801B0734(void);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B0C00;
void func_801B0588(void);
s32 func_80042DA8();
void func_801B0020(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 n; MgSVec v[1]; } MgSVecList;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
u8 *func_800D29D4(s32 *, s32, M2C_UNK, u8 *);
M2C_UNK func_800D4284(u8 *, M2C_UNK, MgMat *);
extern s32 D_801CCC10;
extern MgSVecList *D_801CCC20[];
extern MgSVecList *D_801CCC30[];
extern MgMat D_801CCC40;
typedef struct { u8 b[8]; } BrB8;
void func_800D5774(s32);

#endif /* MAGIC_BIORA_DECLS_H */
