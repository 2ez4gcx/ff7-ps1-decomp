#include "common.h"
#include "magic_biora/decls.h"

void func_801B0000(void) {
    func_801B0B90();
}

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0020);

void func_801B0350(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801CCC68;
    *frame = p->unk2;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801ECC78 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801ECC78);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0410);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0588);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0734);

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0A94);

void func_801B0B30(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801ECC78 = D_801CCC78 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_biora/nonmatchings/text", func_801B0B90);
