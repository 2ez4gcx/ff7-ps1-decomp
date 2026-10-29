/* Declarations the C of src/magic_faiga/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FAIGA_DECLS_H
#define MAGIC_FAIGA_DECLS_H

#include "main/decls.h"
void func_801B0084(void);
s32 func_801B0F28();
void func_801B0A38(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern MgTask D_80162978[];
extern s16 D_8015169C;
extern s32 D_801517C0;
extern u8 D_80062D98;
extern u16 D_801CAFC0;
extern s32 D_801E2FC4;
void func_801B0914(void);
void func_800D5138(s32);
void func_800D51D4(s32);
extern u8 D_801CAFAC[];
void func_801B0284(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
MgMat *func_8003BF8C(MgSVec *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern MgMat D_800FA63C;
extern u8 D_801C9D88[];
void func_801B0458(void);
void func_801B00A4(void);
extern u8 D_801C9364[];
void func_801B0B04(void);
typedef struct { u8 b[8]; } MgB8;
s32 func_800BBEAC(void *);
s32 func_80042DA8(void);
void func_801B0D48(void);
void func_800D3994(s32, s32, void *);
void func_800D54EC(s32, void *);
void func_801B062C(void);
extern u8 D_8015190F[][0xB9C];
extern s16 D_801518F6[][0x5CE];
extern s32 D_801E2FCC;
void func_800D2980(void *, s32, s32, s32);
s32 func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern MgTask *D_801E2FC8;
extern u8 D_801B0030[];
extern u8 D_801B0FC0[];
typedef struct { u8 v; } MgByte;
void func_800D5774(s32);
extern MgByte D_800F5B70;
extern MgByte D_800F5B71;
extern MgByte D_800F5B72;
extern struct { s16 v; } D_800F5B74;

#endif /* MAGIC_FAIGA_DECLS_H */
