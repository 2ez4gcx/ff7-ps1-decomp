#include "common.h"
#include "magic_dethper/decls.h"

void func_801B0054(void) {
    func_801B1D58();
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

INCLUDE_ASM("../asm/us/magic_dethper/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_dethper/nonmatchings/text", func_801B0670);

INCLUDE_ASM("../asm/us/magic_dethper/nonmatchings/text", func_801B0854);

INCLUDE_ASM("../asm/us/magic_dethper/nonmatchings/text", func_801B08D0);

INCLUDE_ASM("../asm/us/magic_dethper/nonmatchings/text", func_801B0CD4);

INCLUDE_ASM("../asm/us/magic_dethper/nonmatchings/text", func_801B115C);

void func_801B11FC(void) {
    MgSVec rot;
    MgSVec ang;
    MgMat m;
    MgMat m2;
    MgVec sc;
    MgVec d;
    MgVec n;
    MgVec v;
    MgTask *p;
    s32 t;
    s32 c8;
    s32 c80;

    p = &D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    ang.vx = 0;
    ang.vy = 0;
    ang.vz = -p->unk10;
    d.vx = D_80158D00 - p->unk4;
    d.vy = 0;
    d.vz = D_80158D04 - p->unk8;
    func_8003A08C(&d, &n);
    func_801B0150(func_801B0074(&D_801B70AC, &n, &v), &m2, &v);
    func_8003A79C(&m2, &m, &m);
    func_8003B27C(&m2, &ang, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    sc.vx = sc.vy = sc.vz = p->unk14;
    func_8003B35C(&m, &sc);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    if (p->unk2 < 0x21) {
        ((MgScratch *)0x1F800000)->unk0 = &D_801B60C8;
        ((MgScratch *)0x1F800000)->unk4 = c8 = 8;
        ((MgScratch *)0x1F800000)->unk8 = 0;
        ((MgScratch *)0x1F800000)->unkA = c80 = 0x80;
        ((MgScratch *)0x1F800000)->unkC = 0x20;
        ((MgScratch *)0x1F800000)->unkE = 0;
        t = p->unk2;
        if (t < 8) {
            ((MgScratch *)0x1F800000)->unkA = c80 - (c8 - t) * 0x10;
        }
        D_801CF0E4 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801CF0E4);
    } else {
        ((DpScr2 *)0x1F800000)->unk0 = &D_801B60C8;
        ((DpScr2 *)0x1F800000)->unk8 = 0xC;
        ((DpScr2 *)0x1F800000)->unk4 = D_801517C0 + 0x70;
        ((DpScr2 *)0x1F800000)->unkC = D_801CF0E4;
        ((DpScr2 *)0x1F800000)->unk2C = p->unk1C;
        D_801CF0E4 = func_801B115C((void *)0x1F800000, p->unk2 - 0x21);
    }
    if (p->unk2 >= 0x35) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x2C) {
            func_800D5774(p->unk1A);
        }
        if (p->unk2 == 0x1F) {
            func_800D5138(1);
        }
        if (p->unk2 == 0x20) {
            func_800D51D4(4);
        }
        p->unkC += p->unkE;
        p->unk2++;
    }
}

void func_801B151C(void) {
    u8 pad1[8];
    MgSVec rot;
    MgMat m;
    u8 pad2[16];
    MgVec d;
    MgVec n;
    MgVec v;
    MgTask *p;
    MgScratch *s;
    MgSVec *rp;
    s32 t;
    s32 k;

    rot.vx = 0;
    rot.vy = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = -p->unk10;
    d.vx = D_80158D00 - p->unk4;
    d.vy = 0;
    d.vz = D_80158D04 - p->unk8;
    func_8003A08C(&d, &n);
    func_801B0150(func_801B0074(&D_801B70BC, &n, &v), &m, &v);
    rp = &rot;
    func_8003B2CC(&m, rp, rp);
    rot.vx += p->unk4;
    rot.vy += p->unk6;
    rot.vz += p->unk8;
    func_800D4368(rp, p->unk14, 0);
    s = (MgScratch *)0x1F800000;
    s->unk0 = &D_801B62CC;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 8) {
        k = 8;
        k -= t;
        goto store;
    }
    if (t >= 0x2B) {
        k = t - 0x2B;
store:
        ((MgScratch *)0x1F800000)->unkA = k << 9;
    }
    if (s->unkA > 0x1000) {
        s->unkA = 0x1000;
    }
    func_8003B69C(0, 0, 0);
    D_801CF0E4 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801CF0E4);
    if (p->unk2 >= 0x33) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_dethper/nonmatchings/text", func_801B173C);

void func_801B1A00(void) {
    MgTask *p;
    MgTask *q;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == D_801B70DC[p->unk1A]) {
            if (p->unk1A < 4) {
                q = &D_80162978[func_800BBEAC(&func_801B173C)];
                *(DpB8 *)&q->unk4 = *(DpB8 *)&p->unk4;
                q->unkC = p->unk1A << 10;
                q->unkE = 0x80;
                q->unk10 = p->unk10;
                q->unk12 = (p->unk12 >> 1) + (p->unk12 >> 2);
                q->unk14 = p->unk14;
                q->unk16 = p->unk12 >> 3;
                q->unk18 = 0x32 - D_801B70DC[p->unk1A];
                q->unk1A = p->unk1A;
                p->unk1A++;
            }
        }
        if (p->unk1A >= 4) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1B80(s32 arg0) {
    MgTask *p;
    MgTask *q;
    s32 k;

    p = &D_80162978[func_800BBEAC(&func_801B11FC)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    k = *(s16 *)D_801518F6[arg0] + 0xE0;
    if (k >= 0x4F3) {
        k = 0x4F2;
    }
    p->unk10 = k;
    p->unkE = 0x30;
    p->unkC = 0;
    p->unk14 = 0x400;
    p->unk1A = arg0;
    p->unk1C = D_801CF0EC;
    D_801CF0EC++;
    q = (MgTask *)((func_800BBEAC(&func_801B151C) << 5) + (s32)D_80162978);
    *(DpB8 *)&q->unk4 = *(DpB8 *)&p->unk4;
    q->unk10 = p->unk10;
    q->unk14 = 0xBDA;
    q = (MgTask *)((func_800BBEAC(&func_801B1A00) << 5) + (s32)D_80162978);
    *(DpB8 *)&q->unk4 = *(DpB8 *)&p->unk4;
    q->unk10 = p->unk10;
    q->unk12 = 0x1F4;
    q->unk14 = 0x435;
    q->unk1A = 0;
    ((DpScratch *)0x1F800000)->unk0 = &D_801B60C8;
    ((DpScratch *)0x1F800000)->unk2C = p->unk1C;
    func_801B0854((void *)0x1F800000);
    func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x86);
}

INCLUDE_RODATA("../asm/us/magic_dethper/nonmatchings/text", D_801B0000);

s32 func_801B1D58(arg0, arg1) {
    s32 ret;

    D_801CF0E8 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1DE4, 0, 0, 0);
    ret = func_800D5444(arg0, arg1, 6, &func_801B1B80);
    D_801CF0EC = 0;
    return ret;
}
