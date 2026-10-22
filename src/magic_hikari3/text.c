#include "common.h"
#include "magic_hikari3/decls.h"

void func_801B0000(void) {
    func_801B0814();
}

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B008C);

void func_801B0120(s16 arg0) {
    D_801B8A88 = 0;
    D_801B8A8A = (s16) (0xFF / arg0);
    func_800BBEAC(&func_801B008C);
}

void func_801B0190(s16 arg0) {
    D_801B8A88 = 0xFF;
    D_801B8A8A = (s16) -(0xFF / arg0);
}

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B01E8);

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B02A0);

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B035C);

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B078C);

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B0814);
