#include "common.h"
#include "highway/decls.h"

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A00EC);

void func_800A0554(void) {
    D_800B3BF8 = func_8003CEDC(1);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A057C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A2ADC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A2F4C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A30A0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A31C8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A34A4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3668);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A37C4);

void func_800A397C(void) {
    func_80044244(D_80110A90 + 0x98, 0x1000);
    func_80044244(D_80110A90 + 0x5038, 0x14);
    func_80044244(D_80110A90 + 0x70, 0xA);
    func_800A3AA0(D_80110A90 + 0x5088);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A39E0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3AA0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3AF8);

void func_800A3BC8(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 4) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0xC) = 0x1000;
    M2C_FIELD(arg0, s16 *, 0x14) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x24) = &D_8010EB90;
    M2C_FIELD(arg0, s16 *, 0x2A) = arg1;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3C18);

void func_800A3D24(void *arg0, M2C_UNK arg1, void *arg2) {
    func_8003C21C(arg1, arg0 + 4);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(arg2, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_FIELD(arg2, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg2, s32 *, 8);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3D84);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3E64);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3E98);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3ECC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3EFC);

void func_800A3F78(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), void **, 0x34) = (void *) M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x30) = (void *) M2C_FIELD(arg0, void **, 0x30);
}

void func_800A3F98(void) {
    D_800BDFBC = 0;
    D_8010EBD0 = 0;
    D_800BE304 = 0;
    D_800C4C3C = D_800B4258;
    D_80110AA8 = D_800B425C;
    D_800BD7EC = D_800B4254;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A3FE8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A40B0);

s32 func_800A40DC(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_800BDFBC * 0x24;
    D_800BDFBC += arg0;
    return temp_v0 + D_800C4C3C;
}

s32 func_800A4110(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8010EBD0 * 0x28;
    D_8010EBD0 += arg0;
    return temp_v0 + D_80110AA8;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A4144);

void func_800A4914(s32 arg0) {
    Unk80046D0C sp10;

    func_80046CFC(arg0);
loop_1:
    if (func_80046D0C(&sp10) != 0) {
        if (sp10.a_arg != 0) {
            func_80044000(sp10.a, (void *) sp10.a_arg);
        }
        if (sp10.b_arg != 0) {
            func_80044000(sp10.b, (void *) sp10.b_arg);
        }
        goto loop_1;
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A4984);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A5294);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A535C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A59D8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A5BA8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A5D6C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A64B0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A65B4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A67B8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A6B18);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A6E00);

void func_800A7050(void) {
    D_800BE2EC = 0x78;
    D_800BC4E0 = 0x8E;
    D_800BC4E4 = 0x95;
    D_800BC4E8 = 0x94;
    D_800BDFB8 = 0;
    D_800BC4EC = 0xB1;
    func_800A714C(0);
    func_800A714C(1);
    func_800A714C(2);
    func_800A714C(3);
    func_800A714C(4);
    func_800A714C(5);
    func_800A71E8();
}

void func_800A70E4(s32 arg0, s32 arg1) {
    D_800BE2F4 = arg1;
    D_800BD818 = arg0;
    func_800A7C34();
    func_800A8010();
    func_800A8B48();
    func_800A7A50();
    func_800A9658();
    func_800A9A9C();
    func_800AFC28();
    func_800AA03C();
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A714C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A71E8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A780C);

void func_800A7A48(void) {
}

void func_800A7A50(void) {
    func_800A7AF0(0);
    func_800A7AF0(1);
    if (D_800B528C != 5) {
        func_800A7AF0(2);
    }
    if (D_800B540C != 5) {
        func_800A7AF0(3);
    }
    if (D_800B558C != 5) {
        func_800A7AF0(4);
    }
    if (D_800B570C != 5) {
        func_800A7AF0(5);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A7AF0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A7C34);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A7DA0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A7F48);

