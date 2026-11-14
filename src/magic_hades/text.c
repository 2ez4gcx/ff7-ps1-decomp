#include "common.h"
#include "magic_hades/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801BA978();
    return &D_801DDE34;
}

s32 func_801B0068(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0144(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02C0(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B039C(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0480);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0708);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0B90);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0C24);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B1144);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B140C);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B14A0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B1940);

s32 func_801B19B4(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F7B76[-v];
    }
    return v;
}

s32 func_801B19F0(s32 a, s32 b) {
    s32 i;
    s32 n;
    s32 orig;

    orig = a;
    if (b > 0) {
        n = b >> 8;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
    } else if (b < 0) {
        b = -b;
        n = b >> 8;
        a = 0x1000 - a;
        for (i = 0; i < n; i++) {
            a = func_80039A74(a / 4);
        }
        a = 0x1000 - a;
    } else {
        return a;
    }
    n = (b & 0xFF) + 1;
    a = (a * n + orig * (0x100 - n)) >> 8;
    return a;
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B1AE8);

void func_801B2B1C(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1AE8)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B2B80(HdObj2 *o, s32 arg1, s32 arg2) {
    HdPolyG4 *p;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    s32 k;
    s32 t;

    t = 0x1000 / arg2 * arg1;
    func_8003B69C(o->bA8, o->bA9, o->bAA);
    func_8003B710(&o->wAC, t, &o->wB0);
    c0 = o->wB0;
    c1 = o->wB4;
    func_8003B69C(o->bB8, o->bB9, o->bBA);
    func_8003B710(&o->wBC, t, &o->wC0);
    p = (HdPolyG4 *)D_80163C74;
    c2 = o->wC0;
    c3 = o->wC4;
    k = (o->w1C + o->w20) >> 3;
    if (k > 0) {
        *(s32 *)((u8 *)p + 8) = o->w68;
        *(s32 *)((u8 *)p + 0x10) = o->w6C;
        *(s32 *)((u8 *)p + 0x18) = o->w88;
        *(s32 *)((u8 *)p + 0x20) = o->w8C;
        *(s32 *)((u8 *)p + 4) = c0;
        *(s32 *)((u8 *)p + 0xC) = c2;
        *(s32 *)((u8 *)p + 0x14) = c1;
        *(s32 *)((u8 *)p + 0x1C) = c3;
        p->tag.len = 8;
        ((u8 *)p)[7] = 0x3A;
        p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
        ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
        p++;
    }
    D_80163C74 = (MgLineG2 *)p;
}

void func_801B2D04(HdObj *o, s32 arg1, s32 arg2, s32 n) {
    HdPolyG4 *p;
    s32 c0;
    s32 c1;
    s32 i;
    s32 j;
    s32 k;

    i = 0x1000 / arg2 * arg1;
    func_8003B69C(o->bA8, o->bA9, o->bAA);
    func_8003B710(&o->wAC, i, &o->wB0);
    p = (HdPolyG4 *)D_80163C74;
    c0 = o->wB0;
    c1 = o->wB4;
    for (i = 0; i < n; i++) {
        j = i + 1;
        if (j >= n) {
            j = 0;
        }
        k = (D_801F74D0[i].pad + D_801F74D0[j].pad) >> 3;
        if (k > 0) {
            *(s32 *)((u8 *)p + 8) = D_801F76D0[i];
            *(s32 *)((u8 *)p + 0x10) = D_801F76D0[j];
            *(s32 *)((u8 *)p + 0x18) = D_801F77D0[i];
            *(s32 *)((u8 *)p + 0x20) = D_801F77D0[j];
            *(s32 *)((u8 *)p + 4) = c0;
            *(s32 *)((u8 *)p + 0xC) = c0;
            *(s32 *)((u8 *)p + 0x14) = c1;
            *(s32 *)((u8 *)p + 0x1C) = c1;
            p->tag.len = 8;
            ((u8 *)p)[7] = 0x3A;
            p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
            ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
            p++;
        }
    }
    D_80163C74 = (MgLineG2 *)p;
}

void func_801B2ED4(HdObj3 *o, s32 arg1, s32 arg2) {
    HdPolyG4 *p;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    s32 k;
    s32 t;

    t = 0x1000 / arg2 * arg1;
    func_8003B69C(o->bA8, o->bA9, o->bAA);
    func_8003B710(&o->wAC, t, &o->wB0);
    c0 = o->wB0;
    c1 = o->wB4;
    func_8003B69C(o->bB8, o->bB9, o->bBA);
    func_8003B710(&o->wBC, t, &o->wC0);
    p = (HdPolyG4 *)D_80163C74;
    c2 = o->wC0;
    c3 = o->wC4;
    k = (o->w1C + o->w20) >> 3;
    if (k > 0) {
        *(s32 *)((u8 *)p + 8) = o->w68;
        *(s32 *)((u8 *)p + 0x10) = o->w70;
        *(s32 *)((u8 *)p + 0x18) = o->w88;
        *(s32 *)((u8 *)p + 0x20) = o->w90;
        *(s32 *)((u8 *)p + 4) = c0;
        *(s32 *)((u8 *)p + 0xC) = c2;
        *(s32 *)((u8 *)p + 0x14) = c1;
        *(s32 *)((u8 *)p + 0x1C) = c3;
        p->tag.len = 8;
        ((u8 *)p)[7] = 0x3A;
        p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
        ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
        p++;
        *(s32 *)((u8 *)p + 8) = o->w70;
        *(s32 *)((u8 *)p + 0x10) = o->w6C;
        *(s32 *)((u8 *)p + 0x18) = o->w90;
        *(s32 *)((u8 *)p + 0x20) = o->w8C;
        *(s32 *)((u8 *)p + 4) = c2;
        *(s32 *)((u8 *)p + 0xC) = c0;
        *(s32 *)((u8 *)p + 0x14) = c3;
        *(s32 *)((u8 *)p + 0x1C) = c1;
        p->tag.len = 8;
        ((u8 *)p)[7] = 0x3A;
        p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
        ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
        p++;
    }
    D_80163C74 = (MgLineG2 *)p;
}

