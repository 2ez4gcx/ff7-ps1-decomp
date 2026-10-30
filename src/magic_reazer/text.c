#include "common.h"
#include "magic_reazer/decls.h"

void func_801B0088(void) {
    func_801B1F9C();
}

s32 func_801B00A8(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0184(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0300(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03DC(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B04C0(void) {
    MgTask *p;
    u16 *frame;
    u16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801BA67C;
    *frame = p->unk2;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -((s16)t >> 3));
    D_801D2680 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D2680);
    if (p->unk2 >= 0x11) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_reazer/nonmatchings/text", func_801B058C);

void func_801B102C(RzObj *sc, s32 arg1, s32 arg2, s32 arg3) {
    RzPolyG4 *p;
    s32 i;
    s32 c0;
    s32 c1;
    s32 k;
    u8 len;
    u8 code;

    if (arg3 != 0) {
        c0 = sc->unk6C;
        c1 = sc->unk68;
    } else {
        func_8003B69C(0x68, 0x28, 0x28);
        func_8003B710(&sc->unk64, 0x1000 / arg2 * arg1, &sc->unk68);
        c0 = sc->unk68;
        c1 = sc->unk6C;
    }
    i = 0;
    len = 8;
    code = 0x3A;
    p = (RzPolyG4 *)D_801D2680;
    k = (sc->unk60 + sc->otz) >> 3;
    do {
        *(s32 *)((u8 *)p + 8) = sc->a[i];
        *(s32 *)((u8 *)p + 0x10) = sc->a[(i + 1) & 3];
        *(s32 *)((u8 *)p + 0x18) = sc->b[i];
        *(s32 *)((u8 *)p + 0x20) = sc->b[(i + 1) & 3];
        *(s32 *)((u8 *)p + 4) = c0;
        *(s32 *)((u8 *)p + 0xC) = c0;
        *(s32 *)((u8 *)p + 0x14) = c1;
        *(s32 *)((u8 *)p + 0x1C) = c1;
        p->tag.len = len;
        ((u8 *)p)[7] = code;
        p->tag.addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
        ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
        p++;
        i++;
    } while (i < 4);
    D_801D2680 = (MgLineG2 *)p;
}

INCLUDE_ASM("../asm/us/magic_reazer/nonmatchings/text", func_801B11C0);

void func_801B13CC(RzObj *o, s32 arg1) {
    RzPolyG4 *p;

    o->d1.vx = o->p1.vx - o->p0.vx;
    o->d1.vy = o->p1.vy - o->p0.vy;
    o->d1.vz = o->p1.vz - o->p0.vz;
    func_8003A08C(&o->d1, &o->d1);
    func_801B0184(func_801B00A8(&D_801BA664, &o->d1, &o->d2), &o->m, &o->d2);
    o->v[0].vx = 0;
    o->v[0].vy = -arg1;
    o->v[0].vz = 0;
    o->v[1].vx = arg1;
    o->v[1].vy = 0;
    o->v[1].vz = 0;
    o->v[2].vx = -arg1;
    o->v[2].vy = 0;
    o->v[2].vz = 0;
    o->v[3].vx = 0;
    o->v[3].vy = arg1;
    o->v[3].vz = 0;
    func_8003B2CC(&o->m, &o->v[0], &o->v[0]);
    func_8003B2CC(&o->m, &o->v[1], &o->v[1]);
    func_8003B2CC(&o->m, &o->v[2], &o->v[2]);
    func_8003B2CC(&o->m, &o->v[3], &o->v[3]);
    o->v[0].vx += o->p0.vx;
    o->v[0].vy += o->p0.vy;
    o->v[0].vz += o->p0.vz;
    o->v[1].vx += o->p0.vx;
    o->v[1].vy += o->p0.vy;
    o->v[1].vz += o->p0.vz;
    o->v[2].vx += o->p0.vx;
    o->v[2].vy += o->p0.vy;
    o->v[2].vz += o->p0.vz;
    o->v[3].vx += o->p0.vx;
    o->v[3].vy += o->p0.vy;
    o->v[3].vz += o->p0.vz;
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = (RzPolyG4 *)D_801D2680;
    o->otz = func_8003BD7C(&o->v[0], &o->v[1], &o->v[2], &o->v[3], &p->xy0, &p->xy1, &p->xy2, &p->xy3, &o->unk4, &o->unkC);
    p->tag.len = 8;
    p->c0 = 0x686868;
    p->c1 = 0x686868;
    p->c2 = 0x686868;
    p->c3 = 0x686868;
    ((u8 *)p)[7] = 0x3A;
    p->tag.addr = ((MgTag *)D_801517C0 + (o->otz >> 2) + 0x1C)->addr;
    ((MgTag *)D_801517C0 + (o->otz >> 2) + 0x1C)->addr = (u32)p;
    p++;
    D_801D2680 = (MgLineG2 *)p;
}

void func_801B16C8(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801D2680;
    r->otz = func_8003BBDC(v0, &p->x0, &r->sxy, &r->flag);
    func_8003BBDC(v1, &p->x1, &r->sxy, &r->flag);
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->tag.len = 4;
    p->code = 0x52;
    p->tag.addr = ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr;
    ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr = (u32)p;
    p++;
    D_801D2680 = p;
}

INCLUDE_RODATA("../asm/us/magic_reazer/nonmatchings/text", D_801B001C);

void func_801B17F8(void) {
    MgVec v1;
    MgVec v2;
    u8 pad[0x20];
    RzB24 tbl;
    MgMat m;
    MgTask *p;
    RzBolt *b;
    s32 i;
    s32 n;
    s32 amp;
    s32 k;

    tbl = D_801B001C;
    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk14 < 12) {
            amp = p->unkC;
            for (i = 0; i < 12; i++) {
                if (p->unk2 == *(s16 *)&tbl.b[i * 2]) {
                    k = amp >> 1;
                    k *= k;
                    n = p->unk14;
                    p->unk14++;
                    D_8016297C[func_800BBEAC(&func_801B058C)][0] = n;
                    D_801D26AC[n].unk0 = 0;
                    *(RzB8 *)&D_801D26AC[n].org = *(RzB8 *)&D_801D2694;
                    b = &D_801D26AC[n];
                    *(RzB8 *)&b->dir = *(RzB8 *)&p->unk4;
                    *(RzB8 *)&D_801D26AC[n].pos = *(RzB8 *)&b->dir;
                    D_801D26AC[n].pos.vx += func_80042DA8() % (amp * 2) - amp;
                    D_801D26AC[n].pos.vy += func_80042DA8() % (amp * 2) - amp;
                    D_801D26AC[n].pos.vz += func_80042DA8() % (amp * 2) - amp;
                    D_801D26AC[n].pos.pad = amp;
                    D_801D26AC[n].unk6C = k;
                    D_801D26AC[n].unk70 = 0;
                    D_801D26AC[n].unk74 = 0;
                    k = func_80042DA8() % 0x1000;
                    v1.vx = D_801D26AC[n].pos.vx - D_801D2694.vx;
                    v1.vy = D_801D26AC[n].pos.vy - D_801D2694.vy;
                    v1.vz = D_801D26AC[n].pos.vz - D_801D2694.vz;
                    v2.vx = -v1.vy - v1.vz;
                    v2.vy = v1.vx - v1.vz;
                    v2.vz = v1.vx + v1.vy;
                    func_8003A08C(&v1, &v1);
                    func_8003A08C(&v2, &v2);
                    func_801B0184(k, &m, &v1);
                    func_8003AB84(&m, &v2, &v2);
                    D_801D26AC[n].va = v1;
                    D_801D26AC[n].vb = v2;
                    for (k = 0x17; k >= 0; k--) {
                        D_801D26AC[n].trail[k].b = 0;
                    }
                }
            }
        }
        if (D_801D26A4 >= 8) {
            if (D_801D2690 == 0xF) {
                func_800D5774(D_801D2688);
            }
            D_801D2690++;
        }
        if (D_801D2690 >= 0x14) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_reazer/nonmatchings/text", func_801B1D54);

void func_801B1EF0(void) {
    MgLineG2 *q;
    s32 i;

    q = &D_801C6680;
    if (D_800F8368 == 0) {
        q = &D_801BA680;
    }
    D_801D2680 = q;
    if (D_80162080 < 2) {
        *D_801D2684 = -1;
    }
    i = 0;
    D_800D3544 = D_80162080;
    do {
        if (D_80161EF0[i] != 0) {
            D_800D3546 = (D_800D3546 << 8) | i;
        }
        i++;
    } while (i < 0x64);
}

s32 func_801B1F9C(arg0, arg1) {
    s32 i;
    s32 n;

    D_801D2684 = (s32 *)&D_80162978[func_800BBEAC(&func_801B1EF0)];
    func_800D2980(&D_801B2090, 0, 0, 0);
    i = 0;
    n = 0;
    for (; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D2688 = i;
            }
        }
    }
    D_801D268C = arg1;
    D_801D2690 = 0;
    D_801D26A4 = 0;
    D_801D26A8 = 0;
    func_800BBEAC(&func_801B1D54);
    return func_800D55F4(0x28, func_800D574C(arg0), 0x62);
}
