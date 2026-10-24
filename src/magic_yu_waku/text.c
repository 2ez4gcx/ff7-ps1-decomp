#include "common.h"
#include "magic_yu_waku/decls.h"

void func_801B0000(void) {
    func_801B0DC8();
}

INCLUDE_ASM("../asm/us/magic_yu_waku/nonmatchings/text", func_801B0020);

INCLUDE_ASM("../asm/us/magic_yu_waku/nonmatchings/text", func_801B00B0);

INCLUDE_ASM("../asm/us/magic_yu_waku/nonmatchings/text", func_801B01EC);

INCLUDE_ASM("../asm/us/magic_yu_waku/nonmatchings/text", func_801B0370);

INCLUDE_ASM("../asm/us/magic_yu_waku/nonmatchings/text", func_801B046C);

INCLUDE_ASM("../asm/us/magic_yu_waku/nonmatchings/text", func_801B0A48);

void func_801B0D08(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0A48)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_yu_waku/nonmatchings/text", func_801B0DC8);
