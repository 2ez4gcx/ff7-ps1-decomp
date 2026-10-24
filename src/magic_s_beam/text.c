#include "common.h"
#include "magic_s_beam/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B2220();
    return &D_801C3740;
}

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B03A0);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B072C);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B0A5C);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B0CC8);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B0E84);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B1084);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B1304);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B144C);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B1550);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B1760);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B18D8);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B1BA4);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B1DA8);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B1F78);

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B20EC);

void func_801B21C0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E5640 = D_801C5640 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_s_beam/nonmatchings/text", func_801B2220);
