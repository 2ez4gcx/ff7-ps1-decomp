#include "common.h"
#include "magic_mabaria/decls.h"

void func_801B0000(void) {
    func_801B053C();
}

INCLUDE_ASM("../asm/us/magic_mabaria/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_mabaria/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_mabaria/nonmatchings/text", func_801B0378);

void func_801B04DC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0CA8 = D_801B0CA8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_mabaria/nonmatchings/text", func_801B053C);
