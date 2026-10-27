#include "common.h"
#include "magic_barrier/decls.h"

void func_801B0000(void) {
    func_801B0AF0();
}

void func_801B0020(void) {
    MgTask *p;
    MgMat *m;
    MgVec *s;
    s32 a;
    s32 v;
    s16 k;
    u16 f;
    MgWord *w;

    s = (MgVec *)0x1F800020;
    p = (MgTask *)&D_80162978[D_8015169C];
    m = (MgMat *)0x1F800000;
    a = p->unk2 + p->unk0 - 0x11;
    if (a < 0) {
        v = D_801B0CC0 * 0xC00 >> 12;
        D_1F800028.v = v;
        D_1F800024.v = v;
        s->vx = v;
        f = p->unk18;
        k = 0;
    } else {
        if (a >= 8) {
            p->unk0 = -1;
            return;
        }
        k = a << 9;
        f = p->unk18 | 8;
        v = (a * 0x180 + 0xC00) * D_801B0CC0 >> 12;
        D_1F800028.v = v;
        D_1F800024.v = v;
        s->vx = v;
    }
    func_8003B69C(0, 0, 0);
    func_8003C21C((MgSVec *)&p->unk10, m);
    func_8003B35C(m, s);
    func_8003B27C(m, D_801B0C90, (MgVec *)m->t);
    m->t[0] += p->unk8;
    m->t[1] += p->unkA;
    m->t[2] += p->unkC;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    w = (MgWord *)&D_801B0C9C;
    w->v = f | 0x80;
    D_801B0CA2 = k;
    D_801D0CC4 = func_800D29D4((u8 *)w - 4, D_801517C0 + 0x70, 0xC, D_801D0CC4);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0220(void) {
    MgTask *p;
    MgMat *m;
    MgMat *m2;
    MgVec *s;
    MgVec *s2;
    s32 a;
    s32 v;
    s32 t;
    s16 k;
    u16 f;
    MgWord *w;

    m2 = (MgMat *)0x1F800020;
    s = (MgVec *)0x1F800040;
    s2 = (MgVec *)0x1F800050;
    p = (MgTask *)&D_80162978[D_8015169C];
    t = p->unk2;
    m = (MgMat *)0x1F800000;
    a = t + p->unk0 - 0x11;
    if (a < 0) {
        if (t < 6) {
            v = t * (D_801B0CC0 << 9) >> 12;
        } else {
            v = D_801B0CC0 * 0xC00 >> 12;
        }
        D_1F800048.v = v;
        D_1F800044.v = v;
        s->vx = v;
        do { v = D_801B0CC0 * 0xC00 >> 12; } while (0);
        s2->vz = v;
        s2->vy = v;
        s2->vx = v;
        f = p->unk18;
        k = 0;
    } else {
        if (a >= 8) {
            p->unk0 = -1;
            return;
        }
        k = a << 9;
        f = p->unk18 | 8;
        v = (a * 0x180 + 0xC00) * D_801B0CC0 >> 12;
        D_1F800058.v = v;
        D_1F800054.v = v;
        s2->vx = v;
        D_1F800048.v = v;
        D_1F800044.v = v;
        s->vx = v;
    }
    func_8003B69C(0, 0, 0);
    func_8003C21C((MgSVec *)&p->unk10, m);
    *m2 = *m;
    func_8003B35C(m, s);
    func_8003B35C(m2, s2);
    func_8003B27C(m2, D_801B0CA8, (MgVec *)m->t);
    m->t[0] += p->unk8;
    m->t[1] += p->unkA;
    m->t[2] += p->unkC;
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    w = (MgWord *)&D_801B0CB4;
    w->v = f | 0x80;
    D_801B0CBA = k;
    D_801D0CC4 = func_800D29D4((u8 *)w - 4, D_801517C0 + 0x70, 0xC, D_801D0CC4);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B04F4(void) {
    MgTask *base;
    MgTask *p;
    MgTask *q;

    base = (MgTask *)D_80162978;
    p = base + D_8015169C;
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            q = base + func_800BBEAC(func_801B0020);
            q->unk0 = p->unk2;
            q->unk18 = 0;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 2) {
            q = base + func_800BBEAC(func_801B0020);
            q->unk0 = p->unk2;
            q->unk18 = 1;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 4) {
            q = base + func_800BBEAC(func_801B0020);
            q->unk0 = p->unk2;
            q->unk18 = 3;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 6) {
            q = base + func_800BBEAC(func_801B0020);
            q->unk0 = p->unk2;
            q->unk18 = 2;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 1) {
            q = base + func_800BBEAC(func_801B0220);
            q->unk0 = p->unk2;
            q->unk18 = 0;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 3) {
            q = base + func_800BBEAC(func_801B0220);
            q->unk0 = p->unk2;
            q->unk18 = 1;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 5) {
            q = base + func_800BBEAC(func_801B0220);
            q->unk0 = p->unk2;
            q->unk18 = 3;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 7) {
            q = base + func_800BBEAC(func_801B0220);
            q->unk0 = p->unk2;
            q->unk18 = 2;
            *(MgSVec *)&q->unk10 = *(MgSVec *)&p->unk10;
            *(MgSVec *)&q->unk8 = *(MgSVec *)&p->unk8;
        }
        if (p->unk2 == 0x11) {
            func_800D5774(p->unk4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B092C(arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(func_801B04F4)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
    p->unk8 -= (func_80039A74(D_80151A46[arg0][0]) * D_801518F6[arg0][0]) >> 12;
    p->unkC -= (func_80039B40(D_80151A46[arg0][0]) * D_801518F6[arg0][0]) >> 12;
    *(MgSVec *)&p->unk10 = *(MgSVec *)D_80151A44[arg0];
    p->unk4 = arg0;
}

void func_801B0A90(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0CC4 = D_801B0CC4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B0AF0(arg0, arg1) {
    D_801B0CC0 = 0x3000;
    func_800BBEAC(func_801B0A90);
    func_800D5444(arg0, arg1, 4, &func_801B092C);
    return func_800D55F4(0x20, func_800D574C(arg0), 0x5E);
}