void func_801B30D0(HdObj *o, s32 arg1, s32 arg2) {
    HdPolyG4 *p;
    s32 c0;
    s32 c1;
    s32 k;
    s32 t;

    t = 0x1000 / arg2 * arg1;
    func_8003B69C(o->bA8, o->bA9, o->bAA);
    func_8003B710(&o->wAC, t, &o->wB0);
    c0 = o->wB0;
    c1 = o->wB4;
    p = (HdPolyG4 *)D_80163C74;
    k = (o->w1C + o->w20) >> 3;
    if (k > 0) {
        *(s32 *)((u8 *)p + 8) = o->w68;
        *(s32 *)((u8 *)p + 0x10) = o->w6C;
        *(s32 *)((u8 *)p + 0x18) = o->w88;
        *(s32 *)((u8 *)p + 0x20) = o->w8C;
        *(s32 *)((u8 *)p + 4) = c0;
        *(s32 *)((u8 *)p + 0xC) = c0;
        *(s32 *)((u8 *)p + 0x14) = c1;
        *(s32 *)((u8 *)p + 0x1C) = c1;
        p->tag.len = 8;
        ((u8 *)p)[7] = 0x3A;
        p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
        ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
        p++;
    }
    D_80163C74 = (MgLineG2 *)p;
}

void func_801B3218(MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;
    MgTag *ot;
    s32 otz;
    s32 sxy;
    s32 flag;

    p = D_80163C74;
    otz = func_8003BBDC(v0, &p->x0, &sxy, &flag);
    func_8003BBDC(v1, &p->x1, &sxy, &flag);
    p->tag.len = 4;
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->code = 0x52;
    ot = (MgTag *)D_801517C0 + (otz >> 2) + 0x1C;
    p->tag.addr = ot->addr;
    ot->addr = (u32)p;
    p++;
    D_80163C74 = p;
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B32FC);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3354);

void func_801B3434(HdRot *s, MgSVec *p, s32 n, s32 a3) {
    s32 i;
    s32 step;

    step = 0x1000 / n;
    s->v48.vy = 0;
    s->v48.vx = 0;
    s->v48.vz = a3;
    s->vC8.vz = 0;
    s->vC8.vy = 0;
    s->vC8.vx = 0;
    if (n > 0) {
        i = 0;
        do {
            s->vC8.vy = (u16)s->vC8.vy + step;
            func_8003BF8C(&s->vC8, &s->mD0);
            func_8003B2CC(&s->mD0, &s->v48, &s->v50);
            D_801F74D0[i].vx = (u16)p->vx + (u16)s->v50.vx;
            D_801F74D0[i].vy = (u16)p->vy + (u16)s->v50.vy;
            D_801F74D0[i].vz = (u16)p->vz + (u16)s->v50.vz;
            i++;
        } while (i < n);
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3578);

void func_801B35F0(HdBlk *h, MgSVec *p) {
    s32 start;
    s32 cur;
    s32 num;
    s32 i;
    s32 wrap;

    start = h->start;
    cur = h->cur;
    num = h->num;
    wrap = h->wrap;
    h->pad10 = cur;
    i = cur;
    h->pos[i++] = p;
    num++;
    if (i >= wrap) {
        i = 0;
    }
    if (num >= wrap) {
        num = wrap;
    }
    if (i == start) {
        start++;
        num--;
        if (start >= wrap) {
            start = 0;
        }
    }
    h->cur = i;
    h->start = start;
    h->num = num;
    h->wrap = wrap;
}

void func_801B3664(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &D_801F0C80);
    sc.vx = sc.vy = sc.vz = 0x1000;
    func_8003B35C(&m, &sc);
    ((HdFrame *)0x1F800000)->unk0 = D_801DC62C;
    ((HdFrame *)0x1F800000)->unk8 = 0xC;
    ((HdFrame *)0x1F800000)->unk4 = D_801517C0 + 0x70;
    ((HdFrame *)0x1F800000)->unkC = D_80163C74;
    D_80163C74 = func_801B140C((HdFrame *)0x1F800000, (p->unk2 + 1) << 6);
    if (p->unk2 >= 0x5A) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3768(void) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    sc.vx = sc.vy = sc.vz = 0x1000;
    func_8003B35C(&m, &sc);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((HdFrame *)0x1F800000)->unk0 = D_801DCD98;
    ((HdFrame *)0x1F800000)->unk8 = 0xC;
    ((HdFrame *)0x1F800000)->unk4 = D_801517C0 + 0x70;
    ((HdFrame *)0x1F800000)->unkC = D_80163C74;
    D_80163C74 = func_801B0B90((HdFrame *)0x1F800000, p->unk18);
    if (p->unk2 >= 0x28) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x10) {
            p->unk6 += p->unk1A;
            p->unk18 -= p->unk1A;
        }
        p->unk2++;
    }
}

