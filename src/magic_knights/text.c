#include "common.h"
#include "magic_knights/decls.h"

void func_801B0050(void) {
    func_801BE87C();
}

MgMat *func_801B0070(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801EC474.m[0][0] = D_801EC474.m[1][1] = D_801EC474.m[2][2] = scale;
    func_8003B48C(&D_801EE9AC);
    func_8003B51C(&D_801EE9AC);
    func_8003BC6C(v, (MgVec *)D_801EC474.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801EC474.t, &n);
        D_801EC474.t[0] += (dist * n.vx) >> 12;
        D_801EC474.t[1] += (dist * n.vy) >> 12;
        D_801EC474.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801EC474);
    func_8003B51C(&D_801EC474);
    return &D_801EC474;
}

void func_801B018C(s32 arg0, s32 arg1, MgSVec *arg2) {
    MgMat m;

    arg2->vx = D_80151A6C[arg0].c[arg1].x - D_801EE9AC.t[0];
    arg2->vy = D_80151A6C[arg0].c[arg1].y - D_801EE9AC.t[1];
    arg2->vz = D_80151A6C[arg0].c[arg1].z - D_801EE9AC.t[2];
    func_8003BF3C(&D_801EE9AC, &m);
    func_8003B2CC(&m, arg2, arg2);
}

void func_801B0264(MgMat *arg0, MgSVec *arg1) {
    MgMat m;

    arg1->vx = arg0->t[0] - D_801EE9AC.t[0];
    arg1->vy = arg0->t[1] - D_801EE9AC.t[1];
    arg1->vz = arg0->t[2] - D_801EE9AC.t[2];
    ((void (*)(MgMat *, MgMat *, MgMat *))func_8003BF3C)(&D_801EE9AC, &m, arg0);
    func_8003B2CC(&m, arg1, arg1);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B02E8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B0DA8);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B1244);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B15E8);

void func_801B1C30(MgMat *arg0, u16 *arg1) {
    s32 sp10;
    s32 sp14;
    MgHalf *p;
    MgHalf *q;
    MgHalf *r;
    MgWord *w;

    func_80044AC0((s32)D_801ED128, (Spr *)D_800FAFF4[D_800F8368 ^ 1]);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801ED128);
    p = (MgHalf *)&D_801EC4D0;
    p->v = D_801EC4E0.v = arg1[2];
    D_801EC4DA = D_801EC4E2 = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)p - 0x10));
    func_8003B64C(&sp10, &sp14);
    func_8003B6BC((s16)arg1[2] / 2, (s16)arg1[3] / 2);
    func_8003B48C(arg0);
    func_8003B51C(arg0);
    w = (MgWord *)&D_801EC4A0;
    w->v = D_8016209C;
    D_80163C74 = func_801B02E8((s32 *)w, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B6BC(sp10, sp14);
    q = (MgHalf *)&D_801EC4BC;
    q->v = arg1[2];
    D_801EC4BE = arg1[3];
    func_80046794(D_801517C0 + 0x4084, (s32)((u8 *)q - 0xC));
    func_80044978(D_801ED168, arg1);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801ED168);
    r = (MgHalf *)&D_801ED180;
    r->v = arg1[0];
    D_801ED182 = arg1[1];
    func_800449FC(D_801ED174, r);
    func_80046794(D_801517C0 + 0x4084, (s32)D_801ED174);
}

s32 func_801B1E40(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801FA76E[-v];
    }
    return v;
}

s32 func_801B1E7C(s32 a, s32 b) {
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

void func_801B1F74(s32 arg0, s32 arg1, s32 arg2, MgSVec *arg3) {
    u8 pad[0x20];

    if (arg1 != -1) {
        func_801B0264((MgMat *)&D_801ED23C[arg0].e[arg1 * 0x34], arg3);
    } else {
        arg3->vx = D_801ED23C[arg0].v.vx;
        arg3->vy = D_801ED23C[arg0].v.vy;
        arg3->vz = D_801ED23C[arg0].v.vz;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B2048);

void func_801B3154(s32 arg0, s32 arg1, s16 arg2) {
    D_8016207C = &func_801B2048;
    D_801635D8 = 0;
    D_801635E4 = arg0;
    D_801635E8 = arg1;
    D_801635EC = arg2;
    D_80162080 += 1;
}

void func_801B31A0(void) {
    MgTask *p;
    s32 t;
    s32 d;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        d = p->unk6;
        if (t < d) {
            d = (t << 12) / d;
            v = (p->unk4 * d) >> 12;
        } else {
            t -= d;
            if (t < p->unk8) {
                v = p->unk4;
            } else {
                t -= p->unk8;
                d = p->unkA;
                if (t >= d) {
                    p->unk0 = -1;
                    D_800FA666[0] = 0;
                    return;
                }
                d = (t << 12) / d;
                v = (p->unk4 * (0x1000 - d)) >> 12;
            }
        }
        D_800FA666[0] = (p->unk2 & 1) ? v : -v;
        p->unk2++;
    }
}

void func_801B32DC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B31A0)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B3350(void) {
    MgMat m;

    D_801EC868 = D_801EC334;
    D_801EC858 = D_801EC334;
    if (D_801EC32E != 0) {
        D_801EC874 = D_801EC350;
    } else {
        D_801EC874 = -D_801EC350;
    }
    func_8003A63C(&D_801EC838, &D_801EC858, &m);
    func_801B1C30(&m, &D_801EC878);
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B33E0);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B3748);

