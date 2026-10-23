#include "common.h"
#include "patymenu/decls.h"

void func_801D0198(void) {
    u8 pad[8];

    func_80025B8C((s32)&D_801D41CC);
    func_80043DD8(0);
    func_80025C14((s32)&D_801D19CC);
    func_80043DD8(0);
    func_80025DF8();
    func_80043DD8(0);
}

void func_801D01F0(void) {
    func_80025C94(&D_800756F8);
    func_80043DD8(0);
    func_80025BD0(&D_801D41CC);
    func_80043DD8(0);
    func_80025C54(&D_801D19CC);
    func_80043DD8(0);
}

INCLUDE_ASM("../asm/us/patymenu/nonmatchings/text", func_801D0250);

INCLUDE_RODATA("../asm/us/patymenu/nonmatchings/text", D_801D0000);