void func_800A8010(void) {
    if (D_800B4F8C != 5) {
        func_800A80D4(0);
    }
    if (D_800B510C != 5) {
        func_800A80D4(1);
    }
    if (D_800B570C != 5) {
        func_800A80D4(5);
    }
    if (D_800B528C != 5) {
        func_800A8ADC(2);
    }
    if (D_800B540C != 5) {
        func_800A8ADC(3);
    }
    if (D_800B558C != 5) {
        func_800A8ADC(4);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A80D4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A8ADC);

void func_800A8B48(void) {
    if (D_800B4F8C != 5) {
        func_800A8C0C(0);
    }
    if (D_800B510C != 5) {
        func_800A8C0C(1);
    }
    if (D_800B528C != 5) {
        func_800A8C0C(2);
    }
    if (D_800B540C != 5) {
        func_800A8C0C(3);
    }
    if (D_800B558C != 5) {
        func_800A8C0C(4);
    }
    if (D_800B570C != 5) {
        func_800A8C0C(5);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A8C0C);

void func_800A9658(void) {
    if (D_800B4F8C != 5) {
        func_800A971C(0);
    }
    if (D_800B510C != 5) {
        func_800A971C(1);
    }
    if (D_800B528C != 5) {
        func_800A971C(2);
    }
    if (D_800B540C != 5) {
        func_800A971C(3);
    }
    if (D_800B558C != 5) {
        func_800A971C(4);
    }
    if (D_800B570C != 5) {
        func_800A971C(5);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A971C);

void func_800A9A9C(void) {
    if (D_800B4F8C != 5) {
        func_800A9B60(0);
    }
    if (D_800B510C != 5) {
        func_800A9B60(1);
    }
    if (D_800B528C != 5) {
        func_800A9B60(2);
    }
    if (D_800B540C != 5) {
        func_800A9B60(3);
    }
    if (D_800B558C != 5) {
        func_800A9B60(4);
    }
    if (D_800B570C != 5) {
        func_800A9B60(5);
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A9B60);

void func_800A9DE8(void *arg0, void *arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg1, s32 *, 0x58);
    func_8003CC1C(M2C_FIELD(arg1, s32 *, 0x60) - M2C_FIELD(arg0, s32 *, 0x60), temp_a2 - M2C_FIELD(arg0, s32 *, 0x58), temp_a2);
}

void func_800A9E1C(void *arg0, void *arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    void *temp_a0;
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg1, void **, 0x18);
    temp_a0 = M2C_FIELD(arg0, void **, 0x18);
    temp_v0 = M2C_FIELD(temp_a2, s32 *, 0x18) - M2C_FIELD(temp_a0, s32 *, 0x18);
    temp_v0_2 = M2C_FIELD(temp_a2, s32 *, 0x1C) - M2C_FIELD(temp_a0, s32 *, 0x1C);
    temp_v0_3 = M2C_FIELD(temp_a2, s32 *, 0x20) - M2C_FIELD(temp_a0, s32 *, 0x20);
    temp_a1 = (temp_v0 * temp_v0) + (temp_v0_2 * temp_v0_2);
    func_80039F5C(temp_a1 + (temp_v0_3 * temp_v0_3), temp_a1, temp_a2);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800A9E88);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AA03C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AA438);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AA7FC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AA9E4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AAACC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AAB3C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AB12C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AB348);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AB634);

void func_800AB674(void) {
    D_80110A8C = 1;
    D_800B41E0 = -0x7D0;
    D_800B41D8 = 0;
    D_800B41DC = 0;
    D_800B41E8 = 0;
    D_800B41EC = 0;
    D_800B41F0 = 0;
    D_800B41F8 = 0;
    D_800B41FC = 0;
    D_800B4200 = 0;
    D_800B4208 = 0;
    D_800B420C = 0;
    D_800B4210 = -0x1F4;
    D_8010EA2C = 0;
    D_801163A8 = 0;
    D_800BE2F8 = 0;
    D_800BE2FA = 0;
    D_800BE2FC = 0;
    D_801163F8 = D_800B42D0;
    D_800BE550 = D_800B42D4;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AB738);

void func_800AC2FC(void) {
}

void func_800AC304(s32 arg0, s8 arg1, s32 arg2) {
    D_80110A8C = arg1;
    func_800AC374(arg0 & 0xFF);
    D_800BE538 = 0;
    D_800BDFC8 = arg2;
    D_800BDFAC = D_800BC67C;
    D_800BDFC0 = ((D_800BD550 - 1) << 0x10) - 1;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AC374);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AC3C4);

void func_800AC518(void) {
    D_80110ABC = 0;
    D_800BDFB0 = 0;
    D_800BDFC4 = 0;
    D_800BC4D8 = 0;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AC540);

INCLUDE_RODATA("../asm/us/highway/nonmatchings/text", D_800A0008);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AC680);

s32 func_800AC9C0(void *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v1;
    s32 var_a2;
    s32 var_t2;

    temp_a2 = (s32) M2C_FIELD(arg0, s32 *, 0) >> 2;
    temp_a1 = (s32) M2C_FIELD(arg0, s32 *, 4) >> 2;
    temp_v1 = (s32) M2C_FIELD(arg0, s32 *, 8) >> 2;
    var_t2 = 0;
    var_a2 = 0;
    temp_a3 = (temp_a2 * D_80110A98) + (temp_a1 * D_80110A9C) + (temp_v1 * D_80110AA0) + D_800BDFA4;
    temp_a0 = (temp_a2 * D_80110AAC) + (temp_a1 * D_80110AB0) + (temp_v1 * D_80110AB4) + D_800BDFA8;
    if (temp_a3 > 0) {
        var_t2 = D_800BC674 > 0;
    }
    if ((temp_a3 < 0) && (D_800BC674 < 0)) {
        var_t2 = 1;
    }
    if ((temp_a0 > 0) && (D_800BC6AC > 0)) {
        var_a2 = 1;
    }
    if ((temp_a0 < 0) && (D_800BC6AC < 0)) {
        var_a2 = 1;
    }
    return var_t2 & var_a2;
}

