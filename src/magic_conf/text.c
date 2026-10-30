#include "common.h"
#include "magic_conf/decls.h"

s32 func_801B0080(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B015C(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02D8(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03B4(MgSVec *p, MgSVec *q, MgVec *n) {
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

M2C_UNK *func_801B0498(s32 a, s32 b) {
    func_801B2618(a, b, 0);
    return &D_801BBB4C;
}

M2C_UNK *func_801B04C0(s32 a, s32 b) {
    func_801B2618(a, b, 1);
    return &D_801BBB4C;
}

void func_801B04E8(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801C745C;
    *frame = p->unk2;
    func_800D4368(&p->unk4, p->unk18, -(p->unk18 >> 3));
    D_801DF484 = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801DF484);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        p->unk2++;
    }
}

void func_801B05D0(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 w;
    s32 k;

    p = &D_80162978[D_8015169C];
    k = p->unk2 <= 0;
    if (k) {
        p->unk2++;
        return;
    }
    w = p->unk12;
    for (i = 0; i < 0x16; i++) {
        if (D_80162080 >= 0x60) {
            break;
        }
        q = &D_80162978[func_800BBEAC(&func_801B04E8)];
        *(CfB8 *)&q->unk4 = *(CfB8 *)&p->unk4;
        q->unk6 -= 0x3C;
        v.vx = func_80042DA8() % 0x1000 - 0x800;
        v.vy = 0;
        v.vz = func_80042DA8() % 0x1000 - 0x800;
        func_8003A08C(&v, &v);
        k = p->unk10 + func_80042DA8() % 448;
        q->unkC = (k * v.vx >> 12) / 12;
        q->unkE = 0;
        q->unk10 = (k * v.vz >> 12) / 12;
        k = func_80042DA8() % 0x800 + 0xA00;
        q->unk18 = (w * k) >> 12;
    }
    p->unk0 = -1;
    p->unk2++;
}

void func_801B0800(void) {
    MgTask *p;
    u8 c;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, p->unk18, -(p->unk18 >> 3));
    if (p->unk2 < 6) {
        c = p->unk2 * 0x11;
    } else {
        c = 0x68;
        if (p->unk2 >= 0xC) {
            c = 0x68 - (p->unk2 - 0xC) * 0xD;
        }
    }
    if (p->unk2 % 4 == p->unk1A) {
        c = c << 1;
    }
    D_801C7464[0] = D_801C7465 = D_801C7466 = c;
    D_801DF484 = func_800D4D90(D_801C7464 - 4, D_801517C0 + 0x70, 0xC, D_801DF484);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += p->unk1C;
        p->unk1C -= p->unk1C >> 4;
        p->unk14 += p->unk16;
        if (p->unk6 >= 0) {
            p->unkE = -(func_80042DA8() % 300 + 0x28);
            p->unk1C += func_80042DA8() % 50;
        }
        p->unk2++;
    }
}

void func_801B0A40(void) {
    MgVec v;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 w;
    s32 k;

    p = &D_80162978[D_8015169C];
    k = p->unk2 <= 0;
    if (k) {
        p->unk2++;
        return;
    }
    w = p->unk12;
    for (i = 0; i < 0x18; i++) {
        if (D_80162080 >= 0x60) {
            break;
        }
        q = &D_80162978[func_800BBEAC(&func_801B0800)];
        *(CfB8 *)&q->unk4 = *(CfB8 *)&p->unk4;
        v.vx = func_80042DA8() % 0x1000 - 0x800;
        v.vy = 0;
        v.vz = func_80042DA8() % 0x1000 - 0x800;
        func_8003A08C(&v, &v);
        k = p->unk10 + func_80042DA8() % 672 + 0xE0;
        q->unkC = (k * v.vx >> 12) / 10;
        q->unkE = -(func_80042DA8() % 380 + 0x3C);
        q->unk10 = (k * v.vz >> 12) / 10;
        k = func_80042DA8() % 0xC00 + 0xA00;
        q->unk18 = (w * k) >> 12;
        q->unk1A = func_80042DA8() % 4;
        q->unk1C = func_80042DA8() % 72 + 0x1C;
    }
    p->unk0 = -1;
    p->unk2++;
}

void func_801B0D24(void) {
    MgTask *p;
    MgTask *q;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 1) {
        q = func_800D4FA8(1);
        *(CfB8 *)&q->unk4 = *(CfB8 *)&p->unk4;
        q->unk10 = p->unkC;
        func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x19F);
    } else if (p->unk2 == 0x2A) {
        func_800D4FA8(2);
    }
    if ((u32)((u16)p->unk2 - 1) < 0x10) {
        D_80153D22[0] += p->unk16;
    }
    if ((u32)((u16)p->unk2 - 0x2A) < 0x10) {
        D_80153D22[0] -= p->unk16;
    }
    if (p->unk2 == 0x36) {
        for (i = 0; i < 10; i++) {
            if (1 << i & D_801DF48C) {
                func_800D5774(i);
            }
        }
    }
    if (p->unk2 >= 0x3C) {
        p->unk0 = -1;
    }
    p->unk2++;
}

s32 func_801B0EB4(s32 x, s32 v, s32 a, s32 lim) {
    s32 i;

    x += v;
    v += a;
    for (i = 0; i < 99; i++) {
        x += v;
        v += a;
        a -= a >> 4;
        if (x >= lim && v > 0) {
            break;
        }
    }
    return i;
}

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B0F00);

