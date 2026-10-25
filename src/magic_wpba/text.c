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

INCLUDE_ASM("../asm/us/magic_wpba/nonmatchings/text", func_801B07D8);

INCLUDE_ASM("../asm/us/magic_wpba/nonmatchings/text", func_801B0BA0);

INCLUDE_ASM("../asm/us/magic_wpba/nonmatchings/text", func_801B0E6C);

INCLUDE_ASM("../asm/us/magic_wpba/nonmatchings/text", func_801B10B0);

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
