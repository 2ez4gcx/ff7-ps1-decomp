#include "common.h"
#include "magic_gesui/decls.h"

void func_801B0000(void) {
    func_801B0BE8();
}

void func_801B0020(void) {
    func_801B0D44();
}

void func_801B0040(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D9108 = D_801C1108 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B00AC);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B01AC);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B01FC);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B0290);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B07EC);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B0BE8);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B0D44);
