#include "common.h"
#include "magic_wall/decls.h"

void func_801B0000(void) {
    func_801B074C();
}

INCLUDE_ASM("../asm/us/magic_wall/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_wall/nonmatchings/text", func_801B0200);

INCLUDE_ASM("../asm/us/magic_wall/nonmatchings/text", func_801B03B4);

INCLUDE_ASM("../asm/us/magic_wall/nonmatchings/text", func_801B056C);

void func_801B0670(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D170C = D_801B170C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B06D0(s32 arg0, M2C_UNK arg1) {
    D_801D1710 = 0x1000;
    D_801D1714 = 0xD00;
    func_800BBEAC(&func_801B0670);
    func_800D5444(arg0, arg1, 0, &func_801B056C);
    func_800D55F4(0x20, 0x40, 0x44);
}

INCLUDE_ASM("../asm/us/magic_wall/nonmatchings/text", func_801B074C);

void func_801B07C8(s32 arg0, M2C_UNK arg1) {
    D_801D1710 = 0x2000;
    D_801D1714 = 0;
    func_800BBEAC(&func_801B0670);
    func_800D5444(arg0, arg1, 0, &func_801B056C);
}
