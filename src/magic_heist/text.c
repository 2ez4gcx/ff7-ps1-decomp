#include "common.h"
#include "magic_heist/decls.h"

void func_801B0054(void) {
    func_801B1170();
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

void func_801B048C(void) {
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgMat m0;
    MgMat m1;
    MgMat m2;
    MgVec sc;
    MgVec d0;
    MgVec d1;
    MgVec d2;
    MgTask *p;
    s32 n;
    s32 k;
    s32 m;

    p = &D_80162978[D_8015169C];
    a.vx = p->unk14;
    a.vy = p->unkC - 0x400 + p->unk10;
    a.vz = 0;
    func_8003BF8C(&a, &m0);
    a.vz = p->unk12;
    func_8003BF8C(&a, &m2);
    b.vx = 0;
    b.vy = p->unkE + p->unk10;
    b.vz = 0;
    func_8003BF8C(&b, &m1);
    c.vx = p->unk16;
    c.vy = 0;
    c.vz = 0;
    func_8003B27C(&m1, &c, (MgVec *)m0.t);
    m = p->unk2 * 3;
    k = m;
    if (k >= 0x3D) {
        k = 0x3C;
    }
    c.vx += k;
    func_8003B27C(&m1, &c, (MgVec *)m2.t);
    m0.t[0] = p->unk4 + m0.t[0];
    m0.t[1] += p->unk6;
    m0.t[2] = p->unk8 + m0.t[2];
    m2.t[0] += p->unk4;
    m2.t[1] += p->unk6;
    m2.t[2] += p->unk8;
    if (p->unk1C == 0) {
        if (p->unk2 >= 0x14) {
            d0.vx = p->unk4 - m0.t[0];
            d0.vy = 0;
            d0.vz = p->unk8 - m0.t[2];
            d1.vx = D_801031E8.vx - D_80158D00.vx;
            d1.vy = 0;
            d1.vz = D_801031E8.vz - D_80158D00.vz;
            func_8003A08C(&d0, &d0);
            func_8003A08C(&d1, &d1);
            m = func_801B0074(&d1, &d0, &d2);
            if (m < 0x81) {
                p->unk1C = 4;
            }
            if ((u32)(m - 0x780) < 0x101) {
                p->unk1C = 2;
            }
            if ((u32)(m - 0x380) < 0x101) {
                if (d2.vy > 0) {
                    p->unk1C = 3;
                } else {
                    p->unk1C = 1;
                }
            }
        }
    }
    if (p->unk1C != 0) {
        switch (p->unk1C) {
        case 2:
            n = 0x10;
            b.vx = 0x40;
            b.vy = -0x50;
            b.vz = 0;
            break;
        case 3:
            n = 0xC;
            b.vx = 0x20;
            b.vy = 0x40;
            b.vz = 0;
            break;
        case 4:
            n = 0xA;
            b.vx = -0x40;
            b.vy = -0x60;
            b.vz = 0;
            break;
        case 1:
            n = 0x15;
            b.vx = -0x50;
            b.vy = 0x60;
            b.vz = 0;
            break;
        }

        func_8003BF8C(&b, &m1);
        c.vx = D_80158D00.vx - D_801031E8.vx;
        c.vy = D_80158D00.vy - D_801031E8.vy;
        c.vz = D_80158D00.vz - D_801031E8.vz;
        func_8003B2CC(&D_800FA63C, &c, &c);
        func_8003B2CC(&m1, &c, &c);
        func_8003BF3C(&D_800FA63C, &m1);
        func_8003B2CC(&m1, &c, &c);
        c.vx += D_801031E8.vx;
        c.vy += D_801031E8.vy;
        c.vz += D_801031E8.vz;
        m = p->unk2 - 0x14;
        m0.t[0] += ((c.vx - m0.t[0]) / n) * m;
        m0.t[1] += ((c.vy - m0.t[1]) / n) * m;
        m0.t[2] += ((c.vz - m0.t[2]) / n) * m;
        m2.t[0] += ((c.vx - m2.t[0]) / n) * m;
        m2.t[1] += ((c.vy - m2.t[1]) / n) * m;
        m2.t[2] += ((c.vz - m2.t[2]) / n) * m;
    }
    sc.vx = sc.vy = sc.vz = p->unk18;
    func_8003A63C(&D_800FA63C, &m0, &m1);
    func_8003B35C(&m1, &sc);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    ((MgWord *)0x1F800000)->v = (s32) D_801B92D4;
    *((s32 *)0x1F800004) = 0x80;
    *((s16 *)0x1F800008) = 0;
    *((s16 *)0x1F80000A) = 0;
    *((s16 *)0x1F80000C) = 0;
    *((s16 *)0x1F80000E) = 0;
    D_801D2FA8 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D2FA8);
    func_8003A63C(&D_800FA63C, &m2, &m1);
    m1.t[2] -= p->unk2 * 2;
    func_8003B35C(&m1, &sc);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    *((u8 **)0x1F800000) = D_801B9288;
    D_801D2FA8 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D2FA8);
    if (p->unk2 >= 0x29) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC -= 0x100;
        p->unk12 += 0x180;
        if (p->unk1C != 0) {
            p->unkC += 0x180;
            p->unk14 += 0x40;
        }
        if (p->unk1C == 0) {
            p->unkE -= 0x100;
        }
        if (p->unk2 < 0x14) {
            p->unk18 += p->unk1A;
        }
        if ((p->unk2 < 0x14) || (p->unk1C != 0)) {
            p->unk2++;
        }
    }
}

