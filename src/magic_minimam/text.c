#include "common.h"
#include "magic_minimam/decls.h"

void func_801B0054(void) {
    func_801B0514();
}

INCLUDE_ASM("../asm/us/magic_minimam/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_minimam/nonmatchings/text", func_801B0190);

INCLUDE_ASM("../asm/us/magic_minimam/nonmatchings/text", func_801B0414);

INCLUDE_RODATA("../asm/us/magic_minimam/nonmatchings/text", D_801B0000);

void func_801B0514(arg0, arg1) {
    D_801CC8B0 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B05B8, 0, 0, 0);
    func_800D5444(arg0, arg1, 1, func_801B0414);
    D_801CC8B4 = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0x134);
}
