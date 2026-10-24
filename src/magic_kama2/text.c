#include "common.h"
#include "magic_kama2/decls.h"

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B007C);

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B0170);

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B0238);

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B046C);

void func_801B0914(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B046C)];
    func_800D3994(arg1, D_80151915[arg1][0], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_kama2/nonmatchings/text", func_801B09D4);
