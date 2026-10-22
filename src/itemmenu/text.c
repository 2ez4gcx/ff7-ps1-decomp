#include "common.h"
#include "itemmenu/decls.h"

void func_801D01E8(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0228);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D031C);

void func_801D03B4(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D03C8);

void func_801D0618(u16 *arg0, u16 *arg1) {
    u16 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

s32 func_801D062C(s32 arg0) {
    s32 var_v0;

    if (arg0 != 0) {
        var_v0 = 1;
        if (arg0 < 0) {
            return -1;
        }
        
        return var_v0;
    }
    var_v0 = 0;
    return var_v0;
}

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0650);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D069C);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0704);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D076C);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D081C);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D08E4);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D09AC);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0A74);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0AAC);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0BA0);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0CAC);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0CE8);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0D24);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0DCC);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0E4C);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D0E80);

void func_801D296C(void) {
}

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2974);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D29C4);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2A18);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2ABC);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2C00);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2CDC);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2D74);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2E84);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D2F00);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D3018);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D3138);

INCLUDE_ASM("../asm/us/itemmenu/nonmatchings/text", func_801D3228);
