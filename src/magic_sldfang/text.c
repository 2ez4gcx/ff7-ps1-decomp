#include "common.h"
#include "magic_sldfang/decls.h"

M2C_UNK *func_801B0054(s32 a, s32 b) {
    func_801B3028(a, b, 0);
    return &D_801B94D4;
}

M2C_UNK *func_801B007C(s32 a, s32 b) {
    func_801B3028(a, b, 1);
    return &D_801B94D4;
}

s32 func_801B00A4(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0180(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02FC(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03D8(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B04BC);

void func_801B05DC(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0 + 4;
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32 *, 8) = func_8003BBDC(arg1, arg0 + 0x40, temp_s2, temp_s1);
    func_8003BBDC(arg2, arg0 + 0x44, temp_s2, temp_s1);
}

void func_801B0650(MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;
    MgTag *ot;
    s32 otz;
    s32 sxy;
    s32 flag;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801D4DC4;
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
    D_801D4DC4 = p;
}

void func_801B0754(void) {
    s32 i;
    s32 j;
    MgRing *p;

    for (i = 0; i < 6; i++) {
        p = &D_801D62AC[i];
        p->count = 0;
        p->tail = 0;
        D_801D62AC[i].head = 0;
        for (j = 0x17; j >= 0; j--) {
            D_801D62AC[i].v[j] = 0;
        }
    }
}

void func_801B07B4(MgRing *r, s32 val) {
    s32 head;
    s32 tail;
    s32 count;

    do {
        head = r->head;
        tail = r->tail;
    } while (0);
    count = r->count;
    r->v[head] = val;
    head++;
    count++;
    if (count >= 0x18) {
        count = 0x18;
    }
    if (head >= 0x18) {
        head = 0;
    }
    if (head == tail) {
        count--;
        tail++;
        if (count < 0) {
            count = 0;
        }
        if (tail >= 0x18) {
            tail = 0;
        }
    }
    r->head = head;
    r->tail = tail;
    r->count = count;
}

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B0828);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B0F9C);

void func_801B1720(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgVec scale;
    u8 pad[0x20];
    MgTask *p;
    u16 *frame;
    s32 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801BCDB4;
    *frame = p->unk2;
    rot.vx = 0x400;
    rot.vy = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    rot.vx = 0;
    rot.vy = D_80151A46[D_801D4DD4][0];
    rot.vz = 0;
    func_8003BF8C(&rot, &m2);
    func_8003B16C(&m2, &m1);
    t = p->unk14;
    scale.vx = scale.vz = t;
    scale.vy = t * 2;
    func_8003B35C(&m1, &scale);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    D_801D4DC4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D4DC4);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        p->unk2++;
        p->unkC -= (s16)p->unkC >> 4;
        p->unk10 -= (s16)p->unk10 >> 4;
    }
}

