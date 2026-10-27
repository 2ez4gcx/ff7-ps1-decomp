/* Declarations the C of src/magic_beata/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_BEATA_DECLS_H
#define MAGIC_BEATA_DECLS_H

#include "main/decls.h"
void func_801B0054(void);
void func_801B1184();
void func_801B0074(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
typedef struct { void *unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; } MgScratch;
void func_8003A63C(MgMat *, MgMat *, MgMat *);
void func_8003B35C(MgMat *, MgVec *);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
MgMat *func_8003BF8C(MgSVec *, MgMat *);
s32 func_800D29D4(void *, s32, s32, s32);
extern u8 D_80062D98;
extern MgMat D_800FA63C;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern MgTask D_80162978[];
extern u8 D_801C133C[];
extern s32 D_801DAD30;
void func_801B0238(void);
extern u8 D_801C2130[];
s32 func_800BBEAC(M2C_UNK *);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
void func_800D55F4(s32, s32, s32);
s32 func_800D574C(s32);
extern M2C_UNK D_801B0000;
extern M2C_UNK D_801B121C;
extern MgTask *D_801DAD34;
extern s32 D_801DBC38;
void func_801B10DC(void);
typedef struct { u8 b[8]; } BtB8;
void func_800D54EC(s32, void *);
void func_801B0A04(void);
void func_801B0E28(void);
extern MgSVec D_801DBC3C;
void func_800D5138(s32);
void func_800D51D4(s32);
void func_800D5774(s32);
void func_801B0C90(void);
extern s16 D_801C2D2C;
extern struct { s16 v; } D_800F5B74;
extern s8 D_800F5B70;
extern s8 D_800F5B71;
extern s8 D_800F5B72;
typedef struct { s32 unk0; s16 x; s16 y; s16 z; s16 padA; s32 w[4]; s32 unk1C; } BtItem;
s32 func_80042DA8(void);
extern BtItem D_801DAD38[];
typedef struct { u16 x; u16 y; u16 z; u8 pad[10]; } BtPt;
extern BtPt D_801C2C2C[];
typedef struct { s16 vx; s16 vy; s16 vz; u8 pad[10]; } BtVel;
typedef struct { s32 unk0; s32 unk4; s32 pkt; u8 pad[0x30]; s16 vx; s16 vy; s16 vz; s16 pad42; u8 pad44[0x20]; s32 near; s32 far; s32 j1; s32 j2; } BtScr2;
void func_801B03FC(void *, void *, void *);
extern BtVel D_801C2C34[];
s32 func_801B0620(BtScr2 *s);

#endif /* MAGIC_BEATA_DECLS_H */
