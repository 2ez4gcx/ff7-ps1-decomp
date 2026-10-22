#include "common.h"
#include "savemenu/decls.h"

void func_801D0408(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D0448);

void func_801D05C0(s32 arg0) {
    D_801E3860 = 0xF0;
    D_801E36B8 = arg0 & 0xFF;
    D_801E3850 = 0;
    func_80026448(&D_801E379C, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0U);
    func_80025B8C((s32) &D_801E8F44);
    func_80025C14((s32) &D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D0670);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D06B0);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1774);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1950);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D19C4);

void func_801D1BA4(void) {
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1BAC);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1BE0);

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D0050);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1C2C);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1D1C);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1D40);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D1F40);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2150);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2184);

void func_801D21B8(u8 *arg0, u8 *arg1) {
    s32 var_v1;
    u8 *var_a0;
    u8 *var_a1;
    u8 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v1 = 0;
    do {
        temp_v0 = *var_a1;
        var_a1 += 1;
        var_v1 += 1;
        *var_a0 = temp_v0;
        var_a0 += 1;
    } while (var_v1 < 0x40);
}

void func_801D21E0(s32 arg0) {
    D_801E2CB4 = arg0;
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D21F0);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D224C);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2408);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2A34);

void func_801D2B58(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2B98);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2D10);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D2DA8);

void func_801D32C0(void) {
    func_80042A30(D_8009A024);
    func_80042A30(D_8009A028);
    func_80042A30(D_8009A02C);
    func_80042A30(D_8009A030);
}

void func_801D3318(void) {
    func_80042A30(D_8009A034);
    func_80042A30(D_8009A038);
    func_80042A30(D_8009A03C);
    func_80042A30(D_8009A040);
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D3370);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D33F4);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D3478);

void func_801D3668(s32 arg0) {
    if (!(arg0 & 0x3F)) {
        func_801D3478(0);
        func_801D3478(1);
    }
}

s32 func_801D3698(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_s0;
    s32 var_v1;

    var_s0 = 0;
loop_1:
    var_a0 = arg1;
    if (arg0 != 0) {
        var_a0 |= 0x10;
    }
    if (func_801D1D40(var_a0) == 0) {
        var_v1 = 0;
    } else {
        var_s0 += 1;
        var_v1 = 1;
        if (var_s0 < 0x14) {
            goto loop_1;
        }
    }
    return var_v1;
}

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D370C);

void func_801D39C4(void) {
    D_801E3698 = 0;
    D_801E2CF8 = 7;
    func_8001DEF0(&D_801E368C);
    func_80025D14(&D_801D4EDC, 0x380, 0, 0, 0x1E0);
    func_80043DD8(0);
    func_80026448(&D_801E3DFE, 0, 1, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0U);
    func_80025CD4((s32) &D_801E3F2C);
    func_80025B8C((s32) &D_801E8F44);
    func_80025C14((s32) &D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D018C);

INCLUDE_RODATA("../asm/us/savemenu/nonmatchings/text", D_801D0194);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D3AB0);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D4C38);

INCLUDE_ASM("../asm/us/savemenu/nonmatchings/text", func_801D4CC0);
