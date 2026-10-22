#include "common.h"
#include "magic_kafun/decls.h"

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0148);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0308);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0388);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B06E4);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B08B4);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0A64);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0E14);

void func_801B0F18(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
}

void func_801B0F94(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
    D_801D16A8 = 9;
}

INCLUDE_RODATA("../asm/us/magic_kafun/nonmatchings/text", D_801B0020);
