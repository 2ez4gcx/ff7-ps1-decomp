#include "common.h"
#include "shopmenu/decls.h"

void func_801D0084(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D00C4);

u32 func_801D01B8(u32 arg0) {
    return arg0 >> 0x1F;
}

s32 func_801D01C0(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D01D8);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D0340);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D0C88);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D0E00);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D0F90);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D0FE0);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D104C);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D10B0);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1104);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D11A4);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D16D4);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D17B0);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1868);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1A2C);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1AE0);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1C4C);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1C84);

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D1CC4);

void func_801D40A8(void) {
    func_80025C94(&D_801DEBBC);
    func_80025BD0(&D_801DBEBC);
    func_80025C54(&D_801D96BC);
    func_8003CEDC(0);
    func_800444AC(&D_801D95C0);
    func_800443B0(&D_801D9564);
}

INCLUDE_ASM("../asm/us/shopmenu/nonmatchings/text", func_801D4118);
