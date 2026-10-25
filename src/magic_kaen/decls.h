/* Declarations the C of src/magic_kaen/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KAEN_DECLS_H
#define MAGIC_KAEN_DECLS_H

#include "main/decls.h"
void func_801B0010(void);
s32 func_801B0F6C();
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0030(s16 mask, MgSVec *out);
void func_801B01DC(s32 base, s16 range, MgSVec *out);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80042DA8(void);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B030C(MgSVec *pos, MgSVec *rot, s16 scale, s32 dist);
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
void func_801B046C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801D3F30[];
extern u8 *D_801EBF30;
extern s16 D_80162080;
void func_801B0EAC(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B0AEC(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B05DC(void);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u16 unk14; s16 unk16; } MgGas;
extern u16 D_801D3EE8;
extern s8 D_801D3EE7;
extern s8 D_801D3EE4;
extern s8 D_801D3EE6;
extern s8 D_801D3EE5;
extern s32 D_801517C0;
extern s32 D_80163C74;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B04D8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 unk0; s32 unk4; } MgGasAnim;
typedef struct { MgGasAnim *anim; } MgGasHold;
extern s16 D_801590D4;
extern MgTask D_801621F0[];
void func_800D4368(s16 *, s32, s32);
extern MgGasHold D_801D3EC8;
extern MgGasAnim *D_801D3ED4[];
extern u16 D_801D3ED0;
s32 func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B0FE8;
void func_801B080C(void);
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
MgMat *func_8003A79C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
s32 func_800BC04C(void (*)());
u8 *func_800D29D4(s32 *, s32, s32, u8 *);
void func_800D44E8(MgSVec *, MgMat *);
extern MgSVec D_801D3EEC;
extern s32 D_801D3EF4;
extern u8 D_801D3F04;
extern s32 D_801D3F10[];
extern MgVec D_801B0000;
M2C_UNK func_800D5774(s32);

#endif /* MAGIC_KAEN_DECLS_H */
