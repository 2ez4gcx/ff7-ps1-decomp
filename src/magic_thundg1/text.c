#include "common.h"
#include "magic_thundg1/decls.h"

void func_801B000C(void) {
    func_801B0F00();
}

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B002C);

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B0174);

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B0490);

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B055C);

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B0724);

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B0890);

void func_801B0E0C(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B0890)];
    p->unk4 = arg0;
    p->unk6 = arg1;
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk8);
}

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B0E98);

INCLUDE_ASM("../asm/us/magic_thundg1/nonmatchings/text", func_801B0F00);
