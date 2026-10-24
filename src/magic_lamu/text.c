#include "common.h"
#include "magic_lamu/decls.h"

M2C_UNK *func_801B0038(void) {
    func_801B38E8();
    return &D_801D6B50;
}

s32 func_801B0060(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E82CA[-v];
    }
    return v;
}

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B009C);

void func_801B102C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B009C)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1090);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B13A0);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B16B0);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1774);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1800);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B18D4);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1A10);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1C24);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1E2C);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1EEC);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B1FF0);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2050);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B24A8);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2640);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B275C);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2870);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2B38);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2C3C);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2D80);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2E90);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B2FF0);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B30D0);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B3180);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B3214);

INCLUDE_ASM("../asm/us/magic_lamu/nonmatchings/text", func_801B38E8);
