#include "common.h"
#include "magic_jinrai/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B02B0();
    return &D_801B3470;
}

void func_801B0028(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801B5228[0] = p->unk2;
    D_80163C74 = func_800D4D90(&D_801B5228[-4], D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801B3354) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_jinrai/nonmatchings/text", func_801B00E0);

INCLUDE_ASM("../asm/us/magic_jinrai/nonmatchings/text", func_801B01E4);

INCLUDE_ASM("../asm/us/magic_jinrai/nonmatchings/text", func_801B02B0);
