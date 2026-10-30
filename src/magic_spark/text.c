#include "common.h"
#include "magic_spark/decls.h"

s32 func_801B0054(void) {
    func_801B2200();
    return 0;
}

s32 func_801B0078(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0154(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02D0(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03AC(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B0490(void) {
    MgTask *p;
    s32 lo;

    p = &D_80162978[D_8015169C];
    lo = p->unk18 * D_801CB970[p->unk1C];
    func_800D4368(&p->unk4, lo * 0x10 >> 16, -(lo >> 16));
    ((MgScratch *)0x1F800000)->unk0 = &D_801CB384;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801E39B4 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E39B4);
    if (p->unk2 >= 4) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk1C++;
        p->unk2++;
    }
}

void func_801B05AC(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, -(p->unk18 >> 2));
    ((MgScratch *)0x1F800000)->unk0 = &D_801CADC8;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 4) {
        ((MgScratch *)0x1F800000)->unkA = (t - 4) << 10;
    }
    func_8003B69C(0, 0, 0);
    D_801E39B4 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E39B4);
    if (p->unk2 >= 8) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk18 += p->unk1A;
        p->unk2++;
        p->unk1A -= p->unk1A / 3;
    }
}

void func_801B0700(void) {
    MgSVec pos;
    MgVec v;
    MgMat m;
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    u8 *ot;
    s32 n;
    s32 k;

    p = &D_80162978[D_8015169C];
    *(SpB8 *)&pos = *(SpB8 *)&p->unk4;
    k = p->unk18;
    pos.vx += k * p->unkC >> 12;
    pos.vy += k * p->unkE >> 12;
    pos.vz += k * p->unk10 >> 12;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    pkt = (u8 *)D_801E39B4;
    n = func_8003BD1C(&D_801E39C4, &pos, &p->unk4, pkt + 8, pkt + 0x10, pkt + 0x18, &otz, &flag);
    if (n > 0) {
        *(s32 *)(pkt + 4) = 0xA0A0A0;
        *(s32 *)(pkt + 0xC) = 0x40404;
        *(s32 *)(pkt + 0x14) = 0x40404;
        pkt[3] = 6;
        pkt[7] = 0x32;
        ot = (u8 *)((n >> 2) * 4 + D_801517C0);
        *(u32 *)pkt = (*(u32 *)pkt & 0xFF000000) | (*(u32 *)(ot + 0x70) & 0xFFFFFF);
        *(u32 *)(ot + 0x70) = (*(u32 *)(ot + 0x70) & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
        pkt += 0x1C;
    }
    D_801E39B4 = (s32)pkt;
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < p->unk1C >> 1) {
            p->unk18 += p->unk1A;
        } else {
            p->unk18 -= p->unk1A;
        }
        v.vx = p->unk4 - D_801E39C4.vx;
        v.vy = p->unk6 - D_801E39C4.vy;
        v.vz = p->unk8 - D_801E39C4.vz;
        func_8003A08C(&v, &v);
        k = p->unkA;
        p->unk4 += k * p->unkC >> 12;
        p->unk6 += k * p->unkE >> 12;
        p->unk8 += k * p->unk10 >> 12;
        func_801B0154(func_80042DA8() % 50 + 0x18, &m, &v);
        func_8003B2CC(&m, (MgSVec *)&p->unkC, (MgSVec *)&p->unkC);
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_spark/nonmatchings/text", func_801B0A38);

void func_801B0E70(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;
    u8 c;

    p = &D_80162978[D_8015169C];
    D_801CB9A4[0] = p->unk2;
    c = ((u8 *)p)[0x1A];
    rot.vx = 0;
    D_801CB9A0[0] = D_801CB9A0[1] = D_801CB9A0[2] = c;
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    sc.vx = sc.vy = sc.vz = p->unk18;
    func_8003B35C(&m, &sc);
    func_800D4284(&p->unk4, -(p->unk18 >> 1), &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    D_801E39B4 = func_800D4D90((u8 *)D_801CB9A4 - 8, D_801517C0 + 0x70, 0xC, D_801E39B4);
    if (p->unk2 >= 3) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0FAC(void) {
    MgTask *p;
    u8 c;

    p = &D_80162978[D_8015169C];
    D_801CB9B0[0] = p->unk2;
    c = ((u8 *)p)[0x1A];
    D_801CB9AC[0] = D_801CB9AC[1] = D_801CB9AC[2] = c;
    func_800D4368(&p->unk4, p->unk18, -(p->unk18 >> 2));
    D_801E39B4 = func_800D4D90((u8 *)D_801CB9B0 - 8, D_801517C0 + 0x70, 0xC, D_801E39B4);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1098(arg0, arg1) {
    MgTask *q;
    s32 r;
    u16 raw;
    u8 pad[16];
    s32 d1;
    s32 d2;
    s32 w;
    s32 i;

    func_800D3994(D_801E39C0, D_8015190F[D_801E39C0][0], &D_801E39C4);
    raw = D_801518F6[D_801E39C0][0];
    D_801E39CA = raw;
    r = (s16)raw;
    d1 = (r << 12) / 430;
    d2 = (r << 12) / 350;
    w = r * 2;
    i = 0;
    if (arg1 > 0) {
        do {
            q = &D_80162978[func_800BBEAC(func_801B0E70)];
            *(SpB8 *)&q->unk4 = *(SpB8 *)&D_801E39C4;
            q->unk4 += func_80042DA8() % w - r;
            q->unk6 += func_80042DA8() % w - r;
            q->unk8 += func_80042DA8() % w - r;
            q->unkC = func_80042DA8() % 2 << 11;
            q->unk18 = d1 * (func_80042DA8() % 0xE00 + 0x500) >> 12;
            q->unk1A = func_80042DA8() % 64 + 0x50;
            i++;
        } while (i < arg1);
    }
    r += 0x90;
    w = r * 2;
    i = 0;
    if (arg1 >> 1 > 0) {
        do {
            i++;
            q = &D_80162978[func_800BBEAC(func_801B0FAC)];
            *(SpB8 *)&q->unk4 = *(SpB8 *)&D_801E39C4;
            q->unk4 += func_80042DA8() % w - r;
            q->unk6 += func_80042DA8() % w - r;
            q->unk8 += func_80042DA8() % w - r;
            q->unk18 = d2 * (func_80042DA8() % 0xC00 + 0x500) >> 12;
            q->unk1A = func_80042DA8() % 80 + 0x40;
        } while (i < arg1 >> 1);
    }
}

INCLUDE_ASM("../asm/us/magic_spark/nonmatchings/text", func_801B1508);

INCLUDE_ASM("../asm/us/magic_spark/nonmatchings/text", func_801B2014);

INCLUDE_RODATA("../asm/us/magic_spark/nonmatchings/text", D_801B0000);

void func_801B2200(arg0, arg1) {
    D_801E39B8 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B228C, 0, 0, 0);
    func_800BBEAC(&func_801B2014);
    D_801E39BC = arg0;
    D_801E39C0 = arg1;
}
