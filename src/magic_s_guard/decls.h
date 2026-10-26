/* Declarations the C of src/magic_s_guard/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_S_GUARD_DECLS_H
#define MAGIC_S_GUARD_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
s32 func_801B0B5C();
extern M2C_UNK D_801B10DC;
void func_801B0A7C(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B064C(void);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0AFC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801B3B88[];
extern u8 *D_801D3B88;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
void func_801B09F0(void);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern u8 D_80062D98;
extern s32 D_801D3B8C;
void func_801B0200(void);
extern u8 D_801B3228[];
void *func_801B0228(void);
void func_801B0268(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } SgPart;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32));
void func_801B0028(void);
extern M2C_UNK D_801B0BFC;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { u8 b[8]; } SgB8;
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
void func_801B0444(void);
s32 func_80042DA8(void);
void func_800D52A0(s32, s32);
void func_800D5774(s32);
void func_8003B2CC(MgMat *, MgSVec *, void *);
void func_8003C21C(MgSVec *, MgMat *);
typedef struct { u8 r; u8 g; u8 b; u8 cd; } SgRgb;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
extern SgRgb D_801B3214;
extern s32 D_801517C0;
extern MgMat D_800FA63C;
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_801B3220;
extern u8 D_801B3221;
extern u8 D_801B3222;
extern M2C_UNK D_801B321C;
void func_800D4284(void *, s32, MgMat *);

#endif /* MAGIC_S_GUARD_DECLS_H */
