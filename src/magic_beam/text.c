#include "common.h"
#include "magic_beam/decls.h"

void func_801B0054(void) {
    D_801DFA34 = 0;
    func_801B1564();
}

void func_801B007C(void) {
    D_801DFA34 = 1;
    func_801B1564();
}

s32 func_801B00A8(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B0184);

void func_801B0300(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03DC(MgSVec *p, MgSVec *q, MgVec *n) {
    MgVec up;
    s32 a;
    s32 b;
    s32 den;

    up.vx = 0;
    up.vy = -0x1000;
    up.vz = 0;
    a = p->vx * n->vx + p->vy * n->vy + p->vz * n->vz;
    b = q->vx * n->vx + q->vy * n->vy + q->vz * n->vz;
    den = (n->vx * up.vx + n->vy * up.vy + n->vz * up.vz) >> 12;
    return (b - a) / den;
}

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B04C0);

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B0634);

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B0774);

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B0C40);

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B0E1C);

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B147C);

INCLUDE_ASM("../asm/us/magic_beam/nonmatchings/text", func_801B1564);
