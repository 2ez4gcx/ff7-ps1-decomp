#include "common.h"
#include "snobo2/decls.h"

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0448);

void func_800A05FC(void) {
    func_800A1CC4();
    func_800A1E30();
    func_800A2EF0(0, 0, 0x10);
    func_800A71E0(0, D_80105380);
    D_800E194C = &func_800A0654;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0654);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A06CC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0910);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0C44);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A0FC0);

void func_800A10B4(void) {
    M2C_UNK *var_v1;
    s32 temp_a0;
    s32 temp_v0;

    if (D_80103958 != 0) {
        temp_a0 = D_80103960;
        D_80103960 = temp_a0 + 1;
        func_800ABC54(temp_a0);
    }
    D_801053B0 = 0;
    D_801053A0 = 0;
    func_800A1874();
    temp_v0 = D_80103954 < 0xF1;
    D_80103954 += 1;
    if (temp_v0 == 0) {
        D_80103954 = 0;
        if (D_801053A4 != 0) {
            D_80103964 = func_800A2294();
        } else {
            func_800A21FC();
        }
        var_v1 = &func_800A1194;
        if (D_801053A4 != 0) {
            var_v1 = &func_800A1280;
        }
        D_800E194C = var_v1;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1194);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1280);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A13C8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1544);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1670);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1718);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1874);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A19C4);

void func_800A1C4C(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        D_8009A000 = arg0 + 0x9F;
        D_8009A004 = arg2;
        func_8002DA7C();
    }
    D_8009A000 = arg0 + 0x27;
    D_8009A004 = 0x40;
    D_8009A008 = arg1;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1CC4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1DBC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1E30);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1EB4);

void func_800A1F58(void) {
    func_80033E74(D_800B8260, D_800B8264, 0x801F8000, 0);
    do {

    } while (func_80034B44() != 0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A1FA0);

void func_800A2050(void) {
    func_80033E74(D_800B8270, D_800B8274, 0x80178000, 0);
    do {

    } while (func_80034B44() != 0);
    func_800ACF90(0x80178000);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A20A0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2194);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A21FC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2294);

void func_800A235C(void) {
    D_800E1950 ^= 1;
    D_80105380 = D_800FB954[D_800E1950];
    func_80044244(D_80105380, 0x1000);
    D_8010538C = D_800E1954[D_800E1950];
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A23DC);

void func_800A2490(void) {
    D_80106B54 = D_800DDE88;
    D_80106B64 = D_801069CC;
    D_80106B66 = D_80106A30;
    D_80106B68 = D_801069D0;
}

void func_800A24F8(void) {
    D_800DDE88 = D_80106B54;
    D_801069CC = D_80106B64;
    D_80106A30 = D_80106B66;
    D_801069D0 = D_80106B68;
}

void func_800A2560(void) {
    void *temp_v0;

    temp_v0 = (D_801069CC * 0xC) + M2C_FIELD(D_80106AF8, s32 *, 0x1C);
    D_80106A60 = M2C_FIELD(temp_v0, s32 *, 0);
    D_80106A64 = M2C_FIELD(temp_v0, s32 *, 4);
    D_80106A68 = M2C_FIELD(temp_v0, s32 *, 8);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A25B0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2664);

void func_800A2740(void) {
    if (!(D_8010537C & 0xF)) {
        D_8009A000 = 0xD0;
        D_8009A004 = (s32) (D_800DDE78 << 0x10) >> 0x15;
        func_8002DA7C();
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2794);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A294C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A29BC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2AE8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A2EF0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A32C8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A3674);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A370C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A39AC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A3AE4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4180);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4338);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4494);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A47D0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4870);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4A78);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4B78);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4DF8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4E60);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A4FF8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A52E4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5350);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A53A0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5520);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5570);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5610);

s32 func_800A56B0(void) {
    return 1;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A56B8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5744);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A58F0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A59E0);

void func_800A5A9C(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0) = func_8003CC1C((s32) -M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 2));
    M2C_FIELD(arg1, s16 *, 2) = 0;
    M2C_FIELD(arg1, s16 *, 4) = func_8003CC1C((s32) M2C_FIELD(arg0, s16 *, 0), (s32) M2C_FIELD(arg0, s16 *, 2));
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5AF8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5C54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A5F00);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A627C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A66D0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A6854);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A68FC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A6AD4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A6E18);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7030);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7108);

void func_800A71E0(s32 arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = D_8010538C;
    M2C_FIELD(temp_s0, s32 *, 0) = 0x03000000;
    M2C_FIELD(temp_s0, s32 *, 4) = (s32) ((arg0 & 0xFFFFFF) | 0x61000000);
    M2C_FIELD(temp_s0, s32 *, 8) = 0xFF88FF60;
    M2C_FIELD(temp_s0, s32 *, 0xC) = 0xF00140;
    func_80046794(arg1, (s32) temp_s0);
    D_8010538C = temp_s0 + 0x10;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7258);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A738C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7758);

