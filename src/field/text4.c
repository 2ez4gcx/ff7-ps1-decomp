#include "common.h"
#include "field/decls.h"

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AE23C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AE4DC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AEE24);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AF6EC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AF96C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AFAC4);

void func_800AFDE4(void) {
    List2 *p = &D_800DFDFC;
    s32 n;
    s32 i;
    n = 16;
    p->n = n;
    for (i = 0; i < n; i++) {
        p->e[i].a = 0;
        p->e[i].b = 0;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800AFE1C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B0618);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B0A48);

s32 func_800B0EDC(u8 *arg0, u8 *arg1) {
    s16 x;
    s16 y;
    s16 z;
    s32 q;
    u32 i;
    s32 n;
    u8 pad[8];

    n = arg0[3];
    q = *(u16 *)(arg0 + 0x18) + *(s32 *)(arg0 + 0x1C);
    x = (arg1[1] << 8) | arg1[0];
    y = (arg1[3] << 8) | arg1[2];
    z = (arg1[5] << 8) | arg1[4];
    *(s32 *)0x1F800200 = arg1[6];
    for (i = 0; i < n; i++) {
        func_800B0FB0(q + i * 0x20, x, y, z);
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B0FB0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B1C7C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B1E40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B2598);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B2A00);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B2DD4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B2F40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B480C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B4B04);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B4EAC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B5260);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B5504);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B62C4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B69C0);

s32 func_800B6AE4(S6AE4 *a, u8 *b) {
    s32 i;
    s32 n;
    s32 idx;
    u8 *p;

    n = b[0];
    if (n > 0) {
        p = a->base + a->off;
        for (i = 0; i < n; i++) {
            idx = b[1 + i * 2];
            if (idx < a->n) {
                p[idx * 32] = b[2 + i * 2];
            }
        }
    }
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B6B4C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B79B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B86D8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B8CF0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800B9B0C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BA534);

void func_800BA65C(s32 arg0) {
    if (D_8007EBE0 != 0) {
        func_800D4BFC();
        func_800BC338();
        func_800D7D6C();
        func_800D7F9C();
        D_80095DCC = 0;
        D_8009FE8C = 0;
        D_8007EBE0 = 0;
        if ((u8) M2C_FIELD(D_8009C6DC, u8 *, 1) < 5U) {
            func_800429E0(0x4B, 0xB);
        }
        if ((u8) M2C_FIELD(D_8009C6DC, u8 *, 0) < 2U) {
            func_800429E0(0x4B, 0xA);
        }
        if (((u8) M2C_FIELD(D_8009C6DC, u8 *, 0) >= 3U) || ((u8) M2C_FIELD(D_8009C6DC, u8 *, 1) >= 6U)) {
            func_800429E0(0x4B, 0xC);
        }
    }
    if (((u8) D_80099FFC != 4) && (((u8) D_80099FFC != 5) || (D_80070788 != 0))) {
        func_800BB3A8();
    }
    if (D_80071E2C != 0) {
        func_8001F1BC(&D_80083274, 4, arg0, *D_8009C6E0 ^ 1);
    }
    func_800BC438(arg0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BA7C4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BAF54);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BB1B4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BB3A8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BBBCC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BBF74);

void func_800BC338(void) {
    s16 tp;

    D_80114464 = 0x7FFF;
    D_80114468 = 0x7FFF;
    D_80114490 = 0;
    D_800E48F4[0].len = 9;
    D_800E48F4[0].code = 0x2C;
    D_800E48F4[1].len = 9;
    D_800E48F4[1].code = 0x2C;
    D_800E48F4[0].code &= ~2;
    D_800E48F4[1].code &= ~2;
    D_800E48F4[0].code |= 1;
    D_800E48F4[1].code |= 1;
    if (((s32 (*)(void))func_80043CC0)() == 1 || ((s32 (*)(void))func_80043CC0)() == 2) {
        tp = 0x2F;
    } else {
        tp = 0x1F;
    }
    D_800E48F4[0].tpage = D_800E48F4[1].tpage = tp;
    D_800E48F4[0].clut = D_800E48F4[1].clut = 0x7850;
    D_800E48F4[0].r0 = 0;
    D_800E48F4[1].r0 = 0;
    D_800E48F4[0].g0 = 0;
    D_800E48F4[1].g0 = 0;
    D_800E48F4[0].b0 = 0;
    D_800E48F4[1].b0 = 0;
}

void func_800BC438(s32 arg0) {
    u8 *p;
    u8 *q;
    if (M2C_FIELD(D_8009C6E0, s32 *, 0x80) & 0x100) {
        p = &D_8009D5A6;
        *p ^= 1;
    }
    q = &D_8009D5A6;
    if (((*q == 1) && (M2C_FIELD(D_8009C6E0, u8 *, 0x32) == 0)) || (*q & 2)) {
        func_800BC4D4(arg0);
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BC4D4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BC9FC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0270);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0274);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0278);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A027C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0288);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A028C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0290);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A029C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02A8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02B4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02B8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02BC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02C0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02C4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02C8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02CC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02D0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02D4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02D8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02DC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02E0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02E4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02E8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02EC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02F0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A02F4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BEAD4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BECA4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0300);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0308);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0310);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0318);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0320);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A032C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BEE10);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0394);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A039C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A03A4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A03AC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BF3AC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800BF908);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C0248);

s32 func_800C0B54(void) {
    if (D_8009D820 & 3) {
        func_800DA444(D_8009A058, &D_800E4288);
        func_800DA368(&D_800E4288, "???");
        func_800BEAD4(&D_800E4288, 8);
        func_800DA214(3, 0x7F, 0, 0);
    } else {
        func_800D4848((s32) "Bad Event code!");
    }
    return 1;
}

s32 func_800C0BE8(void) {
    D_800831FC[D_800722C4]++;
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C0C18);

s32 func_800C0DE0(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("set", 3);
    }
    func_800BF3AC(1, 2, func_800BEE10(2, 3) & 0xFF);
    D_800831FC[D_800722C4] += 4;
    return 0;
}

