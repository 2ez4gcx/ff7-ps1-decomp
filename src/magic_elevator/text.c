#include "common.h"
#include "magic_elevator/decls.h"

void func_801B0000(void) {
    func_801B0EF0();
}

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0418);

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B04E0);

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0528);

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B05E4);

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0854);

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0A10);

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0BC0);

void func_801B0E90(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D65BC = D_801B65BC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_elevator/nonmatchings/text", func_801B0EF0);
