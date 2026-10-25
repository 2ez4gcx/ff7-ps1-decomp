#include "common.h"
#include "magic_wep3/decls.h"

void func_801B0054(void) {
    func_801B226C();
}

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0150);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B02CC);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B03A8);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B048C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0510);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B067C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0774);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B096C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0B4C);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0D34);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B0F78);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B10EC);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B1514);

INCLUDE_ASM("../asm/us/magic_wep3/nonmatchings/text", func_801B16EC);

void func_801B21F8(void) {
    u8 pad[8];
    D_80162978[D_8015169C].unk0 = -1;
    D_80162994[func_800BBEAC(func_801B16EC)].unk0 = 0;
    func_800D54EC(D_801EB6B8, D_801EB6C0);
}

INCLUDE_RODATA("../asm/us/magic_wep3/nonmatchings/text", D_801B0000);

void func_801B226C(arg0, arg1) {
    D_801EB6B4 = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B22F8, 0, 0, 0);
    func_800BBEAC(&func_801B21F8);
    D_801EB6B8 = arg0;
    D_801EB6BC = arg1;
}
