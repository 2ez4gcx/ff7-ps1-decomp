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

s32 func_800B0E7C(WmHdr3 *arg0, u8 *arg1) {
    ChoBlk *q;
    ChoBlk *blk;
    u8 *p;
    u32 flag;
    u32 n;
    u32 i;
    u32 j;
    u32 k;

    q = (ChoBlk *)(arg0->off + arg0->base);
    flag = *arg1;
    for (k = 0; k < arg0->cnt; k++) {
        blk = &q[k];
        for (j = 0; j < 2; j++) {
            p = blk->base;
            if (j != 0) {
                p += blk->off;
            }
            n = blk->n[0];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x34;
            }
            n = blk->n[1];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x28;
            }
            n = blk->n[2];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x28;
            }
            n = blk->n[3];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x20;
            }
            n = blk->n[4];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x14;
            }
            n = blk->n[5];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x18;
            }
            n = blk->n[6];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x1C;
            }
            n = blk->n[7];
            for (i = 0; i < n; i++) {
                if (flag != 0) {
                    p[7] |= 2;
                } else {
                    p[7] &= 0xFD;
                }
                if (flag != 0) {
                    p[7] |= 1;
                } else {
                    p[7] &= 0xFE;
                }
                p += 0x24;
            }
        }
    }
    return 1;
}
