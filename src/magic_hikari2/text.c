#include "common.h"
#include "magic_hikari2/decls.h"

void func_801B0000(void) {
    func_801B0854();
}

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B008C);

void func_801B0120(s16 arg0) {
    D_801B8AC8 = 0;
    D_801B8ACA = (s16) (0xFF / arg0);
    func_800BBEAC(&func_801B008C);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0xF);
}

void func_801B01B4(s16 arg0) {
    D_801B8AC8 = 0xFF;
    D_801B8ACA = (s16) -(0xFF / arg0);
    func_800D52A0(0, 0xF);
}

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B0228);

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B02E0);

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B039C);

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B07CC);

INCLUDE_ASM("../asm/us/magic_hikari2/nonmatchings/text", func_801B0854);
