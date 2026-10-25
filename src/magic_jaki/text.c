#include "common.h"
#include "magic_jaki/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B0B40();
    return &D_801B1828;
}

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B004C);

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B00C4);

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B01BC);

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B02C4);

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B0454);

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B08A8);

void func_801B0970(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B08A8)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B09F0);

void func_801B0AE0(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801D3740 = D_801B3740 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 3) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_jaki/nonmatchings/text", func_801B0B40);
