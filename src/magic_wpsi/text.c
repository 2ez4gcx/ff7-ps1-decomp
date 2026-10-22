#include "common.h"
#include "magic_wpsi/decls.h"

void func_801B0054(void) {
    D_801D2C34 = &D_801B2564;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B008C(void) {
    D_801D2C34 = &D_801B28E8;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B00C4(void) {
    D_801D2C34 = &D_801B30CC;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B00FC(void) {
    D_801D2C34 = &D_801B3B48;
    D_801D2C38 = 1;
    func_801B24B0();
}

void func_801B0138(void) {
    D_801D2C34 = &D_801B466C;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B0170(void) {
    D_801D2C34 = &D_801B5020;
    D_801D2C38 = 1;
    func_801B24B0();
}

void func_801B01AC(void) {
    D_801D2C34 = &D_801B5B44;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B01E4(void) {
    D_801D2C34 = &D_801B63C8;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B021C(void) {
    D_801D2C34 = &D_801B6CBC;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B0254(void) {
    D_801D2C34 = &D_801B7748;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B028C(void) {
    D_801D2C34 = &D_801B814C;
    D_801D2C38 = 1;
    func_801B24B0();
}

void func_801B02C8(void) {
    D_801D2C34 = &D_801B8BF0;
    D_801D2C38 = 0;
    func_801B24B0();
}

void func_801B0300(void) {
    D_801D2C34 = &D_801B95A8;
    D_801D2C38 = 2;
    func_801B24B0();
}

void func_801B033C(void) {
    D_801D2C34 = &D_801BA12C;
    D_801D2C38 = 0;
    func_801B24B0();
}

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0374);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0450);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B05CC);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B06A8);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B078C);

void func_801B08B4(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = arg0 + 4;
    temp_s1 = arg0 + 0xC;
    M2C_FIELD(arg0, s32 *, 8) = func_8003BBDC(arg1, arg0 + 0x40, temp_s2, temp_s1);
    func_8003BBDC(arg2, arg0 + 0x44, temp_s2, temp_s1);
}

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0928);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0A2C);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0A8C);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B0B00);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1274);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B15DC);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1834);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1ADC);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1D20);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B1F10);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B22E4);

INCLUDE_ASM("../asm/us/magic_wpsi/nonmatchings/text", func_801B24B0);
