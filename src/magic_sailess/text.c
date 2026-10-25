#include "common.h"
#include "magic_sailess/decls.h"

void func_801B0054(void) {
    func_801B03FC();
}

INCLUDE_ASM("../asm/us/magic_sailess/nonmatchings/text", func_801B0074);

void func_801B02E0(arg0) {
    MgTask *p;
    s32 t;

    p = &D_80162978[func_800BBEAC((void *)func_801B0074)];
    func_800D3994(arg0, D_8015190F[arg0][0], &p->unk4);
    p->unkC = 0;
    p->unkE = D_80151A46[arg0][0];
    t = D_801518F6[arg0][0] + 0xE0;
    if (t >= 0x76D) {
        t = 0x76C;
    }
    p->unk10 = t;
    p->unk12 = t / 16;
    p->unk14 = 0;
    if (t >= 0x4F3) {
        t = 0x4F2;
    }
    p->unk18 = arg0;
    p->unk16 = (t << 12) / 2000;
}

INCLUDE_ASM("../asm/us/magic_sailess/nonmatchings/text", func_801B03FC);
