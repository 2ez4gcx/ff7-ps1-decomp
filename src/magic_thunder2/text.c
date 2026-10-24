#include "common.h"
#include "magic_thunder2/decls.h"

void func_801B0000(void) {
    func_801B147C();
}

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B0020);

void func_801B00B0(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801D2174.unk0 = D_801D2180[p->unk16];
    D_801D2174.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801D2174, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2180[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B01A4);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B02B8);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B04E8);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B06A8);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B09F4);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B0B50);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B0D44);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B13B8);

INCLUDE_ASM("../asm/us/magic_thunder2/nonmatchings/text", func_801B147C);
