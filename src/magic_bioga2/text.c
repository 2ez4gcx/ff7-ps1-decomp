#include "common.h"
#include "magic_bioga2/decls.h"

void func_801B0000(void) {
    func_801B0AB8();
}

INCLUDE_ASM("../asm/us/magic_bioga2/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_bioga2/nonmatchings/text", func_801B0328);

void func_801B04A4(void) {
    MgTask *p;
    u16 *frame;

    p = (MgTask *)&D_80162978[D_8015169C];
    frame = &D_801E37E4;
    *frame = p->unk2;
    func_800D4368(&p->unk8, p->unk10, 0);
    D_801EF7F4 = (u8 *)func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, (s32)D_801EF7F4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= 6) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_bioga2/nonmatchings/text", func_801B0564);

INCLUDE_ASM("../asm/us/magic_bioga2/nonmatchings/text", func_801B0734);

void func_801B0A50(void) {
    MgTask *p;
    u8 *buf;

    p = &D_80162978[D_8015169C];
    buf = D_801B0B50;
    if (p->unk2 == 0) {
        buf = D_801E37F4;
    }
    D_801EF7F4 = buf;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_bioga2/nonmatchings/text", func_801B0AB8);
