#include "common.h"
#include "magic_tifa/decls.h"

M2C_UNK *func_801B0088(void) {
    func_801BCD98();
    return &D_801CDC20;
}

void func_801B00B0(s32 a, s32 b) {
    func_801BCE2C(a, b, 1);
}

void func_801B00D0(s32 a, s32 b) {
    func_801BCE2C(a, b, 2);
}

void func_801B00F0(s32 a, s32 b) {
    func_801BCE2C(a, b, 3);
}

void func_801B0110(s32 arg0, s32 arg1) {
    func_801BCE2C(arg0, arg1, 4);
}

void func_801B0130(s32 arg0, s32 arg1) {
    func_801BCE2C(arg0, arg1, 5);
}

void func_801B0150(s32 arg0, s32 arg1) {
    func_801BCE2C(arg0, arg1, 6);
}

void func_801B0170(s32 arg0, s32 arg1) {
    func_801BCE2C(arg0, arg1, 7);
}

s32 func_801B0190(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B026C(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B03E8(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B04C4(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B05A8);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0750);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B07C8);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B09FC);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0CA4);

void func_801B0D40(TfObj2 *o, s32 arg1, s32 arg2) {
    TfPolyG4 *p;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    s32 k;
    s32 t;

    t = 0x1000 / arg2 * arg1;
    func_8003B69C(o->unkB4, o->unkB5, o->unkB6);
    func_8003B710(&o->unkB8, t, &o->unkBC);
    c0 = o->unkBC;
    c1 = o->unkC0;
    func_8003B69C(o->unkC4, o->unkC5, o->unkC6);
    func_8003B710(&o->unkC8, t, &o->unkCC);
    c2 = o->unkCC;
    c3 = o->unkD0;
    p = (TfPolyG4 *)D_801F3D50;
    k = (o->unk24 + o->unk28) >> 3;
    *(s32 *)((u8 *)p + 8) = o->unk74;
    *(s32 *)((u8 *)p + 0x10) = o->unk7C;
    *(s32 *)((u8 *)p + 0x18) = o->unk94;
    *(s32 *)((u8 *)p + 0x20) = o->unk9C;
    *(s32 *)((u8 *)p + 4) = c0;
    *(s32 *)((u8 *)p + 0xC) = c2;
    *(s32 *)((u8 *)p + 0x14) = c1;
    *(s32 *)((u8 *)p + 0x1C) = c3;
    p->tag.len = 8;
    ((u8 *)p)[7] = 0x3A;
    p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
    ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
    p++;
    *(s32 *)((u8 *)p + 8) = o->unk7C;
    *(s32 *)((u8 *)p + 0x10) = o->unk78;
    *(s32 *)((u8 *)p + 0x18) = o->unk9C;
    *(s32 *)((u8 *)p + 0x20) = o->unk98;
    *(s32 *)((u8 *)p + 4) = c2;
    *(s32 *)((u8 *)p + 0xC) = c0;
    *(s32 *)((u8 *)p + 0x14) = c3;
    *(s32 *)((u8 *)p + 0x1C) = c1;
    p->tag.len = 8;
    ((u8 *)p)[7] = 0x3A;
    p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
    ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
    p++;
    D_801F3D50 = (MgLineG2 *)p;
}

void func_801B0F3C(TfObj *o, s32 arg1, s32 arg2) {
    TfPolyG4 *p;
    s32 c0;
    s32 c1;
    s32 k;
    s32 t;

    t = 0x1000 / arg2 * arg1;
    func_8003B69C(o->unkB4, o->unkB5, o->unkB6);
    func_8003B710(&o->unkB8, t, &o->unkBC);
    c0 = o->unkBC;
    c1 = o->unkC0;
    p = (TfPolyG4 *)D_801F3D50;
    k = (o->unk24 + o->unk28) >> 3;
    *(s32 *)((u8 *)p + 8) = o->unk74;
    *(s32 *)((u8 *)p + 0x10) = o->unk78;
    *(s32 *)((u8 *)p + 0x18) = o->unk94;
    *(s32 *)((u8 *)p + 0x20) = o->unk98;
    *(s32 *)((u8 *)p + 4) = c0;
    *(s32 *)((u8 *)p + 0xC) = c0;
    *(s32 *)((u8 *)p + 0x14) = c1;
    *(s32 *)((u8 *)p + 0x1C) = c1;
    p->tag.len = 8;
    ((u8 *)p)[7] = 0x3A;
    p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
    ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
    p++;
    D_801F3D50 = (MgLineG2 *)p;
}

