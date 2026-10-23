#include "common.h"
#include "field/decls.h"

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A1370);

void func_800A1498(void) {
    if (D_800965E8 == 1) {
        func_8003408C();
    }
    D_80071A5C = 0;
    D_800965E8 = 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A14D8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A16CC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A2314);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A2D5C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A2F78);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A3020);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A364C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A4094);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A4134);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A424C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A4430);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A45D4);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A48B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A496C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A4BEC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A5FB4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A635C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A6418);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A65A4);

void func_800A82A0(void *arg0) {
    D_8009ABF5 = 1;
    D_8009ABF6 = M2C_FIELD(arg0, u16 *, 0x12);
    D_8009ABF8 = M2C_FIELD(arg0, u16 *, 0xC);
    D_8009ABFA = M2C_FIELD(arg0, u16 *, 0xE);
    D_8009AC16 = M2C_FIELD(arg0, u16 *, 0x10);
    D_8009AC18 = (s16) M2C_FIELD(arg0, u8 *, 0x14);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A8304);

s16 func_800A8600(u8 arg0) {
    return D_800DF120[arg0].a;
}

s16 func_800A8620(u8 arg0) {
    return D_800DF120[arg0].b;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A8640);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A8858);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A8968);

void func_800A8DF4(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg2, s16 *, 0));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg1, s16 *, 2) - M2C_FIELD(arg2, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg2, s16 *, 4));
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A8E34);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A8F88);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A9B64);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A9CE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800A9EEC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AA180);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AA348);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AA514);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AA5E4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AA870);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AA930);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AAB24);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AB310);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AB4AC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AB5E8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AB728);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ABA70);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ABF0C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ABFE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AC35C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ACBA0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ACC5C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AD7B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AD858);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ADAA4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ADC90);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800ADD70);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AE23C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AE4DC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AEE24);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AF6EC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AF96C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AFAC4);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800AFE1C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B0618);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B0A48);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B0EDC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B0FB0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B1C7C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B1E40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B2598);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B2A00);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B2DD4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B2F40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B480C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B4B04);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B4EAC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B5260);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B5504);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B62C4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B69C0);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B6B4C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B79B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B86D8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B8CF0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800B9B0C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BA534);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BA7C4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BAF54);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BB1B4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BB3A8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BBBCC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BBF74);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BC338);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BC438);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BC4D4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BC9FC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0270);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0274);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0278);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A027C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0288);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A028C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0290);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A029C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02A8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02B4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02B8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02BC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02C0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02C4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02C8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02CC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02D0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02D4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02D8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02DC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02E0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02E4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02E8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02EC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02F0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A02F4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BEAD4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BECA4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0300);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0308);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0310);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0318);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0320);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A032C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BEE10);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0394);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A039C);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A03A4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A03AC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BF3AC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800BF908);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C0248);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C0C18);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C0FD8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C107C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1214);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C13B0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1674);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1714);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C17B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1858);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1AB4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1BF4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1D24);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1DE4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C1EEC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0674);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2000);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C228C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2394);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A06B0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A06B4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A06C0);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A06CC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A06D4);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A06E0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C24A8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2754);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C285C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2970);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2BFC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2CA8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2D54);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C2E00);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C30FC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C31E4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C32CC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C33B4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C3A20);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0810);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C3C34);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C40A4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C42B0);

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

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0848);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0854);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C43C4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C45AC);

void func_800C46A4(void) {
    s32 i;
    Block9A000 *p = (Block9A000 *)&D_8009A000;
    p->a = 0;
    for (i = 5; i >= 0; i--) {
        p->list[i] = 0;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C46D0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C4804);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C493C);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C4AE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C4BCC);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C4CE8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A08B0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C4DE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C4EE8);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A08D0);

s32 func_800C506C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("mulck", 1);
    }
    D_800716D4 = (D_8009C6DC + D_800831FC[D_800722C4])[1];
    D_800831FC[D_800722C4] += 2;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C50EC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5194);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C523C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C532C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5414);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C54BC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5564);