s32 func_800ACAF0(void *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v1;
    s32 var_a2;
    s32 var_t2;

    temp_a2 = (s32) (M2C_FIELD(arg0, u16 *, 0) << 0x10) >> 0x12;
    temp_a1 = (s32) (M2C_FIELD(arg0, u16 *, 2) << 0x10) >> 0x12;
    temp_v1 = (s32) (M2C_FIELD(arg0, u16 *, 4) << 0x10) >> 0x12;
    var_t2 = 0;
    var_a2 = 0;
    temp_a3 = (temp_a2 * D_80110A98) + (temp_a1 * D_80110A9C) + (temp_v1 * D_80110AA0) + D_800BDFA4;
    temp_a0 = (temp_a2 * D_80110AAC) + (temp_a1 * D_80110AB0) + (temp_v1 * D_80110AB4) + D_800BDFA8;
    if (temp_a3 > 0) {
        var_t2 = D_800BC674 > 0;
    }
    if ((temp_a3 < 0) && (D_800BC674 < 0)) {
        var_t2 = 1;
    }
    if ((temp_a0 > 0) && (D_800BC6AC > 0)) {
        var_a2 = 1;
    }
    if ((temp_a0 < 0) && (D_800BC6AC < 0)) {
        var_a2 = 1;
    }
    return var_t2 & var_a2;
}

s32 func_800ACC34(s32 arg0, s32 arg1, s32 arg2) {
    return ((arg0 >> 2) * D_80110A98) + ((arg1 >> 2) * D_80110A9C) + ((arg2 >> 2) * D_80110AA0) + D_800BDFA4;
}

s32 func_800ACC88(s32 arg0, s32 arg1, s32 arg2) {
    return ((arg0 >> 2) * D_80110AAC) + ((arg1 >> 2) * D_80110AB0) + ((arg2 >> 2) * D_80110AB4) + D_800BDFA8;
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ACCDC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ACED4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ACFBC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AD0A4);

void func_800AD374(void) {
    D_800BD4C0 = func_800A3C18(0xAE, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
    D_800BD4C4 = func_800A3C18(0xA5, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
    D_800BD4C8 = func_800A3C18(0xA3, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
    D_800BD4CC = func_800A3C18(0xA7, 0, 0, 1, &D_8010EB90, 0, 0, 0, 0, 0, 0);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AD47C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AD534);

void func_800AD7AC(void) {
    func_80033E34(D_800B4238, D_800B423C, 0x80120000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800A4144();
    func_800A4984();
    func_80033E34(D_800B4240, D_800B4244, 0x801A0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_800B4248, D_800B424C, 0x80120000, 0);
    do {

    } while (func_80034B44() != 0);
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AD854);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AD8C8);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AD94C);

void func_800ADB20(s32 arg0, s32 arg1) {
    if (arg1 == 1) {
        D_8009A000 = 0xB0;
    }
    if (arg1 == 2) {
        D_8009A000 = 0xB1;
    }
    if (arg1 == 3) {
        D_8009A000 = 0xB2;
    }
    if (arg1 == 4) {
        D_8009A000 = 0xB3;
    }
    D_8009A004 = arg0;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ADBA0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ADC24);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ADCB4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800ADD6C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AE6B4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AE98C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AEB88);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AECE4);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AF41C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AF640);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AF858);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AF990);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AFC28);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AFE98);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800AFF0C);

void func_800B00DC(void *arg0) {
    if (M2C_SFIELD(arg0, s16 *, 0xD8) != -1) {
        D_80116684 -= 1;
        func_800A3E64(M2C_SFIELD(arg0, s32 *, 0xD4));
        func_800B017C(M2C_SFIELD(arg0, s16 *, 0xD8));
        M2C_SFIELD(arg0, s16 *, 0xD8) = -1;
        M2C_SFIELD(arg0, s16 *, 0xDA) = 0;
    }
}

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B0148);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B017C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B01AC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B05E0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B0698);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B0754);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B12B0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B1550);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B1E98);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B2760);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B29E0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B2B38);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B2E58);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B2F2C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3BFC);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3D28);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3E04);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3EC0);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B3F74);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B404C);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B4114);

INCLUDE_ASM("../asm/us/highway/nonmatchings/text", func_800B414C);

INCLUDE_RODATA("../asm/us/highway/nonmatchings/text", D_800A00D0);
