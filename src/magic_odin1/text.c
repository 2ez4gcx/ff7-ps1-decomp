#include "common.h"
#include "magic_odin1/decls.h"

M2C_UNK *func_801B0040(void) {
    func_801B65A0();
    return &D_801DD640;
}

void func_801B0068(MgSVecList *a, MgSVec *b, MgSVec *out) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    for (i = 0; i < n; i++) {
        out->vx = s->vx - b->vx;
        out->vy = s->vy - b->vy;
        out->vz = s->vz - b->vz;
        s++;
        b++;
        out++;
    }
}

void func_801B00F8(MgSVecList *a, MgSVec *b, MgSVec *d, s32 t) {
    s32 i;
    s32 n;
    MgSVec *s;

    n = a->n / 8;
    s = a->v;
    t = 0x1000 - t;
    for (i = 0; i < n; i++) {
        s->vx = b->vx + ((d->vx * t) >> 12);
        s->vy = b->vy + ((d->vy * t) >> 12);
        s->vz = b->vz + ((d->vz * t) >> 12);
        s++;
        b++;
        d++;
    }
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B0E60);

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B11C8);

s32 func_801B1630(s16 **pp) {
    s32 v;

    v = *(*pp)++;
    if (v < 0) {
        v = D_801F76FE[-v];
    }
    return v;
}

s32 func_801B166C(s32 t, s32 s) {
    s32 orig;
    s32 i;
    s32 n;
    s32 m;

    orig = t;
    n = s >> 8;
    if (n > 0) {
        i = 0;
        if (i < n) {
            do {
                t = func_80039A74(t / 4);
                i++;
            } while (i < n);
        }
    } else {
        t = 0x1000 - t;
        m = -n;
        i = 0;
        if (i < m) {
            n = m;
            do {
                t = func_80039A74(t / 4);
                i++;
            } while (i < n);
        }
        t = 0x1000 - t;
    }
    n = s & 0xFF;
    t = (t * n + orig * (0x100 - n)) >> 8;
    return t;
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B1758);

void func_801B2778(s32 arg0, s32 arg1, s16 arg2) {
    MgObjC *p;

    p = (MgObjC *)&D_80162978[func_800BBEAC(&func_801B1758)];
    p->unkC = arg0;
    p->unk10 = arg1;
    p->unk14 = arg2;
}

void func_801B27DC(void) {
    s32 i;
    s32 *p;

    i = 0x1F3;
    p = D_801F7EE0;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}

OdPart *func_801B2800(s32 arg0) {
    s32 i;
    OdPart *p;

    i = 0;
    p = D_801F27EC;
    for (; i < 500; i++) {
        if (D_801F7714[i] == 0) {
            D_801F7714[i] = arg0;
            p->unk0 = 0;
            p->unk2 = 0;
            return p;
        }
        p++;
    }
    return 0;
}

void func_801B2854(void) {
    MgTask *p;
    s32 n;
    s32 i;

    p = &D_80162978[D_8015169C];
    n = 0;
    for (i = 0; i < 500; i++) {
        if (D_801F7714[i] != 0) {
            ((void (*)(OdPart *))D_801F7714[i])(&D_801F27EC[i]);
            if (D_801F27EC[i].unk0 == -1) {
                D_801F7714[i] = 0;
            } else {
                n++;
            }
        }
    }
    if (n == 0 && D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgMat *func_801B2944(MgSVec *v, s16 scale, s32 dist) {
    MgVec n;
    s32 flag;

    D_801F27F0.m[0][0] = D_801F27F0.m[1][1] = D_801F27F0.m[2][2] = scale;
    func_8003B48C(&D_801F3554);
    func_8003B51C(&D_801F3554);
    func_8003BC6C(v, (MgVec *)D_801F27F0.t, &flag);
    if (dist != 0) {
        func_8003A08C((MgVec *)D_801F27F0.t, &n);
        D_801F27F0.t[0] += (dist * n.vx) >> 12;
        D_801F27F0.t[1] += (dist * n.vy) >> 12;
        D_801F27F0.t[2] += (dist * n.vz) >> 12;
    }
    func_8003B48C(&D_801F27F0);
    func_8003B51C(&D_801F27F0);
    return &D_801F27F0;
}

void func_801B2A60(MgTask *p) {
    OdScr *s;
    u8 *k;
    s32 r;
    s32 t;

    D_801F283C->pos.vx = p->unk4 + p->unkC;
    D_801F283C->pos.vy = p->unk6 + p->unkE;
    D_801F283C->pos.vz = p->unk8 + p->unk10;
    if (D_801F283C->pos.vy > 0) {
        p->unk0 = -1;
        return;
    }
    func_8003B48C(&D_801F3554);
    func_8003B51C(&D_801F3554);
    k = (u8 *)D_80163C74;
    r = func_8003BC0C(&p->unk4, D_801F283C, D_801F283C, k + 8, k + 0x10, k + 0x10, &D_801F283C->ext, &D_801F283C->flag);
    s = D_801F283C;
    s->depth = r;
    if (!(s->flag & 0x60000)) {
        *(s32 *)k = 0x04000000;
        *(s32 *)(k + 4) = 0x52000000;
        *(s32 *)(k + 0xC) = 0x808080;
        t = (s->depth >> 2) * 4 + 0x70;
        func_80046794(t + D_801517C0, k);
        D_80163C74 = (s32)(k + 0x14);
    }
    if (D_80062D98 == 0) {
        p->unk6 = D_801F283C->pos.vy;
        p->unk4 = D_801F283C->pos.vx;
        p->unk8 = D_801F283C->pos.vz;
    }
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B2BE0);

void func_801B2EC0(void) {
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
                    D_800FA668[0] = 0;
                    return;
                }
                d = (t << 12) / d;
                v = (p->unk4 * (0x1000 - d)) >> 12;
            }
        }
        D_800FA668[0] = (p->unk2 & 1) ? v : -v;
        p->unk2++;
    }
}

