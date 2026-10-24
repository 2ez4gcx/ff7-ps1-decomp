#include "common.h"
#include "chocobo/decls.h"

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800ABABC);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AC554);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AD52C);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AD7B8);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AD7E8);

s32 func_800AD91C(WmHdr3 *arg0, s32 arg1, s32 arg2) {
    u32 i;
    s32 q;

    arg0->f20 = arg1;
    arg1 += arg0->a << 5;
    q = arg0->off + arg0->base;
    for (i = 0; i < arg0->cnt; i++) {
        arg1 = func_800AD9D8(q + i * 0x20, arg1, 0, arg2);
    }
    func_800AF9E4(arg0, arg0->f16, 0);
    return arg1;
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AD9D8);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AE534);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AE7D4);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AF11C);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AF9E4);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AFC64);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AFDBC);

s32 func_800B00DC(WmHdr3 *arg0, u8 *arg1) {
    u32 i;
    u32 cnt;
    s32 pad[2];
    s32 q;
    s16 x;
    s16 y;
    s16 z;

    cnt = arg0->cnt;
    q = arg0->off + arg0->base;
    x = (arg1[1] << 8) | arg1[0];
    y = (arg1[3] << 8) | arg1[2];
    z = (arg1[5] << 8) | arg1[4];
    *(s32 *)0x1F800200 = arg1[6];
    for (i = 0; i < cnt; i++) {
        func_800B01B0(q + i * 0x20, x, y, z);
    }
    return 1;
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800B01B0);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800B0E7C);
