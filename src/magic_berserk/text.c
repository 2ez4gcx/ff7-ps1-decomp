#include "common.h"
#include "magic_berserk/decls.h"

void func_801B0018(void) {
    func_801B07D0();
}

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B0038);

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B0228);

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B034C);

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B0454);

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B06B0);

void func_801B0764(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF334 = D_801D1334 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_berserk/nonmatchings/text", func_801B07D0);
