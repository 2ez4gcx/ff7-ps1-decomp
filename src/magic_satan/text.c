#include "common.h"
#include "magic_satan/decls.h"

s32 func_801B00E0(void) {
    func_801B664C();
    return 0;
}

s32 func_801B0104(void) {
    func_801B672C();
    return 0;
}

s32 func_801B0128(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0204(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0380(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B045C(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0540);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0818);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B0B5C);

void *func_801B0BF8(SatCtx3 *arg0, u8 *arg1, u16 *arg2) {
    u16 *e;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 r;

    e = (u16 *)((u8 *)arg2 + 4);
    n = arg0->unk2C;
    cnt = *arg2;
    k = 0x4D85C;
    for (i = 0; i < cnt; i++) {
        a = (s16 *)(arg1 + e[0]);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + e[1]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[2]);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 3;
        y /= 3;
        z /= 3;
        D_801E1A6C[n].vy = y;
        y += 0x8CE;
        y = y * y / k;
        D_801E1A6C[n].vx = x;
        D_801E1A6C[n].vz = z;
        D_801E1A6C[n].f6 = y;
        D_801E1A6C[n].f8 = D_801E1A6C[n].fA = D_801E1A6C[n].fC = D_801E1A6C[n].fE = 0;
        y >>= 1;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801E1A6C[n].f10 = (r & 7) * 12;
        } else {
            D_801E1A6C[n].f10 = -((r & 7) * 12);
        }
        D_801E1A6C[n].f12 = 0;
        if (r & 0x204080) {
            D_801E1A6C[n].f14 = ((r >> 3) & 7) * 12;
        } else {
            D_801E1A6C[n].f14 = -(((r >> 3) & 7) * 12);
        }
        D_801E1A6C[n].f16 = -((y + 0x1C) * ((r & 7) + 2));
        n++;
        e += 8;
    }
    arg0->unk2C = n;
    return e;
}

u16 *func_801B0EA8(SatCtx3 *arg0, u8 *arg1, s32 *arg2) {
    u16 *e;
    s16 *a;
    s32 i;
    s32 n;
    s32 cnt;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 r;

    e = (u16 *)(arg2 + 1);
    i = 0;
    n = arg0->unk2C;
    cnt = *arg2;
    k = 0x4D85C;
    for (; i < cnt; i++) {
        a = (s16 *)(arg1 + e[0]);
        x = a[0];
        y = a[1];
        z = a[2];
        a = (s16 *)(arg1 + e[1]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[2]);
        x += a[0];
        y += a[1];
        z += a[2];
        a = (s16 *)(arg1 + e[3]);
        x += a[0];
        y += a[1];
        z += a[2];
        x /= 4;
        y /= 4;
        z /= 4;
        D_801E1A6C[n].vy = y;
        y += 0x8CE;
        y = y * y / k;
        D_801E1A6C[n].vx = x;
        D_801E1A6C[n].vz = z;
        D_801E1A6C[n].f6 = y;
        D_801E1A6C[n].f8 = D_801E1A6C[n].fA = D_801E1A6C[n].fC = D_801E1A6C[n].fE = 0;
        y >>= 1;
        r = func_80042DA8();
        if (r & 0x800) {
            D_801E1A6C[n].f10 = (r & 7) * 12;
        } else {
            D_801E1A6C[n].f10 = -((r & 7) * 12);
        }
        D_801E1A6C[n].f12 = 0;
        if (r & 0x204080) {
            D_801E1A6C[n].f14 = ((r >> 3) & 7) * 12;
        } else {
            D_801E1A6C[n].f14 = -(((r >> 3) & 7) * 12);
        }
        D_801E1A6C[n].f16 = -((y + 0x1C) * ((r & 7) + 2));
        n++;
        e += 10;
    }
    arg0->unk2C = n;
    return e;
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B1178);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B11F8);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B1790);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B1DC0);

