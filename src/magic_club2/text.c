#include "common.h"
#include "magic_club2/decls.h"

void func_801B0054(void) {
    func_801B2DF4();
}

s32 func_801B0074(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0150(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02CC(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03A8(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B048C(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec ofs;
    MgMat m1;
    MgMat m2;
    MgVec scale;
    MgTask *p;
    s32 ang;

    p = &D_80162978[D_8015169C];
    ang = 0x400;
    if (p->unk2 < 9) {
        ang = p->unk2 << 7;
    }
    rot2.vx = 0;
    rot2.vz = 0;
    rot2.vy = D_801F0826;
    func_8003BF8C(&rot2, &m1);
    func_801B0150(-ang, &m2, &D_801D87D8);
    func_8003B16C(&m1, &m2);
    ofs.vx = 0;
    ofs.vy = p->unkA;
    ofs.vz = 0;
    func_8003B2CC(&m2, &ofs, &ofs);
    rot1.vx = 0;
    rot1.vy = 0;
    rot1.vz = 0x800;
    func_8003BF8C(&rot1, &m1);
    func_8003B16C(&m2, &m1);
    m1.t[0] = p->unk4 + ofs.vx;
    m1.t[1] = p->unk6 + ofs.vy;
    m1.t[2] = p->unk8 + ofs.vz;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m1, &scale);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk0 = &D_801D2BE0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801F080C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x12) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 >= 8) {
            p->unk6 += p->unkE;
            p->unkE += p->unkE / 6;
        }
        p->unk2++;
    }
}

void func_801B06E0(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec pad1;
    MgMat m1;
    MgMat m2;
    MgVec pad2;
    MgTask *p;

    rot1.vx = 0x400;
    rot1.vy = 0;
    rot1.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot1, &m1);
    m1.t[0] = 0;
    m1.t[1] = p->unk6 - 0x28;
    m1.t[2] = 0x380;
    rot2.vx = 0;
    rot2.vy = p->unk14;
    rot2.vz = 0;
    func_8003BF8C(&rot2, &m2);
    func_8003B16C(&m2, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk0 = &D_801D2BE0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801F080C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x30) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 8) {
            p->unk6 += p->unkE;
            p->unkE -= p->unkE >> 5;
            if (p->unkE < 2) {
                p->unkE = 1;
            }
        } else if (p->unk2 < 0x28) {
            p->unk6 = (u32)(func_80039A74((p->unk2 - 8) << 7) * 3) >> 9;
            if (p->unk2 >= 0x16 && p->unk2 < 0x22) {
                p->unk14 -= 0xAA;
            }
        } else {
            p->unk6 += p->unkE;
            p->unkE += p->unkE >> 2;
        }
        p->unk2++;
    }
}

void func_801B08F8(void) {
    MgSVec rot1;
    MgSVec rot2;
    MgSVec rot3;
    MgMat m1;
    MgMat m2;
    MgVec v;
    MgTask *p;
    s32 n;

    rot1.vx = 0;
    p = &D_80162978[D_8015169C];
    rot1.vy = p->unk14;
    rot1.vz = 0x800;
    func_8003BF8C(&rot1, &m1);
    m1.t[0] = p->unk4;
    m1.t[1] = p->unk6;
    m1.t[2] = p->unk8;
    v.vx = v.vy = v.vz = p->unk18;
    func_8003B35C(&m1, &v);
    func_8003A63C(&D_800FA63C, &m1, &m1);
    func_8003B48C(&m1);
    func_8003B51C(&m1);
    ((MgScratch *)0x1F800000)->unk0 = &D_801D2BE0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0xC) {
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0xC) * 0x10;
    }
    D_801F080C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xA) {
            n = func_800D56A8(&p->unk4);
            if (n > 0x40) {
                func_800D4D4C(D_801F0818, 0x118);
            } else {
                func_800D4D4C(D_801F0818, 0x18);
            }
            func_800D55F4(0x20, n, 0x1D8);
        }
        p->unk4 += p->unkC;
        p->unk8 += p->unk10;
        p->unkC += p->unkC >> 4;
        p->unk10 += p->unk10 >> 4;
        p->unk2++;
    }
}

