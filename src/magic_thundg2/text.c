#include "common.h"
#include "magic_thundg2/decls.h"

void func_801B000C(void) {
    func_801B0F1C();
}

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B002C);

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B0224);

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B0540);

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B06D0);

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B079C);

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B0908);

void func_801B0EB4(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0FDC;
    if (p->unk2 == 0) {
        buf = D_801D1E8C;
    }
    D_801EDE8C = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_thundg2/nonmatchings/text", func_801B0F1C);
