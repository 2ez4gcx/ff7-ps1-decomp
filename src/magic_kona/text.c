#include "common.h"
#include "magic_kona/decls.h"

void func_801B0000(void) {
    func_801B0D14();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E1498 = D_801C9498 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0178);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0298);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0554);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0728);

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B08EC);

void func_801B0AB0(s32 arg0, s32 arg1) {
    MgTask *p;

    p = (MgTask *)&D_80162978[func_800BBEAC(&func_801B08EC)];
    func_800D3994(arg1, D_80151918[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0B70);

void func_801B0C4C(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E149C;
    for (i = 0; i < 150; i++) {
        p->unk2 = 0;
        p->unk0 = 0;
        p++;
    }
    func_800BBEAC(&func_801B0B70);
}

s32 func_801B0CA4(void) {
    MgObj20 *p;
    s16 i;

    p = D_801E149C;
    for (i = 0; i < 150; i++) {
        if (p->unk0 == 0) {
            p->unk0 = 1;
            return i;
        }
        p++;
    }
    return func_800BBA84(6, -1, 0x40);
}

INCLUDE_ASM("../asm/us/magic_kona/nonmatchings/text", func_801B0D14);
