#include "common.h"
#include "magic_threat/decls.h"

void func_801B0000(void) {
    func_801B0364();
}

INCLUDE_ASM("../asm/us/magic_threat/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_threat/nonmatchings/text", func_801B00DC);

INCLUDE_ASM("../asm/us/magic_threat/nonmatchings/text", func_801B01D8);

void func_801B0304(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8554 = D_801B8554 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_threat/nonmatchings/text", func_801B0364);
