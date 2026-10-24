/* Declarations the C of src/magic_bushin2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BUSHIN2_DECLS_H
#define MAGIC_BUSHIN2_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0008(void);
M2C_UNK func_801B352C();
extern M2C_UNK D_801D8A00;
void func_801B0030(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern s16 D_80162080;
extern MgTask D_80162978[];
extern s32 D_801DB058[];
extern s32 D_801F338C;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgMat D_801DB354;
extern s32 D_801DB368[];
extern s32 D_801DB36C[];
extern s32 D_801DB370[];
MgMat *func_801B0094(MgSVec *pos, MgSVec *rot, s16 s);

#endif /* MAGIC_BUSHIN2_DECLS_H */