u8 *func_801B1E60(SatMdl *m, u8 *base, u8 *blk) {
    u16 *p;
    s32 i;
    s32 n;
    s32 x;
    s32 z;
    s32 *cell;
    s32 old;
    s32 k;
    SatRow *tab;
    s32 r;

    n = *(u16 *)blk;
    p = (u16 *)(blk + 4);
    i = 0;
    if (i < n) {
        do {
            *(MgB8 *)&m->v[0] = *(MgB8 *)(base + p[0]);
            *(MgB8 *)&m->v[1] = *(MgB8 *)(base + p[1]);
            *(MgB8 *)&m->v[2] = *(MgB8 *)(base + p[2]);
            x = m->v[0].vx + m->v[1].vx + m->v[2].vx;
            x /= 3;
            z = m->v[0].vz + m->v[1].vz + m->v[2].vz;
            z /= 3;
            x += 0x888;
            z += 0xE70;
            x /= 0x200;
            z /= 0x200;
            tab = D_801E4B44;
            r = z * 0x24 + (s32)tab;
            cell = (s32 *)(x * 4 + r);
            old = *cell;
            i++;
            if (old != 1) {
                D_801E4D38.node[D_801E4D3C].next = old;
            }
            k = D_801E4D3C;
            *cell = (s32)&D_801E4D38.node[k];
            D_801E4D38.node[k].face = (u8 *)p;
            D_801E4D38.node[k].unk8 = 0;
            D_801E4D3C = k + 1;
            p += 8;
        } while (i < n);
    }
    return (u8 *)p;
}

u8 *func_801B2048(SatMdl *m, u8 *base, u8 *blk) {
    u16 *p;
    s32 i;
    s32 n;
    s32 x;
    s32 z;
    s32 *cell;
    s32 old;
    s32 k;
    SatRow *tab;
    s32 r;

    n = *(u16 *)blk;
    p = (u16 *)(blk + 4);
    i = 0;
    if (i < n) {
        tab = D_801E4B44;
        do {
            *(MgB8 *)&m->v[0] = *(MgB8 *)(base + p[0]);
            *(MgB8 *)&m->v[1] = *(MgB8 *)(base + p[1]);
            *(MgB8 *)&m->v[2] = *(MgB8 *)(base + p[2]);
            *(MgB8 *)&m->v[3] = *(MgB8 *)(base + p[3]);
            x = m->v[0].vx + m->v[1].vx + m->v[2].vx + m->v[3].vx;
            x /= 4;
            z = m->v[0].vz + m->v[1].vz + m->v[2].vz + m->v[3].vz;
            z /= 4;
            x += 0x888;
            z += 0xE70;
            x /= 0x200;
            z /= 0x200;
            r = z * 0x24 + (s32)tab;
            cell = (s32 *)(x * 4 + r);
            old = *cell;
            i++;
            if (old != 1) {
                D_801E4D38.node[D_801E4D3C].next = old;
            }
            k = D_801E4D3C;
            *cell = (s32)&D_801E4D38.node[k];
            D_801E4D38.node[k].face = (u8 *)p;
            D_801E4D38.node[k].unk8 = 1;
            D_801E4D3C = k + 1;
            p += 10;
        } while (i < n);
    }
    return (u8 *)p;
}

void func_801B226C(u8 **arg0) {
    s32 i;
    s32 j;
    s32 o;
    s32 k;
    u8 *d;
    u8 *p;

    D_801E4D3C = 0;
    for (i = 0; i < 14; i++) {
        for (j = 8; j >= 0; j--) {
            D_801E4B44[i].v[j] = 1;
        }
    }
    k = 1;
    for (o = 0x30CC; o >= 0; o -= 0xC) {
        *(s32 *)(D_801E4D40 + o) = k;
    }
    d = *arg0;
    p = d + 4;
    func_801B2048(arg0, p, func_801B1E60(arg0, p, p + *(s32 *)d));
}

