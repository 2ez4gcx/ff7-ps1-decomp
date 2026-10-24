#include "common.h"
#include "magic_shower/decls.h"

void func_801B0000(void) {
    func_801B0D58();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801DB454 = D_801C3454 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_shower/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_shower/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_shower/nonmatchings/text", func_801B02B4);

INCLUDE_ASM("../asm/us/magic_shower/nonmatchings/text", func_801B056C);

INCLUDE_ASM("../asm/us/magic_shower/nonmatchings/text", func_801B06FC);

INCLUDE_ASM("../asm/us/magic_shower/nonmatchings/text", func_801B08A0);

INCLUDE_ASM("../asm/us/magic_shower/nonmatchings/text", func_801B0C80);

void func_801B0D58(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B0DC4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0C80);
}
