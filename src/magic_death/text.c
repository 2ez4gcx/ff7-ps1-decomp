#include "common.h"
#include "magic_death/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B31B4();
    return &D_801B9658;
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

void func_801B0494(DeathRing *r, s32 arg1, s32 arg2) {
    MgTag *p;
    s32 i;
    s32 n;
    s32 k;

    i = 0;
    p = (MgTag *)D_801D6658;
    do {
        n = i + 1;
        k = r->za[i] + r->za[n] + r->zb[i] + r->zb[n];
        k = k >> 4;
        *(s32 *)((u8 *)p + 8) = r->a[n];
        *(s32 *)((u8 *)p + 0x10) = r->a[i];
        *(s32 *)((u8 *)p + 0x18) = r->b[n];
        *(s32 *)((u8 *)p + 0x20) = r->b[i];
        *(s32 *)((u8 *)p + 4) = arg1;
        *(s32 *)((u8 *)p + 0xC) = arg1;
        *(s32 *)((u8 *)p + 0x14) = arg2;
        *(s32 *)((u8 *)p + 0x1C) = arg2;
        p->len = 8;
        ((u8 *)p)[7] = 0x3A;
        p->addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
        ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
        p = (MgTag *)((u8 *)p + 0x24);
        i = n;
    } while (i < 8);
    D_801D6658 = (MgLineG2 *)p;
}

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B05A4);

void func_801B07A8(DeathQuad *q, s32 arg1, s32 arg2) {
    MgTag *p;
    s32 k;

    p = (MgTag *)D_801D6658;
    k = (q->unkD0 + q->unk8) >> 3;
    *(s32 *)((u8 *)p + 8) = q->unk34;
    *(s32 *)((u8 *)p + 0x10) = q->unk30;
    *(s32 *)((u8 *)p + 0x18) = q->unk84;
    *(s32 *)((u8 *)p + 0x20) = q->unk80;
    p->len = 8;
    *(s32 *)((u8 *)p + 4) = arg1;
    *(s32 *)((u8 *)p + 0xC) = arg1;
    *(s32 *)((u8 *)p + 0x14) = arg2;
    *(s32 *)((u8 *)p + 0x1C) = arg2;
    ((u8 *)p)[7] = 0x3A;
    p->addr = ((MgTag *)D_801517C0 + k + 0x1C)->addr;
    ((MgTag *)D_801517C0 + k + 0x1C)->addr = (u32)p;
    p = (MgTag *)((u8 *)p + 0x24);
    D_801D6658 = (MgLineG2 *)p;
}

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0858);

void func_801B0978(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0 + 4;
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32 *, 8) = func_8003BBDC(arg1, arg0 + 0x30, temp_s2, temp_s1);
    func_8003BBDC(arg2, arg0 + 0x34, temp_s2, temp_s1);
}

void func_801B09EC(MgRtp *r, MgSVec *v0, MgSVec *v1, s32 color) {
    MgLineG2 *p;

    func_8003B48C(&D_800FA63C);
    func_8003B51C(&D_800FA63C);
    p = D_801D6658;
    r->otz = func_8003BBDC(v0, &p->x0, &r->sxy, &r->flag);
    func_8003BBDC(v1, &p->x1, &r->sxy, &r->flag);
    *(s32 *)&p->r0 = color;
    *(s32 *)&p->r1 = color;
    p->tag.len = 4;
    p->code = 0x52;
    p->tag.addr = ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr;
    ((MgTag *)D_801517C0 + (r->otz >> 2) + 0x1C)->addr = (u32)p;
    p++;
    D_801D6658 = p;
}

void func_801B0B1C(MgTask *arg0, MgSVec *arg1, MgSVec *arg2) {
    MgSVec v;
    MgMat m1;
    MgMat m2;
    s16 *q;

    q = &D_800FA650;
    v.vx = arg0->unk14 - *q;
    v.vy = arg0->unk18 - D_800FA654;
    v.vz = arg0->unk1C - D_800FA658;
    func_8003BF3C((MgSVec *)(q - 10), &m1);
    func_8003B2CC(&m1, &v, &v);
    func_8003A79C(&m1, arg0, &m2);
    func_8003B2CC(&m2, arg1, arg2);
    arg2->vx += v.vx;
    arg2->vy += v.vy;
    arg2->vz += v.vz;
}

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0C20);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B0EFC);

void func_801B1AF4(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 i;
    s32 j;
    s32 n;
    u8 pad[0x30];

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 1) {
        q = func_800D4FA8(1);
        *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
        q->unk10 = (p->unkC + 0x800) & 0xFFF;
        func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x1A4);
    } else if (p->unk2 == 0x37) {
        func_800D4FA8(2);
    }
    t = (u16)p->unk2;
    if ((u32)(t - 0x18) < 0x10) {
        if ((s16)t < 0x1F) {
            func_801B0C20(1);
        } else {
            func_801B0C20(0);
        }
    } else if ((s16)t == 1) {
        D_801D6670 = 0;
        D_801D6674 = 0;
        D_801D6678 = 0;
        for (j = 0x1E0; j >= 0; j -= 0x20) {
            *(s16 *)(D_801D668A + j) = 0;
        }
    }
    if (p->unk2 == 0x18) {
        func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x1A3);
    }
    if (p->unk2 == 0x28) {
        n = 0;
        for (i = 0; i < 10; i++) {
            if (1 << i & D_801D6660) {
                func_800D5774(i);
                if (D_801517B4 >> i & 1) {
                    n++;
                }
            }
        }
        if (n != 0) {
            func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x1A8);
        }
    }
    if (p->unk2 >= 0x41) {
        p->unk0 = -1;
    }
    p->unk2++;
}

void func_801B1D20(void) {
    MgTask *p;
    MgTask *q;
    s32 t;
    s32 i;
    s32 j;
    u8 pad[0x30];

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 1) {
        q = func_800D4FA8(1);
        *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
        q->unk10 = p->unkC;
        func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x1A4);
    } else if (p->unk2 == 0x37) {
        func_800D4FA8(2);
    }
    t = (u16)p->unk2;
    if ((u32)(t - 0x19) < 0x13) {
        if ((s16)t < 0x1F) {
            func_801B0EFC(1);
        } else {
            func_801B0EFC(0);
        }
    } else if ((s16)t == 1) {
        D_801D6670 = 0;
        D_801D6674 = 0;
        D_801D6678 = 0;
        for (j = 0x1E0; j >= 0; j -= 0x20) {
            *(s16 *)(D_801D668A + j) = 0;
        }
    }
    if (p->unk2 == 0x18) {
        func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x1A3);
    }
    if (p->unk2 == 0x28) {
        for (i = 0; i < 10; i++) {
            if (1 << i & D_801D6660) {
                func_800D5774(i);
            }
        }
        func_800D55F4(0x29, func_800D56A8(&p->unk4), 0x1A8);
    }
    if (p->unk2 >= 0x41) {
        p->unk0 = -1;
    }
    p->unk2++;
}

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B1F14);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2228);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2478);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B278C);

INCLUDE_ASM("../asm/us/magic_death/nonmatchings/text", func_801B2E14);

INCLUDE_RODATA("../asm/us/magic_death/nonmatchings/text", D_801B0000);

void func_801B31B4(arg0, arg1) {
    D_801D665C = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B3248, 0, 0, 0);
    func_800BBEAC(&func_801B2E14);
    D_801D6660 = arg0;
    D_801D6664 = arg1;
    D_801D687C = 0;
}
