#include "common.h"
#include "magic_daisenp/decls.h"

void func_801B0054(void) {
    D_801CF2F4 = 0;
    func_801B0E38();
}

void func_801B007C(void) {
    D_801CF2F4 = 1;
    func_801B0E38();
}

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B00A8);

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B0250);

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B04AC);

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B0B18);

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B0E38);