void func_801B3890(void) {
    MgTask *p;
    s32 t;
    s32 u;
    s32 i;
    s32 j;
    s32 a;
    s32 *src;
    u8 *d;
    u8 *e;
    u8 *n;
    u8 *m;
    u8 *row;
    s32 w;
    s32 x;
    s32 y;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    u = (s16)t;
    if (t == 0) {
        func_801B3350();
        func_801B33E0();
        p->unk2++;
        return;
    }
    if (u < 0x28) {
        if (u < 0xA) {
            a = (u << 12) / 10;
            if (D_80062D98 == 0) {
                a = func_801B1E7C(a, 0x2FF);
                func_801B3748(a * 1000 >> 12, (-(a << 5) >> 12) + 0x80, (-(a * 0x60) >> 12) + 0x80);
            }
        } else {
            a = ((u - 0xA) << 12) / 30;
            if (D_80062D98 == 0) {
                a = func_801B1E7C(a, 0);
                func_801B3748((a * 500 >> 12) + 0x3E8, (-(a * 0x60) >> 12) + 0x60, (-(a << 5) >> 12) + 0x20);
            }
        }
        func_8003B48C(&D_801EE9AC);
        func_8003B51C(&D_801EE9AC);
        for (i = 0; i < 0x10; i++) {
            for (j = 0; j < 0x20; j++) {
                src = (s32 *)(D_801EC834 + (i * 0xF00 + 0x1100) + j * 0x78);
                m = (u8 *)src + (D_801EC880 * 0x34 + 0x10);
                *(s32 *)(D_801EC884 + 0x18) = func_8003BD7C(src[0], src[1], src[2], src[3], m + 8, m + 0x14, m + 0x20, m + 0x2C, D_801EC884 + 0x1C, D_801EC884 + 0x20);
                if ((*(s32 *)(D_801EC884 + 0x20) & 0x60000) == 0) {
                    w = D_801EC880 * 0x34;
                    row = D_801EC834 + i * 4;
                    x = *(s32 *)(row + 0x10100);
                    *(s32 *)(w + (s32)src + 0x20) = x;
                    *(s32 *)(w + (s32)src + 0x14) = x;
                    y = *(s32 *)(row + 0x10104);
                    *(s32 *)(w + (s32)src + 0x38) = y;
                    *(s32 *)(w + (s32)src + 0x2C) = y;
                    func_80046794(D_801517C0 + 0x4078, (u8 *)src + (w + 0x10));
                }
            }
        }
        D_801EC880 ^= 1;
    } else if ((u -= 0x28) < 0x1E) {
        d = D_80163C74;
        e = D_801EC884;
        *(s16 *)(e + 0x12) = 0;
        *(s16 *)(e + 0xA) = 0;
        *(s16 *)(e + 4) = 0;
        *(s16 *)(e + 2) = 0;
        *(s16 *)(e + 0) = 0;
        func_8003B48C(&D_801EE9AC);
        func_8003B51C(&D_801EE9AC);
        n = d + 0x10;
        for (i = 0; i < 0x20; i++) {
            *(s16 *)(D_801EC884 + 8) = (u32)(func_80039A74(i << 7) * 0x11D) >> 8;
            *(s16 *)(D_801EC884 + 0xC) = (u32)(func_80039B40(i << 7) * 0x11D) >> 8;
            *(s16 *)(D_801EC884 + 0x10) = (u32)(func_80039A74((i + 1) << 7) * 0x11D) >> 8;
            *(s16 *)(D_801EC884 + 0x14) = (u32)(func_80039B40((i + 1) << 7) * 0x11D) >> 8;
            func_8003BC0C(D_801EC884, D_801EC884 + 8, D_801EC884 + 0x10, d + 8, d + 0xC, n, D_801EC884 + 0x1C, D_801EC884 + 0x20);
            if ((*(s32 *)(D_801EC884 + 0x20) & 0x60000) == 0) {
                *(s32 *)d = 0x04000000;
                *(s32 *)(n - 0xC) = 0x20000000;
                func_80046794(D_801517C0 + 0x4078, d);
                n += 0x14;
                d += 0x14;
            }
        }
        D_80163C74 = d;
    } else if ((u = t - 0x32) >= 0x1E && (u = t - 0x50) >= 0x1E) {
        p->unk0 = -1;
        return;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B3DB0(void) {
    MgTask *p;
    s32 t;
    s32 f;
    s32 i;
    s32 g;

    p = &D_80162978[D_8015169C];
    func_8003B69C(0, 0, 0);
    t = p->unk2;
    if (t < 0x1E) {
        D_801EC8B8->rot.vz = 0;
        D_801EC8B8->rot.vx = 0;
        D_801EC8B8->rot.vy = p->unk2 * 0x20;
        func_8003C21C(&D_801EC8B8->rot, &D_801EC8B8->b);
        D_801EC8B8->b.t[0] = (D_801EC8B8->b.t[1] = (D_801EC8B8->b.t[2] = 0));
        func_8003A63C(&D_801EE9AC, &D_801EC8B8->b, &D_801EC8B8->b);
        D_801EC8A0[0] = (((t << 12) / 30) << 13) >> 12;
        func_8003A63C(&D_801EC8B8->b, (MgMat *)(D_801EC8A0 - 4), &D_801EC8B8->a);
        func_8003B48C(&D_801EC8B8->a);
        func_8003B51C(&D_801EC8B8->a);
        D_80163C74 = func_800D29D4(D_801EC888, D_801517C0 + 0x70, 0xC, D_80163C74);
    } else {
        t -= 0x1E;
        if (t < 0x1C) {
            D_801EC8B8->rot.vz = 0;
            D_801EC8B8->rot.vx = 0;
            D_801EC8B8->rot.vy = p->unk2 * 0x20;
            func_8003C21C(&D_801EC8B8->rot, &D_801EC8B8->b);
            D_801EC8B8->b.t[0] = (D_801EC8B8->b.t[1] = (D_801EC8B8->b.t[2] = 0));
            func_8003A63C(&D_801EE9AC, &D_801EC8B8->b, &D_801EC8B8->b);
            if (t >= 0x12) {
                t -= 0x12;
                D_801EC892 = (t << 12) / 10;
                func_8003B69C(0, 0, 0);
            }
            t = 0x3E80 - ((p->unk2 * 0x1F4) % 16000);
            if (t >= 0x1F40) {
                t -= 0x1F40;
                f = 1;
            } else {
                f = 0;
            }
            D_801EC8A0[0] = 0x1000;
            func_8003A63C(&D_801EC8B8->b, (MgMat *)(D_801EC8A0 - 4), &D_801EC8B8->a);
            func_8003B48C(&D_801EC8B8->a);
            func_8003B51C(&D_801EC8B8->a);
            i = 0;
            do {
                D_80163C74 = func_801B0DA8(D_801EC888, g, 0, D_80163C74, t, f);
                t -= 0x1F40;
                f ^= 1;
                i++;
            } while (i < 3);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

s32 func_801B40F4(s32 arg0) {
    s32 k;
    s32 a;
    s32 b;

    arg0 = arg0 / 48;
    k = arg0 / 6;
    if (k < 0x10) {
        a = *(s16 *)(D_801EC834 + (k << 8) + 2);
        b = *(s16 *)(D_801EC834 + ((k + 1) << 8) + 2);
        return a + (((b - a) * (((arg0 - k * 6) << 12) / 6)) >> 12);
    }
    return 0;
}

void func_801B4198(void) {
    MgTask *p;
    KnSpr *q;
    s32 t;
    s32 c;
    s32 v;
    s32 s;
    s32 k;
    u16 x;
    u16 y;
    s16 xa;
    s16 yb;
    u8 u;
    s8 ua;
    u8 w;
    s8 wa;

    p = &D_80162978[D_8015169C];
    q = (KnSpr *)D_80163C74;
    t = p->unk2;
    if (t < 5) {
        q->rgbc = 0x2C808080;
    } else {
        t -= 5;
        if (t < 5) {
            c = ((0x1000 - (t << 12) / 5) << 7) >> 12;
            v = (c << 8) | 0x2E000000;
            q->rgbc = c | v | (c << 16);
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(&D_801EE9AC);
    func_8003B51C(&D_801EE9AC);
    D_801EC8BC->r = func_8003BBDC(&p->unk4, &q->x0, &D_801EC8BC->ext, &D_801EC8BC->flag);
    if (!(D_801EC8BC->flag & 0x60000)) {
        s = p->unk0;
        q->tag = 0x09000000;
        x = q->x0;
        y = q->y0;
        xa = x + s;
        yb = y + s;
        q->x2 = x;
        q->x3 = xa;
        q->x1 = xa;
        q->y1 = y;
        q->y3 = yb;
        q->y2 = yb;
        u = *((u8 *)p + 0x1E);
        ua = u + s;
        q->u2 = u;
        q->u0 = u;
        q->u3 = ua;
        q->u1 = ua;
        w = *((u8 *)p + 0x1F);
        wa = w + s;
        q->v1 = w;
        q->v0 = w;
        q->v3 = wa;
        q->v2 = wa;
        q->tpage = 0x12D;
        k = ((D_801EC8BC->r >> 2) << 2) + 0x70;
        func_80046794(k + D_801517C0, (s32)q);
        D_80163C74 = (u8 *)(q + 1);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = (p->unkC * 0xD) >> 4;
        p->unkE = (p->unkE * 0xD) >> 4;
        p->unk10 = (p->unk10 * 0xD) >> 4;
    }
}

void func_801B440C(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 n;
    s32 a;
    s32 r;
    s32 w;
    s32 u;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        n = 0x700;
        if (t >= 0xA) {
            t -= 0xA;
            if (t >= 0x1E) {
                p->unk0 = -1;
                return;
            }
            n = ((0x1000 - (t << 12) / 30) * 0x700) >> 12;
        }
        D_801EC8C0 = n + D_801EC8C0;
        if (n >= 0x100) {
            do {
                n -= 0x100;
                q = &D_80162978[func_800BBEAC(&func_801B4198)];
                q->unk0 = (func_80042DA8() & 1) + 1;
                a = func_80042DA8() & 0x7FF;
                r = ((func_801B1E7C(func_80042DA8() & 0xFFF, 0x1FF) << 11) >> 12) + 0x800;
                r = (r * 0x1200) >> 12;
                q->unk4 = (func_80039A74(a) * r) >> 12;
                q->unk6 = func_801B40F4(r);
                u = func_80039B40(a) * r;
                q->unkC = (q->unk4 << 10) >> 16;
                q->unk8 = u >> 12;
                w = func_80042DA8();
                q->unk10 = (q->unk8 << 10) >> 16;
                q->unkE = -(w % 100 + 0xC8);
                *((u8 *)q + 0x1E) = ((p->unk4 + 0x1200) * 0xBD) / 9216;
                *((u8 *)q + 0x1F) = ((p->unk8 + 0x1200) * 0xBD) / 9216;
            } while (n >= 0x100);
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4694);

void func_801B4B04(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B4694)];
    p->unk0 = arg0;
    p->unkC = func_80042DA8() & 0xFFF;
    D_801FA748[arg0] = p;
}

void func_801B4B70(MgMat *arg0, MgMat *arg1, MgMat *arg2) {
    s32 *t;

    arg2->t[0] = arg1->t[0] - arg0->t[0];
    arg2->t[1] = arg1->t[1] - arg0->t[1];
    arg2->t[2] = arg1->t[2] - arg0->t[2];
    func_8003BF3C(arg0, arg2);
    t = arg2->t;
    func_8003AB84(arg2, t, t);
    func_8003B16C(arg1, arg2);
}

void func_801B4BF8(void) {
    MgTask *p;
    KnLineG3 *q;
    s32 k;

    p = &D_80162978[D_8015169C];
    k = (func_80039A74((p->unk2 << 12) / 8) * 100) >> 12;
    q = (KnLineG3 *)D_80163C74;
    D_801EC8EA = k;
    D_801EC8DA[0] = -k;
    func_8003C21C((MgSVec *)&p->unkC, &D_801EC8F0->m);
    func_8003B48C(&D_801EE9AC);
    func_8003B51C(&D_801EE9AC);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)D_801EC8F0->m.t, &D_801EC8F0->flag);
    func_8003B48C(&D_801EC8F0->m);
    func_8003B51C(&D_801EC8F0->m);
    D_801EC8F0->r = ((s32 (*)(void *, void *, void *, void *, void *, void *, void *, void *))func_8003BC0C)(D_801EC8DA - 1, D_801EC8DA + 3, D_801EC8DA + 7, &q->x0, &q->x1, &q->x2, &D_801EC8F0->ext, &D_801EC8F0->flag);
    if (!(D_801EC8F0->flag & 0x60000)) {
        q->tag.len = 7;
        q->code = 0x58;
        *(s32 *)&q->r0 = 0x5A000000;
        q->end = 0x55555555;
        *(s32 *)&q->r1 = 0x808080;
        *(s32 *)&q->r2 = 0;
        q->tag.addr = ((MgTag *)D_801517C0 + (D_801EC8F0->r >> 2) + 0x1C)->addr;
        ((MgTag *)D_801517C0 + (D_801EC8F0->r >> 2) + 0x1C)->addr = (u32)q;
        D_80163C74 = (u8 *)(q + 1);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        } else {
            p->unk10 = (u16)p->unk10 + 0x200 + func_80042DA8() % 0x400;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B4E78);

void func_801B5670(s32 arg0, s32 arg1, s32 arg2) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B4E78)];
    *(s32 *)&p->unk18 = arg0;
    p->unk1C = arg1;
    *(s32 *)&p->unk14 = arg2;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B56D4);

void func_801B5B24(void *arg0) {
    s32 temp_a1;
    s32 temp_v0;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0xBA0);
    if (temp_a1 != -1) {
        temp_v0 = func_800D376C(arg0 + 0x40, temp_a1, M2C_FIELD(arg0, s16 *, 0xBA4), M2C_FIELD(arg0, s32 *, 0xB9C));
        M2C_FIELD(arg0, s32 *, 0xBA0) = temp_v0;
        if (temp_v0 == 0) {
            M2C_FIELD(arg0, s32 *, 0xBA0) = -1;
        }
    }
}

void func_801B5B7C(u16 *arg0, KnDst *arg1) {
    s16 *a;
    u16 *b;
    s32 n;
    s32 t;
    s32 i;
    u32 w;

    a = (s16 *)arg0 + 2;
    t = arg0[0] + 1;
    arg1->n = t;
    n = (s16)t;
    for (i = 0; i < n; i++) {
        b = (u16 *)a + 2;
        arg1->e[i].unk30 = &arg1->e[*a];
        arg1->e[i].unk2A = 0;
        arg1->e[i].unk28 = 0;
        arg1->e[i].unk2C = arg1->h[*a];
        arg1->h[i] = b[-1];
        w = *(u32 *)b & 0x7FFFFFFF;
        if (w != 0) {
            arg1->p[i] = (u8 *)arg0 + w;
        } else {
            arg1->p[i] = 0;
        }
        a += 4;
    }
}

void func_801B5C5C(KnHdr *arg0, KnDst2 *arg1, void *arg2) {
    MgSVec sp10;
    MgSVec sp18;
    MgMat sp20;
    MgTask *q;
    s32 n;

    q = &D_80162978[func_800BBEAC(arg2)];
    func_800C610C();
    func_801B5B7C((u16 *)((u8 *)arg0 + arg0->unk4 * 4), (KnDst *)arg1);
    n = arg0->unk8 * 4;
    arg1->unkBA0 = 0;
    arg1->unk28 = 0;
    arg1->unk26 = 0;
    arg1->unk24 = 0;
    arg1->unkBA8 = 0;
    arg1->unkA6C = 0;
    arg1->unkA6A = 0;
    arg1->unkA68 = 0;
    arg1->unkBA6 = 0x1000;
    arg1->unkB9C = (u8 *)arg0 + n;
    arg1->unkBB0 = D_801EC354[D_801EC92C];
    arg1->unkBAA = 0;
    arg1->unkBAC = D_801EC370[D_801EC92C];
    arg1->unk0 = 0;
    *(KnDst2 **)((u8 *)q + 0x14) = arg1;
    func_8003B2CC(&D_801EC334, &D_801EC3A4[D_801EC92C * 2], &sp10);
    sp10.vx += D_801EC348;
    sp10.vy += D_801EC34C;
    sp10.vz += *(u16 *)((u8 *)&D_801EC34C + 4);
    func_8003B2CC(&D_801EC334, &D_801EC3A4[D_801EC92C * 2 + 1], &sp18);
    sp18.vx += D_801EC348;
    sp18.vy += D_801EC34C;
    sp18.vz += *(u16 *)((u8 *)&D_801EC348 + 8);
    func_800D85B0(&sp20, &sp18, &sp10, D_800E7D10);
    func_8003A63C(&sp20, &D_801EC334, &arg1->unkBB4);
    D_801EC92C++;
}

s32 func_801B5E4C(void) {
    MgTask *p;
    s32 id;

    if (D_80062D98 == 0) {
        while (1) {
            id = D_801517F0[D_801EC930];
            if (id == 0xFF) {
                break;
            }
            p = func_800D4FA8(0xA);
            p->unk0 = id;
            p->unk10 = D_801EC930;
            D_801EC930++;
            if (D_801517F0[D_801EC930] <= D_801517F0[D_801EC930 - 1]) {
                break;
            }
        }
    }
}

void func_801B5F0C(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_801B0070((MgSVec *)&p->unk4, 0x6000, 0);
    frame = &D_801EC93C;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801C8F74.v) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unkC = p->unkC * 15 >> 4;
            p->unkE = p->unkE * 15 >> 4;
            p->unk10 = p->unk10 * 15 >> 4;
        }
    }
}

void func_801B603C(MgSVec *arg0) {
    MgSVec sp10;
    MgSVec sp18;
    MgVec sp20;
    MgMat sp30;
    MgTask *q;
    s32 i;
    s32 j;

    if (D_80062D98 == 0) {
        for (i = 0; i < 10; i++) {
            if ((D_801EE9CC >> i) & 1) {
                for (j = 0; j < 3; j++) {
                    q = &D_80162978[func_800BBEAC(&func_801B5F0C)];
                    func_801B018C(i, D_8015190F[i][0], &sp10);
                    *(MgB8 *)&q->unk4 = *(MgB8 *)&sp10;
                    sp20.vx = sp10.vx - arg0->vx;
                    sp20.vy = sp10.vy - arg0->vy;
                    sp20.vz = sp10.vz - arg0->vz;
                    func_8003A078(&sp20, &sp10);
                    sp10.vx = sp10.vx >> 4;
                    sp10.vy = sp10.vy >> 4;
                    sp10.vz = sp10.vz >> 4;
                    sp18.vx = func_80042DA8() % 0x200 - 0x100;
                    sp18.vy = func_80042DA8() % 0x200 - 0x100;
                    sp18.vz = func_80042DA8() % 0x200 - 0x100;
                    func_8003C21C(&sp18, &sp30);
                    func_8003B2CC(&sp30, &sp10, (MgSVec *)&q->unkC);
                }
            }
        }
    }
}

void func_801B6248(void) {
    MgTask *temp_s0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            func_800D5138(1);
        } else if (temp_v1 == 1) {
            func_800D51D4(7);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801B62D4(void *arg0) {
    M2C_UNK sp10;

    func_801B0264(arg0 + ((M2C_FIELD(arg0, s16 *, 0xBB0) * 0x34) + 0x40), &sp10);
    func_801B603C(&sp10);
}

void func_801B631C(MgTask *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    u8 c[3];
    s16 t;

    func_8003B69C(0, 0, 0);
    func_8003B710(arg4, arg5, c);
    t = arg0->unkA;
    arg0->unkA = t + (((0x1000 - t) * arg5) >> 12);
    func_8003B69C(c[0], c[1], c[2]);
    func_800D29D4(arg0, arg1, arg2, arg3);
}

void func_801B63E4(void) {
    MgTask *p;
    KnPar *q;
    s32 t;
    s32 k;
    s32 *d;
    s16 *frame;

    p = &D_80162978[D_8015169C];
    q = M2C_FIELD(p, KnPar **, 0xC);
    t = (p->unk2 << 12) / q->unk4;
    k = func_801B1E7C(t, q->unk12);
    D_801EC950->rot.vx = D_801EC950->rot.vz = 0;
    D_801EC950->rot.vy = (q->unk10 * k) >> 12;
    func_8003C21C(&D_801EC950->rot, &D_801EC950->m1);
    func_8003C21C(&q->rot, &D_801EC950->m2);
    func_8003B16C(&D_801EC950->m2, &D_801EC950->m1);
    D_801EC950->m1.t[0] = p->unk4;
    D_801EC950->m1.t[1] = p->unk6;
    D_801EC950->m1.t[2] = p->unk8;
    D_801EC950->scale.vx = D_801EC950->scale.vy = D_801EC950->scale.vz = q->unk6 + (((q->unk8 - q->unk6) * func_801B1E7C(t, q->unkA)) >> 12);
    func_8003B35C(&D_801EC950->m1, &D_801EC950->scale);
    k = func_801B1E7C(t, q->unkE);
    frame = &D_801EC94A;
    *frame = k;
    func_8003A63C(&D_801EE9AC, &D_801EC950->m1, &D_801EC950->m1);
    func_8003B48C(&D_801EC950->m1);
    func_8003B51C(&D_801EC950->m1);
    d = (s32 *)((u8 *)frame - 0xA);
    *d = q->unk0;
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(d, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= q->unk4) {
            p->unk0 = -1;
        }
    }
}