s32 func_800C0E5C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("set2", 4);
    }
    func_800C0248(1, 2, func_800BF908(2, 3));
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800C0EDC(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("lbyte", 3);
    }
    func_800BF3AC(1, 2, func_800BEE10(2, 3) & 0xFF);
    D_800831FC[D_800722C4] += 4;
    return 0;
}

s32 func_800C0F58(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("hbyte", 4);
    }
    func_800BF3AC(1, 2, func_800BF908(2, 3) >> 8);
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800C0FD8(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("2byte", 5);
    }
    temp_s0 = func_800BEE10(2, 4) & 0xFF;
    func_800C0248(1, 3, (s16) (temp_s0 | ((func_800BEE10(4, 5) & 0xFF) << 8)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 6;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C107C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C1214);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C13B0);

s32 func_800C1674(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("biton", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 | (1 << func_800BEE10(2, 3))) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800C1714(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bitof", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, temp_s0 & ~(1 << func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800C17B8(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bitxr", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 ^ (1 << func_800BEE10(2, 3))) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C1858);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C1AB4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C1BF4);

s32 func_800C1D24(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("slip", 1);
    }
    D_8007E7C2[D_8007078C[D_800722C4] * 0x18] = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C1DE4(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("if", 5);
    }
    if (func_800C2000() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4("if=true", 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += 6;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4("if=false", 0, 0);
        }
        D_800831FC[D_800722C4] += (D_8009C6DC + D_800831FC[D_800722C4])[5] + 5;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C1EEC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0674);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C2000);

s32 func_800C228C(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A06B0, 7);
    }
    if (func_800C24A8() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06B4, 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += 8;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06C0, 0, 0);
        }
        D_800831FC[D_800722C4] += (D_8009C6DC + D_800831FC[D_800722C4])[7] + 7;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C2394);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06B0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06B4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06C0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06CC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06D4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A06E0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C24A8);

s32 func_800C2754(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4(D_800A06B0, 7);
    }
    if (func_800C2970() != 0) {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06B4, 0, 0);
        }
        pc = &D_800831FC[D_800722C4];
        *pc += 8;
    } else {
        if (D_8009D820 & 3) {
            func_800BECA4(D_800A06C0, 0, 0);
        }
        D_800831FC[D_800722C4] += (D_8009C6DC + D_800831FC[D_800722C4])[7] + 7;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C285C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C2970);

void func_800C2BFC(void) {
    u16 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("key!", 3);
    }
    if (!(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2) & 2)) {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x68);
    } else {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x78);
    }
    func_800C2E00(var_a0);
}

void func_800C2CA8(void) {
    u16 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("keyon", 3);
    }
    if (!(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2) & 2)) {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x70);
    } else {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x80);
    }
    func_800C2E00(var_a0);
}

void func_800C2D54(void) {
    u16 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("keyof", 3);
    }
    if (!(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2) & 2)) {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x74);
    } else {
        var_a0 = M2C_FIELD(D_8009C6E0, u16 *, 0x84);
    }
    func_800C2E00(var_a0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C2E00);

void func_800C2F7C(void) {
    u16 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("req", 2);
    }
    i = D_800831FC[D_800722C4];
    func_800C33B4(1, ((volatile u8 *)D_8009C6DC + i)[1], ((volatile u8 *)D_8009C6DC + i)[2] >> 5, ((volatile u8 *)D_8009C6DC + i)[2] & 0x1F);
}

void func_800C2FFC(void) {
    u16 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("reqsw", 2);
    }
    i = D_800831FC[D_800722C4];
    func_800C33B4(2, ((volatile u8 *)D_8009C6DC + i)[1], ((volatile u8 *)D_8009C6DC + i)[2] >> 5, ((volatile u8 *)D_8009C6DC + i)[2] & 0x1F);
}

void func_800C307C(void) {
    u16 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("reqew", 2);
    }
    i = D_800831FC[D_800722C4];
    func_800C33B4(3, ((volatile u8 *)D_8009C6DC + i)[1], ((volatile u8 *)D_8009C6DC + i)[2] >> 5, ((volatile u8 *)D_8009C6DC + i)[2] & 0x1F);
}

void func_800C30FC(void) {
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("preq", 2);
    }
    c = D_8009D391[(D_8009C6DC + D_800831FC[D_800722C4])[1]];
    if (c == 0xFF) {
        c = 0xFF;
    } else {
        c = D_8009AD30[c];
    }
    func_800C33B4(1, c, (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 5,
                  (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0x1F);
}

void func_800C31E4(void) {
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("prqsw", 2);
    }
    c = D_8009D391[(D_8009C6DC + D_800831FC[D_800722C4])[1]];
    if (c == 0xFF) {
        c = 0xFF;
    } else {
        c = D_8009AD30[c];
    }
    func_800C33B4(2, c, (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 5,
                  (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0x1F);
}

void func_800C32CC(void) {
    u8 c;

    if (D_8009D820 & 3) {
        func_800BEAD4("prqew", 2);
    }
    c = D_8009D391[(D_8009C6DC + D_800831FC[D_800722C4])[1]];
    if (c == 0xFF) {
        c = 0xFF;
    } else {
        c = D_8009AD30[c];
    }
    func_800C33B4(3, c, (D_8009C6DC + D_800831FC[D_800722C4])[2] >> 5,
                  (D_8009C6DC + D_800831FC[D_800722C4])[2] & 0x1F);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C33B4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C3A20);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0810);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C3C34);

s32 func_800C3EA0(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("back", 1);
    }
    p = &D_800831FC[D_800722C4];
    *p -= M2C_FIELD(&D_8009C6DC[*p], u8 *, 1);
    return 1;
}

s32 func_800C3F1C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("lback", 2);
    }
    p = &D_800831FC[D_800722C4];
    *p -= (D_8009C6DC + *p)[1] | ((D_8009C6DC + *p)[2] << 8);
    return 1;
}

s32 func_800C3FA0(void) {
    u16 *p;
    if (D_8009D820 & 3) {
        func_800BEAD4("skip", 1);
    }
    p = &D_800831FC[D_800722C4];
    *p += (D_8009C6DC + *p)[1] + 1;
    return 0;
}

