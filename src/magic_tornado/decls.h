/* Declarations the C of src/magic_tornado/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_TORNADO_DECLS_H
#define MAGIC_TORNADO_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B10F4();
typedef struct { s16 unk0; s16 unk2; s16 unk4[3]; s16 unkA; u8 pad[0x40]; } MgObj4C;
extern MgObj4C D_801C2F34[];
MgObj4C *func_801B0020(void);
MgObj4C *func_801B07E0(void);
extern MgObj4C D_801C4CE4[];
extern M2C_UNK D_801B1164;
void func_801B0F60(s32 arg0, s32 arg1);
void func_801B1070(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
void func_800D52A0(s32, s32);
extern s16 D_8015169C;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
extern u8 D_801C6A94[];
extern u8 *D_801E6A94;
void func_801B0858(void);
void func_801B0098();
void func_801B0924(void);
void func_801B03AC();
extern u8 D_80062D98;
extern s32 D_801C2EEC;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern u8 D_8015190F[][0xB9C];
extern MgSVec D_801C2F28;
extern s16 D_801C2F2A;
extern s32 D_801C2F30;
s32 func_800BBEAC(void (*)());
void func_800D3994(s32, s32, void *);
void func_800D55F4(s32, s32, s32);
s32 func_800D56A8(void *);
void func_801B0C8C(void);

#endif /* MAGIC_TORNADO_DECLS_H */
