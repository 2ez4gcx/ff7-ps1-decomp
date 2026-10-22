#include "common.h"
#include "magic_flame/decls.h"

void func_801B0000(s32 arg0) {
    D_801DD870 = 0;
    func_801B1014();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0048);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B009C);

void func_801B00F0(s32 arg0) {
    D_801DD870 = 0;
    func_801B10F4();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

void func_801B0138(void) {
    D_801DD870 = 1;
    func_801B10F4();
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0164);

void func_801B01B4(s32 arg0) {
    D_801DD870 = 0;
    func_801B1220();
    func_800D55F4(0x20, func_800D574C(arg0), 0x1DE);
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B01FC);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B03C0);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0484);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B04B0);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0514);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B082C);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0908);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0B38);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0DBC);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0EB8);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B0FB4);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B1014);

void func_801B1084(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B134C, 0, 0, 0);
    func_800BBEAC(&func_801B0FB4);
    func_800D5444(arg0, arg1, 0, &func_801B0EB8);
}

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B10F4);

INCLUDE_ASM("../asm/us/magic_flame/nonmatchings/text", func_801B1220);