s32 func_800C401C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("lskip", 2);
    }
    p = &D_800831FC[D_800722C4];
    *p = ((D_8009C6DC + *p)[1] | ((D_8009C6DC + *p)[2] << 8)) + (u16)(*p + 1);
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C40A4);

s32 func_800C42B0(void) {
    u8 b;
    s16 v;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0854, 8);
    }
    b = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    D_80095DD0 = b;
    v = b | ((D_8009C6DC + D_800831FC[D_800722C4])[2] << 8);
    D_800831FC[D_800722C4] += 3;
    D_80095DD0 = v;
    return 0;
}

s32 func_800C4350(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0854, 8);
    }
    if (D_800965E8 == 2) {
        D_800831FC[D_800722C4]++;
        return 0;
    }
    return 1;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0848);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0854);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C43C4);

s32 func_800C45AC(void) {
    s16 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("batle", 3);
    }
    switch (M2C_FIELD(D_8009C6E0, u8 *, 1)) {
    case 0:
        func_800D4BFC();
        M2C_FIELD(D_8009C6E0, u8 *, 1) = 2;
        v = func_800BF908(2, 2);
        D_8007EBE0 = 1;
        M2C_FIELD(D_8009C6E0, s16 *, 2) = v;
        M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
        return 1;
    case 2:
        if (M2C_FIELD(D_8009C6E0, s16 *, 0x26) == 2) {
            D_800831FC[D_800722C4] += 4;
            M2C_FIELD(D_8009C6E0, u8 *, 1) = 0;
            M2C_FIELD(D_8009C6E0, s16 *, 0x26) = 0;
            return 0;
        }
        break;
    }
    return 1;
}

void func_800C46A4(void) {
    s32 i;
    Block9A000 *p = (Block9A000 *)&D_8009A000;
    p->a = 0;
    for (i = 5; i >= 0; i--) {
        p->list[i] = 0;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C46D0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C4804);

s32 func_800C493C(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("se", 3);
    }
    func_800C46A4();
    D_8009A000 = 0x20;
    D_8009A004 = func_800BEE10(2, 4) & 0xFF;
    D_8009A008 = (s16) func_800BF908(1, 2);
    func_8002DA7C();
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

void func_800C49EC(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("music", 1);
    }
    func_800C46A4();
    D_8009A000 = 0x10;
    func_800C4BCC();
}

void func_800C4A40(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("musvt", 1);
    }
    func_800C46A4();
    D_8009A000 = 0x14;
    func_800C4BCC();
}

void func_800C4A94(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("musvm", 1);
    }
    func_800C46A4();
    D_8009A000 = 0x15;
    func_800C4BCC();
}

s32 func_800C4AE8(void) {
    u16 *pc;
    s32 ret;

    if (D_8009D820 & 3) {
        func_800BEAD4("cmusc", 5);
    }
    func_800C46A4();
    D_8009A000 = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    D_8009A008 = (s16)func_800BF908(3, 4);
    D_8009A00C = (s16)func_800BF908(4, 6);
    ret = func_800C4BCC();
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return ret;
}

s32 func_800C4BCC(void) {
    u16 *pc;
    u8 *p;
    u8 n;

    if (D_800716D4 == 0) {
        n = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        if (D_8009D820 & 3) {
            func_800BECA4("music=", n, 2);
        }
        p = D_8009C6DC + func_800C4C9C(n);
        D_8009A004 = (s32)p;
        M2C_SFIELD(D_8009C6E0, u8 **, 0x48) = p;
        func_8002DA7C(D_8009C6E0);
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C4C9C(s16 arg0) {
    u8 *p;
    s32 r;

    p = &D_8009C6DC[arg0 * 4 + D_8009C6DC[2] * 8];
    r = p[0x20];
    r |= p[0x21] << 8;
    r |= p[0x22] << 0x10;
    r |= p[0x23] << 0x18;
    return r;
}

s32 func_800C4CE8(void) {
    u16 *temp_v1;
    u8 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bmusc", 1);
    }
    if (D_800716D4 == 0) {
        temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
        if (D_8009D820 & 3) {
            func_800BECA4(&D_800A08B0, temp_s0, 2);
        }
        M2C_FIELD(D_8009C6E0, u8 **, 0x44) = &D_8009C6DC[func_800C4C9C((s16) temp_s0)];
    } else {
        M2C_FIELD(D_8009C6E0, u8 **, 0x44) = NULL;
    }
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A08B0);

s32 func_800C4DE8(void) {
    u16 *temp_v1;
    u8 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("fmusc", 1);
    }
    if (D_800716D4 == 0) {
        temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
        if (D_8009D820 & 3) {
            func_800BECA4(&D_800A08B0, temp_s0, 2);
        }
        M2C_FIELD(D_8009C6E0, u8 **, 0x48) = &D_8009C6DC[func_800C4C9C((s16) temp_s0)];
    } else {
        M2C_FIELD(D_8009C6E0, u8 **, 0x48) = NULL;
    }
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C4EE8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A08D0);

s32 func_800C506C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("mulck", 1);
    }
    D_800716D4 = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    D_800831FC[D_800722C4] += 2;
    return 0;
}

s32 func_800C50EC(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgmovie", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x3A) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C5194(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrlo", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x37) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C523C(void) {
    u16 *pc;
    s32 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("dskcg", 1);
    }
    v = M2C_SFIELD(D_8009C6E0, u8 *, 1);
    switch (v) {
        do {
        } while (0);
    case 0:
        M2C_SFIELD(D_8009C6E0, u8 *, 1) = 13;
        v = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        *(s8 *)D_8009D588 = v;
        break;
    case 13:
        if (M2C_SFIELD(D_8009C6E0, s16 *, 0x26) == 2) {
            M2C_SFIELD(D_8009C6E0, u8 *, 1) = 0;
            pc = &D_800831FC[D_800722C4];
            *pc += 2;
            return 0;
        }
        break;
    }
    return 1;
}

