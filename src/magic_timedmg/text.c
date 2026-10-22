#include "common.h"
#include "magic_timedmg/decls.h"

void func_801B0000(void) {
    func_801B171C();
}

void func_801B0020(s32 arg0, void *arg1) {
    M2C_UNK sp10;
    M2C_UNK sp14;
    s16 temp_a0;
    s16 temp_a0_2;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_8003BBDC(arg0, arg1, &sp10, &sp14);
    temp_a0 = M2C_FIELD(arg1, s16 *, 0);
    if (temp_a0 < D_801B3164) {
        M2C_FIELD(arg1, s16 *, 0) = (s16) (u16) D_801B3164;
    } else if ((0x13F - D_801B3164) < temp_a0) {
        M2C_FIELD(arg1, s16 *, 0) = (s16) (0x13F - (u16) D_801B3164);
    }
    temp_a0_2 = M2C_FIELD(arg1, s16 *, 2);
    if (temp_a0_2 < D_801B3164) {
        M2C_FIELD(arg1, s16 *, 2) = (s16) (u16) D_801B3164;
        return;
    }
    if ((0xA6 - D_801B3164) < temp_a0_2) {
        M2C_FIELD(arg1, s16 *, 2) = (s16) (0xA6 - (u16) D_801B3164);
    }
}

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B0124);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B06E0);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B095C);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B0DD0);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B0F74);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B128C);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B1504);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B1688);

INCLUDE_ASM("../asm/us/magic_timedmg/nonmatchings/text", func_801B171C);
