#include "common.h"
#include "field/decls.h"

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A2314);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A2D5C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A2F78);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A3020);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A364C);

s32 func_800A4094(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a1;

    temp_a1 = arg1 - arg0;
    if ((u32) (temp_a1 + 0x7FFFF) <= 0xFFFFEU) {
        arg0 += (temp_a1 * arg3) / arg2;
    } else {
        arg0 += (temp_a1 / arg2) * arg3;
    }
    return arg0;
}

s32 func_800A4134(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t;
    s32 d;
    s32 a;

    t = (arg3 << 12) / arg2 / 32;
    a = (t - 0x80) & 0xFF;
    d = arg1 - arg0;
    return arg0 + (((s32 (*)(s32))func_800A8620)(a) + 0x1000) * d / 0x2000;
}

s32 func_800A41CC(s32 arg0, M2C_UNK arg1) {
    M2C_UNK sp10;
    M2C_UNK sp14;
    s32 temp_s0;

    func_8003AE38();
    func_8003B48C(D_80071E40);
    func_8003B51C(D_80071E40);
    func_8003B6BC(0, 0);
    temp_s0 = func_8003BBDC(arg0, arg1, &sp10, &sp14);
    func_8003AED8();
    return temp_s0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A424C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A4430);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A45D4);

void func_800A47F8(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;
    s16 temp_v1_2;

    temp_v0 = M2C_FIELD(D_800716C4, s16 *, 0x10);
    if ((temp_v0 - 0xA0) < M2C_FIELD(arg0, s16 *, 0)) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (temp_v0 - 0xA0);
    }
    temp_v1 = M2C_FIELD(D_800716C4, s16 *, 0xC);
    if (M2C_FIELD(arg0, s16 *, 0) < (temp_v1 + 0xA0)) {
        M2C_FIELD(arg0, s16 *, 0) = (s16) (temp_v1 + 0xA0);
    }
    temp_v0_2 = M2C_FIELD(D_800716C4, s16 *, 0x12);
    if ((temp_v0_2 - 0x78) < M2C_FIELD(arg0, s16 *, 2)) {
        M2C_FIELD(arg0, s16 *, 2) = (s16) (temp_v0_2 - 0x78);
    }
    temp_v1_2 = M2C_FIELD(D_800716C4, s16 *, 0xE);
    if (M2C_FIELD(arg0, s16 *, 2) < (temp_v1_2 + 0x78)) {
        M2C_FIELD(arg0, s16 *, 2) = (s16) (temp_v1_2 + 0x78);
    }
}

void func_800A48B8(s32 arg0) {
    s16 v[3];
    u8 *p = &D_8009AC12;

    v[0] = D_80074EB0[*p * 33] >> 12;
    v[1] = D_80074EB4[*p * 33] >> 12;
    v[2] = (D_80074EB8[*p * 33] >> 12) + D_8009AC0A;
    func_800A41CC((s32)v, arg0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A496C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A4BEC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A5FB4);

void func_800A635C(s32 arg0, s16 arg1) {
    if (D_8009AC26 == 0) {
        if (D_8009AC6C & 8) {
            D_80074ED9[arg1 * 0x84] = 0xE0;
            return;
        }
        if (D_8009AC6C & 4) {
            D_80074ED9[arg1 * 0x84] = 0x20;
            return;
        }
        D_80074ED9[arg1 * 0x84] = 0;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A6418);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A65A4);

void func_800A82A0(void *arg0) {
    D_8009ABF5 = 1;
    D_8009ABF6 = M2C_FIELD(arg0, u16 *, 0x12);
    D_8009ABF8 = M2C_FIELD(arg0, u16 *, 0xC);
    D_8009ABFA = M2C_FIELD(arg0, u16 *, 0xE);
    D_8009AC16 = M2C_FIELD(arg0, u16 *, 0x10);
    D_8009AC18 = (s16) M2C_FIELD(arg0, u8 *, 0x14);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8304);

s16 func_800A8600(u8 arg0) {
    return D_800DF120[arg0].a;
}

s16 func_800A8620(u8 arg0) {
    return D_800DF120[arg0].b;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8640);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8858);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8968);

void func_800A8DF4(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg2, s16 *, 0));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg1, s16 *, 2) - M2C_FIELD(arg2, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg2, s16 *, 4));
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8E34);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A8F88);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A9B64);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A9CE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800A9EEC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AA180);

