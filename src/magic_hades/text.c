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

HdPolyEnt *func_801B0480(HdPolyCtx *arg0, u8 *arg1, u16 *arg2, s32 arg3) {
    HdPolyEnt *e;
    HdPolyFT3 *p;
    s32 i;
    s32 sh;
    s32 n;
    s32 c;

    e = (HdPolyEnt *)(arg2 + 2);
    i = 0;
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    if ((u32)i < (u32)n) {
        do {
            *(MgB8 *)&arg0->v28 = *(MgB8 *)(arg1 + e->idx[0]);
            i++;
            if (arg0->v28.vy < arg3) {
                *(MgB8 *)&arg0->v30 = *(MgB8 *)(arg1 + e->idx[1]);
                *(MgB8 *)&arg0->v38 = *(MgB8 *)(arg1 + e->idx[2]);
                gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
                gte_rtpt();
                c = e->col;
                *(s32 *)&p->r0 = (c << 16) | (c << 8) | c;
                p->tpage = arg0->tpage;
                p->clut = e->clut;
                p->uv0 = e->uv0;
                p->uv1 = e->uv1;
                p->uv2 = e->uv2;
                p->tag.len = 7;
                p->code = 0x24;
                gte_stflg(&arg0->flag);
                if ((arg0->flag & 0x60000) == 0) {
                    gte_nclip();
                    gte_stopz(&arg0->area);
                    if (arg0->area > 0) {
                        gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                        gte_avsz3();
                        gte_stotz(&arg0->otz);
                        p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                        (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                        p++;
                    }
                }
            }
            e++;
        } while (i < n);
    }
    arg0->prim = p;
    return e;
}

HdQuadEnt *func_801B0708(HdClipCtx *arg0, u8 *arg1, s32 *arg2, s32 arg3) {

    HdQuadEnt *e;
    HdPolyFT4 *p;
    s32 i;
    s32 sh;
    s32 n;
    s32 f;
    s32 y0;
    s32 y2;
    s32 m;
    s32 w;

    e = (HdQuadEnt *)(arg2 + 1);
    i = 0;
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    if (i < n) {
        do {
            *(MgB8 *)&arg0->v28 = *(MgB8 *)(arg1 + e->idx[0]);
            *(MgB8 *)&arg0->v30 = *(MgB8 *)(arg1 + e->idx[1]);
            *(MgB8 *)&arg0->v38 = *(MgB8 *)(arg1 + e->idx[2]);
            *(MgB8 *)&arg0->v40 = *(MgB8 *)(arg1 + e->idx[3]);
            y0 = arg0->v28.vy;
            y2 = arg0->v38.vy;
            f = y0 >= arg3;
            if (y2 >= arg3) {
                f |= 2;
            }
            if (f != 3) {
                *(u16 *)&arg0->u0 = e->uv0;
                *(u16 *)&arg0->u1 = e->uv1;
                *(u16 *)&arg0->u2 = e->uv2;
                *(u16 *)&arg0->u3 = e->uv3;
                if (f == 1) {
                    m = (arg3 - y2) * (arg0->v0 - arg0->v2);
                    w = m / (y0 - y2);
                    arg0->v0 = arg0->v2 + w;
                    m = (arg3 - y2) * (arg0->v1 - arg0->v3);
                    w = m / (y0 - y2);
                    arg0->v1 = arg0->v3 + w;
                    arg0->v30.vy = arg3 + 1;
                    arg0->v28.vy = arg3 + 1;
                } else if (f == 2) {
                    m = (arg3 - y0) * (arg0->v2 - arg0->v0);
                    w = m / (y2 - y0);
                    arg0->v2 = arg0->v0 + w;
                    m = (arg3 - y0) * (arg0->v3 - arg0->v1);
                    w = m / (y2 - y0);
                    arg0->v3 = arg0->v1 + w;
                    arg0->v40.vy = arg3 + 1;
                    arg0->v38.vy = arg3 + 1;
                }
                gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
                gte_rtpt();
                w = e->col;
                *(s32 *)&p->r0 = (w << 16) | (w << 8) | w;
                p->tpage = arg0->tpage;
                p->clut = e->clut;
                p->uv0 = *(u16 *)&arg0->u0;
                p->uv1 = *(u16 *)&arg0->u1;
                p->uv2 = *(u16 *)&arg0->u2;
                p->uv3 = *(u16 *)&arg0->u3;
                p->tag.len = 9;
                p->code = 0x2C;
                gte_stflg(&arg0->flag);
                if ((arg0->flag & 0x60000) == 0) {
                    gte_nclip();
                    gte_stopz(&arg0->area);
                    if (arg0->area > 0) {
                        gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                        gte_ldv0c(&arg0->v40);
                        gte_rtps();
                        gte_stsxy(&p->xy3);
                        gte_avsz4();
                        gte_stotz(&arg0->otz);
                        p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                        (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                        p++;
                    }
                }
            }
            i++;
            e++;
        } while (i < n);
    }
    arg0->prim = p;
    return e;
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B0B90);

HdPolyEnt *func_801B0C24(HdTriCtx *arg0, u8 *arg1, u16 *arg2, s32 arg3) {
    HdPolyEnt *e;
    HdPolyFT3 *p;
    s32 i;
    s32 n;
    s32 sh;
    s32 l1;
    s32 l2;
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 q;

    e = (HdPolyEnt *)(arg2 + 2);
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    for (i = 0; i < n; i++, e++) {
        *(MgB8 *)&arg0->v28 = *(MgB8 *)(arg1 + e->idx[0]);
        *(MgB8 *)&arg0->v30 = *(MgB8 *)(arg1 + e->idx[1]);
        *(MgB8 *)&arg0->v38 = *(MgB8 *)(arg1 + e->idx[2]);
        *(u16 *)&arg0->u0 = e->uv0;
        *(u16 *)&arg0->u1 = e->uv1;
        *(u16 *)&arg0->u2 = e->uv2;
        arg0->va.vx = arg0->v28.vx - arg0->v38.vx;
        arg0->va.vy = 0;
        arg0->va.vz = arg0->v28.vz - arg0->v38.vz;
        l1 = func_80039F5C(func_8003A08C(&arg0->va, &arg0->va));
        arg0->vb.vx = arg0->v30.vx - arg0->v38.vx;
        arg0->vb.vy = 0;
        arg0->vb.vz = arg0->v30.vz - arg0->v38.vz;
        l2 = func_80039F5C(func_8003A08C(&arg0->vb, &arg0->vb));
        if (arg3 < l1) {
            m0 = arg3 * arg0->va.vx;
            m1 = arg3 * arg0->va.vz;
            m2 = arg3 * arg0->vb.vx;
            m3 = arg3 * arg0->vb.vz;
            q = arg3 * (arg0->u0 - arg0->u2) / l1;
            arg0->u0 = arg0->u2 + q;
            q = arg3 * (arg0->v0 - arg0->v2) / l1;
            arg0->v0 = arg0->v2 + q;
            q = arg3 * (arg0->u1 - arg0->u2) / l2;
            arg0->u1 = arg0->u2 + q;
            q = arg3 * (arg0->v1 - arg0->v2) / l2;
            arg0->v28.vx = arg0->v38.vx + (m0 >> 12);
            arg0->v28.vz = arg0->v38.vz + (m1 >> 12);
            arg0->v30.vx = arg0->v38.vx + (m2 >> 12);
            arg0->v30.vz = arg0->v38.vz + (m3 >> 12);
            arg0->v1 = arg0->v2 + q;
        }
        gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
        gte_rtpt();
        q = e->col;
        *(s32 *)&p->r0 = (q << 16) | (q << 8) | q;
        p->tpage = arg0->tpage;
        p->clut = e->clut;
        p->uv0 = *(u16 *)&arg0->u0;
        p->uv1 = *(u16 *)&arg0->u1;
        p->uv2 = *(u16 *)&arg0->u2;
        p->tag.len = 7;
        p->code = 0x24;
        gte_stflg(&arg0->flag);
        if ((arg0->flag & 0x60000) == 0) {
            gte_nclip();
            gte_stopz(&arg0->area);
            if (arg0->area > 0) {
                gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                gte_avsz3();
                gte_stotz(&arg0->otz);
                p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                p++;
            }
        }
    }
    arg0->prim = p;
    return e;
}

HdQuadEnt *func_801B1144(HdQuadCtx *arg0, u8 *arg1, s32 *arg2) {
    HdQuadEnt *e;
    HdPolyFT4 *p;
    s32 i;
    s32 sh;
    s32 n;
    s32 c;

    e = (HdQuadEnt *)(arg2 + 1);
    i = 0;
    p = arg0->prim;
    sh = 14 - arg0->shift;
    n = arg2[0];
    if (i < n) {
        do {
            *(MgB8 *)&arg0->v28 = *(MgB8 *)(arg1 + e->idx[0]);
            *(MgB8 *)&arg0->v30 = *(MgB8 *)(arg1 + e->idx[1]);
            *(MgB8 *)&arg0->v38 = *(MgB8 *)(arg1 + e->idx[2]);
            *(MgB8 *)&arg0->v40 = *(MgB8 *)(arg1 + e->idx[3]);
            gte_ldv3(&arg0->v28, &arg0->v30, &arg0->v38);
            gte_rtpt();
            c = e->col;
            *(s32 *)&p->r0 = (c << 16) | (c << 8) | c;
            p->tpage = arg0->tpage;
            p->clut = e->clut;
            p->uv0 = e->uv0;
            p->uv1 = e->uv1;
            p->uv2 = e->uv2;
            p->uv3 = e->uv3;
            p->tag.len = 9;
            p->code = 0x2C;
            gte_stflg(&arg0->flag);
            i++;
            if ((arg0->flag & 0x60000) == 0) {
                gte_nclip();
                gte_stopz(&arg0->area);
                if (arg0->area > 0) {
                    gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
                    gte_ldv0c(&arg0->v40);
                    gte_rtps();
                    gte_stsxy(&p->xy3);
                    gte_avsz4();
                    gte_stotz(&arg0->otz);
                    p->tag.addr = (arg0->ot + (arg0->otz >> sh))->addr;
                    (arg0->ot + (arg0->otz >> sh))->addr = (u32)p;
                    p++;
                }
            }
            e++;
        } while (i < n);
    }
    arg0->prim = p;
    return e;
}

INCLUDE_ASM("../asm/us/magic_hades/nonmatchings/text", func_801B140C);