void func_801B38DC(void) {
    MgTask *p;
    HdBlk *h;
    HdTrail *tr;
    HdScratch *sc;
    s32 s1;
    s32 n;
    s32 i;
    s32 j;
    s32 last;

    sc = (HdScratch *)0x1F800000;
    p = (MgTask *)&D_80162978[D_8015169C];
    h = &D_801F1250[p->unk1C];
    tr = &D_801F34D0[p->unk1C];
    if (D_80062D98 == 0) {
        tr->v[h->cur] = *(MgSVec *)&p->unk4;
        func_801B35F0(h, &tr->v[h->cur]);
    }
    if (p->unk2 == 0) {
        p->unk2 = p->unk2 + 1;
        return;
    }
    sc->wA8 = 0x400202;
    sc->wB0 = 0x787878;
    sc->wAC = 0x787878;
    s1 = h->start;
    last = h->num - 1;
    sc->v38 = *h->pos[s1];
    func_801B3434(sc, &sc->v38, 0x20, p->unk14);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    func_801B3354(sc, 0x20);
    i = 1;
    if (last > 0) {
        do {
            if (s1 >= h->wrap) {
                s1 = 0;
            }
            n = s1 + 1;
            if (n >= h->wrap) {
                n = 0;
            }
            sc->w20 = sc->w1C;
            sc->wB4 = sc->wB0;
            sc->v38 = *h->pos[n];
            for (j = 0; j < 0x20; j++) {
                D_801F77D0[j] = D_801F76D0[j];
                D_801F74D0[j].vy = sc->v38.vy;
            }
            func_801B3354(sc, 0x20);
            func_801B2D04(sc, i, last, 0x20);
            i++;
            s1++;
        } while (i <= last);
    }
    if (p->unk2 >= 0x28) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unk18;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B3BD4);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B40FC);

void func_801B45B4(void) {
    MgObj20 *temp_v0;

    D_800D3544 = 0x140;
    if (D_80062D98 == 0) {
        temp_v0 = &D_80162978[D_8015169C];
        temp_v0->unk2 = (u16) temp_v0->unk2 + 1;
    }
}

void func_801B4600(void) {
    MgObj20 *p;
    s32 t;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0) {
            D_800F5B70 = D_801F0FA4;
        }
        t = p->unk2 * 0x180;
        D_800F5B74.v = t;
        D_800D3546 = t;
        if (p->unk2 >= 7) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B46B0(void) {
    MgObj20 *p;

    func_8003A63C(&D_800FA63C, &D_801F0C60, &D_801F78D8);
    func_8003A63C(&D_801F78D8, &D_801F7938, &D_801F7958);
    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        D_800F5B74.v = 0xC00 - p->unk2 * 0x180;
        if (p->unk2 >= 7) {
            D_800F5B70.b[2] = 0;
            D_800F5B70.b[1] = 0;
            D_800F5B70.b[0] = 0;
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B4798);

void func_801B4CAC(void) {
    MgObj20 *p;
    MgTask *q;
    s32 i;
    s32 t;

    if (D_80062D98 == 0) {
        i = 0;
        p = &D_80162978[D_8015169C];
        do {
            if (p->unk2 == D_801F1004[i]) {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B4798)];
                q->unk14 = func_80042DA8() % 2;
                q->unk16 = q->unk14 ^ 1;
                q->unk18 = func_80042DA8() % 8;
                t = func_80042DA8() % 4;
                q->unk1A = t << 10;
                q->unk1C = i;
            }
            i++;
        } while (i < 4);
        if (p->unk2 >= D_801F1004[3]) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B4DFC);

