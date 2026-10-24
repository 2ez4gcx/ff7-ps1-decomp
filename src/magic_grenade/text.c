#include "common.h"
#include "magic_grenade/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0F60();
    return &D_801B0FDC;
}

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B0264);

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B03EC);

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B0664);

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B0880);

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B09A0);

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B0AFC);

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B0C64);

void func_801B0F00(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E4EB8 = D_801D4EB8 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_grenade/nonmatchings/text", func_801B0F60);
