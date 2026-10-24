/* Declarations the C of src/magic_vahamut/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_VAHAMUT_DECLS_H
#define MAGIC_VAHAMUT_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B3AB8();
extern M2C_UNK D_801DB958;
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801EFC68;
extern MgMat D_801EEEA0;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist);
s32 func_801B0184(s16 **pp);
extern s16 D_801EFC8A[];
s32 func_801B01C0(s32 t, s32 s);
s32 func_80039A74(s32);
void func_801B12E4(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
void func_801B02B0(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B1484(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B1348(void);
extern MgTask D_80162978[];
typedef struct { s16 mode; s16 frames; s32 unk4; s32 unk8; s16 actor; s16 part; MgSVec pos; MgSVec unk18; MgSVec vel; s16 unk28; s16 pad2A; } MgCam;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s16 *script; MgMat *mat; s16 actor; u8 pad16[0xA]; } MgCamTask;
typedef struct { s16 vx; s16 vy; s16 vz; u8 pad[0xB96]; } MgActorPos;
extern s16 D_8015169C;
extern u8 D_80062D98;
extern MgCam D_801EF2FC;
extern MgCam *D_801EF354;
extern MgCam D_801EF328;
extern MgCam *D_801EF358;
s32 func_80039F5C(s32);
extern s16 D_80162084;
void func_8003A078(MgVec *, MgSVec *);
extern MgSVec D_80158D00;
void func_8003ACE4(MgSVec *, MgVec *);
void func_800D3994(s32, s32, MgSVec *);
extern MgActorPos D_80151A4C[];
extern MgSVec D_801031E8;
extern s16 D_800FA666[];

#endif /* MAGIC_VAHAMUT_DECLS_H */
