#include "common.h"
#include "magic_esna/decls.h"

void func_801B0000(void) {
    func_801B051C();
}

INCLUDE_ASM("../asm/us/magic_esna/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_esna/nonmatchings/text", func_801B01E0);

INCLUDE_ASM("../asm/us/magic_esna/nonmatchings/text", func_801B0404);

void func_801B04BC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D483C = D_801B483C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_esna/nonmatchings/text", func_801B051C);
