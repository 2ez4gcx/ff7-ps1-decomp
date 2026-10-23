#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A1158);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A1798);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A22C0);

void func_800A23BC(s32 arg0) {
    if (D_800E7A38 == arg0) {
        D_800E7A38 = -1;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A23E0);

void func_800A283C(void) {
    u32 i;
    u32 start;
    s32 k;

    k = 0;
    for (i = 0, start = 0; i < 0x6D; i++) {
        if (i == start) {
            D_800F38AC[k] = i;
            k++;
        }
        if (D_800A0098[i] == 0x1F) {
            start = i + 1;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2894);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2974);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text", func_800A2B28);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A0098);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A0108);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", D_800A010C);

INCLUDE_RODATA("../asm/us/battle/nonmatchings/text", jtbl_800A0120);
