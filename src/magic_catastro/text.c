#include "common.h"
#include "magic_catastro/decls.h"

M2C_UNK *func_801B0058(void) {
    func_801B4AB0();
    return &D_801C6C08;
}

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B0080);

s32 func_801B0B40(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801D88F2[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B0B7C);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B0C68);

void func_801B1C9C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0C68)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B1D00);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B1D7C);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B1E94);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2020);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2278);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B24C8);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B27BC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2AC4);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2BA4);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2C64);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2D74);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B2ECC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B3184);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B36E4);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B3CF0);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B3E24);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B40C8);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B42A8);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B4538);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B45DC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B49CC);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B4A34);

INCLUDE_ASM("../asm/us/magic_catastro/nonmatchings/text", func_801B4AB0);
