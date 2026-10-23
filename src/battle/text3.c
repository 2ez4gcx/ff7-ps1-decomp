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

s32 func_800E5FB4(s32 arg0, s32 arg1) {
    s32 r;

    r = 0;
    switch (arg0) {
    case 0:
        if (arg1 == 4) {
            r = 1;
        }
        break;
    case 1:
        if (arg1 == 10) {
            r = 1;
        }
        break;
    case 2:
        if (arg1 == 5) {
            r = 1;
        }
        break;
    case 3:
        if (arg1 == 9) {
            r = 1;
        }
        break;
    case 4:
        if (arg1 == 8) {
            r = 1;
        }
        break;
    case 5:
        r = 1;
        break;
    }
    return r;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E6018);

INCLUDE_ASM("../asm/us/battle/nonmatchings/text3", func_800E60F8);

void func_800E6820(void) {
    func_80026B70(&D_800F384A);
}

void func_800E6848(void) {
    func_80026F44(0x10, 8, D_800F3828[0], 7);
    func_80026F44(0x2C, 0x1C, D_800F3828[1], 7);
    func_80026F44(((s32 (*)(void)) func_800E6820)() + 0x4C, 0x1C, D_800F3828[2], 7);
}

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
