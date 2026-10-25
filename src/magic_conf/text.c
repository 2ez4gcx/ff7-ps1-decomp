#include "common.h"
#include "magic_conf/decls.h"

s32 func_801B0080(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B015C(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02D8(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03B4(MgSVec *p, MgSVec *q, MgVec *n) {
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

M2C_UNK *func_801B0498(s32 a, s32 b) {
    func_801B2618(a, b, 0);
    return &D_801BBB4C;
}

M2C_UNK *func_801B04C0(s32 a, s32 b) {
    func_801B2618(a, b, 1);
    return &D_801BBB4C;
}

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B04E8);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B05D0);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B0800);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B0A40);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B0D24);

s32 func_801B0EB4(s32 x, s32 v, s32 a, s32 lim) {
    s32 i;

    x += v;
    v += a;
    for (i = 0; i < 99; i++) {
        x += v;
        v += a;
        a -= a >> 4;
        if (x >= lim && v > 0) {
            break;
        }
    }
    return i;
}

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B0F00);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B18D8);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B1AA8);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B1D64);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B1E7C);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B2170);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B2350);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B2618);
