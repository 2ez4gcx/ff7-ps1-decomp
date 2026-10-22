#include "common.h"
#include "formmenu/decls.h"

void func_801D0198(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_8009A000 = 0x30;
    D_8009A004 = temp_a0;
    D_8009A008 = temp_a0;
    func_8002DA7C(temp_a0);
}

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D01D8);

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D0350);

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D0560);

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D06F0);

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D08E0);

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D0A00);

void func_801D0BCC(void) {
    switch (D_801D3430) {
    case 0:
        func_801D08E0();
        return;
    case 1:
        func_801D0A00();
        return;
    }
}

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D0C1C);

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D0E24);

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D0E94);

void func_801D1A14(void) {
    func_80025CD4((s32) &D_800756F8);
    func_80025C94(&D_801DDE60);
    func_80025BD0(&D_801D8460);
    func_80025C54(&D_801D3460);
}

INCLUDE_ASM("../asm/us/formmenu/nonmatchings/text", func_801D1A6C);

INCLUDE_RODATA("../asm/us/formmenu/nonmatchings/text", D_801D0000);
