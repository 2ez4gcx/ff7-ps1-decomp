#include "common.h"
#include "magic_dokueki/decls.h"

void func_801B0000(void) {
    func_801B0840();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8D34 = D_801C0D34 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_dokueki/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_dokueki/nonmatchings/text", func_801B01A8);

INCLUDE_ASM("../asm/us/magic_dokueki/nonmatchings/text", func_801B02A4);

INCLUDE_ASM("../asm/us/magic_dokueki/nonmatchings/text", func_801B03DC);

void func_801B0780(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B03DC)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_dokueki/nonmatchings/text", func_801B0840);
