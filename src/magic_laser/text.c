#include "common.h"
#include "magic_laser/decls.h"

void func_801B0000(void) {
    func_801B06F4();
}

INCLUDE_ASM("../asm/us/magic_laser/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_laser/nonmatchings/text", func_801B02F8);

INCLUDE_ASM("../asm/us/magic_laser/nonmatchings/text", func_801B03D8);

INCLUDE_ASM("../asm/us/magic_laser/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_laser/nonmatchings/text", func_801B0640);

void func_801B0694(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E88F4 = D_801C88F4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_laser/nonmatchings/text", func_801B06F4);
