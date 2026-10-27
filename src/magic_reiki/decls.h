/* Declarations the C of src/magic_reiki/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_REIKI_DECLS_H
#define MAGIC_REIKI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B0D5C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D6294[];
extern u8 *D_801EE294;
extern s16 D_80162080;
void func_801B0430(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800D4368(void *, s32, s32);
extern u16 D_801D6218;
extern s32 D_801517C0;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801D6084;
void func_801B065C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_801D6244[];
extern u8 D_801D6242;
extern u8 D_801D6241;
extern u8 D_801D6240;
void func_801B008C(void);
s32 func_800C4FC8(M2C_UNK, M2C_UNK, s16);
extern s32 D_80163C74;
extern s16 D_801D61C4;
void func_801B016C(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003BF8C(MgSVec *, MgMat *);
extern MgVec D_801D6264;
void func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern MgScratch D_801D61C8;
extern u8 D_801D10D8[];
extern s16 D_801D620C;
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern u8 *D_801D61D8[];
extern u8 D_801D6204;
extern u8 D_801D6206;
extern u8 D_801D6205;
extern u16 D_801031EA;

#endif /* MAGIC_REIKI_DECLS_H */
