#include "common.h"
#include "magic_geki1/decls.h"

void func_801B0000(void) {
    func_801B0E5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D54CC = D_801BD4CC + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B008C(void) {
    MgTask *p;

    p = &D_801621F0[D_801590D4];
    func_800D4368(&p->unk4, 0x2000, 0);
    D_801BD488.unk0 = D_801BD494[p->unk16];
    D_801BD488.unk8 = p->unk2;
    D_80163C74 = func_800D4D90(&D_801BD488, D_801517C0 + 0x70, 0xC, D_80163C74);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD494[p->unk16][1]) {
            p->unk0 = -1;
        }
    }
}

void func_801B0180(void) {
    MgObjAwa *p;
    u16 *frame;

    p = (MgObjAwa *)&D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x2000, 0);
    frame = &D_801BD4A4;
    *frame = p->unk2;
    D_801D54CC = func_800D4D90((u8 *)frame - 8, D_801517C0 + 0x70, 0xC, D_801D54CC);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 == D_801BD3C4) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0238);

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0468);

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B05EC);

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0854);

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0D98);

INCLUDE_ASM("../asm/us/magic_geki1/nonmatchings/text", func_801B0E5C);
