#include "common.h"
#include "magic_nadare/decls.h"

void func_801B0000(void) {
    func_801B1FDC();
}

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B0A48);

void func_801B1158(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ED378 = D_801D5378 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B11C4);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B1350);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B1500);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B15C8);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B1820);

void func_801B1910(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D5354[0] = p->unk2;
    D_801ED378 = func_800D4D90(&D_801D5354[-4], D_801517C0 + 0x70, 0xC, D_801ED378);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D511C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B19CC);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B1C54);

INCLUDE_ASM("../asm/us/magic_nadare/nonmatchings/text", func_801B1FDC);
