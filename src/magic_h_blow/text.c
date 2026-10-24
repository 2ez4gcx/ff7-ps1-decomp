#include "common.h"
#include "magic_h_blow/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B11B4();
    return &D_801C2B3C;
}

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B01E0);

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B03C0);

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B04DC);

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B0640);

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B078C);

INCLUDE_ASM("../asm/us/magic_h_blow/nonmatchings/text", func_801B0BAC);

void func_801B111C(s32 arg0, s32 arg1) {
    D_801E34BC = arg0;
    D_801E34C0 = arg1;
    func_800BBEAC(&func_801B0BAC);
}

void func_801B1154(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E34B8 = D_801C34B8 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B11B4(arg0, arg1) {
    func_800D2980(&D_801B1224, 0, 0, 0);
    func_800BBEAC(&func_801B1154);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B111C);
}
