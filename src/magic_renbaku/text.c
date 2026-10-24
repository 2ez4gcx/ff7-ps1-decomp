#include "common.h"
#include "magic_renbaku/decls.h"

void func_801B0054(void) {
    func_801B08C4();
}

INCLUDE_ASM("../asm/us/magic_renbaku/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_renbaku/nonmatchings/text", func_801B02D0);

INCLUDE_ASM("../asm/us/magic_renbaku/nonmatchings/text", func_801B067C);

INCLUDE_RODATA("../asm/us/magic_renbaku/nonmatchings/text", D_801B0000);

void func_801B08C4(arg0) {
    D_801D9170 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B0948, 0, 0, 0);
    func_800BBEAC(&func_801B067C);
    D_801D9174 = arg0;
    D_801D9178 = 0;
}
