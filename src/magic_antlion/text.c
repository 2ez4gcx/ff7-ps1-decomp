#include "common.h"
#include "magic_antlion/decls.h"

void func_801B0040(void) {
    func_801B3D30();
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B0060);

void func_801B0B20(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgHalf *r;
    MgWord *w;

    func_80044AC0((s32)D_801E4084, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801E4084);
    p = (MgHalf *)&D_801E3F5C;
    p->v = D_801E3F6C.v = arg1[2];
    D_801E3F66 = D_801E3F6E = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)p - 0x10));
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801E3F2C;
    w->v = D_8016209C;
    D_80163C74 = func_801B0060((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801E3F48;
    q->v = arg1[2];
    D_801E3F4A = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)q - 0xC));
    func_80044978(D_801E40C4, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801E40C4);
    r = (MgHalf *)&D_801E40DC;
    r->v = arg1[0];
    D_801E40DE = arg1[1];
    func_800449FC(D_801E40D0, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801E40D0);
}

s32 func_801B0D24(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801E4166[-v];
    }
    return v;
}

s32 func_801B0D60(s32 a, s32 b) {
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

void func_801B0E58(s32 arg0, s32 arg1, MgTask *arg2, MgSVec *arg3) {
    MgMat m;

    if (arg1 != -1) {
        func_800D3994(arg0, arg1, arg3);
    } else {
        arg3->vx = D_80151A4C[arg0][0];
        arg3->vy = D_80151A4E[arg0][0];
        arg3->vz = D_80151A50[arg0][0];
    }
    arg3->vx -= arg2->unk14;
    arg3->vy -= arg2->unk18;
    arg3->vz -= arg2->unk1C;
    func_8003BF3C(arg2, &m);
    func_8003B2CC(&m, arg3, arg3);
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B0F48);

void func_801B1EAC(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B0F48)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B1F10(void) {
    MgMat m;

    D_801E3FFC = D_801E3F0C;
    D_801E3FEC = D_801E3F0C;
    if (D_801E3F06 != 0) {
        D_801E4008 = D_801E3F28;
    } else {
        D_801E4008 = -D_801E3F28;
    }
    func_8003A63C(&D_801E3FCC, &D_801E3FEC, &m);
    func_801B0B20(&m, &D_801E400C);
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B1FA0);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B22D4);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B241C);

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B290C);

void func_801B2A7C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    if (p->unk2 < 0x78) {
        func_801B241C(&D_801E4140);
    } else {
        p->unk0 = -1;
        return;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B2B0C);

