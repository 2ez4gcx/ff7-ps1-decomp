/* Declarations the C of src/magic_iyashi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_IYASHI_DECLS_H
#define MAGIC_IYASHI_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
M2C_UNK func_801B0D64();
extern M2C_UNK D_801B0E3C;
typedef struct { s16 unk0; u8 pad[0x5A]; } IyObj;
extern IyObj D_801B8388[];
IyObj *func_801B0A28(void);
void func_801B0D04(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801BA778[];
extern u8 *D_801DA778;
extern s16 D_80162080;
void func_801B0978(void);
void func_801B082C(IyObj *arg0);
void func_801B055C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
u8 *func_800D6260(u8 *, s32, s32, u8 *);
extern s32 D_801517C0;
extern u8 D_801B8364;
extern u8 D_80062D98;
void func_801B028C(void);
typedef struct { s32 unk0; s32 unk4; } IyRec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; IyRec *unk14; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } IyTask;
typedef struct { IyRec *rec; s32 pad; u16 f; } IyFrame;
u8 *func_800D4D90(void *, s32, s32, u8 *);
extern IyFrame D_801B834C;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; u8 pad10[0xC]; MgSVec trail[8]; } IyPart;
void func_8003C21C(MgSVec *, MgMat *);
void func_8003B2CC(MgMat *, MgSVec *, MgSVec *);
void func_801B0624(IyObj *arg0);
extern s16 D_801B8372;
extern MgSVec *D_801B8380;
void func_801B035C(void);
typedef struct { u8 b[8]; } IyB8;
s32 func_800BBEAC(M2C_UNK *);
void func_800D5774(s32);
extern s16 D_801B835A;
extern u16 D_80151A4C[][0x5CE];
extern IyRec D_801B81A8;
extern IyRec D_801B8258;
s32 func_8003BD7C(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
void func_80046794(s32, void *);
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_801B0A74(void);
M2C_UNK func_800D55F4(M2C_UNK, s32, M2C_UNK);
s32 func_800D56A8(s16 *);
s32 func_80042DA8();
void func_801B0028(void);
extern s32 D_801B8378;
extern s32 D_801B8384;
extern u16 D_801518F6[];

#endif /* MAGIC_IYASHI_DECLS_H */
