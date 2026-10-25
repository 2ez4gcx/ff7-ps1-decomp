#include "common.h"
#include "magic_wep3/decls.h"

void func_801B0054(void) {
    func_801B226C();
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
    s32 den;

    up.vx = 0;
    up.vy = -0x1000;
    up.vz = 0;
    a = p->vx * n->vx + p->vy * n->vy + p->vz * n->vz;
    b = q->vx * n->vx + q->vy * n->vy + q->vz * n->vz;
    den = (n->vx * up.vx + n->vy * up.vy + n->vz * up.vz) >> 12;
    return (b - a) / den;
}

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0510);

void func_801B067C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (p->unk1C > 0) {
        if (D_80062D98 == 0) {
            p->unk1C--;
        }
        return;
    }
    D_801D3688[0] = p->unk2;
    func_800D4368(&p->unk4, p->unk14, -(p->unk14 >> 3));
    D_801EB6B0 = func_800D4D90(&D_801D3688[-4], D_801517C0 + 0x70, 0xC, D_801EB6B0);
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0774);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B096C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0B4C);

void func_801B0D34(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s16 k;
    s16 w;

    p = &D_80162978[D_8015169C];
    if (p->unk1C > 0) {
        if (D_80062D98 == 0) {
            p->unk1C--;
        }
        return;
    }
    rot.vx = p->unkC;
    rot.vy = 0;
    rot.vz = p->unk10;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    k = p->unk14;
    scale.vx = scale.vy = scale.vz = k;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D2FFC;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x24) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0x24) * 0x10;
    }
    D_801EB6B0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801EB6B0);
    if (p->unk2 >= 0x2C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        w = p->unkE - 1;
        p->unkE = w;
        if (w <= 0) {
            p->unkE = 1;
        }
        w = p->unk12 - 1;
        p->unk12 = w;
        if (w <= 0) {
            p->unk12 = 1;
        }
        if (p->unk2 < p->unk1E) {
            p->unk14 += p->unk16;
        }
        p->unk2++;
    }
}

void func_801B0F78(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s16 v;
    MgByte *q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 10) {
        c = -0x80 - (t - 10) * 21;
    } else {
        c = 0x80;
    }
    q = &D_801D36A8;
    q->v = D_801D36A9.v = D_801D36AA.v = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801EB6B0 = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801EB6B0);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC -= p->unkC >> 3;
        p->unkE += p->unkE >> 3;
        p->unk10 -= p->unk10 >> 3;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B10EC);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B1514);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B16EC);

void func_801B21F8(void) {
    u8 pad[8];
    D_80162978[D_8015169C].unk0 = -1;
    D_80162994[func_800BBEAC(func_801B16EC)].unk0 = 0;
    func_800D54EC(D_801EB6B8, D_801EB6C0);
}

INCLUDE_RODATA("../asm/us/magic_wep3/nonmatchings/text", D_801B0000);

void func_801B226C(arg0, arg1) {
    D_801EB6B4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B22F8, 0, 0, 0);
    func_800BBEAC(&func_801B21F8);
    D_801EB6B8 = arg0;
    D_801EB6BC = arg1;
}