void func_800A7804(void) {
    func_800A1CC4();
    func_800A1E30();
    func_800A2EF0(0, 0, 0x10);
    func_800A71E0(0xFFFFFF, D_80105380);
    D_800E194C = &func_800A06CC;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7860);

s32 func_800A7984(void) {
    return 1;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A798C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A79E0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7A70);

s32 func_800A7AFC(void *arg0) {
    D_80103E40 = (u16) M2C_FIELD(arg0, u8 *, 1);
    return 0;
}

s32 func_800A7B10(u8 *arg0) {
    D_80103E44[arg0[1]] = 1;
    D_80103E48[arg0[1]] = 0;
    D_80103E4C[arg0[1]] = arg0[2];
    D_80103E40 += 1;
    return 0;
}

s32 func_800A7B68(void) {
    return 1;
}

s32 func_800A7B70(void *arg0) {
    D_800DDE70 = (s16) M2C_FIELD(arg0, u8 *, 1);
    return 1;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7B84);

s32 func_800A7BCC(u8 *arg0) {
    u16 pad;

    pad = D_801053A0;
    if (arg0[2] != 0) {
        pad = ~pad;
    }
    if (pad & D_800DDF54[arg0[1]]) {
        D_80103E40 += 1;
        return 0;
    }
    return 1;
}

s32 func_800A7C34(u8 *arg0) {
    if (D_80103E50 != 0) {
        D_80103E40 = arg0[D_80103E50];
    } else {
        D_80103E40 += 1;
    }
    return 0;
}

s32 func_800A7C78(u8 *arg0) {
    D_80103E44[arg0[1]] = 0;
    D_80103E40 += 1;
    return 0;
}

s32 func_800A7CA8(void *arg0) {
    D_80103E54 = M2C_FIELD(arg0, u8 *, 1);
    D_80103E40 += 1;
    return 0;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7CD0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7D48);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7E88);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A7ECC);

s32 func_800A8038(s32 arg0) {
    return arg0;
}

s32 func_800A8040(s32 arg0) {
    return (s32) (func_80039A74(((arg0 >> 2) * 2) - 0x400) + 0x1000) >> 1;
}

s32 func_800A8070(s32 arg0) {
    return 0x1000 - func_80039A74((arg0 >> 2) + 0x400);
}

s32 func_800A809C(s32 arg0) {
    return -func_80039A74((arg0 >> 2) + 0x800);
}

void func_800A80C4(void) {
    D_800D1D8E = 0;
    D_80103E2C = 0;
    D_80103E30 = 0x7F;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A80E8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8100);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A832C);

void func_800A8684(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_800DDEF4 = 0;
        D_800DDEF2 = 0;
        D_800DDEF0 = 0;
    }
    func_800A7860();
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A86C0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8804);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8AFC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8DEC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8E7C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A8FD0);

void func_800A9014(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A7860();
    func_800A9DE4(arg0);
}

void func_800A9048(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x66) = 0;
    func_800A7860();
    func_800A9DE4(arg0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A907C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9200);

void func_800A93EC(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s32 *, 0x34) = 0;
        M2C_SFIELD(arg0, s32 *, 0x3C) = 0;
        D_80103E50 = (s8) D_80103E58;
        M2C_SFIELD(arg0, s32 *, 0) = (s32) (M2C_SFIELD(arg0, s32 *, 0) | 1);
    }
    func_800A7860();
    if (D_80103E54 != 0) {
        M2C_SFIELD(arg0, s16 *, 0x76) = func_800AA140((s32) D_801053B4, M2C_SFIELD(arg0, s16 *, 0x76), 0x10);
    }
}

void func_800A946C(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
        M2C_FIELD(arg0, s32 *, 0x34) = 0;
        M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 1);
    }
    D_80103E50 = ((u32) D_801053A0 >> 0xC) & 1;
    func_800A7860();
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A94C0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A95D0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9768);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9900);

void func_800A99C8(void *arg0, s32 arg1) {
    u8 var_a0;

    if (arg1 != 0) {
        if (M2C_SFIELD(arg0, u8 *, 0xC) == 0xC) {
            M2C_SFIELD(arg0, s32 *, 0x34) = (s32) -M2C_SFIELD(arg0, s32 *, 0x34);
            M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) -M2C_SFIELD(arg0, s32 *, 0x3C);
        }
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        M2C_SFIELD(arg0, s16 *, 0x72) = 0;
        M2C_SFIELD(arg0, s32 *, 0x34) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x34) >> 1);
        M2C_SFIELD(arg0, s32 *, 0x3C) = (s32) ((s32) M2C_SFIELD(arg0, s32 *, 0x3C) >> 1);
        D_801069D4 += 2;
        if (M2C_SFIELD(arg0, s16 *, 0x14) >= 0x501) {
            var_a0 = (D_8010537C % 3) + 1;
        } else {
            var_a0 = 0;
        }
        D_80103E58 = var_a0;
    }
    if (D_80103E54 != 0) {
        func_800A9B18(arg0);
    }
    func_800A7860();
    func_800A9DE4(arg0);
}

