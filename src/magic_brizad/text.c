#include "common.h"
#include "magic_brizad/decls.h"

INCLUDE_ASM("../asm/us/magic_brizad/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_brizad/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_brizad/nonmatchings/text", func_801B028C);

INCLUDE_ASM("../asm/us/magic_brizad/nonmatchings/text", func_801B02D4);

INCLUDE_ASM("../asm/us/magic_brizad/nonmatchings/text", func_801B031C);

void func_801B037C(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B031C);
    func_800D5444(arg0, arg1, 4, &func_801B02D4);
    func_800D55F4(0x20, func_800D574C(D_80151774), 0x18);
}