void func_801B0B30(void) {
    MgSVec unused;
    MgMat m;
    MgVec v;
    MgVec axis;
    MgTask *p;
    MgTask *q;
    s32 d;
    s32 ang;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 2) {
            q = &D_80162978[func_800BBEAC(&func_801B048C)];
            *(MgSVec *)&q->unk4 = D_801F0820;
            d = *(s16 *)D_80151A4E[D_801F081C] - D_801F0820.vy;
            if (d < 0) {
                d = -d;
            }
            q->unkE = -0x12C;
            q->unkA = d;
            q->unk18 = 0x2000;
            func_800D55F4(0x20, func_800D56A8(&D_801F0820), 0x1D5);
        }
        if (p->unk2 == 0x18) {
            q = &D_80162978[func_800BBEAC(&func_801B06E0)];
            q->unk6 = -0x10A;
            q->unkE = 0x21;
            q->unk14 = 0;
            func_800D55F4(0x20, 0x40, 0x1D6);
        }
        if (p->unk2 == 0x48) {
            func_800D3994(D_801F0818, D_8015190F[D_801F0818][0], &p->unk4);
            v.vx = p->unk4 - D_80158D00[0];
            v.vy = 0;
            v.vz = p->unk8 - D_80158D00[2];
            d = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(&v, &v)) / 12;
            ang = func_801B0074(&D_801D87C8, &v, &axis);
            func_801B0150(ang, &m, &axis);
            func_8003AB84(&m, &D_801D87C8, &v);
            if (axis.vy < 0) {
                ang = -ang;
            }
            q = &D_80162978[func_800BBEAC(&func_801B08F8)];
            q->unk4 = D_80158D00[0];
            q->unk6 = p->unk6;
            q->unk8 = D_80158D00[2];
            q->unkC = (d * v.vx) >> 12;
            q->unkE = 0;
            q->unk10 = (d * v.vz) >> 12;
            q->unk14 = ang;
            q->unk18 = 0x2666;
            func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x1D7);
        }
        if (p->unk2 >= 0x5A) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0E9C(void) {
    MgSVec rot;
    MgMat m;

    func_800D3994(D_801F081C, D_80151919[D_801F081C][0], &D_801F0820);
    D_801F0820.vy -= 0xE0;
    rot.vy = D_801F0820.pad = *(u16 *)D_80151A46[D_801F081C];
    rot.vx = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801D87C8, &D_801F0848);
    func_8003AB84(&m, &D_801D87D8, &D_801F0858);
}

void func_801B0F9C(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk14;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vz = p->unk1C;
    scale.vy = p->unk1E;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D2E8C;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80 - p->unk2 * 0xC;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801F080C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0xA) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk16 -= p->unk16 >> 3;
        p->unk2++;
        p->unk1C += p->unk1C >> 3;
        p->unk1E -= p->unk1E >> 3;
    }
}

void func_801B1164(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgTask *q;
    s32 r2;
    s32 k;
    void *w;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = p->unk18;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk1C;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    w = D_801D8768[p->unk12];
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = w;
    D_801F080C = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= p->unkA + 4 || p->unk6 >= -0x78) {
        q = &D_80162978[func_800BBEAC(func_801B0F9C)];
        *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
        q->unk6 = 0;
        q->unk14 = p->unk14;
        q->unk16 = func_80042DA8() % 0x44 + 0x4E;
        r2 = func_80042DA8();
        k = (u16)p->unk1C + 0x100;
        q->unk1C = k + r2 % 0x200;
        q->unk1E = (u16)p->unk1C << 1;
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkC -= p->unkC >> 6;
        p->unkE -= p->unkE >> 6;
        p->unk10 -= p->unk10 >> 6;
        p->unk2++;
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk1C += p->unk1E;
        p->unk1E += p->unk1E >> 6;
    }
}

void func_801B1468(void) {
    MgSVec rot;
    MgMat m;
    MgMat m2;
    MgVec scale;
    MgVec d;
    MgVec axis;
    MgTask *p;
    s32 len;
    u8 c;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B16C(&D_801F0828, &m);
    d.vx = p->unkC - p->unk4;
    d.vy = p->unkE - p->unk6;
    d.vz = p->unk10 - p->unk8;
    len = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(&d, &d));
    func_801B0150(func_801B0074(&D_801D87A8, &d, &axis), &m2, &axis);
    func_8003B16C(&m2, &m);
    scale.vx = scale.vz = 0x2000;
    scale.vy = (len << 12) / 1920;
    if (scale.vy > 0x7FFF) {
        scale.vy = 0x7FFF;
    }
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    if (p->unk2 < 0xC) {
        D_801D87F0 = p->unk2;
    } else {
        D_801D87F0 = (p->unk2 - 0xC) % 4 + 0xC;
    }
    if (p->unk2 >= 0x24) {
        c = -0x80 - (p->unk2 - 0x24) * 10;
    } else {
        c = 0x80;
    }
    D_801D87EC[0] = D_801D87EC[1] = D_801D87EC[2] = c;
    D_801F080C = func_800D4D90(D_801D87EC - 4, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x30) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B16F8(void) {
    MgSVec rot;
    MgMat m;
    MgMat m2;
    MgVec scale;
    MgVec d;
    MgVec axis;
    MgTask *p;
    s32 len;
    u8 c;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_8003B16C(&D_801F0828, &m);
    d.vx = p->unkC - p->unk4;
    d.vy = p->unkE - p->unk6;
    d.vz = p->unk10 - p->unk8;
    len = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(&d, &d));
    func_801B0150(func_801B0074(&D_801D87A8, &d, &axis), &m2, &axis);
    func_8003B16C(&m2, &m);
    scale.vx = scale.vz = 0x2000;
    scale.vy = (len << 12) / 1920;
    if (scale.vy > 0x7FFF) {
        scale.vy = 0x7FFF;
    }
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    if (p->unk2 < 4) {
        D_801D87FC = p->unk2;
    } else {
        D_801D87FC = (p->unk2 - 4) % 4 + 4;
    }
    if (p->unk2 >= 0x24) {
        c = -0x80 - (p->unk2 - 0x24) * 10;
    } else {
        c = 0x80;
    }
    D_801D87F8[0] = D_801D87F8[1] = D_801D87F8[2] = c;
    D_801F080C = func_800D4D90(D_801D87F8 - 4, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x30) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1988(void) {
    MgTask *p;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801D8808;
    *frame = p->unk2;
    t = p->unk1C;
    func_800D4368((MgSVec *)&p->unk4, t, -(t >> 4));
    D_801F080C = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 3) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

