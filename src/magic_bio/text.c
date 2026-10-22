#include "common.h"
#include "magic_bio/decls.h"

INCLUDE_ASM("../asm/us/magic_bio/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_bio/nonmatchings/text", func_801B0178);

INCLUDE_ASM("../asm/us/magic_bio/nonmatchings/text", func_801B0238);

INCLUDE_ASM("../asm/us/magic_bio/nonmatchings/text", func_801B0554);

INCLUDE_ASM("../asm/us/magic_bio/nonmatchings/text", func_801B05E0);

void func_801B0640(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B06C8, 0, 0, 0);
    func_800BBEAC(&func_801B05E0);
    func_800D5444(arg0, arg1, 0, &func_801B0554);
    func_800D55F4(0x20, func_800D574C(arg0), 0x3F);
}
