#include "common.h"
#include "chocobo/decls.h"

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

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text", func_800A18BC);

INCLUDE_ASM("../asm/us/chocobo/nonmatchings/text", func_800A1F40);

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