void func_801B0C5C(MgB8 *src) {
    s32 i;

    for (i = 0; i < 0x82; i++) {
        D_801B92D8[i] = src[i];
    }
}

void func_801B0CA8(MgSVec *a, MgSVec *b, MgSVec *d) {
    s32 i;

    for (i = 0; i < 0x82; i++) {
        d[i].vx = b[i].vx - a[i].vx;
        d[i].vy = b[i].vy - a[i].vy;
        d[i].vz = b[i].vz - a[i].vz;
    }
}

void func_801B0D00(void) {
    MgTask *p;
    s32 i;

    if (D_80062D98 == 0) {
        p = (MgTask *)&D_80162978[D_8015169C];
        if (p->unk2 < 7) {
            if (p->unk2 == 1) {
                p->unk18 = 0;
                p->unk1A = 0x2AA;
                func_801B0CA8(D_801BA378, D_801BA788, D_801D2FB4);
            }
            func_801B0C5C((MgB8 *)D_801BA378);
        } else {
            if (p->unk2 == 7) {
                p->unk18 = 0;
                p->unk1A = 0x333;
                func_801B0CA8(D_801BA788, D_801BAB98, D_801D2FB4);
            }
            func_801B0C5C((MgB8 *)D_801BA788);
        }
        func_8003A28C((MgSVec *)D_801B92D8, D_801D2FB4, 0x82, p->unk18);
        if (p->unk2 == 0x14) {
            for (i = 0; i < 10; i++) {
                if ((1 << i) & D_801D2FB0) {
                    func_800D5774(i);
                }
            }
            p->unk0 = -1;
        }
        p->unk18 += p->unk1A;
        if (p->unk18 > 0x1000) {
            p->unk18 = 0x1000;
        }
        p->unk2++;
    }
}

void func_801B0E88(void) {
    MgObjH *p;
    MgObjH *q;
    s32 i;
    s32 n;
    s32 first;
    u8 *base;

    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if ((1 << i) & D_801D2FB0) {
            n++;
            if (n == 1) {
                first = i;
            }
        }
    }
    D_80162978[D_8015169C].unk0 = -1;
    func_800BBEAC(&func_801B0D00);
    base = (u8 *)D_80162978;
    p = (MgObjH *)(base + (func_800BBEAC(&func_801B048C) << 5));
    if (n == 1) {
        func_800D3994(first, D_8015190F[first][0], &p->unk4);
        p->unk16 = D_801518F6[first][0] + 0xE0;
        if (p->unk16 > 0x76C) {
            p->unk16 = 0x76C;
        }
    } else {
        func_800D54EC(D_801D2FB0, &p->unk4);
        p->unk4.vy = -0x380;
        p->unk16 = 0x540;
    }
    p->unkC = p->unkE = p->unk12 = p->unk14 = 0;
    p->unk10 = 0;
    p->unk18 = 0x400;
    p->unk1A = 0x100;
    p->unk1C = 0;
    q = (MgObjH *)&D_80162978[func_800BBEAC(&func_801B048C)];
    q->unk4 = p->unk4;
    q->unkC = q->unkE = q->unk12 = q->unk14 = 0;
    q->unk10 = 0x400;
    q->unk16 = p->unk16;
    q->unk18 = p->unk18;
    q->unk1A = p->unk1A;
    q->unk1C = 0;
    q = (MgObjH *)&D_80162978[func_800BBEAC(&func_801B048C)];
    q->unk4 = p->unk4;
    q->unkC = q->unkE = q->unk12 = q->unk14 = 0;
    q->unk10 = 0x800;
    q->unk16 = p->unk16;
    q->unk18 = p->unk18;
    q->unk1A = p->unk1A;
    q->unk1C = 0;
    q = (MgObjH *)&D_80162978[func_800BBEAC(&func_801B048C)];
    q->unk4 = p->unk4;
    q->unkC = q->unkE = q->unk12 = q->unk14 = 0;
    q->unk10 = 0xC00;
    q->unk16 = p->unk16;
    q->unk18 = p->unk18;
    q->unk1A = p->unk1A;
    q->unk1C = 0;
    func_801B0C5C((MgB8 *)D_801BA378);
}

INCLUDE_RODATA("../asm/us/magic_heist/nonmatchings/text", D_801B0000);

s32 func_801B1170(arg0) {
    D_801D2FAC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1208, 0, 0, 0);
    func_800BBEAC(&func_801B0E88);
    D_801D2FB0 = arg0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x53);
}