void func_801B18D8(void) {
    MgSVec rot;
    MgSVec ang;
    MgMat m;
    MgVec v;
    MgTask *p;
    u8 c;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    ang.vx = 0;
    ang.vy = 0;
    ang.vz = p->unk14;
    func_8003B27C(&m, &ang, (MgVec *)m.t);
    m.t[0] += p->unk4;
    m.t[1] += p->unk6;
    m.t[2] += p->unk8;
    v.vx = v.vy = v.vz = p->unk10;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    t = p->unk2;
    if (t < 8) {
        c = t * 0xD;
    } else if (t >= 0x15) {
        c = 0x68 - (t - 0x15) * 0xD;
    } else {
        c = 0x68;
    }
    D_801C7470[0] = D_801C7471 = D_801C7472 = c;
    D_801DF484 = func_800D4D90(D_801C7470 - 4, D_801517C0 + 0x70, 0xC, D_801DF484);
    if (p->unk2 >= 0x1D) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
    }
}

void func_801B1AA8(void) {
    MgSVec rot;
    u8 pad[8];
    MgMat m;
    MgVec v;
    MgTask *p;
    u8 c;
    s32 t;
    s32 r;

    p = &D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk14;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    t = p->unk2;
    if (t < 6) {
        c = t * 0x11;
    } else if (t >= 0x15) {
        c = 0x68 - (t - 0x15) * 0xD;
    } else {
        c = 0x68;
    }
    D_801C747C[0] = D_801C747D = D_801C747E = c;
    D_801DF484 = func_800D4D90(D_801C747C - 4, D_801517C0 + 0x70, 0xC, D_801DF484);
    if (p->unk2 >= 0x1D) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += p->unk1C;
        p->unk1C -= p->unk1C >> 4;
        p->unk14 += p->unk16;
        if (p->unk6 >= 0) {
            p->unkE = -(func_80042DA8() % 80 + 0xFA);
            p->unk1C += func_80042DA8() % 50;
            r = func_80042DA8() % 0x30 + 0x10;
            p->unk16 = r;
            if (p->unk14 < 0) {
                p->unk16 = -r;
            }
        }
        p->unk2++;
    }
}

void func_801B1D64(void) {
    MgTask *p;
    MgTask *q;
    MgTask *b;
    s32 i;
    s32 k1;
    s32 k2;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 0x11) {
        k2 = 0xAAA;
        i = 0;
        b = D_80162978;
        k1 = 0x55;
        do {
            q = (MgTask *)((func_800BBEAC(&func_801B18D8) << 5) + (s32)b);
            *(CfB8 *)&q->unk4 = *(CfB8 *)&p->unk4;
            q->unkC = i << 9;
            q->unkE = k1;
            q->unk10 = k2;
            q->unk14 = p->unk10;
            i++;
        } while (i < 8);
        func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x19E);
    }
    if (p->unk2 >= 0x3C) {
        p->unk0 = -1;
    }
    p->unk2++;
}

INCLUDE_RODATA("../asm/us/magic_conf/nonmatchings/text", D_801B001C);

void func_801B1E7C(void) {
    MgVec v;
    MgVec up;
    MgVec n;
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;
    s32 a;
    s32 c;

    up = D_801B001C;
    p = &D_80162978[D_8015169C];
    if ((u32)((u16)p->unk2 - 0x11) < 4) {
        c = 0xAAA;
        for (i = 0; i < 0x12; i++) {
            q = &D_80162978[func_800BBEAC(&func_801B1AA8)];
            *(CfB8 *)&q->unk4 = *(CfB8 *)&p->unk4;
            v.vx = func_80042DA8() % 0x1000 - 0x800;
            v.vy = 0;
            v.vz = func_80042DA8() % 0x1000 - 0x800;
            func_8003A08C(&v, &v);
            a = func_801B0080(&up, &v, &n);
            q->unk14 = a;
            if (n.vy < 0) {
                q->unk14 = -a;
            }
            q->unk16 = 0;
            k = p->unk10 + func_80042DA8() % 448;
            q->unkC = q->unk4 + (k * v.vx >> 12);
            q->unkE = 0;
            q->unk10 = q->unk8 + (k * v.vz >> 12);
            q->unkC = (q->unkC - q->unk4) / 16;
            q->unkE = -(func_80042DA8() % 60 + 0xFA);
            q->unk10 = (q->unk10 - q->unk8) / 16;
            q->unk18 = c;
            q->unk1C = -q->unk6 / 24;
        }
    }
    if (p->unk2 == 0x11) {
        func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x19E);
    }
    if (p->unk2 >= 0x3C) {
        p->unk0 = -1;
    }
    p->unk2++;
}

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B2170);

INCLUDE_ASM("../asm/us/magic_conf/nonmatchings/text", func_801B2350);

INCLUDE_RODATA("../asm/us/magic_conf/nonmatchings/text", D_801B002C);

void func_801B2618(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK *f;

    D_801DF488 = &D_80162978[func_800BBEAC(&D_801B002C)];
    func_800D2980(&D_801B26C0, 0, 0, 0);
    f = &func_801B2170;
    if (arg2 != 0) {
        f = &func_801B2350;
    }
    func_800BBEAC(f);
    D_801DF48C = arg0;
    D_801DF494 = arg1;
}
