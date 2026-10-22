#include "common.h"
#include "magic_death/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B31B4();
    return &D_801B9658;
}

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B007C);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0158);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B02D4);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B03B0);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0494);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B05A4);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B07A8);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0858);

void func_801B0978(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0 + 4;
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32 *, 8) = func_8003BBDC(arg1, arg0 + 0x30, temp_s2, temp_s1);
    func_8003BBDC(arg2, arg0 + 0x34, temp_s2, temp_s1);
}

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B09EC);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0B1C);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0C20);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0EFC);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B1AF4);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B1D20);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B1F14);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2228);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2478);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B278C);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2E14);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B31B4);
