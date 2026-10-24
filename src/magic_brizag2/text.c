#include "common.h"
#include "magic_brizag2/decls.h"

void func_801B0054(void) {
    func_801B58B4();
}

s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0150(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B06F8);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B09C4);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B0C04);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B0EB4);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B0F78);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B123C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B1524);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B17E8);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B1AD0);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B1B68);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B200C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B2548);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B29DC);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B2F08);

void func_801B2FCC(MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;
    MgTag *ot;
    s32 otz;
    s32 sxy;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801EA264;
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
    D_801EA264 = p;
}

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B30D0);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3294);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3474);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3640);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3844);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3A1C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3BFC);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3D94);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B3F24);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B4124);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B438C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B46E0);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B498C);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B5258);

INCLUDE_ASM("../asm/us/magic_brizag2/nonmatchings/text", func_801B57EC);

INCLUDE_RODATA("../asm/us/magic_brizag2/nonmatchings/text", D_801B0000);

void func_801B58B4(arg0) {
    D_801EA268 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B5938, 0, 0, 0);
    func_800BBEAC(&func_801B57EC);
    D_801EA26C = arg0;
    D_801EA278 = 0;
}