void func_801B51F0(void) {
    MgObj20 *p;
    MgTask *q;
    HdBlk *h;
    s32 i;

    if (D_80062D98 == 0) {
        i = 0;
        p = &D_80162978[D_8015169C];
        do {
            if (p->unk2 == D_801F102C[i]) {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B4DFC)];
                q->unkE = 0;
                q->unk1C = i;
                h = &D_801F1250[i];
                h->num = 0;
                h->start = 0;
                D_801F1250[i].cur = 0;
                D_801F1250[i].wrap = 0x2C;
            }
            i++;
        } while (i < 2);
        if (p->unk2 >= D_801F102C[1]) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B5310(void) {
    MgMat m;
    u8 pad[8];
    MgTask *p;
    HdPart *base;
    HdPart *q;
    HdPart *r;
    s32 i;
    s32 j;
    s32 ang;
    s32 s0;
    s32 k;
    s32 t;

    i = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    base = (HdPart *)D_801F1240 + p->unk1C * 0x12C;
    do {
        q = &base[i];
        if (q->on != 0) {
            D_801F103C[0] = q->age | 0x8000;
            D_801F103C[1] = 0x40;
            D_801F1040.m[0][0] = D_801F1040.m[1][1] = D_801F1040.m[2][2] = q->sc;
            D_801F1040.t[0] = q->x;
            D_801F1040.t[1] = q->y;
            D_801F1040.t[2] = q->z;
            func_8003A63C(&D_801F78D8, &D_801F1040, &m);
            func_8003B48C(&D_801F1040);
            func_8003B51C(&m);
            D_80163C74 = func_800D4D90((u8 *)D_801F103C - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
            if (D_80062D98 == 0) {
                q->x = (u16)q->x + (u16)q->vx;
                q->z = (u16)q->z + (u16)q->vz;
                q->vx = (u16)q->vx - (q->vx >> 3);
                q->vz = (u16)q->vz - (q->vz >> 3);
                q->sc = (u16)q->sc + 0x10;
                if (q->age >= 0xF) {
                    q->on = 0;
                }
                q->age++;
            }
        }
        i++;
    } while (i < 0x12C);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x48) {
            p->unk0 = -1;
        }
        if (p->unk2 < 0x36) {
            k = 0x1900;
            if (p->unk18 > 0x18) {
                p->unk18 = 0x18;
            }
            p->unk18 = p->unk18 + 1;
            i = 0;
            if (p->unk18 > 0) {
                do {
                    for (j = 0; j < 0x12C; j++) {
                        if (base[j].on == 0) {
                            break;
                        }
                    }
                    if (j >= 0x12C) {
                        break;
                    }
                    r = (HdPart *)(j * 0x18 + (s32)base);
                    r->on = 1;
                    r->age = 0;
                    ang = func_80042DA8() % 0x1000;
                    i++;
                    s0 = func_80042DA8() % 240 + D_801F78D0;
                    r->x = p->unk4 + (func_80039B40(ang) * s0 >> 12);
                    r->y = p->unk6 - func_80042DA8() % 40;
                    r->z = p->unk8 - (func_80039A74(ang) * s0 >> 12);
                    t = func_80042DA8() % 95 + 0xBE;
                    s0 = p->unkE + t;
                    r->vx = func_80039B40(ang) * s0 >> 12;
                    r->vz = -(func_80039A74(ang) * s0 >> 12);
                    ang = func_80042DA8() % 0xD00 + 0x600;
                    r->sc = k * ang >> 12;
                } while (i < p->unk18);
            }
            p->unkE = (u16)p->unkE + (u16)p->unk12;
            if (p->unkE < 0) {
                p->unkE = 0;
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B5790);

void func_801B5B00(void) {
    MgObj20 *p;
    MgTask *q;
    HdCell *c;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 6) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B5790)];
            q->unk12 = 0xFA;
            q->unk10 = 0x4C;
            q->unk16 = 0x78;
            q->unkC = 0;
            q->unkE = 0;
            q->unk18 = 0;
            q->unk14 = 0;
            q->unk1A = 0x9D;
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B5310)];
            q->unk6 = -0x6E;
            q->unkE = 0xBE;
            q->unk12 = -8;
            q->unk8 = 0;
            q->unk4 = 0;
            q->unk18 = 4;
            q->unk1C = 0;
            c = (HdCell *)D_801F1240 + 0x12B;
            for (i = 0x12B; i >= 0; i--) {
                c->unk0 = 0;
                c--;
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B5C1C(void) {
    MgMat m;
    u8 pad[8];
    MgTask *p;
    HdPart *base;
    HdPart *q;
    HdPart *r;
    s32 i;
    s32 j;
    s32 ang;
    s32 s0;
    s32 k;
    s32 t;

    i = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    base = (HdPart *)D_801F1240 + p->unk1C * 0x12C;
    do {
        q = &base[i];
        if (q->on != 0) {
            D_801F1068[0] = q->age | 0x8000;
            D_801F1068[1] = 0x40;
            D_801F106C.m[0][0] = D_801F106C.m[1][1] = D_801F106C.m[2][2] = q->sc;
            D_801F106C.t[0] = q->x;
            D_801F106C.t[1] = q->y;
            D_801F106C.t[2] = q->z;
            func_8003A63C(&D_801F78D8, &D_801F106C, &m);
            func_8003B48C(&D_801F106C);
            func_8003B51C(&m);
            D_80163C74 = func_800D4D90((u8 *)D_801F1068 - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
            if (D_80062D98 == 0) {
                q->x = (u16)q->x + (u16)q->vx;
                q->z = (u16)q->z + (u16)q->vz;
                q->vx = (u16)q->vx - (q->vx >> 3);
                q->vz = (u16)q->vz - (q->vz >> 3);
                q->sc = (u16)q->sc - 8;
                if (q->age >= 0xF) {
                    q->on = 0;
                }
                q->age++;
            }
        }
        i++;
    } while (i < 0x12C);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x24) {
            p->unk0 = -1;
        }
        if (p->unk2 < 0x14) {
            k = 0x1900;
            if (p->unk18 > 5) {
                p->unk18 = 5;
            }
            p->unk18 = p->unk18 + 1;
            i = 0;
            if (p->unk18 > 0) {
                do {
                    for (j = 0; j < 0x12C; j++) {
                        if (base[j].on == 0) {
                            break;
                        }
                    }
                    if (j >= 0x12C) {
                        break;
                    }
                    r = (HdPart *)(j * 0x18 + (s32)base);
                    r->on = 1;
                    r->age = 0;
                    ang = func_80042DA8() % 0x1000;
                    i++;
                    s0 = func_80042DA8() % 90 + 0xB4;
                    r->x = p->unk4 + (func_80039B40(ang) * s0 >> 12);
                    r->y = p->unk6 - func_80042DA8() % 30;
                    r->z = p->unk8 - (func_80039A74(ang) * s0 >> 12);
                    t = func_80042DA8() % 55 + 0x6E;
                    s0 = p->unkE + t;
                    r->vx = func_80039B40(ang) * s0 >> 12;
                    r->vz = -(func_80039A74(ang) * s0 >> 12);
                    ang = func_80042DA8() % 0xB80 + 0x580;
                    r->sc = k * ang >> 12;
                } while (i < p->unk18);
            }
            p->unkE = (u16)p->unkE + (u16)p->unk12;
            if (p->unkE < 0) {
                p->unkE = 0;
            }
        }
        p->unk2++;
    }
}

