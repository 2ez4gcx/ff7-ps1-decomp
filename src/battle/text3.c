#include "common.h"
#include "battle/decls.h"

s32 func_800E5F30(void) {
    s32 i;
    s32 ret;

    for (i = 0; i < 3; i++) {
        if (D_8009CBDC[i] != 0xFF) {
            ret = D_8009CBDC[i];
        }
    }
    return ret;
}

s32 func_800E5F70(void) {
    s32 r;
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_8009CBDC[i] != 0xFF) {
            r = i;
        }
    }
    return r;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E5FB4);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E6018);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E60F8);

void func_800E6820(void) {
    func_80026B70(&D_800F384A);
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E6848);

void func_800E68B4(void) {
    switch (D_800F38A5) {
    case 0:
        D_801516F8 = D_8016375C;
        break;
    case 1:
        D_801516F8 = D_8016375E;
        break;
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E6904);

s32 func_800E6B40(void) {
    s32 i;
    s32 m;

    m = (1 << D_800F38A7) & D_801516F8;
    for (i = 0; i < 3; i++) {
        if (m & D_8016376E[i]) {
            return i;
        }
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E6B94);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E6DCC);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E7170);
