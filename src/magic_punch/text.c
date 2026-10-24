#include "common.h"
#include "magic_punch/decls.h"

void func_801B0010(void) {
    D_801C9794 = 6;
    D_801B176C = 1;
    func_801B0880();
}

void func_801B0048(void) {
    D_801C9794 = 6;
    func_801B0880();
}

void func_801B0074(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C9790 = D_801B1790 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_punch/nonmatchings/text", func_801B00E0);

INCLUDE_ASM("../asm/us/magic_punch/nonmatchings/text", func_801B01D8);

INCLUDE_ASM("../asm/us/magic_punch/nonmatchings/text", func_801B0388);

INCLUDE_ASM("../asm/us/magic_punch/nonmatchings/text", func_801B0490);

INCLUDE_ASM("../asm/us/magic_punch/nonmatchings/text", func_801B07EC);

INCLUDE_ASM("../asm/us/magic_punch/nonmatchings/text", func_801B0880);
