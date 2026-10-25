#include "common.h"
#include "field/decls.h"

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A2314);

void func_800A2D5C(s32 unused, u8 *p) {
    RECT16 r;
    u32 a;
    u32 b;
    u8 *q;
    u8 pad[0x28];

    a = *(u32 *)p;
    D_800E4D94 = a;
    D_800E4D98 = *(u16 *)(p + 4);
    D_800E4D9A = *(u16 *)(p + 6);
    D_800E4D9C = *(u16 *)(p + 8);
    D_800E4D9E = *(u16 *)(p + 0xA);
    q = p + 0xC;
    D_800E4D90 = q;
    q += (a >> 2) * 4 - 0xC;
    b = *(u32 *)q;
    D_800E4DA8 = b;
    q += 4;
    D_800E4DAC = *(u16 *)q;
    D_800E4DAE = *(u16 *)(q + 2);
    q += 4;
    D_800E4DB0 = *(u16 *)q * 2;
    D_800E4DB2 = *(u16 *)(q + 2);
    q += 4;
    D_800E4DA4 = q;
    q += (b >> 2) * 4 - 0xC;
    D_800E4DD8 = *(s32 *)q;
    q += 4;
    D_800E4DDC = *(u16 *)q;
    D_800E4DDE = *(u16 *)(q + 2);
    q += 4;
    D_800E4DE0 = *(u16 *)q * 2;
    D_800E4DE2 = *(u16 *)(q + 2);
    q += 4;
    D_800E4DD4 = q;
    r.x = 0;
    r.y = 0x1E0;
    r.w = 0x100;
    r.h = 0x10;
    func_80043DD8(0);
    func_80044000(&r, D_800E4D90);
    func_80043DD8(0);
    D_800E4DB4 = func_800436C0(D_800E4DA4, 1, 0, D_800E4DAC, D_800E4DAE, D_800E4DB0, D_800E4DB2);
    if (D_800E4DD8 != 0) {
        func_80043DD8(0);
        D_800E4DE4 = func_800436C0(D_800E4DD4, 1, 0, D_800E4DDC, D_800E4DDE, D_800E4DE0, D_800E4DE2);
    }
    func_80043DD8(0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A2F78);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A3020);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A364C);

s32 func_800A4094(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a1;

    temp_a1 = arg1 - arg0;
    if ((u32) (temp_a1 + 0x7FFFF) <= 0xFFFFEU) {
        arg0 += (temp_a1 * arg3) / arg2;
    } else {
        arg0 += (temp_a1 / arg2) * arg3;
    }
    return arg0;
}

s32 func_800A4134(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t;
    s32 d;
    s32 a;

    t = (arg3 << 12) / arg2 / 32;
    a = (t - 0x80) & 0xFF;
    d = arg1 - arg0;
    return arg0 + (((s32 (*)(s32))func_800A8620)(a) + 0x1000) * d / 0x2000;
}

s32 func_800A41CC(s32 arg0, M2C_UNK arg1) {
    M2C_UNK sp10;
    M2C_UNK sp14;
    s32 temp_s0;

    func_8003AE38();
    func_8003B48C(D_80071E40);
    func_8003B51C(D_80071E40);
    func_8003B6BC(0, 0);
    temp_s0 = func_8003BBDC(arg0, arg1, &sp10, &sp14);
    func_8003AED8();
    return temp_s0;
}

void func_800A424C(FdOsc *s) {
    s16 t;
    s16 u;
    s16 w;
    u16 x;

    if (s->mode == 1) {
        if (s->phase == 0) {
            s->t = 0;
            s->from = 0;
            s->to = (s16)(D_800E0638[s->idx] * s->amp) / 256;
            s->phase = 1;
            s->idx++;
            return;
        }
        t = s->t;
        if (t > s->dur) {
            s->t = 0;
            s->from = s->to;
            if ((s16)s->from < 0) {
                s->to = (s16)(D_800E0638[s->idx] * s->amp) / 256;
            } else {
                s->to = -(s16)(D_800E0638[s->idx] * s->amp) / 256;
            }
            s->idx++;
            return;
        }
        s->t = t + 1;
        s->out = func_800A4134((s16)s->from, (s16)s->to, s->dur, s->t);
    } else if (s->phase == 1) {
        u = s->t;
        if (u > s->dur) {
            x = s->to;
            s->t = 0;
            s->to = 0;
            s->phase = 0;
            s->from = x;
            s->idx++;
            return;
        }
        s->t = u + 1;
        s->out = func_800A4134((s16)s->from, (s16)s->to, s->dur, s->t);
    } else {
        w = s->t;
        if (s->dur == w) {
            s->out = 0;
            return;
        }
        s->t = w + 1;
        s->out = func_800A4134((s16)s->from, (s16)s->to, s->dur, s->t);
    }
}

