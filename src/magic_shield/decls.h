/* Declarations the C of src/magic_shield/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SHIELD_DECLS_H
#define MAGIC_SHIELD_DECLS_H

#include "main/decls.h"
void func_801B0048(void);
M2C_UNK func_801B0880();
extern s16 D_801C8F54;
void func_801B0010(void);
extern s16 D_801B0F2C;
void func_801B0074(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B0F50[];
extern u8 *D_801C8F50;
extern s16 D_80162080;
void func_801B07EC(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0490();
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0388(void);
extern u8 D_80062D98;
void func_801B01D8(void);
s32 func_800BBEAC(void (*)());
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgVec D_801B0000;
void func_800D44E8(MgSVec *, MgMat *);
extern MgSVec D_801B0F30;
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_8003A79C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
extern s32 D_801B0F3C;
extern s32 D_801517C0;
extern struct { s16 v; } D_801B0F42;
extern s32 D_801B0F48[];
u8 *func_800D29D4(void *, s32, s32, u8 *);

#endif /* MAGIC_SHIELD_DECLS_H */
