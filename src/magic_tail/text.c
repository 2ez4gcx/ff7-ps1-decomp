#include "common.h"
#include "magic_tail/decls.h"

void func_801B0000(void) {
    func_801B1568();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EAC84 = D_801D2C84 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D2BD0.unk0 = D_801D2BDC[p->unk16];
    D_801D2BD0.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D2BD0, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2BDC[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0180);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0294);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B04C4);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0684);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0894);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B09E8);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B0FA4);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B144C);

INCLUDE_ASM("../asm/us/magic_tail/nonmatchings/text", func_801B1568);
