#include "common.h"
#include "world/decls.h"

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A0BE4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A0C54);

void func_800A0D1C(void) {
    D_800E55EC = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A0D2C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A12AC);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A0000);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0028);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A01C0);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A01D8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A01E0);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A01E8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A01F8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A0260);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0268);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A02C0);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A05F0);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0748);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A0768);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0770);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A07C8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0828);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A08C8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A08D8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A090C);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A091C);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0930);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0970);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A09AC);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A09BC);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A09C8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A09D0);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", D_800A09D8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A09E0);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0A48);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0AA8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", jtbl_800A0AE8);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", func_800A0B40);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A1370);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A141C);

void func_800A16D0(s32 arg0) {
    D_800E5630 = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A16E0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A1710);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A19FC);

s32 func_800A1D04(void) {
    return D_800E5648;
}

s32 func_800A1D14(void) {
    return D_800E560C & 0xFFF;
}

void func_800A1D24(s32 arg0) {
    D_800E5608 = arg0 & 0xFFF;
}

void func_800A1D38(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFF;
    D_800E5608 = temp_a0;
    D_800E560C = temp_a0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A1D54);

s32 func_800A1DB0(void) {
    return D_800E5618;
}

s32 func_800A1DC0(void) {
    return D_800E5654;
}

void func_800A1DD0(s32 arg0) {
    D_800E5654 = arg0;
}

s32 func_800A1DE0(void) {
    return D_800E5634;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A1DF0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A1FAC);

void func_800A2040(void) {
    func_8003B48C(&D_800E5698);
    func_8003B51C(&D_800E56B8);
}

s16 func_800A2078(void) {
    return D_800E56D8;
}

void func_800A2088(s32 arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = D_800E5648;
    D_800E5648 = arg0;
    D_800E5650 = temp_v0;
    if (((u32) arg0 < 2U) && (D_800E5634 != 3)) {
        D_800E5608 = 0;
    }
    var_v1 = 0xA0;
    if (D_800E5648 == 0) {
        var_v1 = 0x78;
    }
    D_800E564C = var_v1;
    D_800E5604 = -(D_800E5648 != 3) & 0x78;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A2108);

s32 func_800A21A4(void) {
    return D_800E55FC;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A21B4);

void func_800A31C0(s16 arg0) {
    s32 t;
    t = D_800E5608 - 0x800;
    D_800E5668 = arg0 + t;
}

s32 func_800A31E8(void) {
    return D_800E5628 == 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A31F8);

s32 func_800A32F4(void) {
    return D_800E5678;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A3304);

void func_800A368C(s32 arg0) {
    D_800E5658 = arg0;
}

s32 func_800A369C(void) {
    return D_800E5658;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A36AC);

void func_800A38C8(void) {
    if (D_80071E34 == 1) {
        func_800260DC();
        func_80026090();
        D_80071E34 = 0;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A3908);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A3964);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A3C74);

void func_800A3DFC(void) {
    D_800E566C = 5;
    D_800E5644 = 0x14;
    func_800B7714(0);
    func_800A2108(0, 0);
    func_800B0098(0x10, 1);
}

void func_800A3E4C(void) {
    D_800E566C = 4;
    D_800E5644 = -0x14;
    func_800B7714(0);
    func_800A2108(0, 0);
    func_800B0098(0x10, 1);
}

void func_800A3E9C(void) {
    func_800B7714();
    D_800E566C = 8;
}

void func_800A3EC8(s32 arg0) {
    if (D_800E566C <= 0) {
        D_800E563C = 0;
        D_800E5638 = 0;
        D_800E55F4 = 1;
        D_800E566C = 1;
    }
    if (D_800E566C == 1) {
        D_800E566C = 3;
        func_800A2108(0, 0);
        func_800B7714(arg0);
    }
}

void func_800A3F4C(s32 arg0) {
    if (D_800E566C <= 0) {
        D_800E563C = 0;
        D_800E5638 = 0;
        D_800E55F4 = 1;
        D_800E566C = 1;
    }
    if ((u32) (D_800E566C - 1) < 2U) {
        if (D_80071E30 == 0) {
            D_800E566C = 3;
            func_800A2108(0, 0);
            func_800B77A8(arg0);
            return;
        }
        D_800E5670 = 0x1E;
        func_800B7C44();
    }
}

void func_800A4008(void) {
    if (D_800E566C <= 0) {
        D_800E563C = 0;
        D_800E5638 = 0;
        D_800E55F4 = 1;
        D_800E566C = 1;
    }
    if (D_800E566C == 1) {
        D_800E566C = 3;
        func_800A2108(0, 0);
        func_800B7838();
    }
}

s32 func_800A4080(void) {
    return (D_800E5648 & 3) | ((func_800BCA38() * 4) & 0xC);
}

void func_800A40B8(s32 arg0) {
    func_800A2088(arg0 & 3);
    func_800BC9E8((arg0 >> 2) & 3);
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A40F0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A4138);

void func_800A41E8(s32 arg0) {
    s32 var_s0;

    var_s0 = arg0;
    switch (var_s0) {
    case 1:
        func_800A2108(0, 4);
        func_800B0098(4, 1);
        break;
    case 4:
        func_800A2108(1, 4);
        func_800AFFBC(0x10, 1);
        var_s0 = 0;
        break;
    }
    D_800E56F4 = var_s0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A4268);

