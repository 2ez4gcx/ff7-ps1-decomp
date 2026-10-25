#include "common.h"
#include "magic_gesui/decls.h"

void func_801B0000(void) {
    func_801B0BE8();
}

void func_801B0020(void) {
    func_801B0D44();
}

void func_801B0040(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D9108 = D_801C1108 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B00AC);

void func_801B01AC(u8 *arg0, u8 *arg1) {
    if (*arg0 == 0) {
        *arg0 = 0xFF;
    } else {
        *arg0 = -*arg0;
    }
    if (*arg1 == 0xFF) {
        *arg1 = 0;
    } else {
        *arg1 = -*arg1;
    }
}

s32 func_801B01FC(s32 arg0, s16 arg1) {
    s32 t;
    u8 pad[8];

    if ((u16)arg0 > 0x800) {
        arg0 = 0;
    }
    do {
        t = -D_801D910C[(s16)arg0] * 625;
    } while (0);
    return (D_801D930C[arg1][0] * ((t * 64) >> 16) * 0x10) >> 16;
}

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B0290);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B07EC);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B0BE8);

INCLUDE_ASM("../asm/us/magic_gesui/nonmatchings/text", func_801B0D44);
