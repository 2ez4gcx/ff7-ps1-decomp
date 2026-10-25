#include "common.h"
#include "magic_aeroga/decls.h"

void func_801B0000(void) {
    func_801B09F0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C9A48 = D_801B1A48 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_aeroga/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_aeroga/nonmatchings/text", func_801B04E8);

MgObj14 *func_801B055C(void) {
    s32 i;

    for (i = 0; i < 200; i++) {
        if (D_801B0AA8[i].unk0 == 0) {
            D_801B0AA8[i].unk0 = 1;
            return &D_801B0AA8[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_aeroga/nonmatchings/text", func_801B05A8);

INCLUDE_ASM("../asm/us/magic_aeroga/nonmatchings/text", func_801B0754);

INCLUDE_ASM("../asm/us/magic_aeroga/nonmatchings/text", func_801B095C);

INCLUDE_ASM("../asm/us/magic_aeroga/nonmatchings/text", func_801B09F0);