s32 func_800C532C(void) {
    u16 *pc;
    u8 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("uc", 1);
    }
    D_80081DC4 = M2C_SFIELD(D_8009C6E0, u8 *, 0x32) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    if (D_80081DC4 == 0) {
        D_800756E8[M2C_SFIELD(D_8009C6E0, s16 *, 0x2A)] = 0;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

s32 func_800C5414(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("btlon", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x3B) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C54BC(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpdsp", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x38) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C5564(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mvcam", 1);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x39) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800C560C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("gmovr", 0);
    }
    D_8009C6E0[1] = 0x1A;
    *(s16 *)(D_8009C6E0 + 0x26) = 0;
    return 1;
}

s32 func_800C5668(void) {
    u16 *pc;
    u8 n;

    if (D_8009D820 & 3) {
        func_800BEAD4("cc", 1);
    }
    n = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    if (D_8007EB98[n] != 0xFF) {
        M2C_SFIELD(D_8009C6E0, s16 *, 0x2A) = D_8007EB98[n];
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C5740);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C5898);

s32 func_800C5A2C(void) {
    u16 *temp_v0;

    if (D_8009D820 & 3) {
        func_800BEAD4("ccanm", 3);
    }
    switch ((D_8009C6DC + D_800831FC[D_800722C4])[3]) {
    case 0:
        M2C_FIELD(D_8009C6E0, s16 *, 0x2C) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        break;
    case 1:
        M2C_FIELD(D_8009C6E0, s16 *, 0x2E) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        break;
    case 2:
        M2C_FIELD(D_8009C6E0, s16 *, 0x30) = (D_8009C6DC + D_800831FC[D_800722C4])[1];
        break;
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 4;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C5B38);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C5CE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C5E80);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C5FF4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C63CC);

s32 func_800C6748(void) {
    u16 *pc;
    u8 i;

    if (D_8009D820 & 3) {
        func_800BEAD4("animw", 0);
    }
    i = D_8007EB98[D_800722C4];
    if (i == 0xFF) {
        D_800831FC[D_800722C4]++;
        return 0;
    }
    switch (D_800756E8[i]) {
    case 2:
    case 5:
    case 6:
        return 1;
    case 4:
        D_800756E8[i] = 0;
        break;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 1;
    return 0;
}

s32 func_800C684C(void) {
    u16 *pc;
    u8 *m;

    if (D_8009D820 & 3) {
        func_800BEAD4("animb", 0);
    }
    if (D_8007EB98[D_800722C4] != 0xFF) {
        m = D_8009C544 + D_8007EB98[D_800722C4] * 0x84;
        *(s16 *)(m + 0x64) = (s16)*(u16 *)(m + 0x62) >> 4;
        D_800756E8[D_8007EB98[D_800722C4]] = 3;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 1;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C6924);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C6D64);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C6FD8);

s32 func_800C728C(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("fcfix", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x37) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C7354);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C75F0);

void func_800C7C3C(void) {
    u8 temp_a0;
    u8 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("pmova", 1);
    }
    temp_a0 = D_8009D391[M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)];
    if (temp_a0 == 0xFF) {
        var_a0 = 0xFF;
    } else {
        var_a0 = D_8009AD30[temp_a0];
    }
    func_800C7D5C(var_a0);
}

void func_800C7CE8(void) {
    u16 i;
    if (D_8009D820 & 3) {
        func_800BEAD4("mova", 1);
    }
    i = D_800831FC[D_800722C4]; func_800C7D5C((D_8009C6DC + i)[1]);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C7D5C);

void func_800C814C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("dira", 1);
    }
    func_800C826C(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
}

void func_800C81C0(void) {
    u8 temp_a0;
    u8 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("pdira", 1);
    }
    temp_a0 = D_8009D391[M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)];
    if (temp_a0 == 0xFF) {
        var_a0 = 0xFF;
    } else {
        var_a0 = D_8009AD30[temp_a0];
    }
    func_800C826C(var_a0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C826C);

void func_800C8514(void) {
    u16 i;
    if (D_8009D820 & 3) {
        func_800BEAD4("tura", 3);
    }
    i = D_800831FC[D_800722C4];
    func_800C8634((D_8009C6DC + i)[1]);
}

void func_800C8588(void) {
    u8 temp_a0;
    u8 var_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("ptura", 3);
    }
    temp_a0 = D_8009D391[M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)];
    if (temp_a0 == 0xFF) {
        var_a0 = 0xFF;
    } else {
        var_a0 = D_8009AD30[temp_a0];
    }
    func_800C8634(var_a0);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C8634);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C8B98);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C8F64);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C9080);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C91D8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C955C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800C9A20);

s32 func_800C9B88(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("slidR", 2);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6C) = (u8)func_800BEE10(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 3;
    return 0;
}

s32 func_800C9C84(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("sldR2", 3);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6C) = (s16)func_800BF908(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800C9D80(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("talkR", 2);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6E) = (u8)func_800BEE10(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 3;
    return 0;
}

s32 func_800C9E7C(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("tlkR2", 3);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x6E) = (s16)func_800BF908(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800C9F78(void) {
    u16 *pc;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("msped", 3);
        }
        *(s16 *)(D_8009C544 + D_8007EB98[D_800722C4] * 0x84 + 0x70) = (s16)func_800BF908(2, 2) * M2C_FIELD(D_8009C6E0, s16 *, 0x10) / 512;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800CA074(void) {
    u16 *pc;
    s16 v;
    u8 i;

    if (D_8007EB98[D_800722C4] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("asped", 3);
        }
        v = func_800BF908(2, 2);
        i = D_8007EB98[D_800722C4];
        *(s16 *)(D_8009C544 + i * 0x84 + 0x60) = v;
        D_8009D828[i] = v;
    }
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800CA158(void) {
    u16 *temp_v0;
    u8 temp_s0;

    temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2);
    if (D_8007EB98[temp_s0] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("gtdir", 3);
        }
        func_800BF3AC(2, 3, M2C_FIELD(((D_8007EB98[temp_s0] * 0x84) + D_8009C544), u8 *, 0x38));
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 4;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CA254);

s32 func_800CA394(void) {
    u16 *temp_v0;
    u8 temp_s0;

    temp_s0 = M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 2);
    if (D_8007EB98[temp_s0] != 0xFF) {
        if (D_8009D820 & 3) {
            func_800BEAD4("getai", 3);
        }
        func_800C0248(2, 3, M2C_FIELD(((D_8007EB98[temp_s0] * 0x84) + D_8009C544), s16 *, 0x72));
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 4;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CA490);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CA5D4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CA77C);

