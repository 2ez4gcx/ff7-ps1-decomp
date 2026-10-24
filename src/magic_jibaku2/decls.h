/* Declarations the C of src/magic_jibaku2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_JIBAKU2_DECLS_H
#define MAGIC_JIBAKU2_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
M2C_UNK func_801B164C();
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0020(s16 mask, MgSVec *out);
void func_801B01CC(s32 base, s16 range, MgSVec *out);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80042DA8(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B02FC(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist);
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_801B045C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D2548[];
extern u8 *D_801EA548;
extern s16 D_80162080;
void func_801B06B0(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u8 D_801D2508;
extern u8 D_801D2509;
extern u8 D_801D250A;
extern s16 D_801D250C;
void func_801B0BB4(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
MgMat *func_8003B35C(MgMat *, MgVec *);
s32 func_800D29D4(void *, s32, s32, s32);
extern s16 D_801D2532[];
extern MgVec D_801D2538;
extern s32 D_801D253C;
extern s32 D_801D2540[];
void func_801B09F4(void);
extern s16 D_801590D4;
extern MgTask D_801621F0[];
extern s32 D_80163C74;
extern u8 D_801D2520;
extern u8 D_801D2521;
extern u8 D_801D2522;

#endif /* MAGIC_JIBAKU2_DECLS_H */
