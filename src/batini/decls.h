/* Declarations the C of src/batini/ uses (tools/auto_decomp.py adds to this). */
#ifndef BATINI_DECLS_H
#define BATINI_DECLS_H

#include "main/decls.h"
s32 func_801B14E8(u32 arg0);
s32 func_801B2738(s32 arg0);
extern u8 D_80083184[];
void func_801B137C(s32 arg0);
s32 func_801B1530(u32 *arg0);
void func_801B23E0(s32 arg0, void (*arg1)(void));
void func_801B1CB0(void);
typedef struct { u16 id; u8 qty; u8 a; u8 f; u8 pad; } BiInv;
extern u8 D_800722D8[][0x1C];
extern u8 D_800738A0[][0x2C];
extern BiInv D_801671B8[];
extern u8 D_80166F74;
void func_801B11BC(s32 arg0);
extern u8 D_800707C5[][8];
extern u8 D_800F5BE1[][0x44];
extern u8 D_800F5EFC[][0x18];
s32 func_801B2770(s32 arg0);
void func_801B085C(s32 arg0);
extern s16 D_800F7DA6;
void func_801B1120(void);
typedef struct { s8 a; u8 pad[15]; } BiT16b;
typedef struct { u32 a; u8 pad4[5]; u8 b9; u8 padA[3]; u8 bD; s8 bE; u8 padF[5]; u8 b14; u8 b15; u8 pad16[0xA]; u16 h20; u16 h22; u8 pad24[4]; u16 h28; u16 h2A; s32 w2C; s32 w30; u8 pad34[0x34]; } BiAct;
void func_800A6000(s32, s32, s32);
extern BiT16b D_801636B8[];
extern volatile BiAct D_800F83E0[];
typedef struct { u8 pad0[6]; u8 b6; u8 b7; u16 h8; u16 hA; u16 hC; u16 hE; u8 pad10[2]; s16 s12; u8 pad14[2]; u16 h16; u8 pad18[0xB]; u8 b23; } BiSrc;
typedef struct { u8 pad0[0x10]; u16 h10; s16 s12; s16 s14; s16 s16; } BiDst;
void func_801B18F8(BiSrc *arg0, BiDst *arg1, BiAct *arg2);
void func_801B2308(void);
typedef struct { s16 a; u8 pad[0xE]; } BiT16;
extern BiT16 D_80163658[];
extern volatile u32 D_80163624[][4];
extern volatile u8 D_801636B9[][0x10];
extern volatile u32 D_800F83E4[][0x1A];
extern volatile u8 D_800F83F0[][0x68];
extern volatile u32 D_800F8424[][0x1A];
void func_801B1598(s32 arg0, s32 arg1);
typedef struct { u8 pad0[0xD]; u8 bD; u8 padE[4]; u8 b12; u8 pad13[0x16]; u8 b29; u8 pad2A[0xA]; u32 w34; u8 pad38[4]; s16 h3C; u16 h3E; u8 pad40[4]; } BiP;
typedef struct { u8 pad0[0x20]; u32 w20; u8 pad24[0x10]; } BiQ;
extern BiP D_800F5BB8[];
extern u8 D_80071C29[][0x10];
void func_801B0490(s32 arg0);
typedef struct { u8 pad0[8]; s8 b8; u8 pad9[0x5F]; } BiE;
void func_800A4540(void);
void func_800A7254(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800AE954(s32 arg0);
s32 func_800B108C();
void func_800A3354(void);
void func_801B0F08();
void func_801B19AC(void);
void func_801B1E0C(void);
extern u16 D_8016376C;
extern s8 D_800F6936[];
extern u8 D_800F5E66[];
extern struct { u16 mask; u8 pad[0x30]; BiE e[10]; } D_800F83AE;
extern u16 D_800F83CC;
extern u8 D_800F83A8;
extern u8 D_80163626;
extern u16 D_800F5BBC[][0x22];

#endif /* BATINI_DECLS_H */
