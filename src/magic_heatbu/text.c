#include "common.h"
#include "magic_heatbu/decls.h"

void func_801B0054(void) {
    func_801B06CC();
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
    q = &D_801C09E4;
    q->v = D_801C09E5.v = D_801C09E6.v = c;
    v = p->unk14;
    func_800D4368(&p->unk4, v, -(v >> 2));
    D_801D89EC = func_800D4D90(q - 4, D_801517C0 + 0x70, 0xC, D_801D89EC);
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

INCLUDE_ASM("../asm/us/magic_heatbu/nonmatchings/text", func_801B0214);

INCLUDE_ASM("../asm/us/magic_heatbu/nonmatchings/text", func_801B05CC);

INCLUDE_ASM("../asm/us/magic_heatbu/nonmatchings/text", func_801B06CC);
