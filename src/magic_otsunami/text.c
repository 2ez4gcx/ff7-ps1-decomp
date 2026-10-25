#include "common.h"
#include "magic_otsunami/decls.h"

void func_801B0000(void) {
    func_801B0BC8();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D8F8C = D_801C0F8C + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B008C);

void func_801B018C(u8 *arg0, u8 *arg1) {
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

s32 func_801B01DC(s32 arg0, s16 arg1) {
    s32 t;
    u8 pad[8];

    if ((u16)arg0 > 0x800) {
        arg0 = 0;
    }
    do {
        t = -D_801D8F90[(s16)arg0] * 625;
    } while (0);
    return (D_801D9190[arg1][0] * ((t * 64) >> 16) * 0x10) >> 16;
}

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B0270);

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B07CC);

INCLUDE_ASM("../asm/us/magic_otsunami/nonmatchings/text", func_801B0BC8);
