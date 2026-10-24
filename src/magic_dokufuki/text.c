#include "common.h"
#include "magic_dokufuki/decls.h"

INCLUDE_ASM("../asm/us/magic_dokufuki/nonmatchings/text", func_801B006C);

INCLUDE_ASM("../asm/us/magic_dokufuki/nonmatchings/text", func_801B01E8);

INCLUDE_ASM("../asm/us/magic_dokufuki/nonmatchings/text", func_801B031C);

INCLUDE_ASM("../asm/us/magic_dokufuki/nonmatchings/text", func_801B0454);

INCLUDE_ASM("../asm/us/magic_dokufuki/nonmatchings/text", func_801B07F8);

void func_801B08C4(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0A20, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B07F8);
    func_800BBA84(0x6B, arg1, 0);
    D_8009A000 = 0x28;
    D_8009A004 = 0x40;
    D_8009A008 = 0xB2;
    func_8002DA7C();
}

void func_801B096C(s32 arg0, M2C_UNK arg1) {
    D_801C8E78 = 8;
    func_800BBEAC(&D_801B0000);
    func_800D2980(&D_801B0A20, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B07F8);
    func_800BBA84(0x6B, arg1, 0);
    D_8009A000 = 0x28;
    D_8009A004 = 0x40;
    D_8009A008 = 0xB2;
    func_8002DA7C();
}

INCLUDE_RODATA("../asm/us/magic_dokufuki/nonmatchings/text", D_801B0000);
