#include "common.h"
#include "magic_smkball/decls.h"

void func_801B0000(void) {
    func_801B02B0();
}

INCLUDE_ASM("../asm/us/magic_smkball/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_smkball/nonmatchings/text", func_801B0124);

INCLUDE_ASM("../asm/us/magic_smkball/nonmatchings/text", func_801B0250);

void func_801B02B0(void) {
    func_800D2980(&D_801B0310, 0, 0, 0);
    func_800BBEAC(&func_801B0250);
    func_800BBEAC(&func_801B0124);
    func_800D55F4(0x20, 0x40, 0x261);
}
