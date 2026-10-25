#include "common.h"
#include "jet/decls.h"

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A0450);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A0874);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A0D78);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1198);

void func_800A12EC(void) {
    s32 acc;
    JetUnk24 *base;
    JetUnk24 *e;
    u16 i;
    JetLink *tbl;

    acc = *(s32 *)(D_800D1964 + 0x4370);
    base = (JetUnk24 *)D_800D1BFC;
    if (D_800D1C78 != 0) {
        i = D_800A8A60;
        tbl = D_800E2608;
        do {
            e = &base[i];
            acc = func_800A8734(e, acc, D_800D1964 + 0x70, e);
            i = tbl[i].next;
        } while (i != 0xFFFF);
    }
    *(s32 *)(D_800D1964 + 0x4370) = acc;
}

void func_800A13AC(void) {
    u16 i;
    s32 acc;
    JetLink *tbl;
    JetPair *p;
    JetPair *q;

    i = D_800A89DC;
    tbl = D_800D9948;
    acc = *(s32 *)(D_800D1964 + 0x437C);
loop:
    p = D_800D1C58;
    q = D_800EE194;
    acc = func_800A882C(&p[i], acc, D_800D1964 + 0x70, &q[i]);
    i = tbl[i].next;
    if (i != 0xFFFF) {
        goto loop;
    }
    *(s32 *)(D_800D1964 + 0x437C) = acc;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1450);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A16A4);

void func_800A1A64(void) {
    s32 *gp = &D_800D1964;
    u8 *p;
    s32 c;
    s32 ty;
    s32 tr;
    s16 x0;
    s16 x1;
    u8 pad[8];

    x0 = 0x14;
    x1 = 0x1C;
    do {
        p = ((JetDrawCtx *)*gp)->prim;
        c = D_800D1C5C;
        ty = 0xDC - c;
        *(s16 *)(p + 0xA) = ty;
        *(s16 *)(p + 0x12) = ty;
        *(s16 *)(p + 0x1A) = 0xDC;
        *(s16 *)(p + 0x22) = 0xDC;
        tr = -0x80 - c;
        *(u8 *)(p + 4) = tr;
        *(u8 *)(p + 0xC) = tr;
        *(s16 *)(p + 0x10) = x1;
        *(s16 *)(p + 0x20) = x1;
        *(s16 *)(p + 8) = x0;
        *(s16 *)(p + 0x18) = x0;
        *(u8 *)(p + 5) = c;
        *(u8 *)(p + 6) = 0;
        *(u8 *)(p + 0xD) = c;
        *(u8 *)(p + 0xE) = 0;
        *(u8 *)(p + 0x14) = 0x80;
        *(u8 *)(p + 0x15) = 0;
        *(u8 *)(p + 0x16) = 0;
        *(u8 *)(p + 0x1C) = 0x80;
        *(u8 *)(p + 0x1D) = 0;
        *(u8 *)(p + 0x1E) = 0;
        func_80046848(p, 0);
        ((JetTag *)p)->addr = ((JetDrawCtx *)*gp)->ot.addr;
        ((JetDrawCtx *)*gp)->ot.addr = (u32)p;
        p += 0x24;
        ((JetDrawCtx *)*gp)->prim = p;
    } while (0);
}

