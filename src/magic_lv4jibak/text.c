#include "common.h"
#include "magic_lv4jibak/decls.h"

void func_801B0070(void) {
    func_801B1858();
}

s32 func_801B0090(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B016C(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02E8(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03C4(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B04A8(void) {
    MgTask *p;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801B7D28;
    *frame = p->unk2;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -(t >> 3));
    D_801CFD2C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801CFD2C);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0574(void) {
    MgTask *p;
    MgTask *q;
    MgRec57C *r;
    void *sc;
    s32 col;
    s32 n;
    s32 m;
    s32 i;
    s32 a;
    s32 t;

    p = &D_80162978[D_8015169C];
    r = &D_801CFD40[p->unk10];
    sc = (void *)0x1F800000;
    switch (p->unk14) {
    case 0:
        r->unk8 = 0;
        col = p->unk2 * 0x60606;
        if (p->unk2 >= 7) {
            p->unk14 = 1;
        }
        break;
    case 1:
        col = 0x303030;
        r->unk8 = 0;
        if (p->unk2 >= 0xB) {
            p->unk14 = 2;
        }
        break;
    case 2:
        col = 0x303030;
        t = p->unk2 - 0xB;
        r->unk8 = t;
        if (r->unk4 != t) {
            goto draw;
        }
        p->unk14 = 3;
        p->unk12 = p->unk2 + 4;
        func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xFA);
        break;
    case 3:
        if (D_80062D98 == 0) {
            n = p->unkC;
            i = 0;
            m = n * 2;
            do {
                q = &D_80162978[func_800BBEAC(func_801B04A8)];
                *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
                q->unk4 += func_80042DA8() % m - n;
                q->unk6 += func_80042DA8() % m - n;
                q->unk8 += func_80042DA8() % m - n;
                a = func_80042DA8();
                t = a - a / 0x1000 * 0x1000 + 0x800;
                q->unkC = (p->unkE * t) >> 12;
                i++;
            } while (i < 2);
        }
        if (p->unk2 >= p->unk12) {
            p->unk14 = 4;
            p->unk12 += 5;
        }
        break;
    case 4:
        if (p->unk2 >= p->unk12) {
            p->unk14 = 5;
        }
        break;
    case 5:
        if (D_80062D98 == 0) {
            func_800D5774(p->unk16);
            p->unk14 = 6;
            p->unk12 += 8;
        }
        break;
    case 6:
        if (p->unk2 >= p->unk12) {
            p->unk0 = -1;
        }
        break;
    }
    if (r->unk4 != r->unk8) {
draw:
        func_801B0CF4(sc, r, col);
        if (p->unk14 == 2) {
            func_801B096C(sc, r);
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B096C(JbScratch *sc, MgRec57C *r) {
    s32 i;
    s32 k;
    s32 m;
    s32 t;
    JbPolyG3 *p;
    u8 *q;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    i = 0;
    p = (JbPolyG3 *)D_801CFD2C;
    k = r->unk8;
    do {
        t = func_80042DA8();
        sc->d0.vx = t % 0x1000 - 0x800;
        t = func_80042DA8();
        sc->d0.vy = -(t % 0x800);
        t = func_80042DA8();
        sc->d0.vz = t % 0x1000 - 0x800;
        sc->d1.vx = -sc->d0.vy - sc->d0.vz;
        sc->d1.vy = sc->d0.vx - sc->d0.vz;
        sc->d1.vz = sc->d0.vx + sc->d0.vy;
        func_8003A08C(&sc->d0, &sc->d0);
        func_8003A08C(&sc->d1, &sc->d1);
        i++;
        m = func_80042DA8() % 180 + 0x190;
        q = (u8 *)r + k * 0x1C;
        sc->p0 = *(MgSVec *)(q + 0x3C);
        sc->p0.vx += (m * sc->d0.vx) >> 12;
        sc->p0.vy += (m * sc->d0.vy) >> 12;
        sc->p0.vz += (m * sc->d0.vz) >> 12;
        sc->p1 = *(MgSVec *)(q + 0x3C);
        m >>= 3;
        sc->p1.vx += (m * sc->d1.vx) >> 12;
        sc->p1.vy += (m * sc->d1.vy) >> 12;
        sc->p1.vz += (m * sc->d1.vz) >> 12;
        sc->otz = func_8003BC0C(&sc->p0, &sc->p1, (u8 *)r + (k * 0x1C + 0x3C), &p->xy0, &p->xy1, &p->xy2, &sc->sxy, &sc->flag);
        p->c0 = 0x2030A;
        *(s32 *)((u8 *)p + 0xC) = sc->d0.vx & 0x1F1F3F;
        p->tag.len = 6;
        p->c2 = 0xE0E24;
        ((u8 *)p)[7] = 0x32;
        p->tag.addr = ((MgTag *)D_801517C0 + (sc->otz >> 2) + 0x1C)->addr;
        ((MgTag *)D_801517C0 + (sc->otz >> 2) + 0x1C)->addr = (u32)p;
        p++;
    } while (i < 0x28);
    D_801CFD2C = (MgLineG2 *)p;
}

void func_801B0CF4(void *sc, MgRec57C *r, s32 col) {
    s32 i;
    s32 j;
    u8 *e;

    func_801B0FE4(sc, (u8 *)r + (r->unk8 * 0x1C + 0x3C), 0x1A);
    for (i = r->unk8; i < r->unk4; i++) {
        for (j = 0; j < 4; j++) {
            ((s32 *)sc)[j + 0x14] = ((s32 *)sc)[j + 0x10];
        }
        e = &r->pad0[i * 0x1C + 0x58];
        ((s32 *)sc)[0x18] = ((s32 *)sc)[2];
        func_801B0FE4(sc, e, 0x1A);
        func_801B0DF0(sc, e, col);
    }
}

void func_801B0DF0(void *sc, u8 *r, s32 col) {
    s32 idx;
    s32 i;
    s32 j;
    u8 *p;
    u8 *q;

    idx = (((s32 *)sc)[0x18] + ((s32 *)sc)[2]) >> 3;
    if (idx >= 0) {
        p = (u8 *)D_801CFD2C;
        func_80044A68(p, 0, 1, 0x20, 0);
        ((MgTag *)p)->addr = ((MgTag *)D_801517C0 + idx + 0x1C)->addr;
        ((MgTag *)D_801517C0 + idx + 0x1C)->addr = (u32)p;
        p += 0xC;
        q = p;
        i = 0;
        do {
            j = i + 1;
            *(s32 *)(q + 8) = ((s32 *)sc)[i + 0x10];
            *(s32 *)(q + 0xC) = ((s32 *)sc)[(j & 3) + 0x10];
            *(s32 *)(q + 0x10) = ((s32 *)sc)[i + 0x14];
            i = j;
            *(s32 *)(q + 0x14) = ((s32 *)sc)[(j & 3) + 0x14];
            *(s32 *)(q + 4) = col;
            ((MgTag *)q)->len = 5;
            q[7] = 0x2A;
            ((MgTag *)q)->addr = ((MgTag *)D_801517C0 + idx + 0x1C)->addr;
            ((MgTag *)D_801517C0 + idx + 0x1C)->addr = (u32)q;
            q += 0x18;
        } while (i < 4);
        p = q;
        func_80044A68(p, 0, 1, 0x40, 0);
        ((MgTag *)p)->addr = ((MgTag *)D_801517C0 + idx + 0x1C)->addr;
        ((MgTag *)D_801517C0 + idx + 0x1C)->addr = (u32)p;
        p += 0xC;
        D_801CFD2C = (MgLineG2 *)p;
    }
}

INCLUDE_ASM("../asm/us/magic_lv4jibak/nonmatchings/text", func_801B0FE4);

void func_801B115C(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801CFD2C;
    r->otz = func_8003BBDC(v0, &p->x0, &r->sxy, &r->flag);
    func_8003BBDC(v1, &p->x1, &r->sxy, &r->flag);
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->tag.len = 4;
    p->code = 0x52;
    p->tag.addr = ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr;
    ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr = (u32)p;
    p++;
    D_801CFD2C = p;
}

void func_801B128C(s32 arg0, s32 arg1) {
    MgTask *p;
    JbRec *r;
    JbSc2 *sc;
    s32 t;
    s32 n;
    s32 k;
    s32 x;
    s32 rnd;
    s32 m;
    s16 *q;

    p = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0574)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    sc = (JbSc2 *)0x1F800000;
    t = D_801518F6[arg0][0] + 0xE0;
    if (t >= 0x4F3) {
        t = 0x4F2;
    }
    p->unkC = t;
    p->unk12 = 0;
    p->unk14 = 0;
    p->unk16 = arg0;
    p->unk10 = D_801CFD3C;
    p->unkE = (t << 12) / 300;
    r = (JbRec *)&D_801CFD40[D_801CFD3C];
    D_801CFD3C++;
    q = &D_801CFD3A;
    if (*q == 0) {
        k = D_8015190F[arg1][0];
        func_800D3994(arg1, k, q - 3);
        D_801CFD36 = 0;
        *q = 1;
    }
    rnd = func_80042DA8();
    r->a.vx = p->unk4 - D_801CFD34;
    r->a.vy = 0;
    r->a.vz = p->unk8 - D_801CFD38;
    if (rnd & 1) {
        r->b.vx = -r->a.vz;
        r->b.vz = r->a.vx;
    } else {
        r->b.vx = r->a.vz;
        r->b.vz = -r->a.vx;
    }
    r->b.vy = 0;
    x = ((s32 (*)(MgVec *, MgVec *))func_8003A08C)(&r->a, &r->a);
    func_8003A08C(&r->b, &r->b);
    m = func_80039F5C(x);
    sc->s60 = rnd % 140 + 0xC8;
    t = t / 3;
    sc->s64 = t + rnd % t;
    sc->s78 = 0x1000 / (rnd % 12 + 0x10);
    sc->s68 = sc->s78;
    sc->p10 = *(MgSVec *)&D_801CFD34;
    sc->p18 = *(MgSVec *)&p->unk4;
    sc->d0.vx = r->a.vx * sc->s60 >> 12;
    sc->d0.vy = 0;
    sc->d0.vz = r->a.vz * sc->s60 >> 12;
    sc->e0 = r->b;
    n = m / sc->s60 + 1;
    if (n >= 0x21) {
        n = 0x20;
    }
    r->cnt = n;
    n++;
    r->e[0].p = sc->p10;
    for (k = 1; k < n; k++) {
        sc->p10.vx += sc->d0.vx;
        sc->p10.vz += sc->d0.vz;
        x = func_80039A74(sc->s68) * sc->s64 >> 12;
        sc->p20.vx = sc->p10.vx + (x * sc->e0.vx >> 12);
        sc->p20.vy = 0;
        sc->p20.vz = sc->p10.vz + (x * sc->e0.vz >> 12);
        r->e[k].p = sc->p20;
        sc->c0.vx = sc->p20.vx - r->e[k - 1].p.vx;
        sc->c0.vy = 0;
        sc->c0.vz = sc->p20.vz - r->e[k - 1].p.vz;
        func_8003A08C(&sc->c0, &sc->c0);
        r->e[k].ang = func_801B0090(&D_801B7D00, &sc->c0, &sc->f0);
        r->e[k].n = sc->f0;
        sc->s68 += sc->s78;
    }
    r->e[0].n = r->e[1].n;
    r->e[0].ang = r->e[1].ang;
}

INCLUDE_RODATA("../asm/us/magic_lv4jibak/nonmatchings/text", D_801B001C);

void func_801B1858(arg0, arg1) {
    D_801CFD30 = &D_80162978[func_800BBEAC(D_801B001C)];
    func_800D2980(&D_801B1904, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, (M2C_UNK *)func_801B128C);
    D_801CFD3A = 0;
    D_801CFD3C = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x116);
}
