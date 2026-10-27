/* Declarations the C of src/magic_daichi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_DAICHI_DECLS_H
#define MAGIC_DAICHI_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B0B28();
extern M2C_UNK D_801B6D0C;
void func_801B0AC8(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B7790[];
extern u8 *D_801D7790;
extern s16 D_80162080;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
M2C_UNK func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801517C0;
extern u8 D_801B6C14[];
extern s16 D_801B7780[];
M2C_UNK func_800BBEAC(void (*)());
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
M2C_UNK func_800D55F4(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D574C(s32);
extern M2C_UNK D_801B0BB0;
void func_801B0A48(s32 arg0);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B0858(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 pos; s16 n; MgSVec pt[21]; } DcRing;
typedef struct { MgSVec a; MgSVec b; MgSVec c; MgSVec d; s32 r; s32 ext; s32 flag; s32 col; } DcScratch;
typedef struct { s32 tag; s32 rgbc; s32 xy0; u16 uv0; u16 clut; s32 xy1; u16 uv1; u16 tpage; s32 xy2; u16 uv2; u16 pad2; s32 xy3; u16 uv3; u16 pad3; } DcFT4;
M2C_UNK func_8003B48C(void *);
M2C_UNK func_8003B51C(void *);
s32 func_8003BD7C(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
M2C_UNK func_80046794(s32, void *);
extern u8 D_800FA63C[];
extern DcScratch *D_801B7784;
void func_801B00E8(DcRing *arg0, s32 arg1);
void func_801B03DC(void);
typedef struct { s16 unk0; s16 unk2; DcRing *ring; u16 unk8; s16 unkA; u16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } DcTask;
typedef struct { u16 vx; u16 vy; u16 vz; } DcVec;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8(void);
extern DcVec *D_801B7788;
typedef struct { u8 b[8]; } DcB8;
M2C_UNK func_800D5774(s32);
extern DcRing D_801D7794[];
extern s32 D_801B6D08;
extern s32 D_801B778C;

#endif /* MAGIC_DAICHI_DECLS_H */
