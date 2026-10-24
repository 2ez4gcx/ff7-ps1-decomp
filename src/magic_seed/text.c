#include "common.h"
#include "magic_seed/decls.h"

INCLUDE_ASM("../asm/us/magic_seed/nonmatchings/text", func_801B006C);

INCLUDE_ASM("../asm/us/magic_seed/nonmatchings/text", func_801B0128);

INCLUDE_ASM("../asm/us/magic_seed/nonmatchings/text", func_801B038C);

void func_801B0810(s32 arg0, s32 arg1) {
    MgObjAwa *p;

    p = (MgObjAwa *)&D_80162978[func_800BBEAC(&func_801B038C)];
    func_800D3994(arg1, D_8015190F[arg1][8], &p->unk4);
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unkC);
    p->unk1C = arg0;
}

INCLUDE_ASM("../asm/us/magic_seed/nonmatchings/text", func_801B08D0);
