/* Declarations the C of src/magic_gaishu/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_GAISHU_DECLS_H
#define MAGIC_GAISHU_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B094C();
extern M2C_UNK D_801B2F08;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B3434[];
extern u8 *D_801CB434;
extern s16 D_80162080;
void func_800D54EC(s32, void *);
void func_801B0640(void);
extern MgObj20 D_80162996[];
extern u8 D_801B09E0[];
extern s16 D_801CB438;
extern u8 D_801CB43C[];
void func_801B0094(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, s32 *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003B69C(s32, s32, s32);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
u8 *func_800D29D4(void *, s32, s32, u8 *);
extern volatile u8 D_80062D98;
extern MgMat D_800FA63C;
extern s32 D_801517C0;
extern s16 D_801B33FE[];
extern s16 D_801B340E[];
extern s16 D_801B3414;
extern s16 D_801B3416;
void func_801B027C(void);
extern s16 D_801B341A[];
extern s16 D_801B342A[];
extern s16 D_801B3430;
void func_801B0434(void);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
s32 func_8003BBDC(MgSVec *, u8 *, s32 *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
void func_80046794(s32, u8 *);
s32 func_80042DA8(void);
s32 func_800D574C(s32);
M2C_UNK func_800D5774(s32);
M2C_UNK func_800D52A0(s32, s32);
s32 func_8002DA7C();
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern s32 D_8009A00C;
extern struct { u8 r; u8 g; u8 b; } D_800F5B70;

#endif /* MAGIC_GAISHU_DECLS_H */
