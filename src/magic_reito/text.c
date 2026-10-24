#include "common.h"
#include "magic_reito/decls.h"

void func_801B0000(void) {
    func_801B2354();
}

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B0A48);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1158);

void func_801B12E4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ECB98 = D_801D4B98 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1350);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B149C);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B15CC);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1684);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1968);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1C2C);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B1D74);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B221C);

INCLUDE_ASM("../asm/us/magic_reito/nonmatchings/text", func_801B2354);