void func_800A1B64(s32 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 **pp;
    u8 *fl;
    u16 *cnt;
    u16 *q;
    s32 extra;
    s32 t;

    if (arg1 != 0 && arg1 != 0x5B) {
        pp = &D_800A8A74;
        **pp = D_800D1730[arg1];
        q = &D_800EE18C;
        *q += arg2;
        D_800EE18E += arg3;
        D_800EE190 += arg4;
        fl = &D_800E25E8;
        if (*fl == 1) {
            func_8003BF8C(q, (u8 *)*pp + 4);
            func_800A1198(arg0, *pp, 0, 0, extra);
            func_800A1CD8(D_800A8CC4, 0xDC, 0xA0, 0, 0x18);
        }
        cnt = (u16 *)&D_800A89CC;
        t = *cnt - 1;
        *cnt = t;
        if ((s16) t < 0x32) {
            if (*fl == 0) {
                *fl = 1;
            } else {
                *fl = 0;
            }
        }
        if (D_800A89CC == 0) {
            D_800A8A88 = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1CD8);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A1F18);

void func_800A2058(void) {
    s32 *gp = &D_800D1964;
    u8 *p;
    u16 *tp;
    u16 *cp;

    tp = &D_800A899A;
    cp = &D_800EE1A2;
    p = ((JetDrawCtx4 *)*gp)->prim;
    *(s16 *)(p + 8) = 0;
    *(s16 *)(p + 0xA) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s16 *)(p + 0x12) = 0;
    *(s16 *)(p + 0x18) = 0;
    *(s16 *)(p + 0x1A) = 0;
    *(s16 *)(p + 0x20) = 0;
    *(s16 *)(p + 0x22) = 0;
    *(u8 *)(p + 4) = 0x80;
    *(u8 *)(p + 5) = 0x80;
    *(u8 *)(p + 6) = 0x80;
    *(u8 *)(p + 0xC) = 0;
    *(u8 *)(p + 0xD) = 0;
    *(u8 *)(p + 0x14) = 0;
    *(u8 *)(p + 0x15) = 0;
    *(u8 *)(p + 0x1C) = 0;
    *(u8 *)(p + 0x1D) = 0;
    *(u8 *)(p + 0x24) = 0;
    *(u8 *)(p + 0x25) = 0;
    *(u16 *)(p + 0x16) = *tp;
    *(u16 *)(p + 0xE) = *cp;
    func_80046848(p, 0);
    ((JetTag *)p)->addr = ((JetDrawCtx4 *)*gp)->ot1.addr;
    ((JetDrawCtx4 *)*gp)->ot1.addr = (u32)p;
    p += 0x28;
    *(s16 *)(p + 8) = 0;
    *(s16 *)(p + 0xA) = 0;
    *(s16 *)(p + 0x10) = 0;
    *(s16 *)(p + 0x12) = 0;
    *(s16 *)(p + 0x18) = 0;
    *(s16 *)(p + 0x1A) = 0;
    *(s16 *)(p + 0x20) = 0;
    *(s16 *)(p + 0x22) = 0;
    *(u8 *)(p + 4) = 0x80;
    *(u8 *)(p + 5) = 0x80;
    *(u8 *)(p + 6) = 0x80;
    *(u8 *)(p + 0xC) = 0;
    *(u8 *)(p + 0xD) = 0;
    *(u8 *)(p + 0x14) = 0;
    *(u8 *)(p + 0x15) = 0;
    *(u8 *)(p + 0x1C) = 0;
    *(u8 *)(p + 0x1D) = 0;
    *(u8 *)(p + 0x24) = 0;
    *(u8 *)(p + 0x25) = 0;
    *(u16 *)(p + 0x16) = *tp;
    *(u16 *)(p + 0xE) = *cp;
    func_80046848(p, 0);
    ((JetTag *)p)->addr = ((JetDrawCtx4 *)*gp)->ot2.addr;
    ((JetDrawCtx4 *)*gp)->ot2.addr = (u32)p;
    p += 0x28;
    ((JetDrawCtx4 *)*gp)->prim = p;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2214);

INCLUDE_RODATA("../asm/us/jet/nonmatchings/text", D_800A0000);

void func_800A2420(void) {
    JetRect r = D_800A0000;

    func_80033E34(D_800A8310, D_800A8314, (s32) &D_800A89E4, 0);
    do {
    } while (func_80034B44() != 0);
    func_80033E34(D_800A8318, D_800A831C, 0x800F0000, 0);
    do {
    } while (func_80034B44() != 0);
    func_800A2518();
    func_80033E34(D_800A8320, D_800A8324, (s32) &D_800D1BD4, 0);
    do {
    } while (func_80034B44() != 0);
    func_80033E74(D_800A8328, D_800A832C, 0x800F0000, 0);
    do {
    } while (func_80034B44() != 0);
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2518);

void func_800A27F0(s32 arg0) {
    Unk80046D0C sp10;

    func_80046CFC(arg0);
loop_1:
    if (func_80046D0C(&sp10) != 0) {
        if (sp10.a_arg != 0) {
            func_80044000(sp10.a, (void *) sp10.a_arg);
        }
        if (sp10.b_arg != 0) {
            func_80044000(sp10.b, (void *) sp10.b_arg);
        }
        goto loop_1;
    }
}

void func_800A2860(void) {
    s16 *p = &D_8009A000;

    *p = 0x10;
    D_8009A004 = D_800D1BD4;
    func_8002DA7C();
    *p = 0xC0;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xB8;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xBC;
    D_8009A004 = 0;
    func_8002DA7C();
    *p = 0xA2;
    D_8009A004 = 0;
    func_8002DA7C();
    *p = 0x2A;
    D_8009A004 = 0x40;
    D_8009A008 = 0x177;
    func_8002DA7C();
}

void func_800A2938(void) {
    s16 *p = &D_8009A000;

    *p = 0xC1;
    D_8009A004 = 0xF0;
    D_8009A008 = 0;
    func_8002DA7C();
    *p = 0xB9;
    D_8009A004 = 0xF0;
    D_8009A008 = 0;
    func_8002DA7C();
}

