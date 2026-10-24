#include "common.h"
#include "field/decls.h"

void func_800A1368(void) {
    if (D_800965E8 == 0) {
        func_80033E74(D_800DA5C0[(s16)D_8009A05C * 6], D_800DA5C0[(s16)D_8009A05C * 6 + 1], 0x80128000, 0);
        while (func_80034B44() != 0) {
        }
    } else {
        while (func_80034B44() != 0) {
        }
        func_80034BB0(0x801B0000, 0x80128000);
    }
    func_80033E74(D_800DA5B8[(s16)D_8009A05C * 6], D_800DA5B8[(s16)D_8009A05C * 6 + 1], 0x80114FE4, 0);
    while (func_80034B44() != 0) {
    }
    D_800716C4 = *D_8009AD28;
    D_80071A54 = *D_8009C55C;
    D_8007E770 = *D_80070784;
    D_8008357C = D_8007E770 + 4;
}

void func_800A1498(void) {
    if (D_800965E8 == 1) {
        func_8003408C();
    }
    D_80071A5C = 0;
    D_800965E8 = 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A14D8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A16CC);
