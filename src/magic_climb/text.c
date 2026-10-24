#include "common.h"
#include "magic_climb/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B44();
    return &D_801B4DFC;
}

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B0124);

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B0304);

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B07F4);

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B08B4);

void func_801B0AE4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D6AB0 = D_801B6AB0 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_climb/nonmatchings/text", func_801B0B44);
