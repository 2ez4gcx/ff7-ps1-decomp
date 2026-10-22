#include "common.h"
#include "magic_sennkoku/decls.h"

M2C_UNK *func_801B0054(void) {
    D_801CD5B0 = 0;
    func_801B089C();
    return &D_801B0A70;
}

M2C_UNK *func_801B0084(void) {
    D_801CD5B0 = 1;
    func_801B089C();
    return &D_801B0A70;
}

INCLUDE_ASM("../asm/us/magic_sennkoku/nonmatchings/text", func_801B00B8);

INCLUDE_ASM("../asm/us/magic_sennkoku/nonmatchings/text", func_801B01C8);

INCLUDE_ASM("../asm/us/magic_sennkoku/nonmatchings/text", func_801B0650);

INCLUDE_ASM("../asm/us/magic_sennkoku/nonmatchings/text", func_801B089C);

INCLUDE_RODATA("../asm/us/magic_sennkoku/nonmatchings/text", D_801B0000);
