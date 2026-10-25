#include "common.h"
#include "magic_death/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B31B4();
    return &D_801B9658;
}

s32 func_801B007C(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0158(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02D4(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03B0(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0494);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B05A4);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B07A8);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0858);

void func_801B0978(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0 + 4;
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32 *, 8) = func_8003BBDC(arg1, arg0 + 0x30, temp_s2, temp_s1);
    func_8003BBDC(arg2, arg0 + 0x34, temp_s2, temp_s1);
}

void func_801B09EC(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801D6658;
    r->otz = func_8003BBDC(v0, &p->x0, &r->sxy, &r->flag);
    func_8003BBDC(v1, &p->x1, &r->sxy, &r->flag);
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->tag.len = 4;
    p->code = 0x52;
    p->tag.addr = ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr;
    ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr = (u32)p;
    p++;
    D_801D6658 = p;
}

void func_801B0B1C(MgTask *arg0, MgSVec *arg1, MgSVec *arg2) {
    MgSVec v;
    MgMat m1;
    MgMat m2;
    s16 *q;

    q = &D_800FA650;
    v.vx = arg0->unk14 - *q;
    v.vy = arg0->unk18 - D_800FA654;
    v.vz = arg0->unk1C - D_800FA658;
    func_8003BF3C((MgSVec *)(q - 10), &m1);
    func_8003B2CC(&m1, &v, &v);
    func_8003A79C(&m1, arg0, &m2);
    func_8003B2CC(&m2, arg1, arg2);
    arg2->vx += v.vx;
    arg2->vy += v.vy;
    arg2->vz += v.vz;
}

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0C20);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0EFC);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B1AF4);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B1D20);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B1F14);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2228);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2478);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B278C);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2E14);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B31B4);
