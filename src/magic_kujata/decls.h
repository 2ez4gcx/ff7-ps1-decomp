/* Declarations the C of src/magic_kujata/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KUJATA_DECLS_H
#define MAGIC_KUJATA_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B88A4();
extern M2C_UNK D_801DDD1C;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801F04C8;
extern MgMat D_801EFCE0;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist);
s32 func_801B0184(s16 **pp);
extern s16 D_801F04FA[];
s32 func_801B01C0(s32 t, s32 s);
s32 func_80039A74(s32);
void func_801B12E4(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; u8 pad[0x1C]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B02B0;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B75D8(void);
extern u16 D_801EFC88;
extern s16 D_801EFCAA;
extern u16 D_801F0364;
extern u16 D_801F0354;
extern s32 D_801EFCA4;
extern s32 D_801F0370;
extern M2C_UNK D_801F0334;
void func_8003A63C(void *, void *, MgMat *);
extern M2C_UNK D_801F0374;
void func_801B3878(MgMat *, void *);
void func_801B7F24(s16 arg0);
extern M2C_UNK func_801B7CFC;
void func_801B80A8(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B7F6C(void);
extern MgTask D_80162978[];

#endif /* MAGIC_KUJATA_DECLS_H */