void func_801B60A0(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    s32 k;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    k = p->unk1C;
    rot.vx = 0;
    rot.vy = D_801F10AC[k];
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    t = (D_801F108C[k] << 12) / 320;
    v.vz = t;
    v.vx = t;
    v.vy = (D_801F109C[k] << 12) / 2805;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_801F78D8, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((HdFrame *)0x1F800000)->unk0 = D_801DCD98;
    ((HdFrame *)0x1F800000)->unk8 = 0xC;
    ((HdFrame *)0x1F800000)->unk4 = D_801517C0 + 0x70;
    ((HdFrame *)0x1F800000)->unkC = D_80163C74;
    D_80163C74 = func_801B0B90((HdFrame *)0x1F800000, p->unk18);
    if (D_801F78D4 < 0) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < p->unk1E) {
            p->unk6 = (u16)p->unk6 + (u16)p->unkE;
            p->unkE = (u16)p->unkE - (p->unkE >> 3);
            if (p->unk6 < 0) {
                p->unk6 = 0;
            }
            p->unk18 = (u16)p->unk18 + (u16)p->unk1A;
            p->unk1A = (u16)p->unk1A - (p->unk1A >> 3);
            if (p->unk18 > 0) {
                p->unk18 = 0;
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B62E0);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B64FC);

void func_801B69C4(void) {
    MgSVec rot;
    MgSVec sv;
    MgMat m1;
    MgMat m2;
    MgVec v;
    MgTask *p;
    MgLineG2 *t;

    rot.vy = 0x264;
    rot.vx = 0;
    rot.vz = 0;
    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m1);
    sv.vx = 0;
    sv.vy = 0x834;
    sv.vz = 0;
    rot.vx = (u16)p->unkC;
    rot.vy = 0x12C;
    rot.vz = 0;
    func_8003C21C(&rot, &m2);
    func_8003B16C(&m2, &m1);
    func_8003B27C(&m2, &sv, (MgVec *)&m1.t[0]);
    v.vx = v.vy = v.vz = 0x1656;
    m1.t[1] -= 0x19C8;
    func_8003B35C(&m1, &v);
    func_8003A63C(&D_801F78D8, (M2C_UNK *)&m1, &D_801F7918);
    func_8003B48C(&D_801F7918);
    func_8003B51C(&D_801F7918);
    ((MgScratch *)0x1F800000)->unk0 = D_801DB700;
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 < 0xC) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - p->unk2 * 0x155;
    }
    func_8003B69C(0, 0, 0);
    t = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_80163C74);
    ((MgScratch *)0x1F800000)->unk0 = D_801DD3B4;
    D_80163C74 = t;
    ((MgScratch *)0x1F800000)->unk4 = 0xA0;
    D_80163C74 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, t);
    if (D_801F78D4 < 0) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC = (u32)(func_80039B40(p->unk12) * 0x19) >> 9;
        p->unk12 = (u16)p->unk12 + 0x40;
        p->unk2++;
    }
}

void func_801B6C34(void) {
    MgObj20 *p;
    MgTask *q;
    s32 i;
    s16 t;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 2) {
            i = 0;
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B69C4)];
            q->unkC = 0xC8;
            q->unk12 = 0x40;
            do {
                q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B64FC)];
                q->unk14 = func_80042DA8() % 2;
                q->unk16 = q->unk14 ^ 1;
                q->unk18 = func_80042DA8() % 8;
                t = func_80042DA8() % 4;
                q->unk1C = i;
                q->unk1A = t << 10;
                i++;
            } while (i < 4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B6D74);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B7270);

