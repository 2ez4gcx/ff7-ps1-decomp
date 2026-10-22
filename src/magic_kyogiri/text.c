#include "common.h"
#include "magic_kyogiri/decls.h"

INCLUDE_ASM("../asm/us/magic_kyogiri/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_kyogiri/nonmatchings/text", func_801B0168);

INCLUDE_ASM("../asm/us/magic_kyogiri/nonmatchings/text", func_801B0348);

INCLUDE_ASM("../asm/us/magic_kyogiri/nonmatchings/text", func_801B059C);

INCLUDE_ASM("../asm/us/magic_kyogiri/nonmatchings/text", func_801B063C);

M2C_UNK *func_801B069C(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B14CC, 0, 0, 0);
    func_800BBEAC(&func_801B063C);
    func_800D5444(arg0, arg1, 0, &func_801B059C);
    return &D_801B0714;
}
