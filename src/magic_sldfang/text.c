#include "common.h"
#include "magic_sldfang/decls.h"

M2C_UNK *func_801B0054(s32 a, s32 b) {
    func_801B3028(a, b, 0);
    return &D_801B94D4;
}

M2C_UNK *func_801B007C(s32 a, s32 b) {
    func_801B3028(a, b, 1);
    return &D_801B94D4;
}

s32 func_801B00A4(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0180(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02FC(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03D8(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B04BC);

void func_801B05DC(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0 + 4;
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32 *, 8) = func_8003BBDC(arg1, arg0 + 0x40, temp_s2, temp_s1);
    func_8003BBDC(arg2, arg0 + 0x44, temp_s2, temp_s1);
}

void func_801B0650(MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;
    MgTag *ot;
    s32 otz;
    s32 sxy;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801D4DC4;
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
    D_801D4DC4 = p;
}

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B0754);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B07B4);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B0828);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B0F9C);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B1720);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B18FC);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B1B60);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B1E04);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B21B8);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B27B8);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B29F8);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B2D80);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B2ED4);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B3028);
