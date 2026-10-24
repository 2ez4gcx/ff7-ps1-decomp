#include "common.h"
#include "magic_triangle/decls.h"

void func_801B0000(void) {
    func_801B1340();
}

void func_801B0020(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801EB1C0 = D_801D31C0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B01A8);

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B0320);

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B07A0);

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B091C);

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B0BDC);

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B0DC4);

void func_801B1280(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B0DC4)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_triangle/nonmatchings/text", func_801B1340);
