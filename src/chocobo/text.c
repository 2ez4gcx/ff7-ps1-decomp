#include "common.h"
#include "chocobo/decls.h"

/* Declared here otherwise than in the other files (tools/work.py). */
extern u8 D_8009D48E;
extern u8 D_8009D499;
typedef struct { u8 b[4]; } ChoC4C;
typedef struct { u8 cnt; u8 pad1[3]; u8 *prims; } ChoGfxC;
typedef struct { u8 pad0[5]; u8 b5; u8 pad6; u8 b7; u8 pad8[4]; s32 wC; u8 pad10[0x14]; } ChoPrimC;
typedef struct { u8 pad0[6]; u16 flags; u8 pad8[7]; u8 idx; } ChoEntC;
typedef struct { u8 pad0[0x3C]; u32 n; ChoEntC *ents; } ChoWorkC;
extern s32 D_800F5120;
extern u8 *D_800B1250;
extern u8 D_800B66CC;
extern ChoC4C D_800B1270[];
extern ChoC4C D_800B1284[];
extern ChoC4C D_800B1258[];
extern ChoC4C D_800B7518[];
extern u8 D_800B751C;
extern u8 D_800B751D;
extern u8 D_800B751E;
extern u8 D_8009D49E;
void func_800A1F40(ChoGfxC *arg0, s32 arg1);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text", func_800A02D0);