void func_801B2FFC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B2EC0)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    p->unk8 = arg2;
    p->unkA = arg3;
}

void func_801B3070(MgTask *p) {
    s32 flag;
    s32 d;
    s32 t;
    s32 c;
    s32 u;

    func_8003B48C(&D_801F3554);
    func_8003B51C(&D_801F3554);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)D_801F2850.t, &flag);
    d = D_801F2850.t[2];
    if (d > 0) {
        t = (d >> 4) * 4 + 0x70;
        func_800D4484(t + D_801517C0, 0x20);
    }
    func_8003B48C(&D_801F2850);
    func_8003B51C(&D_801F2850);
    u = p->unk2 + p->unk0;
    if (u >= 0x50) {
        u -= 0x50;
        c = -(((u << 12) / 15) << 5) >> 12;
        c += 0x20;
        D_801F2848[0] = D_801F2848[1] = D_801F2848[2] = c;
    } else {
        *(s32 *)D_801F2848 = 0x2E202020;
    }
    D_801F284C[0] = p->unk2 * D_801DBDA0[0] / 45;
    D_80163C74 = func_800D4D90((u16 *)&D_801F284C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 0x2D || p->unk2 + p->unk0 >= 0x5F) {
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 0xFF >> 8;
        p->unkE = p->unkE * 0xFF >> 8;
        p->unk10 = p->unk10 * 0x41 >> 6;
    }
}

void func_801B32BC(void) {
    MgTask *p;
    MgTask *q;
    s16 b;
    s32 n;
    s32 i;
    s32 j;
    s32 v;
    s32 w;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            for (j = 0xA8; j >= 0; j -= 0xC) {
                *(s16 *)((u8 *)D_801F2B80 + 0xA + j) = 0;
            }
            func_801B27DC();
            func_800BBEAC(&func_801B2854);
        }
        if ((s16)p->unk2 < 0x50) {
            b = p->unk2 % 3;
            i = b * 5;
            n = i;
            for (; i < n + 5; i++) {
                q = (MgTask *)func_801B2800((s32)func_801B3070);
                q->unk0 = p->unk2;
                q->unk4 = func_80042DA8() % 200 - 0x64;
                q->unk6 = func_80042DA8() % 200 - 0x834;
                q->unk8 = func_80042DA8() % 200 - 0xC1C;
                v = D_801F2B80[i].cnt - 1;
                D_801F2B80[i].cnt = v;
                if ((s16)v == -1) {
                    w = (func_80042DA8() & 0x7FF) + 0x400;
                    v = w + D_801F2B7C;
                    D_801F2B7C = v;
                    D_801F2B80[i].a = v;
                    D_801F2B80[i].b = 0x400;
                    D_801F2B80[i].c = func_80042DA8() % 128 + 0x180;
                    D_801F2B80[i].d = func_80042DA8() % 50 + 0x64;
                    D_801F2B80[i].cnt = func_80042DA8() % 2 + 3;
                }
                func_8003C21C((MgSVec *)&D_801F2B80[i], &D_801F2870->m);
                D_801F2870->v.vx = 0;
                D_801F2870->v.vy = D_801F2B80[i].d;
                D_801F2870->v.vz = 0;
                func_8003B2CC(&D_801F2870->m, &D_801F2870->v, &q->unkC);
                D_801F2B80[i].a += 0x100;
            }
        } else {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B3660(MgTask *p) {
    s32 flag;
    s32 d;
    s32 t;

    func_8003B48C(&D_801F3554);
    func_8003B51C(&D_801F3554);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)D_801F2880.t, &flag);
    d = D_801F2880.t[2];
    if (d > 0) {
        t = (d >> 4) * 4 + 0x70;
        func_800D4484(t + D_801517C0, 0x20);
    }
    func_8003B48C(&D_801F2880);
    func_8003B51C(&D_801F2880);
    D_801F287C[0] = p->unk2;
    D_80163C74 = func_800D4D90((u16 *)&D_801F287C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801DBDA0[0]) {
            p->unk0 = -1;
            return;
        }
        p->unk4 = p->unk4;
        p->unk6 -= 0x14;
        p->unk8 -= 0x28;
    }
}

