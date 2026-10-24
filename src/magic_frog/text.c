#include "common.h"
#include "magic_frog/decls.h"

void func_801B0008(void) {
    func_801B1E14();
}

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B0028);

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B0A50);

void func_801B1160(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E2AE8 = D_801CAAE8 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B11CC);

void func_801B12E8(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x3000, 0);
    D_801CAA74[0] = p->unk2;
    D_801E2AE8 = func_800D4D90(&D_801CAA74[-4], D_801517C0 + 0x70, 0xC, D_801E2AE8);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801CA93C) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B13A0);

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B1518);

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B1878);

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B1CDC);

INCLUDE_ASM("../asm/us/magic_frog/nonmatchings/text", func_801B1E14);
