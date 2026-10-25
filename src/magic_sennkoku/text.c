#include "common.h"
#include "magic_sennkoku/decls.h"

M2C_UNK *func_801B0054(void) {
    D_801CD5B0 = 0;
    func_801B089C();
    return &D_801B0A70;
}

M2C_UNK *func_801B0084(void) {
    D_801CD5B0 = 1;
    func_801B089C();
    return &D_801B0A70;
}

void func_801B00B8(void) {
    MgTask *p;
    MgTask *q;

    p = &D_80162978[D_8015169C];
    if (p->unk2 == 1) {
        q = func_800D4FA8(1);
        *(MgSVec *)&q->unk4 = *(MgSVec *)&p->unk4;
        q->unk10 = p->unkC;
    } else if (p->unk2 == 0x11) {
        func_800D55F4(0x20, func_800D56A8(&p->unk4), 0x1A4);
    } else if (p->unk2 == 0x20) {
        func_800D4FA8(2);
    }
    if (p->unk2 >= 0x32) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 == 0x24) {
            func_800D5774(D_801CD5AC);
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_sennkoku/nonmatchings/text", func_801B01C8);

INCLUDE_ASM("../asm/us/magic_sennkoku/nonmatchings/text", func_801B0650);

INCLUDE_ASM("../asm/us/magic_sennkoku/nonmatchings/text", func_801B089C);

INCLUDE_RODATA("../asm/us/magic_sennkoku/nonmatchings/text", D_801B0000);
