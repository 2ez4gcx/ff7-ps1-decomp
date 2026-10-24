#include "common.h"
#include "magic_dethfo/decls.h"

void func_801B0054(void) {
    func_801B0A90();
}

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B0144);

s32 func_801B04CC(s32 a) {
    s32 r;

    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400) {
            r = D_801B8004[a];
        } else {
            r = D_801B8004[0x800 - a];
        }
    } else {
        if (a < 0xC00) {
            r = -D_801B8004[a - 0x800];
        } else {
            r = -D_801B8004[0x1000 - a];
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B0570);

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B073C);

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B09A0);

INCLUDE_ASM("../asm/us/magic_dethfo/nonmatchings/text", func_801B0A90);
