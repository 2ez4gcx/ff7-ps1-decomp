#include "common.h"
#include "magic_fullcare/decls.h"

void func_801B0000(void) {
    func_801B1034();
}

void func_801B0020(void) {
    s32 *p;
    s32 i;

    i = 199;
    p = &D_801E6494;
    for (; i >= 0; i--) {
        *p-- = 0;
    }
}

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B0044);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B00BC);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B01B4);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B0324);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B0410);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B0528);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B06C8);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B089C);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B0AB4);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B0D04);

void func_801B0EF8(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0D04)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B0F78(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_801E4994 = D_801C4994 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 3) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B0FD8);

INCLUDE_ASM("../asm/us/magic_fullcare/nonmatchings/text", func_801B1034);
