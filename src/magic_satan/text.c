#include "common.h"
#include "magic_satan/decls.h"

s32 func_801B00E0(void) {
    func_801B664C();
    return 0;
}

s32 func_801B0104(void) {
    func_801B672C();
    return 0;
}

s32 func_801B0128(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0204(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0380(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B045C(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0540);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0818);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0B5C);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0BF8);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0EA8);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B1178);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B11F8);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B1790);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B1DC0);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B1E60);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B2048);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B226C);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B2328);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B23E0);

s32 func_801B2898(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E7E16[-v];
    }
    return v;
}

s32 func_801B28D4(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B29CC);

void func_801B3A14(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_801621F0[func_800BC04C(&func_801B29CC)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B3A78);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B3AD4);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4350);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B43B0);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4424);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4454);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B46C0);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4B98);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4F68);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B5388);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B5760);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B57AC);

void func_801B5804(void) {
    *(M2C_UNK **)0x1F800000 = &D_801BF980;
    *(s32 *)0x1F800004 = 0x80;
    *(s16 *)0x1F800008 = 0;
    *(s16 *)0x1F80000A = 0;
    *(s16 *)0x1F80000C = 0x20;
    *(s16 *)0x1F80000E = 0;
    D_801E07AC = func_800D29D4(0x1F800000, D_801517C0 + 0x70, 0xC, D_801E07AC);
}

void func_801B5884(void *arg0) {
    M2C_SFIELD(arg0, M2C_UNK **, 0) = &D_801BF980;
    M2C_SFIELD(arg0, s32 *, 8) = 0xC;
    M2C_SFIELD(arg0, s32 *, 0x10) = 0;
    M2C_SFIELD(arg0, s32 *, 4) = (s32) (D_801517C0 + 0x70);
    M2C_SFIELD(arg0, s32 *, 0xC) = (s32) D_801E07AC;
    D_801E07AC = func_801B0B5C();
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B58DC);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B5ACC);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B6060);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B639C);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B65BC);

void func_801B65FC(void) {
    M2C_UNK *var_v1;

    var_v1 = &D_801D47AC;
    if (D_800F8368 == 0) {
        var_v1 = &D_801C87AC;
    }
    D_801E07AC = var_v1;
    if (D_801E1A10 < 0) {
        *D_801E07B0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B664C);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B672C);

INCLUDE_RODATA("../asm/us/magic_satan/nonmatchings/text", D_801B008C);
