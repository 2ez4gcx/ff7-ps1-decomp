/* Declarations the C of src/magic_odin2/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_ODIN2_DECLS_H
#define MAGIC_ODIN2_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0040(void);
M2C_UNK func_801B5264();
extern M2C_UNK D_801DCCD0;
s32 func_801B0068(s16 **pp);
extern s16 D_801F726E[];
void func_801B10E8(s32 arg0, s32 arg1, s16 arg2);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s32 unkC; s32 unk10; s16 unk14; u8 pad16[0xA]; } MgObjC;
void func_801B00A4(void);
M2C_UNK func_800BBEAC(M2C_UNK *);
typedef struct { s32 vx; s32 vy; s32 vz; s32 pad; } MgVec;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 m[3][3]; s32 t[3]; } MgMat;
extern MgMat D_801F6238;
extern MgMat D_801F1C3C;
void func_8003B48C(MgMat *);
void func_8003B51C(MgMat *);
void func_8003BC6C(MgSVec *, MgVec *, s32 *);
void func_8003A08C(MgVec *, MgVec *);
MgMat *func_801B2200(MgSVec *v, s16 scale, s32 dist);
void func_801B25F8(void);
s32 func_800D4D90(M2C_UNK *, s32, M2C_UNK, s32);
extern u8 D_80062D98;
extern s16 D_8015169C;
extern s32 D_801517C0;
extern s32 D_80163C74;
extern M2C_UNK D_801F1C6C;
void func_801B26D0(void);
M2C_UNK func_8003A63C(MgMat *, M2C_UNK *, MgMat *);
s32 func_800D29D4(M2C_UNK *, s32, M2C_UNK, s32);
extern M2C_UNK D_801F1C78;
extern M2C_UNK D_801F1C88;
extern MgMat *D_801F1CA8;
MgMat *func_801B231C(MgSVec *v, s32 d, MgMat *m);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
typedef struct { s16 mode; s16 frames; s32 unk4; s32 unk8; s16 actor; s16 part; MgSVec pos; MgSVec unk18; MgSVec vel; s16 unk28; s16 pad2A; } MgCam;
typedef struct { s16 unk0; s16 unk2; u8 pad4[8]; s16 *script; MgMat *mat; s16 actor; u8 pad16[0xA]; } MgCamTask;
typedef struct { s16 vx; s16 vy; s16 vz; u8 pad[0xB96]; } MgActorPos;
extern MgCam D_801F1DC0;
extern MgCam *D_801F1E18;
extern MgCam D_801F1DEC;
extern MgCam *D_801F1E1C;
s32 func_80039F5C(s32);
void func_8003A078(MgVec *, MgSVec *);
s32 func_80039A74(s32);
extern MgSVec D_80158D00;
void func_8003ACE4(MgSVec *, MgVec *);
void func_800D3994(s32, s32, void *);
extern MgActorPos D_80151A4C[];
extern MgSVec D_801031E8;
extern MgTask D_80162978[];

#endif /* MAGIC_ODIN2_DECLS_H */
