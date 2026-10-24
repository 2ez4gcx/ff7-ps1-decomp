#include "common.h"
#include "magic_dive/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0BD4();
    return &D_801BAA50;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CCFD8 = D_801BCFD8 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_dive/nonmatchings/text", func_801B0088);

INCLUDE_ASM("../asm/us/magic_dive/nonmatchings/text", func_801B01AC);

INCLUDE_ASM("../asm/us/magic_dive/nonmatchings/text", func_801B0274);

INCLUDE_ASM("../asm/us/magic_dive/nonmatchings/text", func_801B0650);

INCLUDE_ASM("../asm/us/magic_dive/nonmatchings/text", func_801B08E8);

INCLUDE_ASM("../asm/us/magic_dive/nonmatchings/text", func_801B0BD4);
