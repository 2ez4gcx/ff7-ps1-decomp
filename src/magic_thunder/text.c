#include "common.h"
#include "magic_thunder/decls.h"

void func_801B0000(void) {
    func_801B06CC();
}

INCLUDE_ASM("../asm/us/magic_thunder/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_thunder/nonmatchings/text", func_801B0180);

INCLUDE_ASM("../asm/us/magic_thunder/nonmatchings/text", func_801B023C);

INCLUDE_ASM("../asm/us/magic_thunder/nonmatchings/text", func_801B0350);

INCLUDE_ASM("../asm/us/magic_thunder/nonmatchings/text", func_801B05A4);

void func_801B066C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E0E78 = D_801C0E78 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_thunder/nonmatchings/text", func_801B06CC);
