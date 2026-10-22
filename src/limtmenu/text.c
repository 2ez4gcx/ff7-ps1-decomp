#include "common.h"
#include "limtmenu/decls.h"

void func_801D002C(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/limtmenu/nonmatchings/text", func_801D006C);

INCLUDE_ASM("../asm/us/limtmenu/nonmatchings/text", func_801D013C);

INCLUDE_ASM("../asm/us/limtmenu/nonmatchings/text", func_801D042C);

void func_801D11A0(void) {
}

INCLUDE_ASM("../asm/us/limtmenu/nonmatchings/text", func_801D11A8);