void func_801B379C(void) {
    MgTask *p;
    MgTask *q;
    u16 *tp;
    MgMat *m;
    s32 k;
    s32 i;
    s32 r;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        m = &D_801F3554;
        tp = (u16 *)((u8 *)m + 0x14);
        func_8003BF3C(m, &D_801F28A0->m);
        i = 0;
        func_8003B48C(&D_801F28A0->m);
        func_8003B51C(&D_801F28A0->m);
        do {
            q = (MgTask *)func_801B2800((s32)func_801B3660);
            i++;
            r = func_80042DA8() % D_80153BC8;
            D_801F28A0->v.vx = D_80153D40[r].x - tp[0];
            D_801F28A0->v.vy = D_80153D40[r].y - tp[2];
            D_801F28A0->v.vz = D_80153D40[r].z - tp[4];
            func_8003ACE4(&D_801F28A0->v, (MgSVec *)D_801F28A0->pad8);
            q->unk4 = *(u16 *)&D_801F28A0->pad8[0] + func_80042DA8() % 400 - 0x4B0;
            k = 0xC8;
            q->unk6 = *(u16 *)&D_801F28A0->pad8[4] - k + func_80042DA8() % 400;
            q->unk8 = *(u16 *)&D_801F28A0->pad8[8] + func_80042DA8() % 400 + 0x12C;
        } while (i < 3);
        p->unk2++;
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
    }
}

