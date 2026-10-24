#include "common.h"
#include "magic_hvshot/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B103C();
    return &D_801B10AC;
}

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B0258);

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B03C0);

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B0680);

INCLUDE_ASM("../asm/us/magic_hvshot/nonmatchings/text", func_801B07F8);

void func_801B0F88(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B07F8)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0FDC(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D59F8 = D_801B59F8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B103C(arg0, arg1) {
    func_800D2980(&D_801B1A18, 0, 0, 0);
    func_800BBEAC(&func_801B0FDC);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B0F88);
}
