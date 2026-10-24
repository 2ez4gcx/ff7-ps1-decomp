#include "common.h"
#include "magic_tornado/decls.h"

void func_801B0000(void) {
    func_801B10F4();
}

MgObj4C *func_801B0020(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C2F34[i].unk0 == -1) {
            D_801C2F34[i].unk0 = 0;
            D_801C2F34[i].unk2 = 0;
            D_801C2F34[i].unkA = 0;
            return &D_801C2F34[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B0098);

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B03AC);

MgObj4C *func_801B07E0(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_801C4CE4[i].unk0 == -1) {
            D_801C4CE4[i].unk0 = 0;
            D_801C4CE4[i].unk2 = 0;
            D_801C4CE4[i].unkA = 0;
            return &D_801C4CE4[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B0858);

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B0924);

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B0A1C);

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B0C8C);

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B0F60);

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B1070);

INCLUDE_ASM("../asm/us/magic_tornado/nonmatchings/text", func_801B10F4);
