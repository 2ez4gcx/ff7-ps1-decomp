#include "common.h"
#include "magic_angermax/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0BEC();
    return &D_801BD6B4;
}

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B00B0);

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B0170);

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B0350);

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B06B8);

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B08C0);

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B09F0);

void func_801B0B8C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DDED4 = D_801BDED4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_angermax/nonmatchings/text", func_801B0BEC);