void func_800A4494(s32 arg0) {
    D_800E561C = arg0;
}

void func_800A44A4(s32 arg0) {
    D_800E5620 = arg0;
}

void func_800A44B4(s32 arg0) {
    D_800E5624 = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A44C4);

void func_800A45C4(s32 arg0) {
    D_800E5638 = arg0;
}

void func_800A45D4(s32 arg0) {
    D_800E563C = arg0;
}

void func_800A45E4(s32 arg0) {
    D_800E5674 = arg0;
}

s32 func_800A45F4(void) {
    return D_800E5674;
}

void func_800A4604(void) {
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A460C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A4DDC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A4F08);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A4F78);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5208);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A52A4);

void func_800A5348(M2C_UNK *arg0, M2C_UNK **arg1) {
    M2C_UNK *temp_v0;

    if (arg1 != NULL) {
        *arg1 = *arg0;
    } else {
        D_800E5810 = *arg0;
    }
    func_800A54F0(arg0);
    temp_v0 = D_800E580C;
    D_800E580C = arg0;
    *arg0 = temp_v0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A53A8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A54F0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A57C8);

void func_800A5924(void) {
    if (D_800E5820 >= 0) {
        D_800E5814 = (D_8011650C * 5) - 1;
        func_800ADD4C(0);
    }
}

s16 func_800A5970(void) {
    M2C_UNK *var_v1;
    s16 var_v0;

    var_v1 = D_800E5768;
    var_v0 = 0;
    if (var_v1 != NULL) {
        do {
            var_v1 = *var_v1;
            var_v0 += 1;
        } while (var_v1 != NULL);
    }
    return var_v0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A59A0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5A20);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5A94);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5AD8);

void func_800A5B88(void *arg0) {
    void *var_s0;

    var_s0 = D_80109D40;
    if (var_s0 != NULL) {
        do {
            if (((((s32) (M2C_FIELD(var_s0, u16 *, 0x12) << 0x10) >> 0x12) * 9) + ((s32) (M2C_FIELD(var_s0, u16 *, 0x10) << 0x10) >> 0x12)) == M2C_FIELD(arg0, s16 *, 4)) {
                func_800A5AD8(var_s0);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0);
        } while (var_s0 != NULL);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5C08);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5D00);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5E28);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A5FB4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A60D8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6168);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A63FC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A64AC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A67A8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6884);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A692C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6994);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6B8C);

void func_800A6BCC(s32 arg0) {
    if (arg0 != 0) {
        func_800A6884(&D_80109D44, arg0, 0, 0);
    }
}

void func_800A6C00(s32 arg0) {
    if (func_800A1DB0() != 2) {
        func_800A1FAC(arg0);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6C3C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A6FC0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A71E8);

s32 func_800A7E7C(void) {
    return D_80109D6C;
}

void func_800A7E8C(s32 arg0) {
    D_80109D6C = arg0;
}

void func_800A7E9C(void) {
}

void func_800A7EA4(void) {
    func_800A4DDC();
    func_800A59A0();
    func_800A60D8();
    D_80109D54 = 0;
    D_80109D58 = 0;
    D_80109D5C = 0;
    D_80109D60 = 0;
    D_800E5828 = 1;
    D_80109D64 = 0;
    D_80109D68 = 0;
    D_80109D6C = 0;
}

void func_800A7F18(void) {
    func_800A7F38();
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A7F38);

void func_800A8048(void) {
    D_800E5828 = 1;
}

s32 func_800A805C(void) {
    return D_800E5828;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A806C);

void func_800A82DC(void) {
    D_80109D54 = 1;
}

s32 func_800A82F0(void) {
    return D_80109D58;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A8300);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A835C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A86C4);

void func_800A886C(s32 arg0) {
    D_80109D64 = 2;
    D_80109D68 = arg0;
}

void func_800A8888(s32 arg0) {
    D_800E5824 = arg0;
}

void func_800A8898(void *arg0) {
    s32 temp_v0;
    void *temp_a1;
    void *temp_a2;
    void *temp_v1;

    temp_v0 = M2C_FIELD(D_80109D5C, s32 *, 0xC);
    temp_a2 = (M2C_FIELD(D_80109D60, u8 *, 0) * 8) + temp_v0;
    temp_a1 = (M2C_FIELD(D_80109D60, u8 *, 1) * 8) + temp_v0;
    temp_v1 = (M2C_FIELD(D_80109D60, u8 *, 2) * 8) + temp_v0;
    M2C_FIELD(arg0, s32 *, 0) = (s32) (M2C_FIELD(temp_a2, s16 *, 0) + M2C_FIELD(temp_a1, s16 *, 0) + M2C_FIELD(temp_v1, s16 *, 0));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(temp_a2, s16 *, 2) + M2C_FIELD(temp_a1, s16 *, 2) + M2C_FIELD(temp_v1, s16 *, 2));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(temp_a2, s16 *, 4) + M2C_FIELD(temp_a1, s16 *, 4) + M2C_FIELD(temp_v1, s16 *, 4));
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A891C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A8A1C);

