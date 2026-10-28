/* Declarations the C of src/magic_yu_waku/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_YU_WAKU_DECLS_H
#define MAGIC_YU_WAKU_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0DC8();
void func_801B0D08(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B0A48(void);
extern MgTask D_80162978[];
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0020(void);
extern s16 D_8015169C;
extern u8 D_801D0784[];
extern u8 *D_801E8784;
extern s16 D_80162080;
M2C_UNK func_800D52A0(M2C_UNK, M2C_UNK);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
extern u8 D_801B0E74[];
void func_801B0370(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u16 D_801D073C;
extern s32 *D_801D0740[];
void func_801B00B0(void);
extern s32 D_801D0588;
extern u16 D_801D0714;
void func_801B01EC(void);
typedef struct { s32 unk0; s32 unk4; } MgAnim;
s32 func_80039A74(s32);
extern s16 D_801D0720[];
extern MgAnim *D_801D0724[];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s16 func_8003CC1C(s32, s32);
s32 func_80042DA8();
void func_800D5774(s32);
extern u16 D_801D077C;
void func_801B046C(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
s32 func_80039B40(s32);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern MgMat D_800FA63C;
extern u8 D_801CCF74[];
extern s32 D_801D0754[];
extern s32 *D_801D0760[];
extern s16 D_801D0780;

#endif /* MAGIC_YU_WAKU_DECLS_H */
