#include "common.h"
#include "magic_toybox/decls.h"

void func_801B0054(s32 arg0, s32 arg1) {
    func_801B1530(arg0, arg1, 0);
}

void func_801B0074(s32 a, s32 b) {
    func_801B1530(a, b, 1);
}

void func_801B0094(s32 a, s32 b) {
    func_801B1530(a, b, 2);
}

void func_801B00B4(s32 a, s32 b) {
    func_801B1530(a, b, 3);
}

s32 func_801B00D4(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B01B0(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B032C(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B0408(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B04EC(void) {
    MgSVec a;
    MgSVec b;
    MgSVec c;
    MgMat m;
    MgMat n;
    MgVec scale;
    MgTask *p;
    s32 i;

    a.vx = 0;
    a.vy = 0;
    p = &D_80162978[D_8015169C];
    a.vz = p->unkC;
    func_8003BF8C(&a, &m);
    c.vx = p->unk16;
    c.vy = 0;
    c.vz = 0;
    b.vx = 0;
    b.vy = p->unk10 + 0x400;
    b.vz = 0;
    func_8003BF8C(&b, &n);
    func_8003A79C(&n, &m, &m);
    func_8003B27C(&n, &c, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6 - p->unk18;
    m.t[2] += p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk12;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801BAA54;
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801D9A30 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D9A30);
    if (p->unk2 >= 0x1A) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x10) {
            i = 0;
            do {
                if (1 << i & D_801D9A38) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if ((u16)(p->unk2 - 0xA) < 4U) {
            p->unkC += p->unkE;
        }
        if (p->unk2 < 8) {
            p->unk12 += p->unk14;
        }
        p->unk2++;
    }
}

void func_801B075C(void) {
    MgSVec a;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 i;

    a.vx = 0;
    p = &D_80162978[D_8015169C];
    a.vy = p->unkC;
    a.vz = 0;
    func_8003BF8C(&a, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6 + p->unk16;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk12;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk4 = 0x180;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = (void *)D_801D9A48;
    D_801D9A30 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D9A30);
    if (p->unk2 >= 0x1A) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x10) {
            i = 0;
            do {
                if (1 << i & D_801D9A38) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 10);
        }
        if (p->unk2 < 6) {
            p->unk16 += p->unk18;
        }
        if (p->unk2 == 6) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0xA6);
        }
        p->unk2++;
    }
}

void func_801B0960(void) {
    MgTask *p;
    s8 *frame;
    s32 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801C1A18;
    t = p->unk2 << 5;
    *frame = t;
    func_800D4368(&p->unk4, p->unk12, 0);
    D_801D9A30 = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_801D9A30);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unk16;
        p->unk8 += p->unk18;
        p->unk2++;
    }
}

void func_801B0A40(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801C1A2C;
    *frame = p->unk2;
    func_800D4368(&p->unk4, p->unk12, 0);
    D_801D9A30 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801D9A30);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unk16;
        p->unk8 += p->unk18;
        p->unk2++;
    }
}

