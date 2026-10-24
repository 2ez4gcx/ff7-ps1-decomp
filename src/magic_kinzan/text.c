#include "common.h"
#include "magic_kinzan/decls.h"

void func_801B0000(void) {
    func_801B0678();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C90B4 = D_801B10B4 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_kinzan/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_kinzan/nonmatchings/text", func_801B02B0);

void func_801B05B4(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B02B0)];
    func_800D3994(arg1, D_8015190F[arg1][9], &D_801B10AC);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

INCLUDE_ASM("../asm/us/magic_kinzan/nonmatchings/text", func_801B0678);
