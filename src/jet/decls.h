/* Declarations the C of src/jet/ uses (tools/auto_decomp.py adds to this). */
#ifndef JET_DECLS_H
#define JET_DECLS_H

#include "main/decls.h"
void func_800A82F0(void *arg0);
void func_800A7AF8(void);
extern s32 D_800A89D8;
extern s32 D_800A8A70;
extern s32 D_800A8A8C;
extern s32 D_800A8CCC;
extern s32 D_800D171C;
extern s32 D_800D1968;
extern s32 D_800D1BD8;
extern s32 D_800D1BFC;
extern s32 D_800D1C14;
void func_800A80A8(void *arg0, s16 arg1);
extern M2C_UNK D_800D16E4;
void func_800A7FAC(void *arg0);
void func_800A2BE0(void);
M2C_UNK func_800A2DE4(M2C_UNK, M2C_UNK);
extern s32 D_800A83C8;
extern s32 D_800A83CC;
extern s32 D_800A83D0;
extern s32 D_800A8CC0;
extern s8 D_800D1960;
extern s32 D_800D1BE8;
extern s32 D_800D1BEC;
extern s32 D_800E2604;
void func_800A27F0(s32 arg0);
s32 func_80046CFC(s32 arg0);
s32 func_80046D0C(Unk80046D0C *);
s32 func_80044000(void *arg0, void *arg1);
s16 func_800A4400(void);
extern s16 D_800D1970[];
extern s16 D_800D9940;
s16 func_800A8238(void);
extern s16 D_800D1A40[];
extern s16 D_800D9944;
void func_800A442C(s16 arg0);
void func_800A8264(s16 arg0);
typedef struct { u8 pad[0x20]; } JetUnk20;
extern JetUnk20 D_800D0554[];
JetUnk20 *func_800A7BF4(void);
typedef struct { u8 pad[0x24]; } JetUnk24;
JetUnk24 *func_800A7C20(s32 arg0);
typedef struct { u8 pad[0x28]; } JetUnk28;
JetUnk28 *func_800A7C54(s32 arg0);
void func_800A8204(void *arg0);
void func_800A2938(void);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
s32 func_8002DA7C();
s32 func_800A7688(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_800A892C;
extern s32 D_800A8930;
extern s32 D_800A8934;
extern s32 D_800A8A5C;
s32 func_800A76DC(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_800A893C;
extern s32 D_800A8940;
extern s32 D_800A8944;
extern s32 D_800A8A64;
void func_800A7E1C(void);
M2C_UNK func_80044244(s32, M2C_UNK);
extern s32 D_800D1964;
typedef struct JetNode { u8 pad0[0x24]; struct JetNode *parent; s16 unk28; s16 unk2A; s16 depth; s16 unk2E; struct JetNode *next; struct JetNode *prev; } JetNode;
extern JetNode D_800EE1D4[];
void func_800A8290(JetNode *arg0, JetNode *arg1);
void func_800A2B78(void);
extern s32 D_800A8338;
extern s32 D_800A833C;
void func_800A4390(void *arg0);
extern s16 D_800EE42C;

#endif /* JET_DECLS_H */