void func_800A9AC0(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_SFIELD(arg0, s16 *, 0x66) = 0;
        D_801069D4 += 1;
    }
    func_800A9B18(arg0);
    func_800A7860();
    func_800A9DE4(arg0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9B18);

void func_800A9BB4(void *arg0) {
    func_800A7860();
    if ((D_80103E54 != 0) && (D_801053A0 & 0x1000)) {
        M2C_FIELD(arg0, s16 *, 0xC) = 2;
    }
}

void func_800A9C0C(s32 *arg0) {
    func_800A7860();
    *arg0 |= 1;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9C44);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9D20);

void func_800A9DE4(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x14) >= 0x80) {
        M2C_FIELD(arg0, s16 *, 0x76) = func_800AA140(func_8003CC1C(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x3C)) + 0x800, M2C_FIELD(arg0, s16 *, 0x76), 0x10);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800A9E40);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AA048);

s16 func_800AA140(s32 arg0, s16 arg1, s32 arg2) {
    s32 d;

    d = (arg0 & 0xFFF) - (arg1 & 0xFFF);
    if (d < 0) {
        d += 0x1000;
    }
    if (d < 0x800) {
        if (arg2 < d) {
            d = arg2;
        }
    } else {
        d -= 0x1000;
        arg2 = -arg2;
        if (d < arg2) {
            d = arg2;
        }
    }
    return (arg1 + d) & 0xFFF;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AA188);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AA2D4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AA440);

void func_800AB494(void) {
    func_80044A68(&D_80103E60, 1, 0, func_8004656C(0, 0, 0x180, 0x100) & 0xFFFF, 0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AB4DC);

INCLUDE_RODATA("../asm/us/snobo2/nonmatchings/text", D_800A0094);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AB700);

void func_800AB868(void *arg0, u32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s8 *, 0) = (s8) (arg2 + (arg1 >> 0x1C));
    M2C_FIELD(arg0, s8 *, 1) = (s8) (arg2 + ((arg1 >> 0x18) & 0xF));
    M2C_FIELD(arg0, s8 *, 3) = (s8) (arg2 + ((arg1 >> 0x14) & 0xF));
    M2C_FIELD(arg0, s8 *, 4) = (s8) (arg2 + ((arg1 >> 0x10) & 0xF));
    M2C_FIELD(arg0, s8 *, 6) = (s8) (arg2 + ((arg1 >> 0xC) & 0xF));
    M2C_FIELD(arg0, s8 *, 7) = (s8) (arg2 + ((arg1 >> 8) & 0xF));
    M2C_FIELD(arg0, s8 *, 8) = (s8) (arg2 + ((arg1 >> 4) & 0xF));
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AB8D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AB9AC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABB50);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABC54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABD5C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABE64);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ABF3C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AC1C8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AC42C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AC580);

void *func_800AC914(void *arg0, void *arg1, s32 *arg2) {
    M2C_FIELD(arg1, s32 *, 0) = 0x06000000;
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x4C000000);
    M2C_FIELD(arg1, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s16 *, 0x8A) << 0x10) | M2C_FIELD(arg0, u16 *, 0x88));
    M2C_FIELD(arg1, s32 *, 0xC) = (s32) ((M2C_FIELD(arg0, s16 *, 0x8E) << 0x10) | M2C_FIELD(arg0, u16 *, 0x8C));
    M2C_FIELD(arg1, s32 *, 0x10) = (s32) ((M2C_FIELD(arg0, s16 *, 0x92) << 0x10) | M2C_FIELD(arg0, u16 *, 0x90));
    M2C_FIELD(arg1, s32 *, 0x14) = (s32) ((M2C_FIELD(arg0, s16 *, 0x96) << 0x10) | M2C_FIELD(arg0, u16 *, 0x94));
    M2C_FIELD(arg1, s32 *, 0x18) = 0x55555555;
    M2C_FIELD(arg1, s32 *, 0) = (s32) ((M2C_FIELD(arg1, s32 *, 0) & 0xFF000000) | (*arg2 & 0xFFFFFF));
    *arg2 = (*arg2 & 0xFF000000) | ((s32) arg1 & 0xFFFFFF);
    return arg1 + 0x1C;
}

void *func_800AC9C8(void *arg0, void *arg1, s32 *arg2) {
    M2C_FIELD(arg1, s32 *, 0) = 0x02000000;
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 0) | 0x68000000);
    M2C_FIELD(arg1, s32 *, 8) = (s32) ((M2C_FIELD(arg0, s16 *, 0x8A) << 0x10) | M2C_FIELD(arg0, u16 *, 0x88));
    M2C_FIELD(arg1, s32 *, 0) = (s32) ((M2C_FIELD(arg1, s32 *, 0) & 0xFF000000) | (*arg2 & 0xFFFFFF));
    *arg2 = (*arg2 & 0xFF000000) | ((s32) arg1 & 0xFFFFFF);
    return arg1 + 0xC;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ACA34);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ACAA4);