void func_800A4430(void) {
    if (D_8009AC13 == 0) {
        switch (D_8009AC11) {
        case 0:
            D_8009A100 = 0;
            D_80071E38 = 0;
            D_80071E3C = 0;
            D_8009AC13 = 2;
            break;
        case 1:
            D_8009A100 = 1;
            D_8009AC13 = 1;
            break;
        case 2:
        case 3:
            D_8009A100 = 1;
            D_80075CF8 = 0;
            D_8009AC13 = 1;
            D_8009C558 = D_8009AC14;
            D_80075E14 = D_80071E38;
            D_80075E1C = D_80071E3C;
            break;
        case 4:
            D_8009A100 = 1;
            D_8009AC13 = 2;
            D_80071E38 = D_8009ABFE;
            D_80071E3C = D_8009AC00;
            break;
        case 5:
        case 6:
            D_8009A100 = 1;
            D_80075CF8 = 0;
            D_8009AC13 = 1;
            D_8009C558 = D_8009AC14;
            D_80075E14 = D_80071E38;
            D_80075E1C = D_80071E3C;
            D_80075E18 = D_8009ABFE;
            D_80075E20 = D_8009AC00;
            break;
        case 7:
        case 8:
        case 9:
            break;
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A45D4);

void func_800A47F8(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 temp_v1_2;

    temp_v0 = M2C_FIELD(D_800716C4, s16 *, 0x10);
    if ((temp_v0 - 0xA0) < M2C_FIELD(arg0, s16 *, 0)) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (temp_v0 - 0xA0);
    }
    temp_v1 = M2C_FIELD(D_800716C4, s16 *, 0xC);
    if (M2C_FIELD(arg0, s16 *, 0) < (temp_v1 + 0xA0)) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (temp_v1 + 0xA0);
    }
    temp_v0_2 = M2C_FIELD(D_800716C4, s16 *, 0x12);
    if ((temp_v0_2 - 0x78) < M2C_FIELD(arg0, s16 *, 2)) {
        M2C_FIELD(arg0, s16 *, 2) = (s16) (temp_v0_2 - 0x78);
    }
    temp_v1_2 = M2C_FIELD(D_800716C4, s16 *, 0xE);
    if (M2C_FIELD(arg0, s16 *, 2) < (temp_v1_2 + 0x78)) {
        M2C_FIELD(arg0, s16 *, 2) = (s16) (temp_v1_2 + 0x78);
    }
}

void func_800A48B8(s32 arg0) {
    s16 v[3];
    u8 *p = &D_8009AC12;

    v[0] = D_80074EB0[*p * 33] >> 12;
    v[1] = D_80074EB4[*p * 33] >> 12;
    v[2] = (D_80074EB8[*p * 33] >> 12) + D_8009AC0A;
    func_800A41CC((s32)v, arg0);
}

