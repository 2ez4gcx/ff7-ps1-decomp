#include "common.h"
#include "magic_meikyo/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0A80();
    return &D_801C1EB0;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DB9D8 = D_801C39D8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_meikyo/nonmatchings/text", func_801B0094);

INCLUDE_ASM("../asm/us/magic_meikyo/nonmatchings/text", func_801B0180);

INCLUDE_ASM("../asm/us/magic_meikyo/nonmatchings/text", func_801B0378);

INCLUDE_ASM("../asm/us/magic_meikyo/nonmatchings/text", func_801B0418);

INCLUDE_ASM("../asm/us/magic_meikyo/nonmatchings/text", func_801B04A0);

INCLUDE_ASM("../asm/us/magic_meikyo/nonmatchings/text", func_801B089C);

INCLUDE_ASM("../asm/us/magic_meikyo/nonmatchings/text", func_801B0A80);
