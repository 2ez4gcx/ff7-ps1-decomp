#include "common.h"
#include "magic_kaeru/decls.h"

void func_801B0054(void) {
    func_801B0D08();
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
    MgTask *p;
    s32 off;
    s32 i;
    u16 t;

    p = &D_80162978[D_8015169C];
    D_801BD270.v = p->unk2;
    off = p->unk18 * 8;
    for (i = 0; i < 4; i++) {
        t = *(u16 *)(D_801D52A6 + off);
        func_800D4368(D_801D52A0 + off, (s16)t, -((s16)t >> 2));
        off += 8;
        D_801D5290 = func_800D4D90(D_801BD268, D_801517C0 + 0x70, 0xC, D_801D5290);
        if (off >= 0x6F0) {
            off = 0;
        }
    }
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B05A8(void) {
    MgTask *b;
    MgTask *p;
    s32 k;
    s32 off;
    s32 i;
    s32 w;

    if (D_80062D98 == 0) {
        b = D_80162978;
        p = &b[D_8015169C];
        if ((u32)((u16)p->unk2 - 0x12) < 0x24) {
            k = D_801D529C;
            i = 0;
            b[func_800BBEAC(&func_801B048C)].unk18 = k;
            off = k * 8;
            do {
                w = func_80042DA8() % 0x1000 + 0x800;
                *(s16 *)(D_801D52A0 + off) = (u16)p->unk4 + func_80042DA8() % p->unkE - (u16)p->unkC;
                k++;
                *(s16 *)(D_801D52A0 + 2 + off) = -(func_80042DA8() % p->unk10);
                *(s16 *)(D_801D52A4 + off) = (u16)p->unk8 + func_80042DA8() % p->unkE - (u16)p->unkC;
                *(s16 *)(D_801D52A6 + off) = (p->unk14 * w) >> 12;
                off += 8;
                if (k >= 0xDE) {
                    off = 0;
                    k = 0;
                }
                i++;
            } while (i < 4);
            D_801D529C = k;
        }
        if (p->unk2 == 0x11) {
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x134);
        }
        if (p->unk2 == 0x1E) {
            func_800D5774(D_801D5298);
        }
        if (p->unk2 >= 0x3C) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0838(void) {
    MgSVec rot;
    MgSVec pos;
    MgMat m;
    MgTask *p;
    u16 t;
    s32 c;

    rot.vx = 0;
    rot.vy = 0;
    p = &D_80162978[D_8015169C];
    rot.vz = p->unk10;
    pos.vx = 0;
    pos.vy = -p->unk14;
    pos.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003B2CC(&m, &pos, &pos);
    func_8003B2CC(&D_801D5990, &pos, &pos);
    pos.vx += p->unk4;
    pos.vy += p->unk6;
    pos.vz += p->unk8;
    if (p->unk2 >= 8) {
        c = -0x80 - ((p->unk2 - 8) << 5);
        D_801BD278 = D_801BD279 = D_801BD27A = c;
    }
    t = p->unkC;
    func_800D4368(&pos, (s16)t, -((s16)t >> 2));
    D_801D5290 = func_800D4D90(D_801BD274, D_801517C0 + 0x70, 0xC, D_801D5290);
    if (p->unk2 >= 0xC) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk10 += p->unk12;
        p->unk14 += p->unk16;
        p->unk2++;
    }
}

void func_801B09E8(void) {
    MgVec v;
    MgVec n;
    MgVec ax;
    MgTask *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    v.vx = D_80158D00 - p->unk4;
    v.vy = 0;
    v.vz = D_80158D04 - p->unk8;
    func_8003A08C(&v, &n);
    func_801B0150(func_801B0074(&D_801BD280, &n, &ax), &D_801D5990, &ax);
    if (D_80062D98 == 0) {
        if ((u32)((u16)p->unk2 - 1) < 0x14) {
            q = &D_80162978[func_800BBEAC(&func_801B0838)];
            *(KrB8 *)&q->unk4 = *(KrB8 *)&p->unk4;
            q->unkC = p->unkC;
            q->unk10 = (7 - (p->unk2 & 7)) << 9;
            q->unk12 = 0x60;
            t = (u16)p->unkE;
            q->unk14 = q->unk16 = (s16)t >> 2;
        }
        if (p->unk2 >= 0x15) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0B68(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 h;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    p = &b[func_800BBEAC(&func_801B05A8)];
    func_800D3994(D_801D5298, D_8015190F[D_801D5298][0], &p->unk4);
    h = (s16)D_801518F6[D_801D5298][0] + 0xE0;
    if (h > 0x4F2) {
        h = 0x4F2;
    }
    p->unkC = h;
    p->unkE = h << 1;
    p->unk10 = -(p->unk6 << 1);
    p->unk14 = (h << 12) / 450;
    q = &b[func_800BBEAC(&func_801B09E8)];
    *(KrB8 *)&q->unk4 = *(KrB8 *)&p->unk4;
    q->unkE = h;
    q->unkC = (h << 12) / 1500;
}

INCLUDE_RODATA("../asm/us/magic_kaeru/nonmatchings/text", D_801B0000);

void func_801B0D08(arg0) {
    s32 i;
    s32 n;

    D_801D5294 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0DDC, 0, 0, 0);
    i = 0;
    n = 0;
    do {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D5298 = i;
            }
        }
        i++;
    } while (i < 10);
    func_800BBEAC(&func_801B0B68);
    D_801D529C = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x9B);
}
