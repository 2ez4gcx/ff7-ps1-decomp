#include "common.h"
#include "magic_magma2/decls.h"

void func_801B0000(void) {
    func_801B0718();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8D08 = D_801B0D08 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgObj18 *func_801B008C(void) {
    s16 i;

    for (i = 0; i < 300; i++) {
        if (D_801C8D0C[i].unk0 == 0) {
            D_801C8D0C[i].unk0 = 1;
            D_801C8D0C[i].unk2 = 0;
            return &D_801C8D0C[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_magma2/nonmatchings/text", func_801B0118);

INCLUDE_ASM("../asm/us/magic_magma2/nonmatchings/text", func_801B0578);

INCLUDE_ASM("../asm/us/magic_magma2/nonmatchings/text", func_801B0718);
