/* Declarations the C of src/magic_chi/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAGIC_CHI_DECLS_H
#define MAGIC_CHI_DECLS_H

#include "main/decls.h"
M2C_UNK *func_801B0000(void);
void func_801B061C();
extern M2C_UNK D_801B47E0;
void func_801B0028(void);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; u8 pad[0x18]; } MgObj20;
extern s16 D_8015169C;
extern MgObj20 D_80162978[];
extern u8 D_801B8080[];
extern u8 *D_801C8080;
extern s16 D_80162080;
void func_801B0088(void);
typedef struct { s16 vx; s16 vy; s16 vz; s16 pad; } MgSVec;
typedef struct { s16 unk0; s16 unk2; MgSVec unk4; MgSVec unkC; u8 pad14[8]; s16 unk1C; s16 unk1E; } MgObjAwa;
void func_800D4368(MgSVec *, s32, s32);
extern u16 D_801B8034;
extern s32 D_801517C0;
extern s32 D_80163C74;
s32 func_800D4D90(void *, s32, s32, s32);
extern u8 D_80062D98;
extern s32 D_801B471C;
void func_800D2980(void *, s32, s32, s32);
void func_800D52A0(s32, s32);
void func_800D54EC(s32, void *);
void func_801B0140(void);
extern u8 D_800F5B70;
extern u8 D_800F5B71;
extern u8 D_800F5B72;
extern MgObj20 D_80162996[];
extern u8 D_801B06D8[];
extern s16 D_801C8084;
extern u8 D_801C8088[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; } MgTask;
s32 func_80039A74(s32);
s32 func_80039B40(s32);
s32 func_80042DA8(void);
s32 func_800BBEAC(void *);
void func_800D3994(s32, u8, void *);
u16 *func_800D4FA8(s32);
s32 func_800D56A8(void *);
void func_800D61AC(void *, s32, s32, s32, s32);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern s32 D_8009A00C;
extern u8 D_8015190F[][0xB9C];
extern u8 D_801517F0[];
extern u8 D_801518F6[][0xB9C];
extern u8 D_80151915[][0xB9C];
extern u8 D_80151A4C[][0xB9C];
extern MgTask D_8016297C[];
extern s16 D_801B8038[];
extern s16 D_801B8050[];
extern s16 D_801B8064;
extern s16 D_801B8066;
extern s16 D_801B8068[];
extern s16 D_801B806A;
extern s16 D_801B8070[];
extern s16 D_801B8074;
extern s16 D_801B8078;
extern s16 D_801B807C;

#endif /* MAGIC_CHI_DECLS_H */