void func_800A29AC(s16 arg0) {
    u8 *flag = &D_800A8928;
    s16 *p;
    s32 t;

    t = (*flag + 1) & 1;
    *flag = t;
    if (t == 0) {
        p = &D_8009A000;
        *p = 0xB0;
        D_8009A004 = 0;
        func_8002DA7C();
        *p = 0x28;
        D_8009A004 = 0x40;
        D_8009A008 = arg0;
        func_8002DA7C();
    }
    if (*flag == 1) {
        p = &D_8009A000;
        *p = 0xB1;
        D_8009A004 = 0;
        func_8002DA7C();
        *p = 0x29;
        D_8009A004 = 0x40;
        D_8009A008 = arg0;
        func_8002DA7C();
    }
}

void func_800A2AA0(s32 arg0) {
    s32 *p = &D_800A8958;

    if (*p == 0) {
        if ((arg0 & 0xFF) == 0) {
            goto zero;
        }
        D_8009A000 = 0x2B;
        D_8009A004 = 0x40;
        D_8009A008 = 0x22B;
        func_8002DA7C();
    }
    arg0 = arg0 & 0xFF;
    if (arg0 != 0) {
        D_800A833C = arg0;
        D_8009A000 = 0xB3;
        D_8009A004 = arg0;
        func_8002DA7C();
        *p = arg0;
        return;
    }
zero:
    D_8009A000 = 0x2B;
    D_8009A004 = 0x40;
    D_8009A008 = 0;
    func_8002DA7C();
    D_800A8958 = 0;
}

void func_800A2B78(void) {
    s16 *p = &D_8009A000;

    *p = 0xA2;
    D_8009A004 = D_800A8338;
    func_8002DA7C();
    *p = 0xA3;
    D_8009A004 = D_800A833C;
    func_8002DA7C();
}

void func_800A2BE0(void) {
    D_800A83CC = -0x1B76;
    D_800A83C8 = 0;
    D_800A83D0 = 0xC8;
    D_800E2604 = D_800D1BEC;
    D_800A8CC0 = D_800D1BE8;
    func_800A2DE4(0, 3);
    D_800D1960 = 1;
}

void func_800A2C50(void) {
    s32 v[3];
    u16 r[4];
    u16 w[4];
    s32 t;
    s32 *p;
    s32 *q;
    s32 *q2;

    p = &D_800D1C54;
    func_800A16A4(*p, -0x64, v, r);
    q = &D_800A897C;
    *p += *q;
    D_800A83B8 = v[0];
    D_800A83BC = v[1];
    D_800A83C0 = v[2];
    if ((s16) r[0] < 0) {
        r[0] += 0x1000;
    }
    D_800A83A4 = -r[2];
    t = func_80039A74((s16) r[0]) / 15;
    if (t > 0 && *q > 0xA7F8) {
        *q -= t;
    }
    if (t < 0) {
        q2 = &D_800A897C;
        if (*q2 <= 0x1D4BF) {
            *q2 -= t;
        }
    }
    D_800A83A8 = v[0];
    D_800A83AC = v[1];
    w[2] = 0;
    D_800A83B0 = v[2];
    w[0] = -r[0];
    w[1] = -r[1];
    func_8003BF8C(w, &D_800EE404);
    func_8003BF8C(&D_800A83A0, &D_800A8380);
    func_8003A63C(&D_800A8380, &D_800EE404, &D_800EE404);
}

void func_800A2DE4(s32 arg0, s32 arg1) {
    s32 b;
    s32 x;

    x = D_800A8CC0[arg0 & 0xFF];
    b = D_800D1BE4;
    D_800A8988 = b + x;
    D_800D1724 = *D_800E2604;
}

void func_800A2E30(void) {
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A2E38);

void func_800A334C(void) {
    s32 i;
    JetLink *p;

    D_800D172C = 0xFFFE;
    D_800A8CC8 = 0;
    D_800D1C60 = D_800D1BF4;
    D_800EE428 = D_800D1BF8;
    D_800D196C = D_800D1BDC;
    D_800EE188 = D_800D1BE0;
    for (i = 0; i < 12000; i++) {
        p = &D_800E2608[i];
        p->prev = 0xFFFF;
        p->next = 0xFFFF;
    }
    D_800D1C78 = 0;
    for (i = 0; i < 9000; i++) {
        p = &D_800D9948[i];
        p->prev = 0xFFFF;
        p->next = 0xFFFF;
    }
    D_800D1C50 = 0;
    D_800E25F8 = 1;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3414);

