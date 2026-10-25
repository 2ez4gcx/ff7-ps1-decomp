#include "common.h"
#include "magic_wpke/decls.h"

void func_801B0054(void) {
    D_801CCA40 = &D_801B0EB8;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B008C(void) {
    D_801CCA40 = &D_801B105C;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B00C4(void) {
    D_801CCA40 = &D_801B1200;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B00FC(void) {
    D_801CCA40 = &D_801B13A4;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B0134(void) {
    D_801CCA40 = &D_801B1548;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B016C(void) {
    D_801CCA40 = &D_801B16EC;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B01A4(void) {
    D_801CCA40 = &D_801B1890;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B01DC(void) {
    D_801CCA40 = &D_801B1A34;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B0214(void) {
    D_801CCA40 = &D_801B1BD8;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B024C(void) {
    D_801CCA40 = &D_801B259C;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B0284(void) {
    D_801CCA40 = &D_801B2740;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B02BC(void) {
    D_801CCA40 = &D_801B3184;
    D_801CCA44 = 0;
    func_801B0E04();
}

void func_801B02F4(void) {
    D_801CCA40 = &D_801B3D08;
    D_801CCA44 = 0;
    func_801B0E04();
}

s32 func_801B032C(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0408(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0584(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B0660(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B0744(void) {
    MgSVec rot;
    MgMat m;
    MgMat pad;
    MgVec v;
    s32 t2;
    MgTask *p2;
    MgVec n;
    MgTask *p;
    s32 k;
    s32 t;

    p = &D_80162978[D_8015169C];
    k = func_801B032C(&D_801CCA20, &D_801CCA30, &n) / 190 + 1;
    t2 = (-(func_80039A74(p->unkA) * 0x2BC) >> 12) * k;
    t = t2;
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = p->unk18;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6 + t;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    v.vx = 0;
    v.vy = 0;
    v.vz = 0;
    func_8003AB84(&m, &v, &v);
    m.t[0] += v.vx;
    m.t[1] += v.vy;
    m.t[2] += v.vz;
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801CCA40;
    if (p->unk2 >= 0x1A) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        t = p->unk2;
        ((MgScratch *)0x1F800000)->unkA = (t - 0x1A) << 10;
    }
    p2 = p;
    func_8003B69C(0, 0, 0);
    D_801CC9FC = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801CC9FC);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p2->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        if (p->unk2 == 0x14) {
            p->unkA = 0;
        }
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

void func_801B09FC(void) {
    MgTask *base;
    MgTask *p;
    MgTask *q;
    s32 k;
    MgVec pad;

    base = D_80162978;
    p = base + D_8015169C;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801CCA30.vx = D_801CCA10.vx - D_801CCA18.vx;
            D_801CCA30.vy = D_801CCA10.vy - D_801CCA18.vy;
            D_801CCA30.vz = D_801CCA10.vz - D_801CCA18.vz;
            k = func_80039F5C(func_8003A08C(&D_801CCA30, &D_801CCA30)) / 20;
            q = base + func_800BBEAC(func_801B0744);
            *(MgSVec *)&q->unk4 = D_801CCA18;
            q->unkC = (k * D_801CCA30.vx) >> 12;
            q->unkE = (k * D_801CCA30.vy) >> 12;
            q->unk10 = (k * D_801CCA30.vz) >> 12;
            q->unkA = q->unk12 = 0x66;
            q->unk14 = q->unk16 = func_80042DA8() % 200 + 0xB4;
            q->unk18 = q->unk1A = func_80042DA8() % 150 + 0xA0;
        }
        if (p->unk2 == 0x15) {
            func_800D5774(D_801CCA08);
            func_800D55F4(0x20, func_800D56A8(&D_801CCA10), 0xE1);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0C88(void) {
    MgSVec rot;
    MgMat m;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    p->unk0 = -1;
    func_800D3994(D_801CCA08, D_8015190F[D_801CCA08][0], &D_801CCA10);
    func_800D3994(D_801CCA0C, D_8015190F[D_801CCA0C][0], &D_801CCA18);
    rot.vy = D_801CCA1E = D_80151A46[D_801CCA0C][0];
    rot.vx = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801B49EC, &D_801CCA20);
    if (D_801CCA44 == 0) {
        p = &D_80162978[func_800BBEAC(&func_801B09FC)];
    }
    p->unk1C = 0;
}

INCLUDE_RODATA("../asm/us/magic_wpke/nonmatchings/text", D_801B0000);

void func_801B0E04(arg0, arg1) {
    s32 i;
    s32 n;

    D_801CCA00 = &D_80162978[func_800BBEAC(&D_801B0000)];
    D_801CCA04 = arg0;
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801CCA08 = i;
            }
        }
    }
    D_801CCA0C = arg1;
    func_800BBEAC(&func_801B0C88);
}
