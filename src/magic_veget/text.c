#include "common.h"
#include "magic_veget/decls.h"

void func_801B0000(void) {
    D_801C4618 = &D_801B6A50;
    func_801B0940();
}

void func_801B0030(void) {
    D_801C4618 = &D_801B94D4;
    func_801B0940();
}

void func_801B0060(void) {
    D_801C4618 = &D_801BAF38;
    func_801B0940();
}

void func_801B0090(void) {
    D_801C4618 = &D_801BC99C;
    func_801B0940();
}

void func_801B00C0(void) {
    D_801C4618 = &D_801BF240;
    func_801B0940();
}

void func_801B00F0(void) {
    D_801C4618 = &D_801C06A4;
    func_801B0940();
}

void func_801B0120(void) {
    D_801C4618 = &D_801C2050;
    func_801B0940();
}

void func_801B0150(void) {
    D_801C4618 = &D_801C36AC;
    func_801B0940();
}

INCLUDE_ASM("../asm/us/magic_veget/nonmatchings/text", func_801B0180);

INCLUDE_ASM("../asm/us/magic_veget/nonmatchings/text", func_801B06C4);

void func_801B08E0(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E461C = D_801C461C + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0940(arg0, arg1) {
    func_800D2980(&D_801B09B0, 0, 0, 0);
    func_800BBEAC(&func_801B08E0);
    func_800D5444(arg0, arg1, 0, (M2C_UNK *)&func_801B06C4);
}
