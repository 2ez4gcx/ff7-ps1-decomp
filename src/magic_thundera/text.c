#include "common.h"
#include "magic_thundera/decls.h"

void func_801B0000(void) {
    func_801B08F4();
}

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B01A0);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B028C);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B0348);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B04D8);

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B07F0);

void func_801B0894(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E90EC = D_801C90EC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_thundera/nonmatchings/text", func_801B08F4);
