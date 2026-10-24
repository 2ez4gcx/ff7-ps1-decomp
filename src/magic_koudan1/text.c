#include "common.h"
#include "magic_koudan1/decls.h"

void func_801B0030(void) {
    func_801B0AC4();
}

void func_801B0050(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E33D0 = D_801CB3D0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B00BC);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B01B0);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B052C);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B06A4);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B09F0);

INCLUDE_ASM("../asm/us/magic_koudan1/nonmatchings/text", func_801B0AC4);