void func_801B7594(void) {
    MgTask *p;
    HdBlk *h;
    HdTrail *tr;
    HdScratch *sc;
    s32 s1;
    s32 n;
    s32 i;
    s32 j;
    s32 last;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    sc = (HdScratch *)0x1F800000;
    h = &D_801F1250[p->unk1C];
    tr = &D_801F34D0[p->unk1C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0 || (p->unk2 >= 2 && p->unk2 <= 4)) {
            tr->v[h->cur] = *(MgSVec *)&p->unk4;
            func_801B35F0(h, &tr->v[h->cur]);
        }
    }
    if (p->unk2 == 0) {
        p->unk2 = p->unk2 + 1;
        return;
    }
    sc->wA8 = D_801F117C;
    sc->wAC = sc->wB0 = D_801F1178;
    s1 = h->start;
    last = h->num - 1;
    sc->v38 = *h->pos[s1];
    func_801B3434(sc, &sc->v38, 0x20, 0xBB8);
    func_8003B48C(&D_801F78D8);
    func_8003B51C(&D_801F78F8);
    func_801B3354(sc, 0x20);
    i = 1;
    if (last > 0) {
        do {
            if (s1 >= h->wrap) {
                s1 = 0;
            }
            n = s1 + 1;
            if (n >= h->wrap) {
                n = 0;
            }
            sc->w20 = sc->w1C;
            sc->wB4 = sc->wB0;
            sc->v38 = *h->pos[n];
            for (j = 0; j < 0x20; j++) {
                D_801F77D0[j] = D_801F76D0[j];
                D_801F74D0[j].vy = sc->v38.vy;
            }
            func_801B3354(sc, 0x20);
            func_801B2D04(sc, i, last, 0x20);
            i++;
            s1++;
        } while (i <= last);
    }
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 2) {
            t -= 2;
            if (t < 3) {
                p->unk6 += p->unk1A;
            } else {
                t -= 3;
                if (t < 8) {
                    s1 = (t + 1) << 9;
                    if (s1 > 0x1000) {
                        s1 = 0x1000;
                    }
                    func_8003B69C(D_801F1170[0], D_801F1170[1], D_801F1170[2]);
                    func_8003B710(&D_801F1174, s1, &D_801F117C);
                } else {
                    t -= 8;
                    if (t < 6) {
                        D_801F1174 = *(MgB4 *)D_801F1170;
                    } else {
                        t -= 6;
                        if (t < 10) {
                            s1 = t * 0x199;
                            func_8003B69C(0, 0, 0);
                            func_8003B710(D_801F1170, s1, &D_801F1178);
                            func_8003B710(&D_801F1174, s1, &D_801F117C);
                        } else {
                            p->unk0 = -1;
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801B79A4(void) {
    MgObj20 *p;
    MgTask *q;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 8) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B7594)];
            q->unk1A = -0xD48;
            q->unk8 = 0;
            q->unk4 = 0;
            q->unk6 = 0;
            q->unk1C = 0x1F;
            D_801F33C8 = 5;
            D_801F33C4 = 0;
            D_801F33C0 = 0;
            D_801F33BC = 0;
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B7A70);

void func_801B8014(void) {
    HdCell *q;
    s32 i;

    D_80162978[D_8015169C].unk0 = -1;
    func_800BBEAC((void *)func_801B7A70);
    q = (HdCell *)D_801F1240 + 0xC7;
    for (i = 0xC7; i >= 0; i--) {
        *(s16 *)((u8 *)q + 0x8CA0) = 0;
        q--;
    }
}

void func_801B8084(void) {
    MgObj20 *p;
    MgTask *q;
    s32 t;
    s32 u;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0x1A) {
            q = (MgTask *)func_800D4FA8(1);
            q->unk4 = 0;
            q->unk6 = -0x1B8;
            u = D_801F0C60.t[2];
            if (D_801F0CA0.vy == 0) {
                t = u + 0x36B;
            } else {
                t = u - 0x36B;
            }
            q->unk8 = t;
            q->unk10 = (u16)D_801F0CA0.vy;
            D_80153BBE.v = 0xE00;
            func_800BBEAC((void *)func_801B8014);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B8150(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    s32 t;
    s32 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    if (D_801F78D4 < 0) {
        p->unk0 = -1;
        return;
    }
    rot.vx = 0;
    rot.vy = (u16)p->unkE;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = 0;
    m.t[1] = 0;
    m.t[2] = 0;
    v.vz = 0x1000;
    v.vx = 0x1000;
    v.vy = p->unk14;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_801F7958, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801DAD8C;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = c = 0x80;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t >= 8) {
        ((MgScratch *)0x1F800000)->unkA = c - (t - 8) * 0x15;
    }
    D_80163C74 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (p->unk2 >= 0xE) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkE = p->unkE;
        p->unk14 = (u16)p->unk14 + (u16)p->unk16;
        p->unk2++;
        p->unk16 = (u16)p->unk16 - (p->unk16 >> 3);
    }
}

void func_801B8314(void) {
    MgObj20 *p;
    MgTask *q;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 >= 2 && p->unk2 % 6 == 2) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B8150)];
            q->unkE = 0;
            q->unk16 = 0x400;
            q->unk14 = 0x400;
        }
        if (D_801F78D4 < 0) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8404);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8888);

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B8D48);