void func_801B107C(MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;
    MgTag *ot;
    s32 otz;
    s32 sxy;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801F3D50;
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
    D_801F3D50 = p;
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B1180);

void func_801B11D8(MgRing *r, s32 v) {
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

void func_801B1258(MgTask *arg0, MgSVec *arg1, MgSVec *arg2) {
    MgSVec v;
    MgMat m1;
    MgMat m2;
    s16 *q;

    q = &D_800FA650;
    v.vx = arg0->unk14 - *q;
    v.vy = arg0->unk18 - D_800FA654;
    v.vz = arg0->unk1C - D_800FA658;
    func_8003BF3C((MgSVec *)(q - 10), &m1);
    func_8003B2CC(&m1, &v, &v);
    func_8003A79C(&m1, arg0, &m2);
    func_8003B2CC(&m2, arg1, arg2);
    arg2->vx += v.vx;
    arg2->vy += v.vy;
    arg2->vz += v.vz;
}

void func_801B135C(s16 *a, u16 *b) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    s32 sp48;
    s32 sp4C;
    s32 q1;
    s32 q2;
    s32 c;

    q1 = a[2] / (s16)b[2];
    c = (s16)D_80151A46[D_801F3D5C][0] + 0x800 & 0xFFF;
    q2 = a[3] / (s16)b[3];
    if (c) {
        rot.vx = 0x400;
        rot.vy = 0x800;
        rot.vz = 0;
        m.t[0] = a[0] / q1;
        m.t[1] = -(a[1] / q2);
    } else {
        rot.vx = 0x400;
        rot.vy = 0;
        rot.vz = 0;
        m.t[0] = -(a[0] / q1);
        m.t[1] = a[1] / q2;
    }
    m.t[2] = 0x200;
    func_8003BF8C(&rot, &m);
    sc.vx = 0x1000 / q1;
    sc.vy = 1;
    sc.vz = 0x1000 / q2;
    func_8003B35C(&m, &sc);
    func_80044AC0((s32)D_801F3C9C, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801F3C9C);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801F3B34);
    func_8003B64C(&sp48, &sp4C);
    func_8003B6BC((s16)b[2] / 2, (s16)b[3] / 2);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk4 = D_8016209C;
    *(s32 *)0x1F80000C = 0;
    *(s32 *)0x1F800014 = 1;
    *(MgLineG2 **)0x1F800010 = D_801F3D50;
    *(s32 *)0x1F800008 = D_801517C0 + 0x4084;
    func_8003B69C(D_800F5B70, D_800F5B71, D_800F5B72);
    D_801F3D50 = func_801B0CA4((void *)0x1F800000, 0x100);
    func_8003B6BC(sp48, sp4C);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801F3B5C);
    func_80044978(D_801F3CDC, b);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801F3CDC);
    D_801F3CF4.v = b[0];
    D_801F3CF6.v = b[1];
    func_800449FC(D_801F3CE8, &D_801F3CF4);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801F3CE8);
}

void func_801B17C0(s16 arg0, s16 *arg1, s16 *arg2) {
    MgSVec v;
    s32 lo;
    s32 hi;
    s32 t;
    s32 i;

    lo = 0x7FFF;
    hi = -0x8000;
    for (i = 0; i < D_801518F4[arg0][0]; i++) {
        func_800D3994(arg0, i, &v);
        t = v.vy;
        if (t < lo) {
            lo = t;
        }
        if (hi < t) {
            hi = t;
        }
    }
    *arg1 = lo;
    *arg2 = hi;
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B18C4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B1A38);

