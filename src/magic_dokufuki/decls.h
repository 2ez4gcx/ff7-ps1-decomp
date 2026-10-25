/* Declarations the C of src/magic_dokufuki/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DOKUFUKI_DECLS_H
#define MAGIC_DOKUFUKI_DECLS_H

#include "main/decls.h"
void func_801B08C4(s32 arg0, M2C_UNK arg1);
M2C_UNK func_800BBA84(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B0A20;
extern M2C_UNK func_801B07F8;
void func_801B096C(s32 arg0, M2C_UNK arg1);
extern s16 D_801C8E78;
void func_801B031C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern s16 D_8015169C;
extern u8 D_80062D98;
extern MgObj20 D_80162978[];
void func_801B01E8(void);
s32 func_80039A74(s32);
void func_8003C4AC(MgSVec *, MgMat *);
void func_8003C8DC(s32, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);

#endif /* MAGIC_DOKUFUKI_DECLS_H */
