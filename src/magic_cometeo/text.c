#include "common.h"
#include "magic_cometeo/decls.h"

void func_801B0000(void) {
    func_801B1488();
}

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B017C);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0608);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0844);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0B88);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B0C4C);

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B11F4);

void func_801B13FC(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B154C;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D4260;
    }
    D_801EC260 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_cometeo/nonmatchings/text", func_801B1488);