void func_800A8A88(void) {
    void *var_v0;

    var_v0 = D_8010AD38;
    if (var_v0 != NULL) {
        do {
            M2C_FIELD(var_v0, s8 *, 0x5E) = -1;
            var_v0 = M2C_FIELD(var_v0, void **, 0);
        } while (var_v0 != NULL);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A8ABC);

void func_800A8AF4(M2C_UNK *arg0) {
    M2C_UNK *temp_v0;

    func_800A8B30();
    temp_v0 = D_8010AD34;
    D_8010AD34 = arg0;
    *arg0 = temp_v0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A8B30);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A8C70);

s32 func_800A8CA4(void) {
    u8 *var_v1;

    var_v1 = D_8010AD38;
    if (var_v1 != NULL) {
loop_1:
        if ((u8) M2C_FIELD(var_v1, u8 *, 0x50) < 0x20U) {
            var_v1 = M2C_FIELD(var_v1, u8 **, 0);
            if (var_v1 != NULL) {
                goto loop_1;
            }
        }
    }
    return var_v1 != NULL;
}

void func_800A8CE4(void) {
    s32 temp_s0;

    temp_s0 = D_8010AD40;
    if ((temp_s0 != 0) && (D_8010AD3C != 0) && (M2C_FIELD(D_8010AD3C, s32 *, 8) == 0)) {
        func_800A8B30(temp_s0);
        M2C_FIELD(D_8010AD3C, s32 *, 8) = temp_s0;
        D_8010AD40 = D_8010AD3C;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A8D58);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A8E50);

s32 func_800A8F48(void) {
    if (D_8010AD3C == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD3C, s32 *, 8) != 0;
}

void func_800A8F74(void) {
    if (D_8010AD40 != 0) {
        func_800A8AF4(D_8010AD40);
    }
}

void func_800A8FA0(void) {
    if (D_8010AD3C != 0) {
        func_800A8AF4(D_8010AD3C);
    }
}

void func_800A8FCC(void) {
    s32 *temp_a0;

    if (D_8010AD40 != 0) {
        temp_a0 = M2C_FIELD(D_8010AD40, s32 **, 8);
        if (temp_a0 != NULL) {
            func_800A8AF4(temp_a0);
            M2C_FIELD(D_8010AD40, s32 **, 8) = NULL;
        }
    }
}

void func_800A9018(void) {
    s32 *temp_a0;

    if (D_8010AD3C != 0) {
        temp_a0 = M2C_FIELD(D_8010AD3C, s32 **, 8);
        if (temp_a0 != NULL) {
            func_800A8AF4(temp_a0);
            M2C_FIELD(D_8010AD3C, s32 **, 8) = NULL;
        }
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9064);

void func_800A90EC(void) {
    if (D_8010AD40 != 0) {
        D_8010AD3C = D_8010AD40;
    }
}

void func_800A9110(void) {
    if (D_8010AD3C != 0) {
        D_8010AD40 = D_8010AD3C;
    }
}

s32 func_800A9134(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_8010AD40 != 0) {
        var_v0 = D_8010AD40 + 0x60;
    }
    return var_v0;
}

u8 func_800A9154(void) {
    u8 var_v0;

    var_v0 = 0;
    if (D_8010AD3C != 0) {
        var_v0 = M2C_FIELD(D_8010AD3C, u8 *, 0x50);
    }
    return var_v0;
}

u8 func_800A9174(void) {
    u8 var_v0;

    var_v0 = 0;
    if (D_8010AD40 != 0) {
        var_v0 = M2C_FIELD(D_8010AD40, u8 *, 0x50);
    }
    return var_v0;
}

s32 func_800A9194(void) {
    return D_8010AD3C;
}

s32 func_800A91A4(s32 arg0) {
    u8 temp_v1;

    if (D_8010AD40 != 0) {
        temp_v1 = M2C_FIELD(D_8010AD40, u8 *, 0x50);
        if (temp_v1 < 0x20U) {
            return (arg0 >> temp_v1) & 1;
        }
    }
    return 0;
}

s32 func_800A91E0(s32 arg0) {
    u8 temp_v1;

    if (D_8010AD3C != 0) {
        temp_v1 = M2C_FIELD(D_8010AD3C, u8 *, 0x50);
        if (temp_v1 < 0x20U) {
            return (arg0 >> temp_v1) & 1;
        }
    }
    return 0;
}

s32 func_800A921C(s32 arg0, u8 arg1) {
    if (arg1 >= 0x20U) {
        return 0;
    }
    return (arg0 >> arg1) & 1;
}

s32 func_800A9240(void) {
    s32 var_a1;
    u8 temp_a0;

    if (D_8010AD40 != 0) {
        temp_a0 = M2C_FIELD(D_8010AD40, u8 *, 0x50);
        var_a1 = 0;
        if ((temp_a0 == 4) || (temp_a0 == 0x13) || ((u32) (M2C_FIELD(D_8010AD40, u8 *, 0x50) - 0x29) < 2U)) {
            var_a1 = 1;
        }
    } else {
        var_a1 = 0;
    }
    return var_a1;
}

