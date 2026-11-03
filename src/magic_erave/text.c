#include "common.h"
#include "magic_erave/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B226C();
    return &D_801CBD74;
}

s32 func_801B007C(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0158(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02D4(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03B0(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_erave/nonmatchings/text", func_801B0494);

void func_801B0AB0(void) {
    MgMat m;
    MgVec scale;
    MgVec dir;
    MgVec n;
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    dir = *(MgVec *)((u8 *)p + 0xC);
    func_801B0158(func_801B007C(&D_801D1340, &dir, &n), &m, &n);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vz = p->unk1C;
    scale.vy = p->unk1E;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    frame = &D_801D1384;
    *frame = p->unk2;
    D_801E9418 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E9418);
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += (p->unkA * dir.vx) >> 12;
        p->unk6 += (p->unkA * dir.vy) >> 12;
        p->unk8 += (p->unkA * dir.vz) >> 12;
        p->unkA -= p->unkA >> 4;
        p->unk2++;
        p->unk1E += p->unk1E >> 4;
    }
}

void func_801B0C9C(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk10;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801CACD0;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801E9418 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E9418);
    if (p->unk2 >= 8) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE >> 5;
        p->unk10 -= p->unk12;
        p->unk12 -= p->unk12 >> 4;
        if (p->unk10 < 0) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0E58(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    void *tbl;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = p->unk18;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk1C;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    tbl = D_801D1360[p->unk1E];
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = tbl;
    if (p->unk2 >= 0xA) {
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0xA) * 0x15;
    }
    D_801E9418 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801E9418);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk2++;
        p->unkE += p->unkE / 7;
    }
}

void func_801B1074(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;
    s32 w;
    s32 c;
    u16 r;
    s32 u;
    s32 n2;
    s16 v;
    u16 n;
    s16 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC((void *)func_801B0494)];
            do {
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unk18 = p->unk18;
                if (p->unk18 == 0) {
                    v = -1;
                } else {
                    v = p->unk1A;
                }
                q->unk1A = v;
            } while (0);
        }
        if (p->unk1A < 0) {
            p->unk0 = -1;
            return;
        }
        if (p->unk2 == 1) {
            if (p->unk18 >= 2) {
                i = 0;
                do {
                    q = &D_80162978[func_800BBEAC((void *)func_801B0AB0)];
                    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                    q->unkA = func_80042DA8() % 280 + 0x44;
                    ((MgVec *)&q->unkC)->vx = func_80042DA8() % 0x1000 - 0x800;
                    ((MgVec *)&q->unkC)->vy = func_80042DA8() % 0x1000 - 0x800;
                    ((MgVec *)&q->unkC)->vz = func_80042DA8() % 0x1000 - 0x800;
                    func_8003A08C((MgVec *)&q->unkC, (MgVec *)&q->unkC);
                    k = 0x2580;
                    c = (func_80042DA8() % 0x600 + 0xA00) * k >> 12;
                    q->unk1C = c;
                    q->unk1E = c;
                    i++;
                } while (i < 0xC);
            }
        }
        if (p->unk2 == 0) {
            if (p->unk18 >= 3) {
                q = &D_80162978[func_800BBEAC((void *)func_801B0C9C)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                q->unk6 = 0;
                q->unkC = func_80042DA8() % 0x1000;
                q->unkE = func_80042DA8() % 220 + 0xF0;
                t = ((p->unk18 - 2) * 200 + 0x514 << 12) / 1000;
                q->unk10 = t;
                q->unk12 = t / 7;
            }
        }
        if (p->unk2 == 0) {
            if (p->unk18 >= 3) {
                w = p->unk18 * 16 + 0xC8;
                for (i = 0; i < p->unk18 + 8; i++) {
                    q = &D_80162978[func_800BBEAC((void *)func_801B0E58)];
                    q->unk4 = (u16)p->unk4 + func_80042DA8() % 1800 - 0x384;
                    r = func_80042DA8() % 780;
                    n2 = p->unk18 - 2;
                    q->unk6 = -(u32)(r + (n2 * 30 + 0x46));
                    q->unk8 = (u16)p->unk8 + func_80042DA8() % 1800 - 0x384;
                    r = func_80042DA8() % 98;
                    u = (p->unk18 - 2) * 10 + 0x10;
                    q->unkE = -(r + u);
                    q->unk14 = q->unk18 = func_80042DA8() % 0x1000;
                    q->unk16 = func_80042DA8() % 72 + 0x60;
                    q->unk1A = func_80042DA8() % 128 + 0x4A;
                    k = (w << 12) / 600;
                    q->unk1C = k * (func_80042DA8() % 0xA00 + 0x500) >> 12;
                    q->unk1E = func_80042DA8() % 4;
                }
            }
        }
        n = p->unk2;
        if (n < 3) {
            if (p->unk18 >= 3) {
                D_800FA666 = (((s16)n + 1) & 1) * 140;
            }
        }
        if (p->unk2 >= 3) {
            D_800FA666 = 0;
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

u8 func_801B1784(s32 arg0) {
    u8 id;
    s32 ang;
    s32 t;
    s32 k;
    s32 c;
    u16 *g;

    g = &D_801EC310;
    id = D_801517F0[arg0];
    func_800D3994(id, D_8015190F[id][0], g);
    k = D_801E9424;
    t = ((D_801518F6[k][0] * D_801518EA[k][0]) >> 12) + ((D_801518F6[id][0] * D_801518EA[id][0]) >> 12);
    ang = D_801518FC[id][0];
    *g += (func_80039A74(ang) * t) >> 12;
    c = func_80039B40(ang) * t;
    D_801EC316 = ang + 0x800;
    D_801EC314 -= c >> 12;
    return id;
}

u8 func_801B1904(s32 arg0) {
    u8 id;
    s32 ang;
    s32 rot;
    s32 t;
    s32 k;
    s32 c;
    u16 *g;

    g = &D_801EC310;
    id = D_801517F0[arg0];
    func_800D3994(id, D_8015190F[id][0], g);
    k = D_801E9424;
    t = ((D_801518F6[k][0] * D_801518EA[k][0]) >> 12) + ((D_801518F6[id][0] * D_801518EA[id][0]) >> 12);
    ang = func_8003CC1C(D_80151A4C[id][0] - D_80151A4C[k][0], D_80151A50[id][0] - D_80151A50[k][0]);
    rot = 0x800 - ang;
    *g -= (func_80039A74(rot) * t) >> 12;
    c = func_80039B40(rot) * t;
    D_801EC316 = ang + 0x800;
    D_801EC314 += c >> 12;
    return id;
}

INCLUDE_ASM("../asm/us/magic_erave/nonmatchings/text", func_801B1AD0);

void func_801B2200(void) {
    MgTask *p;
    MgTask *base;
    s32 n;

    base = D_80162978;
    D_80162978[D_8015169C].unk0 = -1;
    n = func_800BBEAC(&func_801B1AD0);
    p = base + n;
    p->unk14 = 0;
    p->unk16 = 0;
    p->unk1A = 0;
}

INCLUDE_RODATA("../asm/us/magic_erave/nonmatchings/text", D_801B0000);

void func_801B226C(arg0, arg1) {
    D_801E941C = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B22F8, 0, 0, 0);
    func_800BBEAC(&func_801B2200);
    D_801E9420 = arg0;
    D_801E9424 = arg1;
}
