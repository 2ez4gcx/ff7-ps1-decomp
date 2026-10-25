/* Declarations the C of src/magic_vahamut2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_VAHAMUT2_DECLS_H
#define MAGIC_VAHAMUT2_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B7C4C();
extern M2C_UNK D_801D8EAC;
s32 func_801B6828(s32 arg0);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801F1AC0;
extern MgMat D_801EEE00;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B0068(MgSVec *v, s16 scale, s32 dist);
s32 func_801B16A8(s16 **pp);
extern s16 D_801F1AFE[];
s32 func_801B16E4(s32 t, s32 s);
s32 func_80039A74(s32);
void func_801B2808(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
void func_801B17D4(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
void func_801B29A8(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_801B286C(void);
extern MgTask D_80162978[];
void func_801B2A1C(void);
extern u16 D_801EEDD8;
extern s16 D_801EEDD2;
extern u16 D_801EF144;
extern u16 D_801EF134;
extern s32 D_801EEDF4;
extern s32 D_801EF150;
extern M2C_UNK D_801EF114;
void func_8003A63C(void *, void *, MgMat *);
extern M2C_UNK D_801EF154;
void func_801B0C44(MgMat *, void *);
void func_801B6EAC(s16 arg0);
extern M2C_UNK func_801B6C18;
typedef struct { s16 mode; s16 frames; s32 unk4; s32 unk8; s16 actor; s16 part; MgSVec pos; MgSVec unk18; MgSVec vel; s16 unk28; s16 pad2A; } MgCam;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s16 *script; MgMat *mat; s16 actor; u8 pad16[0xA]; } MgCamTask;
typedef struct { s16 vx; s16 vy; s16 vz; u8 pad[0xB96]; } MgActorPos;
extern s16 D_8015169C;
extern u8 D_80062D98;
extern MgCam D_801EF508;
extern MgCam *D_801EF560;
extern MgCam D_801EF534;
extern MgCam *D_801EF564;
s32 func_80039F5C(s32);
extern s16 D_80162084;
void func_8003A078(MgVec *, MgSVec *);
extern MgSVec D_80158D00;
void func_8003ACE4(MgSVec *, MgVec *);
void func_800D3994(s32, s32, MgSVec *);
extern MgActorPos D_80151A4C[];
extern MgSVec D_801031E8;
extern s16 D_800FA668[];
typedef struct { u32 tag; u8 pad4[4]; s32 xy0; u8 pad0c[4]; s32 xy1; u8 pad14[4]; s32 xy2; } MgPolyT;
extern MgSVec D_801EF3E4[];
extern MgPolyT *D_80163C74;
s32 func_8003BC0C(MgSVec *, MgSVec *, MgSVec *, s32 *, s32 *, s32 *, s32 *, s32 *);
MgPolyT *func_801B577C(void);

#endif /* MAGIC_VAHAMUT2_DECLS_H */
