#include "common.h"
#include "magic_magend/decls.h"

void func_801B0000(void) {
    func_801B0448();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C1748 = D_801B1748 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_magend/nonmatchings/text", func_801B0080);

INCLUDE_ASM("../asm/us/magic_magend/nonmatchings/text", func_801B0174);

void func_801B03F4(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0174)];
    p->unk1C = arg0;
    p->unk1E = arg1;
}

void func_801B0448(arg0, arg1) {
    func_800BBEAC(&func_801B0020);
    func_800D2980(&D_801B04B4, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, &func_801B03F4);
}
