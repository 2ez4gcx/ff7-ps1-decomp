#include "common.h"
#include "magic_wep3/decls.h"

void func_801B0054(void) {
    func_801B226C();
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

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0150);

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
    s32 den;

    up.vx = 0;
    up.vy = -0x1000;
    up.vz = 0;
    a = p->vx * n->vx + p->vy * n->vy + p->vz * n->vz;
    b = q->vx * n->vx + q->vy * n->vy + q->vz * n->vz;
    den = (n->vx * up.vx + n->vy * up.vy + n->vz * up.vz) >> 12;
    return (b - a) / den;
}

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0510);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B067C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0774);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B096C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0B4C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0D34);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0F78);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B10EC);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B1514);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B16EC);

void func_801B21F8(void) {
    u8 pad[8];
    D_80162978[D_8015169C].unk0 = -1;
    D_80162994[func_800BBEAC(func_801B16EC)].unk0 = 0;
    func_800D54EC(D_801EB6B8, D_801EB6C0);
}

INCLUDE_RODATA("../asm/us/magic_wep3/nonmatchings/text", D_801B0000);

void func_801B226C(arg0, arg1) {
    D_801EB6B4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B22F8, 0, 0, 0);
    func_800BBEAC(&func_801B21F8);
    D_801EB6B8 = arg0;
    D_801EB6BC = arg1;
}