void func_801B6624(s32 arg0, void *arg1) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B63E4)];
    temp_v0->unk4 = (s16) M2C_FIELD(arg1, u16 *, 0);
    temp_v0->unk6 = (s16) M2C_FIELD(arg1, u16 *, 2);
    temp_v0->unk8 = (s16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg0;
}

void func_801B6690(s32 arg0) {
    func_801B6624((s32)&D_801EC954, &D_801EE9D8[arg0]);
}

void func_801B66C4(void) {
    MgTask *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE9CC >> i) & 1) {
                    func_801B018C(i, D_8015190F[i][0], &D_801EE9D8[i]);
                }
            }
        }
        func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B6690);
        p->unk2++;
        if (p->unk2 > 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B67C4(void) {
    MgTask *p;
    KnCam *r;
    s32 t;
    s32 a;
    s16 w;
    s32 x;

    p = &D_80162978[D_8015169C];
    r = *(KnCam **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x56, (s32)D_801EC974);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x32) {
            func_801B62D4(r);
            func_800BBEAC((M2C_UNK *)func_801B66C4);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x1E) {
            if (t == 0) {
                r->unkBA8 = 1;
                r->unk26 = -0x1F4;
                r->unk24 = 0;
                r->unk28 = 0x2710;
            }
            a = func_801B1E7C((t << 12) / 30, -0x3D0);
            w = (-(a << 10) >> 12) + 0x400;
            D_801ED1E4 = 0xBB8;
            D_801ED1E8 = (a << 11) >> 12;
            r->unkBA6 = a;
            r->unkBAA = 0x1000 - a;
            D_801EC988->scale.vy = 0x1000;
            r->unkA6C = w;
            r->unkA68 = w;
        } else {
            t -= 0x1E;
            if (t < 0x1A) {
                if (t == 0) {
                    r->unkBA6 = 0x1000;
                    r->unkBAA = 0;
                    r->unkA6C = 0;
                    r->unkA68 = 0;
                }
                D_801ED1E8 = 0x800;
                D_801ED1E4 = 0xBB8;
                D_801EC988->scale.vy = 0x1000;
            } else {
                t -= 0x1A;
                if (t < 0x1E) {
                    if (t == 0) {
                        r->unkBA8 = 2;
                        r->unk24 = -(u16)r->unk2C;
                        x = -0x1F4;
                        r->unk26 = x - (u16)r->unk2E;
                        r->unk28 = 0x2710 - (u16)r->unk30;
                    }
                    a = func_801B1E7C((t << 12) / 30, -0x1E0);
                    D_801ED1E8 = ((a << 11) >> 12) + 0x800;
                    D_801ED1E4 = ((a * 0x1B58) >> 12) + 0xBB8;
                    r->unkBA6 = (-(a << 12) >> 12) + 0x1000;
                    r->unkBAA = a;
                    D_801EC988->scale.vy = 0x400;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        D_801EC988->rot.vx = -0x300;
        D_801EC988->rot.vy = -0x280;
        D_801EC988->rot.vz = -0x100;
        func_8003C21C(&D_801EC988->rot, &D_801EC988->m);
        D_801EC988->scale.vz = 0x1000;
        D_801EC988->scale.vx = 0x1000;
        func_8003B35C(&D_801EC988->m, &D_801EC988->scale);
        D_801EC988->rot.vx = (func_80039B40(D_801ED1E8) * D_801ED1E4) >> 12;
        x = func_80039A74(D_801ED1E8) * D_801ED1E4;
        D_801EC988->rot.vz = 0;
        D_801EC988->rot.vy = x >> 12;
        func_8003B2CC(&D_801EC988->m, &D_801EC988->rot, (MgSVec *)&r->unk2C);
        r->unk2C = (u16)r->unk2C;
        r->unk2E = (u16)r->unk2E - 0x1F4;
        r->unk30 = (u16)r->unk30 + 0x2710;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B6B78(s32 arg0) {
    func_801B6624((s32)&D_801EC98C, &D_801EE9D8[arg0]);
}

void func_801B6BAC(void) {
    MgTask *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE9CC >> i) & 1) {
                    func_801B018C(i, D_8015190F[i][0], &D_801EE9D8[i]);
                }
            }
        }
        func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B6B78);
        p->unk2++;
        if (p->unk2 > 0) {
            p->unk0 = -1;
        }
    }
}

void func_801B6CAC(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x48, (s32)D_801EC9AC);
        func_801B5670((s32)r, 0x48, (s32)D_801EC9C0);
    }
    k = D_80062D98 == 0;
    if (k) {
        if (p->unk2 == 0x32) {
            func_801B62D4(r);
            func_800BBEAC((M2C_UNK *)func_801B6BAC);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x38) {
            if (t == 0) {
                p->unk6 = 0x1388;
                p->unk4 = 0;
                p->unk8 = 0;
                *(s16 *)(r + 0x24) = 0x480;
                *(s16 *)(r + 0x26) = 0x800;
                *(s16 *)(r + 0x28) = 0x800;
            }
            if (t < 0x28) {
                *(s16 *)(r + 0xBAA) = 0x1000 - func_801B1E7C((t << 12) / 40, -0x3D0);
            } else {
                *(s16 *)(r + 0xBAA) = 0;
            }
            t = (t << 12) / 56;
            *(s16 *)(r + 0xBA6) = ((func_801B1E7C(t, -0x3D0) * 0xF00) >> 12) + 0x100;
            k = func_801B1E7C(t, -0x3D0);
            p->unk6 = (-(k * 0x2EE0) >> 12) + 0x1388;
        } else {
            t -= 0x38;
            if (t < 0x10) {
                t = (t << 12) / 16;
                *(s16 *)(r + 0xBAA) = func_801B1E7C(t, 0x1FF);
                *(s16 *)(r + 0xBA6) = (-(func_801B1E7C(t, 0x1FF) << 12) >> 12) + 0x1000;
                p->unk6 = (-(func_801B1E7C(t, 0x1FF) * 0x1F40) >> 12) - 0x1B58;
            } else {
                p->unk0 = -1;
                return;
            }
        }
        D_801EC9D4->rot.vx = 0x380;
        D_801EC9D4->rot.vy = 0x800;
        D_801EC9D4->rot.vz = 0x800;
        func_8003C21C(&D_801EC9D4->rot, &D_801EC9D4->m);
        func_8003B2CC(&D_801EC9D4->m, (MgSVec *)&p->unk4, (MgSVec *)(r + 0x2C));
        *(s16 *)(r + 0x2C) = *(u16 *)(r + 0x2C);
        *(s16 *)(r + 0x2E) = *(u16 *)(r + 0x2E) - 0x1F4;
        *(s16 *)(r + 0x30) = *(u16 *)(r + 0x30) + 0x2710;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B6F9C(void) {
    MgTask *p;
    u16 *frame;
    s16 n;

    p = &D_80162978[D_8015169C];
    func_801B0070((MgSVec *)&p->unk4, 0x1000, 0);
    frame = &D_801EC9E0;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= D_801C8DEC.v) {
            p->unk0 = -1;
        } else {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
    }
}

void func_801B7090(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 *g;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        D_801EC9E8 = 0x80;
        D_801EC9EE = 0;
    } else {
        t -= 10;
        if (t < 10) {
            g = &D_801EC9E8;
            *g |= 8;
            D_801EC9EE = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = func_801B1E7C((p->unk2 << 12) / 20, 0x3FF);
    D_801EC9F4->scale.vx = D_801EC9F4->scale.vy = D_801EC9F4->scale.vz = (k << 13) >> 12;
    func_8003C21C((MgSVec *)&p->unkC, &D_801EC9F4->m1);
    D_801EC9F4->rot.vx = 0;
    D_801EC9F4->rot.vy = p->unk2 * 0x20;
    D_801EC9F4->rot.vz = 0;
    func_8003C21C(&D_801EC9F4->rot, &D_801EC9F4->m2);
    func_8003A79C(&D_801EC9F4->m1, &D_801EC9F4->m2, &D_801EC9F4->m2);
    D_801EC9F4->m2.t[0] = p->unk4;
    D_801EC9F4->m2.t[1] = p->unk6;
    D_801EC9F4->m2.t[2] = p->unk8;
    func_8003A63C(&D_801EE9AC, &D_801EC9F4->m2, &D_801EC9F4->m2);
    func_8003B35C(&D_801EC9F4->m2, (KnRig3 *)&D_801EC9F4->scale);
    func_8003B48C(&D_801EC9F4->m2);
    func_8003B51C(&D_801EC9F4->m2);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801EC9E4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801B72AC);

void func_801B7498(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 n;
    s32 i;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if ((u16)p->unk2 < 5) {
            func_800D41FC(&D_801EE9AC, D_801ED85C, &D_801ECA28->m);
            D_801ECA28->a.vy = 0;
            D_801ECA28->a.vx = 0;
            D_801ECA28->a.vz = D_801EDCB0.v;
            func_8003B2CC(&D_801ECA28->m, &D_801ECA28->a, &D_801ECA28->a);
            D_801ECA28->a.vx += D_801ECA28->m.t[0];
            D_801ECA28->a.vy += D_801ECA28->m.t[1];
            D_801ECA28->a.vz += D_801ECA28->m.t[2];
            D_801ECA28->b.vx = -D_801ECA28->a.vx / 16;
            D_801ECA28->b.vy = -D_801ECA28->a.vy / 16;
            D_801ECA28->b.vz = -D_801ECA28->a.vz / 16;
            i = 0;
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B6F9C)];
                *(MgB8 *)&q->unk4 = *(MgB8 *)D_801ECA28;
                D_801ECA28->c.vx = func_80042DA8() % 64 - 32;
                D_801ECA28->c.vy = func_80042DA8() % 64 - 32;
                D_801ECA28->c.vz = func_80042DA8() % 64 - 32;
                func_8003C21C(&D_801ECA28->c, &D_801ECA28->m);
                func_8003B2CC(&D_801ECA28->m, &D_801ECA28->b, (MgSVec *)&q->unkC);
                i++;
            } while (i < 5);
        }
        t = (u16)p->unk2;
        if ((u32)(t - 0xF) < 0xC) {
            n = (s16)t - 0xF;
            k = n / 3;
            if (n == k * 3) {
                i = k;
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B7090)];
                q->unk4 = D_801ECA08[i].a;
                q->unk6 = D_801ECA08[i].b;
                q->unk8 = D_801ECA08[i].c;
                q->unkC = func_80042DA8() & 0xFFF;
                q->unkE = func_80042DA8() & 0xFFF;
                q->unk10 = func_80042DA8() & 0xFFF;
            }
        }
        t = p->unk2;
        if (t == 0xF || t == 0x14 || t == 0x19) {
            q = &D_80162978[func_800BBEAC(&func_801B72AC)];
            q->unkC = 0x200;
            q->unkE = 0x400;
            q->unk10 = func_80042DA8() % 0x200 - 0x100;
        }
        if (p->unk2 == 0x14) {
            func_801B5E4C();
        }
        if (p->unk2 == 0x19) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

