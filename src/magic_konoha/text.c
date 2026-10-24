#include "common.h"
#include "magic_konoha/decls.h"

void func_801B0000(void) {
    func_801B0704();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D5AA8 = D_801BDAA8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_konoha/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_konoha/nonmatchings/text", func_801B03E0);

INCLUDE_ASM("../asm/us/magic_konoha/nonmatchings/text", func_801B0704);
