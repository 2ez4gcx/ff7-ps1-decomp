#include "common.h"
#include "magic_lunatic/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B0D44();
    return &D_801C96E0;
}

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B007C);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0484);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B05F0);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0798);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0944);

INCLUDE_ASM("../asm/us/magic_lunatic/nonmatchings/text", func_801B0B28);

INCLUDE_RODATA("../asm/us/magic_lunatic/nonmatchings/text", D_801B0000);

void func_801B0D44(mask, arg1) {
    s32 i;
    s32 n;

    D_801E23DC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0E10, 0, 0, 0);
    D_801E23E0 = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801E23E4 = i;
            }
        }
    }
    D_801E23E8 = arg1;
    func_800BBEAC(&func_801B0B28);
}
