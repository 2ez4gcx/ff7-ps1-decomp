/* Declarations the C of src/magic_kona/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_KONA_DECLS_H
#define MAGIC_KONA_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
s32 func_801B0D14();
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801C9498[];
extern u8 *D_801E1498;
extern s16 D_80162080;
void func_801B0AB0(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_800BBEAC(void *);
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
extern u8 D_80151918[][0xB9C];
void func_801B08EC(void);
void func_801B0C4C(void);
extern MgObj20 D_801E149C[];
void func_801B0B70(void);
s32 func_801B0CA4(void);
s32 func_800BBA84(s32, s32, s32);
extern u16 D_801E275C;
extern s16 D_801C943C;
void func_801B0554(void);
M2C_UNK func_800D2980(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800D5444(s32, s32, M2C_UNK, void (*)(s32, s32));
extern M2C_UNK D_801B0DA8;
void func_801B008C(void);
s32 func_800C4FC8(s32, s32, s32);
extern s32 D_80163C74;
extern s16 D_801C943E;
extern u8 D_80062D98;
void func_801B0178(void);
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern u16 D_801C9448;
extern s32 D_801517C0;
extern s32 *D_801C944C[];
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
extern s32 D_801C9000;
extern s32 D_801C9188;
extern u16 D_801C9474;
extern u16 D_801C9480;
void func_801B0728(void);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80042DA8(void);
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BADC(MgSVec *, MgSVec *, s32 *);
void func_8003C4AC(MgSVec *, MgMat *);
void func_8003C8DC(s32, MgMat *);
s32 func_80039F5C(s32);
s32 func_8003CC1C(s32, s32);
void func_800D5774(s32);
void func_801B0298(void);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003B69C(s32, s32, s32);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
MgMat *func_8003C21C(MgSVec *, MgMat *);
MgMat *func_8003B05C(MgMat *, MgMat *);
extern MgMat D_800FA63C;
extern MgSVec D_801C9464;
extern s16 D_801C945E[];

#endif /* MAGIC_KONA_DECLS_H */