void func_800ACB2C(void) {
    SbUnkFFC40 *p;
    s32 i;

    D_80103F6C = 0;
    p = D_80103E6C;
    for (i = 7; i != -1; i--) {
        p->unk0 = 0;
        p++;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ACB5C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ACCBC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ACF90);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD00C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD15C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD2C8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD4C4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD714);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AD958);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ADBD8);

void func_800ADD64(void *arg0) {
    void (*var_v0)(void *);

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        D_80105374 = M2C_FIELD(arg0, u16 *, 2);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFD8000;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            func_800A1C4C(3, 0xF0, 0);
            var_v0 = func_800ADDFC;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        } else {
            var_v0 = func_800B43C8;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = var_v0;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ADDFC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800ADE94);

void func_800AE024(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1C4C(3, 0xF0, 0);
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AE0B0;
        } else {
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) == 2) {
        func_800AE138(arg0);
    }
}

void func_800AE0B0(void *arg0) {
    u16 temp_v0;
    u16 temp_v1;

    M2C_FIELD(arg0, s16 *, 0x1E) = (s16) ((s32) -func_80039A74(func_80039A74(M2C_FIELD(arg0, s16 *, 0x84) << 5) >> 4) >> 3);
    temp_v1 = (u16) M2C_FIELD(arg0, s16 *, 0x84);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v1 + 1);
    if ((s16) temp_v1 >= 0x79) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0 + 1);
        if ((s16) temp_v0 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800AE138(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_v0 + 1);
    M2C_FIELD(arg0, s16 *, 0x22) = (s16) (func_80039A74(func_80039A74((s32) (temp_v0 << 0x10) >> 0xB) >> 4) >> 3);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE18C);

void func_800AE324(void *arg0) {
    s32 var_v1;

    if ((M2C_FIELD(arg0, s32 *, 0x30) - D_800DDE90) <= 0x700000) {
        var_v1 = (s32) D_800DDEA0 >> 1;
        if (var_v1 <= 0x7FFF) {
            var_v1 = 0x8000;
        }
        M2C_FIELD(arg0, s32 *, 0x74) = var_v1;
        if (M2C_FIELD(arg0, s16 *, 0x84) != 0) {
            var_v1 = -var_v1;
        }
        M2C_FIELD(arg0, s16 *, 0x14) = 0x40;
        M2C_FIELD(arg0, s32 *, 0x6C) = var_v1;
        M2C_FIELD(arg0, s16 *, 0x8A) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AE3A4;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE3A4);

void func_800AE534(void *arg0) {
    s32 var_v0;
    s32 var_v0_2;

    var_v0 = M2C_FIELD(arg0, s32 *, 0x7C) * 3;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    if (var_v0 < 0) {
        var_v0 += 3;
    }
    M2C_FIELD(arg0, s32 *, 0x6C) = (s32) (var_v0 >> 2);
    M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
    var_v0_2 = M2C_FIELD(arg0, s32 *, 0x80) * 3;
    if (var_v0_2 < 0) {
        var_v0_2 += 3;
    }
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) (var_v0_2 >> 2);
    M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AE5B0;
    func_800A1C4C(3, 0x135, 0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE5B0);

void func_800AE8A8(void *arg0) {
    s32 temp_v0_3;
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0x200);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE944);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AE9D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AEAD0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AEC70);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AECBC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AEEAC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF040);

void func_800AF1D8(void *arg0) {
    s32 var_v1;

    if ((M2C_FIELD(arg0, s32 *, 0x30) - D_800DDE90) <= 0x700000) {
        var_v1 = (s32) D_800DDEA0 >> 1;
        if (var_v1 <= 0x7FFF) {
            var_v1 = 0x8000;
        }
        M2C_FIELD(arg0, s32 *, 0x74) = var_v1;
        if (M2C_FIELD(arg0, s16 *, 0x84) != 0) {
            var_v1 = -var_v1;
        }
        M2C_FIELD(arg0, s16 *, 0x14) = 0x40;
        M2C_FIELD(arg0, s32 *, 0x6C) = var_v1;
        M2C_FIELD(arg0, s16 *, 0x8A) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800AF258;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF258);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF3D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF5EC);

void func_800AF7D4(void *arg0) {
    s32 temp_v0_3;
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - 0x200);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AF868);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFA08);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFA54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFBE8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFD7C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800AFEFC);

void func_800B01EC(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x29) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) + 0x1000);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B027C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0748);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0788);

