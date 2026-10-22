#include "common.h"
#include "magic_sumi/decls.h"

INCLUDE_ASM("../asm/us/magic_sumi/nonmatchings/text", func_801B006C);

INCLUDE_ASM("../asm/us/magic_sumi/nonmatchings/text", func_801B0174);

INCLUDE_ASM("../asm/us/magic_sumi/nonmatchings/text", func_801B03E8);

INCLUDE_ASM("../asm/us/magic_sumi/nonmatchings/text", func_801B0514);

INCLUDE_ASM("../asm/us/magic_sumi/nonmatchings/text", func_801B0964);

void func_801B0B38(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0C3C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0964);
    func_800BBA84(0x8A, arg1, 0x40);
}

void func_801B0BB4(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0C3C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0964);
    func_800BBA84(0x8A, arg1, 0x40);
    D_801B501C = 1;
}

INCLUDE_RODATA("../asm/us/magic_sumi/nonmatchings/text", D_801B0000);