s32 func_800CA95C(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("visi", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x5C) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

s32 func_800CAA24(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("tlkon", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x5B) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CAAEC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CAC98);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CADFC);

s32 func_800CAF60(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("mes", 2);
    }
    if (func_800D4EB4((D_8009C6DC + D_800831FC[D_800722C4])[1], (D_8009C6DC + D_800831FC[D_800722C4])[2]) != 0) {
        pc = &D_800831FC[D_800722C4];
        *pc += 3;
        return 0;
    }
    return 1;
}

s32 func_800CB01C(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpnam", 1);
    }
    func_800D7A58(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CB0B8);

s32 func_800CB1CC(void) {
    u16 *pc;
    s16 n;

    if (D_8009D820 & 3) {
        func_800BEAD4("wcls!", 0);
    }
    pc = &D_800831FC[D_800722C4];
    n = (D_8009C6DC + *pc)[1];
    if (D_8008326C[n] == 0xFF) {
        *pc += 2;
        return 0;
    }
    ((s32 (*)(s32))func_800D4B28)(n);
    func_800D4EB4(n, 0);
    return 1;
}

s32 func_800CB28C(void) {
    s16 n;

    if (D_8009D820 & 3) {
        func_800BEAD4("wsizw", 8);
    }
    n = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    if (D_8008326C[n] == 0xFF) {
        return func_800CB354(n, D_800722C4);
    }
    if (D_8008326C[n] == D_800722C4) {
        ((s32 (*)(s32))func_800D4B28)(n);
        func_800D4EB4(n, 0);
    }
    return 1;
}

s32 func_800CB354() {
    u8 *p;
    u16 *pc;
    s16 a, b, c, d;

    if (D_8009D820 & 3) {
        func_800BEAD4("wsize", 8);
    }
    p = D_8009C6DC;
    p += D_800831FC[D_800722C4];
    a = p[2] | (p[3] << 8);
    b = p[4] | (p[5] << 8);
    c = p[6] | (p[7] << 8);
    d = p[8] | (p[9] << 8);
    func_800D4C68(p[1], a, b, c, d);
    pc = &D_800831FC[D_800722C4];
    *pc += 10;
    return 0;
}

s32 func_800CB450(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("wrow", 2);
    }
    func_800D4E88((s16) (D_8009C6DC + D_800831FC[D_800722C4])[1], ((D_8009C6DC + D_800831FC[D_800722C4])[2] * 0x10) | 9);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 3;
    return 0;
}

s32 func_800CB4F8(void) {
    u8 *p;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("wmove", 8);
    }
    p = D_8009C6DC;
    p += D_800831FC[D_800722C4];
    func_800D4E24(p[1], (s16)(p[2] | (p[3] << 8)), (s16)(p[4] | (p[5] << 8)));
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return 0;
}

s32 func_800CB5C0(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("wrest", 1);
    }
    func_800D493C((s16) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800CB660(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("wclse", 1);
    }
    if (func_800D4B28(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1)) != 0) {
        temp_a0 = &D_800831FC[D_800722C4];
        *temp_a0 += 2;
        return 0;
    }
    return 1;
}

s32 func_800CB718(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("wmode", 3);
    }
    ((void (*)(s16, u8, s16))func_800D4BC0)((D_8009C6DC + D_800831FC[D_800722C4])[1], (D_8009C6DC + D_800831FC[D_800722C4])[2], (D_8009C6DC + D_800831FC[D_800722C4])[3]);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 4;
    return 0;
}

s32 func_800CB7C0(void) {
    u16 *p;
    s32 a;

    if (D_8009D820 & 3) {
        func_800BEAD4("and", 3);
    }
    a = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, a & func_800BEE10(2, 3));
    p = &D_800831FC[D_800722C4];
    *p += 4;
    return 0;
}