s32 func_800A929C(void) {
    s32 var_a1;
    u8 temp_a0;

    if (D_8010AD3C != 0) {
        temp_a0 = M2C_FIELD(D_8010AD3C, u8 *, 0x50);
        var_a1 = 0;
        if ((temp_a0 == 4) || (temp_a0 == 0x13) || ((u32) (M2C_FIELD(D_8010AD3C, u8 *, 0x50) - 0x29) < 2U)) {
            var_a1 = 1;
        }
    } else {
        var_a1 = 0;
    }
    return var_a1;
}

s32 func_800A92F8(s32 arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = arg0 & 0xFF;
    var_a1 = 0;
    if ((temp_v1 == 4) || (temp_v1 == 0x13) || ((u32) ((arg0 - 0x29) & 0xFF) < 2U)) {
        var_a1 = 1;
    }
    return var_a1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9334);

void func_800A9480(s16 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x4C) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x3E) = 0;
    }
}

void func_800A94A8(s16 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD40, s16 *, 0x4C) = arg0;
        M2C_FIELD(D_8010AD40, s16 *, 0x3E) = 0;
    }
}

void func_800A94D0(s16 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x4C) = arg0;
    }
}

void func_800A94F4(s16 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s16 *, 0x40) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x3C) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x4C) = arg0;
        M2C_FIELD(D_8010AD3C, s16 *, 0x3E) = 0;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9520);

void func_800A9678(s16 arg0) {
    func_800A9520(D_8010AD3C, arg0);
}

void func_800A96A4(s16 arg0) {
    func_800A9520(D_8010AD40, arg0);
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A96D0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A97A8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A97E4);

void func_800A9820(s32 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s32 *, 0x10) = (s32) (arg0 + M2C_FIELD(D_8010AD3C, s32 *, 0x10));
    }
}

s32 func_800A984C(void) {
    if (D_8010AD3C == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 1;
}

s32 func_800A9878(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u8 *, 0x51) & 1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A98A4);

u32 func_800A98E4(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u8 *, 0x51) >> 7;
}

s16 func_800A9910(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, s16 *, 0x42);
}

s32 func_800A993C(s32 arg0) {
    u8 *var_v1;

    var_v1 = D_8010AD38;
    if (var_v1 != NULL) {
loop_1:
        if (M2C_FIELD(var_v1, u8 *, 0x50) != arg0) {
            var_v1 = M2C_FIELD(var_v1, u8 **, 0);
            if (var_v1 != NULL) {
                goto loop_1;
            }
        }
        if (var_v1 != NULL) {
            D_8010AD3C = (s32) var_v1;
        }
    }
    return var_v1 != NULL;
}

void func_800A9988(void) {
    s32 temp_v0;

    if (D_8010AD40 != 0) {
        temp_v0 = M2C_FIELD(D_8010AD40, s32 *, 4);
        if (temp_v0 != 0) {
            D_8010AD3C = temp_v0;
        }
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A99BC);

void func_800A9A04(s8 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s8 *, 0x50) = arg0;
    }
}

void func_800A9A24(s16 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s16 *, 0x4A) = arg0;
    }
}

s32 func_800A9A44(void) {
    if (D_8010AD40 == 0) {
        return 0;
    }
    return M2C_FIELD(D_8010AD40, u16 *, 0x4A) & 0x1F;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9A70);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9AA4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9AD0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9B04);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9C64);

void func_800A9D5C(s32 arg0) {
    func_800A9C64(D_8010AD3C, arg0);
}

void func_800A9D88(s32 arg0) {
    func_800A9C64(D_8010AD40, arg0);
}

void func_800A9DB4(s32 arg0) {
    func_800A9C64(D_8010AD40, arg0);
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s32 *, 0x1C) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0xC);
        M2C_FIELD(D_8010AD40, s32 *, 0x20) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x10);
        M2C_FIELD(D_8010AD40, s32 *, 0x24) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x14);
        M2C_FIELD(D_8010AD40, s32 *, 0x28) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x18);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800A9E14);

void func_800AA02C(s32 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s32 *, 0x10) = arg0;
    }
}

void func_800AA04C(s32 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s32 *, 0x10) = arg0;
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) | 4);
    }
}

void func_800AA078(s16 arg0) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, s16 *, 0x4E) = arg0;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA098);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA0E0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA128);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA170);

void func_800AA1B8(void) {
    if (D_8010AD3C != 0) {
        if (M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 4) {
            M2C_FIELD(D_8010AD3C, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x1C);
            M2C_FIELD(D_8010AD3C, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x24);
        } else {
            M2C_FIELD(D_8010AD3C, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x1C);
            M2C_FIELD(D_8010AD3C, s32 *, 0x10) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x20);
            M2C_FIELD(D_8010AD3C, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x24);
            M2C_FIELD(D_8010AD3C, s32 *, 0x18) = (s32) M2C_FIELD(D_8010AD3C, s32 *, 0x28);
        }
        M2C_FIELD(D_8010AD3C, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD3C, u8 *, 0x51) & 0xFE);
    }
}

