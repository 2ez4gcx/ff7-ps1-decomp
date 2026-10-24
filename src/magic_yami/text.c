#include "common.h"
#include "magic_yami/decls.h"

void func_801B0000(void) {
    func_801B0D5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EDDD4 = D_801D5DD4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801D5D60;
    *frame = p->unk2;
    D_801EDDD4 = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801EDDD4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801D5C94) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_yami/nonmatchings/text", func_801B0144);

INCLUDE_ASM("../asm/us/magic_yami/nonmatchings/text", func_801B0264);

INCLUDE_ASM("../asm/us/magic_yami/nonmatchings/text", func_801B0878);

INCLUDE_ASM("../asm/us/magic_yami/nonmatchings/text", func_801B0C9C);

INCLUDE_ASM("../asm/us/magic_yami/nonmatchings/text", func_801B0D5C);
