#include "common.h"
#include "magic_whirl/decls.h"

void func_801B0000(void) {
    func_801B10E0();
}

MgObj4C *func_801B0020(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C2F20[i].unk0 == -1) {
            D_801C2F20[i].unk0 = 0;
            D_801C2F20[i].unk2 = 0;
            D_801C2F20[i].unkA = 0;
            return &D_801C2F20[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0098);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0398);

MgObj4C *func_801B07CC(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C4CD0[i].unk0 == -1) {
            D_801C4CD0[i].unk0 = 0;
            D_801C4CD0[i].unk2 = 0;
            D_801C4CD0[i].unkA = 0;
            return &D_801C4CD0[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0844);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0910);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0A08);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0C78);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B0F4C);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B105C);

INCLUDE_ASM("../asm/us/magic_whirl/nonmatchings/text", func_801B10E0);
