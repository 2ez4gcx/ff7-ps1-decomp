/* Declarations the C of src/magic_jammer2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JAMMER2_DECLS_H
#define MAGIC_JAMMER2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0D8C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801D5130[];
extern s32 D_801ED130;
extern s16 D_80162080;
void func_801B01AC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
extern MgSVec D_801D50C0;
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_8003B69C(s32, s32, s32);
extern s16 D_801D50BA[];
extern s32 D_801517C0;
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgTask D_80162978[];
void func_801B04FC(void);
typedef struct { s32 tag; u8 r; u8 g; u8 b; u8 code; } MgColTag;
extern MgColTag D_801D50EC;
extern s32 D_801D50F8[];
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B008C(void);
typedef struct { s32 unk0; s32 unk4; } MgAnim;
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801D5084[];
extern MgAnim *D_801D5088[];
s32 func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void (*)());
void func_800D2980(void *, s32, s32, s32);
void func_800D3994(s32, s32, void *);
void func_800D52A0(s32, s32);
void func_800D54EC(s32, void *);
void func_801B06E4();
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
extern u8 D_80151918[][0xB9C];
extern u8 D_801B0E84[];
extern s32 D_801ED134;
void func_801B0324(void);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B64C(s16 *, s16 *);
void func_8003B6BC(s32, s32);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
extern s16 D_801D50C8;
extern s32 D_801D50D0[];
extern s16 D_801D50E6[];
extern s16 D_801D5128;
extern s16 D_801D512C;

#endif /* MAGIC_JAMMER2_DECLS_H */