void func_801B1BEC(s32 n, s32 r) {
    s32 i;
    s32 step;
    s32 t;

    step = 0x1000 / n;
    for (i = 0; i < n; i++) {
        D_801F5034[i].vx = r * func_80039B40(i * step) >> 12;
        t = r * func_80039A74(i * step);
        D_801F5034[i].vz = 0;
        D_801F5034[i].vy = t >> 12;
    }
}

void func_801B1CD8(s32 n, s32 r, MgSVec *d) {
    MgSVec *p;
    s32 i;
    s32 step;
    s32 t;

    step = 0x1000 / n;
    for (i = 0; i < n; i++) {
        p = &d[i];
        p->vx = r * func_80039B40(i * step) >> 12;
        t = r * func_80039A74(i * step);
        p->vz = 0;
        p->vy = t >> 12;
    }
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B1DB0);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2094);

void func_801B2378(s32 arg0) {
    u16 v[3];
    s32 r1;
    s32 r2;
    s32 r3;
    s32 k1;
    s32 k3;

    if (arg0 != 0) {
        func_800D3994(D_801F3D5C, 0x17, v);
    } else {
        func_800D3994(D_801F3D5C, 0x10, v);
    }
    func_800D3F0C(v, 0x1000, 0x1000);
    r1 = func_80042DA8();
    k1 = v[0] - 0x32;
    v[0] = k1 + r1 % 100;
    r2 = func_80042DA8();
    v[1] += r2 % 30;
    r3 = func_80042DA8();
    k3 = v[2] - 0x32;
    v[2] = k3 + r3 % 100;
    func_800D3F0C(v, 0x1000, 0x1000);
}

void func_801B24A8(void) {
    MgTask *p;
    s16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801F3B7C;
    *frame = p->unk2 | 0x8000;
    D_801F3B7E.v = p->unk18 << 6;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -(t >> 3));
    D_801F3D50 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801F3D50);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B258C(void) {
    MgTask *p;
    s16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801F3B88;
    *frame = p->unk2 | 0x8000;
    D_801F3B8A.v = p->unk18 << 6;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -(t >> 3));
    D_801F3D50 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801F3D50);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2670(void) {
    MgTask *p;
    s16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801F3B94;
    *frame = p->unk2 | 0x8000;
    D_801F3B96.v = p->unk18 << 6;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -(t >> 3));
    D_801F3D50 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801F3D50);
    if (p->unk2 >= p->unk1A) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2758(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unkC * D_801F3B98[p->unk2];
    func_800D4368(&p->unk4, (s16)(t << 4 >> 16), -(t >> 16));
    ((MgScratch *)0x1F800000)->unk0 = D_801C83D8;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801F3D50 = (MgLineG2 *)func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= 4) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B286C(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = p->unkC * D_801F3BAC[p->unk2];
    func_800D4368(&p->unk4, (s16)(t << 4 >> 16), -(t >> 16));
    ((MgScratch *)0x1F800000)->unk0 = D_801C83D8;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801F3D50 = (MgLineG2 *)func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= 2) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B2980(void) {
    MgTask *p;
    MgMat *m;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 k;
    s16 t;

    p = &D_80162978[D_8015169C];
    t = p->unkC;
    m = func_800D4368(&p->unk4, t, -(t >> 3));
    if (p->unk2 >= p->unk1A) {
        k = 0x1000 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    } else {
        k = 0;
    }
    sp10 = 0x785858;
    sp18 = 0x280202;
    func_8003B69C(0, 0, 0);
    func_8003B710(&sp10, k, &sp14);
    func_8003B710(&sp18, k, &sp1C);
    if (m->t[2] > 0) {
        func_801B1A38((void *)0x1F800000, 0x20, sp14, sp1C);
    }
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE >> 2;
        p->unk2++;
    }
}

void func_801B2B10(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unkC;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801CA730;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    func_8003B69C(0, 0, 0);
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
    }
}

void func_801B2CEC(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unkC;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801CA730;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    func_8003B69C(0, 0, 0);
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE / p->unk12;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2F08);

