/* Declarations the C of src/magic_osen/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_OSEN_DECLS_H
#define MAGIC_OSEN_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B100C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D2D48[];
extern u8 *D_801EAD48;
extern s16 D_80162080;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801D2D28;
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
extern s32 D_801D2D3C[];
extern s32 D_801D2D40[];
extern s32 D_801D2D44[];
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_801B022C(MgSVec *pos, MgSVec *rot, s16 s);

#endif /* MAGIC_OSEN_DECLS_H */
