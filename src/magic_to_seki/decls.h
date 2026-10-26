/* Declarations the C of src/magic_to_seki/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TO_SEKI_DECLS_H
#define MAGIC_TO_SEKI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B1A58();
void func_801B12E0(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern s16 D_80162080;
extern u8 D_801B9F34[];
extern s32 D_801C1F34;
void func_801B1158(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_8003C21C(MgSVec *, MgMat *);
s32 func_80042DA8();
extern MgSVec D_801B9DF4[];
extern MgSVec D_801B9E94[];
void func_801B1214(void);
void func_801B198C(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
s32 func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_80151919[][0xB9C];
extern u8 D_8015191E[][0xB9C];
void func_801B173C(void);
extern MgObjAwa D_80162978[];
void func_800BBA84(s32, s32, s32);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B1ADC;
void func_801B1340(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern s32 D_801B9CF4;
extern u16 D_801B9DC0;
void func_800D5774(s32);
void func_801B1498(void);
s32 func_80039A74(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, void *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
s32 func_801B0020(void *, s32, s32, s32, void *, void *, void *);
extern MgMat D_800FA63C;
extern s32 D_801B9DC4;
extern s32 D_801B9DC8;
extern s16 D_801B9DCE;
extern u8 D_801B9DD4[];
extern s16 D_801B9DE4;
extern s16 D_801B9DEC;

#endif /* MAGIC_TO_SEKI_DECLS_H */
