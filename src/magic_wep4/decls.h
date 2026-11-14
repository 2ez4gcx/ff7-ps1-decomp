/* Declarations the C of src/magic_wep4/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_WEP4_DECLS_H
#define MAGIC_WEP4_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B39A8();
void func_801B3934(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B2A4C();
extern s16 D_8015169C;
extern MgTask D_80162978[];
s32 func_800BBEAC(void (*)());
extern s32 D_801ECF74;
extern u8 D_801ECF7C[];
extern MgTask D_80162994[];
void func_800D54EC(s32, void *);
void func_801B0B0C(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
extern u8 D_801D3D68[];
extern s32 D_801ECF6C;
extern s32 D_801517C0;
extern u8 D_80062D98;
extern MgMat D_800FA63C;
void func_8003BF8C(MgSVec *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void D_801B0000();
extern s8 D_800FAFDC;
extern M2C_UNK D_801B3A98;
extern MgTask *D_801ECF70;
extern s32 D_801ECF78;
extern s32 D_801EF50C[];
extern s32 D_801EF534;
void func_801B2918(void);
void func_800D4368(s16 *, s32, s32);
s32 func_800D4D90(u8 *, s32, s32, s32);
extern u16 D_801D4F50;
void func_801B08D0(void);
extern s32 D_801D4F18[];
void func_801B164C(void);
extern u8 D_801D4F24[];
extern u16 D_801D4F2C;
extern u16 D_801ECF88;
extern u8 D_801ECF8C[];
void func_800D3994(s32, s32, void *);
void func_800D4284(void *, s32, MgMat *);
s32 func_80042DA8(void);
void func_801B0074(s16 arg0, s16 *arg1, s16 *arg2);
extern s16 D_801518F4[][0x5CE];
void func_801B1CE0(void);
extern u8 D_801D4F30;
extern u16 D_801D4F38;

#endif /* MAGIC_WEP4_DECLS_H */
