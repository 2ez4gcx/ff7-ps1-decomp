#include "common.h"
#include "magic_jammer2/decls.h"

void func_801B0000(void) {
    func_801B0D8C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ED130 = D_801D5130 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_jammer2/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_jammer2/nonmatchings/text", func_801B01AC);

INCLUDE_ASM("../asm/us/magic_jammer2/nonmatchings/text", func_801B0324);

INCLUDE_ASM("../asm/us/magic_jammer2/nonmatchings/text", func_801B04FC);

INCLUDE_ASM("../asm/us/magic_jammer2/nonmatchings/text", func_801B06E4);

INCLUDE_ASM("../asm/us/magic_jammer2/nonmatchings/text", func_801B0D8C);
