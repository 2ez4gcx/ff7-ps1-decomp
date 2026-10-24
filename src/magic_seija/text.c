#include "common.h"
#include "magic_seija/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0D2C();
    return &D_801C3C28;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D7528 = D_801C7528 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B0088);

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B0280);

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B038C);

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B0580);

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B0638);

INCLUDE_ASM("../asm/us/magic_seija/nonmatchings/text", func_801B0D2C);