void func_801B18FC(void) {
    MgTask *p;
    s32 i;
    s32 k;
    s16 v;
    u8 pad[56];

    p = &D_80162978[D_8015169C];
    D_801BCDC0.v = p->unk2 / 4;
    k = p->unk14;
    for (i = 0; i < p->unkC; i++) {
        v = D_801D4DF2[k].f[0];
        func_800D4368(&D_801D4DE0[k], v, -(v >> 3));
        D_801D4DC4 = func_800D4D90(D_801BCDB8, D_801517C0 + 0x70, 0xC, D_801D4DC4);
        if (D_80062D98 == 0) {
            D_801D4DE0[k].f[0] += D_801D4DE0[k].f[4];
            D_801D4DE0[k].f[1] += D_801D4DE0[k].f[5];
            D_801D4DE0[k].f[2] += D_801D4DE0[k].f[6];
            D_801D4DE0[k].f[4] -= (s16)D_801D4DE0[k].f[4] >> 4;
            D_801D4DE0[k].f[5] -= (s16)D_801D4DE0[k].f[5] >> 4;
            D_801D4DE0[k].f[6] -= (s16)D_801D4DE0[k].f[6] >> 4;
            k++;
            if (k >= 0xDE) {
                k = 0;
            }
        }
    }
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1B60(void) {
    SfDot *p;
    MgTag *ot;
    MgTask *t;
    s32 sxy;
    s32 flag;
    s32 otz;
    s32 i;
    s32 k;

    p = (SfDot *)D_801D4DC4;
    t = &D_80162978[D_8015169C];
    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    k = t->unk14;
    for (i = 0; i < 0x12; i++) {
        if (D_801D4DDC[k].flag == 0) {
            otz = func_8003BBDC(&D_801D4DDC[k].x, &p->x0, &sxy, &flag);
            if (flag & 0x60000) {
                D_801D4DDC[k].flag = 1;
            } else {
                *(s32 *)&p->r0 = 0x686868;
                p->tag.len = 2;
                p->code = 0x6A;
                ot = (MgTag *)D_801517C0 + (otz >> 2) + 0x1C;
                p->tag.addr = ot->addr;
                ot->addr = (u32)p;
                p++;
                if (D_80062D98 == 0) {
                    D_801D4DDC[k].x += D_801D4DDC[k].vx;
                    D_801D4DDC[k].y += D_801D4DDC[k].vy;
                    D_801D4DDC[k].z += D_801D4DDC[k].vz;
                    k++;
                    if (k >= 0xDE) {
                        k = 0;
                    }
                }
            }
        }
    }
    D_801D4DC4 = (MgLineG2 *)p;
    if (t->unk2 >= 5) {
        t->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        t->unk2++;
    }
}

void func_801B1E04(void) {
    MgSVec rot;
    MgMat m;
    MgVec v;
    u8 pad[16];
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;
    s32 off;
    s32 r;
    s32 t;
    s32 mul;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if ((u16)p->unk2 < 3) {
            k = D_801D4DD8;
            mul = 0xDDD;
            q = &D_80162978[func_800BBEAC(&func_801B18FC)];
            q->unkC = 8;
            q->unk14 = k;
            rot.vx = 0;
            rot.vy = D_80151A46[D_801D4DD4][0];
            rot.vz = 0;
            func_8003BF8C(&rot, &m);
            i = 0;
            off = k * 0x18;
            for (; i < 8; i++) {
                v.vx = func_80042DA8() % 0x1000 - 0x800;
                v.vy = func_80042DA8() % 0x1000 - 0x800;
                v.vz = -(func_80042DA8() % 0x800 + 0x800);
                func_8003A08C(&v, &v);
                func_8003AB84(&m, &v, &v);
                *(s16 *)((u8 *)D_801D4DDC + off) = 0;
                k += 1;
                t = func_80042DA8() % 260;
                *(s16 *)((u8 *)D_801D4DDC + off + 4) = p->unk4 + (t * v.vx >> 12);
                *(s16 *)((u8 *)D_801D4DDC + off + 6) = p->unk6 + (t * v.vy >> 12);
                *(s16 *)((u8 *)D_801D4DDC + off + 8) = p->unk8 + (t * v.vz >> 12);
                r = func_80042DA8();
                t = r % 120 + 0x122;
                *(s16 *)((u8 *)D_801D4DDC + off + 0xC) = t * v.vx >> 12;
                *(s16 *)((u8 *)D_801D4DDC + off + 0xE) = t * v.vy >> 12;
                *(s16 *)((u8 *)D_801D4DDC + off + 0x10) = t * v.vz >> 12;
                t = func_80042DA8() % 0xC00 + 0xC00;
                *(s16 *)((u8 *)D_801D4DDC + off + 0x16) = mul * t >> 12;
                off += 0x18;
                if (k >= 0xDE) {
                    off = 0;
                    k = 0;
                }
            }
            D_801D4DD8 = k;
        }
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
        p->unk2 += 1;
    }
}

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B21B8);

