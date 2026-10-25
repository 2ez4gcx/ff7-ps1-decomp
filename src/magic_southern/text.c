#include "common.h"
#include "magic_southern/decls.h"

void func_801B0000(void) {
    func_801B0E30();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E4294 = D_801CC294 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B018C);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B0334);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B04E8);

INCLUDE_ASM("../asm/us/magic_southern/nonmatchings/text", func_801B06FC);

void func_801B0E30(arg0, arg1) {
    func_800D2980(D_801B0F28, 0, 0, 0);
    D_801E42A0 = arg0;
    func_800D3994(arg1, D_80151918[arg1][0], &D_8016297C[func_800BBEAC((void *)func_801B06FC)]);
    func_800D54EC(arg0, D_801E4298);
    func_800BBA84(0x123, arg1, 0x40);
    D_800F5B72 = 0;
    D_800F5B71 = 0;
    D_800F5B70 = 0;
    func_800D52A0(0x1000, 0x14);
    func_800BBEAC((void *)func_801B0020);
}