s32 func_800CB858(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("and2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 & func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CB8F4(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("or", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 | func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CB98C(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("or2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 | func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBA28(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("xor", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 ^ func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CBAC0(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("xor2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 ^ func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBB5C(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("plus", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 + func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CBBF4(void) {
    s32 t;
    u8 v;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("plus!", 3);
    }
    t = (u8)func_800BEE10(1, 2) + (u8)func_800BEE10(2, 3);
    v = t;
    if (t >= 0x100) {
        v = 0xFF;
    }
    func_800BF3AC(1, 2, v);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 4;
    return 0;
}

s32 func_800CBCA4(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("plus2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 + func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBD40(void) {
    s16 a;
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("pls2!", 3);
    }
    a = func_800BF908(1, 2);
    v = a + (s16)func_800BF908(2, 3);
    if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    func_800C0248(1, 2, v);
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CBDFC(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("minus", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 - func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CBE94(void) {
    s32 t;
    u8 v;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mins!", 3);
    }
    t = (u8)func_800BEE10(1, 2) - (u8)func_800BEE10(2, 3);
    v = t;
    if (t < 0) {
        v = 0;
    }
    func_800BF3AC(1, 2, v);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 4;
    return 0;
}

s32 func_800CBF40(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mins2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 - func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CBFDC(void) {
    s16 a;
    s32 v;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("mns2!", 3);
    }
    a = func_800BF908(1, 2);
    v = a - (s16)func_800BF908(2, 3);
    if (v <= 0x7FFF) {
        v = 0x8000;
    }
    func_800C0248(1, 2, v);
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CC098(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mul", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (temp_s0 * func_800BEE10(2, 3)) & 0xFF);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CC134(void) {
    u16 *temp_a0;
    u32 temp_s0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mul2", 3);
    }
    temp_s0 = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16) (temp_s0 * func_800BF908(2, 3)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

s32 func_800CC1D4(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("div", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (u8) ((u32) (temp_s0 & 0xFF) / (u32) (func_800BEE10(2, 3) & 0xFF)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CC284(void) {
    s32 a;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("div2", 3);
    }
    a = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16)a / (s16)func_800BF908(2, 3));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CC358(void) {
    s32 temp_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("remai", 3);
    }
    temp_s0 = func_800BEE10(1, 2);
    func_800BF3AC(1, 2, (u8) ((u32) (temp_s0 & 0xFF) % (u32) (func_800BEE10(2, 3) & 0xFF)));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CC404(void) {
    s32 a;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("rema2", 3);
    }
    a = func_800BF908(1, 2);
    func_800C0248(1, 2, (s16)a % (s16)func_800BF908(2, 3));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CC4D8(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc", 2);
    }
    func_800BF3AC(2, 2, func_800BEE10(2, 2) + 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC558(void) {
    u16 *p;
    s32 t;
    u8 v;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc!", 2);
    }
    t = (func_800BEE10(2, 2) & 0xFF) + 1;
    v = t;
    if (t >= 0x100) {
        v = 0xFF;
    }
    func_800BF3AC(2, 2, v);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC5EC(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc2", 3);
    }
    func_800C0248(2, 2, func_800BF908(2, 2) + 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC670(void) {
    s32 var_a2;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("inc2!", 3);
    }
    var_a2 = (s16) func_800BF908(2, 2) + 1;
    if (var_a2 > 0x7FFF) {
        var_a2 = 0x7FFF;
    }
    func_800C0248(2, 2, var_a2);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 3;
    return 0;
}

s32 func_800CC70C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec", 2);
    }
    func_800BF3AC(2, 2, func_800BEE10(2, 2) - 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC78C(void) {
    u16 n;
    u16 var_a2;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec!", 2);
    }
    n = func_800BEE10(2, 2) & 0xFF;
    n--;
    var_a2 = n;
    if ((s16) n < 0) {
        var_a2 = 0;
    }
    func_800BF3AC(2, 2, var_a2 & 0xFF);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 3;
    return 0;
}

s32 func_800CC824(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec2", 3);
    }
    func_800C0248(2, 2, (s32)func_800BF908(2, 2) - 1);
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CC8A8(void) {
    s32 var_a2;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("dec2!", 3);
    }
    var_a2 = (s16) func_800BF908(2, 2) - 1;
    if (var_a2 <= 0x7FFF) {
        var_a2 = 0x8000;
    }
    func_800C0248(2, 2, var_a2);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 3;
    return 0;
}

s32 func_800CC944(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("randm", 2);
    }
    D_80095DC8 += (u8) D_8004A630;
    func_800BF3AC(2, 2, D_800E0638[D_80095DC8]);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 3;
    return 0;
}

s32 func_800CC9EC(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("rdmsd", 2);
    }
    D_8004A630 = func_800BEE10(2, 2) * 0x10 + 1;
    D_800831FC[D_800722C4] += 3;
    return 0;
}

s32 func_800CCA68(void) {
    s32 a;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgon", 3);
    }
    a = func_800BEE10(1, 2);
    M2C_FIELD(&D_8009C6E0[a & 0xFF], u8 *, 0xF2) |= 1 << func_800BEE10(2, 3);
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CCB10(void) {
    s32 a;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgoff", 3);
    }
    a = func_800BEE10(1, 2);
    M2C_FIELD(&D_8009C6E0[a & 0xFF], u8 *, 0xF2) &= ~(1 << func_800BEE10(2, 3));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 4;
    return 0;
}

s32 func_800CCBBC(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("bgclr", 3);
    }
    M2C_FIELD(&D_8009C6E0[func_800BEE10(2, 2) & 0xFF], s8 *, 0xF2) = 0;
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CCC3C(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0BE0, 3);
    }
    (D_8009C6E0 + (func_800BEE10(2, 2) & 0xFF))[0xF2] *= 2;
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

s32 func_800CCCC8(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4(&D_800A0BE0, 3);
    }
    (D_8009C6E0 + (func_800BEE10(2, 2) & 0xFF))[0xF2] >>= 1;
    p = &D_800831FC[D_800722C4];
    *p += 3;
    return 0;
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0BE0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CCD54);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CCE94);

s32 func_800CCFE8(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("mvief", 2);
    }
    if (D_800716CC != 0) {
        func_800C0248(2, 2, D_801144D4);
        D_800831FC[D_800722C4] += 3;
        D_801144D4++;
        return 0;
    } else {
        func_800C0248(2, 2, M2C_SFIELD(D_8009C6E0, s16 *, 0x88));
        pc = &D_800831FC[D_800722C4];
        *pc += 3;
        return 0;
    }
}

s32 func_800CD0C4(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("mpjpo", 0);
    }
    M2C_FIELD(D_8009C6E0, u8 *, 0x36) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 2;
    return 0;
}

s32 func_800CD16C(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("scr2d", 5);
    }
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1D) = 4;
    M2C_SFIELD(D_8009C6E0, s16 *, 0xA) = func_800BF908(1, 2);
    M2C_SFIELD(D_8009C6E0, s16 *, 0xC) = func_800BF908(2, 4);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 6;
    return 0;
}

s32 func_800CD214(void) {
    u16 *pc;
    s32 pad;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrlc", 0);
    }
    M2C_SFIELD(D_8009C6E0, u8 *, 0x1D) = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    M2C_SFIELD(D_8009C6E0, u8 *, 0x1E) = M2C_SFIELD(D_8009C6E0, u8 *, 0x2A);
    M2C_SFIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(2, 2);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CD2E8(void) {
    u16 *temp_a0_2;
    u8 temp_a1;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrla", 0);
    }
    temp_a1 = (D_8009C6DC + D_800831FC[D_800722C4])[4];
    if (D_8007EB98[temp_a1] != 0xFF) {
        M2C_FIELD(D_8009C6E0, u8 *, 0x1D) = (D_8009C6DC + D_800831FC[D_800722C4])[5];
        M2C_FIELD(D_8009C6E0, u8 *, 0x1E) = D_8007EB98[temp_a1];
        M2C_FIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(2, 2);
        M2C_FIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    }
    temp_a0_2 = &D_800831FC[D_800722C4];
    *temp_a0_2 += 6;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CD3F0);

