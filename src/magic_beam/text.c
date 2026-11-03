#include "common.h"
#include "magic_beam/decls.h"

void func_801B0054(void) {
    D_801DFA34 = 0;
    func_801B1564();
}

void func_801B007C(void) {
    D_801DFA34 = 1;
    func_801B1564();
}

s32 func_801B00A8(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0184(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0300(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03DC(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B04C0(void) {
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
    q = &D_801C79EC;
    q->v = D_801C79ED.v = D_801C79EE.v = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801DFA00 = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801DFA00);
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

void func_801B0634(void) {
    MgTask *p;
    s16 v;

    p = &D_80162978[D_8015169C];
    if (p->unk14 > 0) {
        if (D_80062D98 == 0) {
            p->unk14--;
        }
        return;
    }
    if (D_801DFA34 != 0) {
        D_801C79F8 = 0x80;
        D_801C79F9 = 0x70;
        D_801C79FA = 0x20;
    } else {
        D_801C79F8 = 0x80;
        D_801C79F9 = 0x80;
        D_801C79FA = 0x80;
    }
    D_801C79FC[0] = p->unk2;
    v = p->unkC;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801DFA00 = func_800D4D90(&D_801C79FC[-4], D_801517C0 + 0x70, 0xC, D_801DFA00);
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0774(void) {
    MgSVec rot;
    MgSVec q;
    MgMat m2;
    MgMat m1;
    MgVec scale;
    MgVec v;
    MgVec w;
    MgVec x;
    MgVec y;
    MgTask *p;
    void *tbl;
    s32 ang;
    s32 len;
    s32 dot;
    s32 k;
    s32 ax;
    s32 ay;
    s32 az;
    s32 bx;
    s32 by;
    s32 bz;

    v.vx = D_801DFA14.vx - D_801DFA1C.vx;
    v.vy = 0;
    v.vz = D_801DFA14.vz - D_801DFA1C.vz;
    p = &D_80162978[D_8015169C];
    func_8003A08C(&v, &v);
    ang = func_801B00A8(&D_801C79D8, &v, &w);
    func_801B0184(ang, &m1, &w);
    w.vx = D_801DFA14.vx - D_801DFA1C.vx;
    w.vy = D_801DFA14.vy - D_801DFA1C.vy;
    w.vz = D_801DFA14.vz - D_801DFA1C.vz;
    len = func_8003A08C(&w, &w);
    ang = func_801B00A8(&v, &w, &x);
    func_801B0184(ang, &m2, &x);
    func_8003B16C(&m2, &m1);
    ax = D_801DFA14.vx - D_801DFA1C.vx;
    ay = D_801DFA14.vy - D_801DFA1C.vy;
    az = D_801DFA14.vz - D_801DFA1C.vz;
    bx = D_80158D00.vx - D_801DFA1C.vx;
    by = D_80158D00.vy - D_801DFA1C.vy;
    bz = D_80158D00.vz - D_801DFA1C.vz;
    y.vx = ax;
    y.vy = ay;
    y.vz = az;
    x.vx = bx;
    x.vy = by;
    x.vz = bz;
    q = D_801DFA1C;
    dot = (ax * bx + ay * by + az * bz) >> 12;
    q.vx += dot * w.vx >> 12;
    q.vy += dot * w.vy >> 12;
    q.vz += dot * w.vz >> 12;
    x.vx = D_80158D00.vx - q.vx;
    x.vy = D_80158D00.vy - q.vy;
    x.vz = D_80158D00.vz - q.vz;
    func_8003A08C(&x, &x);
    dot = func_801B00A8(&D_801C79C8, &x, &y);
    func_8003BA10(&w, &x, &y);
    if (y.vy > 0) {
        dot = -dot;
    }
    rot.vx = dot;
    rot.vy = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m2);
    m2.t[0] = D_801DFA1C.vx;
    m2.t[1] = D_801DFA1C.vy;
    m2.t[2] = D_801DFA1C.vz;
    func_8003B16C(&m1, &m2);
    dot = (func_80039F5C(len) << 12) / 1525;
    if (p->unk2 < 3) {
        dot = dot / 3 * p->unk2;
    }
    scale.vx = dot;
    scale.vy = scale.vz = p->unkC;
    func_8003B35C(&m2, &scale);
    func_8003A63C(&D_800FA63C, &m2, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    tbl = &D_801C5978;
    if (D_801DFA34 != 0) {
        tbl = &D_801C63E4;
    }
    ((MgScratch *)0x1F800000)->unk0 = tbl;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    k = p->unk2;
    if (k >= 4) {
        ((MgScratch *)0x1F800000)->unkA = (k - 4) * 0x2AA;
    }
    func_8003B69C(0, 0, 0);
    D_801DFA00 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DFA00);
    if (p->unk2 >= 0xA) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0C40(void) {
    u8 pad[0x48];
    MgTask *p;
    MgScratch *s;
    void *tbl;
    s16 v;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    v = p->unkC;
    func_800D4368(&D_801DFA1C, v, -(v >> 3));
    s = (MgScratch *)0x1F800000;
    tbl = &D_801C6E50;
    if (D_801DFA34 != 0) {
        tbl = &D_801C740C;
    }
    s->unk0 = tbl;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 6) {
        k = 0x1000 - t * 0x2AA;
        goto store;
    }
    if (t >= 0xA) {
        k = (t - 0xA) * 0x2AA;
store:
        ((MgScratch *)0x1F800000)->unkA = k;
    }
    func_8003B69C(0, 0, 0);
    D_801DFA00 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801DFA00);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 6) {
            p->unkC -= p->unkE;
            p->unkE -= p->unkE / 9;
        }
        p->unk2++;
    }
}

void func_801B0E1C(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    MgTask *e;
    s32 i;
    s32 k;
    s32 r;
    s32 a;
    s32 n;

    func_800D3994(D_801DFA10, D_8015190F[D_801DFA10][0], &D_801DFA1C);
    D_801DFA1C.pad = D_801518F6[D_801DFA10][0] + 0x100;
    D_801DFA24.vx = D_801DFA14.vx - D_801DFA1C.vx;
    D_801DFA24.vy = D_801DFA14.vy - D_801DFA1C.vy;
    D_801DFA24.vz = D_801DFA14.vz - D_801DFA1C.vz;
    func_8003A08C(&D_801DFA24, &D_801DFA24);
    if (D_80062D98 == 0) {
        b = D_80162978;
        p = &b[D_8015169C];
        if (p->unk2 == 1) {
            q = &b[func_800BBEAC((M2C_UNK *)func_801B0C40)];
            q->unkC = 0x6000;
            q->unkE = 0x1333;
        }
        if (p->unk2 == 6) {
            q = &b[func_800BBEAC((M2C_UNK *)func_801B0774)];
            q->unkC = 0x666;
        }
        if (p->unk2 == 0x10) {
            k = 0x2440;
            i = 0;
            do {
                i++;
                n = 0x190;
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0634)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&D_801DFA14;
                q->unk4 = q->unk4 + n - func_80042DA8() % 800;
                q->unk6 = q->unk6 + n - func_80042DA8() % 800;
                q->unk8 = q->unk8 + n - func_80042DA8() % 800;
                a = func_80042DA8() % 0xA00 + 0xC00;
                q->unkC = (k * a) >> 12;
                q->unk14 = func_80042DA8() % 6;
            } while (i < 3);
        }
        if ((u32)((u16)p->unk2 - 0x12) < 4) {
            k = 0x666;
            i = 0;
            do {
                e = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B04C0)];
                r = func_80042DA8();
                a = r / 0x1000;
                a = r - a * 0x1000;
                n = ((s16)D_801DFA14.pad >> 1) + func_80042DA8() % 100;
                e->unk4 = D_801DFA14.vx + ((func_80039B40(a) * n) >> 12);
                r = 0x1E;
                e->unk6 = D_801DFA14.vy + r + func_80042DA8() % 180;
                e->unk8 = D_801DFA14.vz + ((func_80039A74(a) * n) >> 12);
                n = func_80042DA8() % 180 + 0x32;
                e->unkC = (func_80039B40(a) * n) >> 12;
                e->unkE = -(func_80042DA8() % 60 + 0x14);
                e->unk10 = (func_80039A74(a) * n) >> 12;
                a = func_80042DA8() % 0xA00 + 0x800;
                e->unk14 = (k * a) >> 12;
                i++;
            } while (i < 10);
        }
        if (p->unk2 == 7) {
            func_800D55F4(0x20, func_800D56A8(&D_801DFA1C), 0x241);
        }
        if (p->unk2 == 0x10) {
            func_800D55F4(0x21, func_800D56A8(&D_801DFA14), 0x1D2, 0x1D2);
        }
        if (p->unk2 == 0x1A) {
            func_800D5774(D_801DFA0C);
        }
        if (p->unk2 >= 0x28) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B147C(void) {
    u8 pad[8];

    D_80162978[D_8015169C].unk0 = -1;
    D_8016298C[func_800BBEAC(&func_801B0E1C)].unk0 = 0;
    func_800D3994(D_801DFA0C, D_8015190F[D_801DFA0C][0], &D_801DFA14);
    D_801DFA1A = D_801518F6[D_801DFA0C][0] + 0x100;
}

INCLUDE_RODATA("../asm/us/magic_beam/nonmatchings/text", D_801B0000);

void func_801B1564(mask, arg1) {
    s32 i;
    s32 n;

    D_801DFA04 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1630, 0, 0, 0);
    func_800BBEAC(&func_801B147C);
    D_801DFA08 = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801DFA0C = i;
            }
        }
    }
    D_801DFA10 = arg1;
}
