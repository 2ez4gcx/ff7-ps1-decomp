#include "common.h"
#include "magic_zenbaku/decls.h"

void func_801B0054(void) {
    func_801B0860();
}

INCLUDE_ASM("../asm/us/magic_zenbaku/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_zenbaku/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_zenbaku/nonmatchings/text", func_801B02A4);

INCLUDE_ASM("../asm/us/magic_zenbaku/nonmatchings/text", func_801B07A4);

INCLUDE_RODATA("../asm/us/magic_zenbaku/nonmatchings/text", D_801B0000);

void func_801B0860(arg0) {
    D_801D9114 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B08E4, 0, 0, 0);
    func_800BBEAC(&func_801B07A4);
    D_801D9118 = arg0;
    D_801D911C = 0;
}
