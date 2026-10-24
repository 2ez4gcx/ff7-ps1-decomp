#include "common.h"
#include "magic_almighty/decls.h"

void func_801B0000(void) {
    func_801B04E8();
}

INCLUDE_ASM("../asm/us/magic_almighty/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_almighty/nonmatchings/text", func_801B01C0);

INCLUDE_ASM("../asm/us/magic_almighty/nonmatchings/text", func_801B03E4);

void func_801B0488(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D05AC = D_801B05AC + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_almighty/nonmatchings/text", func_801B04E8);