u32 func_801B2328(MgSVec *p, MgSVec *a, MgSVec *b, MgSVec *c) {
    s32 e0;
    s32 e1;
    s32 e2;

    e0 = (p->vx - a->vx) * (a->vz - b->vz) + (p->vz - a->vz) * (b->vx - a->vx);
    e1 = (p->vx - b->vx) * (b->vz - c->vz) + (p->vz - b->vz) * (c->vx - b->vx);
    e2 = (p->vx - c->vx) * (c->vz - a->vz) + (p->vz - c->vz) * (a->vx - c->vx);
    if (e0 == 0) {
        e0 = -1;
    }
    if (e1 == 0) {
        e1 = -1;
    }
    if (e2 == 0) {
        e2 = -1;
    }
    e0 = e0 & e1 & e2;
    return (u32)e0 >> 31;
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B23E0);

s32 func_801B2898(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E7E16[-v];
    }
    return v;
}

s32 func_801B28D4(s32 a, s32 b) {
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

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B29CC);

void func_801B3A14(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_801621F0[func_800BC04C(&func_801B29CC)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B3A78(void) {
    MgTask *p;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (D_801E1A10 & 2) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B3AD4);

void func_801B4350(void) {
    s32 i;
    s32 j;
    MgSatLst *p;

    for (i = 0; i < 8; i++) {
        p = &D_801E16B0[i];
        p->unk8 = 0;
        p->unk4 = 0;
        D_801E16B0[i].unk0 = 0;
        for (j = 7; j >= 0; j--) {
            D_801E16B0[i].unkC[j] = NULL;
        }
    }
}

void func_801B43B0(MgSatLst *r, MgSVec *val) {
    s32 head;
    s32 tail;
    s32 count;

    do {
        head = r->unk0;
        tail = r->unk4;
    } while (0);
    count = r->unk8;
    r->unkC[head] = (MgSatObj *)val;
    head++;
    count++;
    if (count >= 8) {
        count = 8;
    }
    if (head >= 8) {
        head = 0;
    }
    if (head == tail) {
        count--;
        tail++;
        if (count < 0) {
            count = 0;
        }
        if (tail >= 8) {
            tail = 0;
        }
    }
    r->unk0 = head;
    r->unk4 = tail;
    r->unk8 = count;
}

void func_801B4424(void) {
    s32 o;

    D_801E11EC = 0;
    for (o = 0x428; o >= 0; o -= 0x98) {
        *(s32 *)((u8 *)D_801E11F0 + o) = 0;
    }
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4454);

void func_801B46C0(void) {
    MgTask *p;
    MgSatObj *o;
    MgSatLst *l;
    u8 pad0[8];
    MgMat m;
    MgVec sc;
    MgVec w;
    MgVec un;
    MgSVec v;
    u8 pad1[8];
    MgScratch *sp;
    u8 *fr;
    u8 *c;
    s32 col;
    s32 i;
    s32 n;
    s32 k;
    s32 a;
    MgSVec8 *q;

    p = &D_80162978[D_8015169C];
    o = &D_801E11F0[p->unk16];
    l = &D_801E16B0[p->unk16];
    if (D_80062D98 == 0) {
        func_801B4454(o);
        q = &D_801E1810[p->unk16];
        q->v[l->unk0] = *(MgSVec *)&o->unk4;
        func_801B43B0(l, &D_801E1810[p->unk16].v[l->unk0]);
    }
    switch (p->unk14) {
    case 0:
        if (o->unk0 < 0) {
            func_8003B2CC(&D_801E0824, &D_801C8468[p->unkE], &v);
            v.vx += D_801E0838;
            v.vy += D_801E083C;
            v.vz += D_801E0840;
            w.vx = v.vx - o->unk4;
            w.vy = 0;
            w.vz = v.vz - o->unk8;
            func_8003A08C(&w, &w);
            i = 0x4B0;
            o->unk34 = o->unk4 + ((w.vx * i) >> 12);
            o->unk36 = o->unk6;
            o->unk38 = o->unk8 + ((w.vz * i) >> 12);
            o->unk4C = D_801C8468[p->unkE].unk20;
            o->unk0 |= 0x40000000;
            p->unk14 = 1;
        }
        break;
    case 1:
        o->unk36 -= 5;
        break;
    }
    m = D_801E0824;
    func_8003B16C(&o->unk78, &m);
    m.t[0] = o->unk4;
    m.t[1] = o->unk6;
    m.t[2] = o->unk8;
    sc.vx = sc.vy = sc.vz = p->unkC;
    func_8003B35C(&m, &sc);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    sp = (MgScratch *)0x1F800000;
    sp->unk0 = &D_801BEF4C;
    ((MgScratch *)0x1F800000)->unk4 = 0x88;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0x2B) {
        col = p->unk2 - 0x2B;
        ((MgScratch *)0x1F800000)->unkA = col * 0x155;
        col = 0x40 - col * 5;
    } else {
        ((MgScratch *)0x1F800000)->unkA = 0;
        col = 0x40;
    }
    func_8003B69C(0, 0, 0);
    D_801E07AC = func_800D29D4(sp, D_801517C0 + 0x70, 0xC, D_801E07AC);
    i = 0;
    c = D_801C8694;
    c[2] = col;
    c[1] = col;
    c[0] = col;
    n = l->unk4;
    k = 0x1F40;
    if (l->unk8 > 0) {
        fr = c + 4;
        do {
            if (n >= 8) {
                n = 0;
            }
            *(s16 *)fr = i * 2;
            func_800D4368(l->unkC[n], k, -(k >> 4));
            n++;
            D_801E07AC = func_800D4D90(fr - 8, D_801517C0 + 0x70, 0xC, D_801E07AC);
            i++;
        } while (i < l->unk8);
    }
    if (p->unk2 >= 0x37) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4B98);

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B4F68);

