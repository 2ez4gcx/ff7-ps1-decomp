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

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0110);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0130);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0150);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0170);

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

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0D40);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B0F3C);

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

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B135C);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B17C0);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B18C4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B1A38);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B1BEC);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B1CD8);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B1DB0);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2094);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2378);

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

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2670);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2758);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B286C);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2980);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2B10);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2CEC);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B2F08);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B3354);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B36F4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B3B84);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B416C);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B4798);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B4F70);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B54E8);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B5C74);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B6938);

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

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B6EA4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B7090);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B7294);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B7574);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B7F28);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B8128);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B8380);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B872C);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B96B4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801B9D18);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BA1A8);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BADB8);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BB144);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BB364);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BB568);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BB734);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BBA30);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BCCD4);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BCD54);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BCD98);

INCLUDE_ASM("../asm/us/magic_tifa/nonmatchings/text", func_801BCE2C);