void func_800AA238(void) {
    if (D_8010AD40 != 0) {
        if (M2C_FIELD(D_8010AD40, u8 *, 0x51) & 4) {
            M2C_FIELD(D_8010AD40, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x1C);
            M2C_FIELD(D_8010AD40, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x24);
        } else {
            M2C_FIELD(D_8010AD40, s32 *, 0xC) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x1C);
            M2C_FIELD(D_8010AD40, s32 *, 0x10) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x20);
            M2C_FIELD(D_8010AD40, s32 *, 0x14) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x24);
            M2C_FIELD(D_8010AD40, s32 *, 0x18) = (s32) M2C_FIELD(D_8010AD40, s32 *, 0x28);
        }
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) & 0xFE);
    }
}

void func_800AA2B8(void) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) & 0xFD);
    }
}

void func_800AA2E4(s8 arg0) {
    if (D_8010AD3C != 0) {
        M2C_FIELD(D_8010AD3C, s8 *, 0x5D) = arg0;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA304);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA580);

s32 func_800AA640(void) {
    s32 temp_v0;

    temp_v0 = func_800AA580(D_8010AD3C);
    if (temp_v0 != 0) {
        func_800AA1B8();
    }
    return temp_v0;
}

s32 func_800AA684(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_8010AD3C != 0) {
        var_v0 = M2C_FIELD(D_8010AD3C, s32 *, 4);
    }
    return var_v0;
}

void func_800AA6A4(void) {
    if (D_8010AD40 != 0) {
        M2C_FIELD(D_8010AD40, u8 *, 0x51) = (u8) (M2C_FIELD(D_8010AD40, u8 *, 0x51) | 2);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA6D0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA7DC);

void func_800AA8D8(s16 arg0, s16 arg1, s16 arg2) {
    D_8010AD44 = arg0;
    D_8010AD48 = arg1;
    D_8010AD4C = arg2;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AA8F8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AAA00);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AAB18);

void func_800AB36C(void *arg0) {
    if (arg0 != NULL) {
        M2C_SFIELD(arg0, s16 *, 2) = 0;
        M2C_SFIELD(arg0, u16 *, 0) = (u16) D_8010AD54;
        M2C_SFIELD(arg0, u16 *, 4) = (u16) D_8010AD58;
    }
}

void func_800AB398(void *arg0) {
    u8 temp_v1;

    if ((arg0 != NULL) && (D_8010AD40 != 0) && (M2C_FIELD(arg0, u8 *, 0x51) & 2) && (((((func_800A921C(7, M2C_FIELD(arg0, u8 *, 0x50)) != 0) && ((u32) (M2C_FIELD(arg0, u8 *, 0x5D) - 2) >= 4U)) || (func_800A92F8((s32) M2C_FIELD(arg0, u8 *, 0x50)) != 0)) && ((arg0 != D_8010AD40) || (D_8010AD5C == 0)) && ((0x311B6F05 >> (M2C_FIELD(arg0, u16 *, 0x4A) & 0x1F)) & 1)) || (temp_v1 = M2C_FIELD(arg0, u8 *, 0x50), (temp_v1 == 3)) || (temp_v1 == 0xB))) {
        func_800B5C7C(arg0);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB48C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB4F4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB570);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB5E4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB6E4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB8EC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB92C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AB988);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ABA18);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ABA78);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ABB24);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ABE58);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ABFC0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AC3C0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AC484);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AC700);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AD63C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AD788);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AD804);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AD928);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AD970);

void func_800ADA08(void) {
    u8 *var_s0;

    var_s0 = D_8010AD38;
    if (var_s0 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0, u8 *, 0x51) & 8)) {
                func_800AD970(var_s0);
            }
            var_s0 = M2C_FIELD(var_s0, u8 **, 0);
        } while (var_s0 != NULL);
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADA64);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADB30);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADC3C);

void func_800ADC70(void) {
    D_8010AE54 = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADC80);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADD4C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADE30);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADEA8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800ADFC0);

s32 func_800AE024(void *arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0);
    temp_v0 = M2C_FIELD(arg1, s32 *, 0);
    var_a2 = temp_v1 - temp_v0;
    if (var_a2 <= 0) {
        var_a2 = temp_v0 - temp_v1;
    }
    if (var_a2 > 0x23FFF) {
        var_a2 = 0x48000 - var_a2;
    }
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 4);
    temp_v0_2 = M2C_FIELD(arg1, s32 *, 4);
    var_a3 = temp_v1_2 - temp_v0_2;
    if (var_a3 <= 0) {
        var_a3 = temp_v0_2 - temp_v1_2;
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 8);
    temp_a1 = M2C_FIELD(arg1, s32 *, 8);
    var_v1 = temp_a0 - temp_a1;
    if (var_v1 <= 0) {
        var_v1 = temp_a1 - temp_a0;
    }
    if (var_v1 > 0x1BFFF) {
        var_v1 = 0x38000 - var_v1;
    }
    return var_a2 + var_a3 + var_v1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE0BC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE180);

s16 func_800AE47C(void *arg0, void *arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg1, s32 *, 0);
    return func_800AE180(temp_a2 - M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg1, s32 *, 8) - M2C_FIELD(arg0, s32 *, 8), temp_a2);
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE4B8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE5B8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE5F0);

s32 func_800AE628(void) {
    return D_8010B080;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE638);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AE8AC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AEA48);

void func_800AF0A0(s32 arg0) {
    D_8010B174 = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF0B0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF110);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF1A8);