void func_801B9378(void) {
    MgTask *p;
    HdPart *base;
    HdPart *r;
    HdSc9 *sc;
    s32 i;
    s32 j;
    s32 n;
    s32 t;
    s32 k;
    u8 pad[8];

    *(MgMat *)0x1F800020 = D_801F7958;
    base = (HdPart *)D_801F1240;
    p = (MgTask *)&D_80162978[D_8015169C];
    sc = (HdSc9 *)0x1F800000;
    sc->w80 = D_801DAC04;
    sc->h4E = 0;
    sc->h4C = 0;
    sc->h4A = 0;
    sc->h46 = 0;
    sc->h44 = 0;
    sc->h42 = 0;
    sc->w84 = 0x2E686868;
    i = 0;
    do {
        sc->arr[i] = D_801F0CE8[i];
        i++;
    } while (i < 0x14);
    func_801B8404(base, (void *)0x1F800000);
    if (p->unk2 >= 0x44) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x28) {
            i = 0;
            k = 0x1810;
            n = (0x50 - p->unk2) / 6 + func_80042DA8() % 6;
            if (n > 0) {
                do {
                    for (j = 0; j < 0x1AE; j++) {
                        if (base[j].on == 0) {
                            break;
                        }
                    }
                    if (j >= 0x1AE) {
                        break;
                    }
                    (r = (HdPart *)(j * 0x18 + (s32)base))->on = func_80042DA8() % 8;
                    r->age = (s16)(r->on + 0x10) + func_80042DA8() % 14;
                    r->x = func_80042DA8() % 8000 - 4000;
                    r->y = func_80042DA8() % 2100 - 0x3AC;
                    r->z = -(func_80042DA8() % 1500 + 0x190);
                    t = func_80042DA8() % 6 + 6;
                    r->vy = 0;
                    r->pad12 = 0;
                    r->vx = 0x80;
                    r->vz = 0x80 / t;
                    r->pad14 = func_80042DA8() % 40 + 0x16;
                    r->sc = k * (func_80042DA8() % 0xE00 + 0x800) >> 12;
                    i++;
                } while (i < n);
            }
        }
        p->unk2++;
    }
}

