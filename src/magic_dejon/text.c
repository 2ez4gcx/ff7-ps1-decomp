#include "common.h"
#include "magic_dejon/decls.h"

void func_801B0000(void) {
    func_801B0D0C();
}

INCLUDE_ASM("../asm/us/magic_dejon/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_dejon/nonmatchings/text", func_801B0238);

INCLUDE_ASM("../asm/us/magic_dejon/nonmatchings/text", func_801B03A4);

INCLUDE_ASM("../asm/us/magic_dejon/nonmatchings/text", func_801B0590);

INCLUDE_ASM("../asm/us/magic_dejon/nonmatchings/text", func_801B0818);

void func_801B0CAC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E6E34 = D_801C6E34 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_dejon/nonmatchings/text", func_801B0D0C);
