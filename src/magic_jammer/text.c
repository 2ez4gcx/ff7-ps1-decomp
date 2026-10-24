#include "common.h"
#include "magic_jammer/decls.h"

void func_801B0000(void) {
    func_801B0B44();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E92D8 = D_801D12D8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B01AC);

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B0324);

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B050C);

INCLUDE_ASM("../asm/us/magic_jammer/nonmatchings/text", func_801B0A68);

void func_801B0B44(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0BB0, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0A68);
}
