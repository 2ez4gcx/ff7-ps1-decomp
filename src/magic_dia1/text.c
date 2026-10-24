#include "common.h"
#include "magic_dia1/decls.h"

void func_801B0054(void) {
    func_801B1E58();
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
    rot2.vy = D_801DF5F2;
    func_8003BF8C(&rot2, &m1);
    func_801B0150(-ang, &m2, &D_801C6F6C);
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
    ((MgScratch *)0x1F800000)->unk0 = &D_801C6BA4;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DEF94 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DEF94);
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
    ((MgScratch *)0x1F800000)->unk0 = &D_801C6BA4;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    D_801DEF94 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DEF94);
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
    ((MgScratch *)0x1F800000)->unk0 = &D_801C6BA4;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk4 = 0;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 0xC) {
        ((MgScratch *)0x1F800000)->unk4 = 8;
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 0xC) * 0x10;
    }
    D_801DEF94 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801DEF94);
    if (p->unk2 >= 0x14) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0xA) {
            n = func_800D56A8(&p->unk4);
            if (n > 0x40) {
                func_800D4D4C(D_801DEFA0, 0x118);
            } else {
                func_800D4D4C(D_801DEFA0, 0x18);
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
            *(MgSVec *)&q->unk4 = D_801DF5EC;
            d = *(s16 *)D_80151A4E[D_801DEFA4] - D_801DF5EC.vy;
            if (d < 0) {
                d = -d;
            }
            q->unkE = -0x12C;
            q->unkA = d;
            q->unk18 = 0x2000;
            func_800D55F4(0x20, func_800D56A8(&D_801DF5EC), 0x1D5);
        }
        if (p->unk2 == 0x18) {
            q = &D_80162978[func_800BBEAC(&func_801B06E0)];
            q->unk6 = -0x10A;
            q->unkE = 0x21;
            q->unk14 = 0;
            func_800D55F4(0x20, 0x40, 0x1D6);
        }
        if (p->unk2 == 0x48) {
            func_800D3994(D_801DEFA0, D_8015190F[D_801DEFA0][0], &p->unk4);
            v.vx = p->unk4 - D_80158D00[0];
            v.vy = 0;
            v.vz = p->unk8 - D_80158D00[2];
            d = func_80039F5C(((s32 (*)(MgVec *, MgVec *))func_8003A08C)(&v, &v)) / 12;
            ang = func_801B0074(&D_801C6F5C, &v, &axis);
            func_801B0150(ang, &m, &axis);
            func_8003AB84(&m, &D_801C6F5C, &v);
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

    func_800D3994(D_801DEFA4, D_80151919[D_801DEFA4][0], &D_801DF5EC);
    D_801DF5EC.vy -= 0xE0;
    rot.vy = D_801DF5EC.pad = *(u16 *)D_80151A46[D_801DEFA4];
    rot.vx = 0;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801C6F5C, &D_801DF5F4);
    func_8003AB84(&m, &D_801C6F6C, &D_801DF604);
}

INCLUDE_ASM("../asm/us/magic_dia1/nonmatchings/text", func_801B0F9C);

INCLUDE_ASM("../asm/us/magic_dia1/nonmatchings/text", func_801B10B8);

INCLUDE_ASM("../asm/us/magic_dia1/nonmatchings/text", func_801B11D4);

INCLUDE_ASM("../asm/us/magic_dia1/nonmatchings/text", func_801B1500);

INCLUDE_ASM("../asm/us/magic_dia1/nonmatchings/text", func_801B1BCC);

void func_801B1CD8(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    if (D_80062D98 == 0) {
        if (p->unk2 == 90) {
            ((void (*)(s32, s32))func_801B1BCC)(D_801DEFA0, D_801DEFA4);
            p->unk0 = -1;
        }
        p->unk2++;
    }
}

void func_801B1D5C(void) {
    MgSVec pos;
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    p->unk0 = -1;
    func_800D3994(D_801DEFA0, D_8015190F[D_801DEFA0][0], &pos);
    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B0B30)];
    p->unk4 = pos;
    func_801B0E9C();
    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B1CD8)];
    p->unk4 = pos;
}

INCLUDE_RODATA("../asm/us/magic_dia1/nonmatchings/text", D_801B0000);

void func_801B1E58(mask, arg1) {
    s32 i;
    s32 n;

    D_801DEF98 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B1F24, 0, 0, 0);
    D_801DEF9C = mask;
    for (i = 0, n = 0; i < 10; i++) {
        if ((mask >> i) & 1) {
            n++;
            if (n == 1) {
                D_801DEFA0 = i;
            }
        }
    }
    D_801DEFA4 = arg1;
    func_800BBEAC(&func_801B1D5C);
}