void func_801B27B8(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    SfPos *e;
    s32 k;
    s32 a;
    s32 n;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0xC) {
            k = p->unk14;
            n = 0;
            a = 0;
            do {
                n += 1;
                q = &D_80162978[func_800BBEAC(&func_801B0828)];
                e = &D_801D6534[k];
                q->unk14 = k;
                *(s16 *)((u8 *)q + 0xC) = a;
                q->unk10 = 0x78;
                q->unk12 = -0x258;
                func_800D3994(D_801D4DD4, D_80151919[D_801D4DD4][0], e);
                D_801D6534[k].pos.vy = -0x17C;
                func_801B07B4(&D_801D62AC[k], (s32)e);
                k += 1;
                a += 0x550;
            } while (n < 3);
            p->unk14 = k;
            func_800D55F4(0x20, 0x40, 0x186);
        }
        if (p->unk2 == 0x1B) {
            func_800D3994(D_801D4DD4, D_8015190F[D_801D4DD4][0], &v);
            q = &D_80162978[func_800BBEAC(&func_801B1E04)];
            q->unk4 = p->unk4;
            q->unk6 = v.vy;
            q->unk8 = p->unk8;
            p->unk0 = -1;
            func_800D55F4(0x20, func_800D56A8(&q->unk4), 0x1A3);
        }
        p->unk2 += 1;
    }
}

void func_801B29F8(void) {
    MgSVec v;
    MgTask *p;
    MgTask *q;
    SfPos *e;
    s32 k;
    s32 n;

    if (D_80062D98 == 0) {
        p = &D_80162978[D_8015169C];
        if (p->unk2 == 0xC) {
            k = p->unk14;
            for (n = 0; n < 3; n++) {
                q = &D_80162978[func_800BBEAC(&func_801B0828)];
                e = &D_801D6534[k];
                q->unk14 = k;
                *(s16 *)((u8 *)q + 0xC) = n * 0x550;
                q->unk10 = 0x78;
                q->unk12 = -0x258;
                func_800D3994(D_801D4DD4, D_80151919[D_801D4DD4][0], e);
                D_801D6534[k].pos.vy = -0x17C;
                func_801B07B4(&D_801D62AC[k], (s32)e);
                k += 1;
            }
            p->unk14 = k;
            func_800D55F4(0x20, 0x40, 0x186);
        }
        if (p->unk2 == 0x15) {
            k = p->unk14;
            for (n = 0; n < 3; n++) {
                q = &D_80162978[func_800BBEAC(&func_801B0F9C)];
                q->unk14 = k;
                *(s16 *)((u8 *)q + 0xC) = n * 0x550 + 0x3E8;
                q->unk10 = 0x12C;
                q->unk12 = -0x320;
                func_800D3994(D_801D4DD4, D_80151919[D_801D4DD4][0], &D_801D6534[k]);
                D_801D6534[k].pos.vy = -0x17C;
                func_801B07B4(&D_801D62AC[k], (s32)&D_801D6534[k]);
                k += 1;
            }
            p->unk14 = k;
        }
        if (p->unk2 == 0x1B) {
            func_800D3994(D_801D4DD4, D_8015190F[D_801D4DD4][0], &v);
            q = &D_80162978[func_800BBEAC(&func_801B21B8)];
            q->unk4 = p->unk4;
            q->unk6 = v.vy;
            q->unk8 = p->unk8;
            n = D_801518F6[D_801D4DD4][0] + 0x100;
            if (n >= 0x76D) {
                n = 0x76C;
            }
            q->unkC = n;
            p->unk0 = -1;
            func_800D55F4(0x20, func_800D56A8(&q->unk4), 0x1A3);
        }
        p->unk2 += 1;
    }
}

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B2D80);

INCLUDE_ASM("../asm/us/magic_sldfang/nonmatchings/text", func_801B2ED4);

INCLUDE_RODATA("../asm/us/magic_sldfang/nonmatchings/text", D_801B0000);

void func_801B3028(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK *fn;
    s32 i;
    s32 n;

    D_801D4DC8 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B3118, 0, 0, 0);
    i = 0;
    n = 0;
    D_801D4DCC = arg0;
    do {
        if ((arg0 >> i) & 1) {
            n += 1;
            if (n == 1) {
                D_801D4DD0 = i;
            }
        }
        i += 1;
    } while (i < 0xA);
    D_801D4DD4 = arg1;
    fn = &func_801B2D80;
    if (arg2 != 0) {
        fn = &func_801B2ED4;
    }
    func_800BBEAC(fn);
    D_801D4DD8 = 0;
}
