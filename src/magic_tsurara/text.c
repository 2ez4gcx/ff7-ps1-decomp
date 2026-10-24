#include "common.h"
#include "magic_tsurara/decls.h"

void func_801B0000(void) {
    func_801B0C38();
}

void func_801B0020(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E9B4C = D_801D1B4C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 0xA);
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B00B0);

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B01A8);

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B0304);

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B03F0);

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B058C);

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B06D0);

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B0B78);

INCLUDE_ASM("../asm/us/magic_tsurara/nonmatchings/text", func_801B0C38);