void func_800B0888(void *arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
            M2C_FIELD(arg0, s16 *, 4) = 0xCA;
            M2C_FIELD(arg0, s16 *, 6) = 0xD0;
            M2C_FIELD(arg0, u8 *, 1) = 0U;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            *M2C_FIELD(arg0, s8 **, 0x3C) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800AF5EC;
            func_800A1C4C(3, 0x135, 0);
            return;
        }
        M2C_FIELD(arg0, u16 *, 0x84) = 0U;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B0960;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84) + 1;
    M2C_FIELD(arg0, u16 *, 0x84) = temp_v0;
    if ((s16) temp_v0 == 0x3D) {
        M2C_FIELD(arg0, s16 *, 4) = 0xD8;
        M2C_FIELD(arg0, s16 *, 6) = 0xD9;
    }
}

void func_800B0960(void *arg0) {
    u16 temp_a1;
    u16 temp_v0;
    u16 temp_v0_2;
    void *temp_v1;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        temp_v1 = M2C_FIELD(arg0, void **, 0x3C);
        temp_a1 = temp_v0_2 + 1;
        M2C_FIELD(arg0, u16 *, 0x8A) = temp_a1;
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            M2C_FIELD(temp_v1, s8 *, 0) = 0;
            return;
        }
        M2C_FIELD(temp_v1, u16 *, 0x8A) = temp_a1;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B09B8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0AE4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0BA8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0CF0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0E54);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B0FE4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B1248);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B1588);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B15C8);

void func_800B192C(void *arg0) {
    s32 temp_v0_3;
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_SFIELD(arg0, u16 *, 0x84);
    M2C_SFIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_SFIELD(arg0, u16 *, 0x8A);
        M2C_SFIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_SFIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    M2C_SFIELD(arg0, s32 *, 0x28) = (s32) (M2C_SFIELD(arg0, s32 *, 0x28) + M2C_SFIELD(arg0, s32 *, 0x6C));
    M2C_SFIELD(arg0, s16 *, 0x24) = 0;
    M2C_SFIELD(arg0, u16 *, 2) = (u16) D_80106A30;
    temp_v0_3 = M2C_SFIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_SFIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_SFIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_SFIELD(arg0, s32 *, 0x2C));
    M2C_SFIELD(arg0, s32 *, 0x30) = (s32) (M2C_SFIELD(arg0, s32 *, 0x30) + M2C_SFIELD(arg0, s32 *, 0x74));
    M2C_SFIELD(arg0, u16 *, 0x1E) = (u16) (M2C_SFIELD(arg0, u16 *, 0x1E) + 0x80);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B19D4);

void func_800B1B60(void *arg0) {
    u16 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            func_800B1C7C(arg0);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
        goto block_4;
    }
block_4:
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x10) {
        M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFF0000;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B1BEC;
    }
}

void func_800B1BEC(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (M2C_FIELD(arg0, u8 *, 1) & 2) {
        func_800B1C7C(arg0);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0;
    temp_v0_2 = temp_v0 + M2C_FIELD(arg0, s32 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x2C) = temp_v0_2;
    if (M2C_FIELD(arg0, s32 *, 0x34) < temp_v0_2) {
        M2C_FIELD(arg0, s16 *, 6) = 0xE5;
        M2C_FIELD(arg0, s16 *, 0x84) = 0;
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B1B60;
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
        return;
    }
    M2C_FIELD(arg0, s16 *, 6) = 0xD0;
}

void func_800B1C7C(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0) = 2;
    M2C_FIELD(arg0, s32 *, 0x70) = 0xFFFE0000;
    M2C_FIELD(arg0, s16 *, 0x84) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B1CD8;
    M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
    M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
    func_800A1C4C(3, 0x135, 0);
}

void func_800B1CD8(void *arg0) {
    s32 temp_v0_3;
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s32 *, 0x6C));
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x70) + 0x1000;
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0_3 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x74));
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + 0x80);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B1D74);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B1F34);

void func_800B2084(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x88);
    M2C_FIELD(arg0, u16 *, 0x88) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
            return;
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0_3 + 1);
    M2C_FIELD(arg0, s16 *, 4) = (s16) (((temp_v0_3 >> 3) & 3) + 0xB8);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) - 0x800);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2110);

void func_800B220C(void *arg0) {
    u16 temp_v0;

    func_800ABB50(M2C_FIELD(arg0, s16 *, 0x84));
    temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 0x84);
    M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2260);

void func_800B235C(void *arg0) {
    u16 temp_v0;

    func_800ABD5C(M2C_FIELD(arg0, s16 *, 0x84));
    temp_v0 = (u16) M2C_FIELD(arg0, s16 *, 0x84);
    M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        M2C_FIELD(arg0, s8 *, 0) = 0;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B23B0);

void func_800B2534(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B25A0;
            func_800A1C4C(1, 0x10C, 0x7F);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

void func_800B25A0(void *arg0) {
    u16 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_a0 + 1);
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - (func_80039A74((s32) (temp_a0 << 0x10) >> 0x11) >> 2));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) < -0x480) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2610);