void func_800AF1E8(u32 arg0, u32 arg1) {
    if ((D_8010B3B8 != NULL) && (arg0 < 0x24U) && (arg1 < 0x1CU)) {
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 0) & 0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 8) & 0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) ((arg0 << 0xD) | M2C_SFIELD(D_8010B3B8, s32 *, 0));
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) ((arg1 << 0xD) | M2C_SFIELD(D_8010B3B8, s32 *, 8));
    }
}

void func_800AF24C(s32 arg0, s32 arg1) {
    if (D_8010B3B8 != NULL) {
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 0) & ~0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) (M2C_SFIELD(D_8010B3B8, s32 *, 8) & ~0x1FFF);
        M2C_SFIELD(D_8010B3B8, s32 *, 0) = (s32) ((arg0 & 0x1FFF) | M2C_SFIELD(D_8010B3B8, s32 *, 0));
        M2C_SFIELD(D_8010B3B8, s32 *, 8) = (s32) ((arg1 & 0x1FFF) | M2C_SFIELD(D_8010B3B8, s32 *, 8));
    }
}

void func_800AF2A4(s8 arg0, s8 arg1, s8 arg2) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s8 *, 0x10) = arg0;
        M2C_FIELD(D_8010B3B8, s8 *, 0x11) = arg1;
        M2C_FIELD(D_8010B3B8, s8 *, 0x12) = arg2;
    }
}

void func_800AF2E4(s32 arg0) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s32 *, 0x1C) = arg0;
    }
}

void func_800AF304(s32 arg0) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s32 *, 0x20) = arg0;
    }
}

void func_800AF324(s8 arg0, s8 arg1, s8 arg2) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s8 *, 0x14) = arg0;
        M2C_FIELD(D_8010B3B8, s8 *, 0x15) = arg1;
        M2C_FIELD(D_8010B3B8, s8 *, 0x16) = arg2;
    }
}

void func_800AF364(s8 arg0, s8 arg1, s8 arg2) {
    if (D_8010B3B8 != NULL) {
        M2C_FIELD(D_8010B3B8, s8 *, 0x18) = arg0;
        M2C_FIELD(D_8010B3B8, s8 *, 0x19) = arg1;
        M2C_FIELD(D_8010B3B8, s8 *, 0x1A) = arg2;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF3A4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF96C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF9A0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AF9DC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AFCC8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800AFFBC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0098);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B017C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B01C4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0200);

s32 func_800B0240(void) {
    return D_8010B47C == 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0250);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0334);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B04AC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0670);

void func_800B075C(void) {
    if (D_8010C804 == 0) {
        func_800B0670();
        D_8010C804 = 1;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0794);

s32 func_800B0800(void) {
    return D_8010C808;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0810);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0BF4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0D98);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B0E84);

void func_800B104C(void) {
    D_8010CA20 = 0;
    D_8010CA1C = 0;
    D_8010CA78 = 0;
    D_8010CA74 = 0;
    D_800BD144 = 0;
    D_8010CAF0 = 0;
    D_8010CA8C = 0;
    D_8010CAC8 = 0;
    D_8010CAC4 = 0;
    D_8010CAC0 = 0;
    D_8010CAF4 = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B10AC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B11C4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B1650);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B190C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B1C80);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B21E4);

void func_800B22E4(void) {
    func_800B190C();
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B2304);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B2638);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B271C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B28CC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B29CC);

void func_800B2E90(void) {
    func_800B22E4();
    if (D_8010CAF4 != 0) {
        if (D_8010CA8C == 3) {
            D_8010CAF4 = 0;
            D_8010CA8C = 0;
            func_800A2108(1, 5);
        } else if (D_8010CA8C == 2) {
            func_800A1D54(1);
            func_800A45C4(0x1770);
            func_800A45D4(0x5DC);
            func_800ABA18(8);
            D_8010CAF4 = 0;
        }
    }
    if ((D_8010CAF0 == 3) && ((u32) (D_8010CA8C - 2) < 2U) && (D_8010CACC == 0) && (D_8010CAD0 == 0)) {
        func_800B271C(3);
    }
    func_800B29CC();
}

void func_800B2F94(s32 arg0) {
    D_8010CAF0 = arg0;
}

s32 func_800B2FA4(void) {
    if (D_8010CA8C != 2) {
        return -(D_8010CA8C == 3);
    }
    return 1;
}

s32 func_800B2FD0(void) {
    s32 var_v1;

    var_v1 = 0;
    if ((D_8010CACC != 0) || (D_8010CAD0 != 0) || (D_8010CAD4 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_800B3018(void) {
    D_8010CAF4 = 1;
    if (D_8010CA8C != 1) {
        D_8010CA8C = 0;
    }
}

void func_800B3044(s16 arg0) {
    D_8010CAFC = arg0;
    D_8010CB10 = 0;
    D_8010CB0C = 0;
    D_8010CB08 = 0;
    D_8010CB04 = 0;
    D_8010CB00 = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B307C);

s16 func_800B32F0(void) {
    return D_8010CAFC;
}

void func_800B3300(u32 arg0) {
    D_800C68EE = arg0 & 0xFF;
    D_800C6902 = (arg0 >> 8) & 0xFF;
    D_800C6916 = (arg0 >> 0x10) & 0xFF;
    D_8010CB14 = (s32) (arg0 >> 0x18);
    D_8010CB1C = 0;
    D_8010CB18 = 0;
}

s32 func_800B3350(void) {
    return D_800C68EE | (D_800C6902 << 8) | (D_800C6916 << 0x10) | (D_8010CB14 << 0x18);
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B338C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B3418);

void func_800B37E0(s32 *arg0, s32 *arg1) {
    if (arg0 != NULL) {
        *arg0 += D_8010CB18;
    }
    if (arg1 != NULL) {
        *arg1 += D_8010CB1C;
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B3828);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B392C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B39B4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B3C40);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B40B4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B4244);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B45DC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B5274);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B5314);

