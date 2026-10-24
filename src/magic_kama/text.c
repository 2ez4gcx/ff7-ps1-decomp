#include "common.h"
#include "magic_kama/decls.h"

void func_801B0010(void) {
    func_801B09C4();
}

void func_801B0030(void) {
    MgObj20 *p;

    p = &D_80162978[D_8015169C];
    D_801E12C0 = D_801C92C0 + p->unk2 * 0xC000;
    p->unk2 ^= 1;
    if (D_80162080 < 2) {
        p->unk0 = -1;
    }
}

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B009C);

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B0190);

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B0258);

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B049C);

void func_801B0904(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B049C)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_kama/nonmatchings/text", func_801B09C4);
