#include "common.h"
#include "magic_daisenp/decls.h"

void func_801B0054(void) {
    D_801CF2F4 = 0;
    func_801B0E38();
}

void func_801B007C(void) {
    D_801CF2F4 = 1;
    func_801B0E38();
}

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B00A8);

void func_801B0250(void) {
    MgVec d;
    MgTask *p;
    MgSVec *q;
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s16 v;

    p = &D_80162978[D_8015169C];
    i = 0;
    D_801B72E8.v = p->unk2;
    k = p->unk18;
    q = &D_801CFCB8;
    j = k * 8;
    do {
        k++;
        if (D_80062D98 == 0) {
            d.vx = q->vx - *(s16 *)(D_801CF300 + j);
            d.vy = q->vy - *(s16 *)(D_801CF302 + j);
            d.vz = q->vz - *(s16 *)(D_801CF304 + j);
            t = func_80039F5C(func_8003A08C(&d, &d)) >> 5;
            *(s16 *)(D_801CF300 + j) += t * d.vx >> 12;
            *(s16 *)(D_801CF302 + j) += t * d.vy >> 12;
            *(s16 *)(D_801CF304 + j) += t * d.vz >> 12;
        }
        do {
            v = *(u16 *)(D_801CF306 + j);
            func_800D4368(D_801CF300 + j, v, -(v >> 2));
            j += 8;
            D_801CF2EC = func_800D4D90(D_801B72E0, D_801517C0 + 0x70, 0xC, D_801CF2EC);
        } while (0);
        i++;
        if (k >= 0x137) {
            j = 0;
            k = 0;
        }
    } while (i < 4);
    if (p->unk2 >= 0xB) {
        p->unk0 = -1;
    }
    if (*(u8 *)0x80062D98 == 0) {
        p->unk2++;
    }
}

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B04AC);

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B0B18);

INCLUDE_ASM("../asm/us/magic_daisenp/nonmatchings/text", func_801B0E38);