void func_800AA32C(void *arg0) {
    s32 var_v0;
    void *var_a0;

    var_a0 = arg0;
    var_v0 = 0x1F;
    do {
        M2C_FIELD(var_a0, s8 *, 0x15) = 0;
        var_v0 -= 1;
        var_a0 += 0x18;
    } while (var_v0 >= 0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AA348);

s32 func_800AA514(u8 *p, u8 op) {
    s32 ret;
    u8 bit;
    u8 v;

    ret = 0;
    switch (op) {
    case 0:
    case 2:
    case 4:
        bit = 1 << p[0xD];
        v = D_8009ACE6[p[0xC]];
        if (!(v & bit)) {
            ret = 1;
        }
        D_8009ACE6[p[0xC]] = bit | v;
        break;
    case 1:
    case 3:
    case 5:
        if ((u8)(D_8009ACE6[p[0xC]] | ~(1 << p[0xD])) == 0xFF) {
            ret = 1;
        }
        D_8009ACE6[p[0xC]] = ~(1 << p[0xD]) & D_8009ACE6[p[0xC]];
        break;
    }
    return ret;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AA5E4);

void func_800AA870(u8 *p) {
    s32 i;

    i = 0;
    do {
        if (p[0xC] != 0xFF) {
            switch (p[0xE]) {
            case 0:
            case 2:
            case 4:
                func_800AA514(p, 1);
                break;
            case 1:
            case 3:
            case 5:
                func_800AA514(p, 0);
                break;
            }
        }
        i++;
        p += 0x10;
    } while (i < 12);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AA930);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AAB24);

void func_800AB2AC(void) {
}

void func_800AB2B4(void) {
    s32 var_v0;

    if (((u16) D_80114488 == 0) || (D_8009AC2D == 1)) {
        var_v0 = *D_80083578;
    } else {
        var_v0 = D_80083270;
    }
    D_80071E40 = var_v0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AB310);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AB4AC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AB5E8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AB728);

u8 func_800AB9C8(void) {
    D_8009C540 += 1;
    if (D_8009C540 == 0) {
        D_8009AD2C += 0xD;
    }
    return D_800E0638[D_8009C540] - D_8009AD2C;
}

u8 func_800ABA34(void) {
    D_80071C20 += 1;
    return D_800E0638[D_80071C20];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ABA70);

void func_800ABF0C(SPRT16 *p, void *arg1) {
    s16 i;

    i = 0;
    do {
        func_8004694C(p);
        func_80046870(p, 1);
        func_80046848(p, 0);
        p->r0 = 0x80;
        p->g0 = 0x80;
        p->b0 = 0x80;
        p->clut = func_80046634(0x100, 0x1E9);
        i++;
        p++;
    } while (i < 24);
    func_80044A68(arg1, 0, 1, func_8004656C(0, 0, 0x3C0, 0x100) & 0xFFFF, 0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ABFE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AC35C);

s32 func_800ACBA0(Unk800ACBA0 *arg0, s32 arg1, s32 arg2) {
    s32 base;
    u32 i;

    arg0->unk20 = arg1;
    arg1 += arg0->unk2 << 5;
    base = arg0->unk18 + arg0->unk1C;
    for (i = 0; i < arg0->count; i++) {
        arg1 = func_800ACC5C(base + i * 0x20, arg1, 0, arg2);
    }
    func_800AF6EC(arg0, arg0->unk16, 0);
    return arg1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ACC5C);

void func_800AD7B8(void *arg0) {
    Func800AD7B8Hdr *h = arg0;
    Func800AD7B8Entry *e;
    u16 rect[4];
    u32 i;
    u32 n;

    i = 0;
    n = h->n;
    e = h->e;
    for (; i < n; i++) {
        rect[0] = e[i].x;
        rect[1] = e[i].y;
        rect[2] = e[i].w;
        rect[3] = e[i].h;
        func_80044000(rect, (u8 *) h + e[i].off);
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800AD858);

INCLUDE_ASM("../asm/us/field/nonmatchings/text2", func_800ADAA4);

s32 func_800ADC90(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 saved;
    s32 *q;
    u32 i;

    saved = *(s32 *)0x1F800000;
    q = *(s32 **)0x1F800004;
    for (i = 0; i < *(u16 *)(arg0 + 2); i++) {
        *(s32 *)0x1F800000 = saved;
        arg2 = func_800ADD70(arg0, arg1, arg2, i);
    }
    if (arg3 != 0) {
        func_80033E74(q[0], q[1], D_800DFCA0, 0);
        while (func_80034B44() != 0) {
        }
    }
    return arg2;
}
