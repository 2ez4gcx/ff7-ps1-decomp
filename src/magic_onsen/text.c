#include "common.h"
#include "magic_onsen/decls.h"

void func_801B0000(void) {
    func_801B078C();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801C8D44 = D_801B0D44 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

MgObj18 *func_801B008C(void) {
    s16 i;

    for (i = 0; i < 300; i++) {
        if (D_801C8D48[i].unk0 == 0) {
            D_801C8D48[i].unk0 = 1;
            D_801C8D48[i].unk2 = 0;
            return &D_801C8D48[i];
        }
    }
    return NULL;
}

INCLUDE_ASM("../asm/us/magic_onsen/nonmatchings/text", func_801B0118);

INCLUDE_ASM("../asm/us/magic_onsen/nonmatchings/text", func_801B05AC);

void func_801B06C8(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B05AC)];
    func_800D3994(arg1, D_8015190F[arg1][9], &D_801B0D3C);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk18 = arg0;
}

void func_801B078C(arg0, arg1) {
    s16 i;

    func_800BBEAC((void *)func_801B0020);
    func_800D2980(D_801B084C, 0, 0, 0);
    func_800D5444(arg0, arg1, 4, (void *)func_801B06C8);
    func_800BBA84(0x10B, arg1, 0x40);
    for (i = 0; i < 0x12C; i++) {
        D_801C8D48[i].unk0 = 0;
    }
}