s32 func_800C560C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("gmovr", 0);
    }
    D_8009C6E0[1] = 0x1A;
    *(s16 *)(D_8009C6E0 + 0x26) = 0;
    return 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5668);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5740);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5898);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5A2C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5B38);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5CE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5E80);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C5FF4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C63CC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C6748);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C684C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C6924);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C6D64);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C6FD8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C728C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C7354);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C75F0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C7C3C);

void func_800C7CE8(void) {
    u16 i;
    if (D_8009D820 & 3) {
        func_800BEAD4("mova", 1);
    }
    i = D_800831FC[D_800722C4]; func_800C7D5C((D_8009C6DC + i)[1]);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C7D5C);

void func_800C814C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("dira", 1);
    }
    func_800C826C(M2C_FIELD(&D_8009C6DC[D_800831FC[D_800722C4]], u8 *, 1));
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C81C0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C826C);

void func_800C8514(void) {
    u16 i;
    if (D_8009D820 & 3) {
        func_800BEAD4("tura", 3);
    }
    i = D_800831FC[D_800722C4];
    func_800C8634((D_8009C6DC + i)[1]);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C8588);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C8634);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C8B98);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C8F64);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C9080);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C91D8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C955C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C9A20);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C9B88);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C9C84);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C9D80);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C9E7C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800C9F78);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA074);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA158);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA254);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA394);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA490);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA5D4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA77C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CA95C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CAA24);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CAAEC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CAC98);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CADFC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CAF60);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB01C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB0B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB1CC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB28C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB354);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB450);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB4F8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB5C0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB660);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB718);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB7C0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB858);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB8F4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CB98C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBA28);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBAC0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBB5C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBBF4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBCA4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBD40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBDFC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBE94);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBF40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CBFDC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC098);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC134);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC1D4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC284);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC358);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC404);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC558);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC670);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC78C);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC8A8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CC944);

s32 func_800CC9EC(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("rdmsd", 2);
    }
    D_8004A630 = func_800BEE10(2, 2) * 0x10 + 1;
    D_800831FC[D_800722C4] += 3;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CCA68);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CCB10);

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

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0BE0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CCD54);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CCE94);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CCFE8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD0C4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD16C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD214);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD2E8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD3F0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD554);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD5F0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD6B0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD770);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD834);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CD91C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CDA24);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CDB0C);

void func_800CDC14(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CDC28);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CDD40);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CDE8C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CE054);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CE214);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CE480);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CE6F4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CE904);

void func_800CEB20(void) {
    u8 temp_a0;

    if (*D_8009D391 != 0xFF) {
        temp_a0 = D_8009AD30[*D_8009D391];
        if ((temp_a0 != 0xFF) && (D_8007EB98[temp_a0] != 0xFF)) {
            M2C_FIELD(D_8009C6E0, s16 *, 0x2A) = (s16) D_8007EB98[temp_a0];
        }
    }
}

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0C68);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0C70);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0C78);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0C80);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CEB94);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CEE44);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF028);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF140);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF200);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF2BC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF368);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF4CC);

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

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF718);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF874);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CF9B8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CFAF0);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CFB84);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CFC1C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CFCE4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800CFE78);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D0180);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D0518);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D0938);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D0B4C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1200);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1350);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D152C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1654);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D184C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D195C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1A80);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1B94);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1C68);

s32 func_800D1D3C(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("lstmp", 2);
    }
    func_800C0248(2, 2, *(s16 *)(D_8009C6E0 + 0x64));
    D_800831FC[D_800722C4] += 3;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1DB8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1F20);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D1FDC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2098);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2164);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2794);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D28A8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D298C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2A70);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2B60);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2C60);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2E94);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A0F38);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D2F3C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3004);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3124);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3264);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3330);

void func_800D33FC(void) {
    s16 i;

    for (i = 0; i < 3; i++) {
        if (D_8009CBDC[i] != 0xFF) {
            func_80020058(i);
            func_8001786C(i);
        }
    }
    func_80017678();
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D348C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3548);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D368C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3728);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3840);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3958);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3A70);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3B88);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3C18);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3CA8);

s32 func_800D3D40(void) {
    u16 *p;

    if (D_8009D820 & 3) {
        func_800BEAD4("chmph", 3);
    }
    func_800C0248(1, 2, D_8009A162);
    func_800BF3AC(2, 3, D_8009A15C);
    p = &D_800831FC[D_800722C4];
    *p += 4;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3DCC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3E64);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D3F30);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4038);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4160);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4214);

