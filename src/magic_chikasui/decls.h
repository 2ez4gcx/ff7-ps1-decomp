/* Declarations the C of src/magic_chikasui/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CHIKASUI_DECLS_H
#define MAGIC_CHIKASUI_DECLS_H

#include "main/decls.h"
void func_801B0000(void);
void func_801B0714();
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; } MgObj18;
extern MgObj18 D_801C8CCC[];
MgObj18 *func_801B008C(void);
void func_801B0650(s32 arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
void func_800D3994(s32, s32, void *);
extern u8 D_8015190F[][0xB9C];
void func_801B05AC(void);
void func_801B0020(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern u8 D_801B0CC8[];
extern s32 D_801C8CC8;
extern s16 D_80162080;
extern MgObj20 D_80162978[];
extern u8 D_801B07D4[];
s32 func_800BBEAC(void (*)());
void func_801B0118(void);
s32 func_800D5774(s32);
extern volatile u8 D_80062D98;
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8();
void func_800D4368(void *, s32, s32);
s32 func_800D4D90(void *, s32, s32, s32);
extern s32 D_801517C0;
extern u8 D_801B0CB8[];
extern MgSVec D_801B0CC0;

#endif /* MAGIC_CHIKASUI_DECLS_H */
