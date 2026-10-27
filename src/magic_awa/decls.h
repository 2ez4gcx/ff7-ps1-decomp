/* Declarations the C of src/magic_awa/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_AWA_DECLS_H
#define MAGIC_AWA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B1128();
void func_801B1068(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0CB4(void);
void func_801B0458(void);
M2C_UNK func_800D4368(void *, s32, s32);
M2C_UNK func_801B0148(M2C_UNK, s16, M2C_UNK, s16);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s16 D_801C9834;
extern s16 D_801C9836;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } MgObj8;
extern MgObj8 D_801C9868[];
MgObj8 *func_801B0560(void);
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800D4D90(void *, s32, s32, s32);
extern s32 D_801517C0;
extern s32 D_801C9704;
extern s16 D_801C9830[];
extern u8 *D_801E1EA8;
extern MgObj20 D_80162978[];
void func_801B0020(void);
extern u8 D_801C9EA8[];
extern s16 D_80162080;
void func_801B0B04(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u16 D_801C9844;
extern s32 D_801C984C[];
extern s32 D_801C9850;
extern s16 D_801C9862;
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void *);
extern M2C_UNK D_801B1620;
void func_801B05E0(MgTask *p);
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
extern u8 D_801C983C[];
void func_801B0904(void);
s32 func_80042DA8(void);
s16 func_80039F5C(s32);
s32 func_8003CC1C(s32, s32);
void func_800D52A0(s32, s32);
void func_800D5774(s32);
typedef struct { s8 v; } MgByte;
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;

#endif /* MAGIC_AWA_DECLS_H */
