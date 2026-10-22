#include "common.h"
#include "magic_raise/decls.h"

M2C_UNK *func_801B0054(void) {
    D_801DBD1C = 0;
    func_801B0C3C();
    return &D_801B8874;
}

M2C_UNK *func_801B0084(void) {
    D_801DBD1C = 0;
    func_801B1FF8();
    return &D_801B8874;
}

M2C_UNK *func_801B00B4(void) {
    D_801DBD1C = 1;
    func_801B1FF8();
    return &D_801B8874;
}

M2C_UNK *func_801B00E8(void) {
    D_801DBD1C = 1;
    func_801B0C3C();
    return &D_801B8874;
}

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B011C);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B0270);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B037C);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B04F0);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B07A4);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B09FC);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B0C3C);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B0CCC);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B0DF4);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B0F08);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B10D0);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B14BC);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B18D8);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B1D04);

INCLUDE_ASM("../asm/us/magic_raise/nonmatchings/text", func_801B1FF8);

INCLUDE_RODATA("../asm/us/magic_raise/nonmatchings/text", D_801B0000);