void func_800B579C(s32 arg0, s8 arg1, s8 arg2, s8 arg3) {
    u8 *temp_a0;

    temp_a0 = D_8010D9B8[arg0];
    temp_a0[0] = arg1;
    temp_a0[1] = arg2;
    temp_a0[2] = arg3;
    temp_a0[3] = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B57C0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B57DC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B58F8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B59F4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B5C7C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B5DD8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B5E28);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B624C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6348);

void func_800B63E0(s32 arg0) {
    D_801159DC = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B63F0);

void func_800B64A0(void) {
    func_800B63F0(D_801159E0);
}

s32 func_800B64C8(void) {
    return D_801159E0;
}

void func_800B64D8(s32 arg0) {
    D_8009A000 = 0x30;
    D_8009A004 = arg0;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B650C);

void func_800B6570(s32 arg0) {
    D_8009A000 = 0xC0;
    D_8009A004 = arg0;
    func_8002DA7C();
}

void func_800B65A4(s32 arg0, s32 arg1) {
    D_8009A000 = 0xBD;
    D_8009A004 = arg0;
    D_8009A008 = arg1;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B65E0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B667C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6724);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B69A4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6A4C);

void func_800B6AEC(void) {
    if (D_80115A60 != 0) {
        D_80115A60 = 0;
        func_800ADD4C(2);
        func_800B6A4C();
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6B28);

void func_800B6C84(void) {
    if (D_80115A60 == 0) {
        func_800A7F38();
        D_80115A40 = func_800A86C4(2);
        if (func_800ADC80(2) != 0) {
            D_80115A60 = 1;
            D_80115A50 = 0;
            func_80033E74(D_800C74DC, D_800C74E0, D_80115A40, (s32) func_800B6DCC);
            func_80034B44();
        }
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6D10);

void func_800B6DCC(void) {
    if (D_80115A60 != 0) {
        D_80115A60 = 0;
        func_800ADD4C(2);
        func_800B6D10();
    }
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6E08);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6E78);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B6EFC);

void func_800B7104(s16 arg0) {
    D_80115A58 = (s32) arg0;
    func_800B6B28(arg0);
}

void func_800B7134(void) {
    func_8003408C();
    D_80115A60 = 0;
}

void func_800B715C(s32 arg0) {
    D_80115A68 = arg0;
}

s32 func_800B716C(void) {
    return D_80115A68;
}

s32 func_800B717C(void) {
    s32 temp_a0;
    s32 temp_v1;
    s32 var_v0;

    var_v0 = 0;
    if ((u16) D_8009D288 >= 0x3E8U) {
        if ((u16) D_8009D288 < 0x62CU) {
            temp_a0 = D_8009D302 & 1;
            if ((u16) D_8009D288 >= 0x654U) {
                return (temp_a0 | 2) + 1;
            }
            return temp_a0 + 1;
        }
        temp_v1 = (u16) D_8009D288 >= 0x654U;
        if (D_8009D60E & 0x10) {
            return (temp_v1 | 2) + 5;
        }
        var_v0 = temp_v1 + 5;
        
        return var_v0;
    }
    return var_v0;
}

s32 func_800B7200(void) {
    return (u32) (D_8009D288 - 0x3E8) < 0xC8U;
}

u8 func_800B7218(void) {
    return D_8009D686;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7228);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7480);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7620);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B76A8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7714);

void func_800B77A8(s32 arg0) {
    if (arg0 & 0x40000000) {
        func_800B7714(0x2100);
    }
    D_8011626C = 1;
    D_80116274 = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B77F4);

void func_800B7820(void) {
    D_80116278 = 0;
    D_8009D2E7 = 0;
}

void func_800B7838(void) {
    D_8011626C = 2;
    D_80116270 = 0;
    D_80116274 = 0;
}

s32 func_800B785C(void) {
    return D_8011626C;
}

s32 func_800B786C(void) {
    return D_80116270;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B787C);

s32 func_800B79B8(void) {
    if ((D_8009D391 != 0) && (D_8009D392 != 0)) {
        if (D_8009D393 != 0) {
            if ((D_8009D391 != 2) && (D_8009D392 != 2) && (D_8009D393 != 2)) {
                if ((D_8009D391 == 8) || (D_8009D392 == 8) || (D_8009D393 == 8)) {
                    return 2;
                }
                
                return 0;
            }
            return 1;
        }
        
        return 0;
    }
    return 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7A40);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7AC0);

void func_800B7B1C(u8 arg0) {
    D_8009D684 = arg0;
}