void func_800B2794(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B2800;
            func_800A1C4C(1, 0x10C, 0x7F);
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

void func_800B2800(void *arg0) {
    u16 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u16 *, 0x86);
    M2C_FIELD(arg0, u16 *, 0x86) = (u16) (temp_a0 + 1);
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + (func_80039A74((s32) (temp_a0 << 0x10) >> 0x11) >> 2));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) >= 0x481) {
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2870);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B29EC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2B60);

void func_800B2D0C(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1C4C(2, 0x10C, 0);
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2D70);

void func_800B2EE4(void *arg0) {
    void (*var_v1)(void *);

    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            func_800A1C4C(2, 0x10C, 0);
            var_v1 = func_800B2FB4;
            if ((u16) D_801053B4 & 0x800) {
                var_v1 = func_800B2F74;
            }
            M2C_FIELD(arg0, void (**)(void *), 0x38) = var_v1;
            return;
        }
        M2C_FIELD(arg0, void (**)(void *), 0x38) = func_800B43C8;
    }
}

void func_800B2F74(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84) + 8;
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) - temp_v0);
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, u16 *, 0x84) = temp_v0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) < -0x500) {
        M2C_FIELD(arg0, u16 *, 0x84) = 0U;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B43C8;
    }
}

void func_800B2FB4(void *arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84) + 8;
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (temp_v0 + M2C_FIELD(arg0, u16 *, 0x1E));
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, u16 *, 0x84) = temp_v0;
    if ((s16) M2C_FIELD(arg0, u16 *, 0x1E) >= 0x501) {
        M2C_FIELD(arg0, u16 *, 0x84) = 0U;
        M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B43C8;
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B2FF4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B31D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B32B0);

void func_800B3370(void *arg0) {
    s16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x84);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v0 - 1);
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            func_800A1C4C(2, 0xF0, 0);
            M2C_FIELD(arg0, u8 *, 1) = 0U;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, s16 *, 0x14) = 0;
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B33F8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B3598);

s32 func_800B3664(void *arg0) {
    s16 temp_v1;
    u16 temp_v0;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x84);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, s16 *, 0x84) = (s16) (temp_v1 + 1);
        if (temp_v1 >= 0x3D) {
            temp_v0 = M2C_FIELD(arg0, u16 *, 0x8A);
            M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0 + 1);
            if ((s16) temp_v0 >= 0x1F) {
                M2C_FIELD(arg0, s8 *, 0) = 0;
                return 1;
            }
            goto block_8;
        }
        
        return 0;
    }
    if (M2C_FIELD(arg0, u8 *, 1) != 0) {
        if (M2C_FIELD(arg0, u8 *, 1) & 2) {
            M2C_FIELD(arg0, s16 *, 0x84) = 0;
            M2C_FIELD(arg0, s16 *, 0x14) = 0;
            M2C_FIELD(arg0, M2C_UNK **, 0x38) = &func_800B3738;
            M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
            func_800A1C4C(2, 0x10C, 0);
            return 1;
        }
        M2C_FIELD(arg0, s16 *, 0x84) = 1;
block_8:
        
        return 0;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B3738);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B37E8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B398C);

void func_800B3AB4(void) {
    s32 var_v1;

    var_v1 = D_800DDE9C;
    D_800DDE70 = 0xB;
    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }
    if (var_v1 <= 0x3FFFF) {
        var_v1 = 0x40000;
    }
    D_800DDE9C = var_v1;
    func_800A1C4C(2, 0x10C, 0);
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B3B14);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B3B44);

void func_800B3BB4(void) {
    s32 var_v0;
    s8 *var_v1;

    var_v1 = &D_80103F70;
    var_v0 = 0x1F;
    do {
        *var_v1 = 0;
        var_v0 -= 1;
        var_v1 += 0x8C;
    } while (var_v0 != -1);
    D_801050F0 = 0;
    D_80105378 = 0;
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B3BEC);

void func_800B43C8(void *arg0) {
    u16 temp_v0;
    u16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x84);
    M2C_FIELD(arg0, u16 *, 0x84) = (u16) (temp_v0 + 1);
    if ((s16) temp_v0 >= 0x3D) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0x8A) = (u16) (temp_v0_2 + 1);
        if ((s16) temp_v0_2 >= 0x1F) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        }
    }
}

void func_800B4414(s16 arg0, s32 arg1) {
    if ((arg1 != 0) && ((u8) D_80106AF6 >= 0x46U)) {
        func_800B1D74(arg0, &D_800E01C0);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4458);

void func_800B4524(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E01E4);
    }
}

void func_800B4554(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E01F0);
    }
}

void func_800B4584(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E01FC);
    }
}

void func_800B45B4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0208);
    }
}

void func_800B45E4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0214);
    }
}

void func_800B4614(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0220);
    }
}

void func_800B4644(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E022C);
    }
}

void func_800B4674(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0238);
    }
}

void func_800B46A4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0244);
    }
}

void func_800B46D4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0250);
    }
}

void func_800B4704(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E025C);
    }
}

void func_800B4734(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0268);
    }
}

void func_800B4764(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0274);
    }
}

