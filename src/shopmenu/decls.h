/* Declarations the C of src/shopmenu/ uses (tools/auto_decomp.py adds to this). */
#ifndef SHOPMENU_DECLS_H
#define SHOPMENU_DECLS_H

#include "main/decls.h"
void func_801D0084(s32 arg0);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
u32 func_801D01B8(u32 arg0);
s32 func_801D01C0(s32 arg0);
void func_801D40A8(void);
extern s32 D_801D9564;
extern s32 D_801D95C0;
extern M2C_UNK D_801D96BC;
extern M2C_UNK D_801DBEBC;
extern M2C_UNK D_801DEBBC;
s32 func_801D1C84(void);
s32 func_801D10B0(s32 m);
typedef struct { s32 item[0x180]; s32 materia[0x100]; } ShopPrice;
extern ShopPrice *D_801D70E0;
s32 func_801D1C4C(void);
s32 func_801D1868();
s32 func_801D16D4(void);
s32 func_801D0F90(s32 id);
void func_801D0FE0(s32 shop);
extern u8 D_80062DFD;
extern s32 D_801D70E4;
extern s32 D_801D70E8;
extern s32 D_801D70EC;
extern s32 D_801D70F0;
s32 func_801D104C(u32 m);
s32 func_801D17B0(s32 id);
void func_801D1104(void);
extern u8 D_801D42C8[][0x14];
extern Rect8 D_801D70D4;
void func_801D00C4(s16 arg0, s16 arg1, s32 arg2);
typedef struct { s16 type; s16 pad; s32 id; } ShopEntry;
typedef struct { u8 a; u8 b; u8 pad[2]; ShopEntry e[10]; } ShopInfo;
extern s8 D_801D9605;
extern s16 D_801D95FC;
extern ShopInfo D_801D4714[];
void func_801D1AE0(void);
extern ShopPrice D_801D6854;
extern s32 D_801D7058;
extern u8 D_801D95E8[];
s32 func_801D0C88(s32 arg0);
typedef struct { u8 pad0[3]; u8 len; u8 r; u8 g; u8 b; u8 code; s16 x; s16 y; s16 w; s16 h; } ShopPrim;
extern volatile ShopPrim *volatile D_80062F24;
extern s32 D_80062FC4;
extern s32 D_801D6588;
void func_801D0E00(s32 x, s32 y, u8 *slots);
void func_801D4118(s32 shop);
extern u8 D_80077F64[];
extern s32 D_801D70F4;
extern s32 D_801D70F8;
extern u8 *D_801D70FC;
extern u8 D_801D7100[];
extern u8 D_801D9508[];
extern u8 D_801D95D4[];
void func_801D1CC4(s32);
void func_801D01D8(void);
extern u8 D_801D63D0[][0x14];
typedef struct { u8 filled; u8 count; u8 pad[8]; s16 v[8]; } ShopStatDiff;
extern ShopStatDiff *D_801D70DC;
s32 func_801D1A2C(s32 item);

#endif /* SHOPMENU_DECLS_H */