s32 func_800D4300(void) {
    if (D_8009D820 & 3) {
        func_800BEAD4("btrlt", 2);
    }
    func_800C0248(2, 2, *D_800707BE);
    D_800831FC[D_800722C4] += 3;
    return 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4378);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4420);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D44E8);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4780);

void func_800D4838(void) {
}

void func_800D4840(void) {
}

void func_800D4848(s32 arg0) {
    func_800D828C(0, 0x64, 0x64, 0x96, 0xC);
    func_800DA214(0, 0x7F, 0, 0);
    func_800D9F00(0, arg0);
    D_80095DCC = 1;
    D_80099FFC = 4;
}

void func_800D48C0(void) {
    s32 i;
    u16 off;

    D_80071E2C = 0;
    for (i = 0; i < 4; i++) {
        func_800D493C(i);
    }
    off = M2C_FIELD(D_8009C6DC, u16 *, 4);
    if (off != 0) {
        D_8007E7A8 = &D_8009C6DC[off];
    } else {
        D_8007E7A8 = NULL;
    }
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D493C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4B28);

void func_800D4BC0(s16 arg0, s8 arg1, s16 arg2) {
    D_8008327C[arg0].x11 = arg1;
    D_8008327C[arg0].y26 = arg2;
}

void func_800D4BFC(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800832A0[i].v = 0;
        D_80083286[i].v = 0;
        D_8008326C[i] = 0xFF;
        D_8011445C[i] = 0;
    }
    D_80071E2C = 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4C68);

void func_800D4E24(s16 arg0, s32 arg1, s32 arg2) {
    D_80083278[arg0].v += arg1;
    D_8008327A[arg0].v += arg2;
}

void func_800D4E88(s16 arg0, s16 arg1) {
    D_8008327C[arg0].b = arg1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D4EB4);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D5228);

void func_800D5750(void) {
    func_800C46A4();
    D_8009A000 = 0x30;
    D_8009A004 = 1;
    D_8009A008 = 0x40;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D579C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D5A60);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A10DC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", D_800A10EC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D5C9C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D6D44);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D6E0C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D6F6C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D707C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D726C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D775C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D785C);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D7970);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D7A58);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D7C98);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D7D6C);

void func_800D7F9C(void) {
    func_800D828C(5, 0x6C, 0, 0x6C, 0x52);
    func_800DA334(&D_800E4254, "Authr:");
    func_800DA368(&D_800E4254, D_8009C6DC + 0x10);
    func_800D9F00(5, (s32) &D_800E4254);
    func_800DA334(&D_800E4254, "Event:");
    func_800DA368(&D_800E4254, D_8009C6DC + 0x18);
    func_800D9F00(5, (s32) &D_800E4254);
    func_800D9F00(5, (s32) "  Go");
    func_800D9F00(5, (s32) "  Stop");
    func_800D9F00(5, (s32) "  Step");
    func_800DA124(5, 5, "  Actor OFF");
    func_800DA124(5, 6, "  Info  OFF");
    func_800DA2CC(5);
    func_800D828C(4, 0x6C, 0x52, 0x6C, 0x52);
    func_800D9F00(4, (s32) &D_800E0628);
    func_800DA2CC(4);
    func_800D828C(3, 0x6C, 0xA4, 0x6C, 0x5C);
    func_800D9F00(3, (s32) &D_800E0630);
    func_800DA2CC(3);
    func_800D828C(1, 0, 0, 0x6C, 0xCA);
    func_800D9F00(1, (s32) &D_800E0628);
    func_800DA2CC(1);
    D_80099FFC = 3;
    D_8007EBCC = 4;
    D_8007EBDC = 8;
    D_80071E24 = 0;
    D_8009D820 = 0;
    D_80070788 = 0;
    D_80071C08 = 5;
    func_800DA1D4(5, 4);
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D8194);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D828C);

void func_800D8334(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    D_800E0746[arg0].s02 = arg1;
    D_800E0746[arg0].s04 = arg2;
    D_800E0746[arg0].s06 = arg3;
    D_8009D824 = 1;
    D_800E0746[arg0].s08 = arg4;
}

