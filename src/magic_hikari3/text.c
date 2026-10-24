#include "common.h"
#include "magic_hikari3/decls.h"

void func_801B0000(void) {
    func_801B0814();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0AA4 = D_801B8AA4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B008C);

void func_801B0120(s16 arg0) {
    D_801B8A88 = 0;
    D_801B8A8A = (s16) (0xFF / arg0);
    func_800BBEAC(&func_801B008C);
}

void func_801B0190(s16 arg0) {
    D_801B8A88 = 0xFF;
    D_801B8A8A = (s16) -(0xFF / arg0);
}

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B01E8);

void func_801B02A0(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801B8AA0[0] = p->unk2;
    D_801D0AA4 = func_800D4D90(&D_801B8AA0[-4], D_801517C0 + 0x70, 0xC, D_801D0AA4);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801B89C4) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B035C);

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B078C);

INCLUDE_ASM("../asm/us/magic_hikari3/nonmatchings/text", func_801B0814);