s32 func_801B5388(u16 *arg0) {
    MgSVec rot;
    MgMat m;
    MgVec sc;
    s32 sp48;
    s32 sp4C;
    s32 kx;
    s32 kz;

    kx = 23;
    kz = 28;
    if (D_801E07C4 != 0) {
        rot.vz = 0;
        rot.vx = 0x400;
        rot.vy = 0x800;
        m.t[0] = *(s32 *)&D_801E0838 / kx;
        m.t[1] = -(*(s32 *)&D_801E0840 / kz) - 5;
    } else {
        rot.vy = 0;
        rot.vz = 0;
        rot.vx = 0x400;
        m.t[0] = -(*(s32 *)&D_801E0838 / kx);
        m.t[1] = *(s32 *)&D_801E0840 / kz - 5;
    }
    m.t[2] = 0x200;
    func_8003BF8C(&rot, &m);
    sc.vy = 1;
    sc.vx = 0x1000 / kx;
    sc.vz = 0x1000 / kz;
    func_8003B35C(&m, &sc);
    func_80044AC0((s32)D_801C8750, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801C8750);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801C869C);
    func_8003B64C(&sp48, &sp4C);
    func_8003B6BC((s16)arg0[2] / 2, (s16)arg0[3] / 2);
    func_8003B48C(&m);
    func_8003B51C(&m);
    *(s32 *)0x1F800000 = D_8016209C;
    *(s32 *)0x1F800008 = 0;
    *(s32 *)0x1F800010 = 1;
    *(s32 *)0x1F80000C = D_801E07AC;
    *(s32 *)0x1F800004 = D_801517C0 + 0x4084;
    func_8003B69C(D_800F5B70, D_800F5B71, D_800F5B72);
    D_801E07AC = func_801B0B5C(0x1F800000, 0x200);
    func_8003B6BC(sp48, sp4C);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801C86C4);
    func_80044978(D_801C8790, arg0);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801C8790);
    D_801C87A8.v = arg0[0];
    D_801C87AA = arg0[1];
    func_800449FC(D_801C879C, &D_801C87A8);
    return func_80046794(D_801517C0 + 0x4084, (s32)D_801C879C);
}

