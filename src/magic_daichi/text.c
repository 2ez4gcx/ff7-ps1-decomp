#include "common.h"
#include "magic_daichi/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B28();
    return &D_801B6D0C;
}

INCLUDE_ASM("../asm/us/magic_daichi/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_daichi/nonmatchings/text", func_801B00E8);

INCLUDE_ASM("../asm/us/magic_daichi/nonmatchings/text", func_801B03DC);

INCLUDE_ASM("../asm/us/magic_daichi/nonmatchings/text", func_801B0858);

INCLUDE_ASM("../asm/us/magic_daichi/nonmatchings/text", func_801B0A48);

void func_801B0AC8(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D7790 = D_801B7790 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_daichi/nonmatchings/text", func_801B0B28);
