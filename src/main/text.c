#include "common.h"
#include "main/decls.h"

void func_800110B8(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", main_entry);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001117C);

void func_800111E4(s32 arg0) {
    s32 x;
    D_8009A000 = 0xF4;
    func_8002DA7C(arg0);
    if (!(D_8009D5E9 & 0x30)) {
        func_8001117C(0x2B);
    }
    x = D_8009ABF6;
    D_800707BC = x;
    (&D_800707BC)[1] = D_8009AC32;
    (&D_800707BC)[1] = D_800716D0 | D_8009AC32;
    func_800146A4(x);
    D_800716D0 = 0;
}

void func_80011274(void) {
    func_80033E34(D_80048D1C, D_80048D20, 0x800E0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D14, D_80048D18, 0x800A0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80029818(0x800A0000, 0x800E0000);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800112E8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001146C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_8001155C);

void func_8001171C(void) {
    func_8003D1B4();
    func_8003D0C0();
    func_80043938(0);
    func_80036298();
    D_80095DD4 = 0;
    func_8003D150((s32) &func_8001155C);
    func_80043BA8(0);
    func_80043D3C(0);
    func_80039EDC();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011784);

void func_80011860(void) {
    if (D_800965EC != 5 && D_800965EC != 13) {
        if (D_800965EC != 2) {
            func_80033E34(D_80048D24, D_80048D28, 0x80180000, 0);
            while (func_80034B44() != 0) {
            }
            func_80015CA0(0x80180000, 0x800A0000);
        } else {
            while (func_80034B44() != 0) {
            }
            func_80015CA0(0x801C0000, 0x800A0000);
        }
    }
    func_800CF60C();
    func_800A16CC();
}

void func_80011920(void) {
    D_800965E8 = 0;
    D_80071A5C = 0;
}

void func_80011938(void) {
    func_80033E34(D_80048CFC, D_80048D00, 0x800F0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D04, D_80048D08, 0x801B0000, 0);
    do {

    } while (func_80034B44() != 0);
    func_80033E34(D_80048D0C, D_80048D10, 0x801BC800, 0);
    do {

    } while (func_80034B44() != 0);
    func_8002988C(0x800F0000, 0x801BC800);
    func_80029998(0x801B0000);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800119E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011AEC);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011BB4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80011C1C);

void func_80012840(s32 arg0) {
    s32 temp_s0;

    temp_s0 = func_8004656C(0, arg0, 0, 0) & 0xFFFF;
    func_80044A68(D_8009A068, 0, 0, temp_s0, 0);
    func_80044A68(D_8009A068 + 0x30, 0, 0, temp_s0, 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800128B8);

void func_800129D0(void) {
    func_800440C8(&D_8007EB68[(s16) D_80075DEC].disp,
                  D_8007EB68[((s16) D_80075DEC + 1) & 1].disp.x,
                  D_8007EB68[((s16) D_80075DEC + 1) & 1].disp.y);
    while (func_80043DD8(1) != 0) {
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80012A8C);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80012DB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800131B8);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800134F4);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80013564);

s16 func_800135C0(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    return (s16) (arg0 + ((s32) ((s16) (arg1 - arg0) * arg2) / arg3));
}

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80013624);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_80013800);

INCLUDE_ASM("../asm/us/main/nonmatchings/text", func_800138EC);
