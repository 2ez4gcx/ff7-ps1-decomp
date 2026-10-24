#include "common.h"
#include "magic_comet/decls.h"

void func_801B0000(void) {
    func_801B1364();
}

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B017C);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0608);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0850);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0B94);

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B0C58);

void func_801B1258(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0C58)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B12D8(void) {
    M2C_UNK *var_v1;
    MgTask *temp_s0;

    temp_s0 = &D_80162978[D_8015169C];
    var_v1 = &D_801B13E8;
    if (temp_s0->unk2 == 0) {
        var_v1 = &D_801D34C0;
    }
    D_801EB4C0 = var_v1;
    temp_s0->unk2 = (u16) temp_s0->unk2 ^ 1;
    if (D_80162080 < 2) {
        func_800D52A0(0, 4);
        temp_s0->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_comet/nonmatchings/text", func_801B1364);
