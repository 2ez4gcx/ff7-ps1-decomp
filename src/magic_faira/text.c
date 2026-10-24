#include "common.h"
#include "magic_faira/decls.h"

void func_801B0000(void) {
    func_801B031C();
}

INCLUDE_ASM("../asm/us/magic_faira/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_faira/nonmatchings/text", func_801B020C);

void func_801B02BC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DD7E8 = D_801BD7E8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_faira/nonmatchings/text", func_801B031C);
