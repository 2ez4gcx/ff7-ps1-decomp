#include "common.h"
#include "magic_mizufuki/decls.h"

void func_801B0000(void) {
    func_801B140C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E9DAC = D_801D1DAC + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B008C);

void func_801B017C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D1D4C;
    *frame = p->unk2;
    D_801E9DAC = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801E9DAC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D1724) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B0234);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B03B0);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B0498);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B05E0);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B0708);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B0AE8);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B0E40);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B124C);

INCLUDE_ASM("../asm/us/magic_mizufuki/nonmatchings/text", func_801B140C);
