#include "common.h"
#include "magic_mdance/decls.h"

M2C_UNK *func_801B0054(void) {
    func_801B0754();
    return &D_801B07C8;
}

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B007C);

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B01B8);

void func_801B0460(s32 arg0) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B01B8)];
    p->unk12 = arg0;
    p->unk14 = 0;
    p->unk16 = 0x3A;
}

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B04B4);

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B0524);

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B0678);

INCLUDE_ASM("../asm/us/magic_mdance/nonmatchings/text", func_801B0754);
