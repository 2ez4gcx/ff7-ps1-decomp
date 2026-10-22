#include "common.h"
#include "statmenu/decls.h"

void func_801D0000(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D0040);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D0114);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D01B4);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D037C);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D053C);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D0964);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D0B74);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D0D28);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D116C);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D14E0);

INCLUDE_ASM("../asm/us/statmenu/nonmatchings/text", func_801D167C);

void func_801D1960(void) {
}
