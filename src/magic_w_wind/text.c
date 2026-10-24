#include "common.h"
#include "magic_w_wind/decls.h"

INCLUDE_ASM("../asm/us/magic_w_wind/nonmatchings/text", func_801B0010);

INCLUDE_ASM("../asm/us/magic_w_wind/nonmatchings/text", func_801B0208);

void func_801B0460(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D4854 = D_801B4854 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_w_wind/nonmatchings/text", func_801B04C0);
