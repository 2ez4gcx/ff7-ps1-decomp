/* Declarations the C of src/magic_search/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SEARCH_DECLS_H
#define MAGIC_SEARCH_DECLS_H

#include "main/decls.h"
void func_801B0170(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
M2C_UNK func_800D4368(void *, s32, s32);
extern s16 D_801B5414[];
extern s32 D_801517C0;
extern u8 *D_801CD45C;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B5280;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801B0000;
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_801B008C(s32 arg0, MgSVec *rot, s16 scale);

#endif /* MAGIC_SEARCH_DECLS_H */
