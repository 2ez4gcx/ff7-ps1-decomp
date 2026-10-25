#include "common.h"
#include "magic_matra/decls.h"

void func_801B0070(void) {
    func_801B1F38();
}

s32 func_801B0090(MgVec *a, MgVec *b, MgVec *c) {
    s32 dot;
    s32 ang;
    MgVec unused;

    dot = (a->vx * b->vx + a->vy * b->vy + a->vz * b->vz) >> 12;
    func_8003BA10(a, b, c);
    ang = func_8003CC1C(func_8003A59C((c->vx * c->vx + c->vy * c->vy + c->vz * c->vz) >> 12), dot);
    func_8003A08C(c, c);
    return ang;
}

void func_801B016C(s32 ang, MgMat *m, MgVec *v) {
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

void func_801B02E8(MgSVec *p, MgSVec *o, MgVec *n) {
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

s16 func_801B03C4(MgSVec *p, MgSVec *q, MgVec *n) {
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

void func_801B04A8(void) {
    MgTask *p;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801B888C;
    *frame = p->unk2;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -(t >> 3));
    D_801DC890 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801DC890);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_matra/nonmatchings/text", func_801B0574);

INCLUDE_ASM("../asm/us/magic_matra/nonmatchings/text", func_801B0EE0);

INCLUDE_ASM("../asm/us/magic_matra/nonmatchings/text", func_801B107C);

INCLUDE_ASM("../asm/us/magic_matra/nonmatchings/text", func_801B12B8);

void func_801B1428(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801DC890;
    r->otz = func_8003BBDC(v0, &p->x0, &r->sxy, &r->flag);
    func_8003BBDC(v1, &p->x1, &r->sxy, &r->flag);
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->tag.len = 4;
    p->code = 0x52;
    p->tag.addr = ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr;
    ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr = (u32)p;
    p++;
    D_801DC890 = p;
}

INCLUDE_ASM("../asm/us/magic_matra/nonmatchings/text", func_801B1558);

void func_801B1D54(void) {
    s32 i;
    s32 n;
    s32 v;
    s16 t;

    D_80162978[D_8015169C].unk0 = -1;
    for (i = 0; i < D_801DC898; i++) {
        n = D_801DE05C[i].id;
        func_800D3994(n, D_8015190F[n][0], &D_801DE05C[i].x);
        v = (s16)D_801518F6[n][0] + 0x8C;
        if (v >= 0x4F3) {
            v = 0x4F2;
        }
        D_801DE05C[i].h = v;
        D_801DE05C[i].unkC = 0;
    }
    D_80162978[func_800BBEAC(func_801B1558)].unk14 = 0;
    func_800D3994(D_801DC89C, D_8015190F[D_801DC89C][0], D_801DC8A4);
    D_801DC8AA = D_801518F6[D_801DC89C][0];
    t = D_801DC8AA + 0x1F4;
    D_801DC8AC = t;
    if (t >= 0x76D) {
        D_801DC8AC = 0x76C;
    }
}

INCLUDE_RODATA("../asm/us/magic_matra/nonmatchings/text", D_801B001C);

s32 func_801B1F38(arg0, arg1) {
    MgSVec rot;
    MgMat m;
    s32 c;
    s32 k;
    s32 i;
    s32 n;

    D_801DC894 = &D_80162978[func_800BBEAC(D_801B001C)];
    func_800D2980(D_801B20D4, 0, 0, 0);
    c = -1;
    for (k = 0x16C8; k >= 0; k -= 0xD8) {
        *(s32 *)(D_801DC8BC + k) = c;
    }
    for (i = 0, n = 0; i < 10; i++) {
        if ((arg0 >> i) & 1) {
            D_801DE05C[n].id = i;
            n++;
        }
    }
    D_801DC8B0 = 0x400;
    rot.vx = 0;
    D_801DC898 = n;
    D_801DC89C = arg1;
    D_801DC8A0 = 0;
    D_801DC8B4 = 0;
    D_801DC8B8 = 0;
    D_801DE0F0 = 1;
    rot.vy = D_801518F6[arg1][0xA8];
    rot.vz = 0;
    func_8003BF8C(&rot, &m);
    func_8003AB84(&m, &D_801B8864, &D_801B8864);
    func_800BBEAC(func_801B1D54);
    return func_800D55F4(0x28, func_800D574C(arg0), 0x82);
}
