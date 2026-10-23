#include "common.h"
#include "battle/decls.h"

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2d", func_800E4C08);

void func_800E5358(void) {
    s32 i;
    s32 v;

    for (i = 0; i < 3; i++) {
        v = (D_800F338C[i] >> ((u8) D_800F5764 + 1)) & 0xF;
        D_80163774[i] = D_800F332C[i][(1 - v) & 0xF];
    }
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2d", func_800E53C8);

s32 func_800E54EC(void) {
    if (D_800F33A0 == 0) {
        return 0;
    }
    if (D_800F33AA == D_800F5774) {
        return 2;
    }
    return 1;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2d", func_800E5530);

void func_800E5814(void) {
    s32 i;

    for (i = 0; i < D_800F5774; i++) {
        D_80163778[i] = D_800F33B0[D_80163B70[i]][(2 - D_800F338C[i] / 4) & 0xF];
    }
}

void func_800E58B0(void) {
    D_800F3468 = 0;
    D_800F5760 = 0xA;
}

void func_800E58CC(void) {
    s32 i;
    u32 *src;

    src = (u32 *) 0x801B0000;
    for (i = 0; i < 3; i++) {
        D_800F5778[D_80163604 * 3 + i] = src[D_80163600 * 21 + i * 7 + D_80163604];
    }
}

u8 func_800E593C(void) {
    return D_800F381C[D_80163604];
}

s32 func_800E5960(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("../asm/us/battle/nonmatchings/text2d", func_800E5978);
