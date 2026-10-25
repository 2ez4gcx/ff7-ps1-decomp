/* Declarations the C of src/magic_dokueki/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DOKUEKI_DECLS_H
#define MAGIC_DOKUEKI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0840();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C0D34[];
extern u8 *D_801D8D34;
extern s16 D_80162080;
void func_801B0780(s32 arg0, s32 arg1);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
extern M2C_UNK func_801B03DC;
s32 func_800BBEAC(void (*)());
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B02A4(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_80062D98;
s32 func_80039A74(s32);
void func_8003C4AC(MgSVec *, MgMat *);
void func_8003C8DC(s32, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B01A8(void);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, void (*)(s32, s32));
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern M2C_UNK D_801B08DC;
void func_801B008C(void);
typedef struct { s32 unk0; s32 unk4; } MgAnim;
void func_800D4368(void *, s32, s32);
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern s32 D_801517C0;
extern u8 D_801C0D18;
extern u8 D_801C0D19;
extern u8 D_801C0D1A;
extern s16 D_801C0D1C[];
extern MgAnim *D_801C0D20[];

#endif /* MAGIC_DOKUEKI_DECLS_H */