s32 func_800CD554(void) {
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrcc", 0);
    }
    M2C_FIELD(D_8009C6E0, s8 *, 0x1D) = 0;
    M2C_FIELD(D_8009C6E0, u8 *, 0x1E) = (u8) M2C_FIELD(D_8009C6E0, u8 *, 0x2A);
    M2C_FIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 1;
    return 0;
}

s32 func_800CD5F0(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("scr2dc", 8);
    }
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1D) = 6;
    M2C_SFIELD(D_8009C6E0, s16 *, 0xA) = func_800BF908(1, 3);
    M2C_SFIELD(D_8009C6E0, s16 *, 0xC) = func_800BF908(2, 5);
    M2C_SFIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(4, 7);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 0;
}

s32 func_800CD6B0(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("scr2dl", 8);
    }
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1D) = 5;
    M2C_SFIELD(D_8009C6E0, s16 *, 0xA) = func_800BF908(1, 3);
    M2C_SFIELD(D_8009C6E0, s16 *, 0xC) = func_800BF908(2, 5);
    M2C_SFIELD(D_8009C6E0, s16 *, 0x20) = func_800BF908(4, 7);
    M2C_SFIELD(D_8009C6E0, s8 *, 0x1F) = 0;
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 0;
}

s32 func_800CD770(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("scrlw", 0);
    }
    if (D_8009C6E0[0x1F] == 2) {
        switch (D_8009C6E0[0x1D]) {
        case 1:
        case 2:
        case 3:
            D_8009C6E0[0x1D] = 1;
            break;
        case 5:
        case 6:
            D_8009C6E0[0x1D] = 4;
            break;
        }
        D_8009C6E0[0x1F] = 0;
        pc = &D_800831FC[D_800722C4];
        *pc += 1;
        return 0;
    }
    return 1;
}

s32 func_800CD834(void) {
    RECT16 r;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("stpal", 4);
    }
    func_800CDC14(&r);
    r.y = (u8)func_800BEE10(1, 2) + 0x1E0;
    r.x = 0;
    r.w = (D_8009C6DC + D_800831FC[D_800722C4])[4] + 1;
    r.h = 1;
    func_80044064(&r, (s32)(D_80095DE0 + ((u8)func_800BEE10(2, 3) << 5)));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CD91C(void) {
    RECT16 r;
    u16 *pc;
    u8 x;

    if (D_8009D820 & 3) {
        func_800BEAD4("stpls", 4);
    }
    func_800CDC14(&r);
    pc = &D_800831FC[D_800722C4];
    r.y = (D_8009C6DC + *pc)[1] + 0x1E0;
    r.x = x = (D_8009C6DC + *pc)[3];
    r.w = (D_8009C6DC + *pc)[4] + 1;
    r.h = 1;
    ((s32 (*)(RECT16 *, u16 *))func_80044064)(&r, &((u16 (*)[16])D_80095DE0)[(D_8009C6DC + *pc)[2]][x]);
    D_800831FC[D_800722C4] += 5;
    return 0;
}

s32 func_800CDA24(void) {
    RECT16 r;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("ldpal", 4);
    }
    func_800CDC14(&r);
    r.y = (u8)func_800BEE10(2, 3) + 0x1E0;
    r.x = 0;
    r.w = (D_8009C6DC + D_800831FC[D_800722C4])[4] + 1;
    r.h = 1;
    func_80044000(&r, D_80095DE0 + ((u8)func_800BEE10(1, 2) << 5));
    pc = &D_800831FC[D_800722C4];
    *pc += 5;
    return 0;
}

s32 func_800CDB0C(void) {
    RECT16 r;
    u16 *pc;
    u8 x;

    if (D_8009D820 & 3) {
        func_800BEAD4("ldpls", 4);
    }
    func_800CDC14(&r);
    pc = &D_800831FC[D_800722C4];
    r.y = (D_8009C6DC + *pc)[2] + 0x1E0;
    r.x = x = (D_8009C6DC + *pc)[3];
    r.w = (D_8009C6DC + *pc)[4] + 1;
    r.h = 1;
    func_80044000(&r, &((u16 (*)[16])D_80095DE0)[(D_8009C6DC + *pc)[1]][x]);
    D_800831FC[D_800722C4] += 5;
    return 0;
}

void func_800CDC14(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CDC28);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CDD40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CDE8C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CE054);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CE214);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CE480);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CE6F4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CE904);

void func_800CEB20(void) {
    u8 temp_a0;

    if (*D_8009D391 != 0xFF) {
        temp_a0 = D_8009AD30[*D_8009D391];
        if ((temp_a0 != 0xFF) && (D_8007EB98[temp_a0] != 0xFF)) {
            M2C_FIELD(D_8009C6E0, s16 *, 0x2A) = (s16) D_8007EB98[temp_a0];
        }
    }
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C68);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C70);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C78);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text4", D_800A0C80);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CEB94);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CEE44);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CF028);

s32 func_800CF140(void) {
    s32 i;
    u8 buf[3];
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("prtye", 3);
    }
    for (i = 0; i < 3; i++) {
        buf[i] = (D_8009C6DC + D_800831FC[D_800722C4])[i + 1];
    }
    func_800CF368(buf);
    pc = &D_800831FC[D_800722C4];
    *pc += 4;
    return 0;
}

s32 func_800CF200(void) {
    s32 i;
    u8 buf[3];
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("sptye", 5);
    }
    for (i = 0; i < 3; i++) {
        buf[i] = ((s32 (*)(s16, s16))func_800BEE10)(i + 1, i + 3);
    }
    func_800CF368(buf);
    pc = &D_800831FC[D_800722C4];
    *pc += 6;
    return 0;
}

s32 func_800CF2BC(void) {
    s32 i;
    u16 *temp_v0;

    if (D_8009D820 & 3) {
        func_800BEAD4("gptye", 5);
    }
    for (i = 0; i < 3; i++) {
        func_800BF3AC(i + 1, i + 3, D_8009D391[i]);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 6;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CF368);

void func_800CF4CC(u8 *a, u8 *b, u8 *out1, u8 *out2) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        out1[i] = 0xFF;
        out2[i] = 0xFF;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (b[i] == a[j]) {
                goto found1;
            }
        }
        *out1++ = b[i];
    found1:;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[i] == b[j]) {
                goto found2;
            }
        }
        *out2++ = a[i];
    found2:;
    }
}

