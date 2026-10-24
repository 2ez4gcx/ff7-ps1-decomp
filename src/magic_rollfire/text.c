#include "common.h"
#include "magic_rollfire/decls.h"

void func_801B0000(void) {
    func_801B08C4();
}

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0230);

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B02F4);

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0320);

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0384);

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B0610);

void func_801B0864(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DCE60 = D_801BCE60 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_rollfire/nonmatchings/text", func_801B08C4);
