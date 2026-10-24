#include "common.h"
#include "magic_deadsef/decls.h"

void func_801B0040(void) {
    func_801B384C();
}

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B0060);

s32 func_801B0DE4(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801CF89A[-v];
    }
    return v;
}

s32 func_801B0E20(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B0F18);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B1014);

void func_801B1F6C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1014)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B1FD0);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B2748);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B2908);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B2C30);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B2DFC);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B2EFC);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B2F64);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B3108);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B3274);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B338C);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B3568);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B361C);

INCLUDE_ASM("../asm/us/magic_deadsef/nonmatchings/text", func_801B384C);
