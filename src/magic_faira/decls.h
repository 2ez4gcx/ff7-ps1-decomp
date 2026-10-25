/* Declarations the C of src/magic_faira/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_FAIRA_DECLS_H
#define MAGIC_FAIRA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B031C();
void func_801B02BC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BD7E8[];
extern u8 *D_801DD7E8;
extern s16 D_80162080;
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
s32 func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D574C(s32);
extern M2C_UNK D_801B03A4;
void func_801B020C(s32 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
s32 func_800D55A4(s32);
void func_800D5774(s32);
extern u8 D_8015190F[][0xB9C];
void func_801B0020(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003C21C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern MgSVec D_801BD7B8;
extern MgMat D_801BD7C8;
extern u16 D_801BD7C0[];
extern struct { s32 v; } D_801BD7DC;
extern struct { s32 v; } D_801BD7E0;
extern struct { s32 v; } D_801BD7E4;
extern u8 D_801BD3E4[];

#endif /* MAGIC_FAIRA_DECLS_H */
