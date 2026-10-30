#include "common.h"
#include "magic_wpyu/decls.h"

void func_801B0054(void) {
    D_801D3BFC = &D_801B265C;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B008C(void) {
    D_801D3BFC = &D_801B2E40;
    D_801D3C00 = 1;
    func_801B25A8();
}

void func_801B00C8(void) {
    D_801D3BFC = &D_801B3774;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B0100(void) {
    D_801D3BFC = &D_801B4178;
    D_801D3C00 = 1;
    func_801B25A8();
}

void func_801B013C(void) {
    D_801D3BFC = &D_801B4B8C;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B0174(void) {
    D_801D3BFC = &D_801B5420;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B01AC(void) {
    D_801D3BFC = &D_801B6134;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B01E4(void) {
    D_801D3BFC = &D_801B6B30;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B021C(void) {
    D_801D3BFC = &D_801B7554;
    D_801D3C00 = 2;
    func_801B25A8();
}

void func_801B0258(void) {
    D_801D3BFC = &D_801B8038;
    D_801D3C00 = 1;
    func_801B25A8();
}

void func_801B0294(void) {
    D_801D3BFC = &D_801B871C;
    D_801D3C00 = 2;
    func_801B25A8();
}

void func_801B02D0(void) {
    D_801D3BFC = &D_801B9288;
    D_801D3C00 = 1;
    func_801B25A8();
}

void func_801B030C(void) {
    D_801D3BFC = &D_801B9DDC;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B0344(void) {
    D_801D3BFC = &D_801BA410;
    D_801D3C00 = 0;
    func_801B25A8();
}

void func_801B037C(void) {
    D_801D3BFC = &D_801BB390;
    D_801D3C00 = 3;
    func_801B25A8();
}

s32 func_801B03B8(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0494(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0610(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B06EC(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B07D0(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgVec w;
    MgVec v;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk14;
    rot.vz = -0x400;
    func_8003C21C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_801B0494(func_801B03B8(&D_801BBBA4, (MgVec *)D_801D3BEC, &v), &m2, &v);
    func_8003B16C(&m2, &m1);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    w.vx = 0;
    w.vy = 0;
    w.vz = 0;
    func_8003AB84(&m1, &w, &w);
    m1.t[0] += w.vx;
    m1.t[1] += w.vy;
    m1.t[2] += w.vz;
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801D3BFC;
    if (p->unk2 >= 0x16) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unkA = (p->unk2 - 0x16) * 0x200;
    }
    func_8003B69C(0, 0, 0);
    D_801D3BB4 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D3BB4);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += p->unk16;
        p->unk2++;
    }
}

void func_801B0A24(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgVec w;
    MgVec v;
    MgTask *p;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vx = 0;
    rot.vy = p->unk14;
    rot.vz = -0x400;
    func_8003C21C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_801B0494(func_801B03B8(&D_801BBBA4, (MgVec *)D_801D3BEC, &v), &m2, &v);
    func_8003B16C(&m2, &m1);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    w.vx = 0;
    w.vy = 0;
    w.vz = 0;
    func_8003AB84(&m1, &w, &w);
    m1.t[0] += w.vx;
    m1.t[1] += w.vy;
    m1.t[2] += w.vz;
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801D3BFC;
    func_8003B69C(0, 0, 0);
    D_801D3BB4 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D3BB4);
    if (p->unk2 >= 0x18) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        t = p->unk2;
        if (t < 0xC) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unk14 += p->unk16;
        } else if (t < 0x18) {
            p->unk4 -= p->unkC;
            p->unk6 -= p->unkE;
            p->unk8 -= p->unk10;
            p->unk14 += p->unk16;
        }
        if (p->unk2 == 6) {
            func_800D55F4(0x20, func_800D56A8(&D_801D3BCC), 0x159);
        }
        p->unk2++;
    }
}

void func_801B0CD0(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgVec w;
    MgVec v;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = 0;
    func_8003C21C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_801B0494(func_801B03B8(&D_801BBBA4, (MgVec *)D_801D3BEC, &v), &m2, &v);
    func_8003B16C(&m2, &m1);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    w.vx = 0;
    w.vy = 0;
    w.vz = 0;
    func_8003AB84(&m1, &w, &w);
    m1.t[0] += w.vx;
    m1.t[1] += w.vy;
    m1.t[2] += w.vz;
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801D3BFC;
    if (p->unk2 >= 2) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unkA = (p->unk2 - 2) * 0x200;
    }
    func_8003B69C(0, 0, 0);
    D_801D3BB4 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D3BB4);
    if (p->unk2 >= 4) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unk14 += p->unk16;
        p->unk2++;
    }
}

void func_801B0F20(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgVec w;
    MgVec v;
    MgTask *p;
    MgScratch *s;
    s32 k;

    s = (MgScratch *)0x1F800000;
    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = 0;
    func_8003C21C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    func_801B0494(func_801B03B8(&D_801BBBA4, (MgVec *)D_801D3BEC, &v), &m2, &v);
    func_8003B16C(&m2, &m1);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    w.vx = 0;
    w.vy = 0;
    w.vz = 0;
    func_8003AB84(&m1, &w, &w);
    m1.t[0] += w.vx;
    m1.t[1] += w.vy;
    m1.t[2] += w.vz;
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    s->unk0 = D_801D3BFC;
    if (p->unk2 < 4) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - p->unk2 * 0x400;
    } else if (p->unk2 >= p->unk1C - 4) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        k = p->unk2 + 4;
        ((MgScratch *)0x1F800000)->unkA = (k - p->unk1C) * 0x400;
    }
    func_8003B69C(0, 0, 0);
    D_801D3BB4 = func_800D29D4(s, D_801517C0 + 0x70, 0xC, D_801D3BB4);
    if (p->unk2 >= p->unk1C) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 4) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
            p->unk14 += p->unk16;
        }
        if (p->unk2 == 4) {
            func_800D55F4(0x20, func_800D56A8(&D_801D3BCC), 0x159);
        }
        p->unk2++;
    }
}

