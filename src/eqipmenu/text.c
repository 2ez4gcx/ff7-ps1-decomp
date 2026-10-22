#include "common.h"
#include "eqipmenu/decls.h"

void func_801D0124(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

void func_801D0164(void) {
    func_8001F6AC();
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0184);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0314);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0574);

void func_801D064C(void) {
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0654);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D0BD0);

void func_801D1B8C(void) {
}

void func_801D1B94(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

u32 func_801D1BD4(u32 arg0) {
    return arg0 >> 0x1F;
}

s32 func_801D1BDC(s32 arg0) {
    s32 var_v0;

    var_v0 = arg0;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    return var_v0;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D1BF4);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D1D5C);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D26A4);

void func_801D2A80(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D2A94);

void func_801D2CE4(s32 *arg0, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v1;
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D2CF8);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D2D40);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D2E40);

void func_801D2E78(s32 arg0) {
    if (arg0 == 0) {
        func_801D2A94(D_8009CE60, 0xC8, &func_801D2D40, &func_801D2E40);
    }
}

void func_801D2EB4(void) {
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D2EBC);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D2EFC);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3074);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3490);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D373C);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3A24);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3AA0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3CB0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D3E14);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4418);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4678);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4760);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4AA8);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D4D94);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D509C);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D513C);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D5194);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D5300);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D54B0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D5BD0);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D6C2C);

void func_801D7FDC(void) {
    D_80062D9C = 0;
}

void func_801D7FEC(void) {
}

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D7FF4);

INCLUDE_ASM("../asm/us/eqipmenu/nonmatchings/text", func_801D8070);

void func_801D827C(void) {
}

void func_801D8284(void) {
}

void func_801D828C(void) {
}

void func_801D8294(void) {
}

void func_801D829C(void) {
}
