#include "common.h"
#include "magic_brizad/decls.h"

INCLUDE_ASM("../asm/us/magic_brizad/nonmatchings/text", func_801B0000);

INCLUDE_ASM("../asm/us/magic_brizad/nonmatchings/text", func_801B018C);

void func_801B028C(s16 arg0) {
    D_8016297C[func_800BBEAC(&func_801B018C)].unk0 = arg0;
}

void func_801B02D4(s16 arg0) {
    D_8016297C[func_800BBEAC(&func_801B018C)].unk0 = arg0;
}

void func_801B031C(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801D1014 = D_801B1014 + p->unk2 * 0x10000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

void func_801B037C(s32 arg0, M2C_UNK arg1) {
    func_800BBEAC(&func_801B031C);
    func_800D5444(arg0, arg1, 4, &func_801B02D4);
    func_800D55F4(0x20, func_800D574C(D_80151774), 0x18);
}