void func_801B0B1C(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 d;
    s32 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 0xE) < 4U) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0960)];
                v.vx = func_80042DA8() % 0x1000 - 0x800;
                v.vy = 0;
                v.vz = func_80042DA8() % 0x1000 - 0x800;
                func_8003A08C(&v, &v);
                d = p->unkC - p->unkE + func_80042DA8() % (p->unkE * 2);
                q->unk4 = p->unk4 + (d * v.vx >> 12);
                q->unk6 = p->unk6;
                q->unk8 = p->unk8 + (d * v.vz >> 12);
                q->unk12 = p->unk12;
                w = p->unk14 + func_80042DA8() % 32;
                q->unk16 = w * v.vx >> 12;
                i++;
                q->unk18 = w * v.vz >> 12;
            } while (i < 12);
        }
        if (p->unk2 >= 0x1A) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0D30(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 d;
    s32 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)(p->unk2 - 6) < 4U) {
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0A40)];
                v.vx = func_80042DA8() % 0x1000 - 0x800;
                v.vy = 0;
                v.vz = func_80042DA8() % 0x1000 - 0x800;
                func_8003A08C(&v, &v);
                d = p->unkE + func_80042DA8() % (p->unkC - p->unkE + 0x64);
                q->unk4 = p->unk4 + (d * v.vx >> 12);
                q->unk6 = p->unk6;
                q->unk8 = p->unk8 + (d * v.vz >> 12);
                q->unk12 = p->unk12;
                w = p->unk14 + func_80042DA8() % 32;
                q->unk16 = w * v.vx >> 12;
                i++;
                q->unk18 = w * v.vz >> 12;
            } while (i < 12);
        }
        if (p->unk2 >= 0x1A) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0F40(void) {
    MgSVec v;
    MgVec w;
    MgVec n;
    MgTask *b;
    MgTask *p;
    s32 ang;

    D_80162978[D_8015169C].unk0 = -1;
    func_800D54EC(D_801D9A38, &v);
    v.vy = 0;
    func_800D3994(D_801D9A3C, D_8015190F[D_801D9A3C][0], &D_801D9A40);
    w.vx = D_801D9A40.vx - v.vx;
    w.vy = 0;
    w.vz = D_801D9A44 - v.vz;
    func_8003A08C(&w, &w);
    ang = func_801B00D4(&D_801C1A04, &w, &n);
    b = D_80162978;
    if (n.vy < 0) {
        ang = -ang;
    }
    p = &b[func_800BBEAC(&func_801B04EC)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkE = -0x100;
    p->unk14 = 0x49B;
    p->unk16 = 0x7C9;
    p->unkC = 0;
    p->unk10 = ang;
    p->unk12 = 0;
    p->unk18 = 0x5A0;
    p = &b[func_800BBEAC(&func_801B0B1C)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkC = 0x279;
    p->unkE = 0x13C;
    p->unk12 = 0x39DF;
    p->unk14 = 0x74;
    func_800D55F4(0x20, func_800D574C(D_801D9A38), 0xA4);
}

void func_801B111C(void) {
    MgSVec v;
    MgTask *b;
    MgTask *p;

    D_80162978[D_8015169C].unk0 = -1;
    func_800D54EC(D_801D9A38, &v);
    v.vy = 0;
    b = D_80162978;
    p = &b[func_800BBEAC(&func_801B075C)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkC = func_80042DA8() % 0x1000;
    p->unk12 = 0x19E7;
    p->unk16 = -0xDAC;
    p->unk18 = 0x247;
    D_801D9A48 = (s32)D_801BBDB8;
    p = &b[func_800BBEAC(&func_801B0D30)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkC = 0xA28;
    p->unkE = 0x6A4;
    p->unk12 = 0x39DF;
    p->unk14 = 0xD3;
    func_800D55F4(0x20, func_800D574C(D_801D9A38), 0x85);
}

void func_801B1278(void) {
    MgSVec v;
    MgTask *b;
    MgTask *p;

    D_80162978[D_8015169C].unk0 = -1;
    func_800D54EC(D_801D9A38, &v);
    v.vy = 0;
    b = D_80162978;
    p = &b[func_800BBEAC(&func_801B075C)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkC = func_80042DA8() % 0x1000;
    p->unk12 = 0x1124;
    p->unk16 = -0xDAC;
    p->unk18 = 0x247;
    D_801D9A48 = (s32)D_801BCA6C;
    p = &b[func_800BBEAC(&func_801B0D30)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkC = 0x8FC;
    p->unkE = 0x578;
    p->unk12 = 0x39DF;
    p->unk14 = 0xD3;
    func_800D55F4(0x20, func_800D574C(D_801D9A38), 0x85);
}

void func_801B13D4(void) {
    MgSVec v;
    MgTask *b;
    MgTask *p;

    D_80162978[D_8015169C].unk0 = -1;
    func_800D54EC(D_801D9A38, &v);
    v.vy = 0;
    b = D_80162978;
    p = &b[func_800BBEAC(&func_801B075C)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkC = func_80042DA8() % 0x1000;
    p->unk12 = 0x1200;
    p->unk16 = -0xDAC;
    p->unk18 = 0x247;
    D_801D9A48 = (s32)D_801C00E0;
    p = &b[func_800BBEAC(&func_801B0D30)];
    *(MgB8 *)&p->unk4 = *(MgB8 *)&v;
    p->unkC = 0x578;
    p->unkE = 0x384;
    p->unk12 = 0x2924;
    p->unk14 = 0x96;
    func_800D55F4(0x20, func_800D574C(D_801D9A38), 0x85);
}

INCLUDE_RODATA("../asm/us/magic_toybox/nonmatchings/text", D_801B0000);

void func_801B1530(s32 arg0, s32 arg1, s32 arg2) {
    D_801D9A34 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1638, 0, 0, 0);
    D_801D9A38 = arg0;
    D_801D9A3C = arg1;
    switch (arg2) {
    case 0:
        func_800BBEAC(&func_801B0F40);
        break;
    case 1:
        func_800BBEAC(&func_801B111C);
        break;
    case 2:
        func_800BBEAC(&func_801B1278);
        break;
    case 3:
        func_800BBEAC(&func_801B13D4);
        break;
    }
}