void func_801B11F8(void) {
    MgSVec rot;
    MgMat m1;
    MgMat m2;
    MgVec sc;
    MgVec d;
    MgVec v;
    MgTask *p;

    rot.vz = 0x400;
    rot.vx = 0;
    rot.vy = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    d.vx = p->unkC;
    d.vy = p->unkE;
    d.vz = p->unk10;
    func_8003A08C(&d, &d);
    func_801B0494(func_801B03B8(&D_801BBBA4, &d, &v), &m2, &v);
    func_8003B16C(&m2, &m1);
    sc.vx = sc.vy = sc.vz = 0xCCC;
    func_8003B35C(&m1, &sc);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    d.vx = 0;
    d.vy = 0;
    d.vz = 0;
    func_8003AB84(&m1, &d, &d);
    m1.t[0] += d.vx;
    m1.t[1] += d.vy;
    m1.t[2] += d.vz;
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801D3BFC;
    if (p->unk2 >= 6) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unkA = (p->unk2 - 6) * 0x400;
    }
    func_8003B69C(0, 0, 0);
    D_801D3BB4 = func_800D29D4((void *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D3BB4);
    if (p->unk2 >= 0xA) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 4) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        p->unk2++;
    }
}

void func_801B14A4(void) {
    MgTask *p;
    MgTask *q;
    s32 k;
    u8 pad[16];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801D3BEC[0] = D_801D3BCC[0] - D_801D3BD4[0];
            D_801D3BF0 = D_801D3BCC[1] - D_801D3BD4[1];
            D_801D3BF4 = D_801D3BCC[2] - D_801D3BD4[2];
            k = func_80039F5C(((s32 (*)(s32 *, s32 *))func_8003A08C)(D_801D3BEC, D_801D3BEC)) / 6;
            q = &D_80162978[func_800BBEAC(&func_801B07D0)];
            *(WpB8 *)&q->unk4 = *(WpB8 *)&D_801D3BD4[0];
            *(s16 *)((u8 *)q + 0xC) = (k * D_801D3BEC[0]) >> 12;
            *(s16 *)((u8 *)q + 0xE) = (k * D_801D3BF0) >> 12;
            q->unk10 = (k * D_801D3BF4) >> 12;
            q->unk14 = 0;
            q->unk16 = 0x2BC;
        }
        if (p->unk2 == 7) {
            func_800D5774(D_801D3BC4);
            func_800D55F4(0x20, func_800D56A8(&D_801D3BCC), 0x159);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B169C(void) {
    MgTask *p;
    MgTask *q;
    s32 k;
    u8 pad[16];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801D3BEC[0] = D_801D3BCC[0] - D_801D3BD4[0];
            D_801D3BEC[1] = D_801D3BCC[1] - D_801D3BD4[1];
            D_801D3BEC[2] = D_801D3BCC[2] - D_801D3BD4[2];
            k = func_80039F5C(((s32 (*)(s32 *, s32 *))func_8003A08C)(D_801D3BEC, D_801D3BEC)) / 4;
            q = &D_80162978[func_800BBEAC(&func_801B0A24)];
            *(WpB8 *)&q->unk4 = *(WpB8 *)&D_801D3BD4[0];
            q->unkC = (k * D_801D3BEC[0]) >> 12;
            q->unkE = (k * D_801D3BEC[1]) >> 12;
            q->unk10 = (k * D_801D3BEC[2]) >> 12;
            q->unk14 = 0;
            q->unk16 = 0x2BC;
        }
        if (p->unk2 == 0x14) {
            func_800D5774(D_801D3BC4);
            func_800D55F4(0x20, func_800D56A8(&D_801D3BCC), 0x159);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1878(void) {
    MgTask *p;
    MgTask *q;
    s32 w;
    s32 t;
    u8 pad[16];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801D3BEC[0] = D_801D3BCC[0] - D_801D3BD4[0];
            D_801D3BF0 = D_801D3BCC[1] - D_801D3BD4[1];
            D_801D3BF4 = D_801D3BCC[2] - D_801D3BD4[2];
            ((s32 (*)(s32 *, s32 *))func_8003A08C)(D_801D3BEC, D_801D3BEC);
            q = &D_80162978[func_800BBEAC(&func_801B0CD0)];
            *(WpB8 *)&q->unk4 = *(WpB8 *)&D_801D3BD4[0];
            *(s16 *)((u8 *)q + 0xC) = (u32)(D_801D3BEC[0] * 0x4B) >> 10;
            *(s16 *)((u8 *)q + 0xE) = (u32)(D_801D3BF0 * 0x4B) >> 10;
            q->unk10 = (u32)(D_801D3BF4 * 0x4B) >> 10;
            *(s16 *)((u8 *)q + 0x14) = 0;
            *(s16 *)((u8 *)q + 0x16) = 0x2BC;
        }
        if ((u32)((u16)p->unk2 - 7) < 7) {
            q = &D_80162978[func_800BBEAC(&func_801B0F20)];
            *(WpB8 *)&q->unk4 = *(WpB8 *)&D_801D3BCC[0];
            w = *(s16 *)D_801518F6[D_801D3BC4];
            q->unk4 += func_80042DA8() % (w * 2) - w;
            q->unk6 += func_80042DA8() % (w * 2) - w;
            q->unk8 += func_80042DA8() % (w * 2) - w;
            t = func_80042DA8() % 150 + 0x12C;
            w = (t * D_801D3BEC[0]) >> 12;
            *(s16 *)((u8 *)q + 0xC) = w;
            *(s16 *)((u8 *)q + 4) -= w * 4;
            w = (t * D_801D3BF0) >> 12;
            *(s16 *)((u8 *)q + 0xE) = w;
            *(s16 *)((u8 *)q + 6) -= w * 4;
            w = (t * D_801D3BF4) >> 12;
            *(s16 *)((u8 *)q + 0x10) = w;
            *(s16 *)((u8 *)q + 8) -= w * 4;
            q->unk14 = func_80042DA8() % 200 + 0x12C;
            q->unk16 = func_80042DA8() % 300 + 0x190;
            q->unk1C = 0x1D - p->unk2;
        }
        if (p->unk2 == 0x1A) {
            func_800D5774(D_801D3BC4);
            func_800D55F4(0x20, func_800D56A8(&D_801D3BCC), 0x155);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_wpyu/nonmatchings/text", func_801B1D00);

void func_801B23C8(void) {
    MgSVec rot;
    MgMat m;
    MgTask *b;
    MgTask *p;
    M2C_UNK *f;

    b = D_80162978;
    p = &b[D_8015169C];
    p->unk0 = -1;
    func_800D3994(D_801D3BC4, D_8015190F[D_801D3BC4][0], D_801D3BCC);
    func_800D3994(D_801D3BC8, D_8015190F[D_801D3BC8][0], D_801D3BD4);
    rot.vy = D_801D3BDA = D_80151A46[D_801D3BC8][0];
    rot.vx = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801BBBA4, &D_801D3BDC);
    switch (D_801D3C00) {
    case 0:
        f = &func_801B14A4;
        break;
    case 1:
        f = &func_801B169C;
        break;
    case 2:
        f = &func_801B1878;
        break;
    case 3:
        f = &func_801B1D00;
        break;
    default:
        p->unk1C = 0;
        return;
    }
    p = (MgTask *)((func_800BBEAC(f) << 5) + (s32)b);
    p->unk1C = 0;
}

INCLUDE_RODATA("../asm/us/magic_wpyu/nonmatchings/text", D_801B0000);

void func_801B25A8(arg0, arg1) {
    s32 i;
    s32 n;

    D_801D3BB8 = &D_80162978[func_800BBEAC(&D_801B0000)];
    D_801D3BC0 = arg0;
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D3BC4 = i;
            }
        }
    }
    D_801D3BC8 = arg1;
    func_800BBEAC(&func_801B23C8);
}