void func_800A35DC(s32 arg0) {
    u32 x;
    u32 y;
    u32 i;
    u32 j;
    u16 v;
    u16 **pp;
    u16 **qq;
    u32 *pa;
    s32 *pb;
    u32 old;
    s32 t;
    u32 n;
    u32 hi;

    pa = &D_800D172C;
    old = *pa;
    D_800A8CC8 = old;
    hi = old >> 18;
    *pa = old + arg0;
    pb = &D_800D16E0;
    t = *pb;
    n = (*pa >> 18) - hi;
    D_800A894C = n;
    *pb = t + n;
    for (i = 0; y = D_800E25F8, x = D_800A894C, i < x + y; i++) {
        pp = &D_800D1C60;
        while (1) {
            v = *(*pp)++;
            if (v == 0xFFFF) {
                break;
            }
            func_800A385C(v);
        }
    }
    for (j = 0; j < D_800A894C; j++) {
        qq = &D_800D196C;
        while (1) {
            v = *(*qq)++;
            if (v == 0xFFFF) {
                break;
            }
            func_800A3980(v);
        }
    }
}

void func_800A372C(void) {
    u32 x;
    u32 y;
    u32 i;
    u16 v;
    u16 **p;
    u8 *q;

    for (i = 0; y = D_800E25F8, x = D_800A894C, i < x + y; i++) {
        p = &D_800EE428;
        while (1) {
            v = *(*p)++;
            if (v == 0xFFFF) {
                break;
            }
            func_800A38D4(v);
        }
    }
    for (i = 0; i < D_800A894C; i++) {
        p = &D_800EE188;
        while (1) {
            v = *(*p)++;
            if (v == 0xFFFF) {
                break;
            }
            func_800A3A20(v);
        }
    }
    q = &D_800E25F8;
    if (*q == 1) {
        *q = 0;
    }
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A385C);

void func_800A38D4(u16 arg0) {
    JetLink *tbl;
    JetLink *e;
    JetLink *b;
    JetLink *f;
    u16 prev;
    u16 next;
    u16 *count;

    e = &D_800E2608[arg0];
    tbl = D_800E2608;
    prev = e->prev;
    next = e->next;
    if (prev != 0xFFFF) {
        tbl[prev].next = next;
    } else {
        D_800A8A60 = next;
    }
    if (next != 0xFFFF) {
        D_800E2608[next].prev = prev;
    } else {
        D_800D9930 = prev;
    }
    b = D_800E2608;
    f = &b[arg0];
    f->prev = 0xFFFF;
    f->next = 0xFFFF;
    count = &D_800D1C78;
    *count -= 1;
}

void func_800A3980(u16 arg0) {
    u16 *count;
    u16 n;
    JetLink *e;
    JetLink *tbl;
    JetLink *f;
    JetLink *b;
    u16 *tail;
    u16 t;

    count = &D_800D1C50;
    n = *count;
    if (n == 0) {
        b = D_800D9948;
        e = &b[arg0];
        e->prev = 0xFFFF;
        e->next = 0xFFFF;
        D_800A89DC = arg0;
        D_800D1C80 = arg0;
        *count = 1;
    } else {
        n++;
        tbl = D_800D9948;
        f = &tbl[arg0];
        tail = &D_800D1C80;
        t = *tail;
        f->next = 0xFFFF;
        f->prev = t;
        tbl[t].next = arg0;
        *tail = arg0;
        *count = n;
    }
}

void func_800A3A20(u16 arg0) {
    JetLink *tbl;
    JetLink *e;
    u16 prev;
    u16 next;
    u16 *count;

    e = &D_800D9948[arg0];
    tbl = D_800D9948;
    prev = e->prev;
    next = e->next;
    if (prev != 0xFFFF) {
        tbl[prev].next = next;
    } else {
        D_800A89DC = next;
    }
    if (next != 0xFFFF) {
        D_800D9948[next].prev = prev;
    } else {
        D_800D1C80 = prev;
    }
    count = &D_800D1C50;
    *count -= 1;
}

void func_800A3AAC(void) {
    s32 i;
    JetObj *p;

    for (i = 0; i < 100; i++) {
        p = &D_800D1DC0[i];
        p->unkD8 = -1;
        p->unkDA = 0;
    }
    D_800D9940 = 0;
    for (i = 0; i < 100; i++) {
        D_800D1970[i] = i + 1;
    }
    D_800D1C5C = 0x80;
    D_800E25EC = 0xA0;
    D_800D1C4C = 0;
    D_800D1C7C = 0;
    D_800E25F0 = 0x78;
    D_800A898C = 0;
    D_800A89E0 = 0;
    D_800EE42C = 0;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3B58);

