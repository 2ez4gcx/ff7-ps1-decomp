#include "common.h"
#include "magic_blaver/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0730();
    return &D_801B07A0;
}

INCLUDE_ASM("../asm/us/magic_blaver/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_blaver/nonmatchings/text", func_801B014C);

INCLUDE_ASM("../asm/us/magic_blaver/nonmatchings/text", func_801B03F4);

INCLUDE_ASM("../asm/us/magic_blaver/nonmatchings/text", func_801B04C0);

void func_801B067C(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B04C0)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B06D0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DEAD4 = D_801BEAD4 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0730(arg0, arg1) {
    func_800D2980(&D_801B15A8, 0, 0, 0);
    func_800BBEAC(&func_801B06D0);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B067C);
}
