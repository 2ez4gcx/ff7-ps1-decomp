/* Declarations the C of src/magic_wlaser/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_WLASER_DECLS_H
#define MAGIC_WLASER_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B083C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C8E68[];
extern u8 *D_801E0E68;
extern s16 D_80162080;
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
void func_800D4368(MgSVec *, s32, s32);
extern struct { s32 *unk0; s32 unk4; s16 unk8; } D_801C8E3C;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 *D_801C8E48[];
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B07A8(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B0364(void);
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
s32 func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern M2C_UNK D_801B08B8;
void func_801B0180(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039F5C(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003A79C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BF8C(void *, MgMat *);
void func_800D44E8(MgSVec *, MgMat *);
extern MgMat D_800FA63C;
extern s32 D_801C893C;
extern s16 D_801C8E5C;
extern u8 D_801C8E60[];
s32 func_80042DA8();
s32 func_800BC04C(void (*)());
void func_800D5774(s32);

#endif /* MAGIC_WLASER_DECLS_H */
