#include "common.h"
#include "magic_osen/decls.h"

void func_801B0000(void) {
    func_801B100C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EAD48 = D_801D2D48 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B0174);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B022C);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B02DC);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B040C);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B0718);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B08F0);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B0AA0);

INCLUDE_ASM("../asm/us/magic_osen/nonmatchings/text", func_801B100C);
