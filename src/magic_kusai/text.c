#include "common.h"
#include "magic_kusai/decls.h"

void func_801B0054(void) {
    func_801B04E4();
}

INCLUDE_ASM("../asm/us/magic_kusai/nonmatchings/text", func_801B0074);

INCLUDE_ASM("../asm/us/magic_kusai/nonmatchings/text", func_801B0190);

void func_801B0428(void) {
    MgTask *p;
    MgTask *base;
    s32 t;
    s32 n;

    D_80162978[D_8015169C].unk0 = -1;
    n = func_800BBEAC((void *)func_801B0190);
    base = D_80162978;
    p = base + n;
    func_800D54EC(D_801CE994, &p->unk4);
    p->unk6 = -0x540;
    p->unkC = 0x8C0;
    p->unkE = 0x1180;
    p->unk14 = 0x27D2;
    t = (s16)*(u16 *)&p->unk6 >> 1;
    p->unk10 = -t;
    p->unk12 = -t * 3;
    p->unk10 = *(u16 *)&p->unk10 * 2;
}

INCLUDE_RODATA("../asm/us/magic_kusai/nonmatchings/text", D_801B0000);

void func_801B04E4(arg0) {
    D_801CE990 = &D_80162978[func_800BBEAC(D_801B0000)];
    func_800D2980(D_801B0584, 0, 0, 0);
    func_800BBEAC(func_801B0428);
    D_801CE994 = arg0;
    D_801CE998 = 0;
    func_800D55F4(0x20, func_800D574C(arg0), 0xA2);
}
