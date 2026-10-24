#include "common.h"
#include "magic_sdust/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B355C();
    return &D_801B7A00;
}

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B007C);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0148);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0318);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B04C4);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B05BC);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0818);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B09AC);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B0DCC);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B1424);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B1ADC);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B2250);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B276C);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B2D3C);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B2E38);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B2F04);

INCLUDE_ASM("../asm/us/magic_sdust/nonmatchings/text", func_801B3418);

INCLUDE_RODATA("../asm/us/magic_sdust/nonmatchings/text", D_801B0000);

void func_801B355C(arg0) {
    D_801E15FC = &D_80162978[func_800BBEAC(&D_801B0000)];
    func_800D2980(&D_801B35D8, 0, 0, 0);
    func_800BBEAC(&func_801B3418);
    D_801E1600 = arg0;
}
