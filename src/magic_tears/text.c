#include "common.h"
#include "magic_tears/decls.h"

void func_801B0000(void) {
    func_801B03E4();
}

INCLUDE_ASM("../asm/us/magic_tears/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_tears/nonmatchings/text", func_801B0158);

void func_801B0304(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0158)];
    p->unk0 = arg0;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
}

void func_801B0384(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D0460 = D_801B0460 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_tears/nonmatchings/text", func_801B03E4);
