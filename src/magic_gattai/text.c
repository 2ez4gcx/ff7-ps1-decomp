#include "common.h"
#include "magic_gattai/decls.h"

INCLUDE_RODATA("../asm/us/magic_gattai/nonmatchings/text", D_801B0000);

s32 func_801B007C(arg0, arg1) {
    s32 t;

    D_8016297C[func_800BBEAC(D_801B0000)].unk0 = 0x1E;
    t = func_800BC04C(D_800C55B8);
    D_801621F4[t].unk0 = 0x10;
    D_801621F4[t].unk2 = arg1;
    D_801621F2[t].unk0 = 0x100;
    D_800F8374 = 0xE;
    func_800BBA40(0x29);
    if (arg1 == 0) {
        D_80151922[1][0] |= 2;
        D_80151922[2][0] |= 2;
    }
    if (arg1 == 1) {
        D_80151922[0][0] |= 2;
        D_80151922[2][0] |= 2;
    }
    if (arg1 == 2) {
        D_80151922[0][0] |= 2;
        D_80151922[1][0] |= 2;
    }
    return 0;
}
