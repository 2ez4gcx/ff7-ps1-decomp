#include "common.h"
#include "chocobo/decls.h"

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800ABABC);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text4", func_800AC554);

void func_800AD52C(void) {
    s32 i;
    s32 *pi;
    u8 **pb;
    ChoRow *p1;
    ChoRow *p2;
    ChoRow *p3;
    ChoRow *p4;
    ChoRow *p5;
    ChoRow *p6;
    s32 tp;
    s32 idx;
    u8 *buf;

    func_800AD7B8(D_800B23EC[D_800B745C], 0x10, 0x25, 0xAC);
    func_800AD7B8(D_800B23EC[D_800B7460], 0x10, 0x25, 0xC0);
    func_800AD7B8(D_800B23EC[D_800B7464], 0x10, 0x25, 0xD4);
    i = 0;
    pb = &D_800F5074;
    pi = &D_800F5034;
    for (; i < 3; i++) {
        p1 = (ChoRow *)((s32)*pb + *pi * 0x28);
        p1->q.x0 = p1->q.x2 = 0xF;
        p1->q.y0 = p1->q.y1 = 0xA9 + i * 0x15;
        p1->q.x1 = p1->q.x3 = 0x1F;
        p1->q.y2 = p1->q.y3 = 0xB9 + i * 0x15;
        tp = func_8004656C(0, 0, 0x280, 0x100);
        p2 = (ChoRow *)((s32)*pb + *pi * 0x28);
        p2->q.tpage = tp;
        p2->q.clut = 0x7A64;
        p2->q.u0 = p2->q.u2 = 0xD8;
        p3 = (ChoRow *)((s32)*pb + *pi * 0x28);
        p3->q.u1 = p3->q.u3 = 0xE8;
        p4 = (ChoRow *)((s32)*pb + *pi * 0x28);
        p4->q.v0 = p4->q.v1 = -0x68 + i * 0x22;
        p5 = (ChoRow *)((s32)*pb + *pi * 0x28);
        p5->q.v2 = p5->q.v3 = -0x58 + i * 0x22;
        p6 = (ChoRow *)(*pi * 0x28 + (s32)*pb);
        *(s32 *)&p6->q.r0 = 0x2E808080;
        ((u8 *)&p6->q)[3] = 9;
        idx = *pi;
        buf = *pb;
        ((ChoRow *)(buf + idx * 0x28))->q.tag.addr = ((ChoTag *)(buf + 8))->addr;
        ((ChoTag *)(buf + 8))->addr = (u32)(buf + (idx * 0x28 + 0x4010));
        *pi = idx + 1;
    }
}

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
