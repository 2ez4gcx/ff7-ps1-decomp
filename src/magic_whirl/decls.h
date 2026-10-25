/* Declarations the C of src/magic_whirl/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_WHIRL_DECLS_H
#define MAGIC_WHIRL_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B10E0();
typedef struct { s16 unk0; s16 unk2; s16 unk4[3]; s16 unkA; u8 pad[0x40]; } MgObj4C;
extern MgObj4C D_801C2F20[];
MgObj4C *func_801B0020(void);
MgObj4C *func_801B07CC(void);
extern MgObj4C D_801C4CD0[];
extern M2C_UNK D_801B1150;
void func_801B105C(void);
void func_801B0F4C(s32 arg0, s32 arg1);
void func_801B0844(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
void func_801B0098();
extern u8 D_801C6A80[];
extern u8 *D_801E6A80;
extern s16 D_80162080;
void func_800D52A0(s32, s32);
void func_801B0910(void);
void func_801B0398();
extern u8 D_80062D98;
extern s32 D_801C2ED8;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
extern MgSVec D_801C2F14;
extern u8 D_8015190F[][0xB9C];
void func_800D3994(s32, s32, void *);
void func_801B0C78(void);
extern s16 D_801C2F16;
extern s32 D_801C2F1C;
s32 func_800BBEAC(void (*)());
s32 func_800D56A8(void *);
void func_800D55F4(s32, s32, s32);

#endif /* MAGIC_WHIRL_DECLS_H */