void func_800B4794(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0280);
    }
}

void func_800B47C4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E028C);
    }
}

void func_800B47F4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0298);
    }
}

void func_800B4824(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E02A4);
    }
}

void func_800B4854(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E02B0);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4884);

void func_800B48E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E02DC);
    }
}

void func_800B4918(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E02E8);
    }
}

void func_800B4948(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E02F4);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4978);

void func_800B4A54(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AE18C(arg0, &D_800E030C);
        func_800B23B0(arg0, &D_800E0314);
    }
}

void func_800B4AA0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AE18C(arg0, &D_800E0320);
        func_800B23B0(arg0, &D_800E0328);
    }
}

void func_800B4AEC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0334);
    }
}

void func_800B4B1C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0340);
        func_800AEAD0(arg0, &D_800E034C);
    }
}

void func_800B4B68(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0358);
        func_800AEAD0(arg0, &D_800E0364);
    }
}

void func_800B4BB4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0370);
    }
}

void func_800B4BE4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E037C);
    }
}

void func_800B4C14(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0388);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4C44);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4CA4);

void func_800B4D04(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AF040(arg0, &D_800E0404);
        func_800B23B0(arg0, &D_800E040C);
    }
}

void func_800B4D50(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AF040(arg0, &D_800E0418);
        func_800B23B0(arg0, &D_800E0420);
    }
}

void func_800B4D9C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E042C);
    }
}

void func_800B4DCC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0438);
    }
}

void func_800B4DFC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0444);
        func_800AF868(arg0, &D_800E0450);
    }
}

void func_800B4E48(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E045C);
        func_800AF868(arg0, &D_800E0468);
    }
}

void func_800B4E94(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0474);
        func_800AF868(arg0, &D_800E0480);
    }
}

void func_800B4EE0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E048C);
    }
}

void func_800B4F10(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800AFD7C(arg0, &D_800E0498);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4F40);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4F94);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B4FE8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B503C);

void func_800B5118(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E04EC);
    }
}

void func_800B5148(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E04F8);
    }
}

void func_800B5178(s16 arg0, s32 arg1) {
    if ((arg1 != 0) && (D_800C828E != 0)) {
        func_800B2870(arg0, &D_800E0504);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B51B8);

void func_800B52A4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E053C);
        func_800B1D74(arg0, &D_800E0544);
    }
}

void func_800B52F0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0550);
    }
}

void func_800B5320(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0558);
    }
}

void func_800B5350(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0560);
    }
}

void func_800B5380(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0568);
        func_800B1D74(arg0, &D_800E0570);
    }
}

void func_800B53CC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E057C);
    }
}

void func_800B53FC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B29EC(arg0, &D_800E0584);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B542C);

void func_800B5480(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E059C);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B54B0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5544);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B55D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B566C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5700);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5794);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5844);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B58D8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B596C);

void func_800B5A00(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E05FC);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5A30);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5AC4);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5B7C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5C10);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5CC8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5D5C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5E14);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5ECC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B5F60);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6028);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B60BC);

void func_800B6150(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0698);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6180);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6244);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B62AC);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6340);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6404);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B646C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6500);

void func_800B65C4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0704);
    }
}

void func_800B65F4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0710);
    }
}

void func_800B6624(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E071C);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6654);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B66B8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B670C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6760);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B67B4);

void func_800B6808(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B37E8(arg0, &D_800E07B8);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6838);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B688C);

void func_800B6900(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADE94(arg0, &D_800E0810);
    }
}

void func_800B6930(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E081C);
    }
}

void func_800B6960(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0828);
    }
}

void func_800B6990(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0834);
    }
}

void func_800B69C0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0840);
        func_800ADBD8(arg0, &D_800E084C);
    }
}

void func_800B6A0C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0858);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6A3C);

void func_800B6AA0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0884);
    }
}

void func_800B6AD0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0890);
    }
}

void func_800B6B00(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E089C);
    }
}

void func_800B6B30(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08A8);
    }
}

void func_800B6B60(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08B4);
    }
}

void func_800B6B90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08C0);
    }
}

void func_800B6BC0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E08CC);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6BF0);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6C44);

void func_800B6CA8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E090C);
    }
}

void func_800B6CD8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0918);
    }
}

void func_800B6D08(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0924);
    }
}

void func_800B6D38(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0930);
    }
}

void func_800B6D68(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E093C);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B6D98);

void func_800B6DEC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E095C);
    }
}

void func_800B6E1C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0968);
    }
}

void func_800B6E4C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2610(arg0, &D_800E0974);
    }
}

void func_800B6E7C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0980);
        func_800ADE94(arg0, &D_800E098C);
    }
}

void func_800B6EC8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0998);
    }
}

void func_800B6EF8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09A4);
    }
}

void func_800B6F28(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E09B0);
    }
}

void func_800B6F58(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09BC);
    }
}

void func_800B6F88(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADE94(arg0, &D_800E09C8);
    }
}

