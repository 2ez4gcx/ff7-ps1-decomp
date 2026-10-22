#include "common.h"
#include "magic_break/decls.h"

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B024C);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0440);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B05E0);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0758);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B07F4);

void func_801B0854(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B08DC, 0, 0, 0);
    func_800BBEAC(&func_801B07F4);
    func_800D5444(arg0, arg1, 0, &func_801B0758);
    func_800D55F4(0x20, func_800D574C(arg0), 0x55);
}
