#include "common.h"
#include "chocobo/decls.h"

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800ABABC);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AC554);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AD52C);

void func_800AD7B8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80026F44(arg2, arg3, arg0, 7);
}

void func_800AD7E8(void) {
    ChoSpr sp10;
    u8 sp70[0x40];
    s32 *p;
    s32 *q;
    s32 v;
    ChoSpr *src;
    u8 c;

    if (D_800B7514 != 0) {
        src = (ChoSpr *)(D_800F5074 + 0x1EA70); sp10 = *src;
        sp10.e = func_8004656C(0, 2, 0, 0);
        sp10.g = 0;
        func_80044AC0((s32)sp70, (Spr *)&sp10);
        func_800442DC(sp70);
        c = D_800B7514;
        D_800B14BA = c;
        D_800B14B9 = c;
        D_800B14B8 = c;
        func_800442DC(D_800B14B4);
    }
    p = &D_800B7514;
    q = &D_800F5070;
    v = *p + *q;
    *p = v;
    if (v < 0) {
        *p = 0;
        *q = 0;
    } else if (v > 0x100) {
        *p = 0x100;
    }
}

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
