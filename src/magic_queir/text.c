#include "common.h"
#include "magic_queir/decls.h"

void func_801B0074(void) {
    func_801B2DCC();
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B0094);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B033C);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B05EC);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B0668);

s32 func_801B0D8C(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C3C6C[a];
        } else {
            r = D_801C3C6C[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C3C6C[a - 0x800];
        } else {
            r = -D_801C3C6C[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0E30(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C3C6C[0x400 - a];
        } else {
            r = -D_801C3C6C[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C3C6C[0xC00 - a];
        } else {
            r = D_801C3C6C[a - 0xC00];
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B0ECC);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B104C);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B17F4);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B1894);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B19EC);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B1F00);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2144);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B237C);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2590);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2A04);

INCLUDE_ASM("../asm/us/magic_queir/nonmatchings/text", func_801B2C08);

INCLUDE_RODATA("../asm/us/magic_queir/nonmatchings/text", D_801B0020);

void func_801B2DCC(arg0) {
    D_801DC4A4 = &D_80162978[func_800BBEAC(&D_801B0020)];
    func_800D2980(&D_801B2E48, 0, 0, 0);
    func_800BBEAC(&func_801B2C08);
    D_801DC4A8 = arg0;
}
