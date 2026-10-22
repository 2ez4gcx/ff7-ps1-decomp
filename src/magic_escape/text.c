#include "common.h"
#include "magic_escape/decls.h"

void func_801B0000(void) {
    func_801B0E60();
}

INCLUDE_ASM("../asm/us/magic_escape/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_escape/nonmatchings/text", func_801B009C);

INCLUDE_ASM("../asm/us/magic_escape/nonmatchings/text", func_801B063C);

INCLUDE_ASM("../asm/us/magic_escape/nonmatchings/text", func_801B0E00);

void func_801B0E60(void) {
    func_801B009C();
    func_801B0020();
    func_800BBEAC(&func_801B063C);
    func_800BBEAC(&func_801B0E00);
    func_800D55F4(0x20, 0x40, 0x5D);
}
