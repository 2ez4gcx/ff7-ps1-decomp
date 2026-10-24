#include "common.h"
#include "magic_harrier/decls.h"

void func_801B0000(void) {
    func_801B0D58();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E140C = D_801C940C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_harrier/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_harrier/nonmatchings/text", func_801B01D8);

INCLUDE_ASM("../asm/us/magic_harrier/nonmatchings/text", func_801B0324);

INCLUDE_ASM("../asm/us/magic_harrier/nonmatchings/text", func_801B04B4);

INCLUDE_ASM("../asm/us/magic_harrier/nonmatchings/text", func_801B0C20);

INCLUDE_ASM("../asm/us/magic_harrier/nonmatchings/text", func_801B0D58);
