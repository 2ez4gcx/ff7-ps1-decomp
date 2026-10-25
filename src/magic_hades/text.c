#include "common.h"
#include "magic_hades/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801BA978();
    return &D_801DDE34;
}

s32 func_801B0068(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0144(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02C0(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B039C(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0480);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0708);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0B90);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0C24);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B1144);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B140C);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B14A0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B1940);

s32 func_801B19B4(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F7B76[-v];
    }
    return v;
}

s32 func_801B19F0(s32 a, s32 b) {
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

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B1AE8);

void func_801B2B1C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1AE8)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B2B80);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B2D04);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B2ED4);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B30D0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3218);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B32FC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3354);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3434);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3578);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B35F0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3664);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3768);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B38DC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3BD4);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B40FC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B45B4);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B4600);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B46B0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B4798);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B4CAC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B4DFC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B51F0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B5310);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B5790);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B5B00);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B5C1C);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B60A0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B62E0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B64FC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B69C4);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B6C34);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B6D74);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B7270);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B7594);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B79A4);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B7A70);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8014);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8084);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8150);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8314);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8404);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8888);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8D48);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B9378);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B9820);

void func_801B98BC(void) {
    MgObj20 *p;
    MgObj20 *q;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 2) {
            func_800BBEAC((void *)func_801B8D48);
            q = D_801F1240 + 0x12B;
            for (i = 0x12B; i >= 0; i--) {
                *(s16 *)((u8 *)q + 0x9F60) = 0;
                q--;
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B9960);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B9A04);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B9DD4);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801BA020);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801BA1EC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801BA298);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801BA354);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801BA404);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801BA75C);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801BA978);
