#include "common.h"
#include "magic_southern/decls.h"

void func_801B0000(void) {
    func_801B0E30();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E4294 = D_801CC294 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B0334);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B04E8);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B06FC);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B0E30);
