#include "common.h"
#include "magic_wpea/decls.h"

void func_801B0054(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B1438;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B00C0(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B19FC;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B012C(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B2310;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B0198(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B2A74;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B0204(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B3308;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B0270(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B3C04;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B02DC(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B4458;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B0348(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B4E1C;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B03B4(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B58CC;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B0420(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B6310;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

void func_801B048C(s32 arg0, M2C_UNK arg1) {
    D_801CF914 = &D_801B6D8C;
    D_801CF918 = func_80042DA8() % 2;
    func_801B1384(arg0, arg1);
}

s32 func_801B04F8(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B05D4(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B0750(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B082C(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B0910(void) {
    MgSVec rot;
    MgMat m;
    MgMat r;
    MgVec off;
    MgVec axis;
    MgTask *p;
    s32 t;

    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    p = &D_80162978[D_8015169C];
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_801B05D4(func_801B04F8(&D_801B78C0, &D_801CF904, &axis), &r, &axis);
    func_8003B16C(&r, &m);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    off.vx = 0;
    off.vy = 0;
    off.vz = 0x17C;
    func_8003AB84(&m, &off, &off);
    m.t[0] += off.vx;
    m.t[1] += off.vy;
    m.t[2] += off.vz;
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801CF914;
    if (p->unk2 >= 0x16) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        t = p->unk2 - 0x16;
        ((MgScratch *)0x1F800000)->unkA = t << 9;
    }
    func_8003B69C(0, 0, 0);
    D_801CF8D0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801CF8D0);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 6) {
            p->unk4 += p->unkC;
            p->unk6 += p->unkE;
            p->unk8 += p->unk10;
        }
        p->unk2++;
    }
}

void func_801B0B68(void) {
    MgSVec rot;
    MgMat m;
    MgMat r;
    MgVec off;
    MgVec axis;
    MgTask *p;
    s32 t;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unk14;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    func_801B05D4(func_801B04F8(&D_801B78C0, &D_801CF904, &axis), &r, &axis);
    func_8003B16C(&r, &m);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    off.vx = 0;
    off.vy = 0;
    off.vz = 0;
    func_8003AB84(&m, &off, &off);
    m.t[0] += off.vx;
    m.t[1] += off.vy;
    m.t[2] += off.vz;
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk4 = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkA = 0;
    ((MgScratch *)0x1F800000)->unkC = 0;
    ((MgScratch *)0x1F800000)->unkE = 0;
    ((MgScratch *)0x1F800000)->unk0 = D_801CF914;
    if (p->unk2 >= 6) {
        ((MgScratch *)0x1F800000)->unk4 = 0x88;
        t = p->unk2 - 6;
        ((MgScratch *)0x1F800000)->unkA = t * 0xAA;
    }
    func_8003B69C(0, 0, 0);
    D_801CF8D0 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801CF8D0);
    if (p->unk2 >= 0x1E) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unkC;
        p->unk6 += p->unkE;
        p->unk8 += p->unk10;
        if (p->unk2 >= 5) {
            p->unk6 += p->unkA;
            p->unkA += p->unkA >> 1;
        }
        p->unk14 += p->unk16;
        p->unk2++;
    }
}

void func_801B0DF8(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    u8 pad[16];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801CF904.vx = D_801CF8E4.vx - D_801CF8EC.vx;
            D_801CF904.vy = D_801CF8E4.vy - D_801CF8EC.vy;
            D_801CF904.vz = D_801CF8E4.vz - D_801CF8EC.vz;
            n = func_80039F5C(func_8003A08C(&D_801CF904, &D_801CF904)) / 6;
            q = &D_80162978[func_800BBEAC(&func_801B0910)];
            *(MgSVec *)&q->unk4 = D_801CF8EC;
            q->unkC = (n * D_801CF904.vx) >> 12;
            q->unkE = (n * D_801CF904.vy) >> 12;
            q->unk10 = (n * D_801CF904.vz) >> 12;
        }
        if (p->unk2 == 6) {
            func_800D5774(D_801CF8DC);
            func_800D55F4(0x20, func_800D56A8(&D_801CF8E4), 0x32);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B0FE4(void) {
    MgTask *p;
    MgTask *q;
    s32 n;
    u8 pad[16];

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 0) {
            D_801CF904.vx = D_801CF8E4.vx - D_801CF8EC.vx;
            D_801CF904.vy = D_801CF8E4.vy - D_801CF8EC.vy;
            D_801CF904.vz = D_801CF8E4.vz - D_801CF8EC.vz;
            n = func_80039F5C(func_8003A08C(&D_801CF904, &D_801CF904)) / 5;
            q = &D_80162978[func_800BBEAC(&func_801B0B68)];
            *(MgSVec *)&q->unk4 = D_801CF8EC;
            q->unkA = -0xC;
            q->unkC = (n * D_801CF904.vx) >> 12;
            q->unkE = (n * D_801CF904.vy) >> 12;
            q->unk10 = (n * D_801CF904.vz) >> 12;
            q->unk14 = 0;
            q->unk16 = 0x320;
        }
        if (p->unk2 == 5) {
            func_800D5774(D_801CF8DC);
            func_800D55F4(0x20, func_800D56A8(&D_801CF8E4), 0x32);
        }
        if (p->unk2 >= 0x1E) {
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B11E8(void) {
    MgSVec rot;
    MgMat m;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    p->unk0 = -1;
    func_800D3994(D_801CF8DC, D_8015190F[D_801CF8DC][0], &D_801CF8E4);
    func_800D3994(D_801CF8E0, D_8015190F[D_801CF8E0][0], &D_801CF8EC);
    rot.vy = D_801CF8EC.pad = *(u16 *)D_80151A46[D_801CF8E0];
    rot.vx = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801B78C0, &D_801CF8F4);
    switch (D_801CF918) {
    case 0:
        p = &D_80162978[func_800BBEAC((void *)func_801B0DF8)];
        p->unk1C = 0;
        break;
    case 1:
        p = &D_80162978[func_800BBEAC((void *)func_801B0FE4)];
        p->unk1C = 0;
        break;
    default:
        p->unk1C = 0;
        break;
    }
}

INCLUDE_RODATA("../asm/us/magic_wpea/nonmatchings/text", D_801B0000);

void func_801B1384(arg0, arg1) {
    s32 i;
    s32 n;

    D_801CF8D4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    D_801CF8D8 = arg0;
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            n++;
            if (n == 1) {
                D_801CF8DC = i;
            }
        }
    }
    D_801CF8E0 = arg1;
    func_800BBEAC(&func_801B11E8);
}