void func_800A1260(void) {
    s32 t;
    s32 u;
    s32 a;
    s32 b;
    s32 n;

    n = D_800F5084->cnt;
    t = D_800B7598;
    u = D_800F507C;
    a = (t + n) % n;
    b = (u + n) % n;
    func_8003AE38();
    if (b < a) {
        func_800A1354(0, b);
        func_800A1354(a, n);
    } else {
        func_800A1354(a, b);
    }
    func_8003AED8();
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text", func_800A1354);

void func_800A157C(void) {
    s32 i;
    ChoPrim *p;
    ChoRacer *c;
    ChoGfx **g;
    ChoPrim *pr;

    for (i = 0, g = &D_800B1254; i < 6; i++) {
        c = &D_800B75CC[i];
        pr = (*g)->prims; p = &pr[c->f92];
        (*g)->prims[c->f90].r = p->r = 0xC0;
        (*g)->prims[c->f90].g = p->g = 0;
        (*g)->prims[c->f90].b = p->b = 0x80;
    }
}

void func_800A1630(void) {
    u32 temp_a0;

    D_800F5084 = (ChoWork *)0x80110000;
    D_800B7514 = 0xFF;
    D_800F5070 = -0x10;
    D_800B759C = -1;
    D_800B74FC = ((ChoWork *)0x80110000)->cnt;
    D_800B7478 = 0;
    D_800B7500 = ((ChoWork *)0x80110000)->f8;
    D_800B747C = -((D_8009D288 + (D_8009D289 << 8)) >= 0x3E8);
    temp_a0 = (u32)func_8001C808() >> 0x10;
    if ((temp_a0 & 0xF0) == 0xF0) {
        if (temp_a0 & 8) {
            D_8009D48E = 1;
        }
        if (temp_a0 & 2) {
            D_8009D48E = 2;
        }
    }
    if (D_8009D490 != 0) {
        D_8009D491 = 0xFF;
    }
    D_800B7538 = 0;
    D_800B74F8 = 0;
    D_800B753C = 0;
    D_800F504C = -1;
    D_800F508C = -1;
    D_800F5050 = (D_800F5098 + 3) * 2;
    D_800F5098 = D_8009D49F;
    if (D_8009D491 != 0) {
        D_800B7A48 = -1;
    } else {
        D_800B7A48 = 0;
    }
    D_800F5124 = 1;
    D_800F5088 = -1;
    D_800B7594 = -1;
    D_800F5040 = 0;
    D_800F5048 = 0;
    D_800B7A64 = 0;
    D_800F5044 = 0;
    D_800B7660 = 0x1E;
    D_800B753C = 0;
}

void func_800A17F0(void) {
    s16 *p = &D_8009A000;

    *p = 0x23;
    D_8009A004 = 0x40;
    D_8009A014 = 0;
    D_8009A010 = 0;
    D_8009A00C = 0;
    D_8009A008 = 0;
    func_8002DA7C();
    *p = 0xA0;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xA1;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xA2;
    D_8009A004 = 0x7F;
    func_8002DA7C();
    *p = 0xA3;
    D_8009A004 = 0x7F;
    func_8002DA7C();
}

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text", D_800A0018);

void func_800A18BC(void) {
    ChoF4 *a;
    s32 tp;
    s32 c;
    ChoF4 *b;
    s32 i;
    ChoEnv *ev;
    ChoRect rect;
    ChoEnv *f;
    s32 *p;
    s32 h;
    s32 *e;

    rect = D_800A0018;
    e = D_800F5030;
    p = D_800B7530;
    if (p != e) {
loop:
        *p = 0;
        p++;
        if (p != e) {
            goto loop;
        }
    }
    func_8003B6BC(0xA0, 0x78);
    func_8003B6DC(0x10E);
    func_80043D3C(1);
    ev = &D_800D64D8;
    h = 0xE8;
    func_80043814(ev, 0, 0, 0x140, h);
    f = &D_800F4FB8;
    func_80043814(f, 0, 0xF0, 0x140, h);
    tp = func_8004656C(0, 1, 0, 0);
    ev++;
    D_800F4FB8.tpage = D_800D64D8.tpage = tp;
    D_800F4FB8.isbg = D_800D64D8.isbg = 0;
    func_800438D4(ev, 0, 0xF0, 0x140, h);
    func_800438D4(D_800F5014, 0, 0, 0x140, h);
    D_800D64D8.dfe = D_800F4FB8.dfe = 1;
    func_80044244(D_800B7A68, 0x1000);
    func_80044244(D_800D6548, 0x1000);
    func_8004418C(D_800D41A8.ot, 4);
    func_8004418C(D_800F2C88.ot, 4);
    func_80043F6C(&rect, 0, 0, 0);
    func_8003B67C(0x40, 0x40, 0x40);
    func_80043D3C(1);
    func_800444AC(ev);
    func_800443B0(f);
    func_80042DB8(func_8003CEDC(-1));
    func_800A1630();
    D_800F5038 = 0;
    D_800F503A = 0;
    D_800F503C = 0;
    func_800A28D8();
    func_800A272C(D_8009D48F, D_8009D49F);
    D_800F5054 = *D_800F5084->f38;
    if (D_800B7A48 != 0) {
        D_800F5054.b[0] = -1;
    }
    D_800F5054.b[0] = -1;
    i = 0;
    c = 0xFF;
    b = D_800F2BF8;
    a = D_800D4118;
loop2:
    func_800468E8(a);
    func_800468E8(b);
    if (i & 2) {
        a->r = c;
    } else {
        a->r = 0;
    }
    if (i & 4) {
        a->g = c;
    } else {
        a->g = 0;
    }
    if (i & 1) {
        a->b = c;
    } else {
        a->b = 0;
    }
    if (i & 2) {
        b->r = c;
    } else {
        b->r = 0;
    }
    if (i & 4) {
        b->g = c;
    } else {
        b->g = 0;
    }
    if (i & 1) {
        b->b = c;
    } else {
        b->b = 0;
    }
    b++;
    a++;
    i++;
    if (i < 6) {
        goto loop2;
    }
    D_800D5DC2[0] = D_800D5DC2[2] = 0;
    D_800D5DC0[0] = D_800D5DC0[4] = 0;
    D_800D5DC0[2] = D_800D5DC0[6] = 0x140;
    D_800D5DC0[5] = D_800D5DC0[7] = 0xE8;
    func_800468E8((u8 *)D_800D5DC0 - 8);
    func_80046848((u8 *)D_800D5DC0 - 8, 1);
    D_800F4898 = *(ChoF4B *)((u8 *)D_800D5DC0 - 8);
    *(ChoFT4B *)((u8 *)D_800D5DC0 - 0x1C18) = D_800B1298;
    func_800468FC(&D_800D41A8.ft0);
    func_80046848(&D_800D41A8.ft0, 1);
    D_800D41A8.ft0.clut = func_80046634(0x240, 0x80);
    D_800D41A8.ft0.tpage = func_8004656C(0, 0, 0x180, 0);
    D_800F2C88.ft0 = D_800D41A8.ft0;
    D_800D41A8.ft1 = D_800B12C0;
    func_800468FC(&D_800D41A8.ft1);
    func_80046848(&D_800D41A8.ft1, 1);
    D_800D41A8.ft1.clut = func_80046634(0x240, 0x81);
    D_800D41A8.ft1.tpage = func_8004656C(0, 0, 0x180, 0);
    D_800F2C88.ft1 = D_800D41A8.ft1;
    func_800468E8(&D_800D41A8.f4a);
    D_800D41A8.f4a.x0 = D_800D41A8.f4a.x2 = 0x19;
    D_800D41A8.f4a.x1 = D_800D41A8.f4a.x3 = 0x1E;
    D_800D41A8.f4a.y2 = D_800D41A8.f4a.y3 = 0xD1;
    D_800F2C88.f4a = D_800D41A8.f4a;
    func_800A1F40(D_800B1254, D_8009D48F);
    func_800A9828();
}

void func_800A1F40(ChoGfxC *arg0, s32 arg1) {
    s32 po;
    s32 n;
    WmHdr3 *p;
    ChoEntC *e;
    s32 k;
    u32 i;
    s32 h;
    s32 ro;

    D_800F5120 = arg1 ? 0x801AE000 : 0x801AE800;
    *(s32 *)0x1F800000 = 3;
    *(s32 *)0x1F800200 = 1;
    for (i = 0; i < 6; i++) {
        D_800B75CC[i].f92 = i;
        p = (WmHdr3 *)(arg0->prims + i * 0x24);
        p->f16 = 0x280;
        D_800F5120 = func_800AD91C(p, D_800F5120, i);
        if (D_8009D49E != 0 && i == 1) {
            D_800B1250[0] = 0x9C;
            D_800B1250[1] = 0xFF;
            D_800B1250[2] = 0x9C;
            D_800B1250[3] = 0xFF;
            D_800B1250[4] = 0x9C;
            D_800B1250[5] = 0xFF;
            D_800B1250[6] = i;
            D_800B66CC = 0;
            func_800B00DC(p, D_800B1250);
            D_800B66CC = i;
            func_800B00DC(p, D_800B1250);
            D_800B751C = D_800B751D = D_800B751E = 0x40;
        } else if (D_800B7A48 != 0 && i == 0) {
            n = D_8009D499;
            D_800B7518[0] = D_800B1270[n];
            D_800B1250[0] = D_800B1270[n].b[0];
            D_800B1250[1] = (s8)D_800B1270[n].b[0] >> 7;
            D_800B1250[2] = D_800B1270[n].b[1];
            D_800B1250[3] = (s8)D_800B1270[n].b[1] >> 7;
            D_800B1250[4] = D_800B1270[n].b[2];
            D_800B1250[5] = (s8)D_800B1270[n].b[2] >> 7;
            D_800B1250[6] = 1;
            D_800B66CC = 0;
            func_800B00DC(p, D_800B1250);
            D_800B1250[0] = D_800B1284[n].b[0];
            D_800B1250[1] = (s8)D_800B1284[n].b[0] >> 7;
            D_800B1250[2] = D_800B1284[n].b[1];
            D_800B1250[3] = (s8)D_800B1284[n].b[1] >> 7;
            D_800B1250[4] = D_800B1284[n].b[2];
            D_800B1250[5] = (s8)D_800B1284[n].b[2] >> 7;
            D_800B1250[6] = 1;
            D_800B66CC = 1;
            func_800B00DC(p, D_800B1250);
        } else {
            D_800B7518[i] = D_800B1258[i];
            D_800B1250[0] = D_800B1258[i].b[0];
            D_800B1250[1] = (s8)D_800B1258[i].b[0] >> 7;
            D_800B1250[2] = D_800B1258[i].b[1];
            D_800B1250[3] = (s8)D_800B1258[i].b[1] >> 7;
            D_800B1250[4] = D_800B1258[i].b[2];
            D_800B1250[5] = (s8)D_800B1258[i].b[2] >> 7;
            D_800B1250[6] = 1;
            D_800B66CC = 0;
            func_800B00DC(p, D_800B1250);
            D_800B1250[0] = D_800B1258[i].b[0];
            D_800B1250[1] = (s8)D_800B1258[i].b[0] >> 7;
            D_800B1250[2] = D_800B1258[i].b[1];
            D_800B1250[3] = (s8)D_800B1258[i].b[1] >> 7;
            D_800B1250[4] = D_800B1258[i].b[2];
            D_800B1250[5] = (s8)D_800B1258[i].b[2] >> 7;
            D_800B1250[6] = 1;
            D_800B66CC = 1;
            func_800B00DC(p, D_800B1250);
        }
    }
    n = 6;
    if (D_800B7A48 != 0) {
        D_800B75CC[0].f90 = D_8009D48E + 6;
        p = (WmHdr3 *)(arg0->prims + (D_8009D48E * 0x24 + 0xD8));
    } else {
        D_800B75CC[0].f90 = 10;
        p = (WmHdr3 *)(arg0->prims + 10 * 0x24);
    }
    p->f16 = 0x280;
    D_800F5120 = func_800AD91C(p, D_800F5120, n++);
    if (D_8009D49E != 0) {
        D_800B75CC[1].f90 = 9;
        p = (WmHdr3 *)(arg0->prims + 9 * 0x24);
    } else {
        D_800B75CC[1].f90 = 0xB;
        p = (WmHdr3 *)(arg0->prims + 0xB * 0x24);
    }
    p->f16 = 0x280;
    D_800F5120 = func_800AD91C(p, D_800F5120, n++);
    i = 0xC;
    h = 0x280;
    po = 0x1B0;
    ro = 0x148;
loop3:
    do {
        *(s16 *)((u8 *)&D_800B75CC[0].f90 + ro) = i;
        p = (WmHdr3 *)(arg0->prims + po);
        p->f16 = h;
        D_800F5120 = func_800AD91C(p, D_800F5120, n++);
        ro += 0xA4;
        i++;
        po += 0x24;
    } while (0);
    if (i < 0x10) {
        goto loop3;
    }
    for (i = 0x10; i < arg0->cnt; i++) {
        p = (WmHdr3 *)(arg0->prims + i * 0x24);
        p->f16 = 0x280;
        D_800F5120 = func_800AD91C(p, D_800F5120, n);
        n++;
    }
    for (i = 0; i < arg0->cnt; i++) {
        p = (WmHdr3 *)(arg0->prims + i * 0x24);
        ((ChoPrimC *)p)->b5 = 0xC0;
        ((ChoPrimC *)p)->wC = 0;
        ((ChoPrimC *)p)->b7 = 0x80;
    }
    for (i = 0; i < ((ChoWorkC *)D_800F5084)->n; i++) {
        e = (ChoEntC *)((i << 4) + (s32)((ChoWorkC *)D_800F5084)->ents);
        if (e->flags & 1) {
            k = e->idx;
            *(u8 *)0x1F800200 = 0xFF;
            func_800B0E7C((WmHdr3 *)(arg0->prims + k * 0x24), (u8 *)0x1F800200);
        }
    }
}

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text", D_800A0020);

INCLUDE_RODATA("../asm/us/chocobo/nonmatchings/text", D_800A0028);

void func_800A272C(s32 arg0, s32 arg1) {
    ChoRect r1;
    ChoRect r2;

    r1 = D_800A0020;
    r2 = D_800A0028;
    func_80033E74(arg0 ? 0x3C1 : 0x32C, 0x20000, 0x80110000, 0);
    while (func_80034B44() != 0) {
    }
    func_80044000(&r1, 0x80110000);
    func_80043DD8(0);
    if (arg0) {
        func_80033E74(0x3F1, 0x1E000, 0x80190000, 0);
    } else {
        func_80033E74(0x3CE, 0x1E800, 0x80190000, 0);
    }
    while (func_80034B44() != 0) {
    }
    switch (arg1) {
    case 0:
        func_80033E74(0x459, 0x30000, 0x80110000, 0);
        break;
    case 1:
        func_80033E74(0x433, 0x30000, 0x80110000, 0);
        break;
    case 2:
        func_80033E74(0x417, 0x30000, 0x80110000, 0);
        break;
    case 3:
        func_80033E74(0x49C, 0x30000, 0x80110000, 0);
        break;
    }
    while (func_80034B44() != 0) {
    }
    func_80044000(&r2, 0x80110000);
    func_80043DD8(0);
    if (arg0) {
        func_80033E74(0x33E, 0x6A000, 0x80110000, 0);
    } else {
        func_80033E74(0x293, 0x7D000, 0x80110000, 0);
    }
    while (func_80034B44() != 0) {
    }
}

void func_800A28D8(void) {
    func_80033E74(0x4C9, 0x1000, (s32)D_80079F64, 0);
    while (func_80034B44() != 0) {
    }
    func_80033E74(0x4CA, 0x1000, (s32)D_8007AF64, 0);
    while (func_80034B44() != 0) {
    }
    func_80033E74(0x4C8, 0x800, (s32)D_8007BF64, 0);
    while (func_80034B44() != 0) {
    }
    func_80033E74(0x4C7, 0x800, (s32)D_8007C764, 0);
    while (func_80034B44() != 0) {
    }
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text", func_800A2984);

void func_800A2AFC(void) {
    s32 t; s32 u; s32 a; s32 b; s32 n;

    n = D_800F5084->cnt; t = D_800B7598; u = D_800F507C; a = (t + n) % n; b = (u + n) % n;
    D_800F5034 = 0;
    if (b < a) {
        func_800A2BD4(0, b);
        func_800A2BD4(a, n);
    } else {
        func_800A2BD4(a, b);
    }
}

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text", func_800A2BD4);
