#include "common.h"
#include "magic_refrec/decls.h"

void func_801B0000(void) {
    func_801B050C();
}

INCLUDE_ASM("../asm/us/magic_refrec/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_refrec/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_refrec/nonmatchings/text", func_801B03A8);

void func_801B04AC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0C18 = D_801B0C18 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

s32 func_801B050C(arg0, arg1) {
    D_801B0C10 = 0x2000;
    D_801B0C14 = 0;
    func_800BBEAC(func_801B04AC);
    func_800D5444(arg0, arg1, 0, &func_801B03A8);
    return func_800D55F4(0x20, 0x40, 0x48);
}
