#include "common.h"
#include "magic_goblinp/decls.h"

void func_801B0054(void) {
    func_801B0E64();
}

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B0188);

void func_801B0518(void) {
    MgTask *p;
    u16 *frame;
    s16 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801BA3C4;
    *frame = p->unk2;
    t = p->unkC;
    func_800D4368(&p->unk4, t, -(t >> 2));
    D_801D23C8 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D23C8);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B05E4);

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B0D14);

INCLUDE_ASM("../asm/us/magic_goblinp/nonmatchings/text", func_801B0E64);
