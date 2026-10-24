#include "common.h"
#include "batini/decls.h"

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B0050);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B0490);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B0668);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B085C);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B08C0);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B0F08);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1120);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B11BC);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B137C);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B13DC);

s32 func_801B14E8(u32 arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = arg0 & 0xFF;
    var_a1 = 0;
    if ((temp_v1 != 0xFF) && ((D_800730DD[temp_v1].a & 0xF) == 7)) {
        var_a1 = (arg0 >> 8) | 0x80000000;
    }
    return var_a1;
}

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1530);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1598);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1734);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B18F8);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B19AC);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1CB0);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B1E0C);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B2308);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B23E0);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B2738);

INCLUDE_ASM("../asm/us/batini/nonmatchings/text", func_801B2770);
