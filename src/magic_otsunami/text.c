#include "common.h"
#include "magic_otsunami/decls.h"

void func_801B0000(void) {
    func_801B0BC8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8F8C = D_801C0F8C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B01DC);

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B0270);

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B07CC);

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B0BC8);
