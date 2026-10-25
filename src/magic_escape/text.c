#include "common.h"
#include "magic_escape/decls.h"

void func_801B0000(void) {
    func_801B0E60();
}

s32 func_801B0020(void) {
    Rect16 a;
    Rect16 b;
    u16 x;
    u16 y;

    x = D_801517C0->x;
    a.x = x;
    b.x = x + 0xA0;
    y = D_801517C0->y;
    b.w = 0xA0;
    a.w = 0xA0;
    b.h = 0xA8;
    a.h = 0xA8;
    b.y = y;
    a.y = y;
    func_800440C8(&a, 0x300, 0);
    func_800440C8(&b, 0x280, 0x100);
    return func_80043DD8(0);
}

INCLUDE_ASM("../asm/us/magic_escape/nonmatchings/text", func_801B009C);

INCLUDE_ASM("../asm/us/magic_escape/nonmatchings/text", func_801B063C);

void func_801B0E00(void) {
    s32 i;
    MgTask *p;

    p = &D_80162978[D_8015169C];
    D_800F8380 |= 7;
    for (i = 0; i < 10; i++) {
        D_80151909[i][0] |= 2;
    }
    p->unk0 = -1;
}

void func_801B0E60(void) {
    func_801B009C();
    func_801B0020();
    func_800BBEAC(&func_801B063C);
    func_800BBEAC(&func_801B0E00);
    func_800D55F4(0x20, 0x40, 0x5D);
}
