#include "common.h"
#include "magic_magikal/decls.h"

void func_801B0054(void) {
    func_801B068C();
}

void func_801B0074(void) {
    MgTask *p;
    s16 t;
    u8 c;
    s16 v;
    MgByte *q;

    p = &D_80162978[D_8015169C];
    t = p->unk2;
    if (t >= 10) {
        c = -0x80 - (t - 10) * 16;
    } else {
        c = 0x80;
    }
    q = &D_801C09A4;
    q->v = D_801C09A5.v = D_801C09A6.v = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 2));
    D_801D89AC = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801D89AC);
    if (p->unk2 >= 0x12) {
        p->unk0 = -1;
    }
    if (D_80062D98 == 0) {
        if (p->unk2 < 0x11) {
            p->unk4 += p->unkC;
            p->unk8 += p->unk10;
        }
        if (p->unk2 >= 7) {
            p->unk6 += p->unkE;
            if (p->unk2 >= 0x10) {
                p->unkE >>= 1;
            }
        }
        if (p->unk2 < 0xB) {
            p->unk14 += p->unk16;
        }
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_magikal/nonmatchings/text", func_801B0214);

INCLUDE_ASM("../asm/us/magic_magikal/nonmatchings/text", func_801B058C);

INCLUDE_ASM("../asm/us/magic_magikal/nonmatchings/text", func_801B068C);
