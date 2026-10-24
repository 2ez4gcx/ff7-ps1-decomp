#include "common.h"
#include "magic_m_break/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0A54();
    return &D_801B0AC4;
}

INCLUDE_ASM("../asm/us/magic_m_break/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_m_break/nonmatchings/text", func_801B0258);

INCLUDE_ASM("../asm/us/magic_m_break/nonmatchings/text", func_801B0370);

INCLUDE_ASM("../asm/us/magic_m_break/nonmatchings/text", func_801B04E8);

void func_801B09A0(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B04E8)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B09F4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D5FE0 = D_801B5FE0 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0A54(arg0, arg1) {
    func_800D2980(&D_801B1430, 0, 0, 0);
    func_800BBEAC(&func_801B09F4);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B09A0);
}
