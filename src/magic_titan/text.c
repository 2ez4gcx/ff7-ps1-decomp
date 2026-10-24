#include "common.h"
#include "magic_titan/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B5190();
    return &D_801C0EC8;
}

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B0068);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B0830);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B0E64);

s32 func_801B1A24(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801D3E02[-v];
    }
    return v;
}

s32 func_801B1A60(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;

    orig = t;
    if (s > 0) {
        n = s >> 8;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
    } else {
        s = -s;
        n = s >> 8;
        t = 0x1000 - t;
        for (i = 0; i < n; i++) {
            t = func_80039A74(t / 4);
        }
        t = 0x1000 - t;
    }
    n = (s & 0xFF) + 1;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B1B50);

void func_801B2B84(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1B50)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B2BE8);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B2CE0);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B2D88);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3014);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B30F8);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B31B8);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3358);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B37B0);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B391C);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3C2C);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B3E80);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B40A0);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4244);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4910);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4CC4);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B4F68);

INCLUDE_ASM("../asm/us/magic_titan/nonmatchings/text", func_801B5190);
