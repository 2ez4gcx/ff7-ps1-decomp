#include "common.h"
#include "magic_elecball/decls.h"

void func_801B0000(void) {
    func_801B0E98();
}

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B00E8);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B02FC);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0518);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0694);

void func_801B0B10(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B0694)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0B64(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EF1E4 = D_801D11E4 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0BD0);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0D4C);

INCLUDE_ASM("../asm/us/magic_elecball/nonmatchings/text", func_801B0E98);