void func_801B1A54(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgScratch *sc;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = p->unk18;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk1C;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    sc = (MgScratch *)0x1F800000;
    sc->unk0 = D_801D3CD8;
    ((MgScratch *)0x1F800000)->unk4 = 0xA8;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2;
    if (t < 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x1000 - (t << 9);
    } else if (t >= 0x2E) {
        ((MgScratch *)0x1F800000)->unkA = (t - 0x2E) << 9;
    } else {
        ((MgScratch *)0x1F800000)->unkA = 0;
    }
    func_8003B69C(0, 0, 0);
    D_801F080C = func_800D29D4(sc, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x36) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

void func_801B1C2C(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgScratch *sc;
    void *w;
    s32 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = p->unk18;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk1C;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    w = D_801D8780[(s16)(p->unk2 % 10)];
    sc = (MgScratch *)0x1F800000;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    sc->unk0 = w;
    t = p->unk2;
    if (t < 8) {
        ((MgScratch *)0x1F800000)->unkA = t * 0x18;
    } else if (t >= 0x2E) {
        ((MgScratch *)0x1F800000)->unkA = 0xC0 - (t - 0x2E) * 0x18;
    } else {
        ((MgScratch *)0x1F800000)->unkA = 0xC0;
    }
    D_801F080C = func_800D29D4(sc, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x36) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

void func_801B1E38(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;
    MgScratch *sc;
    s16 t;

    p = &D_80162978[D_8015169C];
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = p->unk18;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk1C;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    sc = (MgScratch *)0x1F800000;
    sc->unk0 = D_801D2FD0;
    ((MgScratch *)0x1F800000)->unk4 = 0x28;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    t = p->unk2 % 6;
    if (t < 3) {
        ((MgScratch *)0x1F800000)->unkA = t * 0x2A;
    } else {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (t - 3) * 0x2A;
    }
    D_801F080C = func_800D29D4(sc, D_801517C0 + 0x70, 0xC, D_801F080C);
    if (p->unk2 >= 0x36) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_club2/nonmatchings/text", func_801B2040);

void func_801B2AA8(arg0, arg1) {
    MgTask *p;
    u8 pad[8];
    s32 v;

    p = &D_80162978[func_800BBEAC(&func_801B2040)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    v = *(s16 *)D_801518F6[arg0] + 0x2A0;
    if (v >= 0x76D) {
        v = 0x76C;
    }
    p->unk1C = v;
    func_800D3994(arg1, D_80151919[arg1][0], &D_801F0820);
    D_801F0820.vy -= 0x1F8;
    func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x1D9);
}

void func_801B2BD8(void) {
    MgTask *p;
    s32 v;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x5A) {
            func_801B2AA8(D_801F0818, D_801F081C);
        }
        if (p->unk2 < 0x4E) {
            v = 0;
        } else if (p->unk2 < 0x5A) {
            D_800F5B70[0] = D_800F5B70[1] = D_800F5B70[2] = 0;
            v = (p->unk2 - 0x4E) * 0x155;
        } else if (p->unk2 >= 0x8E) {
            v = 0x1000 - ((p->unk2 - 0x8E) << 9);
        } else {
            v = 0x1000;
        }
        if (p->unk2 >= 0x96) {
            v = 0;
            p->unk0 = -1;
        }
        D_800F5B74[0] = v;
        p->unk2++;
    }
}

void func_801B2CF8(void) {
    MgSVec pos;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    p->unk0 = -1;
    func_800D3994(D_801F0818, D_8015190F[D_801F0818][0], &pos);
    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0B30)];
    p->unk4 = pos;
    func_801B0E9C();
    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B2BD8)];
    p->unk4 = pos;
}

INCLUDE_RODATA("../asm/us/magic_club2/nonmatchings/text", D_801B0000);

void func_801B2DF4(mask, arg1) {
    s32 i;
    s32 n;

    D_801F0810 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B2EC0, 0, 0, 0);
    D_801F0814 = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801F0818 = i;
            }
        }
    }
    D_801F081C = arg1;
    func_800BBEAC(&func_801B2CF8);
}