void func_800A3C04(u32 arg0, u32 arg1, JetV3 *arg2, s32 arg3) {
    JetSV a;
    JetSV b;
    JetV3 d;
    JetSV *e;
    s32 t0, t1, t2;
    s32 p0, p1, p2;

    e = (JetSV *)((arg0 >> 16) * 8 + arg1);
    a.x = e[0].x;
    a.y = e[0].y;
    a.z = e[0].z;
    b.x = e[1].x;
    b.y = e[1].y;
    b.z = e[1].z;
    t0 = (s16) b.x - (s16) a.x;
    t1 = (s16) b.y - (s16) a.y;
    t2 = (s16) b.z - (s16) a.z;
    d.x = t0;
    d.y = t1;
    d.z = t2;
    p0 = t0 * (arg0 & 0xFFFF);
    p1 = t1 * (arg0 & 0xFFFF);
    p2 = t2 * (arg0 & 0xFFFF);
    *(volatile s32 *)&d.x = p0;
    d.x = p0 >> 16;
    *(volatile s32 *)&d.y = p1;
    d.y = p1 >> 16;
    *(volatile s32 *)&d.z = p2;
    d.z = p2 >> 16;
    if ((arg3 & 0xFF) == 0) {
        arg2->x = (s16) e[0].x + d.x;
        arg2->y = -(s16) e[0].y - d.y;
        arg2->z = -(s16) e[0].z - d.z;
    } else {
        arg2->x = (s16) e[0].x + d.x;
        arg2->y = (s16) e[0].y + d.y;
        arg2->z = (s16) e[0].z + d.z;
    }
}

void func_800A3D50(JetDrawCtx2 *arg0) {
    u8 *p;
    s32 x; s32 y; s16 x0; s16 y0; s16 x1; s16 y1;

    p = arg0->prim;
    x = D_800E25EC;
    y = D_800E25F0;
    x0 = x - 0x10;
    y0 = y - 0x10;
    x1 = x + 0x10;
    y1 = y + 0x10;
    *(s16 *)(p + 0x10) = x1;
    *(s16 *)(p + 0x20) = x1;
    *(u8 *)(p + 4) = 0x80;
    *(u8 *)(p + 5) = 0x80;
    *(u8 *)(p + 6) = 0x80;
    *(s16 *)(p + 8) = x0;
    *(s16 *)(p + 0xA) = y0;
    *(s16 *)(p + 0x12) = y0;
    *(s16 *)(p + 0x18) = x0;
    *(s16 *)(p + 0x1A) = y1;
    *(s16 *)(p + 0x22) = y1;
    *(u8 *)(p + 0xC) = 0;
    *(u8 *)(p + 0xD) = 0;
    *(u8 *)(p + 0x14) = 0x40;
    *(u8 *)(p + 0x15) = 0;
    *(u8 *)(p + 0x1C) = 0;
    *(u8 *)(p + 0x1D) = 0x40;
    *(u8 *)(p + 0x24) = 0x40;
    *(u8 *)(p + 0x25) = 0x40;
    *(u16 *)(p + 0x16) = D_800A8990;
    *(u16 *)(p + 0xE) = D_800EE198;
    func_80046848(p, 0);
    ((JetTag *)p)->addr = arg0->ot.addr;
    arg0->ot.addr = (u32)p;
    p += 0x28;
    arg0->prim = p;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A3E58);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A40F4);

void func_800A4390(void *arg0) {
    s16 *p;

    if (M2C_FIELD(arg0, s16 *, 0xD8) != -1) {
        p = &D_800EE42C;
        *p -= 1;
        func_800A8204(M2C_FIELD(arg0, void **, 0xD4));
        func_800A442C(M2C_FIELD(arg0, s16 *, 0xD8));
        M2C_FIELD(arg0, s16 *, 0xD8) = -1;
        M2C_FIELD(arg0, s16 *, 0xDA) = 0;
    }
}

s16 func_800A4400(void) {
    s16 *p;
    s16 i;

    p = &D_800D9940;
    i = *p;
    *p = D_800D1970[i];
    return i;
}

void func_800A442C(s16 arg0) {
    s16 *p;
    s16 *q;

    q = &D_800D1970[arg0];
    p = &D_800D9940;
    *q = *p;
    *p = arg0;
}

void func_800A4458(void) {
    u8 *tbl;
    s32 i;
    s32 j;
    s32 k;
    u8 *cnt;
    JetEnt *base;
    JetEnt *ent;
    s32 *p;
    s32 *dst;
    s32 *cfc;

    for (i = D_800A898C; i < D_800D16E0; i++) {
        tbl = D_800D1C10;
        cnt = tbl + i;
        cfc = D_800D1CFC;
        p = &D_800A89E0;
        for (j = 0; j < *cnt; j++) {
            base = D_800D1C0C;
            for (k = 0, dst = cfc; k < 20; k++) {
                *dst++ = *(s32 *)(k * 4 + (s32)&base[*p].data[0]);
            }
            ent = (JetEnt *)(*p * 0x60 + (s32)base);
            D_800D1CC4 = *(s32 *)((u8 *)ent + 8);
            D_800D1CC8 = *(s32 *)((u8 *)ent + 0xC);
            func_800A45C0(0, 0, 0, *(s16 *)((u8 *)ent + 0), *(s16 *)((u8 *)ent + 4));
            *p += 1;
        }
    }
    D_800A898C = D_800D16E0;
}

