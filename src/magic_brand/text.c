#include "common.h"
#include "magic_brand/decls.h"

M2C_UNK *func_801B0020(void) {
    func_801B0C38();
    return &D_801B5148;
}

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B0048);

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B01B0);

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B02A8);

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B0404);

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B0540);

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B06C4);

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B0A8C);

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B0B2C);

void func_801B0BD8(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6DFC = D_801B6DFC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_brand/nonmatchings/text", func_801B0C38);
