#include "common.h"
#include "magic_ranto/decls.h"

M2C_UNK *func_801B0000(void) {
    func_801B079C();
    return &D_801B6C2C;
}

void func_801B0028(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C9668 = D_801B9668 + p->unk2 * 0x8000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_ranto/nonmatchings/text", func_801B0088);

INCLUDE_ASM("../asm/us/magic_ranto/nonmatchings/text", func_801B0170);

void func_801B079C(arg0, arg1) {
    func_800BBEAC(func_801B0028);
    func_800D2980(D_801B0830, 0, 0, 0);
    D_801C966C = arg0;
    func_800D54EC(arg0, D_801C9670);
    D_80162996[func_800BBEAC(func_801B0170)].unk0 = arg1;
}
