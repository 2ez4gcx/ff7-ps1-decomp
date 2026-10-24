#include "common.h"
#include "magic_kona/decls.h"

void func_801B0000(void) {
    func_801B0D14();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E1498 = D_801C9498 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0178);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0298);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0554);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0728);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B08EC);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0AB0);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0B70);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0C4C);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0CA4);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0D14);
