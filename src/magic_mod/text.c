#include "common.h"
#include "magic_mod/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B1350();
    return &D_801B8FA8;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D23B0 = D_801BA3B0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B0094);

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B01A4);

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B081C);

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B0994);

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B0B4C);

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B0CE8);

INCLUDE_ASM("../asm/us/magic_mod/nonmatchings/text", func_801B126C);

void func_801B1350(arg0, arg1) {
    func_800BBEAC(&func_801B0028);
    func_800D2980(&D_801B13BC, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B126C);
}
