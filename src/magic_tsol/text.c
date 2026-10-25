#include "common.h"
#include "magic_tsol/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B06EC();
    return &D_801B0760;
}

INCLUDE_ASM("../asm/us/magic_tsol/nonmatchings/text", func_801B007C);

INCLUDE_ASM("../asm/us/magic_tsol/nonmatchings/text", func_801B02AC);

INCLUDE_ASM("../asm/us/magic_tsol/nonmatchings/text", func_801B04EC);

INCLUDE_RODATA("../asm/us/magic_tsol/nonmatchings/text", D_801B0000);

s32 func_801B06EC(arg0, arg1) {
    s32 v;

    D_801CDBB0 = &D_80162978[func_800BBEAC(D_801B0000)];
    v = func_800BBEAC(func_801B04EC);
    D_801CDBB4 = arg0;
    D_801CDBB8 = arg1;
    return v;
}
