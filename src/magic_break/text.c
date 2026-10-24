#include "common.h"
#include "magic_break/decls.h"

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B024C);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0440);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B05E0);

INCLUDE_ASM("../asm/us/magic_break/nonmatchings/text", func_801B0758);

void func_801B07F4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ED328 = D_801CD328 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0854(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B08DC, 0, 0, 0);
    func_800BBEAC(&func_801B07F4);
    func_800D5444(arg0, arg1, 0, &func_801B0758);
    func_800D55F4(0x20, func_800D574C(arg0), 0x55);
}