void func_800CF5A0(void) {
    u8 sp10[8];
    u8 sp18[8];

    func_800CF4CC(D_8009CBDC, D_8009CBDC + 0x7B5, sp10, sp18);
    func_800CF66C(D_8009CBDC, sp18);
    func_800CF6C0(D_8009CBDC, sp10);
    D_80071E34 = 1;
}

void func_800CF60C(void) {
    u8 sp10[8];
    u8 sp18[8];

    func_800CF4CC(D_8009D391, D_8009D391 - 0x7B5, sp10, sp18);
    func_800CF66C(D_8009D391, sp18);
    func_800CF6C0(D_8009D391, sp10);
}

void func_800CF66C(u8 *a, u8 *b) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (b[i] == a[j]) {
                a[j] = 0xFF;
            }
        }
    }
}

void func_800CF6C0(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (arg0[j] == 0xFF) {
                arg0[j] = arg1[i];
                break;
            }
        }
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CF718);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CF874);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CF9B8);

s32 func_800CFAF0(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("mmblk", 3);
    }
    p = &D_800831FC[D_800722C4];
    D_8009D788[0] |= 1 << (D_8009C6DC + *p)[1];
    *p += 2;
    return 0;
}

s32 func_800CFB84(void) {
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("mmbuk", 3);
    }
    temp_a0 = &D_800831FC[D_800722C4];
    *D_8009D788 &= ~(1 << M2C_FIELD(&D_8009C6DC[*temp_a0], u8 *, 1));
    *temp_a0 += 2;
    return 0;
}

s32 func_800CFC1C(void) {
    u16 *temp_v0;
    u8 temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("solid", 1);
    }
    temp_a0 = D_8007EB98[D_800722C4];
    if (temp_a0 != 0xFF) {
        M2C_FIELD(((temp_a0 * 0x84) + D_8009C544), u8 *, 0x59) = (u8) M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1);
    }
    temp_v0 = &D_800831FC[D_800722C4];
    *temp_v0 += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CFCE4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800CFE78);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D0180);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D0518);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D0938);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D0B4C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D1200);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D1350);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D152C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D1654);

s32 func_800D184C(void) {
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("nfade", 8);
    }
    M2C_FIELD(D_8009C6E0, volatile s16 *, 0x4C) = (D_8009C6DC + D_800831FC[D_800722C4])[3];
    M2C_FIELD(D_8009C6E0, s16 *, 0x5E) = (u8)func_800BEE10(1, 4);
    M2C_FIELD(D_8009C6E0, s16 *, 0x60) = (u8)func_800BEE10(2, 5);
    M2C_FIELD(D_8009C6E0, s16 *, 0x62) = (u8)func_800BEE10(3, 6);
    M2C_FIELD(D_8009C6E0, volatile s16 *, 0x4E) = 0;
    M2C_SFIELD(D_8009C6E0, s16 *, 0x50) = func_800BF908(4, 7);
    pc = &D_800831FC[D_800722C4];
    *pc += 9;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D195C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D1A80);

s32 func_800D1B94(void) {
    s16 n;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("gwcol", 6);
    }
    n = (u8)func_800BEE10(1, 3);
    n = n * 3;
    func_800BF3AC(2, 4, D_80049208[n]);
    func_800BF3AC(3, 5, D_80049208[n + 1]);
    func_800BF3AC(4, 6, D_80049208[n + 2]);
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

s32 func_800D1C68(void) {
    s16 n;
    u16 *pc;

    if (D_8009D820 & 3) {
        func_800BEAD4("swcol", 6);
    }
    n = (u8)func_800BEE10(1, 3);
    n = n * 3;
    D_80049208[n] = func_800BEE10(2, 4);
    D_80049208[n + 1] = func_800BEE10(3, 5);
    D_80049208[n + 2] = func_800BEE10(4, 6);
    pc = &D_800831FC[D_800722C4];
    *pc += 7;
    return 0;
}

s32 func_800D1D3C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("lstmp", 2);
    }
    func_800C0248(2, 2, *(s16 *)(D_8009C6E0 + 0x64));
    D_800831FC[D_800722C4] += 3;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D1DB8);

s32 func_800D1F20(void) {
    s32 temp_s0;
    s32 temp_s0_2;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("stitm", 4);
    }
    temp_s0 = (func_800BEE10(2, 4) & 0xFF) << 9;
    temp_s0_2 = temp_s0 | func_800BF908(1, 2);
    if (D_8009D820 & 3) {
        func_800BECA4("S item=", temp_s0_2 & 0xFFFF, 4);
    }
    func_80025380(temp_s0_2 & 0xFFFF);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 5;
    return 0;
}

s32 func_800D1FDC(void) {
    s32 temp_s0;
    s32 temp_s0_2;
    u16 *temp_v1;

    if (D_8009D820 & 3) {
        func_800BEAD4("dlitm", 4);
    }
    temp_s0 = (func_800BEE10(2, 4) & 0xFF) << 9;
    temp_s0_2 = temp_s0 | func_800BF908(1, 2);
    if (D_8009D820 & 3) {
        func_800BECA4("G item=", temp_s0_2 & 0xFFFF, 4);
    }
    func_80025288(temp_s0_2 & 0xFFFF);
    temp_v1 = &D_800831FC[D_800722C4];
    *temp_v1 += 5;
    return 0;
}

s32 func_800D2098(void) {
    s32 var_s0;
    u16 *temp_a0;

    if (D_8009D820 & 3) {
        func_800BEAD4("ckitm", 4);
    }
    var_s0 = func_80025310(func_800BF908(1, 2) & 0xFFFF);
    if (D_8009D820 & 3) {
        func_800BECA4("C item=", var_s0 & 0xFFFF, 4);
    }
    if ((var_s0 & 0xFFFF) == 0xFFFF) {
        var_s0 = 0;
    }
    func_800BF3AC(2, 4, (u8) ((u32) (var_s0 & 0xFFFF) >> 9));
    temp_a0 = &D_800831FC[D_800722C4];
    *temp_a0 += 5;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text4", func_800D2164);