void func_800D83A8(s16 arg0, s16 arg1, s16 arg2) {
    D_8009D824 = 1;
    D_800E0746[arg0].s02 += arg1;
    D_800E0746[arg0].s04 += arg2;
}

void func_800D8420(s16 arg0, s32 arg1, s32 arg2) {
    D_8009D824 = 1;
    D_800E074C[arg0].a += arg1;
    D_800E074C[arg0].b += arg2;
}

s32 func_800D8498(s16 arg0) {
    return D_800E08C0[arg0].a == 0;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D84CC);

void func_800D85C0(void) {
    D_800E41B8 = 0;
    D_800E41C0 = 0;
    D_800E41BC = 0;
    D_800E41C4 = 0;
    D_800E1024 ^= 1;
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D85FC);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D8710);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D9C04);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D9F00);

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800D9FFC);

s32 func_800DA124(s16 arg0, s16 arg1, u8 *arg2) {
    func_800DA334((u8 *)&D_800E0746[arg0] + 0x12 + arg1 * 0xE, arg2);
    D_8009D824 = 1;
    return 1;
}

s32 func_800DA194(s16 arg0, s16 arg1, s8 arg2) {
    D_800E0746[arg0].f162[arg1] = arg2;
    return 1;
}

s32 func_800DA1D4(s32 arg0, s32 arg1) {
    s32 r = 1;
    D_800E0746[(s16)arg0].s10 = arg1;
    D_8009D824 = r;
    return r;
}

void func_800DA214(s16 arg0, s8 arg1, s8 arg2, s8 arg3) {
    if (D_800E08C0[arg0].a == 0) {
        D_800E0746[arg0].b0A = arg1;
        D_800E0746[arg0].b0B = arg2;
        D_800E0746[arg0].b0C = arg3;
        D_8009D824 = 1;
    }
}

void func_800DA28C(s16 arg0) {
    D_800E08C0[arg0].a = 1;
    D_8009D824 = 1;
}

void func_800DA2CC(s16 arg0) {
    D_800E08C0[arg0].a = 2;
    D_8009D824 = 1;
}

void func_800DA310(void) {
    D_800E4210 = (D_800E4210 + 1) & 3;
}

void func_800DA334(u8 *arg0, u8 *arg1) {
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    if (*var_a1 != 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 += 1;
            *var_a0 = temp_v0;
            var_a0 += 1;
        } while (*var_a1 != 0);
    }
    *var_a0 = 0;
}

void func_800DA368(u8 *dst, u8 *src) {
    while (*dst) {
        dst++;
    }
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
}

s32 func_800DA3C4(u8 *arg0) {
    s32 var_v1;
    u8 *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    if (*var_a0 != 0) {
        do {
            var_a0 += 1;
            var_v1 += 1;
        } while (*var_a0 != 0);
    }
    return var_v1;
}

void func_800DA3F0(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 pad[8];
    s32 var_v1;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v1 = arg2 - 1;
    if (arg2 != 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 += 1;
            var_v1 -= 1;
            *var_a0 = temp_v0;
            var_a0 += 1;
        } while (var_v1 != -1);
    }
}

void func_800DA424(s32 arg0, u8 *arg1) {
    arg1[1] = 0;
    arg1[0] = D_800E0208[arg0 & 0xF];
}

void func_800DA444(s32 arg0, u8 *arg1) {
    arg1[2] = 0;
    arg1[0] = D_800E0208[(arg0 & 0xF0) >> 4];
    arg1[1] = D_800E0208[arg0 & 0xF];
}

void func_800DA480(s32 arg0, u8 *arg1) {
    arg1[4] = 0;
    arg1[0] = D_800E0208[(arg0 & 0xF000) >> 12];
    arg1[1] = D_800E0208[(arg0 & 0xF00) >> 8];
    arg1[2] = D_800E0208[(arg0 & 0xF0) >> 4];
    arg1[3] = D_800E0208[arg0 & 0xF];
}

INCLUDE_ASM("../asm/us/field/nonmatchings/text", func_800DA4FC);

INCLUDE_RODATA("../asm/us/field/nonmatchings/text", func_800A1368);
