#include "common.h"
#include "magic_garyu/decls.h"

M2C_UNK *func_801B0060(void) {
    func_801B36B0();
    return &D_801D48D8;
}

M2C_UNK *func_801B0088(void) {
    func_801B3780();
    return &D_801D48D8;
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B00B0);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B02B0);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0480);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0808);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B0C9C);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B12FC);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B1400);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B18DC);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B1C9C);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2654);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B27B0);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2918);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2AF4);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B2D34);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B3434);

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B35F0);

void func_801B3654(void) {
    s32 var_v1;

    if (D_800F8368 != 0) {
        var_v1 = D_801D62E8 + 0xE000;
    } else {
        var_v1 = D_801D62E8;
    }
    D_801D62EC = var_v1;
    if (D_801D9F90 < 0) {
        *D_801D62F0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_garyu/nonmatchings/text", func_801B36B0);

void func_801B3780(arg0, arg1) {
    D_80162994[func_800BBEAC((void *)func_801B35F0)].unk0 = 0x80;
    D_801D9F90 &= 0xBFFFFFFF;
    if (arg0 == (1 << arg1)) {
        D_801D9F90 |= 0x20000000;
    }
    D_801D62F4 = arg0;
    D_801D62F8 = arg1;
}

INCLUDE_RODATA("../asm/us/magic_garyu/nonmatchings/text", D_801B0000);