void func_800B6FB8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09D4);
    }
}

void func_800B6FE8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E09E0);
    }
}

void func_800B7018(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E09EC);
    }
}

void func_800B7048(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADE94(arg0, &D_800E09F8);
    }
}

void func_800B7078(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E0A04);
    }
}

void func_800B70A8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A10);
    }
}

void func_800B70D8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E0A1C);
    }
}

void func_800B7108(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A28);
    }
}

void func_800B7138(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A34);
    }
}

void func_800B7168(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A40);
    }
}

void func_800B7198(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A4C);
    }
}

void func_800B71C8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B19D4(arg0, &D_800E0A58);
    }
}

void func_800B71F8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0A64);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B7228);

void func_800B727C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0A84);
    }
}

void func_800B72AC(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E0A90);
    }
}

void func_800B72DC(s16 arg0, s32 arg1) {
    if ((arg1 != 0) && (D_800C82CE != 0)) {
        func_800B2870(arg0, &D_800E0A9C);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B731C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B73E8);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B743C);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B7490);

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B74E4);

void func_800B7538(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B10);
    }
}

void func_800B7568(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B1C);
    }
}

void func_800B7598(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B28);
    }
}

void func_800B75C8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B34);
    }
}

void func_800B75F8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B40);
    }
}

void func_800B7628(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0B4C);
    }
}

void func_800B7658(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0B58);
    }
}

void func_800B7688(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B64);
    }
}

void func_800B76B8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B74);
    }
}

void func_800B76E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B84);
    }
}

void func_800B7718(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0B94);
    }
}

void func_800B7748(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BA4);
    }
}

void func_800B7778(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BB4);
    }
}

void func_800B77A8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BC4);
    }
}

void func_800B77D8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BD4);
    }
}

void func_800B7808(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BE4);
    }
}

void func_800B7838(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0BF4);
    }
}

void func_800B7868(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C04);
    }
}

void func_800B7898(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C14);
    }
}

void func_800B78C8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C24);
    }
}

void func_800B78F8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C34);
    }
}

void func_800B7928(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C44);
    }
}

void func_800B7958(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C54);
    }
}

void func_800B7988(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C64);
    }
}

void func_800B79B8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C74);
    }
}

void func_800B79E8(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0C84);
        func_800B1D74(arg0, &D_800E0C94);
    }
}

void func_800B7A34(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CA0);
    }
}

void func_800B7A64(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CB0);
    }
}

void func_800B7A94(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CC0);
    }
}

void func_800B7AC4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2FF4(arg0, &D_800E0CD0);
        func_800B1D74(arg0, &D_800E0CE0);
    }
}

void func_800B7B10(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0CEC);
    }
}

void func_800B7B40(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0CF8);
    }
}

void func_800B7B70(void) {
}

void func_800B7B78(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D04);
        func_800B1D74(arg0, &D_800E0D10);
    }
}

void func_800B7BC4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D1C);
    }
}

void func_800B7BF4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D28);
    }
}

void func_800B7C24(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D34);
    }
}

void func_800B7C54(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0D40);
    }
}

void func_800B7C84(void) {
}

void func_800B7C8C(void) {
}

void func_800B7C94(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D4C);
    }
}

void func_800B7CC4(void) {
}

void func_800B7CCC(void) {
}

void func_800B7CD4(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D58);
    }
}

void func_800B7D04(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D64);
        func_800B1D74(arg0, &D_800E0D70);
    }
}

void func_800B7D50(void) {
}

void func_800B7D58(void) {
}

void func_800B7D60(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D7C);
    }
}

void func_800B7D90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2B60(arg0, &D_800E0D88);
        func_800B1D74(arg0, &D_800E0D94);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B7DDC);

void func_800B7E30(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DB4);
    }
}

void func_800B7E60(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0DC0);
    }
}

void func_800B7E90(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DCC);
    }
}

void func_800B7EC0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DD8);
    }
}

void func_800B7EF0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0DE4);
    }
}

void func_800B7F20(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DF0);
    }
}

void func_800B7F50(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0DFC);
    }
}

void func_800B7F80(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0E08);
    }
}

void func_800B7FB0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800ADBD8(arg0, &D_800E0E14);
    }
}

void func_800B7FE0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0E20);
    }
}

void func_800B8010(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0E2C);
        func_800B1D74(arg0, &D_800E0E3C);
    }
}

void func_800B805C(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0E48);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B808C);

void func_800B80F0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0E84);
    }
}

INCLUDE_ASM("../asm/us/snobo2/nonmatchings/text", func_800B8120);

void func_800B8184(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0EC0);
        func_800B1D74(arg0, &D_800E0ED0);
    }
}

void func_800B81D0(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1248(arg0, &D_800E0EDC);
    }
}

void func_800B8200(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B1D74(arg0, &D_800E0EEC);
    }
}

void func_800B8230(s16 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800B2870(arg0, &D_800E0EF8);
    }
}