void func_801B3354(void) {
    MgSVec pos;
    MgSVec pos2;
    MgVec v;
    MgMat m;
    s32 otz;
    s32 flag;
    MgTask *p;
    u8 *pkt;
    u8 *ot;
    s32 n;
    s32 k;

    p = &D_80162978[D_8015169C];
    k = p->unk18;
    pos.vx = D_801F3D60.vx + (k * p->unk4 >> 12);
    pos.vy = D_801F3D60.vy + (k * p->unk6 >> 12);
    pos.vz = D_801F3D60.vz + (k * p->unk8 >> 12);
    k = p->unk14;
    pos2.vx = pos.vx + (k * p->unkC >> 12);
    pos2.vy = pos.vy + (k * p->unkE >> 12);
    pos2.vz = pos.vz + (k * p->unk10 >> 12);
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    pkt = (u8 *)D_801F3D50;
    n = func_8003BD1C(&D_801F3D60, &pos, (s16 *)&pos2, pkt + 8, pkt + 0x10, pkt + 0x18, &otz, &flag);
    if (n > 0) {
        *(s32 *)(pkt + 4) = 0xA08080;
        *(s32 *)(pkt + 0xC) = 0x40404;
        *(s32 *)(pkt + 0x14) = 0x40404;
        pkt[3] = 6;
        pkt[7] = 0x32;
        ot = (u8 *)((n >> 2) * 4 + D_801517C0);
        *(u32 *)pkt = (*(u32 *)pkt & 0xFF000000) | (*(u32 *)(ot + 0x70) & 0xFFFFFF);
        *(u32 *)(ot + 0x70) = (*(u32 *)(ot + 0x70) & 0xFF000000) | ((u32)pkt & 0xFFFFFF);
        pkt += 0x1C;
    }
    D_801F3D50 = (MgLineG2 *)pkt;
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < p->unk1C >> 1) {
            p->unk14 += p->unk16;
        } else {
            p->unk14 -= p->unk16;
        }
        p->unk18 += p->unk1A;
        v.vx = p->unk4;
        v.vy = p->unk6;
        v.vz = p->unk8;
        func_801B026C(func_80042DA8() % 60 + 0x1E, &m, &v);
        func_8003B2CC(&m, (MgSVec *)&p->unkC, (MgSVec *)&p->unkC);
        if (p->unk1E != 0) {
            k = p->unkA;
            pos.vx += k * p->unkC >> 12;
            pos.vy += k * p->unkE >> 12;
            pos.vz += k * p->unk10 >> 12;
            pos.vx -= D_801F3D60.vx;
            pos.vy -= D_801F3D60.vy;
            pos.vz -= D_801F3D60.vz;
            func_8003A0B8(&pos, (MgSVec *)&p->unk4);
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B36F4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B3B84);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B416C);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B4798);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B4F70);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B54E8);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B5C74);