void func_801B5760(MgB8 *src) {
    s32 i;

    for (i = 0; i < 0x135; i++) {
        D_801BF984[i] = src[i];
    }
}

void func_801B57AC(MgSVec *a, MgSVec *b, MgSVec *d) {
    s32 i;

    for (i = 0; i < 0x135; i++) {
        d[i].vx = b[i].vx - a[i].vx;
        d[i].vy = b[i].vy - a[i].vy;
        d[i].vz = b[i].vz - a[i].vz;
    }
}

void func_801B5804(void) {
    *(M2C_UNK **)0x1F800000 = &D_801BF980;
    *(s32 *)0x1F800004 = 0x80;
    *(s16 *)0x1F800008 = 0;
    *(s16 *)0x1F80000A = 0;
    *(s16 *)0x1F80000C = 0x20;
    *(s16 *)0x1F80000E = 0;
    D_801E07AC = func_800D29D4(0x1F800000, D_801517C0 + 0x70, 0xC, D_801E07AC);
}

void func_801B5884(void *arg0) {
    M2C_SFIELD(arg0, M2C_UNK **, 0) = &D_801BF980;
    M2C_SFIELD(arg0, s32 *, 8) = 0xC;
    M2C_SFIELD(arg0, s32 *, 0x10) = 0;
    M2C_SFIELD(arg0, s32 *, 4) = (s32) (D_801517C0 + 0x70);
    M2C_SFIELD(arg0, s32 *, 0xC) = (s32) D_801E07AC;
    D_801E07AC = func_801B0B5C();
}

void func_801B58DC(SatCtx *ctx, s32 amp) {
    s32 i;
    s32 o;
    s32 k;
    s32 lox;
    s32 hix;
    s32 loz;
    s32 hiz;
    SatActor *e;
    MgSVec *q;
    s32 px;
    s32 pz;
    u8 *fl;
    u16 *h;

    ctx->unk0 = &D_801BF980;
    ctx->unk10 = D_801E07C4;
    if (D_801E07C4 != 0) {
        lox = *(s32 *)&D_801E0838 - 0x888;
        hix = *(s32 *)&D_801E0838 + 0x888;
        loz = *(s32 *)&D_801E0840 - 0xD58;
        hiz = *(s32 *)&D_801E0840 + 0xE70;
    } else {
        lox = *(s32 *)&D_801E0838 - 0x888;
        hix = *(s32 *)&D_801E0838 + 0x888;
        loz = *(s32 *)&D_801E0840 - 0xE70;
        hiz = *(s32 *)&D_801E0840 + 0xD58;
    }
    i = 0;
    fl = D_80151909;
    h = D_801E07CA;
    o = 0;
    D_800D3544 = 0;
    D_800D3546 = 0;
    do {
        e = (SatActor *)(D_80151A24 + o);
        q = &e->pos;
        px = e->pos.vx;
        if (px >= lox && px <= hix) {
            pz = e->pos.vz;
            if (pz >= loz && pz <= hiz) {
                func_801B23E0(ctx, q);
                if (ctx->unkD8 != 0) {
                    ctx->unk98.vy = *h;
                    k = func_801B045C(&ctx->unk98, &ctx->unkA0, &ctx->unkA8) * amp >> 12;
                    *(s16 *)((u8 *)D_80151A4C + 2 + o) = *h - k;
                    if (k != 0) {
                        *fl |= 0x10;
                    } else if (!(D_801E0818[i] & 0x10)) {
                        *fl &= 0xEF;
                    }
                }
            }
        }
        fl += 0xB9C;
        h += 4;
        i++;
        o += 0xB9C;
    } while (i < 10);
}

