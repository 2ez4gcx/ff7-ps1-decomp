#include "common.h"
#include "magic_night/decls.h"

void func_801B0054(void) {
    func_801B2528();
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

INCLUDE_ASM("../asm/us/magic_night/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_night/nonmatchings/text", func_801B0948);

INCLUDE_ASM("../asm/us/magic_night/nonmatchings/text", func_801B09B8);

INCLUDE_ASM("../asm/us/magic_night/nonmatchings/text", func_801B0E58);

void func_801B0ECC(MgRing *r, s32 v) {
    s32 head;
    s32 tail;
    s32 count;
    s32 size;
    s32 last;

    tail = r->tail;
    last = r->head;
    count = r->count;
    r->prev = r->last;
    size = r->size;
    r->last = last;
    head = last;
    r->buf[head] = v;
    head++;
    count++;
    if (head >= size) {
        head = 0;
    }
    if (count >= size) {
        count = size;
    }
    if (head == tail) {
        tail++;
        count--;
        if (tail >= size) {
            tail = 0;
        }
    }
    r->head = head;
    r->tail = tail;
    r->count = count;
    r->size = size;
}

INCLUDE_ASM("../asm/us/magic_night/nonmatchings/text", func_801B0F4C);

void func_801B14C8(void) {
    MgSVec rot;
    MgMat m;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    NtScr *s;
    s16 k;
    s32 v;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    rot.vx = p->unk10;
    rot.vy = 0;
    rot.vz = p->unk14;
    func_8003BF8C(&rot, &m2);
    func_8003B16C(&m2, &m);
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    s = (NtScr *)0x1F800000;
    s->unk0 = &D_801C3964;
    ((NtScr *)0x1F800000)->unk8 = 0xC;
    ((NtScr *)0x1F800000)->unk4 = D_801517C0 + 0x70;
    ((NtScr *)0x1F800000)->unkC = D_801DBEE0;
    k = p->unk1C / 3;
    if (p->unk2 < k) {
        ((NtScr *)0x1F800000)->unkDC = 0x80;
        ((NtScr *)0x1F800000)->unkDD = 8;
        ((NtScr *)0x1F800000)->unkDE = 0x10;
        ((NtScr *)0x1F800000)->unkE0 = 0x60;
        ((NtScr *)0x1F800000)->unkE1 = 8;
        ((NtScr *)0x1F800000)->unkE2 = 0x80;
        v = (0x1000 / k) * p->unk2;
    } else if (p->unk2 < k * 2) {
        ((NtScr *)0x1F800000)->unkDC = 0x60;
        ((NtScr *)0x1F800000)->unkDD = 8;
        ((NtScr *)0x1F800000)->unkDE = 0x80;
        ((NtScr *)0x1F800000)->unkE0 = 0x10;
        ((NtScr *)0x1F800000)->unkE1 = 8;
        ((NtScr *)0x1F800000)->unkE2 = 0x80;
        v = (0x1000 / k) * (p->unk2 - k);
    } else if (p->unk2 < 9) {
        ((NtScr *)0x1F800000)->unkDC = 0x10;
        ((NtScr *)0x1F800000)->unkDD = 8;
        ((NtScr *)0x1F800000)->unkDE = 0x80;
        ((NtScr *)0x1F800000)->unkE0 = 0x10;
        ((NtScr *)0x1F800000)->unkE1 = 8;
        ((NtScr *)0x1F800000)->unkE2 = 0x80;
        v = 0;
    } else {
        ((NtScr *)0x1F800000)->unkDC = 0x10;
        ((NtScr *)0x1F800000)->unkDD = 8;
        ((NtScr *)0x1F800000)->unkDE = 0x80;
        ((NtScr *)0x1F800000)->unkE0 = 0;
        ((NtScr *)0x1F800000)->unkE1 = 0;
        ((NtScr *)0x1F800000)->unkE2 = 0;
        v = (p->unk2 - 9) << 9;
    }
    D_801DBEE0 = func_801B0E58(s, v);
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk18 += p->unk1A;
        p->unk2++;
        p->unk1A += p->unk1A >> 4;
    }
}

void func_801B1860(void) {
    MgTask *p;
    u16 *frame;
    s16 v;

    p = &D_80162978[D_8015169C];
    frame = &D_801C3EDC;
    *frame = p->unk2 | 0x8000;
    D_801C3EDE.v = p->unk1A;
    v = p->unk18;
    func_800D4368(&p->unk4, v, -(v >> 4));
    D_801DBEE0 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801DBEE0);
    if (p->unk2 >= 8) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1940(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    s32 c;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vz = p->unk10;
    scale.vy = p->unk14;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = &D_801C3350;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x18) {
        ((MgScratch *)0x1F800000)->unkA = c - (p->unk2 - 0x18) * 10;
    }
    D_801DBEE0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DBEE0);
    if (p->unk2 >= 0x24) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE >> 6;
        p->unk10 += p->unk12;
        if (p->unk2 < 0x16) {
            p->unk14 += p->unk16;
        }
        if (p->unk2 == 0) {
            func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x21B);
        }
        p->unk2++;
    }
}

