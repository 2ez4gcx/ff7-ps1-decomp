#include "common.h"
#include "magic_wpsi/decls.h"

void func_801B0054(void) {
    D_801D2C34 = &D_801B2564;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B008C(void) {
    D_801D2C34 = &D_801B28E8;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B00C4(void) {
    D_801D2C34 = &D_801B30CC;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B00FC(void) {
    D_801D2C34 = &D_801B3B48;
    D_801D2C38 = 1;
    func_801B24B0();
}

void func_801B0138(void) {
    D_801D2C34 = &D_801B466C;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B0170(void) {
    D_801D2C34 = &D_801B5020;
    D_801D2C38 = 1;
    func_801B24B0();
}

void func_801B01AC(void) {
    D_801D2C34 = &D_801B5B44;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B01E4(void) {
    D_801D2C34 = &D_801B63C8;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B021C(void) {
    D_801D2C34 = &D_801B6CBC;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B0254(void) {
    D_801D2C34 = &D_801B7748;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B028C(void) {
    D_801D2C34 = &D_801B814C;
    D_801D2C38 = 1;
    func_801B24B0();
}

void func_801B02C8(void) {
    D_801D2C34 = &D_801B8BF0;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B0300(void) {
    D_801D2C34 = &D_801B95A8;
    D_801D2C38 = 2;
    func_801B24B0();
}

void func_801B033C(void) {
    D_801D2C34 = &D_801BA12C;
    D_801D2C38 = 0;
    func_801B24B0();
}

s32 func_801B0374(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0450(s32 ang, MgMat *m, MgVec *v) {
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    s32 z;
    s32 xx;
    s32 yy;
    s32 zz;
    s32 omc;

    s = func_80039A74(ang);
    c = func_80039B40(ang);
    x = v->vx;
    y = v->vy;
    z = v->vz;
    omc = 0x1000 - c;
    xx = (x * x) >> 12;
    yy = (y * y) >> 12;
    zz = (z * z) >> 12;
    m->m[0][0] = xx + (((0x1000 - xx) * c) >> 12);
    m->m[0][1] = ((((x * y) >> 12) * omc) >> 12) - ((z * s) >> 12);
    m->m[0][2] = ((((x * z) >> 12) * omc) >> 12) + ((y * s) >> 12);
    m->m[1][0] = ((((x * y) >> 12) * omc) >> 12) + ((z * s) >> 12);
    m->m[1][1] = yy + (((0x1000 - yy) * c) >> 12);
    m->m[1][2] = ((((y * z) >> 12) * omc) >> 12) - ((x * s) >> 12);
    m->m[2][0] = ((((x * z) >> 12) * omc) >> 12) - ((y * s) >> 12);
    m->m[2][1] = ((((y * z) >> 12) * omc) >> 12) + ((x * s) >> 12);
    m->m[2][2] = zz + (((0x1000 - zz) * c) >> 12);
}

void func_801B05CC(MgSVec *p, MgSVec *o, MgVec *n) {
    MgVec d;
    s32 dot;

    d.vx = p->vx - o->vx;
    d.vy = p->vy - o->vy;
    d.vz = p->vz - o->vz;
    dot = (n->vx * d.vx + n->vy * d.vy + n->vz * d.vz) >> 12;
    p->vx -= (dot * n->vx) >> 12;
    p->vy -= (dot * n->vy) >> 12;
    p->vz -= (dot * n->vz) >> 12;
}

s16 func_801B06A8(MgSVec *p, MgSVec *q, MgVec *n) {
    MgVec up;
    s32 a;
    s32 b;

    up.vx = 0;
    up.vy = -0x1000;
    up.vz = 0;
    a = p->vx * n->vx + p->vy * n->vy + p->vz * n->vz;
    b = q->vx * n->vx + q->vy * n->vy + q->vz * n->vz;
    return (b - a) / ((n->vx * up.vx + n->vy * up.vy + n->vz * up.vz) >> 12);
}

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B078C);

void func_801B08B4(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0 + 4;
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32 *, 8) = func_8003BBDC(arg1, arg0 + 0x40, temp_s2, temp_s1);
    func_8003BBDC(arg2, arg0 + 0x44, temp_s2, temp_s1);
}

void func_801B0928(MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;
    MgTag *ot;
    s32 otz;
    s32 sxy;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801D2BF0;
    otz = func_8003BBDC(v0, &p->x0, &sxy, &flag);
    func_8003BBDC(v1, &p->x1, &sxy, &flag);
    p->tag.len = 4;
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->code = 0x52;
    ot = (MgTag *)D_801517C0 + (otz >> 2) + 0x1C;
    p->tag.addr = ot->addr;
    ot->addr = (u32)p;
    p++;
    D_801D2BF0 = p;
}

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0A2C);

void func_801B0A8C(MgRing *r, s32 val) {
    s32 head;
    s32 tail;
    s32 count;

    do {
        head = r->head;
        tail = r->tail;
    } while (0);
    count = r->count;
    r->v[head] = val;
    head++;
    count++;
    if (count >= 0x18) {
        count = 0x18;
    }
    if (head >= 0x18) {
        head = 0;
    }
    if (head == tail) {
        count--;
        tail++;
        if (count < 0) {
            count = 0;
        }
        if (tail >= 0x18) {
            tail = 0;
        }
    }
    r->head = head;
    r->tail = tail;
    r->count = count;
}

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0B00);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1274);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B15DC);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1834);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1ADC);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1D20);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1F10);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B22E4);

INCLUDE_RODATA("../asm/us/magic_wpsi/nonmatchings/text", D_801B0000);

void func_801B24B0(arg0, arg1) {
    s32 i;
    s32 n;

    D_801D2BF4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    D_801D2BF8 = arg0;
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D2BFC = i;
            }
        }
    }
    D_801D2C00 = arg1;
    func_800BBEAC(&func_801B22E4);
}
