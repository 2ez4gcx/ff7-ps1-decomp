#include "common.h"
#include "magic_bacume/decls.h"

void func_801B0000(void) {
    func_801B0D5C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801CFED0 = D_801B7ED0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B0294);

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B031C);

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B0368);

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B04F8);

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B06AC);

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B08C4);

void func_801B0C9C(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B08C4)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_bacume/nonmatchings/text", func_801B0D5C);
