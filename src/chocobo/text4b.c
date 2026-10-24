#include "common.h"
#include "chocobo/decls.h"

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AD9D8);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AE534);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AE7D4);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AF11C);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AF9E4);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AFC64);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800AFDBC);

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

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800B01B0);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4b", func_800B0E7C);
