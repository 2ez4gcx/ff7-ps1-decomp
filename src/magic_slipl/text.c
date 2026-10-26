#include "common.h"
#include "magic_slipl/decls.h"

void func_801B0054(void) {
    func_801B0824();
}

INCLUDE_ASM("../asm/us/magic_slipl/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_slipl/nonmatchings/text", func_801B035C);

INCLUDE_ASM("../asm/us/magic_slipl/nonmatchings/text", func_801B0460);

INCLUDE_ASM("../asm/us/magic_slipl/nonmatchings/text", func_801B0614);

INCLUDE_RODATA("../asm/us/magic_slipl/nonmatchings/text", D_801B0000);

void func_801B0824(arg0, arg1) {
    D_801D0E68 = &D_80162978[func_800BBEAC(&func_801B0000)];
    func_800D2980(&D_801B08C0, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, &func_801B0614);
    func_800D55F4(0x20, func_800D574C(arg0), 0x49);
}
