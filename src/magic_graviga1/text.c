#include "common.h"
#include "magic_graviga1/decls.h"

void func_801B0000(void) {
    MgTask *p;
    MgMat *m;

    p = (MgTask *)&D_80162978[D_8015169C];
    m = func_800D4368(&p->unk8, 0x1200, 0);
    if (m->t[2] > 0) {
        func_800D4484(D_801517C0 + 0x70 + (m->t[2] >> 4) * 4, 0x20);
        D_801D1784[0] = p->unk2;
        D_801EFA84 = func_800D4D90(&D_801D1784[-4], D_801517C0 + 0x70, 0xC, D_801EFA84);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 5) {
            p->unk0 = -1;
        }
    }
}

void func_801B00E8(void) {
    MgObjVel *p;
    MgObjVel *q;

    p = (MgObjVel *)&D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        p->unk8.vx += p->unk10.vx;
        p->unk8.vy += p->unk10.vy;
        p->unk8.vz += p->unk10.vz;
        q = (MgObjVel *)&D_80162978[func_800BBEAC(&func_801B0000)];
        q->unk8 = p->unk8;
        p->unk2++;
        if (p->unk2 >= 8) {
            p->unk0 = -1;
        }
    }
}

void func_801B01C0(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    s32 s;
    u8 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 0xF) {
        D_801D1790 = D_801D1791 = D_801D1792 = 0x80;
        s = t * 0x2400 / 15 + 0x100;
    } else {
        t -= 0xF;
        if (t < 0x14) {
            D_801D1790 = D_801D1791 = D_801D1792 = 0x80;
            s = 0x2500;
        } else {
            t -= 0x14;
            if (t < 0xF) {
                c = -(t << 7) / 15 - 0x80;
                D_801D1790 = D_801D1791 = D_801D1792 = c;
                s = t * 0x1B00 / 15 + 0x2500;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    m = func_800D4368(&p->unk8, s, p->unk18);
    if (m->t[2] > 0) {
        func_800D4484(D_801517C0 + 0x70 + (m->t[2] >> 4) * 4, 0x20);
        D_801EFA84 = func_800D6260(D_801D1788, D_801517C0 + 0x70, 0xC, D_801EFA84);
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B03A8(void) {
    MgSVec v;
    u8 pad[8];
    MgMat m;
    MgTask *p;
    s32 t;
    s32 i;
    s32 ang;
    s32 k;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        D_801D17A0 = D_801D17A1 = D_801D17A2 = (t << 7) / 5;
    } else {
        t -= 5;
        if (t < 0x1E) {
            D_801D17A0 = D_801D17A1 = D_801D17A2 = 0x80;
        } else {
            t -= 0x1E;
            if (t >= 5) {
                p->unk0 = -1;
                return;
            }
            D_801D17A0 = D_801D17A1 = D_801D17A2 = -(t << 7) / 5 - 0x80;
        }
    }
    k = p->unk18 * ((func_80039A74(((p->unk0 + p->unk2) << 12) / 30) << 10 >> 12) + 0xC00) >> 12;
    for (i = 0; i < 0x10; i++) {
        ang = (p->unk2 << 6) + (i << 8);
        v.vx = (func_80039A74(ang) * func_80039B40(ang) >> 12) * k >> 12;
        v.vy = func_80039B40(ang) * k >> 12;
        v.vz = 0;
        func_8003C21C((MgSVec *)&p->unk10, &m);
        func_8003B2CC(&m, &v, &v);
        v.vx += p->unk8;
        v.vy += p->unkA;
        v.vz += p->unkC;
        func_800D4368(&v, 0x900, 0);
        D_801EFA84 = func_800D6260(D_801D1798, D_801517C0 + 0x70, 0xC, D_801EFA84);
    }
    if (D_80062D98 == 0) {
        p->unk10 += 0x50;
        p->unk12 += 0x40;
        p->unk14 += 0x50;
        p->unk2++;
    }
}

void func_801B0634(void) {
    MgTask *p;
    MgMat *m;
    s32 t;
    u8 c;

    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    if (t < 5) {
        c = (t << 7) / 5;
        D_801D17AC = D_801D17AD = D_801D17AE = c;
    } else {
        t -= 5;
        if (t < 0x28) {
            c = 0x80;
            D_801D17AC = D_801D17AD = D_801D17AE = c;
        } else {
            t -= 0x28;
            if (t < 5) {
                c = -(t << 7) / 5 - 0x80;
                D_801D17AC = D_801D17AD = D_801D17AE = c;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    D_801D17B0[0] = (p->unk2 + p->unk0) % 12;
    m = func_800D4368(&p->unk8, p->unk1A, p->unk18);
    m->t[0] += p->unk10;
    m->t[1] += p->unk12;
    func_8003B51C(m);
    D_801EFA84 = func_800D4D90(&D_801D17B0[-4], D_801517C0 + 0x70, 0xC, D_801EFA84);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B07D8(MgTask *p) {
    MgSVec *sv;
    MgSVec *sv2;
    MgSVec *d;
    s32 ext;
    s32 flag;
    s32 r;
    s32 k;
    s32 t;
    s32 g;
    s32 u;
    u16 x0;
    u16 x1;
    u16 y0;
    u16 y1;
    s16 dx;
    s16 dy;
    u8 *q;

    sv = (MgSVec *)0x1F800000;
    sv2 = (MgSVec *)0x1F800008;
    d = (MgSVec *)0x1F800010;
    x1 = p->unkC;
    sv2->vx = x1;
    x0 = p->unk4;
    dx = x1 - x0;
    sv->vx = x0;
    d->vx = dx;
    y1 = p->unkE;
    sv2->vy = y1;
    y0 = p->unk6;
    sv->vz = 0;
    sv2->vz = 0;
    d->vz = 0;
    dy = y1 - y0;
    sv->vy = y0;
    d->vy = dy;
    k = p->unk2;
    if (k < 2) {
        sv2->vx = x0 + dx * k / 2;
        sv2->vy = y0 + dy * k / 2;
    } else {
        k -= 2;
        if (k < 2) {
            sv->vx = x0 + dx * k / 2;
            sv->vy = y0 + dy * k / 2;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    q = D_801EFA84;
    r = func_8003BC0C(sv, sv + 1, sv + 1, q + 0x10, q + 0x18, q + 0x18, &ext, &flag);
    if (!(flag & 0x60000)) {
        t = (r >> 2) * 4 + 0x70;
        *(s32 *)q = 0x08000000;
        *(s32 *)(q + 0x1C) = 0x3A000000;
        *(s32 *)(q + 0xC) = 0x3A000000;
        *(s32 *)(q + 0x14) = 0x3A606060;
        *(s32 *)(q + 4) = 0x3A000000;
        *(s16 *)(q + 8) = *(u16 *)(q + 0x18) + p->unk14;
        *(s16 *)(q + 0xA) = *(u16 *)(q + 0x1A) + p->unk16;
        *(s16 *)(q + 0x20) = *(u16 *)(q + 0x18) + p->unk1C;
        u = *(u16 *)(q + 0x1A);
        g = D_801517C0;
        *(s16 *)(q + 0x22) = u + p->unk1E;
        func_80046794(t + g, q);
        D_801EFA84 = q + 0x24;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

s32 func_801B0A34(void) {
    s32 n;
    s32 i;
    s32 m;
    u8 *p;
    s32 o;

    n = 0;
    i = 0;
    m = -1;
    p = D_801D17B4;
    o = 0;
    do {
        if (*(s16 *)(D_801D17B4 + o) != m) {
            func_801B07D8(p);
            n++;
        }
        o += 0x24;
        i++;
        p += 0x24;
    } while (i < 0x14);
    return n;
}

INCLUDE_ASM("../asm/us/magic_graviga1/nonmatchings/text", func_801B0AC8);

void func_801B0E54(void) {
    MgTask *p;
    MgTask *q;
    MgSVec sv;
    u8 pad[8];
    s32 t;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t == 0) {
            func_800D52A0(0x400, 4);
            D_800F5B72 = D_800F5B71 = D_800F5B70 = 0xFF;
        }
        t -= 4;
        if (t == 0) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B00E8)];
            func_800D3994(p->unk6, D_8015190F[p->unk6][0], &q->unk8);
            *(GvBytes8 *)&sv = *(GvBytes8 *)&p->unk8;
            q->unk10 = (sv.vx - q->unk8) / 8;
            q->unk12 = (sv.vy - q->unkA) / 8;
            q->unk14 = (sv.vz - q->unkC) / 8;
            func_800D55F4(0x20, func_800D56A8(&q->unk8), 0x50);
        }
        if (t == 0xC) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B03A8)];
            q->unk0 = 0;
            *(GvBytes8 *)&q->unk8 = *(GvBytes8 *)&p->unk8;
            q->unk18 = 0x3E8;
            q->unk14 = 0;
            q->unk12 = 0;
            q->unk10 = 0;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B03A8)];
            q->unk0 = 0xF;
            *(GvBytes8 *)&q->unk8 = *(GvBytes8 *)&p->unk8;
            q->unk18 = 0x3E8;
            q->unk10 = 0;
            q->unk12 = 0x400;
            q->unk14 = 0;
        }
        if (t == 8) {
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0634)];
            q->unk0 = 0;
            *(GvBytes8 *)&q->unk8 = *(GvBytes8 *)&p->unk8;
            q->unk10 = 0;
            q->unk12 = -0x1F4;
            q->unk18 = -D_801518F6[p->unk4][0];
            q->unk1A = 0x2000;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0634)];
            q->unk0 = 2;
            *(GvBytes8 *)&q->unk8 = *(GvBytes8 *)&p->unk8;
            q->unk10 = -0x12C;
            q->unk12 = 0;
            q->unk18 = -D_801518F6[p->unk4][0];
            q->unk1A = 0x2000;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0634)];
            q->unk0 = 4;
            *(GvBytes8 *)&q->unk8 = *(GvBytes8 *)&p->unk8;
            q->unk10 = 0x12C;
            q->unk12 = 0xC8;
            q->unk18 = -D_801518F6[p->unk4][0];
            q->unk1A = 0x2000;
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B01C0)];
            *(GvBytes8 *)&q->unk8 = *(GvBytes8 *)&p->unk8;
            q->unk18 = -D_801518F6[p->unk4][0];
            func_800D55F4(0x20, func_800D56A8(&q->unk8), 0x4A);
            q = &D_80162978[func_800BBEAC((M2C_UNK *)func_801B0AC8)];
            *(GvBytes8 *)&q->unk8 = *(GvBytes8 *)&p->unk8;
        }
        if (t == 0xF) {
            func_800D5774(p->unk4);
        }
        if (t >= 0xF) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1348(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0E54)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
}

void func_801B13D4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EFA84 = D_801D1A84 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        p->unk0 = -1;
    }
}

void func_801B1464(s32 arg0, M2C_UNK arg1) {
    s32 i;
    s32 m;

    func_800D2980(&D_801B14F4, 0, 0, 0);
    func_800BBEAC(&func_801B13D4);
    m = -1;
    for (i = 0x2AC; i >= 0; i -= 0x24) {
        *(s16 *)(D_801D17B4 + i) = m;
    }
    func_800D5444(arg0, arg1, 8, func_801B1348);
}
