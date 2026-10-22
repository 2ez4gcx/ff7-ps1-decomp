#include "common.h"
#include "cnfgmenu/decls.h"

void func_801D0040(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/cnfgmenu/nonmatchings/text", func_801D0080);

INCLUDE_ASM("../asm/us/cnfgmenu/nonmatchings/text", func_801D0118);

INCLUDE_ASM("../asm/us/cnfgmenu/nonmatchings/text", func_801D014C);

INCLUDE_ASM("../asm/us/cnfgmenu/nonmatchings/text", func_801D01C8);

INCLUDE_ASM("../asm/us/cnfgmenu/nonmatchings/text", func_801D069C);

INCLUDE_ASM("../asm/us/cnfgmenu/nonmatchings/text", func_801D080C);

void func_801D1AA0(void) {
}
