/* Declarations the C of src/magic_seija/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_SEIJA_DECLS_H
#define MAGIC_SEIJA_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B0D2C();
extern M2C_UNK D_801C3C28;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern MgTask D_80162978[];
extern u8 D_801C7528[];
extern s32 D_801D7528;
extern s16 D_80162080;
void func_801B0580(void);
s32 func_800BBEAC(M2C_UNK *);
extern u8 D_80062D98;
void func_801B038C(void);
extern u8 D_801B0DE8[];
void func_800D2980(void *, s32, s32, s32);
extern u8 D_801D7530[];
extern s16 D_801D752C;
void func_800D54EC(s32, void *);
void func_801B0638();
extern MgObj20 D_80162996[];
extern u8 D_800F5B71;
extern u8 D_800F5B70;
extern u8 D_800F5B72;
void func_800D52A0(s32, s32);
void func_801B018C(void);
M2C_UNK func_800D4368(s16 *, s32, s32);
s32 func_800D4D90(s32 **, s32, s32, s32);
extern s32 D_801517C0;
extern s32 D_80163C74;
extern s32 *D_801C7490[];
extern u16 D_801C7498;
extern s32 *D_801C749C[];
void func_801B0088(void);
extern s32 *D_801C7474[];
extern u8 D_801C7478;
extern u8 D_801C7479;
extern u8 D_801C747A;
extern s32 *D_801C7480[];
void func_801B0280(void);
extern u8 D_801C74AC;
extern u8 D_801C74AD;
extern u8 D_801C74AE;
extern u16 D_801C74B0[];
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
s32 func_80039A74(s32);
M2C_UNK func_8003A63C(M2C_UNK *, MgMat *, MgMat *);
M2C_UNK func_8003B35C(MgMat *, MgVec *);
M2C_UNK func_8003B48C(MgMat *);
M2C_UNK func_8003B51C(MgMat *);
M2C_UNK func_8003B69C(s32, s32, s32);
M2C_UNK func_8003BF8C(s16 *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern M2C_UNK D_800FA63C;
extern M2C_UNK D_801C2F08;
extern M2C_UNK D_801C34EC;
extern s16 D_801C74BE[];
extern s16 D_801C74C6[];

#endif /* MAGIC_SEIJA_DECLS_H */
