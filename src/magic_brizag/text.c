#include "common.h"
#include "magic_brizag/decls.h"

void func_801B0054(void) {
    func_801B324C();
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0368);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B03C0);

s32 func_801B0A8C(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C0DB0[a];
        } else {
            r = D_801C0DB0[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C0DB0[a - 0x800];
        } else {
            r = -D_801C0DB0[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0B30(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801C0DB0[0x400 - a];
        } else {
            r = -D_801C0DB0[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801C0DB0[0xC00 - a];
        } else {
            r = D_801C0DB0[a - 0xC00];
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0BCC);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0DD0);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B0E48);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B1114);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B116C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B15A8);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B16B0);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B19FC);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B1D3C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B1F08);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B210C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B254C);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B2DF0);

INCLUDE_ASM("../asm/us/magic_brizag/nonmatchings/text", func_801B303C);

INCLUDE_RODATA("../asm/us/magic_brizag/nonmatchings/text", D_801B0000);

void func_801B324C(arg0) {
    D_801D9600 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B32C8, 0, 0, 0);
    func_800BBEAC(&func_801B303C);
    D_801D9604 = arg0;
}