void func_800A45C0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    JetFld *p = &D_800D1C84;

    p->x = arg0;
    D_800D1C88 = arg1;
    D_800D1C8C = arg2;
    D_800D1CAC = arg3;
    D_800D1CBC = 1;
    D_800D1CB0 = 0;
    D_800D1CB4 = (s16) arg4;
    func_800A40F4(p, 0, arg2, arg3);
}

void func_800A4650(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    JetFld *p = &D_800D1C84;

    p->x = arg0;
    D_800D1C88 = arg1;
    D_800D1C8C = arg2;
    D_800D1CAC = arg3;
    D_800D1CBC = 1;
    D_800D1CB0 = 0;
    D_800D1D2C = 0;
    D_800D1CB4 = (s16) arg4;
    func_800A40F4(p, 0, arg2, arg3);
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A46E8);

void func_800A6B08(JetSpawn *arg0) {
    u32 v;
    s32 hp;
    s32 *p;
    s32 x;
    s32 a;
    s32 b;

    v = (u16) D_800D1C5C >> 5;
    if ((v & 0xFF) == 0) {
        v = 1;
    }
    hp = arg0->fAC - (v & 0xFF);
    arg0->fAC = hp;
    if (hp < 0) {
        func_800A6BD8(arg0);
        return;
    }
    a = arg0->f4;
    b = arg0->f8;
    x = arg0->x;
    p = &D_800D1CAC;
    *p = 0xCA;
    D_800D1CBC = 1;
    D_800D1CB4 = 0x3F;
    D_800D1CB0 = 0;
    D_800D1D2C = 0;
    D_800D1C84.x = x;
    D_800D1C88 = (s16) a;
    D_800D1C8C = (s16) b;
    func_800A40F4((JetFld *)(p - 10), 0);
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A6BD8);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A70D4);

s32 func_800A7414(s32 *arg0) {
    s32 a, b, c, d, e, f;
    s32 x, y, z;
    s32 s1, s2;
    s32 r2, r1;

    a = D_800A892C;
    b = D_800A8930;
    c = D_800A8934;
    d = D_800A893C;
    e = D_800A8940;
    f = D_800A8944;
    x = arg0[0] >> 2;
    y = arg0[1] >> 2;
    z = arg0[2] >> 2;
    r1 = 0;
    r2 = 0;
    s1 = a * x + b * y + c * z + D_800A8A5C;
    s2 = d * x + e * y + f * z + D_800A8A64;
    if (s1 > 0) {
        r1 = D_800A8950 > 0;
    }
    if (s1 < 0 && D_800A8950 < 0) {
        r1 = 1;
    }
    if (s2 > 0 && D_800A8968 > 0) {
        r2 = 1;
    }
    if (s2 < 0 && D_800A8968 < 0) {
        r2 = 1;
    }
    return r1 & r2;
}

s32 func_800A7544(u16 *arg0) {
    s32 a, b, c, d, e, f;
    s32 x, y, z;
    s32 s1, s2;
    s32 r2, r1;

    a = D_800A892C;
    b = D_800A8930;
    c = D_800A8934;
    d = D_800A893C;
    e = D_800A8940;
    f = D_800A8944;
    x = (s16) arg0[0] >> 2;
    y = (s16) arg0[1] >> 2;
    z = (s16) arg0[2] >> 2;
    r1 = 0;
    r2 = 0;
    s1 = a * x + b * y + c * z + D_800A8A5C;
    s2 = d * x + e * y + f * z + D_800A8A64;
    if (s1 > 0) {
        r1 = D_800A8950 > 0;
    }
    if (s1 < 0 && D_800A8950 < 0) {
        r1 = 1;
    }
    if (s2 > 0 && D_800A8968 > 0) {
        r2 = 1;
    }
    if (s2 < 0 && D_800A8968 < 0) {
        r2 = 1;
    }
    return r1 & r2;
}

s32 func_800A7688(s32 arg0, s32 arg1, s32 arg2) {
    s32 a, b, c;
    a = D_800A892C;
    b = D_800A8930;
    c = D_800A8934;
    return a * (arg0 >> 2) + b * (arg1 >> 2) + c * (arg2 >> 2) + D_800A8A5C;
}

s32 func_800A76DC(s32 arg0, s32 arg1, s32 arg2) {
    s32 a, b, c;
    a = D_800A893C;
    b = D_800A8940;
    c = D_800A8944;
    return a * (arg0 >> 2) + b * (arg1 >> 2) + c * (arg2 >> 2) + D_800A8A64;
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A7730);

