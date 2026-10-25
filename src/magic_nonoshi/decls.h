/* Declarations the C of src/magic_nonoshi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_NONOSHI_DECLS_H
#define MAGIC_NONOSHI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B2400();
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B1158(s16 mask, MgSVec *out);
void func_801B1304(s32 base, s16 range, MgSVec *out);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80042DA8(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B1434(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist);
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_801B1594(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C641C[];
extern u8 *D_801DE41C;
extern s16 D_80162080;
void func_801B1600(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_801590D4;
extern MgObj20 D_801621F0[];
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801C5BA4[];
extern s32 D_801517C0;
extern u8 *D_80163C74;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801C5938;
void func_801B2340(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK func_801B1EE0;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B1818(void);
extern s16 D_801C5C1C[][4];
extern s16 D_801C5C20[][4];
extern s16 D_801C601C[][4];
extern s16 D_801C6020[][4];

#endif /* MAGIC_NONOSHI_DECLS_H */
