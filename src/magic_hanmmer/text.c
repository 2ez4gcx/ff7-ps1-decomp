#include "common.h"
#include "magic_hanmmer/decls.h"

void func_801B0054(void) {
    func_801B0810();
}

INCLUDE_ASM("../asm/us/magic_hanmmer/nonmatchings/text", func_801B0074);

void func_801B02B8(void) {
    MgTask *p;
    s8 *frame;
    s32 t;

    p = &D_80162978[D_8015169C];
    frame = &D_801B1BE4;
    t = p->unk2 << 5;
    *frame = t;
    func_800D4368(&p->unk4, p->unk12, 0);
    D_801C9BF0 = func_800D6260(frame - 4, D_801517C0 + 0x70, 0xC, D_801C9BF0);
    if (p->unk2 >= 7) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        p->unk4 += p->unk16;
        p->unk8 += p->unk18;
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_hanmmer/nonmatchings/text", func_801B0398);

INCLUDE_ASM("../asm/us/magic_hanmmer/nonmatchings/text", func_801B05E0);

INCLUDE_ASM("../asm/us/magic_hanmmer/nonmatchings/text", func_801B0810);
