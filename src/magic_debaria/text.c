#include "common.h"
#include "magic_debaria/decls.h"

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0054);

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0314);

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B036C);

s32 func_801B0A18(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801B22EC[a];
        } else {
            r = D_801B22EC[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801B22EC[a - 0x800];
        } else {
            r = -D_801B22EC[0x1000 - a];
        }
    }
    return r;
}

s32 func_801B0ABC(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801B22EC[0x400 - a];
        } else {
            r = -D_801B22EC[a - 0x400];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801B22EC[0xC00 - a];
        } else {
            r = D_801B22EC[a - 0xC00];
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0B58);

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0CD4);

void func_801B0D4C(void) {
    func_801B12F8();
}

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0D6C);

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B0F30);

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B112C);

INCLUDE_ASM("../asm/us/magic_debaria/nonmatchings/text", func_801B12F8);