void func_801B5ACC(void) {
    u8 pad[8];
    MgMat m;
    MgVec sc;
    MgSat5 *p;
    MgScr *sp;
    MgTask *q;
    s32 a;
    s32 s2;
    s32 s3;
    s32 s4;
    s32 v;

    p = &D_801621F0[D_801590D4];
    sp = (MgScr *)0x1F800000;
    switch (p->unk14) {
    case 0:
        a = p->unk16;
        s2 = a * 0xDB;
        s3 = (a + 1) * 0xDB;
        s4 = a << 8;
        if (D_80062D98 != 0) {
            break;
        }
        if (a == 0) {
            func_800D55F4(0x20, func_800D574C(D_801E07B4), 0x14C);
        }
        if (p->unk16 < 0x10) {
            break;
        }
        p->unk14 = 1;
        p->unk16 = 0;
    case 1:
        s3 = 0xDB6;
        s2 = 0xDB6;
        s4 = 0x1000;
        if (D_80062D98 != 0) {
            break;
        }
        if (p->unk16 == 4) {
            q = &D_80162978[func_800BBEAC(func_801B4F68)];
            q->unkC = 0;
            q->unkE = 0xE49;
            func_800D55F4(0x20, func_800D574C(D_801E07B4), 0x189);
        }
        if (p->unk16 == 0x15) {
            D_801E1A10 |= 0x40000040;
            p->unk16 += 1;
        }
        if (p->unk16 < 0x20) {
            break;
        }
        if (D_801E1A10 & 0x20000000) {
            p->unk14 = 4;
            p->unk16 = 0;
        } else {
            p->unk14 = 2;
            p->unk16 = 0;
        }
        break;
    case 2:
        s3 = 0xDB6;
        s2 = 0xDB6;
        s4 = 0x1000;
        if (D_80062D98 != 0) {
            break;
        }
        if (p->unk16 == 1) {
            func_800D55F4(0x20, func_800D574C(D_801E07B4), 0x14B);
        }
        v = p->unk16 << 8;
        func_801B5760(D_801C58C8);
        func_8003A28C(D_801BF984, D_801E0844, 0x135, v);
        if (p->unk16 < 0x10) {
            break;
        }
        p->unk14 = 3;
        p->unk16 = 0;
    case 3:
        s3 = 0xDB6;
        s2 = 0xDB6;
        s4 = 0x1000;
        if (D_80062D98 != 0) {
            break;
        }
        if (p->unk16 == 0) {
            func_800D55F4(0x20, func_800D574C(D_801E07B4), 0x1A5);
        }
        if (p->unk16 == 6) {
            func_800BBEAC(func_801B4B98);
        }
        if (p->unk16 < 0x46) {
            break;
        }
        p->unk14 = 4;
        p->unk16 = 0;
        break;
    case 4:
        a = p->unk16;
        s2 = 0xDB6;
        s3 = 0xDB6 - (a + 1) * 0x6D;
        if (s3 < 0) {
            s3 = 0;
        }
        if (D_80062D98 != 0) {
            break;
        }
        if (a == 1) {
            func_800D55F4(0x20, func_800D574C(D_801E07B4), 0x152);
        }
        if (p->unk16 < 0x21) {
            break;
        }
        p->unk14 = 5;
        p->unk16 = 0;
        break;
    case 5:
        s4 = 0;
        s3 = 0;
        s2 = 0;
        if (D_80062D98 != 0) {
            break;
        }
        if (p->unk16 < 2) {
            break;
        }
        p->unk14 = 6;
        p->unk16 = 0;
    case 6:
        s4 = 0;
        s3 = 0;
        s2 = 0;
        p->unk0 = -1;
        D_801E1A10 |= 0x10000000;
        break;
    }
    m = D_801E0824;
    sc.vz = 0x1000;
    sc.vx = 0x1000;
    sc.vy = s2;
    func_8003B35C(&m, &sc);
    sp->unk0 = (u8 *)&D_801BF980;
    sp->unk8 = 0xC;
    sp->unk4 = D_801517C0 + 0x70;
    sp->unkC = D_801E07AC;
    if (p->unk14 < 4) {
        func_8003A63C(&D_800FA63C, &m, &m);
        func_8003B48C(&m);
        func_8003B51C(&m);
        sp->unk10 = 2;
        sp->unk28 = 0x80808080;
        D_801E07AC = func_801B0B5C(sp, s4);
    } else {
        func_8003A63C(&D_800FA63C, &m, (MgMat *)((u8 *)sp + 0x30));
        func_8003B69C(0, 0, 0);
        D_801E07AC = func_801B1DC0(sp, p->unk16 + 4);
    }
    func_801B58DC(sp, s3);
    if ((D_801E1A10 & 0x40000000) == 0) {
        if (D_80062D98 == 0) {
            p->unk2++;
            p->unk16++;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_satan/nonmatchings/text", func_801B6060);

void func_801B639C(void) {
    MgSVec rot;
    SatSpawn *q;
    s32 o;
    s32 k;
    s32 i;

    D_80162978[D_8015169C].unk0 = -1;
    q = (SatSpawn *)&D_801621F0[func_800BC04C((M2C_UNK *)func_801B6060)];
    func_800D54EC(D_801E07B4, &q->pos);
    q->pos.vy = 0;
    q->unk14 = 0;
    q->unk16 = 0x16A;
    i = D_80151A46[D_801E07B8][0];
    if ((u32)(i - 0x400) < 0x800) {
        D_801E07C4 = 0;
    } else {
        D_801E07C4 = 1;
    }
    rot.vx = 0;
    rot.vz = 0;
    k = D_801E07C4 << 11;
    rot.vy = k;
    func_8003BF8C(&rot, &D_801E0824);
    ((MgVec *)&D_801E0838)->vx = q->pos.vx;
    ((MgVec *)&D_801E0838)->vy = 0;
    ((MgVec *)&D_801E0838)->vz = q->pos.vz;
    func_801B5388(D_801C86DC);
    for (i = 0; i < 10; i++) {
        D_801E07C8[i] = *(MgB8 *)&D_80151A4C[i];
        o = i * 0xB9C;
        D_801E0818[i] = D_80151909[o];
    }
    *(M2C_UNK **)0x1F800000 = &D_801BF980;
    func_801B226C((u8 **)0x1F800000);
    func_801B57AC((MgSVec *)((u8 *)&D_801BF980 + 4), (MgSVec *)D_801C2514, (MgSVec *)D_801E0844);
    func_801B4424();
    func_801B4350();
    *(u8 **)0x1F800004 = D_801C2514;
    func_801B1178(0x1F800000);
    ((void (*)(u8 *, MgMat *, s32))func_801B3A14)(D_801C8624, &D_801E0824, D_801E07B8);
}

void func_801B65BC(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (p->unk14 & D_801E1A10) {
        p->unk0 = -1;
    }
}

void func_801B65FC(void) {
    M2C_UNK *var_v1;

    var_v1 = &D_801D47AC;
    if (D_800F8368 == 0) {
        var_v1 = &D_801C87AC;
    }
    D_801E07AC = var_v1;
    if (D_801E1A10 < 0) {
        *D_801E07B0 = -1;
    }
}

void func_801B664C(arg0, arg1) {
    D_801E07B0 = (s32 *)&D_801621F0[func_800BC04C((M2C_UNK *)func_801B65FC)];
    func_800D2980(&D_801B67C8, 3, 0x80, 0);
    func_800D2538(&D_801C86E8, &D_801C86E4);
    D_8016298C[func_800BBEAC(func_801B65BC)].unk0 = 0x40;
    func_800BBEAC(&func_801B639C);
    D_801E07B4 = arg0;
    D_801E07B8 = arg1;
    D_801E1A10 = 0;
    D_800FAFDC = 1;
}

void func_801B672C(arg0, arg1) {
    D_8016298C[func_800BBEAC((void *)func_801B65BC)].unk0 = 0x80;
    D_801E1A10 &= 0xBFFFFFFF;
    if (arg0 == (1 << arg1)) {
        D_801E1A10 |= 0x20000000;
    }
    D_801E07B4 = arg0;
    D_801E07B8 = arg1;
}

INCLUDE_RODATA("../asm/us/magic_satan/nonmatchings/text", D_801B008C);