void func_801B6938(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    s32 k;
    s32 h;
    s32 kk;
    u16 t;
    s32 i;

    if (D_80062D98 == 0) {
        b = D_80162978;
        p = &b[D_8015169C];
        if (p->unk2 == 0) {
            q = &b[func_800BBEAC(func_801B5C74)];
            q->unk14 = p->unk14;
        }
        if (p->unk2 == 0x24) {
            func_800D55F4(0x20, func_800D56A8(D_801F5360), 0xE7);
        }
        if (p->unk2 == 0x2A) {
            i = D_801518F4[p->unk14][1] + 0x140;
            q = &b[func_800BBEAC(func_801B2B10)];
            *(MgB8 *)&q->unk4 = *(MgB8 *)D_801F5360;
            q->unk18 = 0xA;
            q->unk6 = 0;
            q->unk1A = 6;
            q->unkC = q->unkE = (i << 12) / 3600;
            func_800D55F4(0x20, func_800D56A8(D_801F5360), 0x14);
        }
        if ((u32)((u16)p->unk2 - 0x2A) < 2) {
            k = D_801518F4[p->unk14][1] + 0x140;
            h = k >> 1;
            kk = k * 2;
            if (h < 0x140) {
                h = 0x140;
            }
            i = 0;
            do {
                i++;
                q = &D_80162978[func_800BBEAC(func_801B258C)];
                q->unk4 = *(u16 *)&D_801F5360[0] + func_80042DA8() % kk - k;
                q->unk6 = -(func_80042DA8() % k);
                q->unk8 = *(u16 *)&D_801F5360[4] + func_80042DA8() % kk - k;
                q->unkC = h * (func_80042DA8() % 2560 + 0x800 << 4) >> 12;
                q->unk18 = 0;
            } while (i < 6);
        }
        if (p->unk2 == 0x22) {
            func_800D3E8C(D_801F3D5C);
            func_801B2378(1);
        }
        t = p->unk2;
        if ((u32)(t - 0x2B) < 4) {
            D_800FA666 = (t & 1) * 5 << 5;
        }
        if (p->unk2 == 0x2B) {
            func_800D5774(p->unk14);
        }
        if (p->unk2 >= 0x2F) {
            D_800FA666 = 0;
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B6D34(void) {
    MgTask *p;
    MgByte *q;
    s32 c;
    s32 t;
    s16 v;

    p = &D_80162978[D_8015169C];
    if (p->unk2 < p->unk1E) {
        if (D_80062D98 == 0) {
            p->unk2++;
        }
        return;
    }
    t = p->unk2;
    if (t >= 2) {
        c = -0x80 - (t - 2) * 0x10;
    } else {
        c = 0x80;
    }
    q = &D_801F3BBC;
    D_801F3BBE.v = c;
    D_801F3BBD.v = c;
    q->v = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 3));
    D_801F3D50 = func_800D4D90((u8 *)q - 4, D_801517C0 + 0x70, 0xC, D_801F3D50);
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk6 += p->unkE;
        p->unkE += p->unk12;
        if (p->unkE > 0) {
            p->unkE >>= 1;
        }
        p->unk12 += p->unk12 >> 5;
        p->unk2++;
    }
}

void func_801B6EA4(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unkC;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801CB46C;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - 0x80 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE >> 3;
        p->unk2++;
    }
}

void func_801B7090(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vz = p->unkC;
    v.vy = p->unk10;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801CB0D8;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - 0x80 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE >> 3;
        p->unk10 += p->unk12;
        p->unk2++;
    }
}

void func_801B7294(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;
    TfScratch *s;
    s32 t;
    s32 k;
    s32 u;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk18;
    rot.vy = D_80151A46[D_801F3D5C][0] + 0x800;
    rot.vz = 0;
    func_8003C21C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk14;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    s = (TfScratch *)0x1F800000;
    t = p->unk2;
    if (t >= 0xD) {
        t = 0xC;
    }
    u = D_801F3B00[t];
    ((TfScratch *)0x1F800000)->unk4 = D_801BD138;
    ((TfScratch *)0x1F800000)->unkC = 0xC;
    s->unk0 = u;
    ((TfScratch *)0x1F800000)->unk8 = D_801517C0 + 0x70;
    ((TfScratch *)0x1F800000)->unk10 = D_801F3D50;
    if (p->unk2 >= p->unk1E) {
        k = 0x1000 / (p->unk1C - p->unk1E) * (p->unk2 - p->unk1E);
    } else {
        k = 0;
    }
    func_8003B69C(0, 0, 0);
    D_801F3D50 = func_801B0750(s, k);
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkE += p->unk12;
        if (p->unkE > 0) {
            p->unkE = p->unkE >> 2;
        }
        p->unk12 += p->unk12 / 14;
        if (p->unk2 >= 8) {
            p->unk18 += p->unk1A;
            p->unk1A += 5;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B7574);

void func_801B7F28(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unkC;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801CAD44;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - 0x80 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
        p->unkE -= p->unkE / 6;
    }
}

void func_801B8128(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk10;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unkC;
    v.vy += p->unkC >> 2;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801C76EC;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = p->unk16;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - 0x80 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unkE -= p->unkE / 6;
        p->unk10 += p->unk12;
        p->unk2++;
        p->unk12 -= p->unk12 / 6;
    }
}

