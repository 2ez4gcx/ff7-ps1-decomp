#include "common.h"
#include "magic_bioga1/decls.h"

void func_801B0000(void) {
    func_801B0C8C();
}

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B03B0);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0600);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0778);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0958);

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0B94);

void func_801B0C24(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0DA4;
    if (p->unk2 == 0) {
        buf = D_801E1EF4;
    }
    D_801EDEF4 = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_bioga1/nonmatchings/text", func_801B0C8C);
