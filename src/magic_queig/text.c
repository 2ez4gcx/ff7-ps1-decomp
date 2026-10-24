#include "common.h"
#include "magic_queig/decls.h"

void func_801B0054(void) {
    func_801B33B4();
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B034C);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B0638);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B06B8);

s32 func_801B0DBC(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801CCC60[a];
        } else {
            r = D_801CCC60[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801CCC60[a - 0x800];
        } else {
            r = -D_801CCC60[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0E60(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801CCC60[0x400 - a];
        } else {
            r = -D_801CCC60[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801CCC60[0xC00 - a];
        } else {
            r = D_801CCC60[a - 0xC00];
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B0EFC);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1100);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1898);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1938);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1AE0);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1C38);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1C84);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B1CDC);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2274);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2818);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B29E0);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2BBC);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B2F34);

INCLUDE_ASM("../asm/us/magic_queig/nonmatchings/text", func_801B318C);

INCLUDE_RODATA("../asm/us/magic_queig/nonmatchings/text", D_801B0000);

void func_801B33B4(arg0) {
    D_801E5550 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B3430, 0, 0, 0);
    func_800BBEAC(&func_801B318C);
    D_801E5554 = arg0;
}
