/* Declarations the C of src/magic_harrier/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HARRIER_DECLS_H
#define MAGIC_HARRIER_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0D58();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C940C[];
extern u8 *D_801E140C;
extern s16 D_80162080;
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
MgMat *func_8003A79C(MgMat *, MgMat *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s32 D_801C9338;
extern s16 D_801C93A4;
extern MgSVec D_801C93A8;
extern MgVec D_801C93B0;
extern MgMat D_801E1410;
void func_801B0C20(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
void func_800D44E8(MgSVec *, MgMat *);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151915[][0xB9C];
void func_801B04B4(void);

#endif /* MAGIC_HARRIER_DECLS_H */