s32 func_801B786C(void) {
    MgTask *p;
    KnCam *r;
    s32 t;
    s32 k;
    s32 a;
    s32 x;

    p = &D_80162978[D_8015169C];
    r = *(KnCam **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x44, (s32)D_801ECA2C);
        func_801B5670((s32)r, 0x44, (s32)D_801ECA40);
        *(u16 *)r |= 1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x1A) {
            func_800BBEAC(&func_801B7498);
        }
        t = p->unk2;
        if (t < 0xF) {
            if (t == 0) {
                r->unkBA8 = 1;
                r->unk26 = -0x1F4;
                r->unk28 = 0x3A98;
                r->unk24 = 0;
                r->unkA6A = -0x300;
            }
            k = func_801B1E7C((t << 12) / 15, 0x1FF);
            D_801ED1EC = (-(k * 0x7D0) >> 12) + 0x1F40;
            D_801ED1F0 = ((k << 7) >> 12) + 0x300;
            r->unkBA6 = k;
            r->unkBAA = 0x1000 - k;
        } else {
            t -= 0xF;
            if (t < 0x1C) {
                if (t == 0) {
                    r->unkBA6 = 0x1000;
                    r->unkBAA = 0;
                }
                D_801ED1F0 = 0x380;
                D_801ED1EC = 0x1770;
            } else {
                t -= 0x1C;
                if (t < 0x19) {
                    if (t == 0) {
                        r->unkBA8 = 2;
                        r->unk24 = -(u16)r->unk2C;
                        x = -0x1F4;
                        r->unk26 = x - (u16)r->unk2E;
                        r->unk28 = 0x3A98 - (u16)r->unk30;
                    }
                    k = (t << 12) / 25;
                    a = func_801B1E7C(k, -0x3C0);
                    D_801ED1F0 = ((a * 0x280) >> 12) + 0x380;
                    D_801ED1EC = ((a * 0xFA0) >> 12) + 0x1770;
                    r->unkA6A = ((a << 10) >> 12) - 0x400;
                    a = func_801B1E7C(k, -0x4FF);
                    r->unkBA6 = (-(a << 12) >> 12) + 0x1000;
                    r->unkBAA = a;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        D_801ECA54->rot.vx = -0x380;
        D_801ECA54->rot.vy = 0x400;
        D_801ECA54->rot.vz = -0x400;
        func_8003C21C(&D_801ECA54->rot, &D_801ECA54->m);
        D_801ECA54->rot.vx = (func_80039B40(D_801ED1F0) * D_801ED1EC) >> 12;
        x = func_80039A74(D_801ED1F0) * D_801ED1EC;
        D_801ECA54->rot.vz = 0;
        D_801ECA54->rot.vy = x >> 12;
        func_8003B2CC(&D_801ECA54->m, &D_801ECA54->rot, &D_801ECA54->rot);
        r->unk2C = D_801ECA54->rot.vx;
        r->unk2E = D_801ECA54->rot.vy - 0x1F4;
        r->unk30 = D_801ECA54->rot.vz + 0x3A98;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B7C28(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECA58, sp10);
}

s32 func_801B7C84(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 a;
    s32 x;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x54, (s32)D_801ECA78);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x34) {
            func_801B62D4(r);
            func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B7C28);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x18) {
            if (t == 0) {
                *(s16 *)(r + 0xBA8) = 1;
                *(s16 *)(r + 0x26) = -0x3E8;
                *(s16 *)(r + 0x24) = 0;
                *(s16 *)(r + 0x28) = 0x2710;
            }
            a = func_801B1E7C((t << 12) / 24, -0x3D0);
            D_801ED1F4 = 0xBB8;
            D_801ED1F8 = -(a << 11) >> 12;
            *(s16 *)(r + 0xBA6) = a;
            *(s16 *)(r + 0xBAA) = 0x1000 - a;
        } else {
            t -= 0x18;
            if (t < 6) {
                if (t == 0) {
                    *(s16 *)(r + 0xBA6) = 0x1000;
                    *(s16 *)(r + 0xBAA) = 0;
                }
                D_801ED1F8 = -0x800;
                D_801ED1F4 = 0xBB8;
            } else {
                t -= 6;
                if (t < 0x36) {
                    if (t == 0) {
                        *(s16 *)(r + 0xBA8) = 2;
                        *(s16 *)(r + 0x24) = -*(u16 *)(r + 0x2C);
                        x = -0x3E8;
                        *(s16 *)(r + 0x26) = x - *(u16 *)(r + 0x2E);
                        *(s16 *)(r + 0x28) = 0x2710 - *(u16 *)(r + 0x30);
                    }
                    a = func_801B1E7C((t << 12) / 54, -0x3D0);
                    D_801ED1F8 = -0x800;
                    D_801ED1F4 = (-(a * 0x7D * 0x78) >> 12) + 0xBB8;
                    if (t >= 0x19) {
                        func_801B1E7C(((t - 0x18) << 12) / 30, -0x1FF);
                    }
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        D_801ECA8C->rot.vx = 0;
        D_801ECA8C->rot.vy = -0x480;
        D_801ECA8C->rot.vz = 0;
        func_8003C21C(&D_801ECA8C->rot, &D_801ECA8C->m);
        D_801ECA8C->rot.vx = (func_80039B40(D_801ED1F8) * D_801ED1F4) >> 12;
        x = func_80039A74(D_801ED1F8) * D_801ED1F4;
        D_801ECA8C->rot.vz = 0;
        D_801ECA8C->rot.vy = x >> 12;
        func_8003B2CC(&D_801ECA8C->m, &D_801ECA8C->rot, &D_801ECA8C->rot);
        *(s16 *)(r + 0x2C) = D_801ECA8C->rot.vx;
        *(s16 *)(r + 0x2E) = D_801ECA8C->rot.vy - 0x3E8;
        *(s16 *)(r + 0x30) = D_801ECA8C->rot.vz + 0x2710;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B8014(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECA90, sp10);
}

s32 func_801B8070(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x38, (s32)D_801ECAB0);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x23) {
            func_801B62D4(r);
            func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B8014);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0xF) {
            if (t == 0) {
                *(s16 *)(r + 0x26) = 0x800;
            }
            t = (t << 12) / 15;
            *(s16 *)(r + 0xBA6) = func_801B1E7C(t, -0x1FF);
            *(s16 *)(r + 0xBAA) = 0x1000 - t;
            k = func_801B1E7C(t, 0x1FF);
            *(s16 *)(r + 0x2C) = 0x7D0;
            *(s16 *)(r + 0x2E) = (-(k * 0x1388) >> 12) + 0x1388;
            *(s16 *)(r + 0x30) = 0x1F40;
        } else {
            t -= 0xF;
            if (t < 0x29) {
                k = func_801B1E7C((t << 12) / 41, -0x1FF);
                *(s16 *)(r + 0x2C) = (-(k * 0xBB8) >> 12) + 0x7D0;
                *(s16 *)(r + 0x2E) = -(k * 0x7D0) >> 12;
                *(s16 *)(r + 0x30) = ((k * 0x2EE0) >> 12) + 0x1F40;
                if (t < 0x1A) {
                    if (t == 0) {
                        *(s16 *)(r + 0xBA6) = 0x1000;
                        *(s16 *)(r + 0xBAA) = 0;
                    }
                } else {
                    t -= 0x1A;
                    k = func_801B1E7C((t << 12) / 15, -0x1FF);
                    *(s16 *)(r + 0xBA6) = (-(k << 12) >> 12) + 0x1000;
                    *(s16 *)(r + 0xBAA) = k;
                }
            } else {
                p->unk0 = -1;
                return;
            }
        }
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B831C(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECAC8, sp10);
    func_801B6624((s32)&D_801ECAE8, sp10);
}

