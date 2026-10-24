#include "common.h"
#include "magic_gravira/decls.h"

void func_801B0000(void) {
    func_801B0C10();
}

INCLUDE_ASM("../asm/us/magic_gravira/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_gravira/nonmatchings/text", func_801B0108);

INCLUDE_ASM("../asm/us/magic_gravira/nonmatchings/text", func_801B01E0);

INCLUDE_ASM("../asm/us/magic_gravira/nonmatchings/text", func_801B033C);

INCLUDE_ASM("../asm/us/magic_gravira/nonmatchings/text", func_801B0558);

INCLUDE_ASM("../asm/us/magic_gravira/nonmatchings/text", func_801B06D4);

void func_801B0B50(s16 arg0, s16 arg1) {
    MgObj20 *p;

    p = &D_80162978[func_800BBEAC(&func_801B06D4)];
    p->unk4 = arg0;
    p->unk6 = arg1;
}

void func_801B0BA4(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EEF40 = D_801D0F40 + p->unk2 * 0xF000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_gravira/nonmatchings/text", func_801B0C10);