s32 func_800A7928(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 a, b, c;
    s32 sum;
    s32 ret;
    s32 d;

    a = D_800A892C;
    b = D_800A8930;
    c = D_800A8934;
    ret = 0;
    sum = a * (arg0 >> 2) + b * (arg1 >> 2) + c * (arg2 >> 2) + D_800A8A5C;
    if (D_800A8950 > 0) {
        ret = (u32) ~sum >> 31;
    }
    if (D_800A8950 < 0 && sum <= 0) {
        ret = 1;
    }
    if (ret == 0) {
        d = D_800AB890;
        if (sum < 0) {
            sum = -sum;
        }
        if (sum / d < arg3) {
            ret = 1;
        }
    }
    return ret;
}

s32 func_800A7A10(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 a, b, c;
    s32 sum;
    s32 ret;
    s32 d;

    a = D_800A893C;
    b = D_800A8940;
    c = D_800A8944;
    ret = 0;
    sum = a * (arg0 >> 2) + b * (arg1 >> 2) + c * (arg2 >> 2) + D_800A8A64;
    if (D_800A8968 > 0) {
        ret = (u32) ~sum >> 31;
    }
    if (D_800A8968 < 0 && sum <= 0) {
        ret = 1;
    }
    if (ret == 0) {
        d = D_800D0550;
        if (sum < 0) {
            sum = -sum;
        }
        if (sum / d < arg3) {
            ret = 1;
        }
    }
    return ret;
}

void func_800A7AF8(void) {
    D_800A8A70 = 0;
    D_800D171C = 0;
    D_800A8A8C = 0;
    D_800A8CCC = D_800D1BFC;
    D_800D1968 = D_800D1C14;
    D_800A89D8 = D_800D1BD8;
}

JetUnk20 *func_800A7B48(s32 arg0) {
    JetSpr *spr;
    JetSprDef *def;
    s32 x;
    s32 y;

    spr = (JetSpr *)func_800A7BF4();
    def = &((JetSprDef *)D_800A89D8)[arg0];
    x = def->x;
    y = def->y;
    spr->unk16 = def->unk4;
    spr->unk14 = def->unkC;
    spr->unk1A = def->unk8;
    spr->unk18 = def->unk10;
    spr->unk2 = 0;
    spr->unk4 = x;
    spr->unk6 = y;
    spr->unk8 = 0;
    spr->unk0 = x + y;
    spr->unkC = func_800A7C20(x);
    spr->unk10 = func_800A7C54(y);
    return (JetUnk20 *)spr;
}

JetUnk20 *func_800A7BF4(void) {
    s32 *p;
    JetUnk20 *base;
    s32 n;

    p = &D_800A8A8C;
    n = *p;
    *p = n + 1;
    base = D_800D0554;
    return base + n;
}

JetUnk24 *func_800A7C20(s32 arg0) {
    s32 *p;
    s32 n;
    JetUnk24 *base;

    p = &D_800A8A70;
    n = *p;
    *p = n + arg0;
    base = (JetUnk24 *)D_800A8CCC;
    return base + n;
}

JetUnk28 *func_800A7C54(s32 arg0) {
    s32 *p;
    s32 n;
    JetUnk28 *base;

    p = &D_800D171C;
    n = *p;
    *p = n + arg0;
    base = (JetUnk28 *)D_800D1968;
    return base + n;
}

void func_800A7C88(void) {
    u8 *p; u8 *q; s32 off = 0x12674;

    p = (u8 *)&D_800AB898;
    func_80043814((Spr *)p, 0, 0, 0x140, 0xF0);
    func_800438D4((DispEnv *)(p + 0x5C), 0, 0xF0, 0x140, 0xF0);
    func_80043814(&D_800BDEF4, 0, 0xF0, 0x140, 0xF0);
    func_800438D4(&D_800BDF50, 0, 0, 0x140, 0xF0);
    D_800AB8B0 = 0;
    *(s8 *)(p + off) = 0;
    D_800AB8B1 = 0;
    D_800AB8B2 = 0;
    D_800AB8B3 = 8;
    D_800BDF0D = 0;
    D_800BDF0E = 0;
    D_800BDF0F = 8;
    func_8003B6BC(0xA0, 0xA0);
    func_8003B6DC(0x100);
    func_80043D3C(1);
    func_8003B67C(0x80, 0x80, 0x80);
    func_8003B69C(0, 0, 8);
    q = p + 0x4368;
    func_800A7E70(q);
    func_800A7E70(&D_800C225C);
    func_800A7FAC(q);
    func_800A7FAC(&D_800C225C);
    func_80044244((s32) (p + 0x70), 0x1000);
    func_80044244((s32) &D_800BDF64, 0x1000);
    func_80044244((s32) (p + 0x4098), 0xB4);
    func_80044244((s32) &D_800C1F8C, 0xB4);
    D_800D1964 = (s32) p;
}

void func_800A7E1C(void) {
    s32 *p = &D_800D1964;

    func_80044244(*p + 0x70, 0x1000);
    func_80044244(*p + 0x4098, 0xB4);
    func_800A7FAC((void *)(*p + 0x4368));
}

