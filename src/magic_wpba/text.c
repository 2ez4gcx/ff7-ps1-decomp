#include "common.h"
#include "magic_wpba/decls.h"

void func_801B0054(void) {
    D_801D3678 = &D_801B158C;
    D_801D367C = 0;
    func_801B14D8();
}

void func_801B008C(void) {
    D_801D3678 = &D_801B21BC;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B00C8(void) {
    D_801D3678 = &D_801B2BD8;
    D_801D367C = 0;
    func_801B14D8();
}

void func_801B0100(void) {
    D_801D3678 = &D_801B36EC;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B013C(void) {
    D_801D3678 = &D_801B3FF0;
    D_801D367C = 0;
    func_801B14D8();
}

void func_801B0174(void) {
    D_801D3678 = &D_801B4B54;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B01B0(void) {
    D_801D3678 = &D_801B5710;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B01EC(void) {
    D_801D3678 = &D_801B6444;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B0228(void) {
    D_801D3678 = &D_801B6E88;
    D_801D367C = 0;
    func_801B14D8();
}

void func_801B0260(void) {
    D_801D3678 = &D_801B78AC;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B029C(void) {
    D_801D3678 = &D_801B8280;
    D_801D367C = 0;
    func_801B14D8();
}

void func_801B02D4(void) {
    D_801D3678 = &D_801B8B04;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B0310(void) {
    D_801D3678 = &D_801B9540;
    D_801D367C = 0;
    func_801B14D8();
}

void func_801B0348(void) {
    D_801D3678 = &D_801B9E94;
    D_801D367C = 1;
    func_801B14D8();
}

void func_801B0384(void) {
    D_801D3678 = &D_801BA9A0;
    D_801D367C = 1;
    func_801B14D8();
}

s32 func_801B03C0(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B049C(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0618(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B06F4(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B07D8(void) {
    MgSVec rot;
    MgMat m;
    MgMat n;
    MgVec v;
    MgVec w;
    MgTask *p;
    s32 k;
    s32 c;
    s32 x;
    s32 y;
    s32 z;
    s32 u;

    p = &D_80162978[D_8015169C];
    if (p->unk2 < 0xC) {
        c = func_801B03C0(&D_801D3658, &D_801D3668, &w) / 190 + 1;
        k = (-(func_80039A74(p->unkA) * 400) >> 12) * c;
    } else {
        k = p->unkA;
    }
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    x = p->unk4;
    m.t[0] = x;
    y = p->unk6 + k;
    m.t[1] = y;
    z = p->unk8;
    v.vx = x - D_801D3680.v;
    m.t[2] = z;
    v.vy = y - D_801D3682;
    v.vz = z - D_801D3684;
    func_8003A08C(&v, &v);
    func_801B049C(func_801B03C0(&D_801BB624, &v, &w), &n, &w);
    func_8003B16C(&n, &m);
    if (D_80062D98 == 0) {
        D_801D3680.v = m.t[0];
        D_801D3682 = m.t[1];
        D_801D3684 = m.t[2];
    }
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    v.vx = 0;
    v.vy = 0;
    v.vz = 0x50;
    func_8003AB84(&m, &v, &v);
    m.t[0] += v.vx;
    m.t[1] += v.vy;
    m.t[2] += v.vz;
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801D3678;
    if (p->unk2 >= 0x18) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        u = p->unk2;
        ((MgScratch *)0x1F800000)->unkA = (u - 0x18) * 0x2AA;
    }
    func_8003B69C(0, 0, 0);
    D_801D3634 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D3634);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        if (p->unk2 == 0xC) {
            p->unkA = 0;
            p->unk12 = -(func_80042DA8() % 30 + 0x3C);
        }
        p->unk2++;
    }
}

void func_801B0BA0(void) {
    MgSVec rot;
    MgMat m;
    MgMat unused;
    MgVec v;
    MgVec w;
    MgTask *p;
    s32 k;
    s32 c;

    p = &D_80162978[D_8015169C];
    c = func_801B03C0(&D_801D3658, &D_801D3668, &w) / 190 + 1;
    k = (-(func_80039A74(p->unkA) * 600) >> 12) * c;
    rot.vx = p->unk14;
    rot.vy = 0;
    rot.vz = p->unk18;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6 + k;
    m.t[2] = p->unk8;
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    v.vx = 0;
    v.vy = 0;
    v.vz = 0x50;
    func_8003AB84(&m, &v, &v);
    m.t[0] += v.vx;
    m.t[1] += v.vy;
    m.t[2] += v.vz;
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801D3678;
    if (p->unk2 >= 0x18) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        ((MgScratch *)0x1F800000)->unkA = (p->unk2 - 0x18) * 0x2AA;
    }
    func_8003B69C(0, 0, 0);
    D_801D3634 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801D3634);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        p->unkA += p->unk12;
        if (p->unk2 == 0x12) {
            p->unkA = 0;
        }
        p->unk14 += p->unk16;
        p->unk18 += p->unk1A;
        p->unk2++;
    }
}

void func_801B0E6C(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    MgSVec *f;
    MgVec *e;
    s32 n;
    u8 pad[16];

    b = D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            e = &D_801D3668;
            f = &D_801D3650;
            e->vx = D_801D3648.vx - f->vx;
            D_801D366C = D_801D364A.v - D_801D3652.v;
            D_801D3670 = D_801D364C.v - D_801D3654.v;
            n = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(e, e)) / 12;
            q = &b[func_800BBEAC((M2C_UNK *)func_801B07D8)];
            *(MgSVec *)&q->unk4 = *f;
            *(s16 *)((u8 *)q + 0xC) = n * e->vx >> 12;
            *(s16 *)((u8 *)q + 0xE) = n * D_801D366C >> 12;
            *(s16 *)((u8 *)q + 0x10) = n * D_801D3670 >> 12;
            q->unkA = q->unk12 = 0xAA;
            D_801D3680.v = q->unk4 - q->unkC;
            D_801D3682 = q->unk6 - q->unkE;
            do {
                D_801D3684 = q->unk8 - q->unk10;
            } while (0);
        }
        if (p->unk2 == 0xD) {
            func_800D5774(D_801D3640);
            func_800D55F4(0x20, func_800D56A8(&D_801D3648), 0x1E4);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B10B0(void) {
    MgTask *b;
    MgTask *p;
    MgTask *q;
    MgSVec *f;
    MgVec *e;
    s32 n;
    u8 pad[16];

    b = D_80162978;
    p = &b[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            e = &D_801D3668;
            f = &D_801D3650;
            e->vx = D_801D3648.vx - f->vx;
            D_801D366C = D_801D364A.v - D_801D3652.v;
            D_801D3670 = D_801D364C.v - D_801D3654.v;
            n = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(e, e)) / 18;
            q = &b[func_800BBEAC(&func_801B0BA0)];
            *(MgSVec *)&q->unk4 = *f;
            *(s16 *)((u8 *)q + 0xC) = n * e->vx >> 12;
            *(s16 *)((u8 *)q + 0xE) = n * D_801D366C >> 12;
            *(s16 *)((u8 *)q + 0x10) = n * D_801D3670 >> 12;
            q->unkA = q->unk12 = 0x71;
            q->unk14 = q->unk16 = func_80042DA8() % 200 + 0xB4;
            q->unk18 = q->unk1A = func_80042DA8() % 150 + 0xA0;
        }
        if (p->unk2 == 0x12) {
            func_800D5774(D_801D3640);
            func_800D55F4(0x20, func_800D56A8(&D_801D3648), 0x1E4);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B133C(void) {
    MgSVec rot;
    MgMat m;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    p->unk0 = -1;
    func_800D3994(D_801D3640, D_8015190F[D_801D3640][0], &D_801D3648);
    func_800D3994(D_801D3644, D_8015190F[D_801D3644][0], &D_801D3650);
    rot.vy = D_801D3650.pad = *(u16 *)D_80151A46[D_801D3644];
    rot.vx = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801BB624, &D_801D3658);
    switch (D_801D367C) {
    case 0:
        p = &D_80162978[func_800BBEAC((void *)func_801B0E6C)];
        p->unk1C = 0;
        break;
    case 1:
        p = &D_80162978[func_800BBEAC((void *)func_801B10B0)];
        p->unk1C = 0;
        break;
    default:
        p->unk1C = 0;
        break;
    }
}

INCLUDE_RODATA("../asm/us/magic_wpba/nonmatchings/text", D_801B0000);

void func_801B14D8(arg0, arg1) {
    s32 i;
    s32 n;

    D_801D3638 = &D_80162978[func_800BBEAC(&D_801B0000)];
    D_801D363C = arg0;
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801D3640 = i;
            }
        }
    }
    D_801D3644 = arg1;
    func_800BBEAC(&func_801B133C);
}
