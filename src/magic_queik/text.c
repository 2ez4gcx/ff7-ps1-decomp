#include "common.h"
#include "magic_queik/decls.h"

void func_801B0054(void) {
    func_801B0330();
}

INCLUDE_ASM("../asm/us/magic_queik/nonmatchings/text", func_801B0074);

void func_801B024C(arg0) {
    MgTask *p;
    s16 t;

    p = &D_80162978[func_800BBEAC((void *)func_801B0074)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unk6 = 0;
    p->unkC = 0;
    t = D_801518F6[arg0][0] + 0xE0;
    p->unkE = t;
    if (t >= 0x76D) {
        p->unkE = 0x76C;
    }
    p->unkE = p->unkE / 8;
    p->unk10 = arg0;
}

INCLUDE_ASM("../asm/us/magic_queik/nonmatchings/text", func_801B0330);
