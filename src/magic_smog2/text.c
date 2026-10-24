#include "common.h"
#include "magic_smog2/decls.h"

void func_801B0000(void) {
    func_801B0E84();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E9A18 = D_801D1A18 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B0190);

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B0458);

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B0590);

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B06B4);

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B0DC4);

INCLUDE_ASM("../asm/us/magic_smog2/nonmatchings/text", func_801B0E84);