void func_801B8380(void) {
    MgSVec rot;
    MgMat m2;
    MgMat m;
    MgVec sc;
    MgVec v;
    MgVec w;
    MgSVec loc;
    MgTask *p;
    s32 k;
    s32 ang;
    s16 q;

    p = &D_80162978[D_8015169C];
    *(MgB8 *)&loc = *(MgB8 *)&D_80151A4C[p->unk14];
    v.vx = D_801F5334 - D_80151A4C[p->unk14].vx;
    v.vy = D_801F5336 - D_80151A4C[p->unk14].vy;
    v.vz = D_801F5338 - D_80151A4C[p->unk14].vz;
    func_8003A08C(&v, &v);
    ang = func_801B0190(&D_801F3BF4, &v, &w);
    func_801B026C(ang, &m, &w);
    q = (s16)p->unkC / 3;
    k = q * 2;
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m2);
    m2.t[0] = loc.vx + (k * v.vx >> 12);
    m2.t[1] = loc.vy + (k * v.vy >> 12) - D_801F534A + D_801F5352;
    m2.t[2] = loc.vz + (k * v.vz >> 12);
    func_8003B16C(&m, &m2);
    sc.vx = sc.vy = sc.vz = (p->unkC << 12) / 840;
    func_8003B35C(&m2, &sc);
    func_8003A63C(&D_800FA63C, &m2, &m2);
    func_8003B48C(&m2);
    func_8003B51C(&m2);
    ((MgScratch *)0x1F800000)->unk0 = D_801C8C94;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = (p->unk2 & 1) << 6;
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B872C);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B96B4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B9D18);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BA1A8);

void func_801BADB8(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgVec v;
    MgTask *p;
    s32 lim;
    s32 k;
    s32 n;
    s32 t;
    s32 u;
    s32 w;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unkC;
    rot.vy = 0;
    rot.vz = p->unk10;
    func_8003BF8C(&rot, &m1);
    m1.t[0] = p->unk4;
    w = p->unk6;
    m1.t[1] = w;
    m1.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk14;
    func_8003B35C(&m1, &v);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    u = D_801F3C04[p->unk18];
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = (void *)u;
    func_8003B69C(0, 0, 0);
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    lim = 0x184000;
    if (D_800F8368 == 0) {
        lim = 0x168000;
    }
    lim += 0x1B000;
    if ((D_80163C74 & 0x7FFFFFFF) < lim) {
        rot.vx = 0;
        rot.vy = p->unkA;
        rot.vz = 0;
        func_8003BF8C(&rot, &m2);
        m2.t[0] = p->unk4;
        m2.t[1] = 0;
        m2.t[2] = p->unk8;
        n = p->unk1C;
        t = p->unk2;
        if (t < n - 4) {
            k = p->unk14;
        } else {
            lim = p->unk14;
            w = lim / 4;
            u = t + 4;
            u -= n;
            k = lim - w * u;
        }
        v.vx = v.vz = k;
        v.vy = 0;
        func_8003B35C(&m2, &v);
        func_8003A63C(&D_800FA63C, &m2, &m2);
        func_8003B48C(&m2);
        func_8003B51C(&m2);
        u = D_801F3C04[p->unk18];
        ((MgScratch *)0x1F800000)->unk4 = 0x80;
        ((MgScratch *)0x1F800000)->unkA = 0x1000;
        ((MgScratch *)0x1F800000)->unk8 = 0;
        ((MgScratch *)0x1F800000)->unkC = 0x20;
        ((MgScratch *)0x1F800000)->unkE = 0;
        ((MgScratch *)0x1F800000)->unk0 = (void *)u;
        func_8003B69C(0, 0, 0);
        D_80163C74 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_80163C74);
    }
    if (p->unk6 > 0) {
        p->unk0 = -1;
    }
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk6 += p->unkE;
        p->unkE += p->unk12;
        p->unk12 += p->unk12 >> 4;
        p->unkC += p->unk16;
        p->unk2++;
        p->unk10 += p->unk1A;
    }
}