void func_800A7E70(u8 *arg0) {
    s32 i;

    for (i = 0; i < 1; i++) {
        func_80046898(arg0 + 0x24 + i * 0x14);
    }
    for (i = 0; i < 1; i++) {
        func_800468E8(arg0 + 0x38 + i * 0x18);
    }
    for (i = 0; i < 0x640; i++) {
        func_800468C0(arg0 + 0x50 + i * 0x1C);
    }
    for (i = 0; i < 0x1E; i++) {
        func_80046910(arg0 + 0xAF50 + i * 0x24);
    }
    for (i = 0; i < 1; i++) {
        func_800468AC(arg0 + 0xB388 + i * 0x20);
    }
    for (i = 0; i < 0x12C; i++) {
        func_800468FC(arg0 + 0xB3A8 + i * 0x28);
    }
    for (i = 0; i < 1; i++) {
        func_800468D4(arg0 + 0xE288 + i * 0x28);
    }
    for (i = 0; i < 1; i++) {
        func_80046924(arg0 + 0xE2B0 + i * 0x34);
    }
    for (i = 0; i < 1; i++) {
        func_800469C4(arg0 + 0xE2E4 + i * 0x10);
    }
}

void func_800A7FAC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg0 + 0x24);
    M2C_FIELD(arg0, void **, 4) = (void *) (arg0 + 0x38);
    M2C_FIELD(arg0, void **, 8) = (void *) (arg0 + 0x50);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (arg0 + 0xAF50);
    M2C_FIELD(arg0, void **, 0x10) = (void *) (arg0 + 0xB388);
    M2C_FIELD(arg0, void **, 0x14) = (void *) (arg0 + 0xB3A8);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (arg0 + 0xE288);
    M2C_FIELD(arg0, void **, 0x1C) = (void *) (arg0 + 0xE2B0);
    M2C_FIELD(arg0, void **, 0x20) = (void *) (arg0 + 0xE2E4);
}

void func_800A8010(void) {
    s32 i;
    JetNode *a;
    JetNode *b;

    func_800A80A8(&D_800D16E4, 0);
    D_800D1710 = 0;
    D_800D9944 = 0;
    for (i = 0; i < 200; i++) {
        D_800D1A40[i] = i + 1;
    }
    for (i = 0; i < 10; i++) {
        a = &D_800A8A90[i];
        b = &D_800EE1D4[i];
        a->next = NULL;
        a->prev = b;
        b->next = a;
        b->prev = NULL;
    }
}

void func_800A80A8(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 4) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0xC) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x14) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x24) = &D_800D16E4;
    M2C_FIELD(arg0, s16 *, 0x2A) = arg1;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}

JetNode *func_800A80F8(s16 arg0, s32 arg1, s32 arg2, s32 arg3, JetNode *arg4, s32 arg5, s32 arg6, s32 arg7, u16 arg8, u16 arg9, u16 arg10) {
    u16 v[3];
    s16 id;
    JetNode *n;
    JetNode *base;

    id = func_800A8238();
    base = D_800A8CD0;
    n = &base[id];
    func_800A8290(n, arg4);
    *(s32 *)n = D_800D1730[arg0];
    n->unk28 = arg0;
    n->unk2A = id;
    v[0] = arg8;
    v[1] = arg9;
    v[2] = arg10;
    func_8003BF8C(v, &n->pad0[4]);
    *(s32 *)&n->pad0[0x18] = arg5;
    *(s32 *)&n->pad0[0x1C] = arg6;
    *(s32 *)&n->pad0[0x20] = arg7;
    return n;
}

void func_800A8204(void *arg0) {
    func_800A82F0(arg0);
    func_800A8264(M2C_FIELD(arg0, s16 *, 0x2A));
}

s16 func_800A8238(void) {
    s16 *p;
    s16 i;

    p = &D_800D9944;
    i = *p;
    *p = D_800D1A40[i];
    return i;
}

void func_800A8264(s16 arg0) {
    s16 *p;
    s16 *q;

    q = &D_800D1A40[arg0];
    p = &D_800D9944;
    *q = *p;
    *p = arg0;
}

void func_800A8290(JetNode *arg0, JetNode *arg1) {
    s16 depth;
    JetNode *head;

    arg0->parent = arg1;
    depth = arg1->depth + 1;
    arg0->depth = depth;
    head = &D_800EE1D4[depth];
    arg0->next = head->next;
    arg0->prev = arg0->next->prev;
    head->next->prev = arg0;
    head->next = arg0;
}

void func_800A82F0(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x34) = (void *) M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x30) = (void *) M2C_FIELD(arg0, void **, 0x30);
}

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A8310);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A83F0);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A84A4);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A84DC);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A8604);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A8734);

INCLUDE_ASM("../asm/us/jet/nonmatchings/text", func_800A882C);