void func_800A496C(void) {
    struct { s16 x; s16 y; } p;

    if (D_8009AC13 == 1) {
        switch (D_8009AC11) {
        case 0:
            break;
        case 1:
            func_800A48B8((s32)&p);
            func_800A47F8(&p);
            D_80071E38 = -p.x;
            D_80071E3C = -p.y;
            break;
        case 2:
            func_800A48B8((s32)&p);
            func_800A47F8(&p);
            D_80071E38 = func_800A4094((s16)D_80075E14, -p.x, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4094((s16)D_80075E1C, -p.y, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 3:
            func_800A48B8((s32)&p);
            func_800A47F8(&p);
            D_80071E38 = func_800A4134((s16)D_80075E14, -p.x, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4134((s16)D_80075E1C, -p.y, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 5:
            D_80071E38 = func_800A4094((s16)D_80075E14, (s16)D_80075E18, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4094((s16)D_80075E1C, (s16)D_80075E20, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 6:
            D_80071E38 = func_800A4134((s16)D_80075E14, (s16)D_80075E18, (s16)D_8009C558, D_80075CF8);
            D_80071E3C = func_800A4134((s16)D_80075E1C, (s16)D_80075E20, (s16)D_8009C558, D_80075CF8);
            if ((s16)D_8009C558 == D_80075CF8) {
                D_8009AC13 = 2;
            } else {
                D_80075CF8 = D_80075CF8 + 1;
            }
            break;
        case 9:
            break;
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A4BEC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A5FB4);

void func_800A635C(s32 arg0, s16 arg1) {
    if (D_8009AC26 == 0) {
        if (D_8009AC6C & 8) {
            D_80074ED9[arg1 * 0x84] = 0xE0;
            return;
        }
        if (D_8009AC6C & 4) {
            D_80074ED9[arg1 * 0x84] = 0x20;
            return;
        }
        D_80074ED9[arg1 * 0x84] = 0;
    }
}

void func_800A6418(s32 arg0) {
    u8 m;
    u8 *p;
    u8 *base;
    u16 v;

    m = ((u8 *)D_8008357C)[arg0 * 8 + 4];
    if (m != 0xFF) {
        p = D_8004A62C[1] + m * 0x24;
        base = (u8 *)(*(u16 *)(p + 0x1A) + *(s32 *)(p + 0x1C));
        if (D_8009AC27 == 0) {
            D_80074F02[arg0].x4 += D_80074F02[arg0].x2;
            if (arg0 == D_800965E0 && D_8009AC26 == 0) {
                v = D_80074F02[arg0].x6 = *(u16 *)(base + D_80074F02[arg0].x0 * 16) - 1;
                if ((s16)v << 4 < D_80074F02[arg0].x4) {
                    D_80074F02[arg0].x4 = 0;
                }
            } else {
                v = D_80074F02[arg0].x6;
                if ((s16)v * 16 < D_80074F02[arg0].x4) {
                    D_80074F02[arg0].x4 = v << 4;
                }
            }
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A65A4);

void func_800A82A0(void *arg0) {
    D_8009ABF5 = 1;
    D_8009ABF6 = M2C_FIELD(arg0, u16 *, 0x12);
    D_8009ABF8 = M2C_FIELD(arg0, u16 *, 0xC);
    D_8009ABFA = M2C_FIELD(arg0, u16 *, 0xE);
    D_8009AC16 = M2C_FIELD(arg0, u16 *, 0x10);
    D_8009AC18 = (s16) M2C_FIELD(arg0, u8 *, 0x14);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8304);

s16 func_800A8600(u8 arg0) {
    return D_800DF120[arg0].a;
}

s16 func_800A8620(u8 arg0) {
    return D_800DF120[arg0].b;
}

s32 func_800A8640(FdVec *arg0, FdVec *arg1, s32 *arg2) {
    s32 dx;
    s32 dy;
    s32 d;
    s32 a;
    s32 t;

    dx = arg1->x - arg0->x;
    dy = arg1->y - arg0->y;
    t = dx * dx + dy * dy;
    *arg2 = t;
    d = (*arg2 = func_80039F5C(t));
    dx = (dx << 12) / d / 32;
    dy = (dy << 12) / d / 32;
    if (dx * dx > dy * dy) {
        if (dx > 0) {
            if (dy > 0) {
                a = D_800DEF88[dy * 2];
            } else {
                a = -D_800DEF88[-dy * 2];
            }
        } else if (dy > 0) {
            a = -0x80 - D_800DEF88[dy * 2];
        } else {
            a = D_800DEF88[-dy * 2] - 0x80;
        }
    } else if (dy > 0) {
        if (dx > 0) {
            a = 0x40 - D_800DEF88[dx * 2];
        } else {
            a = D_800DEF88[-dx * 2] + 0x40;
        }
    } else if (dx > 0) {
        a = D_800DEF88[dx * 2] - 0x40;
    } else {
        a = -0x40 - D_800DEF88[-dx * 2];
    }
    return (a + 0x40) & 0xFF;
}

s32 func_800A8858(FdMover *e, s16 step) {
    FdVec a;
    FdVec b;
    s32 d;
    s32 r;

    a.x = e->x >> 12;
    a.y = e->y >> 12;
    b.x = e->tx >> 12;
    b.y = e->ty >> 12;
    d = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    r = e->x6C + step;
    r = r * r + 0x1000;
    if (step != 0 && r >= d) {
        return 0;
    }
    if (d < (e->x70 * e->x70) >> 16 || d < 4) {
        e->x = e->tx;
        e->y = e->ty;
        return 0;
    }
    e->x36 = func_800A8640(&a, &b, &d) - e->x35;
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8968);

void func_800A8DF4(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg2, s16 *, 0));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg1, s16 *, 2) - M2C_FIELD(arg2, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg2, s16 *, 4));
}

s32 func_800A8E34(FdVec *a, FdVec *b, FdVec *c, s16 *d) {
    s32 n[3];

    n[0] = -a->y * b->z + b->y * a->z;
    n[1] = -a->z * b->x + a->x * b->z;
    n[2] = -a->x * b->y + b->x * a->y;
    a->x = d[0];
    a->y = d[1];
    a->z = d[2];
    return (n[0] * a->x + n[1] * a->y + n[2] * a->z - n[0] * c->x - n[1] * c->y) / n[2];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8F88);

s32 func_800A9B64(s16 arg0, FdVec *arg1) {
    s16 i;
    s32 hit;
    s32 r0;
    s32 r;
    s32 dx;
    s32 dy;

    hit = 0;
    r0 = D_80074EFC[arg0].x14;
    for (i = 0; i < D_8009AC1C[0]; i++) {
        if (i != arg0 && D_80074EFC[i].x1 == 0) {
            if ((u32)((D_80074EB8[i * 33] >> 12) - arg1->z + 0x7E) < 0xFE) {
                r = (r0 + D_80074EFC[i].x14) >> 1;
                r *= r;
                dx = (D_80074EB0[i * 33] - arg1->x) >> 12;
                dy = (D_80074EB4[i * 33] - arg1->y) >> 12;
                if (dx * dx + dy * dy < r) {
                    hit = 1;
                    if (arg0 == D_800965E0) {
                        D_80074EFC[i].x0 = 1;
                    }
                }
            }
        }
    }
    return hit;
}

s32 func_800A9CE8(FdGate18 *g, s32 *pos, s32 *out) {
    s32 t;

    t = -(((g->x0 - pos[0]) * (g->x1 - g->x0) + (g->y0 - pos[1]) * (g->y1 - g->y0) + (g->z0 - pos[2]) * (g->z1 - g->z0)) << 8)
        / ((g->x1 - g->x0) * (g->x1 - g->x0) + (g->y1 - g->y0) * (g->y1 - g->y0) + (g->z1 - g->z0) * (g->z1 - g->z0));
    out[0] = ((t * (g->x1 - g->x0)) >> 8) + g->x0;
    out[1] = ((t * (g->y1 - g->y0)) >> 8) + g->y0;
    out[2] = ((t * (g->z1 - g->z0)) >> 8) + g->z0;
    if ((g->x0 - out[0] >= 0 && g->x1 - out[0] <= 0) || (g->x0 - out[0] <= 0 && g->x1 - out[0] >= 0)) {
        if ((g->y0 - out[1] >= 0 && g->y1 - out[1] <= 0) || (g->y0 - out[1] <= 0 && g->y1 - out[1] >= 0)) {
            t = (out[0] - pos[0]) * (out[0] - pos[0]) + (out[1] - pos[1]) * (out[1] - pos[1]) + (out[2] - pos[2]) * (out[2] - pos[2]);
        } else {
            t = -1;
        }
    } else {
        t = -1;
    }
    return t;
}

s32 func_800A9EEC(u8 *e, FdGateT *t, s32 *v) {
    s32 i;
    s32 d;
    s32 on;
    s32 ret;
    s32 *pos;
    s32 *b;
    s32 *out;
    s32 sp10;
    s32 c1;
    s32 c2;

    b = (s32 *)0x1F800010;
    out = (s32 *)0x1F800020;
    pos = (s32 *)0x1F800000;
    pos[0] = M2C_FIELD(e, s32 *, 0xC) >> 12;
    pos[1] = M2C_FIELD(e, s32 *, 0x10) >> 12;
    ret = 0;
    pos[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    i = 0;
    b[0] = v[0] >> 12;
    on = 1;
    b[1] = v[1] >> 12;
    b[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    for (; i < 32; i++, t++) {
        if (t->xC == on) {
            t->x15 = 0;
            d = func_800A9CE8(t, pos, out);
            sp10 = d;
            if (d != -1 && d < M2C_FIELD(e, u16 *, 0x6C) * M2C_FIELD(e, u16 *, 0x6C)) {
                if (t->x16 == on) {
                    ret = 1;
                }
                if (t->xE == 0) {
                    t->x12 = on;
                }
                t->xE = on;
                c1 = (t->x1 - t->x0) * (pos[1] - t->y0) - (pos[0] - t->x0) * (t->y1 - t->y0);
                c2 = (t->x1 - t->x0) * (b[1] - t->y0) - (b[0] - t->x0) * (t->y1 - t->y0);
                if ((c1 >= 0 && c2 < 0) || (c2 >= 0 && c1 < 0) || (c1 > 0 && c2 <= 0) || (c2 > 0 && c1 <= 0)) {
                    t->xF = on;
                }
                if ((pos[0] == out[0] && pos[1] == out[1]) || (t->x14 = func_800A8640((FdVec *)pos, (FdVec *)out, &sp10), ((t->x14 - e[0x36] + 0x40) & 0xFF) < 0x80)) {
                    t->x10 = on;
                    t->x15 = on;
                }
            } else {
                if (t->xE == on) {
                    t->x13 = on;
                }
                t->xE = 0;
            }
        }
    }
    return ret;
}

void func_800AA180(u8 *e, FdTrig18 *t) {
    s32 i;
    s32 d;
    s32 on;
    s32 *pos;
    s32 *out;
    s32 *pad;

    out = (s32 *)0x1F800010;
    i = 0;
    on = 1;
    pos = (s32 *)0x1F800000;
    pos[0] = M2C_FIELD(e, s32 *, 0xC) >> 12;
    pos[1] = M2C_FIELD(e, s32 *, 0x10) >> 12;
    pos[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    pad = &D_8009AC6C;
    for (; i < 32; i++, t++) {
        if (t->xC == on && e[0x5D] == 0) {
            d = func_800A9CE8(t, pos, out);
            if (d != -1 && d < M2C_FIELD(e, u16 *, 0x6C) * M2C_FIELD(e, u16 *, 0x6C)) {
                if (t->xE == 0) {
                    t->x12 = on;
                }
                t->xE = on;
            } else {
                if (t->xE == on) {
                    t->x13 = on;
                }
                t->xE = 0;
            }
            if (t->x15 == on && ((t->x14 - e[0x36] + 0x20) & 0xFF) < 0x40 && (pad[0] & 0x20) && !(pad[1] & 0x20)) {
                t->x11 = on;
            }
        }
    }
}

void func_800AA32C(void *arg0) {
    s32 var_v0;
    void *var_a0;

    var_a0 = arg0;
    var_v0 = 0x1F;
    do {
        M2C_FIELD(var_a0, s8 *, 0x15) = 0;
        var_v0 -= 1;
        var_a0 += 0x18;
    } while (var_v0 >= 0);
}

void func_800AA348(u8 *e, FdGate18 *g, s32 *v) {
    s32 i;
    s32 d;
    s32 *pos;
    s32 *pos2;
    s32 *out;
    s32 c1;
    s32 c2;

    pos2 = (s32 *)0x1F800010;
    pos = (s32 *)0x1F800000;
    pos[0] = M2C_FIELD(e, s32 *, 0xC) >> 12;
    pos[1] = M2C_FIELD(e, s32 *, 0x10) >> 12;
    out = (s32 *)0x1F800020;
    pos[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    pos2[0] = v[0] >> 12;
    pos2[1] = v[1] >> 12;
    pos2[2] = M2C_FIELD(e, s32 *, 0x14) >> 12;
    for (i = 0; i < 12; i++, g++) {
        if (g->map != 0x7FFF) {
            d = func_800A9CE8(g, pos, out);
            if (d != -1 && d < M2C_FIELD(e, u16 *, 0x6C) * M2C_FIELD(e, u16 *, 0x6C)) {
                c1 = (g->x1 - g->x0) * (pos[1] - g->y0) - (pos[0] - g->x0) * (g->y1 - g->y0);
                c2 = (g->x1 - g->x0) * (pos2[1] - g->y0) - (pos2[0] - g->x0) * (g->y1 - g->y0);
                if ((c1 >= 0 && c2 < 0) || (c2 >= 0 && c1 < 0) || (c1 > 0 && c2 <= 0) || (c2 > 0 && c1 <= 0)) {
                    func_800A82A0(g);
                }
            }
        }
    }
}

s32 func_800AA514(u8 *p, u8 op) {
    s32 ret;
    u8 bit;
    u8 v;

    ret = 0;
    switch (op) {
    case 0:
    case 2:
    case 4:
        bit = 1 << p[0xD];
        v = D_8009ACE6[p[0xC]];
        if (!(v & bit)) {
            ret = 1;
        }
        D_8009ACE6[p[0xC]] = bit | v;
        break;
    case 1:
    case 3:
    case 5:
        if ((u8)(D_8009ACE6[p[0xC]] | ~(1 << p[0xD])) == 0xFF) {
            ret = 1;
        }
        D_8009ACE6[p[0xC]] = ~(1 << p[0xD]) & D_8009ACE6[p[0xC]];
        break;
    }
    return ret;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A00BC);

void func_800AA5E4(u8 *e, u8 *g) {
    FdTbl4 tbl;
    s32 i;
    s32 d;
    s16 r;
    u8 op;
    s32 *pos;
    s32 *out;

    out = (s32 *)0x1F800020;
    tbl = D_800A00BC;
    i = 0;
    pos = (s32 *)0x1F800000;
    pos[0] = *(s32 *)(e + 0xC) >> 12;
    pos[1] = *(s32 *)(e + 0x10) >> 12;
    pos[2] = *(s32 *)(e + 0x14) >> 12;
    for (; i < 12; i++, g += 0x10) {
        if (g[0xC] != 0xFF) {
            d = func_800A9CE8((FdGate18 *)g, pos, out);
            if (d != -1 && d < *(u16 *)(e + 0x6C) * *(u16 *)(e + 0x6C)) {
                if (pos[0] == out[0] && pos[1] == out[1]) {
                    r = func_800AA514(g, g[0xE]);
                    if (r == 1) {
                        func_8001117C(tbl.v[g[0xF]]);
                    }
                } else {
                    if ((((u8)func_800A8640((FdVec *)pos, (FdVec *)out, &d) - e[0x36] + 0x40) & 0xFF) < 0x80) {
                        r = func_800AA514(g, g[0xE]);
                        if (r == 1) {
                            func_8001117C(tbl.v[g[0xF]]);
                        }
                    }
                }
            } else {
                op = g[0xE];
                if (op >= 4) {
                    if ((*(s16 *)(g + 6) - *(s16 *)g) * (pos[1] - *(s16 *)(g + 2)) - (*(s16 *)(g + 8) - *(s16 *)(g + 2)) * (pos[0] - *(s16 *)g) > 0) {
                        continue;
                    }
                }
                if (op == 2 || op == 4) {
                    r = func_800AA514(g, 1);
                    if (r == 1) {
                        func_8001117C(tbl.v[g[0xF]]);
                    }
                }
                if (g[0xE] == 3 || g[0xE] == 5) {
                    r = func_800AA514(g, 0);
                    if (r == 1) {
                        func_8001117C(tbl.v[g[0xF]]);
                    }
                }
            }
        }
    }
}

void func_800AA870(u8 *p) {
    s32 i;

    i = 0;
    do {
        if (p[0xC] != 0xFF) {
            switch (p[0xE]) {
            case 0:
            case 2:
            case 4:
                func_800AA514(p, 1);
                break;
            case 1:
            case 3:
            case 5:
                func_800AA514(p, 0);
                break;
            }
        }
        i++;
        p += 0x10;
    } while (i < 12);
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text2", D_800A00DC);

void func_800AA930(void) {
    u32 i;
    u8 **nv;
    u32 t;
    u8 *q;

    D_800DFCA0 = 0x80128000;
    t = func_800ADAA4(D_8007E770, D_8004A62C);
    D_80075E10 = t;
    D_800E0204 = t;
    func_80033E74(D_800DA5C0[(s16)D_8009A05C * 6 + 2], D_800DA5C0[(s16)D_8009A05C * 6 + 3], 0x801B0000, 0);
    while (func_80034B44() != 0) {
    }
    *(s32 *)0x1F800000 = (s32)&D_800DF08C;
    *(s32 *)0x1F800004 = (s32)&D_800DF0D4;
    D_80075E10 = func_800ADC90((u8 *)D_8007E770, (s32)D_8004A62C, D_80075E10, 1);
    D_80075E10 = func_800AC35C(D_8007E770, D_8004A62C, &D_800A00DC, 0x801B0000);
    for (i = 1; i < *(u8 *)D_8004A62C; i++) {
        *(u8 *)(D_8004A62C[1] + i * 0x24) = 0;
    }
    for (i = 0; i < *(u8 *)D_8004A62C; i++) {
        *(u8 *)0x1F800001 = 1;
        *(u8 *)0x1F800002 = 0;
        nv = &D_8004A62C[1];
        *(u8 *)0x1F800003 = i;
        q = (u8 *)(*nv + i * 0x24);
        *(u8 *)0x1F800000 = 1;
        func_800B1C7C(q, (u8 *)0x1F800000);
    }
    func_800AFDE4();
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AAB24);

void func_800AB2AC(void) {
}

void func_800AB2B4(void) {
    s32 var_v0;

    if (((u16) D_80114488 == 0) || (D_8009AC2D == 1)) {
        var_v0 = *D_80083578;
    } else {
        var_v0 = D_80083270;
    }
    D_80071E40 = var_v0;
}

void func_800AB310(void) {
    u8 *p;

    if (D_800965E8 == 1) {
        if (func_80034B44() == 0) {
            D_800965E8 = 2;
        }
        return;
    }
    p = &D_8009ABF5;
    if (*p == 0x14) {
        func_80035658();
        D_80114488 = 0;
        D_800E4D44 = 0;
        D_8009AC1A = 2;
        return;
    }
    switch (func_80034B44()) {
    case 0:
        if (*p == 3 && D_8009AC1A == 0) {
            if (D_80075E10 <= 0x801AFFFF) {
                func_80034FC8(D_80075E10, (s16)D_8009ABF6);
            } else {
                func_80034FC8(0x801B0000, (s16)D_8009ABF6);
            }
            D_8009AC1A = 1;
            D_800E4D44 = 1;
        }
        if (D_80114488 == 1) {
            D_801142C8 = 1;
            D_80114488 = 0;
            D_800E4D44 = 0;
            D_8009AC1A = 2;
        }
        break;
    case 10:
        if (*p == 3) {
            D_8009AC1A = 2;
        }
        if (*p == 4) {
            D_8009AC1A = 1;
            func_800354CC();
            D_80114488 = 1;
        }
        break;
    }
}

void func_800AB4AC(FdSprBuf *arg0) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_800E42E8[i].x6 = 0;
        D_800E42E8[i].x2 = i * 4;
        D_800E42E8[i].x0 = i % 8;
        func_800469C4(&arg0->prims[i]);
        func_80046848(&arg0->prims[i], 1);
        arg0->prims[i].r0 = 0x10;
        arg0->prims[i].g0 = 0x10;
        arg0->prims[i].b0 = 0x10;
    }
    func_80044A68(arg0->dm, 0, 0, func_8004656C(0, 1, 0, 0) & 0xFFFF, 0);
}

void func_800AB5E8(u32 *ot, FdLineF2 *prims, s32 arg2, u32 *tag) {
    s32 p;
    s32 flag;
    s32 i;

    func_8003AE38();
    func_8003B48C(arg2);
    func_8003B51C(arg2);
    for (i = 0; i < 64; i++) {
        if (D_800E42D8[i].x6 == 1) {
            func_8003BBDC(&D_800E42D8[i].a, &prims->xy0, &p, &flag);
            func_8003BBDC(&D_800E42D8[i].b, &prims->xy1, &p, &flag);
            func_80046794((s32)ot, (s32)prims);
        }
        prims++;
    }
    func_8003AED8();
    *tag = (*tag & 0xFF000000) | (*ot & 0xFFFFFF);
    *ot = (*ot & 0xFF000000) | ((u32)tag & 0xFFFFFF);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AB728);

u8 func_800AB9C8(void) {
    D_8009C540 += 1;
    if (D_8009C540 == 0) {
        D_8009AD2C += 0xD;
    }
    return D_800E0638[D_8009C540] - D_8009AD2C;
}

u8 func_800ABA34(void) {
    D_80071C20 += 1;
    return D_800E0638[D_80071C20];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ABA70);

void func_800ABF0C(SPRT16 *p, void *arg1) {
    s16 i;

    i = 0;
    do {
        func_8004694C(p);
        func_80046870(p, 1);
        func_80046848(p, 0);
        p->r0 = 0x80;
        p->g0 = 0x80;
        p->b0 = 0x80;
        p->clut = func_80046634(0x100, 0x1E9);
        i++;
        p++;
    } while (i < 24);
    func_80044A68(arg1, 0, 1, func_8004656C(0, 0, 0x3C0, 0x100) & 0xFFFF, 0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ABFE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AC35C);

s32 func_800ACBA0(Unk800ACBA0 *arg0, s32 arg1, s32 arg2) {
    s32 base;
    u32 i;

    arg0->unk20 = arg1;
    arg1 += arg0->unk2 << 5;
    base = arg0->unk18 + arg0->unk1C;
    for (i = 0; i < arg0->count; i++) {
        arg1 = func_800ACC5C(base + i * 0x20, arg1, 0, arg2);
    }
    func_800AF6EC(arg0, arg0->unk16, 0);
    return arg1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ACC5C);

void func_800AD7B8(void *arg0) {
    Func800AD7B8Hdr *h = arg0;
    Func800AD7B8Entry *e;
    u16 rect[4];
    u32 i;
    u32 n;

    i = 0;
    n = h->n;
    e = h->e;
    for (; i < n; i++) {
        rect[0] = e[i].x;
        rect[1] = e[i].y;
        rect[2] = e[i].w;
        rect[3] = e[i].h;
        func_80044000(rect, (u8 *) h + e[i].off);
    }
}

void func_800AD858(FdLdHdr *h) {
    s32 n;
    s32 i;
    s32 t;
    FdLdEnt *p;
    FdLdEnt *e;

    if (h != 0) {
        n = h->count;
        if (n != 0) {
            p = h->e;
            for (i = 0; i < n; i++) {
                e = &p[i];
                switch (e->type) {
                case 0:
                    func_80042D98(e->arg, (u8 *)h + e->off, e->len);
                    break;
                case 1:
                    if ((u32)e->arg < *(u16 *)(D_800DFCA0 + 4)) {
                        t = D_800DFCA0 + *(s32 *)(D_800DFCA0 + 8) + (e->arg << 9);
                        *(FdBlk200 *)t = *(FdBlk200 *)((u8 *)h + e->off);
                    }
                    break;
                case 2:
                    if ((u32)e->arg < *(u16 *)(D_800DFCA0 + 6)) {
                        *(FdBlk20 *)(D_800DFCA0 + *(s32 *)(D_800DFCA0 + 0xC) + (e->arg << 5)) = *(FdBlk20 *)((u8 *)h + e->off);
                    }
                    break;
                case 3:
                    func_80044000(&e->arg, (u8 *)h + e->off);
                    break;
                }
            }
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ADAA4);

s32 func_800ADC90(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 saved;
    s32 *q;
    u32 i;

    saved = *(s32 *)0x1F800000;
    q = *(s32 **)0x1F800004;
    for (i = 0; i < *(u16 *)(arg0 + 2); i++) {
        *(s32 *)0x1F800000 = saved;
        arg2 = func_800ADD70(arg0, arg1, arg2, i);
    }
    if (arg3 != 0) {
        func_80033E74(q[0], q[1], D_800DFCA0, 0);
        while (func_80034B44() != 0) {
        }
    }
    return arg2;
}
