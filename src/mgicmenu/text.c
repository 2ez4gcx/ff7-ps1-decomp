#include "common.h"
#include "mgicmenu/decls.h"

void func_801D0124(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/mgicmenu/nonmatchings/text", func_801D0164);

INCLUDE_ASM("../asm/us/mgicmenu/nonmatchings/text", func_801D0378);

INCLUDE_ASM("../asm/us/mgicmenu/nonmatchings/text", func_801D03B4);

INCLUDE_ASM("../asm/us/mgicmenu/nonmatchings/text", func_801D03F0);

INCLUDE_ASM("../asm/us/mgicmenu/nonmatchings/text", func_801D0490);

void func_801D2928(void) {
}
