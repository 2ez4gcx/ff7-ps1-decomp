#include "common.h"
#include "magic_barrier/decls.h"

void func_801B0000(void) {
    func_801B0AF0();
}

INCLUDE_ASM("../asm/us/magic_barrier/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_barrier/nonmatchings/text", func_801B0220);

INCLUDE_ASM("../asm/us/magic_barrier/nonmatchings/text", func_801B04F4);

INCLUDE_ASM("../asm/us/magic_barrier/nonmatchings/text", func_801B092C);

void func_801B0A90(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0CC4 = D_801B0CC4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_barrier/nonmatchings/text", func_801B0AF0);
