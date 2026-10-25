#include "common.h"
#include "magic_gaishu/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B094C();
    return &D_801B2F08;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CB434 = D_801B3434 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_gaishu/nonmatchings/text", func_801B0094);

INCLUDE_ASM("../asm/us/magic_gaishu/nonmatchings/text", func_801B027C);

INCLUDE_ASM("../asm/us/magic_gaishu/nonmatchings/text", func_801B0434);

INCLUDE_ASM("../asm/us/magic_gaishu/nonmatchings/text", func_801B0640);

void func_801B094C(arg0, arg1) {
    func_800BBEAC(func_801B0028);
    func_800D2980(D_801B09E0, 0, 0, 0);
    D_801CB438 = arg0;
    func_800D54EC(arg0, D_801CB43C);
    D_80162996[func_800BBEAC(func_801B0640)].unk0 = arg1;
}