void func_801B2DF8(void) {
    u8 pad[8];
    MgMat m;
    MgMat *mp;
    MgMat *ep;
    MgTask *p;
    s32 t;
    s32 k;
    s32 u;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x1E) {
        u = 0x1000 - (t << 12) / 30;
    } else {
        t -= 0x1E;
        u = 0;
        if (t >= 0x3C) {
            t -= 0x3C;
            if (t < 0x1E) {
                u = (t << 12) / 30;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    k = u;
    mp = &m;
    func_8003BF8C(&D_801E4028, mp);
    ep = (MgMat *)&D_801E4140;
    m.t[0] = m.t[1] = m.t[2] = 0;
    func_8003A63C(ep, mp, mp);
    k = (((k - 0x1000) << 11) >> 12) + 0x1000;
    func_801B2B0C(mp, k);
    D_801E4028.vy += 0x100;
    func_8003BF8C(&D_801E4030, mp);
    m.t[0] = m.t[1] = m.t[2] = 0;
    func_8003A63C(ep, mp, mp);
    func_801B2B0C(mp, k);
    D_801E4030.vy += 0x80;
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

s32 func_801B2FB0(MgSVec *arg0) {
    s32 dz;
    s32 d;
    s32 t;
    s32 i;
    s32 f;
    s32 y0;
    s32 y1;

    if (D_801E4164 != 0) {
        dz = arg0->vz - D_801E3F28;
        d = arg0->vx * arg0->vx + dz * dz;
        t = ((func_80039F5C(d) / 64) << 12) / D_801E4164;
        i = t / 4;
        if (i < 0x10) {
            y0 = *(s16 *)(D_801E3FC8 + (i << 7) + 2);
            y1 = *(s16 *)(D_801E3FC8 + ((i + 1) << 7) + 2);
            f = ((t - i * 4) << 12) / 4;
            return y0 + (((y1 - y0) * f) >> 12);
        }
    }
    return 0;
}

void func_801B30C4(AlRec *e, MgTask *p) {
    s32 k;

    e->unk168.vy = p->unk6 + func_801B2FB0(&e->unk168);
    if (!(p->unk14 & 0x10)) {
        D_801E4048->rot.vx = D_801E4048->rot.vy = D_801E4048->rot.vz = 0;
        func_8003C21C(&D_801E4048->rot, &D_801E4048->mat);
        if (e->unkC == -1) {
            k = -p->unk6;
            D_801E4048->mat.t[0] = D_801E4048->mat.t[1] = k;
            D_801E4048->mat.t[2] = 0;
        } else {
            D_801E4048->mat.t[0] = e->unk19C;
            D_801E4048->mat.t[1] = -p->unk6;
            D_801E4048->mat.t[2] = e->unk1A0 + e->unkC;
        }
        D_801E4048->v.vx = e->unk8;
        D_801E4048->v.vy = 0;
        D_801E4048->v.vz = e->unkA;
        func_8003B35C(&D_801E4048->mat, &D_801E4048->v);
        func_8003A63C(&e->unk140, &D_801E4048->mat, &D_801E4048->mat);
        func_8003B48C(&D_801E4048->mat);
        func_8003B51C(&D_801E4048->mat);
        func_800D4484(D_801517C0 + 0x406C, 0x20);
        D_80163C74 = func_800D29D4(&D_801E4038, D_801517C0 + 0x406C, 0, D_80163C74);
        func_800D4484(D_801517C0 + 0x406C, 0x40);
    }
}

void func_801B325C(void) {
    MgTask *p;
    AlActor *e;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    e = &D_801518E4[p->unk0];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0) {
            *(AlB8 *)&p->unk4 = *(AlB8 *)&e->vx;
            p->unk14 = e->flags;
            e->flags |= 0x10;
        } else {
            if (t >= 0x78) {
                p->unk0 = -1;
                return;
            }
            func_801B30C4(e, p);
            if (t == 0x77) {
                e->vy = p->unk6;
                e->flags = (e->flags & 0xEB) | (p->unk14 & 0x14);
            }
        }
        p->unk2++;
    }
}

void func_801B338C(void) {
    MgTask *p;
    AlRec2 *e;
    AlFoe *f;
    s32 k;
    s16 t;
    s32 a;
    s32 n;
    s32 r;
    s32 m;
    s32 x;
    s32 *g;
    s32 i;

    p = (MgTask *)&D_80162978[D_8015169C];
    e = (AlRec2 *)&D_801518E4[p->unk0];
    f = &D_800FA6D8[p->unk0];
    if (D_80062D98 == 0) {
        k = p->unk2;
        t = k;
        if (k == 0) {
            *(AlB8 *)&p->unk4 = *(AlB8 *)&e->unk168;
            *(AlB8 *)&p->unkC = *(AlB8 *)&e->unk160;
            p->unk14 = e->flags;
            e->flags |= 0x10;
        } else if (t < 0x5A) {
            func_801B30C4(e, p);
            if (t >= 0xF) {
                n = t - 0xF;
                if (n < 0x3C) {
                    if (n == 0) {
                        func_800D5774(p->unk0);
                    }
                    a = (n << 12) / 60;
                    r = func_801B0D60(a, -0x2FF);
                    D_801E404C.vy += (a << 8) >> 12;
                    func_8003BF8C(&D_801E404C, &D_801E4054->mat);
                    m = 0x1000 - r;
                    x = p->unk4 * m >> 12;
                    g = &D_801E3F28;
                    D_801E4054->rot.vy = 0;
                    D_801E4054->rot.vx = x;
                    x = (p->unk8 - *g) * m >> 12;
                    D_801E4054->rot.vz = x;
                    func_8003B2CC(&D_801E4054->mat, &D_801E4054->rot, &D_801E4054->v);
                    e->unk168 = D_801E4054->v.vx;
                    e->unk16C = D_801E4054->v.vz + *(u16 *)g;
                    e->unk162 += 0x100;
                } else {
                    n = k - 0x4B;
                    if (n < 0xF) {
                        a = (n << 12) / 15;
                        e->c0 = e->c1 = e->c2 = 0;
                        e->unk14 = a;
                        for (i = 0; i < e->unk10; i++) {
                            e->arr[i] |= 8;
                        }
                        for (i = 0; i < f->n; i++) {
                            f->b[i] |= 8;
                        }
                        e->unk162 += 0x100;
                    }
                }
            }
        } else {
            *(AlB8 *)&e->unk168 = *(AlB8 *)&p->unk4;
            *(AlB8 *)&e->unk160 = *(AlB8 *)&p->unkC;
            e->flags |= 2;
            p->unk0 = -1;
            return;
        }
        p->unk2++;
    }
}

void func_801B3708(void) {
    MgTask *p;
    AlPoly *prim;
    AlWork2 *w;
    s16 *q;
    s32 t;
    s32 n;
    u16 x;
    u16 y;
    s16 x2;
    s16 y2;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    prim = (AlPoly *)D_80163C74;
    if (t < 10) {
        prim->rgbc = D_801E4058;
    } else {
        t -= 10;
        if (t < 5) {
            func_8003B710(&D_801E4058, (t << 12) / 5, &prim->rgbc);
            *((u8 *)prim + 7) = 0x2A;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(&D_801E4140);
    func_8003B51C(&D_801E4140);
    q = &p->unk4;
    n = func_8003BBDC(q, &prim->x0, &D_801E405C->p, &D_801E405C->flag);
    w = D_801E405C;
    w->z = n;
    if (!(w->flag & 0x60000)) {
        *(u32 *)prim = 0x05000000;
        x = prim->x0;
        y = prim->y0;
        x2 = x + 2;
        y2 = y + 2;
        prim->y2 = prim->y3 = y2;
        prim->x2 = x;
        prim->x1 = prim->x3 = x2;
        prim->y1 = y;
        func_80046794(D_801517C0 + 0x70 + (w->z >> 2) * 4, prim);
        D_80163C74 = (s32)(prim + 1);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        D_801E405C->rot.vx = 0;
        D_801E405C->rot.vy = 0x80;
        D_801E405C->rot.vz = 0;
        func_8003BF8C(&D_801E405C->rot, &D_801E405C->mat);
        D_801E405C->rot.vx = p->unk4;
        D_801E405C->rot.vy = p->unk6 + p->unkE;
        D_801E405C->rot.vz = p->unk8;
        func_8003B2CC(&D_801E405C->mat, &D_801E405C->rot, (MgSVec *)q);
        y2 = p->unkE;
        p->unkE = y2 * 7 >> 3;
    }
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B3910);

void func_801B3B24(s32 arg0) {
    u8 f;
    s32 t;
    M2C_UNK *fn;
    MgObj20 *p;

    f = D_80151909[arg0][0];
    if ((f & 0x80) && !(f & 4) && !(f & 2)) {
        do {
            t = (D_801E4160 >> arg0) & 1;
        } while (0);
        fn = &func_801B325C;
        if (t) {
            fn = &func_801B338C;
        }
        p = &D_80162978[func_800BBEAC(fn)];
        *(volatile s16 *)&p->unk0 = arg0;
    }
}

void func_801B3BD8(void) {
    MgTask *p;
    s32 t;

    p = (MgTask *)&D_80162978[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801E3F0C, &D_801E4140);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 5) {
            t -= 5;
            if (t < 0x1E) {
                if (t == 0) {
                    func_800BBEAC(&func_801B290C);
                    func_800BBEAC(&func_801B2DF8);
                    func_800BBEAC((M2C_UNK *)func_801B2A7C);
                    func_800D5444(7, 0, 0, func_801B3B24);
                    func_800BBEAC(&func_801B3910);
                    func_800D55F4(0x22, 0x40, 0x105, 0x17F, 0x27E);
                }
            } else {
                t -= 0x1E;
                if (t >= 0x3C) {
                    t -= 0x3C;
                    if (t >= 0x1E) {
                        D_800FAFDC = 0;
                        p->unk0 = -1;
                        func_800D55F4(0x22, 0x40, 0, 0, 0);
                    }
                }
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_antlion/nonmatchings/text", func_801B3D30);
