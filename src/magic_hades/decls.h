/* Declarations the C of src/magic_hades/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_HADES_DECLS_H
#define MAGIC_HADES_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801BA978();
extern M2C_UNK D_801DDE34;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
void func_8003BA10(MgVec *, MgVec *, MgVec *);
s32 func_8003A59C(s32);
s32 func_8003CC1C(s32, s32);
void func_8003A08C(MgVec *, MgVec *);
s32 func_801B0068(MgVec *a, MgVec *b, MgVec *c);
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
void func_801B0144(s32 ang, MgMat *m, MgVec *v);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
void func_801B02C0(MgSVec *p, MgSVec *o, MgVec *n);
s16 func_801B039C(MgSVec *p, MgSVec *q, MgVec *n);
s32 func_801B19B4(s16 **pp);
extern s16 D_801F7B76[];
s32 func_801B19F0(s32 a, s32 b);
void func_801B2B1C(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
extern M2C_UNK func_801B1AE8;
M2C_UNK func_800BBEAC(M2C_UNK *);
extern MgObj20 D_80162978[];
void func_801B98BC(void);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern MgObj20 *D_801F1240;
void func_801B8D48();
void func_801B9960(void);
void func_801B9378();
void func_801B38DC(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s32 cur; s32 start; s32 num; s32 wrap; s32 pad10; MgSVec *pos[64]; } HdBlk;
typedef struct { MgSVec v[64]; } HdTrail;
typedef struct { u8 pad0[0x1C]; s32 w1C; s32 w20; u8 pad24[0x14]; MgSVec v38; u8 pad40[0x68]; s32 wA8; s32 wAC; s32 wB0; s32 wB4; } HdScratch;
extern HdBlk D_801F1250[];
extern HdTrail D_801F34D0[];
extern s32 D_801F76D0[];
extern s32 D_801F77D0[];
extern MgSVec D_801F74D0[];
extern MgMat D_800FA63C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_801B35F0(HdBlk *, MgSVec *);
void func_801B3434(void *, void *, s32, s32);
void func_801B3354(void *, s32);
void func_801B2D04(void *, s32, s32, s32);

#endif /* MAGIC_HADES_DECLS_H */
