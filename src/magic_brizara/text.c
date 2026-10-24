#include "common.h"
#include "magic_brizara/decls.h"

INCLUDE_ASM("../asm/us/magic_brizara/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_brizara/nonmatchings/text", func_801B01C8);

INCLUDE_ASM("../asm/us/magic_brizara/nonmatchings/text", func_801B03A4);

INCLUDE_ASM("../asm/us/magic_brizara/nonmatchings/text", func_801B0634);

void func_801B06B4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8F98 = D_801B8F98 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0714(s32 arg0, M2C_UNK arg1) {
    func_800D2980(&D_801B07A4, 0, 0, 0);
    func_800BBEAC(&func_801B06B4);
    func_800D5444(arg0, arg1, 0, &func_801B0634);
    func_800D55F4(0x20, func_800D574C(D_80151774), 0x1D);
}