void func_801BB144(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk10;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vz = p->unkC;
    v.vy = p->unkA;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801CC2B4;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    func_8003B69C(0, 0, 0);
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk10 += p->unk12;
        p->unk2++;
        p->unkE -= p->unkE / 6;
    }
}

void func_801BB364(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk10;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unkC;
    func_8003B35C(&m, &v);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801CBB20;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= p->unk1A) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - 0x80 / (p->unk18 - p->unk1A) * (p->unk2 - p->unk1A);
    }
    D_801F3D50 = (MgLineG2 *)func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, (s32)D_801F3D50);
    if (p->unk2 >= p->unk18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk2++;
        p->unkE -= p->unkE / 6;
    }
}

void func_801BB568(void) {
    MgTask *p;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 t;
    s32 k;
    s16 v;
    u8 pad[1];

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (p->unk2 < 0xC) {
        if (D_80062D98 == 0) {
            p->unk2++;
        }
        return;
    }
    k = 0;
    if (t >= 0x54) {
        k = (t - 0x54) << 10;
    }
    sp10 = 0x108888;
    sp18 = 0x404;
    func_8003B69C(0, 0, 0);
    func_8003B710(&sp10, k, &sp14);
    func_8003B710(&sp18, k, &sp1C);
    v = p->unkC;
    func_800D4368(D_801F5360, v, -(v >> 4));
    func_801B18C4((void *)0x1F800000, 0x20, sp14, sp1C);
    if (p->unk2 >= 0x58) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        t = p->unk2;
        if (t < 0x12) {
            p->unkC += p->unkE;
        } else if (t < 0x44) {
            p->unkC += (func_80039A74(p->unk10) * 0xF0) >> 12;
            p->unk10 += 0x17C;
        } else {
            p->unkC -= p->unkC >> 3;
            if (p->unkC < 0) {
                p->unkC = 0;
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BB734);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BBA30);

void func_801BCCD4(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    if (p->unk2 >= 5) {
        q = func_800D4FA8(7);
        q->unk10 = 0x1A;
        *(M2C_UNK **)&q->unkC = &D_801D3900;
        p->unk0 = -1;
    }
    p->unk2++;
}

s32 func_801BCD54(s32 arg0) {
    s32 r;
    s32 n;
    s32 i;

    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                r = i;
            }
        }
    }
    return r;
}

void func_801BCD98(void) {
    u8 *a;

    a = (u8 *)&D_801D3900;
    D_801F3D4C = a;
    D_801F3D48 = a + 0x9000;
    func_800D2980(&D_801D3900, 0, 0, 0);
    func_800D2538(&D_801F3C94, &D_801F3C90);
    func_801B1BEC(8, 0x100);
    func_801B1CD8(0x20, 0x200, D_801F5134);
    func_801B1CD8(0x20, 0x180, D_801F5234);
}

void func_801BCE2C(s32 arg0, s32 arg1, s32 arg2) {
    MgTask *p;

    D_801F3D54 = &D_80162978[func_800BBEAC(D_801B0020)];
    switch (arg2) {
    case 1:
        p = &D_80162978[func_800BBEAC(func_801B3B84)];
        break;
    case 2:
        p = &D_80162978[func_800BBEAC(func_801B4798)];
        break;
    case 3:
        p = &D_80162978[func_800BBEAC(func_801B54E8)];
        break;
    case 4:
        p = &D_80162978[func_800BBEAC(func_801B6938)];
        break;
    case 5:
        p = &D_80162978[func_800BBEAC(func_801B7574)];
        break;
    case 6:
        p = &D_80162978[func_800BBEAC(func_801B96B4)];
        break;
    case 7:
        p = &D_80162978[func_800BBEAC(func_801BBA30)];
        D_800FAFDC = 1;
        break;
    case 0:
    default:
        break;
    }
    p->unk14 = func_801BCD54(arg0);
    p->unk16 = arg2;
    p->unk18 = 0;
    D_801F3D58 = arg0;
    D_801F3D5C = arg1;
    D_801F3D70 = 0;
}

INCLUDE_RODATA("../asm/us/magic_tifa/nonmatchings/text", D_801B0020);