void func_801B1B54(void) {
    MgTask *p;
    MgTask *q;
    u16 t;
    s32 i;
    s32 b;
    s32 a;
    s32 c;
    s32 r;
    s32 r2;
    s16 v;
    s16 w;
    s32 s0;
    NtFx *d;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        t = p->unk2;
        if ((t >= 13) && (t < 21)) {
            if (((s16) t) == 13) {
                func_800D5138(1);
            }
            if (p->unk2 == 15) {
                func_800D51D4(2);
            }
        }
        if (p->unk2 == 21) {
            q = &D_80162978[func_800BBEAC(&func_801B1940)];
            *((MgB8 *) (((u8 *) q) + 4)) = *((MgB8 *) (((u8 *) p) + 4));
            q->unk6 = 0;
            q->unkC = 0;
            q->unkE = 0x120;
            v = (p->unk18 << 12) / 655;
            q->unk10 = v;
            q->unk14 = 0;
            q->unk12 = (v >> 1) / 22;
            w = q->unk10 / 3;
            q->unk16 = w / 11;
        }
        if ((((u16) p->unk2) >= 36) && (((u16) p->unk2) < 57)) {
            v = p->unk18;
            w = v / 3;
            a = w * 2;
            if (a >= 0x4F3) {
                b = 0x4F2;
            } else {
                b = a;
            }
            b <<= 4;
            i = 0;
            c = w * 4;
            do {
                q = &D_80162978[func_800BBEAC(&func_801B1860)];
                i++;
                *((MgB8 *) (((u8 *) q) + 4)) = *((MgB8 *) (((u8 *) p) + 4));
                q->unk4 += (func_80042DA8() % c) - a;
                q->unk6 += (func_80042DA8() % c) - a;
                q->unk8 += (func_80042DA8() % c) - a;
                q->unk18 = (b * ((func_80042DA8() % 0x900) + 0x600)) >> 12;
                q->unk1A = (func_80042DA8() % 3) << 6;
            } while (i < 2);
        }
        t = p->unk2;
        if (((t >= 50) && (t < 65)) && (t & 1)) {
            q = &D_80162978[func_800BBEAC(&func_801B14C8)];
            *((MgB8 *) (((u8 *) q) + 4)) = *((MgB8 *) (((u8 *) p) + 4));
            q->unkC = func_80042DA8() % 0x1000;
            q->unkE = (func_80042DA8() % 170) + 0x80;
            if (q->unkC & 1) {
                q->unkE = -q->unkE;
            }
            q->unk10 = (func_80042DA8() % 0x400) - 0x200;
            q->unk14 = ((p->unk2 * 700) & 0xFFF) + (func_80042DA8() % 500);
            b = (p->unk18 << 12) / 1350;
            q->unk18 = (b * ((func_80042DA8() % 0x600) + 0xB00)) >> 12;
            q->unk1A = b >> 4;
            q->unk1C = (func_80042DA8() % 9) + 0x11;
        }
        if (p->unk2 == 60) {
            i = 0;
            a = p->unk18 + (p->unk18 >> 1);
            do {
                q = &D_80162978[func_800BBEAC(&func_801B0F4C)];
                *((MgB8 *) (((u8 *) q) + 4)) = *((MgB8 *) (((u8 *) p) + 4));
                q->unk6 = -0x6C;
                q->unkA = (func_80042DA8() % 8) + (b = i);
                q->unkC = func_80042DA8() % 0x1000;
                q->unkE = (func_80042DA8() % 120) + 0x46;
                if (q->unkC & 1) {
                    q->unkE = -q->unkE;
                }
                r = func_80042DA8();
                q->unk18 = 0x1851;
                q->unk10 = a + (r % 200);
                r2 = func_80042DA8();
                q->unk1C = b;
                q->unk1E = 0;
                q->unk1A = -((r2 % 50) + 0x1C);
                d = &D_801DBEF4[i];
                d->w[2] = 0;
                d->w[1] = 0;
                D_801DBF00[i].w[0] = 8;
                D_801DBEF4[i].w[0] = 0;
                D_801DBF04[i].w[0] = -1;
                i++;
            } while (i < 4);
        }
        if (p->unk2 == 50) {
            func_800D55F4(0x28, func_800D56A8(&p->unk4), 0x16A);
        } else
            if (p->unk2 == 60) {
            func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x17B);
        } else
            if (p->unk2 == 85) {
            func_800D55F4(0x29, func_800D56A8(&p->unk4), 0);
        }
        if (p->unk2 < 6) {
            D_800F5B72[0] = 0;
            D_800F5B71[0] = 0;
            D_800F5B70[0] = 0;
            s0 = p->unk2 * 341;
        } else
            if (p->unk2 < 0x4D) {
            s0 = 0x800;
        } else {
            s0 = 0x800 - ((p->unk2 - 0x4D) << 8);
        }
        if (p->unk2 == 0x41) {
            func_800D5774(D_801DBEEC);
        }
        if (p->unk2 >= 0x55) {
            s0 = 0;
            p->unk0 = -1;
        }
        D_800F5B74[0] = s0;
        p->unk2++;
    }
}

void func_801B2420(void) {
    MgTask *p;
    MgTask *base;
    s32 n;
    s32 t;

    D_80162978[D_8015169C].unk0 = -1;
    n = func_800BBEAC(&func_801B1B54);
    base = D_80162978;
    p = base + n;
    func_800D3994(D_801DBEEC, D_8015190F[D_801DBEEC][0], &p->unk4);
    t = D_801518F6[D_801DBEEC][0] + 0x1B0;
    if (t >= 0x76D) {
        t = 0x76C;
    }
    p->unk18 = t;
    *(void **)0x1F800000 = &D_801C3350;
    func_801B0948((void *)0x1F800000);
}

INCLUDE_RODATA("../asm/us/magic_night/nonmatchings/text", D_801B0000);

void func_801B2528(mask, arg1) {
    s32 i;
    s32 n;

    D_801DBEE4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B25F4, 0, 0, 0);
    D_801DBEE8 = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801DBEEC = i;
            }
        }
    }
    D_801DBEF0 = arg1;
    func_800BBEAC(&func_801B2420);
}
