#include "common.h"
#include "magic_magma/decls.h"

void func_801B0000(void) {
    func_801B07E0();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8D98 = D_801B0D98 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgObj18 *func_801B008C(void) {
    s16 i;

    for (i = 0; i < 300; i++) {
        if (D_801C8D9C[i].unk0 == 0) {
            D_801C8D9C[i].unk0 = 1;
            D_801C8D9C[i].unk2 = 0;
            return &D_801C8D9C[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_magma/nonmatchings/text", func_801B0118);

INCLUDE_ASM("../asm/us/magic_magma/nonmatchings/text", func_801B05C0);

void func_801B071C(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B05C0)];
    func_800D3994(arg1, D_8015190F[arg1][9], &D_801B0D90);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

INCLUDE_ASM("../asm/us/magic_magma/nonmatchings/text", func_801B07E0);
