#include "common.h"
#include "magic_mgbeam/decls.h"

void func_801B0000(void) {
    func_801B099C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CBD20 = D_801B3D20 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B01D8);

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B0294);

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B03DC);

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B0864);

INCLUDE_ASM("../asm/us/magic_mgbeam/nonmatchings/text", func_801B099C);
