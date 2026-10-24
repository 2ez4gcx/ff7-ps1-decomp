/* Declarations the C of src/magic_sting/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_STING_DECLS_H
#define MAGIC_STING_DECLS_H

#include "main/decls.h"
void func_801B0040(void);
M2C_UNK func_801B4770();
void func_801B0060(void);
void func_801B4804(void);
M2C_UNK func_8003C21C(M2C_UNK *, M2C_UNK *);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_801B485C;
extern M2C_UNK D_801CC6D0;
extern M2C_UNK D_801CC6F0;
extern M2C_UNK func_801B4640;
s32 func_801B2004(s16 **pp);
extern s16 D_801CD40E[];
s32 func_801B2040(s32 a, s32 b);
s32 func_80039A74(s32);
void func_801B318C(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B2228;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801CD3F0;
extern MgMat D_801CC794;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B31F0(MgSVec *v, s16 scale, s32 dist);
void func_801B3448(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B330C(void);
extern MgTask D_80162978[];
void func_801B40A0(s16 arg0);
extern s32 func_801B3D20;
void func_801B40E4(s16 arg0);
extern s32 func_801B3F1C;
typedef struct { s32 n; MgSVec v[1]; } MgSVecList;
void func_801B1EAC(MgSVecList *a, MgSVec *b, MgSVec *out);
void func_801B1F3C(MgSVecList *a, MgSVec *b, MgSVec *d, s32 t);
extern s16 D_8015169C;
extern u8 D_80062D98;
extern s16 D_800FA666[];

#endif /* MAGIC_STING_DECLS_H */
