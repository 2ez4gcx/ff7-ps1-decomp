/* Declarations the C of src/magic_mgbeam/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_MGBEAM_DECLS_H
#define MAGIC_MGBEAM_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B099C();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B3D20[];
extern u8 *D_801CBD20;
extern s16 D_80162080;
void func_801B008C(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgSVec D_801B3CD0;
MgMat *func_8003C21C(MgSVec *, MgMat *);
extern MgMat D_801CBD24;
MgMat *func_8003A79C(MgMat *, MgMat *, MgMat *);
extern MgVec D_801B3CD8;
MgMat *func_8003B35C(MgMat *, MgVec *);
extern MgMat D_800FA63C;
MgMat *func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
extern s32 D_801B3C60;
extern s32 D_801517C0;
extern s16 D_801B3CCC;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
void func_801B0864(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_801B03DC(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
extern u8 D_80151915[][0xB9C];
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_800D44E8(MgSVec *, MgMat *);
void func_801B01D8(void);
void func_800D4368(void *, s32, s32);
extern s32 D_801B1B58;
extern u16 D_801B3CF0;
void func_801B0294(void);
extern MgSVec D_801B3D14;
extern MgVec D_801B3CF4;
extern u8 D_801B3D04[];
MgMat *func_8003BF8C(MgSVec *, MgMat *);
void func_8003B69C(s32, s32, s32);
s32 func_800D29D4(void *, s32, s32, s32);
s32 func_800BBA84(s32, s32, s32);
M2C_UNK func_800D2980(M2C_UNK *, s32, s32, s32);
M2C_UNK func_800D5444(s32, s32, s32, void (*)(s32, s32));
extern M2C_UNK D_801B0B14;
extern M2C_UNK D_801B1C1C;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
M2C_UNK func_8003BADC();
s32 func_80042DA8(void);
M2C_UNK func_800D5774(s32);
extern u8 D_800FA6D4;
extern u8 D_801518F6[][0xB9C];
extern struct { s32 x; s32 y; s32 z; } D_801CBD38[];

#endif /* MAGIC_MGBEAM_DECLS_H */
