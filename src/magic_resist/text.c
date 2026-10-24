#include "common.h"
#include "magic_resist/decls.h"

INCLUDE_ASM("../asm/us/magic_resist/nonmatchings/text", func_801B0010);

INCLUDE_ASM("../asm/us/magic_resist/nonmatchings/text", func_801B0218);

INCLUDE_ASM("../asm/us/magic_resist/nonmatchings/text", func_801B044C);

void func_801B0504(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E0770 = D_801C0770 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B0564(s32 arg0, M2C_UNK arg1) {
    s32 temp_v0;
    s32 var_v1;

    func_800D2980(&D_801B063C, 0, 0, 0);
    func_800BBEAC(&func_801B0504);
    temp_v0 = func_800D54BC(arg0);
    D_801E0774 = temp_v0;
    var_v1 = 3;
    if (temp_v0 == 1) {
        var_v1 = 6;
    }
    D_801C076C = var_v1;
    func_800D5444(arg0, arg1, -(temp_v0 >= 4) & 0xA, &func_801B044C);
    if (D_801E0774 < 4) {
        func_800D55F4(0x20, func_800D574C(arg0), 0x80);
    }
}
