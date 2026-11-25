#include "common.h"
#include "magic_hmoon/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B1140();
    return &D_801C93D4;
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

void func_801B0494(void) {
    MgTask *p;
    s32 t;
    u8 c;
    s16 v;
    s16 *q;
    s8 *frame;

    p = &D_80162978[D_8015169C];
    D_801CB71C[0] = p->unk2;
    t = p->unk2;
    if (t >= 9) {
        c = 0x60 - ((t - 9) * 0x10);
    } else {
        c = 0x60;
    }
    frame = &D_801CB718;
    q = &p->unk14;
    *frame = (D_801CB719 = (D_801CB71A = c));
    v = (u16)(*q);
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801E373C = func_800D4D90(frame - 4, D_801517C0 + 0x70, 0xC, D_801E373C);
    if (p->unk2 >= 0xF) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        p->unk2++;
        p->unkC -= ((s16)p->unkC) >> 3;
        p->unk10 -= ((s16)p->unk10) >> 3;
    }
}

void func_801B05E8(void *arg0) {
    HmStrip *s;
    HmPoly *q;
    s32 x0;
    s32 rgb;
    s32 x1;
    s32 phase;
    s32 n;
    s32 a1;
    s32 t;
    s32 ot;
    s32 cc;
    u32 m1;
    u32 m2;
    s32 col;
    s32 u;
    s32 w;
    s32 cw;

    s = arg0;
    q = D_801E373C;
    phase = s->phase;
    col = s->color;
    s->a.vx = -0x400;
    s->a.vy = -0x400;
    s->b.vy = -0x400;
    s->c.vx = -0x400;
    s->a.vz = 0;
    s->b.vx = 0x400;
    s->b.vz = 0;
    s->c.vy = -0x3F8;
    s->c.vz = 0;
    s->d.vx = 0x400;
    s->d.vy = -0x3F8;
    s->d.vz = 0;
    rgb = ((col << 16) | (col << 8)) | col;
    x0 = s->a.vx;
    x1 = s->b.vx;
    a1 = 0;
    if (s->amp != 0) {
        a1 = (func_80039A74(phase) * s->amp) >> 12;
        phase += s->step;
    }
    cc = 0x2C00FF;
    cw = 0x78080000;
    n = 0;
    s->a.vx += a1;
    s->b.vx += a1;
    do {
        a1 = 0;
        if (s->amp != 0) {
            t = func_80039A74(phase);
            a1 = (t * s->amp) >> 12;
            phase += s->step;
        }
        s->c.vx = x0 + a1;
        s->d.vx = x1 + a1;
        s->unk8 = func_8003BD7C(&s->a, &s->b, &s->c, &s->d, &q->xy0, &q->xy1, &q->xy2, &q->xy3, &s->unk4, &s->unkC);
        s->a.vx = s->c.vx;
        s->b.vx = s->d.vx;
        s->a.vy = s->c.vy;
        s->b.vy = s->d.vy;
        s->c.vy += 8;
        s->d.vy += 8;
        t = n << 8;
        w = cw + t;
        u = cc + t;
        t = 0;
        q->uv0 = w;
        q->uv1 = u;
        q->uv2 = w + 0x100;
        q->uv3 = u + 0x100;
        q->col = rgb;
        ((u8 *)q)[3] = 9;
        if (s->mode != 0) {
            ((u8 *)q)[7] = 0x2E;
        } else {
            ((u8 *)q)[7] = 0x2C;
        }
        n++;
        m1 = 0xFFFFFF;
        m2 = 0xFF000000;
        q->tag = (q->tag & m2) | ((*((u32 *)((((s->unk8 >> 2) << 2) + D_801517C0) + 0x70))) & m1);
        ot = ((s->unk8 >> 2) << 2) + D_801517C0;
        *((u32 *)(ot + 0x70)) = ((*((u32 *)(ot + 0x70))) & m2) | (((u32)q) & m1);
        q++;
    } while (n < 0xFF);
    D_801E373C = q;
}

void func_801B08B4(void) {
    MgSVec rot;
    u8 pad[8];
    MgMat m;
    MgVec scale;
    MgTask *p;
    HmScr *s;
    s32 t;
    s32 v;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    func_8003B16C(&D_801E375C, &m);
    m.t[0] = p->unk4 - (p->unk14 * D_801E374C >> 12);
    m.t[1] = p->unk6 - (p->unk14 * D_801E3750 >> 12);
    m.t[2] = p->unk8 - (p->unk14 * D_801E3754 >> 12);
    scale.vx = scale.vy = scale.vz = p->unk16;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    s = (HmScr *)0x1F800000;
    s->unk34 = 0x20;
    s->unk38 = p->unk2 << 7;
    t = p->unk2;
    if (t < 0xD) {
        v = func_80039B40(t * 0x55) << 11;
        s->unk30 = v >> 12;
        s->unk40 = 1;
    } else if (t >= 0x31) {
        v = func_80039A74((t - 0x31) << 6) << 11;
        s->unk30 = v >> 12;
        s->unk40 = 1;
    } else {
        s->unk30 = 0;
        s->unk40 = 0;
    }
    t = p->unk2;
    if (t < 8) {
        v = t * 12;
    } else if (t >= 0x39) {
        v = 0x60 - (t - 0x39) * 12;
    } else {
        v = 0x60;
    }
    s->unk3C = v;
    do {
        func_801B05E8(s);
    } while (0);
    if (p->unk2 >= 0x41) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2 += 1;
    }
}

