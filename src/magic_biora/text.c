#include "common.h"
#include "magic_biora/decls.h"

void func_801B0000(void) {
    func_801B0B90();
}

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0350);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0410);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0588);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0734);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0A94);

void func_801B0B30(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ECC78 = D_801CCC78 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0B90);