u8 func_800B7B2C(void) {
    return D_8009D684;
}

s32 func_800B7B3C(void) {
    return ((u16) *D_800707BE >> 3) & 1;
}

s32 func_800B7B54(void) {
    u32 var_v1;

    var_v1 = D_80062F19;
    if (var_v1 >= 0x11U) {
        var_v1 *= 2;
    }
    return var_v1;
}

s32 func_800B7B78(void) {
    s32 var_v1;

    var_v1 = D_80062F1B & 0x7F;
    if (var_v1 >= 0x11) {
        var_v1 *= 2;
    }
    return var_v1;
}

u32 func_800B7BA0(void) {
    return (u8) D_80062F1B >> 7;
}

u8 func_800B7BB0(void) {
    return D_80062F1A;
}

s32 func_800B7BC0(void) {
    return D_8009D40D & 1;
}

s32 func_800B7BD0(void) {
    return 1;
}

s32 func_800B7BD8(void) {
    s32 var_a0;
    s32 var_v1;
    u8 temp_v0;

    var_a0 = 0;
    var_v1 = 0;
    do {
        temp_v0 = D_8009CBDC[var_v1];
        var_v1 += 1;
        var_a0 += temp_v0 != 0xFF;
    } while (var_v1 < 3);
    return var_a0 >= 2;
}

s32 func_800B7C14(void) {
    return 1;
}

void func_800B7C1C(void) {
    D_80116284 = 0;
    func_800B7C44();
}

void func_800B7C44(void) {
    D_8011627C = -0x8C;
}

void func_800B7C58(void) {
    D_8011627C = -0x1E;
}

void func_800B7C6C(s32 arg0) {
    D_80116280 = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B7C7C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B832C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8488);

void func_800B84D8(s32 arg0) {
    if (D_800832A0 == 0) {
        D_8011628C = 0;
        D_80116288 = 0;
        func_800B8D4C(0, arg0 & 0xFF);
    }
}

void func_800B851C(s32 arg0, s16 arg1, s16 arg2) {
    if (D_800832A0 == 0) {
        D_80116288 = arg1;
        D_8011628C = arg2;
        func_800B90C0(0, arg0 & 0xFF, (u8) D_80116288, (u8) D_8011628C, &D_80116290);
    }
}

s32 func_800B857C(void) {
    return D_800832A0 != 0;
}

s32 func_800B858C(void) {
    if ((D_800832A0 != 0) && (D_800832A0 != 7)) {
        func_800B89C4(0);
    }
    return D_800832A0 != 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B85D4);

s16 func_800B86C4(void) {
    if (D_800832A0 == 0) {
        return D_80116290;
    }
    return -1;
}

void func_800B86E8(void *arg0) {
    if (arg0 != NULL) {
        func_800B8B00(0, M2C_FIELD(arg0, s16 *, 0), M2C_FIELD(arg0, s16 *, 2), M2C_FIELD(arg0, s16 *, 4), (s32) M2C_FIELD(arg0, s16 *, 6));
    }
}

void func_800B8720(s16 arg0, s16 arg1) {
    func_800B8A5C(0, arg0, arg1);
}

void func_800B8750(void) {
}

void func_800B8758(void) {
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8760);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B87D8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B89C4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8A5C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8A98);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8B00);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8CBC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8D20);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B8D4C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B90C0);

void func_800B95E8(void) {
    D_8009A000 = 0x30;
    D_8009A004 = 1;
    D_8009A008 = 0x40;
    func_8002DA7C();
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B962C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B98F0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800B9B2C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BA938);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BAA00);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BAB60);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BAC70);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BAE60);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB350);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB450);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB568);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB650);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB7DC);

void func_800BB8B0(void) {
    D_801163D4 = 0;
    D_801163D8 = 0;
    D_801163E8 = (u32) &D_801163E0;
    D_801163EC = 0;
    D_801163DC = 0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB8E8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB9A0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BB9D0);

u8 func_800BBA0C(void) {
    u8 var_a0;

    var_a0 = 0;
    if ((u32) &D_801163E0 < (u32) D_801163E8) {
        var_a0 = M2C_FIELD(D_801163E8, u8 *, -1);
    }
    return var_a0;
}

void func_800BBA34(s8 arg0) {
    D_801163E0 = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BBA44);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BBA5C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BBBB0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BBC4C);

void func_800BBD0C(void) {
    D_801163D4 = 1;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BBD20);

s32 func_800BC1AC(void) {
    return D_801163D4;
}

void func_800BC1BC(s32 arg0) {
    D_801163EC = arg0;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BC1CC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BC420);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BC9E8);

s16 func_800BCA38(void) {
    return D_801164F8;
}

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCA48);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCA78);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCB2C);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCBE8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BCECC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BD948);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BFBF0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800BFCAC);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C02F4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C0808);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C08A8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C0B48);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C1490);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C1D58);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C1FD8);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C2130);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C2450);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C2524);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C31F0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C3948);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C3DB0);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C4148);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C4FB4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C5CD4);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C6104);

INCLUDE_ASM("../asm/us/world/nonmatchings/text", func_800C6598);

INCLUDE_RODATA("../asm/us/world/nonmatchings/text", func_800A0BD4);
