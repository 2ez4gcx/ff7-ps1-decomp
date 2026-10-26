#include "common.h"
#include "magic_break/decls.h"

void func_801B0000(void) {
    MgTask *p;
    MgMat *m;
    s16 *u;
    MgVec *s;
    s32 a;
    s32 b;
    s32 t;

    p = &D_80162978[D_8015169C];
    a = (p->unk2 * 0x350 / 25 + 0x100) * p->unkC >> 12;
    D_1F800028 = a;
    s = (MgVec *)0x1F800020;
    s->vx = a;
    u = &p->unk2;
    b = *u * 0x380 / 25 * p->unkC >> 12;
    D_1F800024 = b;
    m = (MgMat *)0x1F800000;
    if (a > 0x7FFF) {
        D_1F800028 = 0x7FFF;
    }
    if (b > 0x7FFF) {
        D_1F800024 = 0x7FFF;
    }
    t = p->unk2;
    if (t < 0xF) {
        D_801CD2C2 = 0x80;
    } else {
        t -= 0xF;
        if (t < 0xA) {
            D_801CD2C2 = -(t << 7) / 10 + 0x80;
        } else {
            p->unk0 = -1;
            return;
        }
    }
    func_8003C21C(&D_801CD2B0, m);
    m->t[0] = p->unk4;
    m->t[1] = p->unk6;
    m->t[2] = p->unk8;
    func_8003B35C(m, s);
    func_8003A63C(&D_800FA63C, m, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801ED328 = func_800D29D4(D_801CD2B8, D_801517C0 + 0x70, 0xC, D_801ED328);
    if (D_80062D98 == 0) {
        D_801CD2B0.vy -= 0xC0;
        p->unk2++;
    }
}

void func_801B024C(void) {
    MgTask *p;
    MgMat *m;
    MgVec *s;
    s32 v;
    s32 t;

    s = (MgVec *)0x1F800020;
    p = &D_80162978[D_8015169C];
    t = p->unk2;
    m = (MgMat *)0x1F800000;
    if (t < 5) {
        D_801CD2CC = 0x88;
        D_801CD2D2 = -(t << 12) / 5 + 0x1000;
    } else {
        t -= 5;
        if (t < 0xF) {
            D_801CD2CC = 0x80;
            D_801CD2D2 = 0;
        } else {
            t -= 0xF;
            if (t < 0xA) {
                D_801CD2CC = 0x88;
                D_801CD2D2 = (t << 12) / 10;
            } else {
                p->unk0 = -1;
                return;
            }
        }
    }
    v = p->unkC * 3 >> 4;
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    s->vx = s->vy = s->vz = v;
    D_801CD2D8.t[0] = p->unk4;
    D_801CD2D8.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &D_801CD2D8, m);
    func_8003B35C(m, s);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801ED328 = func_800D29D4(D_801CD2C8, D_801517C0 + 0x70, 0xC, D_801ED328);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B0440(void) {
    MgTask *p;
    MgMat *m;
    s32 v;
    s32 t;

    p = &D_80162978[D_8015169C];
    v = (p->unk2 * 0x1100 / 20 + 0x400) * p->unkC >> 12;
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    D_801CD2F8.m[0][0] = D_801CD2F8.m[2][2] = v;
    D_801CD2F8.t[0] = p->unk4;
    D_801CD2F8.t[2] = p->unk8;
    m = (MgMat *)0x1F800000;
    t = p->unk2;
    if (t < 0) {
        D_801CD322 = 0;
    } else if (t < 0x14) {
        D_801CD322 = (t << 12) / 20;
    } else {
        p->unk0 = -1;
        return;
    }
    func_8003B69C(0, 0, 0);
    func_8003A63C(&D_800FA63C, &D_801CD2F8, m);
    func_8003B48C(m);
    func_8003B51C(m);
    D_801ED328 = func_800D29D4(D_801CD318, D_801517C0 + 0x70, 0xC, D_801ED328);
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B05E0(void) {
    MgTask *q;
    MgTask *p;
    MgTask *r;
    s32 t;
    s32 u;

    q = D_80162978;
    p = &q[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            r = &q[func_800BBEAC(&func_801B0000)];
            r->unk4 = p->unk4;
            r->unk6 = 0;
            r->unk8 = p->unk8;
            r->unkC = p->unkC;
        }
        if (p->unk2 == 0xF) {
            r = &q[func_800BBEAC(&func_801B024C)];
            r->unk4 = p->unk4;
            r->unk6 = 0;
            r->unk8 = p->unk8;
            r->unkC = p->unkC;
        }
        t = p->unk2;
        if (t == 0x14) {
            r = &q[func_800BBEAC(&func_801B0440)];
            r->unk4 = p->unk4;
            r->unk6 = 0;
            r->unk8 = p->unk8;
            r->unkC = p->unkC;
            u = p->unk2;
            if (u == t) {
                func_800D5774(p->unk0);
                if (p->unk2 == u) {
                    p->unk0 = -1;
                }
            }
        }
        p->unk2++;
    }
}

void func_801B0758(s32 arg0) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B05E0)];
    p->unk0 = arg0;
    p->unkC = func_800D55A4(arg0) / 2;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B07F4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ED328 = D_801CD328 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0854(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B08DC, 0, 0, 0);
    func_800BBEAC(&func_801B07F4);
    func_800D5444(arg0, arg1, 0, &func_801B0758);
    func_800D55F4(0x20, func_800D574C(arg0), 0x55);
}
