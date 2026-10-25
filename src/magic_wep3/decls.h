/* Declarations the C of src/magic_wep3/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_WEP3_DECLS_H
#define MAGIC_WEP3_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B226C();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B22F8;
extern MgTask D_80162978[];
extern MgTask *D_801EB6B4;
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_801B21F8(void);
extern s32 D_801EB6B8;
extern s32 D_801EB6BC;
s32 func_800BBEAC(void (*)());
void func_800D54EC(s32, void *);
extern s16 D_8015169C;
extern MgTask D_80162994[];
extern u8 D_801EB6C0[];
void func_801B16EC();
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n);

#endif /* MAGIC_WEP3_DECLS_H */
