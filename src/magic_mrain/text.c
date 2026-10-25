#include "common.h"
#include "magic_mrain/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B289C();
    return &D_801D4384;
}

s32 func_801B007C(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B0158(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02D4(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03B0(MgSVec *p, MgSVec *q, MgVec *n) {
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

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B0494);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B083C);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B08AC);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B0A08);

void func_801B0EA8(void) {
    MgTask *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    frame = &D_801D5800;
    *frame = p->unk2;
    func_800D4368(&p->unk4, 0x2500, 0);
    D_801ED820 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D2A2C) {
            p->unk0 = -1;
        }
    }
}

void func_801B0F6C(void) {
    MgTask *p;
    MrPart *base;
    s32 o;
    MrPart *e;
    s32 i;
    s32 j;
    s32 r;
    s32 s2;
    s32 s1;
    s16 v;

    i = 0;
    p = &D_80162978[D_8015169C];
    base = D_801ED838[p->unk1C].e;
    do {
        e = &base[i];
        if (e->flag != 0) {
            D_801D580C.v = e->timer;
            v = e->w;
            func_800D4368(&e->x, v, -(v >> 3));
            D_801ED820 = func_800D4D90((u8 *)&D_801D580C - 8, D_801517C0 + 0x70, 0xC, D_801ED820);
            if (D_80062D98 == 0) {
                if (e->timer >= 7) {
                    e->flag = 0;
                }
                e->timer++;
            }
        }
        i++;
    } while (i < 0x40);
    if (D_80062D98 == 0) {
        if (p->unk2 >= 0x10) {
            p->unk0 = -1;
        }
        j = 0;
        if (p->unk2 < 6) {
            s1 = p->unk18;
            i = 0;
            s2 = s1 * 2;
            do {
                for (j = 0; j < 0x40; j++) {
                    if (base[j].flag == 0) {
                        break;
                    }
                }
                if (j >= 0x40) {
                    break;
                }
                o = j * 0x18;
                e = (MrPart *)(o + (s32)base);
                e->flag = 1;
                e->timer = 0;
                e->x = p->unk4 + (func_80042DA8() % s2 - s1);
                e->y = p->unk6 - func_80042DA8() % s1;
                e->z = p->unk8 + (func_80042DA8() % s2 - s1);
                r = func_80042DA8();
                e->w = r % 0x800 + 0x2000;
                i++;
                j = 0;
            } while (i < 2);
        }
        p->unk2++;
    }
}

void func_801B1238(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D2E64;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 8) * 0x10;
    }
    D_801ED820 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk18 += p->unk1A;
        p->unk1A -= p->unk1A >> 2;
        p->unk2++;
        p->unkE -= p->unkE / 5;
    }
}

void func_801B1420(void) {
    MgSVec rot;
    MgMat m;
    MgVec scale;
    MgTask *p;

    rot.vx = 0;
    p = &D_80162978[D_8015169C];
    rot.vy = p->unkC;
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    m.t[0] = p->unk4;
    m.t[1] = p->unk6;
    m.t[2] = p->unk8;
    scale.vx = scale.vy = scale.vz = p->unk18;
    func_8003B35C(&m, &scale);
    func_8003A63C(&D_800FA63C, &m, &m);
    func_8003B48C(&m);
    func_8003B51C(&m);
    ((MgScratch *)0x1F800000)->unk0 = D_801D33C0;
    ((MgScratch *)0x1F800000)->unk4 = 8;
    ((MgScratch *)0x1F800000)->unkA = 0x80;
    ((MgScratch *)0x1F800000)->unk8 = 0;
    ((MgScratch *)0x1F800000)->unkC = 0x20;
    ((MgScratch *)0x1F800000)->unkE = 0;
    if (p->unk2 >= 8) {
        ((MgScratch *)0x1F800000)->unkA = 0x80 - (p->unk2 - 8) * 0x10;
    }
    D_801ED820 = func_800D29D4((MgScratch *)0x1F800000, D_801517C0 + 0x70, 0xC, D_801ED820);
    if (p->unk2 >= 0x10) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unkC += p->unkE;
        p->unk18 += p->unk1A;
        p->unk1A -= p->unk1A >> 2;
        p->unk2++;
        p->unkE -= p->unkE / 5;
    }
}

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B1608);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B179C);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B1940);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B1B24);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B1C14);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B2048);

INCLUDE_ASM("../asm/us/magic_mrain/nonmatchings/text", func_801B27A4);

INCLUDE_RODATA("../asm/us/magic_mrain/nonmatchings/text", D_801B0000);

void func_801B289C(arg0, arg1) {
    D_801ED824 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B2928, 0, 0, 0);
    func_800BBEAC(&func_801B27A4);
    D_801ED828 = arg0;
    D_801ED82C = arg1;
}
