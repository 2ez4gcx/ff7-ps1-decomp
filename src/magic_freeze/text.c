#include "common.h"
#include "magic_freeze/decls.h"

void func_801B0000(void) {
    func_801B17D0();
}

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B026C);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B04B8);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B067C);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0828);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B09D4);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0AC0);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0CA8);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0E44);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B0FC4);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B10B0);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B13A8);

INCLUDE_ASM("../asm/us/magic_freeze/nonmatchings/text", func_801B16BC);

void func_801B1770(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5F30 = D_801D5F30 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B17D0(arg0, arg1) {
    func_800D2980(&D_801B1840, 0, 0, 0);
    func_800BBEAC(&func_801B1770);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B16BC);
}
