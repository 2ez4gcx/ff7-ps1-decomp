#include "common.h"
#include "magic_kafun/decls.h"

void func_801B008C(void) {
    MgTask *p;

    p = &D_80162978[D_8015169C];
    func_800D4368(&p->unk4, 0x1800, 0);
    D_801D16B4[0] = p->unk2;
    D_801E9D28 = func_800D4D90(&D_801D16B4[-4], D_801517C0 + 0x70, 0xC, D_801E9D28);
    if (D_80062D98 == 0) {
        p->unk2++;
        if (p->unk2 >= D_801D1504) {
            p->unk0 = -1;
        }
    }
}

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0148);

MgObj8 *func_801B0308(void) {
    s16 i;

    for (i = 0; i < 200; i++) {
        if (D_801D16E8[i].unk0 == 0) {
            D_801D16E8[i].unk0 = 1;
            D_801D16E8[i].unk6 = 0;
            return &D_801D16E8[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0388);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B06E4);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B08B4);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0A64);

INCLUDE_ASM("../asm/us/magic_kafun/nonmatchings/text", func_801B0E14);

void func_801B0F18(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
}

void func_801B0F94(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&D_801B0020);
    func_800D2980(&D_801B1460, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B0E14);
    func_800BBA84(0x69, arg1, 0x40);
    D_801D16A8 = 9;
}

INCLUDE_RODATA("../asm/us/magic_kafun/nonmatchings/text", D_801B0020);
