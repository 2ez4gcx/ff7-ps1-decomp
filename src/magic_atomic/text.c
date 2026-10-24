#include "common.h"
#include "magic_atomic/decls.h"

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B008C);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B0168);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B0268);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B03AC);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B0548);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B0654);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B08E4);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B09C8);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B0B44);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B0E88);

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B1050);

void func_801B18B8(s32 arg0, s32 arg1) {
    MgTask *p;

    p = &D_80162978[func_800BBEAC(&func_801B1050)];
    func_800D3994(arg1, D_8015190F[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_atomic/nonmatchings/text", func_801B1978);
