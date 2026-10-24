#include "common.h"
#include "magic_toboe/decls.h"

void func_801B0000(void) {
    func_801B0820();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C95B0 = D_801B15B0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0194);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B030C);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0484);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0760);

INCLUDE_ASM("../asm/us/magic_toboe/nonmatchings/text", func_801B0820);