s32 func_801B8388(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x30, (s32)D_801ECB08);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xE) {
            func_801B62D4(r);
            func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B831C);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 7) {
            if (t == 0) {
                *(s16 *)(r + 0x26) = 0x900;
            }
        } else {
            t -= 7;
            if (t < 0x1B) {
                if (t == 0) {
                    *(s16 *)(r + 0xBA6) = 0x1000;
                    *(s16 *)(r + 0xBAA) = 0;
                }
            } else {
                t -= 0x1B;
                if (t < 0xE) {
                    k = func_801B1E7C((t << 12) / 14, -0x1FF);
                    *(s16 *)(r + 0xBA6) = (-(k * 0xFF0) >> 12) + 0x1000;
                    *(s16 *)(r + 0xBAA) = k;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        k = func_801B1E7C((p->unk2 << 12) / 48, 0x1C0);
        D_801ECB1C->rot.vx = 0x100;
        D_801ECB1C->rot.vy = 0x100;
        D_801ECB1C->rot.vz = 0;
        func_8003C21C(&D_801ECB1C->rot, &D_801ECB1C->m);
        D_801ECB1C->rot.vy = 0;
        D_801ECB1C->rot.vx = 0;
        D_801ECB1C->rot.vz = ((k * 0x36B0) >> 12) - 0x7D0;
        func_8003B2CC(&D_801ECB1C->m, &D_801ECB1C->rot, &D_801ECB1C->rot);
        *(s16 *)(r + 0x2C) = D_801ECB1C->rot.vx - 0x5DC;
        *(s16 *)(r + 0x2E) = D_801ECB1C->rot.vy;
        *(s16 *)(r + 0x30) = D_801ECB1C->rot.vz + 0x2710;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B85F8(void) {
    MgTask *p;
    s16 t;
    s32 n;
    s32 k;
    s32 r;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 10) {
        r = func_801B1E7C((t << 12) / 10, 0x1FF);
        k = (r * -0x2F00 >> 12) + 0x3000;
    } else {
        n = t - 10;
        if (n < 10) {
            r = func_801B1E7C((n << 12) / 10, 0);
            k = (r * -0x100 >> 12) + 0x100;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B0070(&D_801ECB30, k, -0x3E8);
    D_80163C74 = func_800D29D4(D_801ECB20, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B8744(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 10) {
        t -= 10;
        if (t < 10) {
            if (t == 0) {
                D_801ECB3C[0] |= 8;
            }
            D_801ECB42 = (t << 12) / 10;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    k = func_801B1E7C((p->unk2 << 12) / 20, 0x2F0);
    D_801ECB48->v0 = D_801ECB48->v4 = D_801ECB48->v8 = (k * 5 << 10) >> 12;
    func_8003C21C((MgSVec *)&p->unkC, &D_801ECB48->m);
    D_801ECB48->m.t[0] = D_801ECB48->m.t[1] = D_801ECB48->m.t[2] = 0;
    func_8003B35C(&D_801ECB48->m, D_801ECB48);
    func_8003A63C(&D_801EE9AC, &D_801ECB48->m, &D_801ECB48->m);
    func_8003B48C(&D_801ECB48->m);
    func_8003B51C(&D_801ECB48->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801ECB38, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unkC = p->unkC;
        p->unkE = p->unkE;
        p->unk10 = p->unk10;
        p->unk2++;
    }
}

void func_801B8924(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;
    s16 temp_s1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (temp_s0->unk2 == 0) {
            func_800BBEAC(&func_801B85F8);
        }
        if (temp_s0->unk2 == 0xA) {
            temp_v0 = &D_80162978[func_800BBEAC(&func_801B8744)];
            temp_v0->unk10 = 0;
            temp_v0->unkE = 0;
            temp_v0->unkC = 0;
        }
        temp_s1 = temp_s0->unk2;
        if (temp_s1 == 0x14) {
            func_801B5E4C();
            if (temp_s0->unk2 == temp_s1) {
                temp_s0->unk0 = -1;
            }
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

s32 func_801B8A00(void) {
    MgTask *p;
    KnCam *r;
    s32 t;
    s32 k;
    s32 a;
    s32 s;
    s32 z;
    s32 x;

    p = &D_80162978[D_8015169C];
    r = *(KnCam **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x47, (s32)D_801ECB54);
        func_801B5670((s32)r, 0x47, (s32)D_801ECB68);
    }
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0x1E) {
            func_800BBEAC((M2C_UNK *)func_801B8924);
            t = p->unk2;
        }
        if (t < 0xF) {
            if (t == 0) {
                r->unkBA8 = 1;
                r->unk24 = 0;
                r->unk26 = 0;
                r->unk28 = 0x3A98;
            }
            k = (t << 12) / 15;
            a = func_801B1E7C(k, -0x1FF);
            s = (a * 0x600) >> 12;
            z = 0x1388;
            r->unkA6C = ((k << 10) >> 12) - 0x400;
            a = func_801B1E7C(k, -0x1FF);
            r->unkBA6 = ((a * 0xFF8) >> 12) + 8;
            r->unkBAA = 0x1000 - a;
        } else {
            t -= 0xF;
            if (t < 0x1F) {
                if (t == 0) {
                    r->unkBA6 = 0x1000;
                    r->unkBAA = 0;
                    r->unkA6C = 0;
                }
                if (t >= 0x10) {
                    k = ((t - 0xF) << 12) / 16;
                    r->unkA6A = (u32)k >> 1;
                    r->unkA68 = (u32)(k * 3) >> 4;
                }
                s = 0x600;
                z = 0x1388;
            } else {
                t -= 0x1F;
                if (t < 0x19) {
                    /* identical arms: the dead test keeps s and z in the game's saved registers */
                    if (D_801ECB7C != 0) {
                        k = (t << 12) / 25;
                        a = func_801B1E7C(k, 0x2FF);
                        z = ((a * 0x1388) >> 12) + 0x1388;
                        a = func_801B1E7C(k, -0x1FF);
                        r->unkBA6 = (-(a * 0xFF8) >> 12) + 0x1000;
                        r->unkBAA = a;
                        s = 0x600;
                    } else {
                        k = (t << 12) / 25;
                        a = func_801B1E7C(k, 0x2FF);
                        z = ((a * 0x1388) >> 12) + 0x1388;
                        a = func_801B1E7C(k, -0x1FF);
                        r->unkBA6 = (-(a * 0xFF8) >> 12) + 0x1000;
                        r->unkBAA = a;
                        s = 0x600;
                    }
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        func_8003C21C(&D_801ECB4C, &D_801ECB7C->m);
        D_801ECB7C->rot.vx = (func_80039B40(s) * z) >> 12;
        x = func_80039A74(s) * z;
        D_801ECB7C->scale.vx = D_801ECB7C->scale.vz = 0x1000;
        D_801ECB7C->rot.vz = 0;
        D_801ECB7C->scale.vy = 0x800;
        D_801ECB7C->rot.vy = x >> 12;
        func_8003B35C(&D_801ECB7C->m, &D_801ECB7C->scale);
        func_8003B2CC(&D_801ECB7C->m, &D_801ECB7C->rot, &D_801ECB7C->rot);
        r->unk2C = D_801ECB7C->rot.vx;
        r->unk2E = D_801ECB7C->rot.vy;
        r->unk30 = D_801ECB7C->rot.vz + 0x3A98;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B8D7C(s32 arg0) {
    func_801B6624((s32)&D_801ECB80, &D_801EE9D8[arg0]);
}

void func_801B8DB0(void) {
    MgTask *p;
    s32 i;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (i = 0; i < 10; i++) {
                if ((D_801EE9CC >> i) & 1) {
                    func_801B018C(i, D_8015190F[i][0], &D_801EE9D8[i]);
                }
            }
        }
        func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B8D7C);
        p->unk2++;
        if (p->unk2 > 0) {
            p->unk0 = -1;
        }
    }
}

s32 func_801B8EB0(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 u;
    s32 a;
    s32 z;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        *(u16 *)r |= 1;
    }
    if (p->unk2 == 5) {
        func_801B5670((s32)r, 0x2E, (s32)D_801ECBA0);
        func_801B5670((s32)r, 0x2E, (s32)D_801ECBB4);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x1A) {
            func_801B62D4(r);
            func_800BBEAC((M2C_UNK *)func_801B8DB0);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x25) {
            u = t << 12;
            a = func_801B1E7C(u / 37, -0x3D0);
            z = (-(a * 0x3A98) >> 12) + 0x2710;
            if (t < 0xC) {
                if (t == 0) {
                    *(s16 *)(r + 0x24) = 0x200;
                }
                a = func_801B1E7C(u / 12, -0x1FF);
                *(s16 *)(r + 0xBA6) = a;
                *(s16 *)(r + 0xBAA) = 0x1000 - a;
            } else {
                t -= 0xC;
                if (t < 0x19) {
                    if (t == 0) {
                        *(s16 *)(r + 0xBA6) = 0x1000;
                        *(s16 *)(r + 0xBAA) = 0;
                    }
                }
            }
        } else {
            t -= 0x25;
            if (t < 0xE) {
                t = (t << 12) / 14;
                a = func_801B1E7C(t, -0x1FF);
                *(s16 *)(r + 0xBA6) = (-(a << 12) >> 12) + 0x1000;
                *(s16 *)(r + 0xBAA) = a;
                a = func_801B1E7C(t, 0x3FF);
                z = (-(a * 0x2710) >> 12) - 0x1388;
            } else {
                p->unk0 = -1;
                return;
            }
        }
        func_8003C21C(&D_801ECBC8, &D_801ECBD0->m);
        D_801ECBD0->rot.vx = 0;
        D_801ECBD0->rot.vy = 0;
        D_801ECBD0->rot.vz = z;
        func_8003B2CC(&D_801ECBD0->m, &D_801ECBD0->rot, &D_801ECBD0->rot);
        *(s16 *)(r + 0x2C) = D_801ECBD0->rot.vx;
        *(s16 *)(r + 0x2E) = D_801ECBD0->rot.vy - 0x1F4;
        *(s16 *)(r + 0x30) = D_801ECBD0->rot.vz + 0x2710;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B91C8(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 c;
    s16 n;

    p = &D_80162978[D_8015169C];
    t = (p->unk2 << 12) / 30;
    k = func_801B1E7C(t, 0x1E0);
    D_801ECBE4->rot.vx = *((u8 *)p + 0x14) * 0x10;
    D_801ECBE4->rot.vy = *((u8 *)p + 0x15) * 0x10;
    D_801ECBE4->rot.vz = *((u8 *)p + 0x16) * 0x10;
    func_8003C21C(&D_801ECBE4->rot, &D_801ECBE4->m);
    D_801ECBE4->m.t[0] = p->unk4 + ((p->unkC * k) >> 12);
    D_801ECBE4->m.t[1] = p->unk6 + ((p->unkE * k) >> 12);
    D_801ECBE4->m.t[2] = p->unk8 + ((p->unk10 * k) >> 12);
    c = (-(func_801B1E7C(t, -0x1E0) << 12) >> 12) + 0x1000;
    D_801ECBE4->scale.vx = D_801ECBE4->scale.vy = D_801ECBE4->scale.vz = (p->unk1C * c) >> 12;
    func_8003B35C(&D_801ECBE4->m, &D_801ECBE4->scale);
    func_8003A63C(&D_801EE9AC, &D_801ECBE4->m, &D_801ECBE4->m);
    func_8003B48C(&D_801ECBE4->m);
    func_8003B51C(&D_801ECBE4->m);
    D_80163C74 = func_800D29D4(D_801ECBD4, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 0x1E) {
            p->unk0 = -1;
            return;
        }
        *((u8 *)p + 0x14) += *((u8 *)p + 0x18);
        *((u8 *)p + 0x15) += *((u8 *)p + 0x19);
        *((u8 *)p + 0x16) += *((u8 *)p + 0x1A);
    }
}

void func_801B9408(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    s32 k;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        n = (p->unk2 * 0x100 & 0xFF) + 0x100;
        if (n >= 0x100) {
            do {
                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B91C8)];
                D_801ECBF8->vx = func_80042DA8() % 8000 - 0xFA0;
                D_801ECBF8->vy = 0;
                D_801ECBF8->vz = func_80042DA8() % 8000 - 0xFA0;
                q->unk4 = D_801ECBE8.vx + D_801ECBF8->vx;
                q->unk6 = D_801ECBE8.vy;
                q->unk8 = D_801ECBE8.vz + D_801ECBF8->vz;
                D_801ECBF8->vx = D_801ECBF0.vx - D_801ECBE8.vx;
                D_801ECBF8->vy = D_801ECBF0.vy - D_801ECBE8.vy;
                D_801ECBF8->vz = D_801ECBF0.vz - D_801ECBE8.vz;
                r = func_80042DA8() % 0x400 + 0x1400;
                q->unkC = (D_801ECBF8->vx * r) >> 12;
                q->unkE = (D_801ECBF8->vy * r) >> 12;
                q->unk10 = (D_801ECBF8->vz * r) >> 12;
                *(s32 *)&q->unk14 = func_80042DA8() & 0xFFFFFF;
                *((u8 *)q + 0x18) = func_80042DA8() % 4 - 2;
                *((u8 *)q + 0x19) = func_80042DA8() % 4 - 2;
                *((u8 *)q + 0x1A) = func_80042DA8() % 4 - 2;
                k = func_80042DA8();
                q->unk1C = k % 0x1000 + 0x2000;
                n -= 0x100;
            } while (n >= 0x100);
        }
        p->unk2++;
        if (p->unk2 >= 0xA) {
            p->unk0 = -1;
        }
    }
}

void func_801B9700(void) {
    MgTask *p;
    s16 t;
    s32 n;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        k = (p->unk1C * func_801B1E7C((t << 12) / 5, 0x1FF)) >> 12;
    } else {
        n = t - 5;
        if (n < 5) {
            k = (p->unk1C * (0x1000 - func_801B1E7C((n << 12) / 5, -0x1FF))) >> 12;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_801B0070((MgSVec *)&p->unk4, k, -0x1F4);
    D_80163C74 = func_800D29D4(D_801ECBFC, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B9834(void) {
    MgTask *p;
    MgTask *q;
    u16 t;
    s32 n;
    s32 k;
    s32 r;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = &D_80162978[func_800BBEAC(&func_801B9408)];
            q->unk4 = p->unk4 * 2;
            q->unk6 = p->unk6 * 2;
            q->unk8 = p->unk8 * 2;
            q->unkC = -q->unk4 / 30;
            q->unkE = -q->unk6 / 30;
            q->unk10 = -q->unk8 / 30;
        }
        t = p->unk2;
        if ((u32)(t - 0x1E) < 0xA) {
            n = ((s16)t * 0x80 - 0xF00) & 0xFF;
            do {
                k = n + 0x80;
            } while (0);
            if (n != 0) {
                do {
                    q = &D_80162978[func_800BBEAC(&func_801B9700)];
                    q->unk4 = func_80042DA8() % 6000 - 0xBB8;
                    q->unk6 = 0;
                    q->unk8 = func_80042DA8() % 6000 - 0xBB8;
                    r = func_80042DA8();
                    q->unk1C = r % 0x800 + 0x800;
                    k -= 0x100;
                } while (k >= 0x100);
            }
        }
        if (p->unk2 == 0x1E) {
            func_801B5E4C();
        }
        if (p->unk2 == 0x23) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

s32 func_801B9AA0(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;
    s32 a;
    s32 s;
    s32 z;
    s32 x;
    s16 w;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x5F, (s32)D_801ECC14);
        func_801B5670((s32)r, 0x5F, (s32)D_801ECC28);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x47) {
            func_801B0264((MgMat *)(r + 0x658), (MgSVec *)&D_80162978[func_800BBEAC(&func_801B9834)].unk4);
        }
        t = p->unk2;
        if (t < 0x28) {
            if (t == 0) {
                *(s16 *)(r + 0xBA8) = 1;
                *(s16 *)(r + 0x24) = 0;
                *(s16 *)(r + 0x26) = 0;
                *(s16 *)(r + 0x28) = 0x4E20;
            }
            k = (t << 12) / 40;
            a = func_801B1E7C(k, -0x3D0);
            s = ((a * 0x380) >> 12) + 0x300;
            z = ((a * 0x1B58) >> 12) + 0x1388;
            a = func_801B1E7C(k, -0x1FF);
            *(s16 *)(r + 0xBA6) = ((a * 0xFF8) >> 12) + 8;
            *(s16 *)(r + 0xBAA) = 0x1000 - a;
        } else {
            t -= 0x28;
            if (t < 0x28) {
                s = 0x680;
                if (t == 0) {
                    *(s16 *)(r + 0xBA6) = 0x1000;
                    *(s16 *)(r + 0xBAA) = 0;
                }
                z = 0x2EE0;
            } else {
                t -= 0x28;
                if (t < 0xF) {
                    k = (t << 12) / 15;
                    a = func_801B1E7C(k, 0x2FF);
                    s = 0x680;
                    z = ((a * 0x1F40) >> 12) + 0x2EE0;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        func_8003C21C(&D_801ECC0C, &D_801ECC3C->m);
        D_801ECC3C->rot.vx = (func_80039B40(s) * z) >> 12;
        x = func_80039A74(s) * z;
        D_801ECC3C->scale.vx = D_801ECC3C->scale.vz = 0x1000;
        D_801ECC3C->rot.vz = 0;
        D_801ECC3C->scale.vy = 0x800;
        D_801ECC3C->rot.vy = x >> 12;
        func_8003B35C(&D_801ECC3C->m, &D_801ECC3C->scale);
        func_8003B2CC(&D_801ECC3C->m, &D_801ECC3C->rot, &D_801ECC3C->rot);
        *(s16 *)(r + 0x2C) = D_801ECC3C->rot.vx;
        *(s16 *)(r + 0x2E) = D_801ECC3C->rot.vy;
        w = D_801ECC3C->rot.vz + 0x4E20;
        *(s16 *)(r + 0x30) = w;
        if (w >= 0x4E21) {
            *(s16 *)(r + 0xA6C) = 0x800;
        } else {
            *(s16 *)(r + 0xA6C) = 0;
        }
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801B9DF0(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECC40, sp10);
}

s32 func_801B9E4C(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;
    s32 a;
    s32 z;
    s32 s;
    s32 x;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x4C, (s32)D_801ECC68);
        func_801B5670((s32)r, 0x4C, (s32)D_801ECC7C);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x33) {
            func_801B62D4(r);
            func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801B9DF0);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x19) {
            if (t == 0) {
                *(s16 *)(r + 0x24) = -0x400;
                *(s16 *)(r + 0x26) = 0;
                *(s16 *)(r + 0x28) = 0x800;
            }
            k = (t << 12) / 25;
            a = func_801B1E7C(k, 0x2F0);
            s = ((a * 0x600) >> 12) + 0x200;
            z = (-(a * 0x3E8) >> 12) + 0x1388;
            a = func_801B1E7C(k, -0x1FF);
            *(s16 *)(r + 0xBA6) = ((a * 0xFF8) >> 12) + 8;
            *(s16 *)(r + 0xBAA) = 0x1000 - a;
        } else {
            t -= 0x19;
            if (t < 0xA) {
                if (t == 0) {
                    *(s16 *)(r + 0xBA6) = 0x1000;
                    *(s16 *)(r + 0xBAA) = 0;
                }
                s = 0x800;
                z = 0xFA0;
                k = (t << 12) / 10;
                a = func_801B1E7C(k, 0x2FF);
                *(s16 *)(r + 0x24) = (-(a << 10) >> 12) - 0x400;
            } else {
                t -= 0xA;
                if (t < 0x29) {
                    if (t == 0) {
                        *(s16 *)(r + 0x24) = -0x800;
                    }
                    k = (t << 12) / 41;
                    a = func_801B1E7C(k, -0x2F0);
                    s = 0x800;
                    z = (-(a * 0x36B0) >> 12) + 0xFA0;
                    if (t >= 0x1B) {
                        k = ((t - 0x1A) << 12) / 15;
                        a = func_801B1E7C(k, -0x1FF);
                        *(s16 *)(r + 0xBA6) = (-(a * 0xFF8) >> 12) + 0x1000;
                        *(s16 *)(r + 0xBAA) = a;
                    }
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        func_8003C21C(&D_801ECC60, &D_801ECC90->m);
        D_801ECC90->rot.vx = (func_80039B40(s) * z) >> 12;
        x = func_80039A74(s) * z;
        D_801ECC90->rot.vz = 0;
        D_801ECC90->scale.vz = 0x1000;
        D_801ECC90->scale.vx = 0x1000;
        D_801ECC90->scale.vy = 0x1000;
        D_801ECC90->rot.vy = x >> 12;
        func_8003B35C(&D_801ECC90->m, &D_801ECC90->scale);
        func_8003B2CC(&D_801ECC90->m, &D_801ECC90->rot, &D_801ECC90->rot);
        *(s16 *)(r + 0x2C) = D_801ECC90->rot.vx;
        *(s16 *)(r + 0x2E) = D_801ECC90->rot.vy;
        *(s16 *)(r + 0x30) = D_801ECC90->rot.vz + 0x2710;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801BA230(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECC94, sp10);
    func_801B6624((s32)&D_801ECCB4, sp10);
}

void func_801BA29C(void) {
    func_801B6624(&D_801ECCD4, &D_801ECCF4);
    func_800D5444(D_801EE9CC, 0, 0, &func_801BA230);
}

s32 func_801BA2E8(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;
    s32 a;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x48, (s32)D_801ECCFC);
    }
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0x38) {
            func_801B62D4(r);
            func_801BA29C();
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
            t = p->unk2;
        }
        if (t < 0x12) {
            k = (t << 12) / 18;
            a = func_801B1E7C(k, 0x3D0);
            D_801ECD10->vx = 0;
            D_801ECD10->vy = (-(a * 0x1770) >> 12) + 0x1388;
            D_801ECD10->vz = 0xBB8;
            a = func_801B1E7C(k, 0x3D0);
            *(s16 *)(r + 0xBA6) = ((a * 0xFF8) >> 12) + 8;
            *(s16 *)(r + 0xBAA) = 0x1000 - a;
        } else {
            t -= 0x12;
            if (t < 0x26) {
                if (t == 0) {
                    *(s16 *)(r + 0xBA6) = 0x1000;
                    *(s16 *)(r + 0xBAA) = 0;
                }
                D_801ECD10->vy = -0x3E8;
                D_801ECD10->vx = 0;
                D_801ECD10->vz = 0xBB8;
            } else {
                t -= 0x26;
                if (t < 0x10) {
                    k = (t << 12) / 16;
                    a = func_801B1E7C(k, -0x3D0);
                    D_801ECD10->vx = 0;
                    D_801ECD10->vy = (-(a * 0x2328) >> 12) - 0x3E8;
                    D_801ECD10->vz = 0xBB8;
                    a = func_801B1E7C(k, -0x3D0);
                    *(s16 *)(r + 0xBA6) = (-(a * 0xFF8) >> 12) + 0x1000;
                    *(s16 *)(r + 0xBAA) = a;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        *(s16 *)(r + 0x2C) = D_801ECD10->vx;
        *(s16 *)(r + 0x2E) = D_801ECD10->vy;
        *(s16 *)(r + 0x30) = D_801ECD10->vz + 0x2710;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801BA598(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624((s32)&D_801ECD14, sp10);
    func_801B6624((s32)&D_801ECD34, sp10);
}

s32 func_801BA604(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;
    s32 a;
    s32 s;
    s32 z;
    s32 x;
    s16 w;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x47, (s32)D_801ECD5C);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x38) {
            func_801B62D4(r);
            func_800D5444(D_801EE9CC, 0, 0, (M2C_UNK *)func_801BA598);
            func_800BBEAC((M2C_UNK *)func_801B6248);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x1E) {
            if (t == 0) {
                *(s16 *)(r + 0xBA8) = 1;
                *(s16 *)(r + 0x24) = 0;
                *(s16 *)(r + 0x26) = 0;
                *(s16 *)(r + 0x28) = 0x3A98;
            }
            k = (t << 12) / 30;
            a = func_801B1E7C(k, -0x2F0);
            z = 0x1388;
            s = (a << 11) >> 12;
            w = (-(a << 10) >> 12) + 0x400;
            *(s16 *)(r + 0xA6C) = w;
            *(s16 *)(r + 0xA68) = w;
            a = func_801B1E7C(k, -0x2F0);
            *(s16 *)(r + 0xBA6) = ((a * 0xFF8) >> 12) + 8;
            *(s16 *)(r + 0xBAA) = 0x1000 - a;
        } else {
            t -= 0x1E;
            if (t < 0xB) {
                s = 0x800;
                if (t == 0) {
                    *(s16 *)(r + 0xBA8) = 2;
                    *(s16 *)(r + 0xBA6) = 0x1000;
                    *(s16 *)(r + 0xA6C) = 0;
                    *(s16 *)(r + 0xA68) = 0;
                    *(s16 *)(r + 0xBAA) = 0;
                    *(s16 *)(r + 0x24) = -*(u16 *)(r + 0x2C);
                    *(s16 *)(r + 0x26) = -*(u16 *)(r + 0x2E);
                    *(s16 *)(r + 0x28) = 0x3A98 - *(u16 *)(r + 0x30);
                }
                z = 0x1388;
            } else {
                t -= 0xB;
                if (t < 0x1E) {
                    k = (t << 12) / 30;
                    a = func_801B1E7C(k, -0x3F0);
                    s = 0x800;
                    z = (-(a * 0x3A98) >> 12) + 0x1388;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        func_8003C21C(&D_801ECD54, &D_801ECD70->m);
        D_801ECD70->rot.vx = (func_80039B40(s) * z) >> 12;
        x = func_80039A74(s) * z;
        D_801ECD70->scale.vx = D_801ECD70->scale.vz = 0x1000;
        D_801ECD70->rot.vz = 0;
        D_801ECD70->scale.vy = 0x800;
        D_801ECD70->rot.vy = x >> 12;
        func_8003B35C(&D_801ECD70->m, &D_801ECD70->scale);
        func_8003B2CC(&D_801ECD70->m, &D_801ECD70->rot, &D_801ECD70->rot);
        *(s16 *)(r + 0x2C) = D_801ECD70->rot.vx;
        *(s16 *)(r + 0x2E) = D_801ECD70->rot.vy;
        *(s16 *)(r + 0x30) = D_801ECD70->rot.vz + 0x3A98;
        func_801B5B24(r);
        p->unk2++;
    }
}

void func_801BA964(void) {
    MgTask *p;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 4) {
        k = (t << 12) / 4 >> 3;
        D_801ECD84.m[0][0] = D_801ECD84.m[1][1] = D_801ECD84.m[2][2] = k;
    } else {
        t -= 4;
        if (t < 4) {
            k = 0x200;
            D_801ECD84.m[0][0] = D_801ECD84.m[1][1] = D_801ECD84.m[2][2] = k;
        } else {
            t -= 4;
            if (t >= 0xF) {
                func_800D51D4(5);
                p->unk0 = -1;
                return;
            }
            k = func_801B1E7C((t << 12) / 15, 0x3FF);
            D_801ECD84.m[0][0] = (k * 0x1600 >> 12) + 0x200;
            D_801ECD84.m[1][1] = D_801ECD84.m[2][2] = 0x200;
            if (t == 0xB) {
                func_800D5138(4);
            }
        }
    }
    func_8003B48C(&D_801ECD84);
    func_8003B51C(&D_801ECD84);
    D_80163C74 = func_800D29D4(D_801ECD74, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801BAAFC(s32 arg0) {
    s32 sp10[2];

    func_801B018C(arg0, D_8015190F[arg0][0], sp10);
    func_801B6624(&D_801ECDA4, sp10);
}

void func_801BAB58(void) {
    MgTask *p;
    s32 t;
    s32 q;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        q = (t << 12) / 5;
        k = func_801B1E7C(q, 0x1F0);
        D_801ECDE4.m[0][0] = D_801ECDEC = D_801ECDF4 = (u32)k >> 2;
    } else {
        t -= 5;
        if (t < 0x14) {
            q = (t << 12) / 20;
            k = func_801B1E7C(q, -0x1F0);
            D_801ECDE4.m[0][0] = ((k * 31) << 10 >> 12) + 0x400;
            k = func_801B1E7C(q, 0x4FF);
            D_801ECDEC = (-(k << 10) >> 12) + 0x400;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003B48C(&D_801EE9AC);
    func_8003B51C(&D_801EE9AC);
    func_8003BC6C(&D_801ECDD4, (MgVec *)D_801ECE04->a.t, &D_801ECE04->flag);
    func_8003BC6C(&D_801ECDDC, (MgVec *)D_801ECE04->b.t, &D_801ECE04->flag);
    func_8003B48C(&D_801ECDE4);
    func_8003B51C(&D_801ECE04->a);
    D_80163C74 = func_800D29D4(D_801ECDC4, D_801517C0 + 0x4084, 0, D_80163C74);
    func_8003B51C(&D_801ECE04->b);
    D_80163C74 = func_800D29D4(D_801ECDC4, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

s32 func_801BAD78(void) {
    MgTask *p;
    u8 *r;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    r = *(u8 **)((u8 *)p + 0x14);
    if (p->unk2 != 0) {
        func_801B56D4((s32)r);
    } else {
        func_801B5670((s32)r, 0x78, (s32)D_801ECE08);
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x6E) {
            func_800BBEAC(&func_801BA964);
        }
        if (p->unk2 == 0x70) {
            func_800D5444(D_801EE9CC, 0, 0, &func_801BAAFC);
            func_801B62D4(r);
            func_801B5E4C();
        }
        t = p->unk2;
        if (t < 0x30) {
            if (t == 0) {
                *(s16 *)(r + 0x30) = -0x1388;
                *(s16 *)(r + 0x2C) = 0;
                *(s16 *)(r + 0x26) = 0x800;
            }
            k = func_801B1E7C((t << 12) / 48, 0x180);
            *(s16 *)(r + 0x2E) = (-(k * 0x2EE0) >> 12) + 0x2710;
            *(s16 *)(r + 0xBAA) = 0x1000 - k;
            *(s16 *)(r + 0xBA6) = k;
        } else {
            t -= 0x30;
            if (t < 0x12) {
                if (t == 0) {
                    *(s16 *)(r + 0x2E) = -0x7D0;
                    *(s16 *)(r + 0xBAA) = 0;
                    *(s16 *)(r + 0xBA6) = 0x1000;
                }
                if (t == 5) {
                    func_800BBEAC(&func_801BAB58);
                }
            } else {
                t -= 0x12;
                if (t >= 0x36) {
                    p->unk0 = -1;
                    return;
                }
            }
        }
        if ((u32)((u16)p->unk2 - 0x30) >= 0x12U) {
            func_801B5B24(r);
        }
        p->unk2++;
    }
}

void func_801BAF80(MgMat *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    MgMat m;
    u8 pad[8];
    KnSt *s;
    s32 t;
    s32 u;
    s32 o;
    s32 w;
    s16 a;
    s32 *q;
    MgSVec *e;

    switch (arg4) {
    case 0:
        s = (KnSt *)D_801ECE3C;
        break;
    case 1:
        s = (KnSt *)D_801ECE50;
        break;
    default:
        s = (KnSt *)D_801ECE64;
        break;
    }
    t = arg1 % 4924;
    if (t < 0x99E) {
        s->flags &= ~0x200;
        s->unk8 = (u8)s->unk8;
    } else {
        t -= 0x99E;
        s->flags |= 0x200;
        s->unk8 = (u8)s->unk8 | 0x200;
    }
    q = &D_801ECE30;
    D_801ECE34 = 0;
    *q = 0;
    D_801ECE38 = t + arg2;
    a = 0;
    w = func_8003B66C();
    func_8003B6DC(0x100);
    func_8003A63C(arg0, (MgMat *)((u8 *)q - 0x14), &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    for (o = 0; o < 0x120; o++) {
        e = &D_801F9E30[o];
        e->vz = 0;
        e->vy = 0;
        D_801F9E30[o].vx = 0;
    }
    u = 0;
    if (arg3 > 0) {
        do {
            if (arg4 < 2) {
                if (D_801F9E2C >= 2) {
                    D_80163C74 = func_800D7D3C(s, D_801517C0 + 0x4068, 0, D_80163C74);
                } else {
                    D_801F9E28 = func_800D7D3C(s, D_801517C0 + 0x4068, 0, D_801F9E28);
                }
            } else {
                if (D_801F9E2C >= 2) {
                    D_80163C74 = func_801B15E8(s, D_801517C0 + 0x4068, 0, D_80163C74);
                } else {
                    D_801F9E28 = func_801B15E8(s, D_801517C0 + 0x4068, 0, D_801F9E28);
                }
            }
            a += 0x99E;
            s->flags ^= 0x200;
            s->unk8 ^= 0x200;
            for (o = 0x11F; o >= 0; o--) {
                D_801F9E34[o].v = a;
            }
            u++;
            D_801F9E2C++;
        } while (u < arg3);
    }
    func_8003B6DC(w);
}

void func_801BB270(void) {
    MgTask *p;
    KnFx *f;
    s32 t;
    s32 a;
    s32 b;
    s32 c;
    s32 k;

    p = &D_80162978[D_8015169C];
    f = *(KnFx **)((u8 *)p + 4);
    func_8003C21C(&f->rot, &D_801ECE78->m);
    func_8003B35C(&D_801ECE78->m, &f->scale);
    t = p->unk2;
    a = f->unk24;
    if (t < a) {
        k = (t << 12) / a;
        func_8003B69C(0, 0, 0);
        func_8003B710((s32)f, 0x1000 - k, (u8 *)D_801ECE78);
    } else {
        t -= a;
        b = f->unk26;
        if (t < b) {
            *(MgB4 *)D_801ECE78 = *(MgB4 *)f;
        } else {
            t -= b;
            c = f->unk28;
            if (t < c) {
                k = (t << 12) / c;
                func_8003B69C(0, 0, 0);
                func_8003B710((s32)f, k, (u8 *)D_801ECE78);
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801ECE78->m.t[0] = 0;
    D_801ECE78->m.t[1] = 0;
    D_801ECE78->m.t[2] = 0x100;
    func_8003B69C(D_801ECE78->r, D_801ECE78->g, D_801ECE78->b);
    func_8003B64C(&D_801ECE78->w2C, &D_801ECE78->w30);
    func_8003B6BC(0xA0, 0x53);
    func_801BAF80(&D_801ECE78->m, p->unk2 * f->unk2A + f->unk32, f->unk2C, f->unk2E, f->unk30);
    func_8003B6BC(D_801ECE78->w2C, D_801ECE78->w30);
    if (D_80062D98 == 0) {
        f->rot.vx += f->unkC;
        f->rot.vy += f->unkE;
        f->rot.vz += f->unk10;
        p->unk2++;
    }
}

void func_801BB500(void *arg0) {
    *(s32 *)&D_80162978[func_800BBEAC(&func_801BB270)].unk4 = (s32)arg0;
}

void func_801BB548(void) {
    MgTask *p;
    s32 k;
    s32 s;
    s32 w;
    s32 t;
    s16 n;

    p = &D_80162978[D_8015169C];
    D_801ECE8C->rot.vx = 0;
    D_801ECE8C->rot.vy = 0;
    D_801ECE8C->rot.vz = p->unk10;
    func_8003C21C(&D_801ECE8C->rot, &D_801ECE8C->m);
    k = 0x1000 - func_801B1E7C((p->unk2 << 12) / 10, 0x4E0);
    s = (p->unkC * k) >> 12;
    D_801ECE8C->m.t[0] = -((s * func_80039A74(p->unk10)) >> 12);
    w = k << 8;
    t = s * func_80039B40(p->unk10);
    D_801ECE8C->m.t[2] = 0x200;
    D_801ECE8C->scale.vx = 0x20;
    D_801ECE8C->scale.vy = w >> 12;
    D_801ECE8C->scale.vz = 0;
    D_801ECE8C->m.t[1] = (t >> 12) - 0x25;
    func_8003B35C(&D_801ECE8C->m, &D_801ECE8C->scale);
    func_8003B48C(&D_801ECE8C->m);
    func_8003B51C(&D_801ECE8C->m);
    D_80163C74 = func_800D29D4(D_801ECE7C, D_801517C0 + 0x4064, 0, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 10) {
            p->unk0 = -1;
        }
    }
}

void func_801BB6EC(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s16 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x1E) {
            t = (((t << 12) / 30) << 10) >> 12;
        } else {
            t -= 0x1E;
            if (t < 0x38) {
                t = 0x400;
            } else {
                t -= 0x38;
                if (t >= 0x25) {
                    p->unk0 = -1;
                    return;
                }
                t = (-(((t << 12) / 37) << 10) >> 12) + 0x400;
            }
        }
        D_801ECE90 = t + D_801ECE90;
        if (D_801ECE90 >= 0x100) {
            do {
                q = &D_80162978[func_800BBEAC(&func_801BB548)];
                k = func_80042DA8() % 200 + 0x12C;
                q->unkC = k;
                q->unkE = -k / 10;
                q->unk10 = func_80042DA8() & 0xFFF;
                D_801ECE90 -= 0x100;
            } while (D_801ECE90 >= 0x100);
        }
        p->unk2++;
    }
}

void func_801BB8C4(void) {
    MgTask *p;
    s32 k;
    s32 s;
    s32 w;
    s32 t;
    s16 n;

    p = &D_80162978[D_8015169C];
    D_801ECEA4->rot.vx = 0;
    D_801ECEA4->rot.vy = 0;
    D_801ECEA4->rot.vz = p->unk10;
    func_8003C21C(&D_801ECEA4->rot, &D_801ECEA4->m);
    k = func_801B1E7C((p->unk2 << 12) / 10, -0x4E0);
    s = (p->unkC * k) >> 12;
    D_801ECEA4->m.t[0] = -((s * func_80039A74(p->unk10)) >> 12);
    w = k << 8;
    t = s * func_80039B40(p->unk10);
    D_801ECEA4->m.t[2] = 0x200;
    D_801ECEA4->scale.vx = 0x20;
    D_801ECEA4->scale.vy = w >> 12;
    D_801ECEA4->scale.vz = 0;
    D_801ECEA4->m.t[1] = (t >> 12) - 0x25;
    func_8003B35C(&D_801ECEA4->m, &D_801ECEA4->scale);
    func_8003B48C(&D_801ECEA4->m);
    func_8003B51C(&D_801ECEA4->m);
    w = D_801517C0 + 0x4064;
    D_80163C74 = func_800D29D4(D_801ECE94, w, 0, D_80163C74);
    if (D_80062D98 == 0) {
        n = (u16)p->unk2 + 1;
        p->unk2 = n;
        if (n >= 10) {
            p->unk0 = -1;
        }
    }
}

void func_801BBA64(void) {
    MgTask *p;
    MgTask *q;
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0x39) {
            t = (t << 12) / 57;
            t = (t * 0x300) >> 12;
        } else {
            t -= 0x39;
            if (t < 0x84) {
                t = 0x300;
            } else {
                t -= 0x84;
                if (t >= 0xF) {
                    p->unk0 = -1;
                    return;
                }
                t = (t << 12) / 15;
                t = (t * -0x300 >> 12) + 0x300;
            }
        }
        D_801ECEA8 = t + D_801ECEA8;
        if (D_801ECEA8 >= 0x100) {
            do {
                q = &D_80162978[func_800BBEAC(&func_801BB8C4)];
                q->unkC = func_80042DA8() % 200 + 0x12C;
                q->unk10 = func_80042DA8() & 0xFFF;
                D_801ECEA8 -= 0x100;
            } while (D_801ECEA8 >= 0x100);
        }
        p->unk2++;
    }
}

void *func_801BBC20(void *arg0, s32 arg1, void *arg2) {
    void *temp_s2;

    M2C_FIELD(arg2, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg2, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg2, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg2, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
    M2C_FIELD(arg2, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
    func_80046794(arg1, (s32) arg2);
    temp_s2 = arg2 + 0x14;
    func_80044A68(temp_s2, 0, 1, (s32) M2C_FIELD(arg0, u16 *, 0x10), 0);
    func_80046794(arg1, (s32) temp_s2);
    return arg2 + 0x20;
}

void func_801BBCE0(void) {
    MgTask *p;
    s32 t;
    s32 c;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < p->unk4) {
        q = (t << 12) / p->unk4;
        c = (u32)q >> 5;
    } else {
        t -= p->unk4;
        if (t < p->unk6) {
            c = 0x80;
        } else {
            t -= p->unk6;
            if (t >= p->unk8) {
                goto kill;
            }
            q = (t << 12) / p->unk8;
            c = (-(q << 7) >> 12) - 0x80;
        }
    }
    D_801ECEB8 = D_801ECEB9 = D_801ECEBA = c;
    goto done;
kill:
    p->unk0 = -1;
    return;
done:
    D_801ECEAC[0] = (u16)D_801ECEC0 - 0x100;
    D_80163C74 = func_801BBC20(D_801ECEAC, D_801517C0 + 0x406C, D_80163C74);
    D_801ECEAC[0] += 0x100;
    D_80163C74 = func_801BBC20(D_801ECEAC, D_801517C0 + 0x406C, D_80163C74);
    D_801ECEAC[0] += 0x100;
    D_80163C74 = func_801BBC20(D_801ECEAC, D_801517C0 + 0x406C, D_80163C74);
    if (D_80062D98 == 0) {
        D_801ECEC0 = (D_801ECEC0 + 4) & 0xFF;
        p->unk2++;
    }
}

void func_801BBEC8(void) {
    MgTask *p;
    s32 t;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < p->unk4) {
        q = (t << 12) / p->unk4;
        D_801ECECE = 0x1000 - q;
    } else {
        t -= p->unk4;
        if (t < p->unk6) {
            D_801ECECE = 0;
        } else {
            t -= p->unk6;
            if (t < p->unk8) {
                q = (t << 12) / p->unk8;
                D_801ECECE = q;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801ECED4->m = D_801EE9AC;
    D_801ECED4->v0 = D_801ECED4->v4 = D_801ECED4->v8 = 0x300;
    func_8003B35C(&D_801ECED4->m, D_801ECED4);
    D_801ECED4->m.t[1] = -0x25;
    D_801ECED4->m.t[0] = 0;
    D_801ECED4->m.t[2] = 0x200;
    func_8003B48C(&D_801ECED4->m);
    func_8003B51C(&D_801ECED4->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801ECEC4, D_801517C0 + 0x4068, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801BC0E0(void) {
    MgTask *p;
    KnTl *q;
    s32 t;
    s32 a;
    s32 b;

    p = &D_80162978[D_8015169C];
    q = M2C_FIELD(p, KnTl **, 0x14);
    if (q->unk16 == 0) {
        D_801ED200 = (KnDesc *)D_801ECED8;
    } else {
        D_801ED200 = (KnDesc *)D_801ECEE8;
    }
    t = p->unk2;
    a = q->unk10;
    if (t < a) {
        a = (t << 12) / a;
        D_801ED200->d = 0x1000 - a;
    } else {
        t -= a;
        b = q->unk12;
        if (t < b) {
            D_801ED200->d = 0;
        } else {
            t -= b;
            a = q->unk14;
            if (t < a) {
                a = (t << 12) / a;
                D_801ED200->d = a;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    func_8003C21C((MgSVec *)q, &D_801ECEF8->m);
    D_801ECEF8->v0 = D_801ECEF8->v4 = D_801ECEF8->v8 = 0x300;
    func_8003B35C(&D_801ECEF8->m, (MgVec *)D_801ECEF8);
    D_801ECEF8->m.t[0] = p->unk4;
    D_801ECEF8->m.t[1] = p->unk6;
    D_801ECEF8->m.t[2] = p->unk8;
    func_8003B48C(&D_801ECEF8->m);
    func_8003B51C(&D_801ECEF8->m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(D_801ED200, D_801517C0 + 0x4068, 0, D_80163C74);
    if (D_80062D98 == 0) {
        q->unk0 += q->unk8;
        q->unk2 += q->unkA;
        q->unk4 += q->unkC;
        p->unk2++;
    }
}

void func_801BC334(void) {
    MgTask *p;
    s32 t;
    s32 k;
    s32 w;
    s32 s;
    s32 v;
    s32 x;
    s32 y;
    s32 *d;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0x24) {
        k = (t << 12) / 36;
        D_801ECF06 = 0x1000 - k;
        s = 0x40;
    } else {
        t -= 0x24;
        if (t < 0x167) {
            k = (t << 12) / 359;
            s = (k >> 8) + 0x40;
            w = ((t % 15) << 12) / 15;
            x = (func_80039A74(w) + 0x1000) / 2;
            y = ((x * 3 << 11) >> 12) - 0x800;
            v = ((y * k) >> 12) + 0x1000;
            s = (s * v) >> 12;
            if (t < 0x149) {
                D_801ECF06 = 0;
            } else {
                k = ((t - 0x149) << 12) / 30;
                D_801ECF06 = k;
            }
        } else {
            p->unk0 = -1;
            return;
        }
    }
    D_801ECF0C->rot.vx = p->unk2 * 0x80;
    D_801ECF0C->rot.vy = p->unk2 * 0x40;
    D_801ECF0C->rot.vz = p->unk2 * 0x20;
    func_8003C21C(&D_801ECF0C->rot, &D_801ECF0C->m);
    D_801ECF0C->m.t[1] = -0x25;
    D_801ECF0C->m.t[0] = 0;
    D_801ECF0C->m.t[2] = 0x200;
    D_801ECF0C->scale.vx = D_801ECF0C->scale.vy = D_801ECF0C->scale.vz = s;
    func_8003B35C(&D_801ECF0C->m, &D_801ECF0C->scale);
    func_8003B48C(&D_801ECF0C->m);
    func_8003B51C(&D_801ECF0C->m);
    func_8003B69C(0, 0, 0);
    d = &D_801ECEFC;
    *d = (s32)D_801C3CE8;
    D_80163C74 = func_800D29D4(d, D_801517C0 + 0x4064, 0, D_80163C74);
    D_801ECF0C->rot.vz = 0;
    D_801ECF0C->rot.vy = 0;
    D_801ECF0C->rot.vx = 0;
    func_8003C21C(&D_801ECF0C->rot, &D_801ECF0C->m);
    func_8003B35C(&D_801ECF0C->m, &D_801ECF0C->scale);
    func_8003B48C(&D_801ECF0C->m);
    *d = (s32)D_801C52EC;
    D_80163C74 = func_800D29D4(d, D_801517C0 + 0x4060, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801BC65C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_801BB500(D_801ECF10);
    func_801BB500(D_801ECF10 + 0x34);
    p->unk0 = -1;
}

void func_801BC6BC(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_801BB500(D_801ECF78);
    func_801BB500(D_801ECF78 + 0x34);
    p->unk0 = -1;
}

void func_801BC71C(void) {
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    func_801BB500(&D_801ECFE0);
    func_800BBEAC(&func_801BB6EC);
    temp_s0->unk0 = -1;
}

void func_801BC778(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;
    s16 temp_v1;

    temp_s0 = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        temp_v1 = temp_s0->unk2;
        if (temp_v1 == 0) {
            temp_v0 = &D_80162978[func_800BBEAC(&func_801BBCE0)];
            temp_v0->unk4 = 0x25;
            temp_v0->unk6 = 0x73;
            temp_v0->unk8 = 0x6C;
        } else if (temp_v1 == 0x25) {
            func_801BB500(&D_801ED014);
            temp_s0->unk0 = -1;
        }
        temp_s0->unk2 = (u16) temp_s0->unk2 + 1;
    }
}

void func_801BC838(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    func_800BBEAC(&func_801BC334);
    func_801BB500(&D_801ED07C);
    temp_v0 = &D_80162978[func_800BBEAC(&func_801BC0E0)];
    M2C_FIELD(temp_v0, M2C_UNK **, 0x14) = &D_801ED0B0;
    temp_v0->unk6 = -0x25;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0x200;
    temp_s0->unk0 = -1;
}

void func_801BC8D4(void) {
    MgTask *temp_s0;
    MgTask *temp_v0;

    temp_s0 = &D_80162978[D_8015169C];
    temp_v0 = &D_80162978[func_800BBEAC(&func_801BC0E0)];
    M2C_FIELD(temp_v0, M2C_UNK **, 0x14) = &D_801ED0C8;
    temp_v0->unk6 = -0x25;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0x200;
    temp_s0->unk0 = -1;
}

void func_801BC950(void) {
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    func_800BBEAC(&func_801BBA64);
    temp_s0->unk0 = -1;
}

s32 func_801BC99C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    KnDesc d;
    u8 pad[8];
    u8 *a;
    MgMat *m;
    s32 i;
    s32 o;
    s32 o2;
    s32 r;

    r = arg3;
    a = D_801518E4 + arg0 * 0xB9C;
    if (a[0x25] & 0x80) {
        i = 0;
        if (*(s16 *)(a + 0x10) > 0) {
            o2 = arg0 * 0x74;
            o = 0x174;
            do {
                if (*(s32 *)(a + 0x78 + i * 4) != 0) {
                    m = (MgMat *)(a + o);
                    func_8003B48C(m);
                    func_8003B51C(m);
                    d.a = *(s32 *)(a + 0x78 + i * 4);
                    d.b = *(u8 *)(a + i + 0x3F) | 0x90;
                    d.c = *(u16 *)(D_8015122E + o2);
                    d.d = 0;
                    d.e = 0x20;
                    d.f = *(u16 *)(a + 0x16);
                    r = func_800D29D4((M2C_UNK *)&d, arg1, arg2, r);
                }
                o += 0x34;
                i++;
            } while (i < *(s16 *)(a + 0x10));
        }
    }
    return r;
}

void func_801BCB04(void) {
    MgVec a;
    MgVec b;
    MgVec c;
    KnPrtI *p;
    u8 *tbl;
    u8 *ix;
    s16 *va;
    s16 *vb;
    s16 *vc;
    s32 i;
    s32 n;
    s32 k;
    u8 *q;
    u8 pad[8];

    q = (u8 *)D_801DDB24;
    D_801FA788 = (MgMat *)(q + 0x2AA8);
    D_801FA78C = (s32 *)(q + 0x4CC8);
    D_801FA790 = q + 0x510C;
    i = 0;
    D_801FA784 = (KnPrt *)q;
    p = (KnPrtI *)q;
    tbl = D_801C76B4;
    ix = tbl + D_801C76B0;
    n = *(s16 *)ix;
    ix += 4;
    if (n > 0) {
        do {
            va = (s16 *)(tbl + *(s16 *)ix);
            vb = (s16 *)(tbl + *(s16 *)(ix + 2));
            vc = (s16 *)(tbl + *(s16 *)(ix + 4));
            p->unk8 = (va[0] + vb[0] + vc[0]) / 3;
            p->unkA = (va[1] + vb[1] + vc[1]) / 3;
            p->unkC = (va[2] + vb[2] + vc[2]) / 3;
            a.vx = va[0] - vb[0];
            a.vy = va[1] - vb[1];
            a.vz = va[2] - vb[2];
            b.vx = vb[0] - vc[0];
            b.vy = vb[1] - vc[1];
            b.vz = vb[2] - vc[2];
            func_8003BA68(&a, &b, &c);
            while ((u32)(c.vx + 0x4000) > 0x8000U || (u32)(c.vy + 0x4000) > 0x8000U || (u32)(c.vz + 0x4000) > 0x8000U) {
                c.vx >>= 1;
                c.vy >>= 1;
                c.vz >>= 1;
            }
            func_8003A08C(&c, &c);
            k = func_80042DA8() % 500 + 0x3E8;
            p->unk10 = (k * c.vx) >> 12;
            p->unk12 = (k * c.vy) >> 12;
            p->unk14 = (k * c.vz) >> 12;
            p->unk0 = 0x19 - (p->unkA + 0x300C) / 984;
            p->unk18 = 0;
            p->unk1A = 0;
            p->unk1C = 0;
            p->unk20 = func_80042DA8() % 16 - 8;
            p->unk22 = func_80042DA8() % 16 - 8;
            p->unk24 = func_80042DA8() % 16 - 8;
            p->unk2 = 0x1000;
            p->unk4 = func_80042DA8() % 20 + 4;
            p++;
            ix += 0x10;
            D_801FA78C[i] = 0x22FFFFFF;
            i++;
        } while (i < n);
    }
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BCF1C);

void func_801BD080(MgMat *arg0, s32 arg1, s32 arg2) {
    KnPrt *p;
    MgMat *m;
    s32 i;
    s32 t;
    s32 v;
    s32 u;
    s32 c;

    p = D_801FA784;
    m = D_801FA788;
    i = 0;
    do {
        if (D_80062D98 == 0 && 0x19 - p->unk0 < arg1) {
            p->unk8 += p->unk10;
            p->unkA += p->unk12;
            p->unkC += p->unk14;
            p->unk10 = (p->unk10 * 0xF) >> 4;
            p->unk12 = ((p->unk12 * 0xF) >> 4) - 0xA;
            p->unk14 = (p->unk14 * 0xF) >> 4;
            p->unk18 += p->unk20;
            p->unk1A += p->unk22;
            p->unk1C += p->unk24;
            u = arg1 - 0x19;
            t = u + p->unk0;
            if (t < 0x1E) {
                c = 0xFF - ((t << 8) / 30);
                v = (c << 8) | 0x22000000;
                c = c | v | (c << 16);
            } else {
                c = 0x22000000;
            }
            D_801FA78C[i] = c;
        }
        func_8003BF8C((MgSVec *)&p->unk18, &D_801ED0E4->m);
        D_801ED0E4->m.t[0] = p->unk8;
        D_801ED0E4->m.t[1] = p->unkA;
        D_801ED0E4->m.t[2] = p->unkC;
        D_801ED0E4->v0 = (p->unk2 * arg2) >> 12;
        D_801ED0E4->v4 = arg2;
        D_801ED0E4->v8 = arg2;
        p++;
        i++;
        func_8003B35C(&D_801ED0E4->m, (MgVec *)D_801ED0E4);
        func_8003A63C(arg0, &D_801ED0E4->m, m);
        m++;
    } while (i < 0x111);
}

void func_801BD2D0(void) {
    MgTask *p;
    s32 i;
    s32 o;
    s32 t;
    s32 k;
    s32 v;
    u8 *q;

    p = &D_80162978[D_8015169C];
    i = 0;
    if (p->unk2 == 0) {
        func_801BCB04();
    }
    func_80044244((D_801ED0F8 << 14) + D_801FA790, 0x1000);
    o = 0;
    do {
        if (((D_801EE9D0 >> i) & 1) && (D_80151909[o] & 0x80) && !(D_801FA730[i] & 0x46)) {
            D_80163C74 = (u8 *)func_801BC99C(i, (D_801ED0F8 << 14) + D_801FA790, 0xC, (s32)D_80163C74);
        }
        i++;
        o += 0xB9C;
    } while (i < 10);
    D_801ED11C->rot.vx = 0;
    D_801ED11C->rot.vy = 0x400;
    D_801ED11C->rot.vz = 0;
    func_8003C21C(&D_801ED11C->rot, &D_801ED11C->m);
    D_801ED11C->m.t[2] = 0;
    D_801ED11C->m.t[0] = 0;
    D_801ED11C->m.t[1] = -0x7D0;
    func_8003A63C(&D_801EE9AC, &D_801ED11C->m, &D_801ED11C->m);
    t = p->unk2;
    if (t < 0x1E) {
        func_801BCF1C(&D_801ED11C->m, t);
        *(s32 *)(D_801ED100 + D_801ED0F8 * 0x10) = 0x62808080;
    } else {
        t -= 0x1E;
        if (t < 0x2D) {
            if (t == 0) {
                i = 0;
                o = 0;
                do {
                    *(s16 *)(o + (s32)D_801FA784 + 0x20) = func_80042DA8() % 0x200 - 0x100;
                    *(s16 *)(o + (s32)D_801FA784 + 0x22) = func_80042DA8() % 0x200 - 0x100;
                    *(s16 *)(o + (s32)D_801FA784 + 0x24) = func_80042DA8() % 0x200 - 0x100;
                    i++;
                    o += 0x28;
                } while (i < 0x111);
            }
            k = (t << 12) / 45;
            func_801BD080(&D_801ED11C->m, t, 0x1000);
            v = (u32)(0x1000 - k) >> 5;
            k = D_801ED0F8 * 0x10;
            q = k + D_801ED0FC;
            q[6] = v;
            q[5] = v;
            *(D_801ED100 + k) = v;
            if (t == 0x2C) {
                p->unk0 = -1;
            }
        }
    }
    func_800D4484((D_801ED0F8 << 14) + D_801FA790 + 0x3FF8, 0x20);
    D_80163C74 = func_801B1244(D_801ED0E8, (D_801ED0F8 << 14) + D_801FA790 + 0x3FF8, 0, D_80163C74, D_801FA788, D_801FA78C);
    func_800D4484((D_801ED0F8 << 14) + D_801FA790 + 0x3FF8, 0x40);
    func_80046794((D_801ED0F8 << 14) + D_801FA790 + 0x3FF8, D_801ED0FC + D_801ED0F8 * 0x10);
    func_800467D0((MainTag *)(D_801517C0 + 0x74), (D_801ED0F8 << 14) + D_801FA790 + 0x3FFC, (MainTag *)((D_801ED0F8 << 14) + D_801FA790));
    D_801ED0F8 ^= 1;
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801BD718(s32 arg0, s32 arg1) {
    MgTask *p;

    p = func_800D4FA8(7);
    p->unk10 = arg0;
    *(s32 *)&p->unkC = arg1;
}

void func_801BD758(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == p->unk0) {
            func_800D55F4(0x28, 0x40, p->unk4);
            func_800D55F4(0x29, 0x40, p->unk6);
            if (p->unk8 != 0) {
                func_800D55F4(0x2A, 0x40, p->unk8);
            }
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801BD7FC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801BD758)];
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
    temp_v0->unk6 = arg2;
    temp_v0->unk8 = arg3;
}

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BD870);

INCLUDE_ASM("../asm/us/magic_knights/nonmatchings/text", func_801BE87C);
