#include "common.h"
#include "magic_flea/decls.h"

void func_801B0054(void) {
    func_801B15CC();
}

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0234);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B03EC);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B05A4);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B06F8);

void func_801B0880(void) {
    MgObj20 *p;
    u16 *frame;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    frame = &D_801D3508;
    *frame = D_801D34D0[p->unk2];
    D_801EB5D8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EB5D8);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B094C);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0ACC);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B0E34);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B147C);

INCLUDE_ASM("../asm/us/magic_flea/nonmatchings/text", func_801B15CC);
