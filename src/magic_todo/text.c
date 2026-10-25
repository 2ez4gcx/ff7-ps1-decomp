#include "common.h"
#include "magic_todo/decls.h"

void func_801B0054(void) {
    func_801B04E8();
}

INCLUDE_ASM("../asm/us/magic_todo/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_todo/nonmatchings/text", func_801B0190);

INCLUDE_ASM("../asm/us/magic_todo/nonmatchings/text", func_801B03F4);

INCLUDE_RODATA("../asm/us/magic_todo/nonmatchings/text", D_801B0000);

void func_801B04E8(arg0, arg1) {
    D_801CE998 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B058C, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, func_801B03F4);
    D_801CE99C = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x134);
}
