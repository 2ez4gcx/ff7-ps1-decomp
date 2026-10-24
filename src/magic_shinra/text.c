#include "common.h"
#include "magic_shinra/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0950();
    return &D_801BAD68;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CC8C0 = D_801BC8C0 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_shinra/nonmatchings/text", func_801B0088);

INCLUDE_ASM("../asm/us/magic_shinra/nonmatchings/text", func_801B01E8);

INCLUDE_ASM("../asm/us/magic_shinra/nonmatchings/text", func_801B0504);

INCLUDE_ASM("../asm/us/magic_shinra/nonmatchings/text", func_801B0664);

INCLUDE_ASM("../asm/us/magic_shinra/nonmatchings/text", func_801B0950);
