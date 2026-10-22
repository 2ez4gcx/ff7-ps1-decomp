#include "common.h"
#include "magic_fire/decls.h"

INCLUDE_ASM("../asm/us/magic_fire/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_fire/nonmatchings/text", func_801B00B8);

INCLUDE_ASM("../asm/us/magic_fire/nonmatchings/text", func_801B0210);

INCLUDE_ASM("../asm/us/magic_fire/nonmatchings/text", func_801B0294);

void func_801B02EC(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B039C, 0, 0, 0);
    func_800D5444(arg0, arg1, 0, &func_801B0210);
    func_800BBEAC(&func_801B0294);
    func_800D55F4(0x20, func_800D574C(D_80151774), 9);
}

void func_801B037C(void) {
    func_8001C3C4();
}
