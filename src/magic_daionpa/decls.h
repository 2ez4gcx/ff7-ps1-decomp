/* Declarations the C of src/magic_daionpa/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DAIONPA_DECLS_H
#define MAGIC_DAIONPA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0D98();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801D44B4[];
extern s32 D_801EC4B4;
extern s16 D_80162080;
void func_801B01AC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s16 D_801D443E[];
extern MgSVec D_801D4444;
extern MgTask D_80162978[];
void func_801B04FC(void);
typedef struct { s32 tag; u8 r; u8 g; u8 b; u8 code; } MgColTag;
s32 func_800D4D90(void *, s32, s32, s32);
extern MgColTag D_801D4470;
extern s32 D_801D447C[];
void func_801B008C(void);
typedef struct { s32 unk0; s32 unk4; } MgAnim;
void func_800D4368(void *, s32, s32);
extern s16 D_801D4418[];
extern MgAnim *D_801D441C[];
void func_800BBA84(s32, s32, s32);
s32 func_800BBEAC(void (*)());
void func_800D2980(void *, s32, s32, s32);
void func_800D3994(s32, s32, void *);
void func_800D52A0(s32, s32);
void func_800D54EC(s32, void *);
void func_801B06E4();
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
extern u8 D_80151917[][0xB9C];
extern u8 D_801B0E98[];
extern s32 D_801EC4B8;
void func_801B0324(void);
typedef struct { u16 v; } MgHalf;
void func_8003B35C(MgMat *, MgVec *);
void func_8003B64C(s32 *, s32 *);
void func_8003B6BC(s32, s32);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
extern s16 D_801D444C;
extern s32 D_801D4454;
extern u16 D_801D446A;
extern s32 D_801D44AC;
extern s32 D_801D44B0;

#endif /* MAGIC_DAIONPA_DECLS_H */