void func_801B3A24(MgTask *p) {
    s32 flag;
    s32 d;
    s32 t;

    func_8003B48C(&D_801F3554);
    func_8003B51C(&D_801F3554);
    func_8003BC6C((MgSVec *)&p->unk4, (MgVec *)D_801F28B0.t, &flag);
    d = D_801F28B0.t[2];
    if (d > 0) {
        t = (d >> 4) * 4 + 0x70;
        func_800D4484(t + D_801517C0, 0x20);
    }
    func_8003B48C(&D_801F28B0);
    func_8003B51C(&D_801F28B0);
    D_801F28AC[0] = p->unk2;
    D_80163C74 = func_800D4D90((u16 *)&D_801F28AC[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801DBDA0[0]) {
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 15 >> 4;
        p->unkE = p->unkE * 0x21 >> 5;
        p->unk10 = p->unk10 * 15 >> 4;
    }
}

void func_801B3BAC(void) {
    MgTask *p;
    MgTask *q;
    s32 i;
    s32 k;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        i = 0;
        do {
            q = (MgTask *)func_801B2800((s32)func_801B3A24);
            D_801F28D0->v.vx = func_80042DA8() % 256 + 0x100;
            D_801F28D0->v.vy = func_80042DA8() % 1024 - 0x200;
            D_801F28D0->v.vz = 0;
            k = func_80042DA8() % 200 + 0x12C;
            q->unk4 = k * func_80039A74(D_801F28D0->v.vy) >> 12;
            q->unk6 = 0;
            i++;
            q->unk8 = k * func_80039B40(D_801F28D0->v.vy) >> 12;
            func_8003C21C(&D_801F28D0->v, &D_801F28D0->m);
            D_801F28D0->v.vx = 0;
            D_801F28D0->v.vy = 0;
            D_801F28D0->v.vz = func_80042DA8() % 100 + 0xC8;
            func_8003B2CC(&D_801F28D0->m, &D_801F28D0->v, &q->unkC);
        } while (i < 5);
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B3DC0);

void func_801B41C4(void) {
    MgTask *p;
    MgMat *m;
    MgVec *sc;
    s32 t;
    s32 s;

    sc = (MgVec *)0x1F800020;
    p = &D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        D_801F296A = -(t << 12) / 5 + 0x1000;
        goto draw;
    }
    t -= 5;
    if (t < 0) {
        D_801F296A = 0;
        goto draw;
    }
    if (t < 5) {
        D_801F296A = (t << 12) / 5;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    s = p->unk14 * ((p->unk2 << 11) / 10 + 0x1000) >> 12;
    sc->vx = sc->vy = sc->vz = s;
    func_8003BF8C((MgSVec *)&p->unkC, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003B35C(m, sc);
    func_8003A63C(&D_801F3554, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_800D29D4(&D_801F2960, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        p->unkE += 0x80;
        p->unk6 -= 0x32;
    }
}

void func_801B43C4(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 q;

    p = &D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 5) {
        D_801F297A = 0;
        goto draw;
    }
    t -= 5;
    if (t < 10) {
        q = (t << 12) / 10;
        D_801F297A = q;
        goto draw;
    }
    p->unk0 = -1;
    return;
draw:
    q = (p->unk2 << 12) / 15;
    q = func_80039A74(q / 4) * 3;
    D_801F2980.m[0][0] = D_801F2980.m[1][1] = D_801F2980.m[2][2] = q;
    func_8003A63C(&D_801F3554, &D_801F2980, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_80163C74 = func_800D29D4(&D_801F2970, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B4538(void) {
    MgTask *p;
    s16 t;
    s32 n;
    s32 k;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801F29AA = 0;
        k = (t << 14) / 5;
    } else {
        n = t - 5;
        if (n < 5) {
            D_801F29AA = (n << 12) / 5;
            k = 0x4000;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_800D4368(&p->unk4, k, 0);
    D_80163C74 = func_800D29D4(&D_801F29A0, D_801517C0 + 0x4084, 0, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B4654(void) {
    MgTask *p;
    s32 t;
    s32 q;
    s32 c;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        q = (t << 12) / 15;
        c = q * 3 << 10 >> 12;
    } else {
        t -= 0xF;
        if (t < 0x6E) {
            c = 0xC00;
        } else {
            t -= 0x6E;
            if (t < 0x3C) {
                q = (t << 12) / 60;
                c = (0x1000 - q) * 3 << 10 >> 12;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801F29C0.m[0][0] = D_801F29C0.m[1][1] = D_801F29C0.m[2][2] = c;
    func_8003A63C(&D_801F3554, &D_801F29C0, D_801F29E0);
    func_8003B48C(D_801F29E0);
    func_8003B51C(D_801F29E0);
    func_8003B69C(0, 0, 0);
    D_80163C74 = func_801B01C0(&D_801F29B0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B47E0(void) {
    MgTask *p;
    u8 *k;
    s32 t;
    s32 c;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    k = (u8 *)D_80163C74;
    if (t < 5) {
        q = (t << 12) / 5;
        c = (u32)(q * 0xFF) >> 12;
        goto draw;
    }
    t -= 5;
    if (t >= 5) {
        goto kill;
    }
    q = (t << 12) / 5;
    c = (q * -0xFF >> 12) - 1;
draw:
    k[0x14] = k[0x1C] = c;
    k[0x15] = k[0x1D] = c;
    k[0x16] = k[0x1E] = c;
    p->unk10 = D_801F76F8;
    func_8003C21C((MgSVec *)&p->unkC, &D_801F2A04->m);
    D_801F2A04->m.t[0] = p->unk4;
    D_801F2A04->m.t[1] = p->unk6;
    D_801F2A04->m.t[2] = p->unk8;
    D_801F2A04->sc.vx = D_801F2A04->sc.vy = D_801F2A04->sc.vz = p->unk14;
    func_8003B35C(&D_801F2A04->m, &D_801F2A04->sc);
    func_8003A63C(&D_801F3554, &D_801F2A04->m, &D_801F2A04->m);
    func_8003B48C(&D_801F2A04->m);
    func_8003B51C(&D_801F2A04->m);
    D_801F2A04->depth = func_8003BD7C(&D_801F29E4[0], &D_801F29E4[1], &D_801F29E4[2], &D_801F29E4[3], k + 8, k + 0x10, k + 0x18, k + 0x20, &D_801F2A04->ext, &D_801F2A04->flag);
    if (!(D_801F2A04->flag & 0x60000)) {
        *(s32 *)(k + 4) = *(s32 *)(k + 0xC) = 0x3A000000;
        ((MgWord *)k)->v = 0x08000000;
        func_80046794(D_801517C0 + 0x4084, k);
        D_80163C74 = (s32)(k + 0x24);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 + p->unk0 >= 0xF) {
kill:
            p->unk0 = -1;
        }
    }
}

void func_801B4A38(void) {
    MgTask *p;
    u8 *k;
    s32 t;
    s32 c;
    s32 q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    k = (u8 *)D_80163C74;
    if (t < 5) {
        q = (t << 12) / 5;
        c = q * 0xFF >> 12;
        goto draw;
    }
    t -= 5;
    if (t >= 5) {
        goto kill;
    }
    q = (t << 12) / 5;
    c = (q * -0xFF >> 12) - 1;
draw:
    k[4] = c;
    k[5] = c;
    k[6] = c;
    func_8003C21C((MgSVec *)&p->unkC, &D_801F2A20->m);
    D_801F2A20->m.t[0] = p->unk4;
    D_801F2A20->m.t[1] = p->unk6;
    D_801F2A20->m.t[2] = p->unk8;
    D_801F2A20->sc.vx = D_801F2A20->sc.vy = D_801F2A20->sc.vz = p->unk14;
    func_8003B35C(&D_801F2A20->m, &D_801F2A20->sc);
    func_8003A63C(&D_801F3554, &D_801F2A20->m, &D_801F2A20->m);
    func_8003B48C(&D_801F2A20->m);
    func_8003B51C(&D_801F2A20->m);
    D_801F2A08[1].vz = -(u16)p->unk16;
    D_801F2A08[2].vz = (u16)p->unk16;
    D_801F2A20->depth = func_8003BC0C(&D_801F2A08[0], &D_801F2A08[1], &D_801F2A08[2], k + 8, k + 0x10, k + 0x18, &D_801F2A20->ext, &D_801F2A20->flag);
    if (!(D_801F2A20->flag & 0x60000)) {
        k[7] = 0x32;
        *(s32 *)(k + 0xC) = 0x32000000;
        *(s32 *)(k + 0x14) = 0x32000000;
        ((MgWord *)k)->v = 0x06000000;
        func_80046794(D_801517C0 + 0x4084, k);
        D_80163C74 = (s32)(k + 0x1C);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 + p->unk0 >= 0x19) {
kill:
            p->unk0 = -1;
        }
    }
}

void func_801B4C8C(void) {
    MgTask *p;
    s32 k;

    p = &D_80162978[D_8015169C];
    k = p->unk14;
    func_801B2944((MgSVec *)&p->unk4, k, -(k * 0x10) >> 9);
    D_801F2A2C[0] = p->unk2;
    D_80163C74 = func_800D4D90((u16 *)&D_801F2A2C[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801DBF28[0]) {
            p->unk0 = -1;
            return;
        }
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC = p->unkC * 7 >> 3;
        p->unkE -= 0xF;
        p->unk10 = p->unk10 * 7 >> 3;
    }
}

void func_801B4DBC(void) {
    MgTask *p;
    s32 t;
    u32 c;
    u32 v;
    s32 off;
    u8 *q;

    p = &D_80162978[D_8015169C];
    t = D_801F2A30[p->unk0];
    if (t == -1) {
        if (D_801F2A64 == 0) {
            p->unk0 = -1;
            return;
        }
        goto flash;
    }
    if (p->unk2 == t) {
        D_801F2A64 = 0xFFFF;
        p->unk0++;
    }
    if (D_801F2A64 != 0) {
flash:
        c = D_801F2A64 >> 8;
        off = D_801F2A60 * 16;
        q = D_801F2A40 + off;
        D_801F2A44[off] = q[5] = q[6] = c;
        func_80046794(D_801517C0 + 0x4084, &D_801F2A40[D_801F2A60 * 16]);
        D_801F2A60 ^= 1;
        v = D_801F2A64 - 0x8000;
        D_801F2A64 = v;
        if ((s32)v < 0) {
            D_801F2A64 = 0;
        }
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B4F30(void) {
    MgTask *p;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        v = p->unk2;
        if (v < 0xF) {
            v = (v << 12) / 15;
            v = (-(v * 0x1FF0) >> 12) + 0xFF0;
        } else {
            v -= 0xF;
            if (v < 0xA) {
                v = -0x1000;
            } else {
                v -= 0xA;
                if (v >= 0x28) {
                    D_800F5B74 = 0;
                    p->unk0 = -1;
                    return;
                }
                v = (v << 12) / 40;
                v = ((v << 12) >> 12) - 0x1000;
            }
        }
        if (v > 0) {
            D_800F5B70 = 0x10;
            D_800F5B71 = 0x10;
            D_800F5B72 = 0;
            D_800F5B74 = v;
        } else {
            D_800F5B70 = 0xFF;
            D_800F5B71 = 0xFF;
            D_800F5B72 = 0xFF;
            D_800F5B74 = -v;
        }
        if (D_80062D98 == 0) {
            p->unk2++;
        }
    }
}

void func_801B5088(void) {
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    t = (p->unk2 << 12) / p->unk8;
    D_80162084 = p->unk4 + ((p->unk6 - p->unk4) * t >> 12);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= p->unk8) {
            p->unk0 = -1;
        }
    }
}

void func_801B5148(s16 arg0, s16 arg1, s16 arg2) {
    MgTask *temp_v0;

    temp_v0 = &D_80162978[func_800BBEAC(&func_801B5088)];
    temp_v0->unk4 = arg0;
    temp_v0->unk6 = arg1;
    temp_v0->unk8 = arg2;
}

void func_801B51AC(void) {
    MgTask *p;
    MgMat *mat;
    MgMat *g;
    s32 t;
    s32 u;
    s32 k;
    OdG4 *pk;
    u8 pad[8];

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    u = t;
    g = &D_80153ECC;
    if (t < 0xA2) {
        mat = g;
    } else {
        t -= 0xA2;
        if (t < 0x12) {
            if (t == 0) {
                func_800D41FC(&D_801F3554, g, &D_801F2A88);
                p->unk4 = D_801F2A9C[0];
                p->unk6 = D_801F2A9C[1];
                p->unk8 = D_801F2A9C[2];
                D_801F2AE0->rot.vx = 0x7CB;
                D_801F2AE0->rot.vy = 0;
                D_801F2AE0->rot.vz = 0;
                func_8003C21C(&D_801F2AE0->rot, &D_801F2A88);
                p->unkC = 0;
                p->unkE = (u32)(func_80039B40(0x7CB) * 0x753) >> 8;
                p->unk10 = (u32)(func_80039A74(0x7CB) * 0x753) >> 8;
            }
            if (D_80062D98 == 0) {
                k = func_801B166C((t << 12) / 18, -0x380);
                D_801F2A9C[0] = p->unk4 + (p->unkC * k >> 12);
                D_801F2A9C[1] = p->unk6 + (p->unkE * k >> 12);
                D_801F2A9C[2] = p->unk8 + (p->unk10 * k >> 12);
            }
            func_8003A63C(&D_801F3554, &D_801F2A88, &D_801F2AE0->m);
            k = func_801B166C((t << 12) / 18, -0x280);
            D_801F2AE0->sc.vx = D_801F2AE0->sc.vy = D_801F2AE0->sc.vz = (k << 13 >> 12) + 0x1000;
            func_8003B35C(&D_801F2AE0->m, &D_801F2AE0->sc);
            D_801F2ADC = 0;
            mat = &D_801F2AE0->m;
        } else {
            t -= 0x12;
            if (t < 0x23) {
                if (t == 0) {
                    s32 r;

                    D_801F2AE0->rot.vx = 0x540;
                    D_801F2AE0->rot.vy = 0;
                    D_801F2AE0->rot.vz = 0;
                    func_8003C21C(&D_801F2AE0->rot, &D_801F2A88);
                    p->unkC = 0;
                    p->unkE = (u32)(func_80039B40(0x540) * 0x36B) >> 9;
                    r = func_80039A74(0x540);
                    p->unk4 = 0;
                    p->unk10 = (u32)(r * 0x36B) >> 9;
                    p->unkC = 0;
                    k = -0x4E20;
                    p->unk6 = k - (u16)p->unkE;
                    p->unkE = p->unkE * 0x23 / 20;
                    p->unk8 = -(u16)p->unk10;
                    p->unk10 = p->unk10 * 0x23 / 20;
                    D_801F2ADC = 0;
                }
                if (D_80062D98 == 0) {
                    k = func_801B166C((t << 12) / 35, 0x1FF);
                    D_801F2A9C[0] = p->unk4 + (p->unkC * k >> 12);
                    D_801F2A9C[1] = p->unk6 + (p->unkE * k >> 12);
                    D_801F2A9C[2] = p->unk8 + (p->unk10 * k >> 12);
                }
                func_8003A63C(&D_801F3554, &D_801F2A88, &D_801F2AE0->m);
                k = func_801B166C((t << 12) / 35, 0x4FF);
                D_801F2AE0->sc.vx = D_801F2AE0->sc.vy = D_801F2AE0->sc.vz = (-(k * 0xEE00) >> 12) + 0xF000;
                func_8003B35C(&D_801F2AE0->m, &D_801F2AE0->sc);
                D_801F2AC0[0] = 0xA79 - (D_801F2AE0->sc.vy * 0xA79 >> 12);
                func_8003A63C(&D_801F2AE0->m, (MgMat *)((u8 *)D_801F2AC0 - 0x18), &D_801F2AE0->m);
                mat = &D_801F2AE0->m;
            } else {
                t -= 0x23;
                if (t < 0x2D) {
                    if (D_80062D98 == 0) {
                        p->unk2 = u + 1;
                    }
                    return;
                }
                t -= 0x2D;
                if (t < 0x23) {
                    if (t == 0) {
                        D_801F2A9C[0] = 0;
                        D_801F2A9C[1] = -0x4524;
                        D_801F2A9C[2] = 0xD48;
                        D_801F2AE0->rot.vx = 0;
                        D_801F2AE0->rot.vy = 0;
                        D_801F2AE0->rot.vz = 0;
                        func_8003C21C(&D_801F2AE0->rot, (MgMat *)((u8 *)D_801F2A9C - 0x14));
                        D_801F2ADC = 0;
                    }
                    if (t < 5 && D_80062D98 == 0) {
                        D_801F2A9C[1] += 0xBB8;
                    }
                    func_8003A63C(&D_801F3554, &D_801F2A88, &D_801F2AE0->m);
                    mat = &D_801F2AE0->m;
                } else {
                    p->unk0 = -1;
                    return;
                }
            }
        }
    }
    func_8003B48C(mat);
    func_8003B51C(mat);
    D_80163C74 = func_800D29D4(D_801F2A68, D_801517C0 + 0x70, 0xC, D_80163C74);
    D_80163C74 = func_800D29D4(D_801F2A78, D_801517C0 + 0x30, 0xC, D_80163C74);
    func_800D41FC(&D_801F3554, mat, &D_801F2AE0->m);
    func_8003B48C(&D_801F2AE0->m);
    func_8003B51C(&D_801F2AE0->m);
    func_8003BC6C(&D_801F2AC8[0], &D_801F2AE0->sc, &D_801F2AE0->flag);
    D_801F3534[D_801F2AD8].a.vx = D_801F2AE0->sc.vx;
    D_801F3534[D_801F2AD8].a.vy = D_801F2AE0->sc.vy;
    D_801F3534[D_801F2AD8].a.vz = D_801F2AE0->sc.vz;
    func_8003BC6C(&D_801F2AC8[1], &D_801F2AE0->sc, &D_801F2AE0->flag);
    D_801F3534[D_801F2AD8].b.vx = D_801F2AE0->sc.vx;
    D_801F3534[D_801F2AD8].b.vy = D_801F2AE0->sc.vy;
    D_801F3534[D_801F2AD8].b.vz = D_801F2AE0->sc.vz;
    D_801F2AD8 ^= 1;
    if (D_801F2ADC != 0) {
        func_8003B48C(&D_801F3554);
        func_8003B51C(&D_801F3554);
        pk = (OdG4 *)D_80163C74;
        D_801F2AE0->depth = func_8003BD7C(&D_801F3534[D_801F2AD8].a, &D_801F3534[D_801F2AD8].b, &D_801F3534[D_801F2AD8 ^ 1].a, &D_801F3534[D_801F2AD8 ^ 1].b, &pk->xy0, &pk->xy1, &pk->xy2, &pk->xy3, &D_801F2AE0->ext, &D_801F2AE0->flag);
        if (!(D_801F2AE0->flag & 0x60000)) {
            pk->tag = 0x08000000;
            pk->c1 = 0x3A000000;
            pk->c0 = 0x3A000000;
            pk->c3 = 0x3A400080;
            pk->c2 = 0x3A400080;
            func_80046794(D_801517C0 + 0x70 + ((D_801F2AE0->depth >> 2) << 2), pk);
            D_80163C74 = (s32)(pk + 1);
        }
    }
    D_801F2ADC = 1;
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B5A74(void) {
    MgTask *p;
    MgTask *q;
    u8 *cam;
    s32 t;
    s32 k;

    p = &D_80162978[D_8015169C];
    cam = D_80153BB8;
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0) {
            q = func_800D4FA8(1);
            func_8003B2CC(&D_801DD620, &D_801F2AE4, D_801F2AEC);
            q->unk4 = ((OdHW *)&D_801DD620.t[0])->v + D_801F2AEC[0];
            q->unk6 = ((OdHW *)&D_801DD620.t[1])->v + D_801F2AEC[1];
            q->unk8 = ((OdHW *)&D_801DD620.t[2])->v + D_801F2AEC[2];
            *(s16 *)((u8 *)q + 0x10) = ((OdHW *)&D_801DD618.vy)->v + 0x800;
            D_80153BE0 = D_80153BE1 = D_80153BE2 = 0;
        }
        if (t < 0x1E) {
            D_801F2AE4.vy += 0x21;
            D_801F2AE8 += 0x64;
            k = ((t + 1) << 12) / 30;
            D_80153BCC = (-(k << 12) >> 12) + 0x1000;
        } else {
            t -= 0x1E;
            if (t >= 0x96) {
                t -= 0x96;
                if (t < 0x23) {
                    if (t == 0) {
                        D_80153BDD |= 2;
                    }
                } else {
                    t -= 0x23;
                    if (t < 0x28) {
                        if (t == 0) {
                            D_80153BDD &= 0xFD;
                        }
                        if (t == 0x18) {
                            func_800D4FA8(2);
                            p->unk0 = -1;
                        }
                    }
                }
            }
        }
        func_8003B2CC(&D_801DD620, &D_801F2AE4, D_801F2AEC);
        *(u16 *)(cam + 0x168) = ((OdHW *)&D_801DD620.t[0])->v + D_801F2AEC[0];
        *(u16 *)(cam + 0x16A) = ((OdHW *)&D_801DD620.t[1])->v + D_801F2AEC[1];
        *(u16 *)(cam + 0x16C) = ((OdHW *)&D_801DD620.t[2])->v + D_801F2AEC[2];
        p->unk2++;
    }
}

void func_801B5D14(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    MgTask *e;
    s32 t;
    s32 i;
    s32 x;
    s32 y;
    s32 r;

    b = D_80162978;
    p = &b[D_8015169C];
    func_8003A63C(&D_800FA63C, &D_801DD620, &D_801F3554);
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t >= 5) {
            t -= 5;
            if (t < 0x41) {
                if (t == 0) {
                    func_800BBEAC((M2C_UNK *)func_801B4654);
                    func_800BBEAC((M2C_UNK *)func_801B2BE0);
                    q = (MgTask *)((func_800BBEAC((M2C_UNK *)func_801B4DBC) << 5) + (s32)b);
                    q->unk0 = 0;
                }
                if (t == 0xF) {
                    func_800BBEAC((M2C_UNK *)func_801B32BC);
                    func_800D52A0(0xFF0, 0x6E);
                    D_800F5B71 = D_800F5B70 = 0x10;
                    D_800F5B72 = 0;
                }
                if (t == 0) {
                    func_800D55F4(0x22, 0x40, 0x253, 0x254, 0x255);
                }
            } else {
                t -= 0x41;
                if (t >= 0xF) {
                    t -= 0xF;
                    if (t < 0xF) {
                        if (t == 0xE) {
                            func_800BBEAC((M2C_UNK *)func_801B5A74);
                        }
                    } else {
                        t -= 0xF;
                        if (t < 0xF) {
                            if (t == 0) {
                                func_800BBEAC((M2C_UNK *)func_801B51AC);
                                func_800BBEAC((M2C_UNK *)func_801B379C);
                            }
                        } else {
                            t -= 0xF;
                            if (t >= 0xF) {
                                t -= 0xF;
                                if (t < 0x3C) {
                                    if (t == 0) {
                                        func_800BBEAC((M2C_UNK *)func_801B3BAC);
                                        func_800D55F4(0x21, 0x40, 0x256, 0x257);
                                    }
                                } else {
                                    t -= 0x3C;
                                    if (t < 0xF) {
                                        if (t == 0) {
                                            func_800D55F4(0x22, 0x40, 0x258, 0x259, 0x25A);
                                        }
                                    } else {
                                        t -= 0xF;
                                        if (t >= 0x19) {
                                            t -= 0x19;
                                            if (t >= 0x14) {
                                                t -= 0x14;
                                                if (t < 0xC) {
                                                    if (t == 0xB) {
                                                        func_801B5148(0x80, 0x80, 0x12);
                                                    }
                                                } else {
                                                    t -= 0xC;
                                                    if (t < 0x12) {
                                                        if (t == 0) {
                                                            e = func_800D4FA8(7);
                                                            e->unk10 = 2;
                                                            *(M2C_UNK **)((u8 *)e + 0xC) = &D_801B67C8;
                                                        }
                                                        if (t == 0x11) {
                                                            func_800D2980(&D_801B67C8, 0, 0, 0);
                                                            D_80162084 = 0x200;
                                                        }
                                                    } else {
                                                        t -= 0x12;
                                                        if (t < 0x14) {
                                                            if (t == 0) {
                                                                func_800BBEAC((M2C_UNK *)func_801B3DC0);
                                                                D_801F76FC = 0;
                                                            }
                                                        } else {
                                                            t -= 0x14;
                                                            if (t < 0xF) {
                                                                s32 g;

                                                                D_801F76FC = (t << 12) / 15;
                                                                D_801F76FC = func_80039A74(func_80039A74(func_80039A74(func_80039A74(D_801F76FC / 4) / 4) / 4) / 4);
                                                                *(s32 *)&D_801F76F8 = (-(D_801F76FC << 8) >> 12) + 0x400;
                                                                q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B47E0)];
                                                                q->unk0 = t;
                                                                q->unk4 = 0;
                                                                q->unk6 = -0x55F0;
                                                                q->unk8 = 0;
                                                                q->unkC = 0;
                                                                r = func_80042DA8();
                                                                q->unk10 = 0x380;
                                                                q->unk14 = 0x1000;
                                                                g = D_801F2B18 + 0x400;
                                                                q->unkE = D_801F2B18 = g + (r & 0x7FF);
                                                                q->unk16 = func_80042DA8() % 200 + 100;
                                                                if (t == 0) {
                                                                    func_800D55F4(0x22, 0x40, 0x25B, 0x25C, 0x25D);
                                                                }
                                                            } else {
                                                                t -= 0xF;
                                                                if (t < 0x19) {
                                                                    s32 g;

                                                                    if (t == 0) {
                                                                        func_800BBEAC((M2C_UNK *)func_801B4F30);
                                                                    }
                                                                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B4A38)];
                                                                    q->unk6 = -0x2328;
                                                                    q->unk0 = t;
                                                                    q->unk4 = 0;
                                                                    q->unk8 = 0xD48;
                                                                    q->unkC = 0;
                                                                    r = func_80042DA8();
                                                                    g = D_801F2B18 + 0x400;
                                                                    q->unkE = D_801F2B18 = g + (r & 0x7FF);
                                                                    q->unk10 = (func_80042DA8() & 0x7F) + 0x280;
                                                                    q->unk14 = 0x4000;
                                                                    q->unk16 = func_80042DA8() % 200 + 100;
                                                                    if (t == 0x18) {
                                                                        func_801B5148(0x100, 0x100, 0xF);
                                                                    }
                                                                } else {
                                                                    t -= 0x19;
                                                                    if (t < 0xF) {
                                                                        if (t == 0xE) {
                                                                            D_80162084 = 0x200;
                                                                        }
                                                                    } else {
                                                                        t -= 0xF;
                                                                        if (t < 0xA) {
                                                                            if (t == 0) {
                                                                                for (i = 0; i < 4; i++) {
                                                                                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B41C4)];
                                                                                    *(MgB8 *)&q->unk4 = D_801F2AF0[i];
                                                                                    q->unkC = 0;
                                                                                    q->unkE = func_80042DA8() & 0xFFF;
                                                                                    q->unk10 = 0;
                                                                                    q->unk14 = D_801F2B10[i];
                                                                                }
                                                                            }
                                                                        } else {
                                                                            t -= 0xA;
                                                                            if (t < 0x1E) {
                                                                                if (t == 0) {
                                                                                    i = 0;
                                                                                    func_800BBEAC((M2C_UNK *)func_801B43C4);
                                                                                    q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B4538)];
                                                                                    *(MgB8 *)&q->unk4 = *(MgB8 *)&p->unk4;
                                                                                    do {
                                                                                        q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B4C8C)];
                                                                                        q->unk4 = 0;
                                                                                        q->unk6 = 0;
                                                                                        q->unk8 = 0xD48;
                                                                                        x = (i << 12) / 20 + func_80042DA8() % 204;
                                                                                        y = func_80042DA8() % 200 + 200;
                                                                                        q->unkC = func_80039A74(x) * y >> 12;
                                                                                        q->unkE = 0;
                                                                                        q->unk10 = func_80039B40(x) * y >> 12;
                                                                                        q->unk14 = 0x4000;
                                                                                        i++;
                                                                                    } while (i < 0x14);
                                                                                    func_801B2FFC(0xC8, 0, 0, 0xA);
                                                                                    func_800D5774(D_801F3574);
                                                                                }
                                                                                if (t == 0) {
                                                                                    func_800D55F4(0x22, 0x40, 0x25E, 0x25F, 0x260);
                                                                                }
                                                                            } else {
                                                                                D_800F8380 = 0;
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
                            }
                        }
                    }
                }
            }
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_odin1/nonmatchings/text", func_801B65A0);
