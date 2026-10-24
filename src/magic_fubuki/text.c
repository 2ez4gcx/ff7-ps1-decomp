#include "common.h"
#include "magic_fubuki/decls.h"

void func_801B0020(void) {
    func_801B0F20();
}

void func_801B0040(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EA7CC = D_801D27CC + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B00AC(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x1000, 0);
    D_801D1AFC[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D1AFC[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D1970) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B0168);

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B032C);

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B0400);

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B05BC);

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B0730);

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B08FC);

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B0DAC);

INCLUDE_ASM("../asm/us/magic_fubuki/nonmatchings/text", func_801B0F20);

INCLUDE_RODATA("../asm/us/magic_fubuki/nonmatchings/text", D_801B0000);
