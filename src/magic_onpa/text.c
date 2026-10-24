#include "common.h"
#include "magic_onpa/decls.h"

void func_801B0000(void) {
    func_801B059C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C0B1C = D_801B0B1C + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_onpa/nonmatchings/text", func_801B0080);

INCLUDE_ASM("../asm/us/magic_onpa/nonmatchings/text", func_801B0158);

INCLUDE_ASM("../asm/us/magic_onpa/nonmatchings/text", func_801B02D0);

INCLUDE_ASM("../asm/us/magic_onpa/nonmatchings/text", func_801B04DC);

INCLUDE_ASM("../asm/us/magic_onpa/nonmatchings/text", func_801B059C);
