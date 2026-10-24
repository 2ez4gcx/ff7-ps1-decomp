#include "common.h"
#include "magic_slow/decls.h"

void func_801B0000(void) {
    func_801B07FC();
}

INCLUDE_ASM("../asm/us/magic_slow/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_slow/nonmatchings/text", func_801B013C);

INCLUDE_ASM("../asm/us/magic_slow/nonmatchings/text", func_801B01B8);

void func_801B079C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DB148 = D_801BB148 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_slow/nonmatchings/text", func_801B07FC);
