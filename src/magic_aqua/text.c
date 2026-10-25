#include "common.h"
#include "magic_aqua/decls.h"

void func_801B0054(void) {
    func_801B0680();
}

void func_801B0074(void) {
    MgTask *p;
    s32 i;
    s32 k;
    s16 v;
    u16 w;

    p = &D_80162978[D_8015169C];
    k = p->unk18;
    for (i = 0; i < 2; i++) {
        v = D_801D89A8[k].v[5];
        func_800D4368(&D_801D89A8[k], v, -(v >> 2));
        D_801D8998 = func_800D4D90(D_801C098C, D_801517C0 + 0x70, 0xC, D_801D8998);
        if (D_80062D98 == 0) {
            if (p->unk2 < 6) {
                w = D_801D89A8[k].v[5] + D_801D89A8[k].v[6];
                D_801D89A8[k].v[5] = w;
                if ((s16)w >= 0x7001) {
                    D_801D89A8[k].v[5] = 0x7000;
                }
            } else if (p->unk2 >= 7) {
                w = D_801D89A8[k].v[5] - D_801D89A8[k].v[7];
                D_801D89A8[k].v[5] = w;
                if ((s16)w < 0) {
                    D_801D89A8[k].v[5] = 0;
                }
            } else {
                D_801D89A8[k].v[5] = D_801D89A8[k].v[4];
            }
        }
        k++;
        if (k >= 0xDE) {
            k = 0;
        }
    }
    if (p->unk2 >= 0xD) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_aqua/nonmatchings/text", func_801B0254);

INCLUDE_ASM("../asm/us/magic_aqua/nonmatchings/text", func_801B05C4);

INCLUDE_ASM("../asm/us/magic_aqua/nonmatchings/text", func_801B0680);