void func_801B9820(void) {
    MgObj20 *p;
    HdCell *q;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 2) {
            func_800BBEAC((void *)func_801B8888);
            q = (HdCell *)D_801F1240 + 0x1AD;
            for (i = 0x1AD; i >= 0; i--) {
                q->unk0 = 0;
                q--;
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B98BC(void) {
    MgObj20 *p;
    MgObj20 *q;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 2) {
            func_800BBEAC((void *)func_801B8D48);
            q = D_801F1240 + 0x12B;
            for (i = 0x12B; i >= 0; i--) {
                *(s16 *)((u8 *)q + 0x9F60) = 0;
                q--;
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B9960(void) {
    MgObj20 *p;
    MgObj20 *q;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 2) {
            func_800BBEAC((void *)func_801B9378);
            q = D_801F1240 + 0x12B;
            for (i = 0x12B; i >= 0; i--) {
                *(s16 *)((u8 *)q + 0x9F60) = 0;
                q--;
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B9A04);

void func_801B9DD4(s32 arg0) {
    MgB8 tmp;
    MgTask *q;
    s32 i;
    s32 d;
    s32 n;
    s32 u;
    s32 t;
    s32 w;
    s16 h;

    func_800D3994(arg0, D_8015190F[arg0][0], (s16 *)&tmp);
    n = D_801518F6[arg0][0] + 0x100;
    if (n >= 0x76D) {
        n = 0x76C;
    }
    u = (n << 12) / 1250;
    i = 0;
    do {
        q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B9A04)];
        *(MgB8 *)&q->unk4 = tmp;
        q->unkA = func_80042DA8() % 8 + 1;
        d = n * (i + 1);
        q->unk6 += func_80042DA8() % d - (d >> 1);
        q->unkE = 0;
        q->unk12 = func_80042DA8() % 100 + 0x28;
        t = func_80042DA8();
        t %= 0x600;
        w = i * 0x100 + 0x800;
        h = u * (t + w) >> 12;
        q->unk14 = h;
        q->unk16 = h / 20;
        q->unk18 = 0;
        q->unk1C = 0;
        q->unk1A = 5;
        i++;
    } while (i < 1);
}

void func_801BA020(void) {
    MgTask *p;
    MgTask *q;

    if (D_80062D98 == 0) {
        p = (MgTask *)&D_80162978[D_8015169C];
        if ((s16)(p->unk2 % 11) == 0) {
            q = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801B9A04)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
            q->unk6 += func_80042DA8() % p->unk14 - (p->unk14 >> 1);
            q->unkE = func_80042DA8() % 0x1000;
            q->unk12 = func_80042DA8() % 100 + 0x28;
            q->unk14 = 0xE14;
            q->unk16 = 0xB4;
            q->unk1A = 5;
            q->unk18 = 0;
        }
        if (p->unk2 >= 0x2C) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801BA1EC(s32 arg0) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[func_800BBEAC((void *)func_801BA020)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    t = D_801518F6[arg0][0] + 0x100;
    if (t >= 0x76D) {
        t = 0x76C;
    }
    p->unk14 = t;
}

void func_801BA298(void) {
    MgObj20 *p;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 1) {
            func_800D4FA8(2);
            D_801F78D4 |= 0x80000000;
        }
        if (p->unk2 == 2) {
            func_800D5444(D_801F1244, D_801F1248, 2, (void *)func_801BA1EC);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801BA354(void) {
    MgObj20 *p;
    s32 i;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0x2A) {
            i = 0;
            do {
                if ((1 << i) & D_801F1244) {
                    func_800D5774(i);
                }
                i++;
            } while (i < 0xA);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801BA404(void) {
    MgObj20 *p;
    s32 t;

    func_8003A63C(&D_800FA63C, (M2C_UNK *)&D_801F0C60, &D_801F78D8);
    func_8003A63C(&D_801F78D8, (M2C_UNK *)&D_801F7938, &D_801F7958);
    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        t = p->unk2;
        if (t < 5) {
            if (t == 0) {
                func_800BBEAC((void *)func_801B4600);
            }
        } else {
            t -= 5;
            if (t < 0x28) {
                if (t == 0) {
                    func_800BBEAC((void *)func_801B4CAC);
                    func_800BBEAC((void *)func_801B51F0);
                    func_800D55F4(0x22, 0x40, 0x294, 0x295, 0x296);
                }
            } else {
                t -= 0x28;
                if (t >= 0xA) {
                    t -= 0xA;
                    if (t < 0x3C) {
                        if (t == 0) {
                            func_800BBEAC((void *)func_801B5B00);
                        }
                    } else {
                        t -= 0x3C;
                        if (t < 0x3C) {
                            if (t == 0) {
                                func_800BBEAC((void *)func_801B62E0);
                            }
                        } else {
                            t -= 0x3C;
                            if (t < 0x1E) {
                                if (t == 0) {
                                    func_800BBEAC((void *)func_801B6C34);
                                }
                                if (t == 3) {
                                    func_800D55F4(0x22, 0x40, 0x297, 0x298, 0x299);
                                }
                            } else {
                                t -= 0x1E;
                                if (t < 0x1E) {
                                    if (t == 0) {
                                        D_801F124C = 0;
                                        func_800BBEAC((void *)func_801B7270);
                                        func_800BBEAC((void *)func_801B79A4);
                                        func_800BBEAC((void *)func_801B8084);
                                    }
                                } else {
                                    t -= 0x1E;
                                    if (t < 0x30) {
                                        if (t == 0x29) {
                                            func_800D55F4(0x22, 0x40, 0x29A, 0x29B, 0x29C);
                                        }
                                    } else {
                                        t -= 0x30;
                                        if (t >= 0x3E) {
                                            t -= 0x3E;
                                            if (t < 0x1E) {
                                                if (t == 0) {
                                                    func_800BBEAC((void *)func_801B8314);
                                                    func_800BBEAC((void *)func_801B98BC);
                                                }
                                                if (t == 3) {
                                                    func_800D55F4(0x22, 0x40, 0x29D, 0x29E, 0x29F);
                                                }
                                            } else {
                                                t -= 0x1E;
                                                if (t < 0x3E7) {
                                                    if (t == 0) {
                                                        func_800BBEAC((void *)func_801B9960);
                                                        func_800BBEAC((void *)func_801BA298);
                                                        func_800BBEAC((void *)func_801BA354);
                                                    }
                                                    if (t == 0x44) {
                                                        func_800BBEAC((void *)func_801B46B0);
                                                        p->unk0 = -1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

void func_801BA75C(void) {
    MgTask *q;
    MgObj20 *b;
    MgVec v;
    MgSVec loc;
    s32 i;
    s32 j;
    s32 t;
    s32 k;
    u16 w;
    u16 *p;

    D_80162978[D_8015169C].unk0 = -1;
    b = D_80162978;
    q = (MgTask *)&b[func_800BBEAC((void *)func_801BA404)];
    func_800D54EC(D_801F1244, &q->unk4);
    func_8003C21C(&D_801F0CA0, &D_801F7938);
    v.vx = v.vy = v.vz = 0xE00;
    func_8003B35C(&D_801F7938, &v);
    D_801F7938.t[0] = 0;
    D_801F7938.t[1] = -0x681;
    D_801F7938.t[2] = 0;
    t = q->unk8;
    if (t < D_80151A50[D_801F1248][0]) {
        k = t + 0x157C;
        D_801F0C7C.v = k;
    } else {
        D_801F0CA0.vy = 0x800;
        k = q->unk8 - 0x157C;
        D_801F0C7C.v = k;
    }
    func_8003C21C(&D_801F0CA0, &D_801F0C60);
    loc.vx = 0;
    loc.vy = 0x64;
    loc.vz = 0;
    func_8003C21C(&loc, &D_801F0C80);
    p = D_801BAA92;
    for (i = 0; i < 15; i++) {
        w = *p++;
        D_801F7978[i][0] = 0;
        for (j = 0; j < 15; j++) {
            D_801F7978[j][(j + i) % 15 + 1] = w;
        }
    }
    ((void (*)(s32, s32, s32))func_801B2B1C)((s32)D_801F0E38, (s32)&D_801F0C60, D_801F1248);
}

s32 func_801BA978(arg0, arg1) {
    s32 temp_v0;

    func_800D2980(&D_801BA9FC, 0, 0, 0);
    temp_v0 = func_800BBEAC((void *)func_801BA75C);
    D_801F1240 = &D_801BA9FC;
    D_801F1244 = arg0;
    D_801F1248 = arg1;
    D_801F78D4 = 0;
    return temp_v0;
}
