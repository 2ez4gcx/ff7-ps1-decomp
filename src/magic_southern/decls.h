/* Declarations the C of src/magic_southern/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SOUTHERN_DECLS_H
#define MAGIC_SOUTHERN_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0E30();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801CC294[];
extern u8 *D_801E4294;
extern s16 D_80162080;
extern u8 D_801B0F28[];
void func_800D2980(void *, s32, s32, s32);
void func_801B06FC();
extern s16 D_801E42A0;
s32 func_800BBEAC(void *);
extern MgObj20 D_8016297C[];
extern u8 D_80151918[][0xB9C];
void func_800D3994(s32, s32, void *);
extern u8 D_801E4298[];
void func_800D54EC(s32, void *);
void func_800BBA84(s32, s32, s32);
extern u8 D_800F5B72;
extern u8 D_800F5B71;
extern u8 D_800F5B70;
void func_800D52A0(s32, s32);
void func_801B018C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgVec D_801CC280;
void func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern s16 D_801CC25E;
extern s32 D_801CC258;
extern s32 D_801CB6E8[];
extern s32 D_801517C0;
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern s32 D_801CB5EC[];
extern u8 D_80062D98;
void func_801B0334(void);
typedef struct { s8 v; } MgByte;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_800D4368(void *, s16, s32);
extern MgByte D_801CC268;
extern MgByte D_801CC26A;
extern MgByte D_801CC269;
extern s32 D_80163C74;
s32 func_800D4D90(void *, s32, s32, s32);
void func_801B04E8(void);
void func_8003B69C(s32, s32, s32);
extern u8 D_801CC270[];
void func_801B008C(void);
extern s16 D_801590D4;
extern MgTask D_801621F0[];
extern s16 D_801CC238[];
extern s32 *D_801CC23C[];

#endif /* MAGIC_SOUTHERN_DECLS_H */
