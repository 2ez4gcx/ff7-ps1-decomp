#include "common.h"
#include "magic_hyper/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B254C();
    return &D_801D2440;
}

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B0A50);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B1160);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B12E8);

void func_801B1424(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EC780 = D_801D4780 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B1490(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D46A4;
    *frame = p->unk2;
    D_80163C74 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D2374) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B1548);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B1630);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B179C);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B1958);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B1AC0);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B1EA4);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B2014);

INCLUDE_ASM("../asm/us/magic_hyper/nonmatchings/text", func_801B254C);