void func_801B0B00(void) {
    MgVec v;
    MgVec u;
    MgVec w;
    MgMat m;
    MgTask *p;
    MgTask *q;
    s32 a;
    s32 i;
    s32 r;
    s32 c;
    s32 k;

    p = &D_80162978[D_8015169C];
    v.vx = D_80158D00.vx - p->unk4;
    v.vy = 0;
    v.vz = D_80158D00.vz - p->unk8;
    func_8003A08C(&v, (MgVec *)&D_801E374C);
    func_801B0158(func_801B007C(&D_801CB72C, (MgVec *)&D_801E374C, &w), &D_801E375C, &w);
    u.vx = D_80158D00.vx - p->unk4;
    u.vy = D_80158D00.vy - p->unk6;
    u.vz = D_80158D00.vz - p->unk8;
    func_8003A08C(&u, &u);
    func_801B0158(func_801B007C((MgVec *)&D_801E374C, &u, &w), &m, &w);
    func_8003B16C(&m, &D_801E375C);
    if (D_80062D98 == 0) {
        if (p->unk2 == 2) {
            p->unk1C = 1;
            q = &D_80162978[func_800BBEAC((void *)func_801B08B4)];
            *(HmB8 *)&q->unk4 = *(HmB8 *)&D_80151A4C[D_801E3748];
            q->unk6 -= 0x960;
            q->unk14 = p->unk14;
            q->unk16 = 0xC80;
        }
        if ((u16)(p->unk2 - 0x3A) < 3U) {
            k = 0xC80;
            i = 0;
loop:
            do {
                q = &D_80162978[func_800BBEAC((void *)func_801B0494)];
                *(HmB8 *)&q->unk4 = *(HmB8 *)&D_80151A4C[D_801E3748];
                a = func_80042DA8() % 0x1000;
            } while (0);
            r = func_80042DA8() % 80 + 0xC8;
            i++;
            q->unk4 += func_80039A74(a) * r >> 12;
            q->unk8 += func_80039B40(a) * r >> 12;
            r = func_80042DA8() % 50 + 0x50;
            q->unkC = func_80039A74(a) * r >> 12;
            q->unk10 = func_80039B40(a) * r >> 12;
            r = func_80042DA8() % 0x600 + 0xA00;
            q->unk14 = k * r >> 12;
            if (i < 0x10) {
                goto loop;
            }
        }
        if (p->unk2 < 8) {
            D_800F5B70.v = 0x40;
            D_800F5B71.v = D_800F5B72.v = 0;
            c = p->unk2 << 8;
        } else if (p->unk2 >= 0x3E) {
            c = 0x800 - ((p->unk2 - 0x3E) << 8);
        } else {
            c = 0x800;
        }
        if (p->unk2 == 0x41) {
            for (i = 0; i < 10; i++) {
                if ((1 << i) & D_801E3744) {
                    func_800D5774(i);
                }
            }
        }
        if (p->unk2 >= 0x46) {
            c = 0;
            D_800F5B70.v = 0;
            p->unk0 = -1;
            func_800D55F4(0x28, func_800D56A8(&p->unk4), 0);
        }
        D_800F5B74.v = c;
        p->unk2++;
    }
}

void func_801B1014(void) {
    MgTask *p;
    MgTask *b;
    s16 *q;
    s32 t;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    p = &b[func_800BBEAC((void *)func_801B0B00)];
    q = &p->unk4;
    func_800D3994(D_801E3748, D_8015190F[D_801E3748][0], q);
    t = D_801518F6[D_801E3748][0] + 0x180;
    if (t >= 0x76D) {
        t = 0x76C;
    }
    p->unk14 = t;
    p->unk1C = 0;
    func_800D55F4(0x28, func_800D56A8(q), 0x128);
    func_800D55F4(0x29, func_800D56A8(q), 0x1AA);
}

INCLUDE_RODATA("../asm/us/magic_hmoon/nonmatchings/text", D_801B0000);

void func_801B1140(arg0, arg1) {
    D_801E3740 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B11CC, 0, 0, 0);
    func_800BBEAC(&func_801B1014);
    D_801E3744 = arg0;
    D_801E3748 = arg1;
}
